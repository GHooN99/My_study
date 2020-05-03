#include "my_func.h"
void Delete(person **arr, int *num)             //정보 제거 함수 
{
	char tmp[101];
	int k = 0;
	if (!(*num))                   //등록인원이 0명이면 출력 
		printf("NO MEMBER\n");

	else
	{
		printf("Name:");               //검색할 이름 입력 
		scanf("%s", tmp);

		for (int i = 0; i < *num; i++)
		{
			if (!strcmp(arr[i]->name, tmp))              //찾는 이름이면 
			{


				for (int k = i; k < *num - 1; k++)             //배열 한칸씩 당기고 맨뒤 삭제
				{
					arr[k]->name = (char*)realloc(arr[k]->name, strlen(arr[k + 1]->name) + 1);
					arr[k]->bir = (char*)realloc(arr[k]->bir, strlen(arr[k + 1]->bir) + 1);
					arr[k]->pnum = (char*)realloc(arr[k]->pnum, strlen(arr[k + 1]->pnum) + 1);
					strcpy(arr[k]->name, arr[k + 1]->name);
					strcpy(arr[k]->bir, arr[k + 1]->bir);
					strcpy(arr[k]->pnum, arr[k + 1]->pnum);
				}

				free(arr[*num - 1]->name);    //동적할당 해제
				free(arr[*num - 1]->bir);
				free(arr[*num - 1]->pnum);

				(*num)--;              //인원수 감소
				k = 1;   //삭제완료 

				free(arr[*num]);   //마지막 배열 할당해제
				break;
			}
		}
		if (!k)   //찾는 이름이 없으면 출력 
			printf("NO MEMBER\n");
	}
}