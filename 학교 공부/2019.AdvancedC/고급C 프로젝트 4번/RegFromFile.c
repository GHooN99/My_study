#include "my_func.h"
void RegFromFile(person **arr, int *num, int *MAX_NUM)               //파일에서 정보 읽어오는 함수 
{
	FILE *fp;
	char tmp1[100], tmp2[100], tmp3[100];
	fp = fopen("PHONE_BOOK.txt", "r");                 //파일 불러오기
	int cnt = 0;

	for (;; cnt++)
	{
		if (fscanf(fp, "%s %s %s\n", tmp1, tmp2, tmp3) == -1)    //몇명이 등록되어있는지 카운트 
			break;
	}

	//printf("%d", cnt);

	fclose(fp);

	fp = fopen("PHONE_BOOK.txt", "r");              //다시열고 

	for (int z = 0; z < cnt; z++)    //n(명수)번  반복하면서 등록 
	{

		int idx = 0, i;
		int add = 0;
		char tmp[101];
		if ((*num) + 1 > *MAX_NUM)
			printf("OVERFLOW\n");
		else
		{
			arr[*num] = (person*)malloc(sizeof(person));    //공간할당 (위와 동일 (이름순 할당)))
			fscanf(fp, "%s", tmp);     //파일에서 읽어서 저장

			if (*num)
			{
				for (i = 0; i < *num; i++)
				{
					if (strcmp(arr[i]->name, tmp) > 0)
					{


						for (int k = *num - 1; k >= i; k--)
						{
							arr[k + 1]->name = malloc(strlen(arr[k]->name) + 1);
							arr[k + 1]->bir = malloc(strlen(arr[k]->bir) + 1);
							arr[k + 1]->pnum = malloc(strlen(arr[k]->pnum) + 1);
							strcpy(arr[k + 1]->name, arr[k]->name);
							strcpy(arr[k + 1]->bir, arr[k]->bir);
							strcpy(arr[k + 1]->pnum, arr[k]->pnum);
						}


						arr[i]->name = (char*)realloc(arr[i]->name, strlen(tmp) + 1);
						strcpy(arr[i]->name, tmp);
						add = 1;
						break;
					}
				}
				if (!add)
				{
					arr[i]->name = (char*)malloc(strlen(tmp) + 1);
					strcpy(arr[i]->name, tmp);
				}
				idx = i;
			}
			else
			{

				arr[0]->name = (char*)malloc(strlen(tmp) + 1);
				strcpy(arr[0]->name, tmp);
				idx = 0;
			}

			fscanf(fp, "%s", tmp);    //파일에서 읽어서 저장 

			if (!add)
				arr[idx]->pnum = (char*)malloc(strlen(tmp) + 1);
			else
				arr[idx]->pnum = (char*)realloc(arr[i]->pnum, strlen(tmp) + 1);
			strcpy(arr[idx]->pnum, tmp);

			fscanf(fp, "%s", tmp);			 //파일에서 읽어서 저장

			if (!add)
				arr[idx]->bir = (char*)malloc(strlen(tmp) + 1);
			else
				arr[idx]->bir = (char*)realloc(arr[i]->bir, strlen(tmp) + 1);

			strcpy(arr[idx]->bir, tmp);
			(*num)++;
		}
		strcpy(tmp, "\0");


	}

	fclose(fp);   //파일 닫기 
}