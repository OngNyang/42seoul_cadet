#include "mini_pipex.h"
#include <stdio.h>


/*
파이프 갯수 알아내기
프로세스 갯수 == 커맨드 갯수 알아내기, 근데 사실 파이프가 한개도 없으면 커맨드는 1개일수밖에
<, >, <<, >> 같은거 있으면 입출력 위치 바꾸기.
*/

//지금 프로그램은 최소 2개의 커맨드가 들어올때인데, 1개의 커맨드일때ㅔ는 어떰?
//	동작을 안하네
//	그냥 파이프 갯수 세고 커맨드 갯수 세서 1개인 경우, 그렇지 않은 경우 나눠야 할듯



void	exec(char *cmd_with_option, char **envp)
{
	char	*cmd_with_path;
	char	**cmd_args;

	cmd_args = ft_split(cmd_with_option, ' ');
	cmd_with_path = find_command_path(cmd_args[0], envp);
	if (execve(cmd_with_path, cmd_args, envp) == -1)
	{
		ft_p_error("Error: failure in execve()");
	}
}


void	first_process(t_info *info)
{
	int	j;
	int	k;
	int	fd_in;

	j = 0;
	while (j < info->num_pipe)
	{
		k = 0;
		while (k < 2)
		{
			if (!(j == 0 && k == 1))
				close(info->pipes[j][k]);
			k++;
		}
		j++;
	}
	// fd_in = open(argv[1], O_RDONLY);
	// dup2(fd_in, STDIN);
	dup2(info->pipes[0][WRITE], STDOUT);
	exec(argv[2], envp);
}


void	redir_infile(----)
{

}

void	redir_outfile(----)
{

}

t_bool	check_redir_keyword(char *str)
{
	if (ft_strcmp(str, "|") == 0)
		return (TRUE);
	if (ft_strcmp(str, "<") == 0)
		return (TRUE);
	if (ft_strcmp(str, ">") == 0)
		return (TRUE);
	if (ft_strcmp(str, "<<") == 0)
		return (TRUE);
	if (ft_strcmp(str, ">>") == 0)
		return (TRUE);
	return (FALSE);
}

void	fork_process(t_info *info)
{
	// int		i;
	// pid_t	pid;

	// while (i < info->num_process)
	// {
	// 	pid = fork();
	// 	if (pid < 0)
	// 		exit(1);
	// 	else if (pid == 0)
	// 	{
	// 		if (info->idx_prcs == 0)
	// 			first_process(info);
	// 		else if (info->idx_prcs == info->num_pipe)
	// 			last_process(info);
	// 		else
	// 			middle_process(info);
	// 	}
	// 	i++;
	// }
	pid_t	pid;
	int		i;


	while (info->arg[info->idx_arg])
	{
		// if (ft_strcmp(info->arg[i], "<") == 0)
		// {
		// 	redir_infile(----);
		// 	i++;
		// }
		// if (ft_strcmp(info->arg[i], ">") == 0)
		// {
		// 	redir_outfile(----);
		// 	i++;
		// }
		if (check_redir_keyword(info->arg[i]) == TRUE)
		{
			adfasdfadf_____do_something()
		}
		else	//명령어인경우
		{
			pid = fork();
			if (pid < 0)
				exit(1);
			else if (pid == 0)
			{				//idx_prcs, idx_arg	 둘다 전진 시켜야 함.
				if (info->idx_prcs == 0).
				
					fisrst_process(info);
				else if (info->idx_prcs == info->num_pipe)
					last_process(info);
				else
					middle_process(info)
			}
		}
	}
}



int	main(int argc, char **argv, char **envp)
{
//----------------------------------------------------
	char	**arg_split = ft_split(argv[1], ' ');
//----------------------------------------------------
	t_info	info;

	init_info(&info, arg_split, envp);
	// if (info.num_pipe == 0)
		//파이프 없으면, 자식 프로세스 하나 생성해서 실행.

	//프로세스가 2개 이상일때.
	fork_process(&info);




}

/*
test t_info

	printf("%d %d %d %d\n", info.num_pipe, info.num_process, info.idx_prcs, info.idx_arg);
	for (int i=0; info.arg[i]; i++)
	{
		printf("%s\n", info.arg[i]);
	}
	for (int i=0; i < info.num_pipe; i++)
	{
		printf("%d ", info.pipes[i][0]);
		printf("%d ", info.pipes[i][1]);
		printf("\n");
	}
	printf("%d %d %d %d\n", info.redir_flag.infile, info.redir_flag.outfile_append, info.redir_flag.outfile_overwrite, info.redir_flag.here_doc);

*/




// int	main(int argc, char **argv, char **envp)
// {

// 	int	i;
// 	char	**new_arg;
// 	int		**pipes;
// 	t_redir_flag	redir_flag;


// 	num_pipe = 0;
// 	init_redir_flag(&redir_flag);
// 	new_arg = ft_split(argv[1], ' ');
// 	i = 0;
// 	while (new_arg[i])			//파이프의 갯수와, 리디렉션 키워드 존재 확인
// 	{
// 		if (ft_strcmp(new_arg[i], "|") == 0)
// 			num_pipe++;
// 		else if (ft_strcmp(new_arg[i], "<") == 0)
// 			redir_flag.infile = TRUE;
// 		else if (ft_strcmp(new_arg[i], ">") == 0)
// 			redir_flag.outfile_overwrite = TRUE;
// 		else if (ft_strcmp(new_arg[i], ">>") == 0)
// 			redir_flag.outfile_append = TRUE;
// 		else if (ft_strcmp(new_arg[i], "<<") == 0)
// 			redir_flag.here_doc = TRUE;
// 		i++;
// 	}
// 	num_process = num_pipe - 1;


// 	if (num_pipe == 0)
// 	{
// 		//자식 프로세스를 통해 커맨드 1개 실행.
// 	}

// 	pipes = create_pipes(num_pipe);

// 	int	idx_prcs = 0;





// }

	// for (int i=0; new_arg[i]; i++)
	// {
	// 	printf("%s\n", new_arg[i]);
	// }