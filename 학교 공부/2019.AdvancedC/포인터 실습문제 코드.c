#pragma	warning(disable:4996)
#include <stdio.h>
//1번
/*
int main()
{


	char ch[10];
	char *i, *j;
	int cnt = 0;
	int max = 0;
	char mc;

	char *pch;
	pch = ch;
	
	for (i = pch; i <= (pch + 9); i++)
	{
		scanf("%c", i);
	}

	for (i = pch; i <=(pch+9); i++)
	{
		cnt = 0;
		for (j = pch; j <= (pch+9); j++)
		{
			if (*i == *j)
				cnt++;
		}

		if (max < cnt)
		{
			max = cnt;
			mc = *i;
		}


	}


	printf("%c %d", mc, max);


	return 0;

}

*/
//2번
/*
void input(int *x, int *y, int*z)
{
	scanf("%d %d %d", x,y,z);
}
void output(int *x, int *y, int*z)
{
	printf("%d %d %d", *x, *y, *z);
}
int main()
{
	int x, y, z;
	input(&x,&y,&z);
	output(&x,&y,&z);


	return 0;

}
*/
//3번
/*
void swap(int *x, int *y)
{
	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}
int main()
{
	int n[50];
	int s;
	int i;
	int a, b;
	scanf("%d", &s);

	for (i = 0; i < s; i++)
		scanf("%d", n + i);
	
	scanf("%d %d", &a, &b);
	swap(n+a,n+b);

	for (i = 0; i < s; i++)
		printf("%d ",*(n + i));

	return 0;
}
*/
//4번
/*
int* mid(int *x)
{

	int i,j;
	int temp;

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (*(x+j) < *(x+j+1))
			{
				temp = *(x+j);
				*(x+j) =*( x+1+j);
				*(x +j+ 1) =temp;
			}

		}
	
	}

	return x + 1;

}
int main()
{
	int x[3];

	int i, *j;

	for (i = 0; i < 3; i++)
		scanf("%d",(x + i));

		j = mid(x);
		printf("%d", *j);


}
*/
//5번
/*
void gcdlcm(int x, int y, int *px, int *py)
{

	int i, j;
	int gcd, lcm;
	int min = x;
	if (min > y)
		min = y;


	for (i = 1; i <= min; i++)
	{
		if (x%i == 0 && y%i == 0)
			gcd = i;

	}
	lcm =  (x*y)/gcd;

	*px = gcd;
	*py = lcm;

}

int main()
{
	int x, y;
	int *px = &x;
	int *py = &y;
	scanf("%d %d", px, py);
	gcdlcm(x, y, px, py);

	printf("%d %d",x,y);



}
*/
//6번
/*
void strcopy(char *a, char *b)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		*(a + i) = *(b + i);
	}

}



int main() {

	char ch[6];
	char a[6];

	int i;
	for (i = 0; i < 6; i++)
		scanf("%c", ch + i);

	strcopy(a,ch);
	for (i = 0; i < 6; i++)
		printf("%c", *(a + i));
	return 0;
}
*/
//7번
/*
void addArray(int *x, int *y, int *z, int n)
{
	int i,j;
	for (i = 0,j=n-1; i < n,j>=0; i++,j--)
	{
		*(z + i) = *(x + i) + *(y + j);
	}


}

int main()
{
	int a[20], b[20],c[20] ,n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (a+i));
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (b + i));
	}

	addArray(a, b, c, n);

	for (int i = 0; i < n; i++)
		printf(" %d", *(c + i));

	return 0;

}


*/
//8번
/*
int arrsum(int *px, int *py)
{
	int sum = 0;
	for (int *i = px; i <= py; i++)
	{
		sum += (*i);
	}
	return sum;

}

int main()
{

	int n, s, e;
	int x[100];
	int sum;
	scanf("%d %d %d",&n,&s,&e);

	for (int i = 0; i < n; i++)
		scanf("%d", (x + i));

	sum=arrsum(x + s, x + e);

	printf("%d", sum);



	return 0;

}

*/
//9번
/*
int add_to_k(int *px, int *py)
{
	int sum = 0;
	for (int *i = px; i <= py; i++)
	{
		sum += (*i);
	}
	return sum;

}

int main()
{

	int n;
	int x[100];
	int sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", x + i);
	}
	
	for (int i = 0; i < n; i++)
	{
		sum += add_to_k(x, x + i);
	
	}

	printf("%d", sum);


	return 0;

}


*/
//10번
/*
void abc(int *px, int k)
{

	int i, j,temp,pos;

	int max ;

		for (i = 10-k; i < 10; i++)
		{
			if (i == 10-k)
			{
				max = *(px + i);
				pos = i;
			}
			if (*(px + i) > max)
			{
				max = *(px + i);
				pos = i;
			}
		}
		
		temp = *(px+10-k);
		*(px+10-k) = max;
		*(px + pos) = temp;
		
}



int main()
{
	
	int x[10];
	int i, j;
	for( i = 0; i < 10; i++)
		scanf("%d", x + i);


	for (i = 10; i > 1; i--)
	{
		abc(x, i);

	}
	for ( i = 0; i < 10; i++)
	printf(" %d", *(x + i));


}
*/













































