#include "my_func.h"
int check_birth(char *str, int bir)              //생일 체크 함수 
{
	int k;
	k = atoi(str);
	k = k % 10000 / 100;
	if (k == bir)	return 1;              //찾는 생일이면 1 반환 

	return 0;
}