#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
/*
//재귀 상 하향식 분석 
//원 코드  
void recur2(int n)
{
	if (n > 0)
	{
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}
int main()
{
	recur2(3);
	return 0;
}
*/

// 상향식 분석 

/*
recur2(0) : x
recur2(1) : recur2(-1) / 1 /recur2(0) -> 1출력
recur2(2) : recur2(0) / 2 / recur2(1) -> 2 출력 , 1출력 
recur2(3) : recur2(1) / 3 / recur2(2) -> 1출력 , 3출력 ,2출력 ,1출력 

결과: 1,3,2,1 출력 
*/

//하향식 분석 
/*
				recur2(1) /			 3 /			  recur2(2)
		recur2(-1)/1/recur2(0)      출력2		recur2(0)  / 2    /      recur2(1)
		x		출력1	x							x     출력3    recur2(-1) / 1 / recur2(0)
					                                               x          출력4   x
결과 : 1, 3, 2, 1 출력
*/

//재귀->비재귀
//꼬리제거
/*
void recur2(int n)
{
	Top : 
	if (n > 0)
	{
		recur2(n - 2);
		printf("%d\n", n);
		n--;
		goto Top;  //꼬리 제거
	}
}
int main()
{
	recur2(3);
	return 0;
}

*/
// 재귀 의 제거 -> 스택자료구조 를 이용 
/*
void recur2(int n)
{
Top:
	if (n > 0)
	{
		Push(stk, n);	//n을 푸시 
		n=n-2;   //n줄이고 
		goto Top;  //
	}
	if (!isEmtpy) //비어있지 않은 스택이면
	{
		Pop(stk, n);   //n을 팝
		printf("%d\n", n);   
		n = n - 1;  //n줄이고
		goto Top;
	}

	
}
int main()
{
	recur2(3);
	return 0;
}
*/