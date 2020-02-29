#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int max; // 최대 원소 개수 
	int num; //현재 원소 개수
	int *set; //집합 배열 첫원소 포인터
}IntSet;


int Init(IntSet *s, int max)  //집합 초기화
{
	s->num = 0;
	if ((s->set = calloc(max, sizeof(int))) == NULL)
	{
		s->max = 0;
		return -1;	//비정상 종료
	}
	s->max = max;
	return 0; //정상 종료 
}
int isMember(const IntSet *s, int n) //원소 찾기 
{
	for (int i = 0; i < s->num; i++)
		if (s->set[i] == n) return i;	//원소 찾으면 인덱스 반환

	return -1; //없으면 -1 반환
}
int Add(IntSet *s, int n) //원소 추가 
{
	if (s->num == s->max)	return -1;  //오버플로 확인
	if (isMember(s, n) != -1) return -1; //중복값 있음
	else
		s->set[s->num++] = n; //원소 추가 후 현재 개수 증가
		return 0; //정상 종료
}
int Remove(IntSet *s, int n) //원소 삭제
{
	int idx = isMember(s,n);
	if (s->num == 0)	return -1; //삭제 불가
	if (idx == -1)	return -1; //찾는값이 없음 
	else
		s->set[idx] = s->set[--(s->num)]; //마지막에 있는 값을 삭제할 인덱스에 복사 후 마지막 삭제
	return 0;
}
void Assign(IntSet *s1, const IntSet *s2) //집합 s2를 s1에 대입
{
	int n;
	if (s1->max < s2->num) n = s1->max; // 최대면 최대만큼
	else n = s2->num;  //넘지 않으면 현재 s2 만큼

	for (int i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;

}
int isEqual(const IntSet *s1, const IntSet *s2) //같은 집합인지 확인
{
	int j = 0;
	if (s1->num != s2->num) return 0;
	for (int i = 0; i < s1->num; i++)
	{
		for (j = 0; j < s2->num; j++)
			if (s2->set[j] == s1->set[i]) break;
		if (j == s2->num) return 0; //같은걸 찾지 못함 
	}
	return 1;
}

IntSet* Union(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2,s3 의 합집합을 s1 에 대입 
{
	Assign(s1, s2); //s1에 s2 를 넣음
	for (int i = 0; i < s3->num; i++)
		Add(s1, s3->set[i]); //s1에 s3을 넣음 

	return s1; //s1 주소를 반환 
}
IntSet* Intersection(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2,s3 의 교집합을 s1 에 대입 
{
	s1->num = 0; //s1 을 공집합으로 
	int j;

	for (int i = 0; i < s2->num; i++)
	{
		for (j = 0; j < s3->num; j++)
		{
			if (s3->set[j] == s2->set[i])
				Add(s1, s2->set[i]);
		}
	}
	return s1; //s1 주소를 반환 
}
IntSet* Difference(IntSet *s1, const IntSet *s2, const IntSet *s3) //s2에서 s3 를뺀 차집합을 s1 에 대입 
{
	s1->num = 0; //s1 을 공집합으로 
	int j;


	for (int i = 0; i < s2->num; i++)
	{
		for (j = 0; j < s3->num; j++)
			if (s3->set[j] == s2->set[i])  //같은게 없으면 
				break;

		if (j == s3->num)
			Add(s1, s2->set[i]);  //추가 
	}

	return s1; //s1 주소를 반환 
}
void Print(const IntSet *s) // 원소 출력 
{
	printf("{ ");
	for (int i = 0; i < s->num; i++)
	{
		printf("%d ", s->set[i]);
	}
	printf("}\n");
}
void Terminate(IntSet *s)  //집합 종료
{
	free(s->set);
	s->max = 0;
	s->num = 0;
}

int main()
{

	int menu, n, max,c;
	IntSet s1, s2, s3; // 집합 3개 초기화
	printf("최대 집합 원소 개수 :");
	scanf("%d", &max);
	Init(&s1, 10);
	Init(&s2, 10);
	Init(&s3, 10);

	while (1)
	{
		printf("s1: ");
		Print(&s1);
		printf("s2: ");
		Print(&s2);
		printf("___Menu___\n");
		printf("(1)Add (2)Remove (3)Assign (4)Operation (0)Exit\n");
		printf("Menu :");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("(0)s1에 추가 (1)s2에 추가 :");
			scanf("%d", &c);
			printf("추가 할 원소 :");
			scanf("%d", &n);
			if (!c)	Add(&s1, n);
			else Add(&s2, n);
			break;
		case 2:
			printf("(0)s1에서 삭제 (1)s2에서 삭제 :");
			scanf("%d", &c);
			printf("삭제 할 원소 :");
			scanf("%d", &n);
			if (!c)	Remove(&s1, n);
			else Remove(&s2, n);
			break;
		case 3:
			printf("(0)s1에서 s2에 대입 (1)s2에서 s1에 대입:");
			scanf("%d", &c);
			if (!c)	Assign(&s2, &s1);
			else Assign(&s1, &s2);
			break;



		case 4:
			printf("Union : ");
			Union(&s3, &s1, &s2);
			Print(&s3);

			printf("Intersection : ");
			Intersection(&s3, &s1, &s2);
			Print(&s3);

			printf("Difference (s1-s2): ");
			Difference(&s3, &s1, &s2);
			Print(&s3);
			printf("Difference (s2-s1): ");
			Difference(&s3, &s2, &s1);
			Print(&s3);
			break;
		case 0:
			Terminate(&s1);
			Terminate(&s2);
			Terminate(&s3);
			return 0;
		default:
			break;
		}

	}
	
	return 0;
}