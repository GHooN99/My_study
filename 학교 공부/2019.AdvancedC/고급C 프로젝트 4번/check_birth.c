#include "my_func.h"
int check_birth(char *str, int bir)              //���� üũ �Լ� 
{
	int k;
	k = atoi(str);
	k = k % 10000 / 100;
	if (k == bir)	return 1;              //ã�� �����̸� 1 ��ȯ 

	return 0;
}