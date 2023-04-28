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

// typedef struct	s_redir_flag
// {
// 	t_bool	infile;
// 	t_bool	outfile_overwrite;
// 	t_bool	outfile_append;
// 	t_bool	here_doc;
// }				t_redir_flag;

typedef struct	s_info
{
	// struct s_redir_flag	redir_flag;
	int					num_pipe;
	// int					num_process;
	int					**pipes;
	// int					idx_prcs;
	// int					idx_arg;
	// char				**arg;
	pid_t				*arr_pid;
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

// void	init_redir_flag(t_redir_flag *flag);
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

	if (!cmd_args[0])
		return (FALSE);
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		exit(1);
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
t_node	*new_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
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
void	init_2d_arr(char ***arr)
{
	*arr = malloc(sizeof(char *));
	(*arr)[0] = NULL;
}
void	init_node(t_node *node)
{
	init_2d_arr(&(node->cmd));
	init_2d_arr(&(node->order_redir));
	init_2d_arr(&(node->file_redir));
	init_2d_arr(&(node->filename_heredoc));
	node->num_heredoc = 0;
}
char	**append_str(char **arg, char *str)
{
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
	new_arr[i] = malloc(ft_strlen(str) + 1);
	ft_strlcpy(new_arr[i], str, ft_strlen(str) + 1);
	i++;
	new_arr[i] = NULL;
	if (arg)
		free_2d_arr(arg);
	return (new_arr);
}


t_node	*push_init_new_node(t_deque *deque)
{
	t_node	*node;

	node = new_node();
	init_node(node);
	push_r(deque, node);
	return (node);
}

t_deque	*parsing_pipe(char **arg)
{
	int		i;
	t_deque	*deque;
	t_node	*node;

	deque = new_deque();
	node = push_init_new_node(deque);
	i = 0;
	while (arg[i])
	{
		if ((ft_strcmp(arg[i], "<") == 0) || (ft_strcmp(arg[i], ">") == 0) || (ft_strcmp(arg[i], "<<") == 0) || (ft_strcmp(arg[i], ">>") == 0))
		{
			node->file_redir = append_str(node->file_redir, arg[i+1]);
			node->order_redir = append_str(node->order_redir, arg[i]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], "|") == 0)
		{
			node = push_init_new_node(deque);
			i += 1;
		}
		else	//커맨드인 경우
			node->cmd = append_str(node->cmd, arg[i++]);
	}
	return (deque);
}




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


void	init_t_heredoc(t_heredoc *hdoc)
{
	init_2d_arr(&(hdoc->terminators));
	init_2d_arr(&(hdoc->filename_temp));
	hdoc->size_heredoc = 0;
}

void	parsing_heredoc(char **arg, t_heredoc *hdoc)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (ft_strcmp(arg[i], "<<") == 0)
		{
			hdoc->terminators = append_str(hdoc->terminators, arg[i+1]);
			hdoc->filename_temp = append_str(hdoc->filename_temp, ft_strjoin("./.here_doc", ft_itoa(hdoc->size_heredoc)));
			hdoc->size_heredoc++;
		}
		i++;
	}
}

void	get_heredoc(t_heredoc *hdoc)
{
	int	i;

	hdoc->fd_heredoc = malloc(sizeof(int) * hdoc->size_heredoc);
	i = 0;
	while (i < hdoc->size_heredoc)
	{
		hdoc->fd_heredoc[i] = ft_here_doc(hdoc, i);
		i++;
	}
}

void	cnt_heredoc_in_node(t_deque *deque)
{
	t_node	*node;
	int		i;

	node = deque->front;
	while (node)
	{
		i = 0;
		while (node->order_redir[i])
		{
			if (ft_strcmp(node->order_redir[i], "<<") == 0)
				node->num_heredoc++;
			i++;
		}
		node = node->next;
	}
}

