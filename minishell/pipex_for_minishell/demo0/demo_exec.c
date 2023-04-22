#include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
#include <stdlib.h>

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
	char			**cmd;
	char			**infile;
	char			**outfile_ow;
	char			**outfile_apd;
	char			**here_doc;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

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

	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		return (FALSE);
	}
	return (TRUE);
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

void	init_2d_arr(char **arr)
{
	arr = malloc(sizeof(char *) * 1);
	arr[0] = NULL;
}

void	init_node(t_node *node)
{
	init_2d_arr(node->cmd);
	init_2d_arr(node->infile);
	init_2d_arr(node->outfile_apd);
	init_2d_arr(node->outfile_ow);
	init_2d_arr(node->here_doc);
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
			node->infile = append_str(node->infile, arg[i + 1]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], ">") == 0)
		{
			node->outfile_ow = append_str(node->outfile_ow, arg[i + 1]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], "<<") == 0)
		{
			node->here_doc = append_str(node->here_doc, arg[i + 1]);
			i += 2;
		}
		else if (ft_strcmp(arg[i], ">>") == 0)
		{
			node->outfile_apd = append_str(node->outfile_apd, arg[i + 1]);
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

int	main(int argc, char **argv, char **envp)
{
//----------------------------------------------------
	char	*argum = "< infile0 ls -l | grep 2";
	// char	*argum = "< infile0 grep r";
	char	**arg_split = ft_split(argum, ' ');
//----------------------------------------------------
	t_deque	*deque = parsing_pipe(arg_split);
//----------------------------------------------------
	t_node	*node = deque->front;
//----------------------------------------------------

	if (node->cmd)
	{
		for (int i=0; node->cmd[i]; i++)
		{
			printf("%s\n", node->cmd[i]);
		}
	}

	if (node->cmd)
	{
		exec(node->cmd, envp);
	}

	// char	*str = "ls -a";
	// char	**str_split = NULL;
	// str_split = append_str(str_split, "ls");
	// str_split = append_str(str_split, "-a");
	// str_split = append_str(str_split, "-l");
	// node->cmd = str_split;

	// exec(node->cmd, envp);


}



/*
파싱에 문제 없고, 정상 작동함.
무한 루프에 걸리는 이유는 grep 명령어가 input을 필요로 하는데,
그 input이 적절히 들어오지 않아서 인듯 하다.
*/