/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:26:24 by hyejeong          #+#    #+#             */
/*   Updated: 2023/01/06 16:54:33 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
// #define BUFFER_SIZE 1024

// static char *ft_read_line(int fd, char *buf, char *backup)
// {
// 	int		count;
// 	char	*temp_pointer;

// 	count = 1;
// 	while (count)
// 	{
// 		count = read(fd, buf, BUFFER_SIZE);
// 		if (count == -1)
// 			return (0);
// 		else if (count == 0)
// 			break ;
// 		buf[count] = '\0';
// 		if (!backup)
// 			backup = ft_strdup("");
// 		temp_pointer = backup;
// 		backup = ft_strjoin(temp_pointer, buf);
// 		if (!backup)
// 			return (NULL);
// 		free(temp_pointer);
// 		temp_pointer = NULL;
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 	}
// 	return (backup);
// }

// static char *ft_extract(char *line)
// {
// 	int	i;
// 	char	*result;

// 	i = 0;
// 	while (line[i] != '\n' && line[i] != '\0')
// 		i++;
// 	if (line [i] == '\0')
// 		return (0);
// 	result = ft_substr(line, i+1, ft_strlen(line) - i);
// 	if (!result)
// 		return (NULL);
// 	if (result[0] == '\0')
//` 	{
// 		free(result);
// 		result = NULL;
// 		return (NULL);
// 	}
// 	line[i + 1] = '\0';
// 	return (result);
// }

// char	*get_next_line(int fd)
// {
// 	char	*line;
// 	char	*buf;
// 	static char	*backup;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	line = ft_read_line(fd, buf, backup);
// 	free(buf);
// 	buf = NULL;
// 	if (!line)
// 		return (NULL);
// 	backup = ft_extract(line);
// 	return (line);
// }



//--------------------------------------------------------


// #include "get_next_line.h"
// #define BUFFER_SIZE 4

// static char	*ft_read_line(int fd, char *buf, char *backup)
// {
// 	int		count;
// 	char	*temp_pointer;

// 	count = 1;
// 	while (count)
// 	{
// 		count = read(fd, buf, BUFFER_SIZE); //버퍼사이즈 만큼 읽어 들이는데, 읽어 들인 사이즈를 저장해줌.
// 		if (count == -1) //read()는 읽기에 실패했을때 -1을 리턴함.
// 			return (0);
// 		else if(count ==0)
// 			break ;
// 		buf[count] = '\0'; //널 터미네이팅
// 		if (!backup)
// 			backup = ft_strdup(""); //backup이 비어있다면, 아무것도 없는 문자열을 만들어준다.
// 		temp_pointer = backup;
// 		backup = ft_strjoin(temp_pointer, buf); //버퍼와 backup 문자열을 융합해준다.
// 		if (!backup)
// 			return (NULL);
// 		free(temp_pointer); //임시로 사용한 메모리 해제해줌.
// 		temp_pointer = NULL; //임시 포인터 변수 다시 초기화 해줌.
// 		if (ft_strchr(buf, '\n')) //개행을 만나면 멈춘다.
// 			break ;
// 	}
// 	return (backup);
// }
// //버퍼 사이즈가 개행을 만나기 전에 끝난다면 -> while 문 반복
// //버퍼 사이즈가 개행을 1개만 담고 다음 개행 이저에 끝난다면 -> while문 break. 
// //버퍼 사이즈가 전문을 다 담는다면 -> while문 break.
// //버퍼 사이즈가 개행을 못만나면, 반복해서 읽기를 한다.

// static char *ft_extract(char *line)
// {
// 	int	i;
// 	char	*result;

// 	i = 0;
// 	while (line[i] != '\n' && line[i] != '\0') // \n이나  \0을 만날때까지 인덱스 전진
// 		i++;
// 	if (line[i] == '\0')
// 		return (0);
// 	result = ft_substr(line, i + 1, ft_strlen(line) - i); //해당 범위 만큼 동적할당 뒤 복사해준다. 
// 	if (!result)
// 		return (NULL);
// 	if (result[0] == '\0') //복사한 문자열 널가드
// 	{
// 		free(result);
// 		result = NULL;
// 		return (NULL);
// 	}
// 	line[i + 1] = '\0'; //널 터미네이팅.
// 	return (result);
// }
// //추출된 문자열 중에서, \0 이나 \n을 만나기 전까지의 문자들만 추출하여 반환한다.

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	char		*buf;
// 	static char	*backup;

// 	if (fd < 0 || BUFFER_SIZE <= 0) //fd와 버퍼사이즈 유효성 검사.
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); //버퍼 메모리 동적할당
// 	if (!buf)
// 		return (NULL);
// 	line = ft_read_line(fd, buf, backup); //버퍼 사이즈만큼 읽어서 저장한다. 개행을 만날때까지 해야 한다.
// 	free(buf); //버퍼 비워준다.
// 	buf = NULL;
// 	if (!line)
// 		return (NULL);
// 	backup = ft_extract(line); //주어진 문자열 중에서 \0, \n을 만나기 전까지의 문자들만 추출하여 저장.
// 	return (line);
// }

// ----------------------------------------------------










// #include "get_next_line.h"

// char	*ft_read(int fd, char *buffer, char *stt_buffer)
// {
// 	ssize_t	len;

// 	len = 1;
// 	while (len)
// 	{
// 		len = read(fd, buffer, BUFFER_SIZE);
// 		if (len < 0) // fail read()
// 			return (NULL);
// 		else if (len == 0) // EOF
// 			break ;
// 		buffer[len] = '\0'; //null terminated
// 		if (!stt_buffer)
// 			stt_buffer = ft_strdup("");
// 		stt_buffer = ft_strjoin(stt_buffer, buffer);
// 		if (!stt_buffer)
// 			return (NULL);
// 		if (ft_strchr(buffer, '\n') != 0)
// 			break ;
// 	}
// 	return (stt_buffer);
// }
// /*

// */

