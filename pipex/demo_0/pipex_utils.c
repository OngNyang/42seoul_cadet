#include "pipex.h"

void	ft_p_error(char *str)
{
	ft_printf("%s\n", str);
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
	char	*env_path;
	char	**token_env_path;
	char	*buffer;
	char	*temp;
	int		j;

	env_path = find_env_path(envp);
	token_env_path = ft_split(env_path, ':');		// :을 구분자로 나누어서 문자열 저장.
	j = 0;
	while (token_env_path[j])
	{
		buffer = ft_strjoin(token_env_path[j], "/");			// 마지막에 /붙여줘야함
		temp = buffer;
		buffer = ft_strjoin(temp, cmd);
		free(temp);
		// printf("buffer : %s\n", buffer);
		if (access(buffer, F_OK | X_OK) == 0)
			break ;
		else
			free(buffer);
		j++;
	}
	free_2d_array(token_env_path);
	return (buffer);
}

void	exec_cmd(char *cmd_with_option, char **envp)
{
/*
2차원 배열 {명령어(경로포함), 옵션, ..., NULL}
*/
	char	*cmd_with_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd_with_option, ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		free_2d_array(cmd_args);
		free(cmd_with_path);
		ft_p_error("Error: failure in execve()");
	}
}
