#include "my_func.h"

void registration(person **arr, int *num, int *MAX_NUM)    //1�� ����Լ� 
{
	int idx = 0, i;
	int add = 0;
	char tmp[101];
	if ((*num) + 1 > *MAX_NUM)                 //�����÷ο� ó��
		printf("OVERFLOW\n");
	else
	{
		arr[*num] = (person*)malloc(sizeof(person));
		printf("Name:");                //�̸� �Է� 
		gets(tmp);
		if (*num)               //ù����� �ƴҽ� 
		{
			for (i = 0; i < *num; i++)
			{
				if (strcmp(arr[i]->name, tmp) > 0)                 //�̸��� ��ġ ã�� 
				{
					for (int k = *num - 1; k >= i; k--)                //��ġ�� ã���� �迭 �ڷ� �а� �̸� ���� 
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
					add = 1;					//�̸��� �߰��� 
					break;
				}
			}
			if (!add)    //�̸��� �߰� ���������� ������ �߰� 
			{
				arr[i]->name = (char*)malloc(strlen(tmp) + 1);
				strcpy(arr[i]->name, tmp);
			}
			idx = i;
		}

		else          //ù��Ͻ� 0���� �̸� ���� 
		{

			arr[0]->name = (char*)malloc(strlen(tmp) + 1);
			strcpy(arr[0]->name, tmp);
			idx = 0;
		}

		//������ ��ȭ��ȣ ���� ���� ��� 
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


		(*num)++;                    //���� �ο��� ���� 
		printf("<<%d>>\n", *num);
	}

	strcpy(tmp, "\0");
}