// char	*ft_slice(char *line)
// {
// 	ssize_t	i;
// 	char	*str;

// 	i = 0;
// 	while (line[i] != '\n' && line[i] != '\0') // \n \0 을 만나기 전까지 전진 시켜줌.
// 		i++;
// 	if (line[i] == '\0')
// 		return (0);
// 	str = ft_substr(line, i + 1, ft_strlen(line) - i);
// 	if (!str)
// 		return (NULL);
// 	line[i + 1] = '\0';
// 	return (str);
// }
// /*
// \n을 만난 이후를 다른 문자열에 저장해준다. 
// 기존 문자열 또한 그 순간에서 멈추게 해준다.
// */


// char	*get_next_line(int fd)
// {
// 	static char	*stt_buffer;
// 	char		*line;
// 	char		*buffer;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // \0을 넣어주기 위해 +1 해줌
// 	if(!buffer)
// 		return (NULL);
// 	line = ft_read(fd, buffer, stt_buffer);
// 	if (!line)
// 		return (NULL);
// 	stt_buffer = ft_slice(line);
// 	return (line);
// }

//-----------------------------------------------------------

#include "get_next_line.h"

char	*ft_read_err(char *stt_buffer)
{
	char	*temp2;
	
	temp2 = stt_buffer;
	stt_buffer = ft_strdup("");
	//stt_buffer = NULL;
	free(temp2);
	return (stt_buffer);
	
			// 	temp2= stt_buffer;
		// 	stt_buffer = ft_strdup("");
		// 	free(temp2);
		// 	return (stt_buffer);
		// 	//return (NULL);

			// 	temp2 = stt_buffer;
		// 	stt_buffer = NULL;
		// 	free(temp2);
		// 	return (NULL);

		// free(stt_buffer);
		// return (NULL);
}

char	*ft_read(int fd, char *buffer, char *stt_buffer)
{
	//ssize_t	len;
	int		len;
	char	*temp;
	//char	*temp2;
	
	len = 1;
	while (len)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
		{
			stt_buffer = ft_read_err(stt_buffer);
			//return (NULL);
			return (stt_buffer);
		}
		else if (len == 0) // EOF
			break ;
		buffer[len] = '\0'; //null terminated
		// if (!stt_buffer)
		// 	stt_buffer = ft_strdup("");
		if (!stt_buffer)
			stt_buffer = ft_strdup("");
		temp = stt_buffer;
		stt_buffer = ft_strjoin(stt_buffer, buffer);
		free(temp);
		if (!stt_buffer)
			return (NULL);
		if (ft_strchr(buffer, '\n') != 0)
			break ;
	}
	return (stt_buffer);
}
/*

*/

char	*ft_slice(char *line)
{
	//ssize_t	i;
	int	i;
	char	*str;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0') // \n \0 을 만나기 전까지 전진 시켜줌.
		i++;
	if (line[i] == '\0')
		return (0);
	str = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!str)
		return (NULL);
	if (*str == '\0')
	{
		free (str);
		//line = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (str);
}
/*
\n을 만난 이후를 다른 문자열에 저장해준다. 
기존 문자열 또한 그 순간에서 멈추게 해준다.
*/


char	*get_next_line(int fd)
{
	static char	*stt_buffer;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); // \0을 넣어주기 위해 +1 해줌
	if(!buffer)
		return (NULL);
	line = ft_read(fd, buffer, stt_buffer);
//
	free(buffer);
//
	if (!line)
		return (NULL);
	stt_buffer = ft_slice(line);

	// if (*line == '\0')
	// {
	// 	free (stt_buffer);
	// 	return (NULL);
	// }
	if (!stt_buffer && *line == '\0')
	{
		free(line);
		return (NULL);
	}
		
	return (line);
}





//--------------------------------------------------


// char	*ft_read(int fd, char *buffer, char *stt_buffer)
// {
// 	int		len;
// 	char	*temp;

// 	len = 1;
// 	if (!stt_buffer)
// 		stt_buffer = ft_strdup("");
// 	if (!stt_buffer)
// 		return (NULL);
// 	while (len && ft_strchr(buffer, '\n'))
// 	{
// 		len = read(fd, buffer, BUFFER_SIZE);
// 		if (len == -1)
// 		{
// 			return (NULL);
// 		}
// 		else if (len == 0)
// 			break ;
// 		buffer[len] = '\0';
// 		temp = stt_buffer;
// 		stt_buffer = ft_strjoin(stt_buffer, buffer);
// 		free(temp);
// 		if (!stt_buffer)
// 			return (NULL);
// 	}
// 	return (stt_buffer);
// }

// char *ft_slice(char *line)
// {
// 	int	i;
// 	char	*str;

// 	i = 0;
// 	while (line[i] != '\n' && line[i] != '\0')
// 		i++;
// 	if (line[i] == '\0')
// 		return (NULL);
// 	str = ft_substr(line, i+1, ft_strlen(line) - i);
// 	if (!str)
// 		return (NULL);
// 	if (*str == '\0')
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	line[i+1] = '\0';
// 	return (str);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*stt_buffer;
// 	char		*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	line = ft_read(fd, buffer, stt_buffer);
// 	free(buffer);
// 	if (!line)
// 	{
// 		free(stt_buffer);
// 		stt_buffer = NULL;
// 		return (NULL);	
// 	}
// 	stt_buffer = ft_slice(line);
// 	return (line);	
// }