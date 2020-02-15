#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 스택과 큐 */
//스택 

// int 형 스택 구현 

typedef struct IntStack
{
	int max;		//스택 용량
	int ptr;		//스택 포인터 
	int *stk;		//스택 첫요소 포인터

}IntStack;

int init(IntStack *s, int max);	//스택 초기화
int Push(IntStack *s, int x);	// 푸시
int Pop(IntStack *s, int *x);	// 팝
int Peek(const IntStack *s, int *x); //피크
void Clear(IntStack *s); //스택비우기
int Capacity(const IntStack *s); //스택 최대용량
int Size(const IntStack *s); //데이터 개수
int isEmpty(const IntStack *s);	//스택 비어있는지 
int isFull(const IntStack *s);	//스택 차있는지 
int Search(const IntStack *s,int x);	//스택 검색
void Print(const IntStack *s); //모든 데이터 출력
void Terminate(IntStack *s); // 스택종료

int main()
{
	IntStack stack;
	int max,idx,menu, x;;
	printf("최대 원소 개수 :");
	scanf("%d", &max);
	if (init(&stack, max) == -1)
	{
		printf("스택 생성 실패\n");
		return -1;
	}
	while (1)
	{
		
		printf("_______________________\n");
		printf("현재 데이터 수 : %d /%d \n",stack.ptr,stack.max);
		printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear (6)Search (0)Exit\n입력 :");
		scanf("%d", &menu);

		if (0 == menu) break;

		switch (menu)
		{
			case 1:
				printf("입력 :");
				scanf("%d", &x);
				if(Push(&stack, x)==-1)
					printf("실패\n");
				else
					printf("%d 를 push 했습니다.\n", x);
				break;
			case 2:
				if (Pop(&stack, &x) == -1)
					printf("실패\n");
				else
					printf("%d 를 pop 했습니다.\n", x);
				break;
			case 3:
				if (Peek(&stack, &x) == -1)
					printf("실패\n");
				else
					printf("peek 데이터는 %d 입니다.\n", x);
				break;
			case 4:
				printf("현재 데이터 : ");
				Print(&stack);
				break;
			case 5:
				Clear(&stack);
				printf("스택을 비웠습니다.\n");
				break;
			case 6:
				printf("검색할 원소 입력 :");
				scanf("%d", &x);
				idx = Search(&stack, x);
				if (idx >= 0)
					printf("%d번째에 위치합니다.\n", idx + 1);
				else
					printf("검색 실패\n");
				break;

			default:
				break;
		}

	}
	printf("종료 \n");
	Terminate(&stack);

	return 0;
}
int init(IntStack *s, int max)	//스택 초기화
{
	s->ptr = 0; //포인터 개수 초기화
	s->stk = (int*)calloc(max, sizeof(int));   //max 개의 배열 생성 

	if (s->stk == NULL)
	{
		s->max = 0;  //다른 함수 접근 막기위함 
		return -1; // 할당 성공 확인
	}
	s->max = max; //최대값 초기화 
	return 0; //정상 종료 
}
int Push(IntStack *s, int x)	// 푸시
{
	if (s->ptr >= s->max) return -1; //스택이 가득할때
		s->stk[(s->ptr)++] = x; //s[]번에 x대입 후 요소개수 증가  
	return 0; //정상 종료 

}
int Pop(IntStack *s, int *x)// 팝
{
	if (s->ptr <= 0) return -1; //뺄것이 없음
	*x = s->stk[--(s->ptr)];	//맨 위에 있는것을 빼기 
	return 0;
}
int Peek(const IntStack *s, int *x) //피크 꼭대기의 데이터를 가져옴 
{
	if (s->ptr <= 0) return -1; //뺄것이 없음
	
	*x = s->stk[s->ptr - 1];

	return 0;
}
void Clear(IntStack *s) //스택비우기
{
	s->ptr = 0; // 요소 개수 0개로 
}
int Capacity(const IntStack *s) //스택 최대용량
{
	return s->max;   //최대값 반환
}
int Size(const IntStack *s) //데이터 개수
{
	return s->ptr; //개수 반환 
}
int isEmpty(const IntStack *s)//스택 비어있는지
{
	if (s->ptr <= 0) return 1;
	return 0;
}
int isFull(const IntStack *s)	//스택 차있는지 
{
	if (s->ptr >= s->max) return 1;
	return 0;
}
int Search(const IntStack *s, int x)	//스택 검색
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x) return i;		//인덱스 반환
	}
	return -1;
}
void Print(const IntStack *s) //모든 데이터 출력
{
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);
	printf("\n");
}
void Terminate(IntStack *s) // 스택종료
{
	if (s->stk != NULL)
		free(s->stk);

	s->max = s->ptr = 0;
	
}