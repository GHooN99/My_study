#include "my_func.h"
void Delete(person **arr, int *num)             //���� ���� �Լ� 
{
	char tmp[101];
	int k = 0;
	if (!(*num))                   //����ο��� 0���̸� ��� 
		printf("NO MEMBER\n");

	else
	{
		printf("Name:");               //�˻��� �̸� �Է� 
		scanf("%s", tmp);

		for (int i = 0; i < *num; i++)
		{
			if (!strcmp(arr[i]->name, tmp))              //ã�� �̸��̸� 
			{


				for (int k = i; k < *num - 1; k++)             //�迭 ��ĭ�� ���� �ǵ� ����
				{
					arr[k]->name = (char*)realloc(arr[k]->name, strlen(arr[k + 1]->name) + 1);
					arr[k]->bir = (char*)realloc(arr[k]->bir, strlen(arr[k + 1]->bir) + 1);
					arr[k]->pnum = (char*)realloc(arr[k]->pnum, strlen(arr[k + 1]->pnum) + 1);
					strcpy(arr[k]->name, arr[k + 1]->name);
					strcpy(arr[k]->bir, arr[k + 1]->bir);
					strcpy(arr[k]->pnum, arr[k + 1]->pnum);
				}

				free(arr[*num - 1]->name);    //�����Ҵ� ����
				free(arr[*num - 1]->bir);
				free(arr[*num - 1]->pnum);

				(*num)--;              //�ο��� ����
				k = 1;   //�����Ϸ� 

				free(arr[*num]);   //������ �迭 �Ҵ�����
				break;
			}
		}
		if (!k)   //ã�� �̸��� ������ ��� 
			printf("NO MEMBER\n");
	}
}