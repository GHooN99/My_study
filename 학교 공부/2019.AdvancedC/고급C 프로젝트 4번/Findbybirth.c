#include "my_func.h"
void Findbybirth(person **arr, int *num)    //���Ϸ� ã�� �Լ� 
{
	int tbir;
	printf("Birth:");             //���� �Է� 
	scanf("%d", &tbir);
	for (int i = 0; i < *num; i++)
	{
		if (check_birth(arr[i]->bir, tbir))          //ã�� �����̸� ��� 
			printf("%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);
	}

}