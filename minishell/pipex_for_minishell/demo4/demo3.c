#include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
#include <stdlib.h>
#include <readline/readline.h>
# include <readline/history.h>


typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}				t_bool;

typedef enum e_io
{
	INPUT = 0,
	OUTPUT = 1
}				t_io;

typedef enum e_rw
{
	READ = 0,
	WRITE = 1
}			t_rw;

typedef enum e_stdio
{
	STDIN = 0,
	STDOUT = 1
}				t_stdio;

typedef struct	s_redir_flag
{
	t_bool	infile;
	t_bool	outfile_overwrite;
	t_bool	outfile_append;
	t_bool	here_doc;
}				t_redir_flag;

typedef struct	s_info
{
	// struct s_redir_flag	redir_flag;
	int					num_pipe;
	// int					num_process;
	int					**pipes;
	// int					idx_prcs;
	// int					idx_arg;
	// char				**arg;
	char				**envp;
}				t_info;



typedef struct	s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
}				t_deque;

typedef struct	s_node
{
	int				std_output;
	int				idx;
	// int				pipe_fd[2];
	char			**cmd;
//------------------------------------------------------------------
	char			**order_redir;
	char			**file_redir;
	char			**filename_heredoc;
	// int				*node_fd_heredoc;
	int				num_heredoc;
//------------------------------------------------------------------
	// char			**infile;
	// char			**outfile_ow;
	// char			**outfile_apd;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_heredoc
{
	char	**terminators;
	char	**filename_temp;
	int		size_heredoc;
	int		*fd_heredoc;
}				t_heredoc;

int		**create_pipes(int num_pipe);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *str, size_t size);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);

void	init_redir_flag(t_redir_flag *flag);
void	init_info(t_info *info, char **arg_s, char **envp_orig);
void	first_process(t_info *info);
void	fork_process(t_info *info);
char	**append_str(char **arg, char *str);
char	**tokenize(char **envp);
char	*free_and_return(char **token_env_path, char *buffer);



static int	get_size(long long num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}


static char	*fill_mem(char *res, int n)
{
	long long	num;
	int			i;
	int			size;

	i = 0;
	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		res[i] = '-';
		i++;
	}
	size = get_size(num);
	res[i + size] = '\0';
	while (num != 0)
	{
		res[i + size - 1] = num % 10 + '0';
		size--;
		num = num / 10;
	}
	return (res);
}


static char	*fill_zero(char *res)
{
	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*res;

	res = NULL;
	if (n == 0)
	{
		res = fill_zero(res);
		return (res);
	}
	num = (long long)n;
	if (num < 0)
	{
		num *= -1;
		res = (char *)malloc(sizeof(char) * (get_size(num) + 2));
	}
	else
		res = (char *)malloc(sizeof(char) * (get_size(num) + 1));
	if (!res)
		return (0);
	res = fill_mem(res, n);
	return (res);
}



void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, s + i, 1);
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*temp;

	temp = malloc(nmemb * size);
	if (!temp)
		return (0);
	ft_memset(temp, 0, nmemb * size);
	return (temp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *str, size_t size)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(str);
	if (!dst || !str)
		return (0);
	if (size > 0)
	{
		while (i < s_len && i < size - 1)
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (s_len);
}

