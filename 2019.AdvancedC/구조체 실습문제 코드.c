#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

//1번
/*
struct vector
{
	int x, y, z;
};
int main()
{
	struct vector v1, v2, v3;

	scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
	scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
	
	v3.x = v1.x*v2.x;
	v3.y = v1.y*v2.y;
	v3.z = v1.z*v2.z;

	printf("%d %d %d\n", v3.x, v3.y, v3.z);
	printf("%d", v3.x + v3.y + v3.z);

	return 0;
}
*/
//2번 
/*
struct time
{
	int hour, min, sec;
};
struct time sub_time(struct time t1, struct time t2)
{
	int sect1, sect2,sect3;
	struct time t3;

	sect1 = t1.hour * 3600 + t1.min * 60 + t1.sec;
	sect2 = t2.hour * 3600 + t2.min * 60 + t2.sec;
	sect3 = sect2 - sect1;
	t3.sec = sect3 % 3600 % 60;
	t3.min = sect3 % 3600 / 60;
	t3.hour = sect3 / 3600;

		return t3;
}
int main()
{
	struct time t1, t2, t3;

	scanf("%d %d %d", &t1.hour, &t1.min, &t1.sec);
	scanf("%d %d %d", &t2.hour, &t2.min, &t2.sec);

	t3=sub_time(t1,t2);
	printf("%d %d %d", t3.hour, t3.min, t3.sec);



	return 0;
}
*/
//3번
/*
struct student
{
	char name[10];
	int score;
};
int main()
{
	struct student st[5];
	int avg, sum = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%s %d", st[i].name, &st[i].score);
		sum += st[i].score;
	}
	avg = sum / 5;
	for (int i = 0; i < 5; i++)
	{
		if (st[i].score <= avg)
			printf("%s", st[i].name);
		printf("\n");
	}

	return 0;
}
*/
//4번
/*
struct student
{
	int score1, score2, score3;
	char name[20];
};
char grade(float avg) 
{
	char grd;
	if (avg >= 90)
		grd = 'A';
	else if (avg>=80)
		grd = 'B';
	else if (avg >= 70)
		grd = 'C';
	else 
		grd = 'F';

	return grd;

}
float avg(struct student st)
{
	float a;
	a = (st.score1 + st.score2 + st.score3) / 3.0;
	return a;
}
int main()
{
	struct student st[20];
	int i,n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %d %d %d", st[i].name, &st[i].score1, &st[i].score2, &st[i].score3);
	
	for (i = 0; i < n; i++)
	printf("%s %.1f %c\n", st[i].name, avg(st[i]), grade(avg(st[i])));

	return 0;
}
*/
//5번
/*
struct student
{
	int score1, score2, score3;
	char name[8];
	float avg;
	char grade;
};
char grade(float avg)
{
	char grd;
	if (avg >= 90)
		grd = 'A';
	else if (avg >= 80)
		grd = 'B';
	else if (avg >= 70)
		grd = 'C';
	else
		grd = 'D';

	return grd;

}
float avg(struct student *st)
{
	float a;
	a = (st->score1 + st->score2 + st->score3) / 3.0;
	return a;
}
int main()
{
	struct student st[50];
	struct student *ptr_st = &st;
	int i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", &(ptr_st + i)->name, &(ptr_st + i)->score1, &(ptr_st + i)->score2, &(ptr_st + i)->score3);
		(ptr_st+i)->avg = avg((ptr_st+i));
		(ptr_st+i)->grade = grade((ptr_st+i)->avg);
		
	}

	for (i = 0; i < n; i++)
		printf("%s %.1f %c\n", (ptr_st + i)->name, (ptr_st + i)->avg, (ptr_st + i)->grade);

	return 0;
	
}
*/
//6번
/*
typedef struct student
{
	int gen, h, w;

}student;

int wgrade(student st,int m)
{
	int k=0;

	if (!m)
		k = 10;

	if (st.h >= 175)
	{
		if (st.w >= 70 - k)
			return 1;
		else if (st.w >= 60 - k)
			return 2;
		else
			return 3;

	}
	else if (st.h >= 165)
	{
		if (st.w >= 70 - k)
			return 3;
		else if (st.w >= 60 - k)
			return 1;
		else
			return 2;


	}
	else
	{
		if (st.w >= 70 - k)
			return 2;
		else if (st.w >= 60 - k)
			return 3;
		else
			return 1;
	}

}

void g_grade(student *st, int *grade, int n)
{
	int i,idx;

	for (i = 0; i < n; i++)
	{
		if (st[i].gen == 1)
		{
			idx = wgrade(st[i], 1);
			grade[idx - 1]++;
		}
		else
		{
			idx = wgrade(st[i], 0);
			grade[idx - 1]++;
		}

	}

}
int main()
{
	student st[10];

	int n, i, grade[3] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &st[i].gen, &st[i].w, &st[i].h);
	
	g_grade(st, grade, n);

	for (int i = 0; i < 3; i++)
		printf("%d " ,grade[i]);



	return 0;
}
*/
//7번
/*
typedef struct rank
{
	int n;
	int label;
}rank;
void swap(int *f1, int *f2)
{
	int tmp;
	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}
void label(rank *rar, int *arr)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (rar[i].n == arr[j])
			{
				rar[i].label = j+1 ;
				break;
			}
		}

	}
}
void sort(int *arr)
{
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}

}
int main()
{
	rank rnk[10];
	int arr[10];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &rnk[i].n);
		arr[i] = rnk[i].n;
	}

	sort(arr);
	label(rnk, arr);
	

	for (int i = 0; i < 10; i++)
	{
		if (rnk[i].label == 3)
		{
			printf("%d ", rnk[i].n);
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (rnk[i].label == 7)
		{
			printf("%d ", rnk[i].n);
			break;
		}
	}

	return 0;
}
*/
//8번
/*
typedef struct complex
{
	float real, imag;
}complex;

complex add(complex c1, complex c2)
{
	complex c3;

	c3.real = c1.real + c2.real;
	c3.imag = c1.imag + c2.imag;

	return c3;
}
int main()
{
	complex c1, c2, c3;

	scanf("%f %f", &c1.real, &c1.imag);
	scanf("%f %f", &c2.real, &c2.imag);

	c3 = add(c1, c2);

	printf("%.1f + %.1fi", c3.real, c3.imag);


	return 0;
}
*/
//9번
/*
typedef struct result
{
	int hScore, lScore;
	char PNP;
	int scoretpass;
	int abshighlow;

}result;

void passorfail(result *st)
{
	st->abshighlow = (st->hScore) - (st->lScore);
	
	if (st->abshighlow <= (st->scoretpass))
		st->PNP = 'P';
	else
		st->PNP = 'F';


}
int main()
{
	result st,*ptrst=&st;

	scanf("%d %d %d", &st.hScore, &st.lScore, &st.scoretpass);
	passorfail(ptrst);

	printf("%d %c", st.abshighlow,st.PNP);

	return 0;
}
*/
//10번
/*
typedef struct date
{
	int year, mon, day;

}date;

date* select_min(date *st1, date *st2)
{
	date *minst = st1;
	if (st1->year == st2->year)
	{
		if (st1->mon == st2->mon)
		{
			if (st1->day > st2->day)
				minst = st2;
			else
				minst = st1;
		}
		else if (st1->mon > st2->mon)
			minst = st2;
		else
			minst = st1;
	}
	else if (st1->year > st2->year)
		minst = st2;
	else
		minst = st1;


	return minst;
}

int main()
{

	date st[2],*ptr;

	for (int i = 0; i < 2; i++)
		scanf("%d/%d/%d", &st[i].year, &st[i].mon, &st[i].day);
	
	ptr=select_min(st, st+1);
	printf("%d/%d/%d", ptr->year, ptr->mon, ptr->day);
		

	return 0;

}
*/
//11번
/*
typedef struct student
{
	char name[10];
	int score;
}student;

student* select_min(student *st)
{
	int min=100;
	student *minptr=NULL;
	for (int i = 0; i < 5; i++)
	{
		if (st[i].score < min)
		{
			min = st[i].score;
			minptr = st + i;
		}
	}
	return minptr;
}

int main()
{
	student st[5],*ptr;
	for (int i = 0; i < 5; i++)
		scanf("%s %d", &st[i].name, &st[i].score);
	
	ptr=select_min(st);

	printf("%s %d", ptr->name, ptr->score);

	return 0;
}
*/
//12번 
/*
typedef struct student
{
	int score1,score2,score3;
	char name[10];
	float avg;
}student;
void swap(float *f1, float *f2)
{
	float tmp;
	tmp = *f1;
	*f1 = *f2;
	*f2 = tmp;
}
void read_data(student *st)
{
	for (int i = 0; i < 10; i++)
		scanf("%s %d %d %d", &st[i].name, &st[i].score1, &st[i].score2, &st[i].score3);
}
void cal_avg(student *st)
{
	for (int i = 0; i < 10; i++)
	st[i].avg= (st[i].score1+st[i].score2+st[i].score3)/3.0;
}
void sort(student *st)
{
	char tmp[10] = "\0";
	for (int i = 0; i < 9; i++)
	{

		for (int j = 0; j < 9; j++)
		{
			if (st[j].avg < st[j+1].avg)
			{
				
				strcpy(&tmp, &(st[j].name));
				strcpy(&(st[j].name), &(st[j+1].name));
				strcpy(&(st[j+1].name),&tmp);
				swap(&(st[j].avg), &(st[j + 1].avg));
				
			}
		}
	}
}
void print_score(student *st)
{
	printf("%s %.2f\n",st[0].name,st[0].avg);
	printf("%s %.2f\n", st[9].name, st[9].avg);
	for(int i=7;i<10;i++)
		printf("%s %.2f\n", st[i].name, st[i].avg);
}

int main()
{
	student st[10];

	read_data(st);
	cal_avg(st);

	sort(st);

	print_score(st);

	return 0;

}
*/




