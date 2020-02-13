/*#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
*/
/* 1 기본 알고리즘 */

//실습 1 세 수의 최대값 
/*
int main()
{
	int a, b, c;
	int max;
	scanf("%d %d %d", &a, &b, &c);

	max = a;
	if (max < b) max = b;
	if (max < c) max = c;

	printf("%d", max);

	return 0;
}
*/

//연습문제 1 4값의 최대값 최소값 
/*
int min4(int a, int b, int c, int d)
{
	int min;
	min = a;
	if (min > b) min = b;
	if (min > d) min = d;
	if (min > c) min = c;
	return min;

}
int max4(int a, int b, int c, int d)
{
	int max;
	max= a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;

	return max;
}
int main()
{
	int a, b, c, d;
	int max;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d\n",max4(a, b, c, d));
	printf("%d", min4(a, b, c, d));
}
*/

/*2 배열 구조체 */
//역순정렬 
/*
void swap(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
int main()
{
	
	int x[5];
	int i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		x[i] = rand()%100;
	}
	for (i = 0; i < 5; i++)
		printf("%d ",x[i]);
		
	for (i = 0; i < 5/2; i++)
		swap(&x[i], &x[4 - i]);

	printf("\n");

	for (i = 0; i < 5; i++)
		printf("%d ",x[i]);
	return 0;
}
*/

//c 언어 형식 으로 사용 매크로 
/*
#define swap(type,x,y)do{type t=x;x=y;y=t;}while(0)

void reverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
	{
		swap(int, arr[i], arr[n - i - 1]);
	}


}
int main()
{

	int x[5];
	int i;
	srand(time(NULL));
	for (i = 0; i < 5; i++)
	{
		x[i] = rand() % 100;
	}
	for (i = 0; i < 5; i++)
		printf("%d ", x[i]);

	reverse(x, 5);
	printf("\n");

	for (i = 0; i < 5; i++)
		printf("%d ", x[i]);
	return 0;
}
*/

//진법 변환 프로그램
/*
int convert(unsigned int x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEF";
	int digit = 0;

	if (x == 0) d[digit++] = dchar[0];
	else
	{
		while (x)
		{
			d[digit++] = dchar[x%n];
			x = x / n;
		}

	}
	return digit;
}

int main()
{

	int i;
	unsigned int a;
	int cd;
	int dgt;
	int retry = 0;
	char k[100];
	do
	{
		scanf("%u %d", &a, &cd);
		dgt = convert(a, cd, k);
		for (i = dgt - 1; i >= 0; i--)
			printf("%c", k[i]);
	

		printf("\n");
		scanf("%d", &retry);
	} while (retry);



	return 0;
}
*/
//연습문제 7번
/*
int convert(unsigned int x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEF";
	int digit = 0;

	if (x == 0) d[digit++] = dchar[0];
	else
	{
		while (x)
		{
			printf("%d|     %d ... %d\n", n, x, x%n);
			printf(" +----------\n");
			d[digit++] = dchar[x%n];
			x = x / n;
		}
		printf("      0\n");
	}
	return digit;
}

int main()
{

	int i;
	unsigned int a;
	int cd;
	int dgt;
	int retry = 0;
	char k[100];
	do
	{
		scanf("%u %d", &a, &cd);
		dgt = convert(a, cd, k);
		printf("%d진수로 ",cd);
		for (i = dgt - 1; i >= 0; i--)
			printf("%c", k[i]);
		printf(" 입니다. 다시?(1,0):");


		printf("\n");
		scanf("%d", &retry);
	} while (retry);



	return 0;
}
*/
//연습문제 8 9번
/*
void arrcpy(int *x, int *y, int n)
{
	int i;
	for (i = 0; i < n; i++)
		y[i] = x[i];
}
void arr_rcpy(int *x, int *y, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		y[n - i - 1] = x[i];
	}

}
*/

//연습문제 10번 
/*
void swap(int *x, int*y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
void shuffle(int *arr, int n)
{
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		swap(&arr[rand()%(n-1)], &arr[rand()%(n-1)]);
	}
}
int main()
{
	int *arr;
	int n;
	int i;
	srand(time(NULL));

	scanf("%d", &n);
	arr =(int*) malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		arr[i] = rand()%45;
	}
	for (i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");

	shuffle(arr, n);

	for (i = 0; i < n; i++)
		printf("%d ",arr[i]);
	free(arr);
	return 0;
}
*/

//소수 구하기

//소수 알고리즘 1
/*
int main()
{
	int count = 0;
	int i, n;
	for (n = 2; n <= 1000; n++)
	{
		for (i = 2; i < n; i++)
		{
			count++;
			if (n%i == 0)
				break;
		}
		if (i == n) printf("%d\n", n);

	}
	printf("%d", count);

	return 0;
}

*/
//소수 알고리즘 2
/*
int main()
{
	int prime[1000];
	int ptr = 0;
	int count = 0;
	int i, n;
	prime[ptr++]=2;
	for (n = 3; n <= 1000; n=n+2)
	{
		for (i = 1; i < ptr; i++)
		{
			count++;
			if (n%prime[i] == 0)
				break;
		}
		if (i == ptr)
		{
			printf("%d\n", n);
			prime[ptr] = n;
			ptr++;
		}
	}

	printf("%d", count);


	return 0;
}
*/
//소수 알고리즘 3
/*
int main()
{
	int prime[1000];
	int ptr = 0;
	int count = 0;
	int i, n;
	int flag = 0;
	prime[ptr++] = 2;
	prime[ptr++] = 3;
	for (n = 5; n <= 1000; n = n + 2)
	{
		flag = 0;
		for (i = 1; count++,prime[i]*prime[i]<=n; i++)
		{
			count++;
			if (n%prime[i] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			printf("%d\n", n);
			prime[ptr] = n;
			ptr++;
		}
	}

	printf("%d", count);


	return 0;
}
*/
//지난 날수 구하기
/*
int isLeapYear(int year)
{
	if (year % 4 == 0)
	{
		if (year % 400 == 0) return 1;
		if (year % 100 == 0) return 0;
	}
	else return 0;
}

int dayOfYear(int y, int m, int d)
{
	int days=0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (isLeapYear(y))	month[1]++;

	for (int i = 0; i < m - 1; i++)
	{
		days += month[i];
	}
	days += d;
	return days;
}
int main()
{
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);
	printf("%d", dayOfYear(y, m, d));


	return 0;
}
*/