static char	*get_word(const char *s, char charset)
{
	size_t			len;
	char			*word;

	len = 0;
	while (s[len] && s[len] != charset)
		len++;
	word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static char	**freeing(char **s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	cnt_word(const char *s, char charset)
{
	size_t			cnt;
	size_t			i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != charset)
		{
			cnt++;
			while (s[i] && s[i] != charset)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (cnt_word(s, c) + 1));
	if (!arr)
		return (NULL);
	while (i < cnt_word(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		temp = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		arr[i] = get_word(&s[temp], c);
		if (arr[i++] == 0)
			return (freeing(arr));
	}
	arr[i] = NULL;
	return (arr);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_p_error(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_env_path(char **envp)
{
	int		i;
	char	*env_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			env_path = envp[i] + 5;
			return (env_path);
		}
		i++;
	}
	return (NULL);
}

char	*find_command_path(char *cmd, char **envp)
{
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	token_env_path = tokenize(envp);
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");
		temp = buffer;
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		if (access(buffer, F_OK | X_OK) == 0)
			return (free_and_return(token_env_path, buffer));
		else
			free(buffer);
		j++;
	}
	ft_putstr_fd("command not found\n", 2);
	exit(1);
	return (NULL);
}

char	**tokenize(char **envp)
{
	char	*env_path;
	char	**token_env_path;

	env_path = find_env_path(envp);
	token_env_path = ft_split(env_path, ':');
	return (token_env_path);
}

char	*free_and_return(char **token_env_path, char *buffer)
{
	free_2d_array(token_env_path);
	return (buffer);
}

t_bool	exec(char **cmd_args, char **envp)
{
	char	*cmd_with_path;
	// char	**cmd_args;

	// cmd_args = ft_split(cmd_with_option, ' ');

	// for (int i=0; cmd_args[i]; i++)
	// {
	// 	printf("%s\n", cmd_args[i]);
	// }
	if (!cmd_args[0])
		return (FALSE);
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		exit(1);
		// return (FALSE);
		// ft_p_error("Error: failure in execve()");
	}
	return (TRUE);
}

int	**create_pipes(int num_pipe)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * num_pipe);
	i = 0;
	while (i < num_pipe)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < num_pipe)
	{
		if (pipe(pipes[i]) == -1)
			exit(1);
		i++;
	}
	return (pipes);
}

// t_node	*new_node(int data)
t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	// node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_deque	*new_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	deque->front = NULL;
	deque->rear = NULL;
	return (deque);
}

int	deque_size(t_deque *deque)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = deque->front;
	while (node != NULL)
	{
		node = node->next;
		cnt++;
	}
	return (cnt);
}

void	push_r(t_deque *deque, t_node *node)
{
	if (deque->rear == NULL)
	{
		deque->front = node;
		deque->rear = node;
	}
	else
	{
		node->prev = deque->rear;
		deque->rear->next = node;
		deque->rear = node;
	}
	//------------------------------------------------
	node->idx = deque_size(deque) - 1;
	//------------------------------------------------

}

char	**subset_arr(char **arr, int start_idx, int end_idx)
{
	int		subset_size;
	char**	subset;
	int		i;

	subset_size = end_idx - start_idx + 1;
	subset = (char**)malloc((subset_size + 1) * sizeof(char*));
	i = 0;
	while (i < subset_size)
	{
		subset[i] = (char*)malloc(ft_strlen(arr[start_idx + i]) + 1);
		ft_strlcpy(subset[i], arr[start_idx + i], ft_strlen(arr[start_idx + i]) + 1);
		i++;
	}
	subset[i] = NULL;
	return (subset);
}

char	check_redir(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "|") == 0)
		return ('p');
	else if (ft_strcmp(str, "<") == 0)
		return ('i');
	else if (ft_strcmp(str, ">") == 0)
		return ('o');
	else if (ft_strcmp(str, "<<") == 0)
		return ('h');
	else if (ft_strcmp(str, ">>") == 0)
		return ('a');
	else
		return ('e');

}

void	free_2d_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// void	init_2d_arr(char **arr)
// {
// 	arr = malloc(sizeof(char *) * 1);
// 	arr[0] = NULL;
// }
void init_2d_arr(char ***arr) {
    *arr = malloc(sizeof(char *));
    (*arr)[0] = NULL;
}


// void	init_node(t_node *node)
// {
// 	init_2d_arr(node->cmd);
// 	init_2d_arr(node->order_redir);
// 	init_2d_arr(node->file_redir);
// }
void init_node(t_node *node) {
    init_2d_arr(&(node->cmd));
    init_2d_arr(&(node->order_redir));
    init_2d_arr(&(node->file_redir));
	init_2d_arr(&(node->filename_heredoc));
	// init_2d_arr(&(node->here_doc));
}