void	distribute_heredoc(t_deque *deque, t_heredoc *hdoc)
{
	t_node	*node;
	int		idx_hd;
	int		i;

	idx_hd = 0;
	node = deque->front;
	while (node)
	{
		i = 0;
		while (i < node->num_heredoc)
		{
			node->filename_heredoc = append_str(node->filename_heredoc, hdoc->filename_temp[idx_hd]);
			idx_hd++;
			i++;
		}
		node = node->next;
	}
}

t_heredoc	*do_heredoc(char **arg, t_deque *deque)
{
	t_heredoc	*hdoc;

	hdoc = malloc(sizeof(t_heredoc) * 1);
	init_t_heredoc(hdoc);
	parsing_heredoc(arg, hdoc);
	get_heredoc(hdoc);
	cnt_heredoc_in_node(deque);
	distribute_heredoc(deque, hdoc);
	return (hdoc);
}

void	redir_infile(t_node *node, int i)
{
	int	fd_in;

	fd_in = open(node->file_redir[i], O_RDONLY);
	if (fd_in < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
}

void	redir_outfile_ow(t_node *node, int i)
{
	int	fd_out;

	fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}

void	redir_outfile_apd(t_node *node, int i)
{
	int	fd_out;

	fd_out =  open(node->file_redir[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}

void	redir_heredoc(t_node *node, int i, int idx_hd_in_node)
{
	int	fd_in;

	fd_in = open(node->filename_heredoc[idx_hd_in_node], O_RDONLY);
	if (fd_in < 0)
	{
		perror("open");
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
}

void	check_pipe_redir(t_node *node, t_info *info)
{
	if(node->prev)
		dup2(info->pipes[node->idx - 1][READ], STDIN_FILENO);
	if (node->next)
		dup2(info->pipes[node->idx][WRITE], STDOUT_FILENO);
}


void	check_file_redir(t_node *node, t_info *info)
{
	int	idx_hd_in_node;
	int	i;

	if (node->order_redir)
	{
		idx_hd_in_node = 0;
		i = 0;
		while (node->order_redir[i])
		{
			if (ft_strcmp(node->order_redir[i], "<") == 0)
				redir_infile(node, i);
			if (ft_strcmp(node->order_redir[i], ">") == 0)
				redir_outfile_ow(node, i);
			if (ft_strcmp(node->order_redir[i], ">>") == 0)
				redir_outfile_apd(node, i);
			if (ft_strcmp(node->order_redir[i], "<<") == 0)
				redir_heredoc(node, i, idx_hd_in_node++);
			i++;
		}
	}
}

int	ft_wait_pids(t_info *info)
{
	int	i;
	int	status;
	int	exit_status;

	i = 0;
	while (i < (info->num_pipe + 1))
	{
		waitpid(info->arr_pid[i], &status, 0);
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			exit_status = WTERMSIG(status);
		}
		i++;
	}
	return (exit_status);
}

void	unlink_temp_file(t_heredoc *hdoc)
{
	int	i;

	i = 0;
	while (hdoc->filename_temp[i])
	{
		unlink(hdoc->filename_temp[i]);
		i++;
	}
}

void	child_process(t_node *node, t_info *info, char **envp)
{
	check_pipe_redir(node, info);
	check_file_redir(node, info);
	if (node->cmd)
		exec(node->cmd, envp);
	exit(0);
}

t_node	*parent_process(t_node *node, t_info *info)
{
	if (node->prev)
		close(info->pipes[node->idx - 1][READ]);
	if (node->next)
		close(info->pipes[node->idx][WRITE]);
	return (node->next);
}

t_info	*init_info(t_deque *deque)
{
	t_info	*info;

	info = malloc(sizeof(t_info) * 1);
	info->num_pipe = deque_size(deque) - 1;
	info->pipes = create_pipes(info->num_pipe);
	info->arr_pid = malloc(sizeof(pid_t) * (info->num_pipe + 1));
	return (info);
}






void	run_cmd(char **arg, char **envp)
{
	t_deque		*deque;
	t_info		*info;
	t_node		*node;
	t_heredoc	*hdoc;

	deque = parsing_pipe(arg);
	info = init_info(deque);
	hdoc = do_heredoc(arg, deque);
	node = deque->front;
	while (node)
	{
		info->arr_pid[node->idx] = fork();
		if (info->arr_pid[node->idx] < 0)
			ft_p_error("Error: fork()");
		else if (info->arr_pid[node->idx] == 0)
			child_process(node, info, envp);
		else
			node = parent_process(node, info);
	}
	ft_wait_pids(info);
	unlink_temp_file(hdoc);
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
	char	*argum = "<< end0 grep a | << end1 grep 1";
	// char	*argum = "ls -al | grep 35 | grep a";
	// char	*argum = "< infile0 grep r";
	// char	*argum = "cat | ls";
	// char	*argum = "echo a | exit 88";
	// char	*argum = "cat | cat | cat";

	char	**arg_split = ft_split(argum, ' ');
//----------------------------------------------------

	run_cmd(arg_split, envp);
// 	t_deque	*deque;
	
// 	deque = parsing_pipe(arg_split);
// //----------------------------------------------------
// 	t_info	*info;

// 	info = malloc(sizeof(t_info) * 1);
// 	info->num_pipe = deque_size(deque) - 1;
// 	info->pipes = create_pipes(info->num_pipe);
// //----------------------------------------------------
// 	t_node	*node = deque->front;
// //----------------------------------------------------
// 	// int	idx = 0;
// 	// while (node)
// 	// {
// 	// 	printf("    pipe : %d\n", idx++);
// 	// 	printf("    pipe idx : %d\n", node->idx);
// 	// 	if (node->cmd)
// 	// 		for (int i=0; node->cmd[i]; i++)
// 	// 			printf("cmd : %s \n", node->cmd[i]);
// 	// 	if (node->order_redir)
// 	// 		for (int i=0; node->order_redir[i]; i++)
// 	// 			printf("order_redir : %s \n", node->order_redir[i]);
// 	// 	if (node->file_redir)
// 	// 		for (int i=0; node->file_redir[i]; i++)
// 	// 			printf("file_redir : %s \n", node->file_redir[i]);
// 	// 	node = node->next;
// 	// }
// 	// printf("---------------\n---------------\n");
// 	// usleep(200);
// 	// node = deque->front;
// //----------------------------------------------------
// 	t_heredoc	*hdoc;

// 	hdoc = do_heredoc(arg_split, deque);

// //----------------------------------------------------
// 	// int	idx = 0;
// 	// node = deque->front;
// 	// while (node)
// 	// {
// 	// 	printf("    pipe : %d\n", idx++);
// 	// 	printf("    pipe idx : %d\n", node->idx);
// 	// 	if (node->cmd)
// 	// 		for (int i=0; node->cmd[i]; i++)
// 	// 			printf("cmd : %s \n", node->cmd[i]);
// 	// 	if (node->order_redir)
// 	// 		for (int i=0; node->order_redir[i]; i++)
// 	// 			printf("order_redir : %s \n", node->order_redir[i]);
// 	// 	if (node->file_redir)
// 	// 		for (int i=0; node->file_redir[i]; i++)
// 	// 			printf("file_redir : %s \n", node->file_redir[i]);
// 	// 	printf("num_heredoc : %d \n", node->num_heredoc);
// 	// 	if (node->filename_heredoc)
// 	// 		for (int i=0; node->filename_heredoc[i]; i++)
// 	// 			printf("filename_heredoc : %s \n", node->filename_heredoc[i]);
// 	// 	node = node->next;
// 	// }
// 	// printf("---------------\n---------------\n");
// 	// usleep(200);
// 	// node = deque->front;
// //----------------------------------------------------
// 	info->arr_pid = malloc(sizeof(pid_t) * (info->num_pipe + 1));
// 	node = deque->front;
// 	while (node)
// 	{
// 		info->arr_pid[node->idx] = fork();
// 		if (info->arr_pid[node->idx] < 0)
// 			ft_p_error("Error: fork()");
// 		else if (info->arr_pid[node->idx] == 0)
// 			child_process(node, info, envp);
// 		else
// 			node = parent_process(node, info);
// 	}
// 	ft_wait_pids(info);
// 	unlink_temp_file(hdoc);
}
