#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

/* 비트 벡터로 집합 만들기 */

/* 집합의 최대 요소의 개수가 작은 경우
비트(1개의 정수)로 집합 구현이 가능 */

// 비트 연산자 이해 필요 


typedef unsigned long BitSet;	// 32비트 를 bitset으로 사용 
#define BitSetNULL (BitSet)0		// 0 공집합
#define BitSetBits 32			//유효 비트 수
#define Setof(no) ((BitSet)1<<(no))		//시프트 연산자(1을 no 만큼 시프트) 
										// no만 있는 집합을 만든다.

int isMember(BitSet s, int n)  //집합 s 에 n이있는지 확인 
{
	return s &Setof(n); //논리곱 연산 , n이있으면 비트 1  없으면 모든 비트 0반환
}
void Add(BitSet *s, int n)	//집합에 추가 
{
	*s |= Setof(n); // s와 비트로 나타낸 n 의 논리 합 연산 
}
void Remove(BitSet *s, int n) //삭제
{
	*s &= ~Setof(n); // s 와 ~n 의 논리 곱 연산 
}
int Size(BitSet s) //원소 개수 반환
{
	int n=0;
	for (n = 0; s != BitSetNULL; n++) // 공집합 일때까지 돌기
		s &= s - 1;  //집합에서 1이 있는것을 0으로 바꾸는 연산 

	return n; //연산 횟수가 1의 개수 
}
void Print(BitSet s) //출력 
{
	printf("{");
	for (int i = 0; i < BitSetBits; i++) // 모든 비트를 돌면서 확인
	{
		if (isMember(s, i)) printf("%d ", i); //해당 비트를 찾으면 출력 
	}
	printf("}\n");
}
int main()
{
	int menu, n, c;
	BitSet 
	s1 = BitSetNULL,
	s2 = BitSetNULL,
	s3 = BitSetNULL; // 집합 3개 초기화

	while (1)
	{
		printf("s1: ");
		Print(s1);
		printf("s2: ");
		Print(s2);
		printf("___Menu___\n");
		printf("(1)Add (2)Remove (3)isEqual (4)Operation (0)Exit\n");
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
			printf("s1 과 s2는 %s습니다.\n",s1==s2 ? "같":"같지 않");
			break;
		case 4:
			printf("Union : ");
			s3 = s1 | s2;
			Print(s3);

			printf("Intersection : ");
			s3 = s1 & s2;
			Print(s3);

			printf("Difference (s1-s2): ");
			s3 = s1 & ~s2; //1교2여 => 1-2
			Print(s3);

			printf("Difference (s2-s1): ");
			s3 = s2 & ~s1; //2교1여 => 2-1
			Print(s3);

			break;
		case 0:
			return 0;
		default:
			break;
		}

	}

	return 0;
}
