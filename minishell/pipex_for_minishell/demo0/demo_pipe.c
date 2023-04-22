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

int	main(int argc, char **argv, char **envp)
{
	char	*argum0 = "ls -al";
	char	**arg_split0 = ft_split(argum0, ' ');
	char	*argum1 = "grep out";
	char	**arg_split1 = ft_split(argum1, ' ');
	
	
	
	pid_t	pid;
	int		fd_in;
	int		num_pipe = 1;
	int		num_process = 2;
	int		**pipes = create_pipes(num_pipe);
	char	*cmd_with_path;


	int index = 0;
	while (index < num_process)
	{
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
		{
			// for (int i=0; i<num_pipe; i++)
			// {
			// 	for (int j=0; j<2; j++)
			// 	{
			// 		if(!((i == index-1 && j == 0) || (i == index && j == 1)))
			// 			close(pipes[i][j]);
			// 	}
			// }
			// if (index > 0)
			// {
			// 	dup2(pipes[index-1][READ], STDIN_FILENO);
			// }
			// if (index < num_process - 1)
			// {
			// 	dup2(pipes[index][WRITE], STDOUT_FILENO);
			// }
			if (index == 0)
			{
				close(pipes[0][READ]);
				dup2(pipes[0][WRITE], STDOUT_FILENO);
			}
			else if (index == 1)
			{
				close(pipes[0][WRITE]);
				dup2(pipes[0][READ], STDIN_FILENO);
			}


			if (index == 0)
			{
				cmd_with_path = find_command_path(arg_split0[0], envp);
				if (execve(cmd_with_path, arg_split0, envp) == -1)
					exit(1);
			}
			else if (index == 1)
			{
				cmd_with_path = find_command_path(arg_split1[0], envp);
				if (execve(cmd_with_path, arg_split1, envp) == -1)
					exit(1);
			}
		}
		else
		{

			printf("wating for %d/ %d\n",pid, index);
			waitpid(pid, NULL, 0);
			printf("wait end %d\n", pid);
			for (int i = 0; i<1; i++)
			{
				close(pipes[i][READ]);
				close(pipes[i][WRITE]);
			}
			index++;
		}
	}
}


// int main(int argc, char **argv, char **envp)
// {
//     char    *argum0 = "ls -al";
//     char    **arg_split0 = ft_split(argum0, ' ');
//     char    *argum1 = "grep out";
//     char    **arg_split1 = ft_split(argum1, ' ');

//     pid_t   pid;
//     int     fd_in;
//     int     num_pipe = 1;
//     int     num_process = 2;
//     int     **pipes = create_pipes(num_pipe);

//     int index = 0;
//     while (index < num_process)
//     {
//         pid = fork();
//         if (pid < 0)
//             exit(1);
//         else if (pid == 0)
//         {
//             // Close all unused pipe ends in the current child process
//             for (int i = 0; i < num_pipe; i++)
//             {
//                 if (i == index - 1)
//                     close(pipes[i][WRITE]);
//                 else if (i == index)
//                     close(pipes[i][READ]);
//                 else
//                 {
//                     close(pipes[i][READ]);
//                     close(pipes[i][WRITE]);
//                 }
//             }

//             // Redirect standard input and/or output if necessary
//             if (index > 0)
//                 dup2(pipes[index-1][READ], STDIN_FILENO);
//             if (index < num_process - 1)
//                 dup2(pipes[index][WRITE], STDOUT_FILENO);

//             // Execute the appropriate command
//             if (index == 0)
//                 exec(arg_split0, envp);
//             else if (index == 1)
//                 exec(arg_split1, envp);

//             // If exec fails, exit with an error code
//             exit(1);
//         }
//         else
//         {
//             printf("Waiting for child process %d\n", pid);
//             waitpid(pid, NULL, 0);
//             printf("Child process %d exited\n", pid);
//             index++;
//         }
//     }

//     // Close all pipe ends in the parent process
//     for (int i = 0; i < num_pipe; i++)
//     {
//         close(pipes[i][READ]);
//         close(pipes[i][WRITE]);
//     }

//     // Free memory
//     free_2d_arr(arg_split0);
//     free_2d_arr(arg_split1);
//     for (int i = 0; i < num_pipe; i++)
//         free(pipes[i]);
//     free(pipes);

//     return 0;
// }
