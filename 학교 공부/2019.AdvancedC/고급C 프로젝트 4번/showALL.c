#include "my_func.h"
void showALL(person **arr, int *num)              //���� ��� �ο����� ��� �Լ� 
{
	for (int i = 0; i < *num; i++)
		printf("%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);
}