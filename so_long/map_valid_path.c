/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejeong <hyejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:40:40 by hyejeong          #+#    #+#             */
/*   Updated: 2023/03/03 14:46:11 by hyejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	contrast(t_game *game, int **visited)
{
	int i;
	int j;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'C')
			{
				if (visited[i][j] == 0)
					return (-1);
			}
			if (game->map[i][j] == 'E')
			{			   //4방 주변중 하나라도 탐색이 됐다면  출구도 접근이 가능한것이다.
				if (!(visited[i + 1][j] == 1 || visited[i - 1][j] == 1 || visited[i][j + 1] == 1 || visited[i][j - 1] == 1))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}
void	dfs(t_game *game, int **visited, int current_i, int current_j)
{
	visited[current_i][current_j] = 1;
	printf("[%d, %d] ", current_i, current_j);
//A
	if (visited[current_i][current_j - 1] == 0 && game->map[current_i][current_j - 1] != '1' && game->map[current_i][current_j - 1] != 'E')
		dfs (game, visited, current_i, current_j - 1);
//S
	if (visited[current_i + 1][current_j] == 0 && game->map[current_i + 1][current_j] != '1' && game->map[current_i + 1][current_j] != 'E')
		dfs (game, visited, current_i + 1, current_j);
//D
	if (visited[current_i][current_j + 1] == 0 && game->map[current_i][current_j + 1] != '1' && game->map[current_i][current_j + 1] != 'E')
		dfs (game, visited, current_i, current_j + 1);
//W
	if (visited[current_i - 1][current_j] == 0 && game->map[current_i - 1][current_j] != '1' && game->map[current_i - 1][current_j] != 'E')
		dfs (game, visited, current_i - 1, current_j);
}



t_vector	start_pos(t_game *game)
{
	int i;
	int j;
	t_vector	vect;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				vect.i = i;
				vect.j = j;
			}
			j++;
		}
		i++;
	}
	return (vect);
}



int valid_path(t_game *game)
{
	/*
	. visited[][]생성
	. 시작위치 구하기
	. 목표 위치( E, C) 구하기
	. dfs함수로 각각의 목표위치에 대해 시작위치로부터의 경로를 구해야함.
	!!!
	그냥 dfs 돌려버리고, 갈수 있는 위치는 전부 1로 표시가 될거 아니야? 그럼 이제, 2중while문 돌면서 ,C,E 찾아서 visited 에 대조해보면 될듯?
	*/
	t_vector	s_v;
	int		 **visited;
	int		 i;
	int		 j;
	visited = malloc(sizeof(int *) * game->height);
	i = 0;
	while (i < game->height)		//visited 이차원 배열 생성, 메모리 할당.
		visited[i++] = malloc(sizeof(int) * game->width);
	printf("malloc visited[][]\n");
	i = 0;
	while (i < game->height)		//visited 배열 0으로 초기화
	{
		j = 0;
		while (j < game->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	printf("init visited[][]\n");
	s_v = start_pos(game);		  //시작 위치 구하기.
	dfs(game, visited, s_v.i, s_v.j);   //dfs로 방문한 공간은 전부 1이 되어 있을것임.
	// i = 0;
	// while (i < game->height)
	// {
	//  j = 0;
	//  while (j < game->width)
	//  {
	//	  if (game->map[i][j] == 'C' || game->map[i][j] == 'E')
	//	  {
	//		  if (visited[i][j] == 0)
	//			  return (-1);
	//	  }
	//	  j++;
	//  }
	//  i++;
	// }
	// return (1);
	printf("\n");
	printf("\n");
	for (int i=0; i<game->height; i++)
	{
		for (int j= 0; j<game->width; j++)
		{
			printf(" %d ", visited[i][j]);
		}
		printf("\n");
	}
	return (contrast(game, visited));
}


// int main(int argc, char **argv)
// {
// 	t_game  *game;
// 	if (argc != 2)
// 		exit(1);
// 	game = malloc(sizeof(t_game) * 1);
// 	gnl_ber_to_array(argv[1], game);
// 	printf("\n\n\n%d\n", valid_path(game));
// }