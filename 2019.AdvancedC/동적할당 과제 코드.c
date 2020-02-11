#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//1번
/*
void compareString(char *str1, char *str2)
{
	if (!strcmp(str1, str2))
		printf("identical");
	else
		printf("different");
}

int main()
{

	char *str1=NULL, *str2 = NULL;
	char tmp[50];

	gets(tmp);
	str1 = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
	strcpy(str1, tmp);

	gets(tmp);
	str2 = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
	strcpy(str2, tmp);

	compareString(str1, str2);

	free(str1);
	free(str2);

	return 0;
}
*/
//2번
/*
struct st
{
	char *str;
	int cnt;
};
typedef struct st st;
void swap(st *st1, st *st2)
{
	st tmp;
	tmp = *st1;
	*st1 = *st2;
	*st2 = tmp;
}
int main()
{
	char vowel[10] = 
	{ 'a','e','i','o','u'
	,'A','E','I','O','U' };

	char tmp[100];
	int n,i,j,k,cnt;
	st *st1;

	scanf("%d", &n);
	getchar();
	st1 = (st*)malloc(sizeof(st)*n);

	for ( i = 0; i < n; i++)
	{
		cnt = 0;
		gets(tmp);
		for (j = 0; j < strlen(tmp); j++)
		{
			for (k = 0; k < 10; k++)
			{
				if (tmp[j] == vowel[k])
					cnt++;
			}
		}
		st1[i].cnt = strlen(tmp) - cnt;
		st1[i].str = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
		strcpy(st1[i].str, tmp);
		
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n-1; j++)
		{
			if (st1[j].cnt < st1[j + 1].cnt)
				swap(&st1[j], &st1[j + 1]);
		}
	}

	for (i = 0; i < n; i++)
		printf("%s\n", st1[i].str);


	for (i = 0; i < n; i++)
		free(st1[i].str);
	free(st1);

	return 0;
}
*/
//3-1번
/*
struct student
{
	char *studentName;
	char id[5];
	char *subjectName;
	double subjectScore;
};
typedef struct student st;
void swap(st *st1, st *st2)
{
	st tmp;
	tmp = *st1;
	*st1 = *st2;
	*st2 = tmp;
}
int main()
{
	st *st1;
	int n,m,i,j,k;
	char tmp[101],tmp2[101];

	scanf("%d", &n);
	getchar();

	st1 = (st*)malloc(sizeof(st)*n);

	for ( i = 0; i < n; i++)
	{
		scanf("%s %s %s %lf", tmp, st1[i].id, tmp2, &st1[i].subjectScore);
		st1[i].studentName = (char*)malloc(sizeof(char)*strlen(tmp) + 1);
		st1[i].subjectName = (char*)malloc(sizeof(char)*strlen(tmp2) + 1);
		strcpy(st1[i].studentName, tmp);
		strcpy(st1[i].subjectName, tmp2);
		
	}
	scanf("%d", &k);
	k--;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (st1[j].subjectScore < st1[j + 1].subjectScore)
				swap(&st1[j], &st1[j + 1]);
		}
	}
	printf("%s %s %s %.2lf", st1[k].studentName, st1[k].id, st1[k].subjectName, st1[k].subjectScore);

	for (i = 0; i < n; i++)
	{
		free(st1[i].studentName);
		free(st1[i].subjectName);
	}
	free(st1);



	return 0;
}
*/
//3-2번
/*
struct subject
{
	char *name;		//할당필요 strlen 개
	double score;
};
struct student
{
	char *name;
	char id[5];
	int numSubject;
	struct subject *psub;	//할당필요 numSub 개
	double avg;
};
typedef struct student st;
void swap(st *st1, st *st2)
{
	st tmp;
	tmp = *st1;
	*st1 = *st2;
	*st2 = tmp;
}
int find_idx(struct subject *sb,int n)
{
	int idx = 0;
	int max=0;
	for (int i = 0; i < n; i++)
	{
		if (sb[i].score > max)
		{
			max = sb[i].score;
			idx = i;
		}
	}
	return idx;
}
double cal_avg(int *x, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += x[i];
	}
	return sum / n;
}
int main()
{

	st *st1;
	int n, m, i, j, k,idx=0,score[20];
	char tmp[101], tmp2[101];
	char subtmp[10][100];
	char s;

	scanf("%d", &n);
	getchar();

	st1 = (st*)malloc(sizeof(st)*n);	//1

	for (i = 0; i < n; i++)
	{
		scanf("%s %s", tmp, st1[i].id);
		st1[i].name = (char*)malloc(sizeof(char)*strlen(tmp) + 1); //2
		strcpy(st1[i].name, tmp);

		for (j = 0;; j++)
		{
			s=getchar();
			if(s=='\n')
				break;
			scanf("%s %d", subtmp[j],&score[j]);
			
		}
		st1[i].numSubject = j;

		st1[i].psub = (struct subject*)malloc
		(sizeof(struct subject)*st1[i].numSubject);	//3

		for (j = 0;j<st1[i].numSubject;j++)
		{
			st1[i].psub[j].name = (char*)malloc	//4
			(sizeof(char)*strlen(subtmp[j]) + 1);

			strcpy(st1[i].psub[j].name, subtmp[j]);

			st1[i].psub[j].score = score[j];
		}
		st1[i].avg = cal_avg(&score, st1[i].numSubject);
	}

	scanf("%d", &k);
	k--;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (st1[j].avg < st1[j + 1].avg)
				swap(&st1[j], &st1[j + 1]);
			if (st1[j].avg == st1[j + 1].avg)
			{
				if(strcmp(st1[j].id , st1[j + 1].id)>0)
					swap(&st1[j], &st1[j + 1]);
			}
		}
	}
	
	idx=find_idx(st1[k].psub,st1[k].numSubject);

	printf("%s %s %.2lf %s %.2lf",
		st1[k].name,st1[k].id, st1[k].avg,
		st1[k].psub[idx].name,st1[k].psub[idx].score);



	for (i = 0; i < n; i++)
	{
		for (j = 0; j < st1[i].numSubject; j++)
			free(st1[i].psub[j].name);		//4
		free(st1[i].psub); //3
		free(st1[i].name);//2
	}

	free(st1); //1


	return 0;
}
*/
//4번
/*
typedef struct tourcity
{
	char city_name[30]; //도시명
	char name[30];		//관광지명
	char date[9];
	char inout;
	int fee;
}tourcity;

int chk_alloc(void *ptr)
{
	if (ptr == NULL)
	{
		printf("Not Enough Memory.");
		return 1;
	}
	return 0;
}

int main()
{
	int n,i,j;
	int *m;
	int idx[2] = { 0 }, max = 0;
	char date[9] = "\0";
	char tmp[100][100] = { "\0" };
	tourcity **tour=NULL;

	scanf("%d", &n);
	getchar();

	tour = (tourcity**)malloc(sizeof(tourcity*)*n);		//1
	m = (int*)malloc(sizeof(int)*n); //1-1
	
	if (chk_alloc(tour))	return -1;
	if (chk_alloc(m))	return -1;

	for (i = 0; i < n; i++)
		scanf("%s", tmp[i]);

	for ( i = 0; i < n; i++)
		scanf("%d",&m[i]);

	getchar();

	for (i = 0; i < n; i++)
	{
		tour[i] = (tourcity*)malloc(sizeof(tourcity)*m[i]);		//2
		if (chk_alloc(tour[i]))	return -1;
	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m[i]; j++)
		{
			strcpy(tour[i][j].city_name, tmp[i]);
			scanf("%s %d %c %s", tour[i][j].name,
			&tour[i][j].fee, &tour[i][j].inout,&tour[i][j].date);

			if (max < tour[i][j].fee)
			{
				max = tour[i][j].fee;
				idx[0]= i;
				idx[1] = j;
				strcpy(date, tour[i][j].date);
			}
			else if (max == tour[i][j].fee)
			{
				if (strcmp(date, tour[i][j].date)>0)
				{
					max = tour[i][j].fee;
					idx[0] = i;
					idx[1] = j;
					strcpy(date, tour[i][j].date);
				}
			}
		}
	}

	i = idx[0];
	j = idx[1];

	printf("%s %s %d %s %c", tour[i][j].city_name, tour[i][j].name,
			tour[i][j].fee,tour[i][j].date,tour[i][j].inout);

	for (i = 0; i < n; i++)
		free(tour[i]);		//2
	free(m);	//1-1
	free(tour);	//1

	return 0;
}
*/