char	**append_str(char **arg, char *str)
{
	/*
	사이즈 1개 만큼 더 크게 만들기.
	기존것 strlcpy()
	만든거 마지막에 strlcpy()
	전체 다 free
	*/
	int		i;
	int		size;
	char	**new_arr;

	size = 0;
	if (!arg)
		size = 0;
	else
		while (arg[size])
			size++;
	new_arr = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (i < size)
	{
		new_arr[i] = (char*)malloc(ft_strlen(arg[i]) + 1);
		ft_strlcpy(new_arr[i], arg[i], ft_strlen(arg[i]) + 1);
		i++;
	}
	// for (int i=0; new_arr[i]; i++)
	// { f
	// 	printf("....%s...\n", new_arr[i]);
	// }
	new_arr[i] = malloc(ft_strlen(str) + 1);
	ft_strlcpy(new_arr[i], str, ft_strlen(str) + 1);
	// printf("!!!%s!!!\n", new_arr[i]);
	i++;
	new_arr[i] = NULL;
	if (arg)
		free_2d_arr(arg);
	return (new_arr);
}



t_deque	*parsing_pipe(char **arg)
{
	int		i;
	int		end_i;
	char	flag;
	t_deque	*deque;
	t_node	*node;

	deque = new_deque();
	node = new_node();
	init_node(node);
	push_r(deque, node);
	i = 0;
	while (arg[i])
	{
		if (ft_strcmp(arg[i], "<") == 0)
		{
			// node->infile = append_str(node->infile, arg[i + 1]);
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, "<");
			i += 2;
		}
		else if (ft_strcmp(arg[i], ">") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, ">");
			i += 2;
		}
		else if (ft_strcmp(arg[i], "<<") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, "<<");

			i += 2;
		}
		else if (ft_strcmp(arg[i], ">>") == 0)
		{
			node->file_redir = append_str(node->file_redir, arg[i + 1]);
			node->order_redir = append_str(node->order_redir, ">>");
			i += 2;
		}
		else if (ft_strcmp(arg[i], "|") == 0)
		{
			node = new_node();
			init_node(node);
			push_r(deque, node);
			i += 1;
		}
		else	//커맨드인 경우
		{
			node->cmd = append_str(node->cmd, arg[i]);
			i += 1;
		}
	}
	return (deque);
}


// void	ft_here_doc(char *terminator, char *filename)
int	ft_here_doc(t_heredoc *hdoc, int idx)
{
	char	*str;
	pid_t	pid;
	int		here_fd;

	here_fd = open(hdoc->filename_temp[idx], O_RDWR | O_CREAT | O_TRUNC, 0666);
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		while (1)
		{
			str = readline("> ");
			if (!str || ft_strcmp(hdoc->terminators[idx], str) == 0)
			{
				if (str)
					free(str);
				exit(0);
			}
			write(here_fd, str, ft_strlen(str));
			write(here_fd, "\n", 1);
			free(str);
		}
	}
	wait(NULL);
	return (here_fd);
}



