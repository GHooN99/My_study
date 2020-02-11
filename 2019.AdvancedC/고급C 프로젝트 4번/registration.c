#include "my_func.h"

void registration(person **arr, int *num, int *MAX_NUM)    //1번 등록함수 
{
	int idx = 0, i;
	int add = 0;
	char tmp[101];
	if ((*num) + 1 > *MAX_NUM)                 //오버플로우 처리
		printf("OVERFLOW\n");
	else
	{
		arr[*num] = (person*)malloc(sizeof(person));
		printf("Name:");                //이름 입력 
		gets(tmp);
		if (*num)               //첫등록이 아닐시 
		{
			for (i = 0; i < *num; i++)
			{
				if (strcmp(arr[i]->name, tmp) > 0)                 //이름순 위치 찾기 
				{
					for (int k = *num - 1; k >= i; k--)                //위치를 찾으면 배열 뒤로 밀고 이름 삽입 
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
					add = 1;					//이름이 추가됨 
					break;
				}
			}
			if (!add)    //이름이 추가 되지않으면 끝에다 추가 
			{
				arr[i]->name = (char*)malloc(strlen(tmp) + 1);
				strcpy(arr[i]->name, tmp);
			}
			idx = i;
		}

		else          //첫등록시 0번에 이름 저장 
		{

			arr[0]->name = (char*)malloc(strlen(tmp) + 1);
			strcpy(arr[0]->name, tmp);
			idx = 0;
		}

		//나머지 전화번호 생일 정보 등록 
		printf("Phone_number:");
		gets(tmp);
		if (!add)
			arr[idx]->pnum = (char*)malloc(strlen(tmp) + 1);
		else
			arr[idx]->pnum = (char*)realloc(arr[i]->pnum, strlen(tmp) + 1);

		strcpy(arr[idx]->pnum, tmp);

		printf("Birth:");
		gets(tmp);
		if (!add)
			arr[idx]->bir = (char*)malloc(strlen(tmp) + 1);
		else
			arr[idx]->bir = (char*)realloc(arr[i]->bir, strlen(tmp) + 1);

		strcpy(arr[idx]->bir, tmp);


		(*num)++;                    //현재 인원수 증가 
		printf("<<%d>>\n", *num);
	}

	strcpy(tmp, "\0");
}