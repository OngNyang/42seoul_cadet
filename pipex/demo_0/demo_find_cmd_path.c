#include <stdlib.h>
#include <stdio.h>
#include "pipex.h"
#include <fcntl.h>

/*
dup2()

execve()

access()
*/


/*
execve() example
*/
// int	main(int argc, char **argv, char **envp)
// {
// 	// char	*envp[] = {0};

// 	// execve("/bin/ls", argv, envp);
// 	int i = 0;
// 	while (envp[i])
// 	{
// 		printf("%s\n", envp[i]);
// 		i++;
// 	}
// }



/*
execve() example
*/
// int	main(int argc, char **argv, char **envp)
// {
// 	printf("%d", access("./infile", R_OK));
// }




/*
dup2() example
*/
// int	main(int argc, char **argv, char **envp)
// {
// 	int	fd = open("./infile", O_RDONLY, 0777);
// 	dup2(fd, 0);
// 	int	c;
// 	while ((c = getchar()) != EOF)
// 		putchar(c);
// 	close(fd);
// }

/*
find_command_path
*/

void	ft_p_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
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
//token_env_path, buffer 프리해야함


int	main(int argc, char **argv, char **envp)
{
	char* path = find_command_path("cat", envp);

	if (path != NULL) {
		printf("cat path: %s\n", path);
		free(path);
	} else {
		printf("Failed to find cat path\n");
	}
	system("leaks pipex");

	return (0);
}