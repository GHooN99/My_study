#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//문제 1 
/*
int sum(int n)		//1부터 n 까지 합을 int 로 반환
{
	int s = 0;
	for (int i = 1; i <= n; i++)
		s += i;
	return s;
}
int main()
{
	int x,s=0;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++)
		s += sum(i);

	printf("%d", s);

	return 0;
}
*/
//문제 2
/*
void ABC(int arr[], int k)		//k번째 정수부터 마지막 정수 중 큰 정수찾고 위치 교환
{
	int i, max=arr[k],idx=k;
	for ( i = k; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			idx = i;
		}
	}

	int tmp = arr[k];
	arr[k] = arr[idx];
	arr[idx] = tmp;

}
int main()
{
	int arr[10];
	int i;

	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < 10; i++)
		ABC(arr,i);

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}
*/
//문제 3
/*
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int arr[50];
	int a, b, i, n;
	
	scanf("%d", &n);

	for ( i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	scanf("%d %d", &a, &b);

	swap(arr + a, arr + b);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
*/
//문제 4
/*
void shift(char *str)
{
	char tmp = str[0];
	for (int i = 0; i < strlen(str)-1; i++)
	{
		str[i] = str[i + 1];
	}
	str[strlen(str) - 1] = tmp;
}
int main()
{
	char str[100];
	int i;

	scanf("%s", str);
	for (i = 0; i < strlen(str); i++)
	{
		printf("%s\n",str);
		shift(str);
	}

	return 0;
}
*/
//문제 5
/*
typedef struct time
{
	int hour;
	int min;
	int sec;
}time;
time cal_time(time t1, time t2)
{
	time t3;

	int t1_sec, t2_sec,t3_sec;
	t1_sec = t1.hour * 3600 + t1.min*60 + t1.sec;
	t2_sec = t2.hour * 3600 + t2.min * 60 + t2.sec;
	
	t3_sec = t2_sec - t1_sec;

	t3.hour = t3_sec / 3600;
	t3.min = t3_sec % 3600 / 60;
	t3.sec = t3_sec % 3600 % 60;

	return t3;
}
int main()
{
	time t1, t2,t3;

	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

	t3 = cal_time(t1, t2);
	printf("%d %d %d", t3.hour, t3.min, t3.sec);

	return 0;
}
*/
//문제 6
/*
typedef struct student
{
	char name[9];
	int score;
}student;

int main()
{
	student st[5];
	int sum = 0;
	float avg;
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", &st[i].name, &st[i].score);
		sum += st[i].score;
	}
	avg = sum / 5.0;

	for (int i = 0; i < 5; i++)
	{
		if (st[i].score <= avg)
			printf("%s\n", st[i].name);
	}

	return 0;
}
*/
//문제 7
/*
int main()
{
	int *arr1,*arr2;
	int n, i;
	scanf("%d", &n);
	
	arr1 = (int*)calloc(n, sizeof(int));
	arr2 = (int*)calloc(n, sizeof(int));

	for ( i = 0; i < n; i++)
		scanf("%d", &arr1[i]);

	for (i = 0; i < n; i++)
		scanf("%d", &arr2[i]);

	for (i = 0; i < n; i++)
		printf("%d ", arr1[i]+arr2[n - i - 1]);

	free(arr1);
	free(arr2);

	return 0;
}
*/
//문제 8
/*
typedef struct student
{
	char name[8];
	int kor;	//국영수 
	int eng;
	int math;
	float avg;

}student;
int isGreat(student st)
{
	return (st.kor >= 90 || st.math >= 90 || st.eng >= 90);
}
int isBad(student st)
{
	return (st.kor < 70 || st.math < 70 || st.eng < 70);
}
int main()
{
	student *st;
	int n, i;

	scanf("%d", &n);

	st =(student*)calloc(n, sizeof(student));
	
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", &st[i].name, &st[i].kor,
			&st[i].eng, &st[i].math);
		st[i].avg = (st[i].eng + st[i].math + st[i].kor) / 3.0;
	}

	for (i = 0; i < n; i++)
	{
		printf("%s %.1f ", st[i].name, st[i].avg);
		
		if (isGreat(st[i]))
			printf("GREAT ");
		if (isBad(st[i]))
			printf("BAD ");
		
		printf("\n");
	}

	free(st);

	return 0;
}
*/