int	main(int argc, char **argv, char **envp)
{
//----------------------------------------------------
	// char	*argum = "< infile0 grep 1 < infile1 > outfile0 < infile2 > outfile1 | < infile3 ls -a -l > outfile";
	// char	*argum = "< infile0 grep 1 | grep a | wc -l";
	// char	*argum = "< infile11";
	// char	*argum = "< infile0 grep r | grep 2 | grep c > outfile0 >> outfile1";
	// char	*argum = "sleep 100 | sleep 200 | sleep 300";
	// char	*argum = "sleep 7 | sleep 10 | sleep 5";
	// char	*argum = "< infile0 grep r > outfile0 > outfile1";
	// char	*argum = "< infile0 < infile1 grep r";
	char	*argum = "<< end0 << end1 grep a | << end2 grep 1";
	// char	*argum = "ls -al | grep 35 | grep a";
	// char	*argum = "< infile0 grep r";
	// char	*argum = "cat | ls";
	// char	*argum = "echo a | exit 88";
	// char	*argum = "cat | cat | cat";

	char	**arg_split = ft_split(argum, ' ');
//----------------------------------------------------
	// for (int i=0; arg_split[i]; i++)
	// {
	// 	printf("%d : %s \n", i, arg_split[i]);
	// }
	// printf("\n\n");
//----------------------------------------------------
	t_deque	*deque = parsing_pipe(arg_split);
//----------------------------------------------------
	t_info	information;

	information.num_pipe = deque_size(deque) - 1;
	information.pipes = create_pipes(information.num_pipe);
//----------------------------------------------------
	t_node	*node = deque->front;
//----------------------------------------------------
	// int	idx = 0;
	// while (node)
	// {
	// 	printf("    pipe : %d\n", idx++);
	// 	printf("    pipe idx : %d\n", node->idx);
	// 	if (node->cmd)
	// 		for (int i=0; node->cmd[i]; i++)
	// 			printf("cmd : %s \n", node->cmd[i]);
	// 	if (node->order_redir)
	// 		for (int i=0; node->order_redir[i]; i++)
	// 			printf("order_redir : %s \n", node->order_redir[i]);
	// 	if (node->file_redir)
	// 		for (int i=0; node->file_redir[i]; i++)
	// 			printf("file_redir : %s \n", node->file_redir[i]);

	// 	node = node->next;
	// }
	// printf("---------------\n---------------\n");
	// usleep(200);
	// node = deque->front;
//----------------------------------------------------
	
	t_heredoc hdoc;
	init_2d_arr(&(hdoc.filename_temp));
	init_2d_arr(&(hdoc.terminators));
	hdoc.size_heredoc = 0;
	for (int i=0; arg_split[i]; i++)
	{
		if (ft_strcmp(arg_split[i], "<<") == 0)
		{
			hdoc.terminators = append_str(hdoc.terminators, arg_split[i+1]);
			hdoc.filename_temp = append_str(hdoc.filename_temp, ft_strjoin("./.here_doc", ft_itoa(hdoc.size_heredoc)));
			hdoc.size_heredoc++;
		}
	}
	hdoc.fd_heredoc = malloc(sizeof(int) * hdoc.size_heredoc);
	for (int i=0; i<hdoc.size_heredoc; i++)
	{
		hdoc.fd_heredoc[i] = ft_here_doc(&hdoc, i);
	}

	//node->num_heredoc 계산
	node = deque->front;
	node->num_heredoc = 0;
	while (node)
	{
		for (int i=0; node->order_redir[i]; i++)
		{
			if (ft_strcmp(node->order_redir[i], "<<") == 0)
				node->num_heredoc++;
		}
		node = node->next;
	}

	//filename_heredoc 분배
	node = deque->front;
	int	idx_hd = 0;
	while (node)
	{
		for (int i=0; i<node->num_heredoc; i++)
		{
			node->filename_heredoc = append_str(node->filename_heredoc, hdoc.filename_temp[idx_hd]);
			idx_hd++;
		}
		node = node->next;
	}

	//fd_heredoc 분배
	// node = deque->front;
	// int	idx_hd = 0;
	// while (node)
	// {
	// 	node->node_fd_heredoc = malloc(sizeof(int) * node->num_heredoc);
	// 	for (int i=0; i<node->num_heredoc; i++)
	// 	{
	// 		node->node_fd_heredoc[i] = hdoc.fd_heredoc[idx_hd++];
	// 	}
	// 	node = node->next;
	// }




//----------------------------------------------------
	// int	idx = 0;
	// node = deque->front;
	// while (node)
	// {
	// 	printf("    pipe : %d\n", idx++);
	// 	printf("    pipe idx : %d\n", node->idx);
	// 	if (node->cmd)
	// 		for (int i=0; node->cmd[i]; i++)
	// 			printf("cmd : %s \n", node->cmd[i]);
	// 	if (node->order_redir)
	// 		for (int i=0; node->order_redir[i]; i++)
	// 			printf("order_redir : %s \n", node->order_redir[i]);
	// 	if (node->file_redir)
	// 		for (int i=0; node->file_redir[i]; i++)
	// 			printf("file_redir : %s \n", node->file_redir[i]);
	// 	printf("num_heredoc : %d \n", node->num_heredoc);
	// 	if (node->filename_heredoc)
	// 		for (int i=0; node->filename_heredoc[i]; i++)
	// 			printf("filename_heredoc : %s \n", node->filename_heredoc[i]);
	// 	node = node->next;
	// }
	// printf("---------------\n---------------\n");
	// usleep(200);
	// node = deque->front;
//----------------------------------------------------




	node = deque->front;
	pid_t	pid;
	int		fd_in;
	int		fd_out;

	while (node)
	{
		pid = fork();
		if (pid < 0)
			ft_p_error("Error: fork()");
		else if (pid == 0)
		{

			if (node->prev)	//이전에 파이프가 있다.
			{
				// close(node->pipe_fd[WRITE]);
				// dup2(node->pipe_fd[READ], STDIN_FILENO);
				dup2(information.pipes[node->idx - 1][READ], STDIN_FILENO);
			}
			
			if (node->next)	//이후에 파이프가 있다.
			{
				// pipe(node->next->pipe_fd);
				// close(node->next->pipe_fd[READ]);
				// dup2(node->next->pipe_fd[WRITE], STDOUT_FILENO);
				dup2(information.pipes[node->idx][WRITE], STDOUT_FILENO);
			}
			
			if (node->order_redir)
			{
				int	idx_hd_in_node = 0;
				for (int i=0; node->order_redir[i]; i++)
				{
					if (ft_strcmp(node->order_redir[i], "<") == 0)
					{
						fd_in = open(node->file_redir[i], O_RDONLY);
						if (fd_in < 0)
						{
							perror("open");
							exit(1);
						}
						dup2(fd_in, STDIN_FILENO);
						close(fd_in);
					}
					if (ft_strcmp(node->order_redir[i], ">") == 0)
					{
						fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
						if (fd_out < 0)
						{
							perror("open");
							exit(1);
						}
						dup2(fd_out, STDOUT_FILENO);
						close(fd_out);
					}
					if (ft_strcmp(node->order_redir[i], ">>") == 0)
					{
						fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
						if (fd_out < 0)
						{
							perror("open");
							exit(1);
						}
						dup2(fd_out, STDOUT_FILENO);
						close(fd_out);
					}
					if (ft_strcmp(node->order_redir[i], "<<") == 0)
					{
						fd_in = open(node->filename_heredoc[idx_hd_in_node++], O_RDONLY);
						if (fd_in < 0)
						{
							perror("open");
							exit(1);
						}
						dup2(fd_in, STDIN_FILENO);
						close(fd_in);
					}
				}
			}

			// if (node->infile)
			// {
			// 	for (int i=0; node->infile[i]; i++)
			// 	{
			// 		fd_in = open(node->infile[i], O_RDONLY);
			// 		dup2(fd_in, STDIN_FILENO);
			// 	}
			// }
			// if (node->outfile_ow)
			// {
			// 	for (int i=0; node->outfile_ow[i]; i++)
			// 	{
			// 		fd_out =  open(node->outfile_ow[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			// 		dup2(fd_out, STDOUT_FILENO);
			// 	}
			// }
			// if (node->outfile_apd)
			// {

			// }

			// usleep(1000 * 1000);

			if (node->cmd)
			{
				exec(node->cmd, envp);
				// char *cmd_with_path = find_command_path(node->cmd[0], envp);
				// if (execve(cmd_with_path, node->cmd, envp) == -1)
				// 	exit(1);
			}
			exit(0);
		}
		else
		{
			// printf("wating for %d/ %d\n",pid, node->idx);
			// waitpid(pid, NULL, 0);
			// printf("wait end %d\n", pid);
			// node = node->next;
			if (node->prev)
            	close(information.pipes[node->idx - 1][READ]);
            if (node->next)
        		close(information.pipes[node->idx][WRITE]);
            // printf("wating for %d/ %d\n",pid, node->idx);
            // waitpid(pid, NULL, 0);
            // printf("wait end %d\n", pid);
            node = node->next;
		}
	}
	for (int i=0; i<information.num_pipe + 1; i++)
		wait(NULL);
	for (int i=0; hdoc.filename_temp[i]; i++)
	{
		unlink(hdoc.filename_temp[i]);
	}
}
