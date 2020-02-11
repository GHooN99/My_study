#include "my_func.h"
void SaveFromFile(person **arr, int *num)                 //파일로 저장하는 함수 
{
	FILE *fp;
	fp = fopen("PHONE_BOOK.txt", "w");              // 파일명 저장 
	for (int i = 0; i < *num; i++)
		fprintf(fp, "%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);             //현재까지 정보 모두 저장 
	fclose(fp);
}