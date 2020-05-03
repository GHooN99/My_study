
#include "my_func.h"

int main()
{
	person **per_list = NULL;    //이중포인터 
	int per_num = 0;         //변수선언 
	int MAX_NUM;
	int n;
	printf("Max_num:");
	scanf("%d", &MAX_NUM);
	per_list = (person**)malloc(sizeof(person*)*MAX_NUM);            //동적할당 

	while (1)
	{
		print_info();               //메시지 출력 
		scanf("%d", &n);
		getchar();
		switch (n)
		{
		case 1:
			registration(per_list, &per_num, &MAX_NUM);          //등록 함수
			break;
		case 2:
			showALL(per_list, &per_num);              //정보 출력함수
			break;
		case 3:
			Delete(per_list, &per_num);            //등록 제거 함수 
			break;
		case 4:
			Findbybirth(per_list, &per_num);    //생일로 찾는 함수 
			break;
		case 5:
			RegFromFile(per_list, &per_num, &MAX_NUM);   //파일로 읽어와서 등록하는 함수 
			break;
		case 6:
			SaveFromFile(per_list, &per_num);    //현재까지 등록된 사람 파일로 저장 

			for (int i = 0; i < per_num; i++)    //할당된 공간 순서대로 해제
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