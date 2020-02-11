
#include "my_func.h"

int main()
{
	person **per_list = NULL;    //���������� 
	int per_num = 0;         //�������� 
	int MAX_NUM;
	int n;
	printf("Max_num:");
	scanf("%d", &MAX_NUM);
	per_list = (person**)malloc(sizeof(person*)*MAX_NUM);            //�����Ҵ� 

	while (1)
	{
		print_info();               //�޽��� ��� 
		scanf("%d", &n);
		getchar();
		switch (n)
		{
		case 1:
			registration(per_list, &per_num, &MAX_NUM);          //��� �Լ�
			break;
		case 2:
			showALL(per_list, &per_num);              //���� ����Լ�
			break;
		case 3:
			Delete(per_list, &per_num);            //��� ���� �Լ� 
			break;
		case 4:
			Findbybirth(per_list, &per_num);    //���Ϸ� ã�� �Լ� 
			break;
		case 5:
			RegFromFile(per_list, &per_num, &MAX_NUM);   //���Ϸ� �о�ͼ� ����ϴ� �Լ� 
			break;
		case 6:
			SaveFromFile(per_list, &per_num);    //������� ��ϵ� ��� ���Ϸ� ���� 

			for (int i = 0; i < per_num; i++)    //�Ҵ�� ���� ������� ����
			{
				free(per_list[i]->bir);
				free(per_list[i]->name);
				free(per_list[i]->pnum);
			}
			for (int i = 0; i < per_num; i++)
				free(per_list[i]);
			free(per_list);

			return 0;
		default:
			break;
		}

	}


}