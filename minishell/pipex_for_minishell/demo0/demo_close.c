#include <stdio.h>


int main(void)
{
	int size = 4;
	int	arr[size][2];

	for (int i=0; i<size; i++)
	{
		arr[i][0] = 2;
		arr[i][1] = 2;
	}


	int idx = 0;
	while (idx < size + 1)
	{
		for (int j=0; j<size; j++)
		{
			for (int k=0; k<2; k++)
			{
				if(!((j == idx-1 && k == 0) || (j == idx && k == 1)))
					arr[j][k] = 0;
			}
		}
		if (idx > 0)
		{
			arr[idx-1][0] = 1;
		}
		if (idx < size)
		{
			arr[idx][1] = 1;
		}

//---------------------------------------------
		printf("try : %d\n", idx);
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<2; j++)
			{
				printf("[%d]", arr[i][j]);
			}
			printf("\n");
		}
		//2로 초기화
		for (int i=0; i<size; i++)
		{
			arr[i][0] = 2;
			arr[i][1] = 2;
		}
//---------------------------------------------

		idx++;
	}




}



//---------------------------------------------
	// for (int i=0; i<size; i++)
	// {
	// 	for (int j=0; j<2; j++)
	// 	{
	// 		printf("[%d]", arr[i][j]);
	// 	}
	// 	printf("\n");
	// }
//---------------------------------------------