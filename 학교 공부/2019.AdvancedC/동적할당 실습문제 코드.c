#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//巩力 1
/*
int main()
{
	int *arr;
	int n,i, sum=0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", arr + i);
		sum += *(arr + i);

	}

	printf("%d", sum);

	free(arr);


	return 0;

}
*/
//巩力 2
/*
int main()
{
	float *arr,max=-99;
	int n, i;
	scanf("%d", &n);

	arr = (float*)malloc(sizeof(float)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%f", arr + i);
		if (max < *(arr + i))
			max = *(arr + i);

	}
	printf("%.2f", max);
	free(arr);

	return 0;
}
*/
//巩力 3
/*
int main()
{
	int *arr;
	int n,m, i, sum = 0;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
		scanf("%d", arr + i);

	scanf("%d", &m);

	arr=(int*)realloc(arr, sizeof(int)*(n - m));

	for ( i = 0; i < n-m; i++)
		printf("%d\n", *(arr + i));
	
	free(arr);

	return 0;
}
*/
//巩力 4
/*
int main()
{
	char **pch;
	int n, m, i, j,k='a';

	scanf("%d %d", &n, &m);

	pch = (char**)malloc(sizeof(char*)*n);

	for (i = 0; i < n; i++)
		pch[i] = (char*)malloc(sizeof(char)*m);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{

			pch[i][j] = (char)k;

			k++;
			if (k > 'z')
			{
				k = 'A';
			}
			if (k == 'Z' + 1)
				k = 'a';
		}
	}

	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < m; j++)
			printf("%c ", pch[i][j]);
		printf("\n");
	}

	for (i = 0; i < n; i++)
		free(pch[i]);
	
	free(pch);

	return 0;
}
*/
//巩力 5
/*
int main()
{
	char *pch;
	char tmp[100];
	int n,i;
	char f1, f2;
	int cnt[2] = { 0 };
	scanf("%d", &n);
	getchar();
	pch = (char*)malloc(sizeof(char)*n+1);

	gets(tmp);
	strcpy(pch, tmp);
	
	scanf("%c %c", &f1, &f2);
	for (i = 0; i < n; i++)
	{
		if (f1 == pch[i])	cnt[0]++;
		if (f2 == pch[i])	cnt[1]++;
	}
	for (i = 0; i < 2; i++)
		printf("%d ", cnt[i]);

	free(pch);

	return 0;
}
*/
//巩力 6
/*
typedef struct student
{
	char *name;
	int k, e, m;
	float avg;
}student;
int isgr(student st)
{
	if (st.e >= 90) return 1;
	if (st.m >= 90) return 1;
	if (st.k >= 90) return 1;

	return 0;
}
int isbd(student st)
{
	if (st.e < 70) return 1;
	if (st.m <70) return 1;
	if (st.k < 70) return 1;

	return 0;
}
int main()
{
	student *st;
	int n,i;
	char tmp[20];
	scanf("%d", &n);
	st = (student*)malloc(sizeof(student)*n);

	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %d",tmp,&st[i].k, &st[i].e, &st[i].m);
		st[i].name=(char*)malloc(strlen(tmp)+1);
		strcpy(st[i].name,tmp);
		st[i].avg = (st[i].k + st[i].e + st[i].m) / 3.0;
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %.1f ", st[i].name, st[i].avg);

		if (isgr(st[i])) printf("GREAT ");
		if (isbd(st[i])) printf("BAD");

		printf("\n");
	}
	for (i = 0; i < n; i++)
		free(st[i].name);
	free(st);

	return 0;
}
*/
//巩力 7
/*
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int main()
{
	int n,i;
	int *arr;
	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	for ( i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (i = 0; i < n-1; i++)
	{
		if (arr[i] > arr[i + 1])
			swap(arr+i, arr+i+1);
	}
	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	free(arr);

	return 0;
}
*/
//巩力 8
/*
int main()
{
	char tmp[100];
	char *pstr=NULL;
	int n, cnt = 0;
	
	scanf("%d", &n);
	getchar();
	gets(tmp);
	pstr = (char*)malloc(sizeof(char)*(n + 1));
	strcpy(pstr, tmp);
	
	for (int i = 0; i < n; i++)
	{
		if(!strncmp((pstr+i),"cat", 3))
			cnt++;
	}
	printf("%d", cnt);

	free(pstr);


	return 0;
}
*/
//巩力 9
/*
int main()
{
	int n,i;
	char **pstr;
	int tmp[120];
	int min = 120, idx = 0;
	scanf("%d", &n);
	getchar();
	pstr = (char**)malloc(sizeof(char**)*n);
	for (i = 0; i < n; i++)
	{
		gets(tmp);
		pstr[i] = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
		strcpy(pstr[i], tmp);
	}
	for (i = 0; i < n; i++)
	{
		if (strlen(pstr[i]) < min)
		{
			min = strlen(pstr[i]);
			idx = i;
		}
	}
	printf("%s", pstr[idx]);

	for (i = 0; i < n; i++)
		free(pstr[i]);

	free(pstr);

	return 0;
}
*/
//巩力 10
/*
void swap(char **str1, char **str2)
{
	char **tmp=NULL;
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
void sort(char **str,int size)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (strlen(str[j]) < strlen(str[j + 1]))
			{
				swap(&str[j],&str[j + 1]);
			}
		}
	}
}
int main()
{
	int n,i,j;
	char **str;
	char tmp[101];

	scanf("%d", &n);
	str = (char**)malloc(sizeof(char**)*n);
	getchar();

	for (i = 0; i < n; i++)
	{
		gets(tmp);
		str[i] = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
		strcpy(str[i], tmp);
		
	}

	sort(str,n);

	for (i = 0; i < n; i++)
		printf("%s\n", str[i]);

	for (i = 0; i < n; i++)
		free(str[i]);

	free(str);

	return 0;
}
*/
//巩力 11
/*
void add_index(int **arr, int *size)
{
	int *tmp,i;
	
	tmp = (int*)malloc(sizeof(int)*(*size +3));

	for (i = 0; i < *size; i++)
	{
		tmp[i] = (*arr)[i];
	}
	free(*arr);

	*arr = tmp;

	*size += 3;

	
}
int main()
{
	int *arr;
	int i, j, k;
	int size = 5;
	int n,idx=0;

	arr = (int*)malloc(sizeof(int) * size);

	for ( i = 0; ; i++)
	{
		scanf("%d", &n);
		if(i<size)
		arr[i] = n;
		else if (i == size)
		{
			add_index(&arr, &size);
			arr[i] = n;
		}
		if (n == -1)
			break;
	}
	idx = i+1;

	for (i = 0; i < idx; i++)
	{
		printf(" %d", arr[i]);

	}

	free(arr);

	return 0;
}
*/
//巩力 12
/*
int main()
{
	int n,k=0;
	int *parr,*parr2;

	scanf("%d", &n);
	
	parr = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++)
		parr[i] = i;

	parr2=(int*)malloc(sizeof(int)*(n-1));

	for (int i = 0; i < n; i++)
	{
		if (i != (n-1) / 2)
		{
			parr2[k] = parr[i];
			k++;
		}

	}
	for (int i = 0; i < n - 1; i++)
		printf(" %d", parr2[i]);

	free(parr);
	free(parr2);

	return 0;
}
*/
//巩力 13
/*
void swap(char **str1, char **str2)
{
	char **tmp = NULL;
	tmp = *str1;
	*str1 = *str2;
	*str2 = tmp;
}
void sort(char **str, int size)
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (strcmp(str[j],str[j+1])>0)
			{
				swap(&str[j], &str[j + 1]);
			}
		}
	}
}
int main()
{
	int n, i, j;
	char **str;
	char tmp[101];

	scanf("%d", &n);
	str = (char**)malloc(sizeof(char**)*n);
	getchar();

	for (i = 0; i < n; i++)
	{
		gets(tmp);
		str[i] = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
		strcpy(str[i], tmp);

	}

	sort(str, n);

	for (i = 0; i < n; i++)
		printf("%s\n", str[i]);

	for (i = 0; i < n; i++)
		free(str[i]);

	free(str);

	return 0;
}
*/