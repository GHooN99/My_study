#include "my_func.h"
void Findbybirth(person **arr, int *num)    //생일로 찾는 함수 
{
	int tbir;
	printf("Birth:");             //생일 입력 
	scanf("%d", &tbir);
	for (int i = 0; i < *num; i++)
	{
		if (check_birth(arr[i]->bir, tbir))          //찾는 생일이면 출력 
			printf("%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);
	}

}