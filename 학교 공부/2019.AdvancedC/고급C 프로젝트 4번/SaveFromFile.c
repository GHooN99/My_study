#include "my_func.h"
void SaveFromFile(person **arr, int *num)                 //���Ϸ� �����ϴ� �Լ� 
{
	FILE *fp;
	fp = fopen("PHONE_BOOK.txt", "w");              // ���ϸ� ���� 
	for (int i = 0; i < *num; i++)
		fprintf(fp, "%s %s %s\n", arr[i]->name, arr[i]->pnum, arr[i]->bir);             //������� ���� ��� ���� 
	fclose(fp);
}