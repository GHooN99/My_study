#pragma warning(disable:4996)
#include <stdio.h>

//巩力 1-1
/*
int maxmin(int *ar)
{
	int max=-99, min=100000;
	int i, j, *par;

	for (par = ar; ; par++)
	{
		if (!*par)
			break;

		if (max < *par)
			max = *par;

		if (min > *par)
			min = *par;
			
	}

	return (max - min);
}
int main()
{
	int N, *pN, ar[100];
	
	int *par;

	int i,k;
	pN = &N;


	scanf("%d", pN);

	for (i = 0; i < *pN; i++)
	{
		
		for (par = ar; ; par++)
		{
			scanf("%d", par);

			if (!*par)
				break;
		}
			
		k=maxmin(ar);

		printf("%d\n", k);

	}

	return 0;
}
*/
//巩力 1-2
/*
int abs(int num)
{
	if (num > 0)
		return num;
	else
		return -num;
}

int* maxmin(int *ar)
{
	int max = -99, min = 100000;
	int smin = 100000;

	int i, j, *par,s,*ps=NULL;

	for (par = ar; ; par++)
	{
		if (!*par)
			break;

		if (max < *par)
			max = *par;

		if (min > *par)
			min = *par;

	}

	 s=(max - min);

	 for (par = ar; ; par++)
	 {
		 if (!*par)
			 break;

		 if (smin > abs(s-*par))
		 {
			 smin = abs(s-*par);
			 ps = par;
		 }
	 }

	 return ps;
}

int main()
{
	int N, *pN, ar[100];

	int *par;

	int i, *k;
	pN = &N;


	scanf("%d", pN);

	for (i = 0; i < *pN; i++)
	{

		for (par = ar; ; par++)
		{
			scanf("%d", par);

			if (!*par)
				break;
		}

		k = maxmin(ar);

		printf("%d\n", *k);

	}

	return 0;
}
*/
//巩力 2-1 
/*
int ispastnum(int n,int *ar)
{
	int *i;
	for (i = ar; i < ar + 6; i++)
	{
		if (*i == n)
			return 1;
	}

	return 0;
}

int main()
{
	int num[6];

	int cnt = 0, *pnum, *pnum2, pastnum[6], k = 0;

	for (pnum = num; pnum < num + 6; pnum++)
		scanf("%d", pnum);

	//
	
	for (pnum = num; pnum < num + 6; pnum++)
	{
		cnt = 0;

		for (pnum2 = pnum; pnum2 < num + 6; pnum2++)
		{
			if (*pnum == *pnum2)
				cnt++;

		}

		if (!ispastnum(*pnum,pastnum))
		{
			if (cnt > 1)
			{
				*(pastnum+k) = *pnum;

				printf("%d %d\n", *pnum, cnt);

				k++;
			}
		}
	}

	if (!k)
		printf("0");

	return 0;

}

*/
//巩力 2-2
/*
int newnum(int *arr)
{
	int *parr, i,in;

	for (i = 1; i < 46; i++)
	{
		in = 1;

		for (parr = arr; parr < arr + 6; parr++)
		{
			if (*parr == i)
			{
				in = 0;
				break;
			}
		}

		if (in)
			return i;

	}

}

int correct(int *arr)
{
	int *parr, *parr2,cnt = 0;


	for (parr = arr; parr < arr + 6; parr++)
	{
		
		for (parr2 = parr+1; parr2 < arr + 6; parr2++)
		{
			if (*parr == *parr2)
			{
				*parr = newnum(arr);
				cnt++;
			}
		}
	}

	if (cnt>0)
		return 1;
	else
		return 0;
}

int main()
{
	int num[6];

	int cnt = 0, *pnum, *pnum2, pastnum[6], k = 0,crt;


	for (pnum = num; pnum < num + 6; pnum++)
		scanf("%d", pnum);


	crt = correct(num);


	printf("%d\n", crt);


	for (pnum = num; pnum < num + 6; pnum++)
		printf("%d ", *pnum);


	return 0;
}
*/
//巩力 3
/*
void input(char *p, int N)
{
	char *par;

	for (par = p; par < p + N; par++)
		scanf("%c", par);

}
void upper(char *p, int N)
{
	char *par;

	for (par = p; par < p + N; par++)
	{
		if ('A' <= *par&&*par <= 'Z')
			printf("%c", *par);
	}
	printf("\n");

}
void lower(char *p, int N)
{
	char *par;

	for (par = p; par < p + N; par++)
	{
		if ('a' <= *par&&*par <= 'z')
			printf("%c", *par);
	}
	printf("\n");
}
int DOUBLE(char *p, int N)
{
	char *par;

	int num=0,digit=1;
	for (par = p; par < p + N; par++)
	{
		if ('0' <= *par&&*par <= '9')
		{
			num = num*10+(int)(*par - '0');
		}
	}

	return num * 2;
}
int main()
{

	char ch[20];
	int N;

	scanf("%d", &N);

	input(ch,N);
	upper(ch,N);
	lower(ch, N);
	printf("%d",DOUBLE(ch, N));



	return 0;

}
*/
//巩力 4
/*
void u_sort(int *x, int n)
{
	int *i, *j, tmp;

	for (i = x; i < x + n - 1; i++)
	{
		for (j = x; j < x + n - 1; j++)
		{
			if (*(j) > *(j + 1))
			{
				tmp = *(j);
				*(j) = *(j + 1);
				*(j + 1) = tmp;
			}
		}
	}

}

void d_sort(int *x, int n)
{
	int *i, *j, tmp;

	for (i = x; i < x+n-1; i++)
	{
		for (j = x; j <x+ n - 1; j++)
		{
			if (*(j) < *(j+1))
			{
				tmp = *(j);
				*( j) = *( j + 1);
				*(j + 1) = tmp;
			}
		}
	}
}

int input(int *ar)
{
	int *par,n=0;
	for (par = ar, n; ; par++, n++)
	{
		scanf("%d", par);
		if (!*par)
			break;
	}
	return n;
}

void output(int *ar,int cnt)
{
	int *par;

	for (par = ar; par < ar + cnt; par++)
		printf("%d ", *par);
}

void find(int *a, int*b, int n, int m)
{
	int *pa, *pb,tmp;
	for (pa = a; pa < a + n; pa++)
	{
		for (pb = b; pb < b + m; pb++)
		{
			if (*pa < *pb)
			{
				tmp = *pa;
				*pa = *pb;
				*pb = tmp;
			}
		}
	}



}

int main()
{
	int a[10], b[10];
	int *pa=&a, *pb=&b;
	int n, m;
	
	n=input(pa);
	m=input(pb);

	find(pa, pb, n, m);

	d_sort(pa, n);
	u_sort(pb, m);

	output(pa, n);
	printf("\n");

	output(pb, m);

	return 0;

}
*/