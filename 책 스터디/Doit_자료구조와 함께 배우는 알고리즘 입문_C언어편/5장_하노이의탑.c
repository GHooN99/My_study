#pragma warning(disable:4996)
#include <stdio.h>

void move(int no, int x, int y) //원반 1~ no을  기둥 x 에서 기둥 y 로 옮김 
{
	if (no > 1) //1번 
	{
		move(no - 1, x, 6 - x - y);  // 중간 기둥의 번호는 6-x-y 로 가능 
	}

	printf("원반 %d 을 %d번기둥 에서 %d번기둥 로 옮김\n",no,x,y); // 2번 (1번이 실행된후 혹은 1,3 이 실행이 안될때 출력)

	if (no > 1)//3번 
	{
		move(no - 1, 6 - x - y , y);   //중간기둥 6-x-y
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	move(n, 1, 3); //n개를 1기둥에서 3기둥으로 옮김 
	return 0;
}


