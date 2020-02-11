#include "my_func.h"
void showALL(person **arr, int *num)              //현재 등록 인원정보 출력 함수 
{
	for (int i = 0; i < *num; i++)
		printf("%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);
}