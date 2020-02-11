#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

//1-1
/*
typedef struct student
{
	char name[10];
	char id[11];
	char grade;

}student;
int find_idx(student *st,char *name)
{
	int idx;
	for (int i = 0; i < 5; i++)
	{
		if (!strcmp(st[i].name, name))
		{
			idx = i;
			break;
		}
	}
	return idx;
}
int main()
{
	student st[5];
	char name[10];
	int i, j,idx=0;

	for (i = 0; i < 5; i++)
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);

	scanf("%s",name);

	idx = find_idx(st, name);
	printf(" %s %c", st[idx].id, st[idx].grade);


	return 0;
}
*/
//1-2
/*
typedef struct student
{
	char name[10];
	char id[11];
	char grade;

}student;

int find_idx(student *st, char *name)
{
	int idx;
	for (int i = 0; i < 5; i++)
	{
		if (!strcmp(st[i].name, name))
		{
			idx = i;
			break;
		}
	}
	return idx;
}

void find_std(student *st, char *name,int idx)
{
	int k = 0;
	for (int i = 0; i < 5; i++)
	{
		if (!strncmp(st[i].id,st[idx].id,4))
		{
			if (st[i].grade == st[idx].grade)
			{
				if (strcmp(st[i].name, name))
				{
					printf(" %s\n", st[i].name);
						k = 1;
				}
			}
		}
	}
	if (!k)
		printf("0");

}
int main()
{
	student st[5];
	char name[10];
	int i, j, idx = 0;

	for (i = 0; i < 5; i++)
		scanf("%s %s %c", st[i].name, st[i].id, &st[i].grade);

	scanf("%s", name);
	idx = find_idx(st, name);
	find_std(st, name,idx);


	return 0;
}
*/
//2-1
/*
typedef struct book				//구조체 선언
{
	int book_id[3];
	int std_id;
	int start_date[3];
}book;
int isLeapYear(int year)     //윤년 판별 함수
{
	if (year % 4)   return 0;
	if (year % 100) return 1;
	if (year % 400) return 0;
	return 1;
}
int cal_date(int *arr)		//날짜 계산 반환
{
	int date = 0;
	int year = arr[0];
	int mon = arr[1];
	int day = arr[2];
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;
	
	date = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;  //윤년일때와 아닐때를 포함해서 년도에 날짜 계산
	if (isLeapYear(year))
		months[1]++;        // 윤년일때는 2월이 29일이 되서 1더해주기 
	for (i = 0; i < mon - 1; i++)
		date += months[i];   // 달수를 이용한 날짜계산
	date += day;           // 일수를 이용한 계산

	return date;
}
int find_std(book *bk, int *mstd,int *today,int N)    //연체 학생 찾는 함수
{
	int i,idx = 0;
	for (i = 0; i < N; i++)
	{
		if ((cal_date(today))-(cal_date(bk[i].start_date)) > 15)
		{
			mstd[idx] = bk[i].std_id;
			idx++;
		}
	}
	return idx;
}
int del_arr(int *arr, int *uarr,int idx)		//배열 중복 제거 함수
{
	int i,j, k = 0;
	for (i = 0; i < idx; i++)
	{
		for (j = 0; j < idx; j++)
		{
			if (arr[i] == uarr[j])
				break;
		}
		if (j == idx)
		{
			uarr[k] = arr[i];
			k++;
		}
	}
	return k;
}
int main()
{
	book bk[50];

	int mStd[50] = { 0 };
	int umStd[50] = { 0 };
	int i,idx,k, N,today[3];

	scanf("%d %d-%d-%d", &N, &today[0], &today[1], &today[2]);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d-%d-%d", &bk[i].std_id, &bk[i].book_id
			, &bk[i].start_date[0], &bk[i].start_date[1], &bk[i].start_date[2]);
	}
	
	idx=find_std(bk, mStd,today,N);
	k=del_arr(mStd, umStd, idx);

	for (i = 0; i<k; i++)
		printf("%d\n",umStd[i]);

	return 0;
}
*/
//2-2
/*
typedef struct book				//구조체 선언
{
	int book_id;
	int std_id;
	int start_date[3];
}book;
int isLeapYear(int year)     //윤년 판별 함수
{
	if (year % 4)   return 0;
	if (year % 100) return 1;
	if (year % 400) return 0;
	return 1;
}
int cal_date(int *arr)		//날짜 계산 반환
{
	int date = 0;
	int year = arr[0];
	int mon = arr[1];
	int day = arr[2];
	int months[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i;

	date = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;  //윤년일때와 아닐때를 포함해서 년도에 날짜 계산
	if (isLeapYear(year))
		months[1]++;        // 윤년일때는 2월이 29일이 되서 1더해주기 
	for (i = 0; i < mon - 1; i++)
		date += months[i];   // 달수를 이용한 날짜계산
	date += day;           // 일수를 이용한 계산

	return date;
}
void find_std(book *bk, int *mstd, int *today, int N, int *check_list,int ch)    //연체 학생 찾는 함수
{
	int i,j,k,date ,idx = 0;
	int printed=0;
	for (i = 0; i < ch; i++)
	{
		for (j = 0; j < N; j++)
		{
			printed = 0;
			if (check_list[i] == bk[j].std_id)
			{
				date = (cal_date(today)) - (cal_date(bk[j].start_date));
				if (date > 15)
				{
					printf("%d %d(%d) ", check_list[i], bk[j].book_id, (date - 15) * 100);
					printed = 1;
					for (k = j + 1; k < N; k++)
					{
						if (check_list[i] == bk[k].std_id)
						{
							date = (cal_date(today)) - (cal_date(bk[k].start_date));
							if (date > 15)
								printf("%d(%d) ", bk[k].book_id, (date - 15) * 100);
						}
					}
					break;
				}
			}	
		}
		if(!printed)
		printf("%d X", check_list[i]);
		printf("\n");
	}
	
}
int main()
{
	book bk[50];

	int mStd[50] = { 0 };
	int umStd[50] = { 0 };
	int check_list[50];
	int i, idx, k, N,ch, today[3];

	scanf("%d %d-%d-%d", &N, &today[0], &today[1], &today[2]);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d-%d-%d", &bk[i].std_id, &bk[i].book_id
			, &bk[i].start_date[0], &bk[i].start_date[1], &bk[i].start_date[2]);
	}
	scanf("%d", &ch);

	for ( i = 0; i <ch; i++)
		scanf("%d", &check_list[i]);

	find_std(bk, mStd, today, N,check_list,ch);

	return 0;
}
*/
//3
/*
typedef struct parking
{
	int car_id;
	int std_id;
	int in_date[3];
	int out_date[3];
	int in_time[2];
	int out_time[2];
}parking;
void swap(int *x, int *y)   //스왑함수 선언
{
	int tmp;
	tmp = *x;   // 값 끼리 스왑 
	*x = *y;
	*y = tmp;

}
void u_sort(int *x, int n)			//오름차순 함수 선언
{
	int *i, *j, tmp;    //변수 선언 

	for (i = x; i < x + n - 1; i++)    //포인터 반복문 
	{
		for (j = x; j < x + n - 1; j++)			//포인터 이중 반복문 
		{
			if (*(j) > *(j + 1))      //값이 크면 
			{
				swap(j, j + 1);   //스왑
			}
		}
	}

}

int del_arr(int *arr, int *uarr, int idx)		//배열 중복 제거 함수
{
	int i, j, k = 0;
	for (i = 0; i < idx; i++)
	{
		for (j = 0; j < idx; j++)
		{
			if (arr[i] == uarr[j])
				break;
		}
		if (j == idx)
		{
			uarr[k] = arr[i];
			k++;
		}
	}
	return k;
}
int find_std(parking *pk,int *arr,int N)
{
	int i,j, idx = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (pk[i].std_id == pk[j].std_id)
			{
				arr[idx] = pk[i].std_id;
				idx++;
				break;
			}
		}
	}
	return idx;
}
int main()
{
	parking pk[100];

	int mStd[50] = { 0 };
	int umStd[50] = { 0 };
	int i, idx, k, N, today[3];
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d-%d-%d %d:%d %d-%d-%d %d:%d"
		,&pk[i].car_id, &pk[i].std_id
		,&pk[i].in_date[0], &pk[i].in_date[1], &pk[i].in_date[2]
		,&pk[i].in_time[0], &pk[i].in_time[1]
		,&pk[i].out_date[0], &pk[i].out_date[1], &pk[i].out_date[2]
		,&pk[i].out_time[0], &pk[i].out_time[1]);

	}

	idx=find_std(pk, mStd,N);
	k = del_arr(mStd, umStd, idx);
	u_sort(umStd, k);
	for (i = 0; i < k; i++)
		printf("%d\n", umStd[i]);

	return 0;
}
*/
//4
/*
typedef struct parking
{
	int car_id;
	int std_id;
	int in_date[3];
	int out_date[3];
	int in_time[2];
	int out_time[2];
}parking;
int del_arr(int *arr, int *uarr, int idx)		//배열 중복 제거 함수
{
	int i, j, k = 0;
	for (i = 0; i < idx; i++)
	{
		for (j = 0; j < idx; j++)
		{
			if (arr[i] == uarr[j])
				break;
		}
		if (j == idx)
		{
			uarr[k] = arr[i];
			k++;
		}
	}
	return k;
}
int cal_fee(int time)
{
	int fee;
	if (time >=261+60)
		return 30000;
	else if (time <= 60)
		return 3000;
	else
	{
		fee = 3000 + (((time - 60) / 10)+1) * 1000;
		return fee;
	}
}
int isCheater(int *arr,int id,int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (id == arr[i])
			return 1;
	}
	return 0;
}
void cal_time(parking *pk, int *check_list, int N, int car, int *fee,int *std,int k)
{
	int time, intime, outtime;
	int i, j;
	for (i = 0; i < car; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (check_list[i] == pk[j].car_id)
			{
				intime = pk[j].in_time[0] * 60 + pk[j].in_time[1];
				outtime = pk[j].out_time[0] * 60 + pk[j].out_time[1];
				time = outtime - intime;
				fee[i] = cal_fee(time);
				if (isCheater(std,pk[j].std_id,k))
					fee[i] = 100000;
			}
		}
	}
}
int find_std(parking *pk,int *arr,int N)
{
	int i,j, idx = 0;
	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (pk[i].std_id == pk[j].std_id)
			{
				arr[idx] = pk[i].std_id;
				idx++;
				break;
			}
		}
	}
	return idx;
}
int main()
{
	parking pk[100];

	int mStd[50] = { 0 };
	int umStd[50] = { 0 };
	int i, idx, k, N,car,fd;
	int check_list[50];
	int fee[50];
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d %d-%d-%d %d:%d %d-%d-%d %d:%d"
		,&pk[i].car_id, &pk[i].std_id
		,&pk[i].in_date[0], &pk[i].in_date[1], &pk[i].in_date[2]
		,&pk[i].in_time[0], &pk[i].in_time[1]
		,&pk[i].out_date[0], &pk[i].out_date[1], &pk[i].out_date[2]
		,&pk[i].out_time[0], &pk[i].out_time[1]);

	}

	scanf("%d", &car);
	for (i = 0; i < car; i++)
		scanf("%d", &check_list[i]);


	idx=find_std(pk, mStd,N);
	k = del_arr(mStd, umStd, idx);
	cal_time(pk, check_list, N, car, fee,umStd,k);
	for (i = 0; i < car; i++)
		printf("%d\n", fee[i]);

	return 0;
}
*/
