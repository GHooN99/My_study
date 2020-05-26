#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack   //스텍 구조체
{
	char data;   // 데이터
	struct stack *next;  // 다음 노드의 주소 싱글 리스트 
}stack;  // 스택 구조체 선언

typedef int bool;  // 형식 재정의

bool isEmpty(stack *s)  // 스택 비었는지 확인 
{
	return s->next == NULL;   //헤더노드 밖에 없으면 빈 스택
}
void Swap(char *x, char *y)  //스왑함수
{
	char tmp = *x;  //임시변수
	*x = *y;   //변수 바꾸기
	*y = tmp;  // 변수 바꾸기
}
int Size(stack *s)   //스택의 크기 함수
{
	int cnt = 0;  // 변수 초기화
	stack *ptr = s->next;  // 포인터 탐색변수 초기화
	while (ptr != NULL)  //스택 끝까지 탐색
	{
		ptr = ptr->next;  // 다음 노드로
		cnt++;  //크기 증가
	}
	return cnt;  // 크기 반환 

}
stack* allocNode()   // 노드 할당 함수
{
	return (stack*)calloc(1, sizeof(stack));  // 1개 노드 할당
}
void initStack(stack **s, int n)  // 스택 초기화 함수
{
	(*s) = allocNode();   // 헤더노드 할당
	(*s)->next = NULL;  //헤더노드 초기화
}
void Push(stack **s, int n, char data)   //푸시 함수
{
	if (Size(*s) == n)  // 사이즈가 최대일때
	{
		printf("Stack FULL\n");  //메시지출력 
		return; // 종료
	}
	stack *ptr = (*s)->next;		//헤더 다음 포인터 변수
	stack *new_node = allocNode();  // 새로운 노드 할당 

	(*s)->next = new_node;  // 맨앞에 새로운 노드 연결
	new_node->next = ptr;   // 새로운 노드 다음 노드를 연결 
	new_node->data = data;  //데이터를 삽입

}
char Pop(stack **s)   //팝 함수 
{
	if (isEmpty(*s))  // 빈 스택이면 
	{
		printf("Stack Empty\n");  //메시지 출력 
		return (char)NULL;  // 함수종료
	}
	
	stack *ptr = (*s)->next;   // 임시 포인터 변수
	char data = ptr->data;   // 데이터 저장  
	(*s)->next = ptr->next;   // 맨앞 노드 연결 해제
	free(ptr);  // 할당 해제

	return data;  // 데이터 반환 
}
void Peek(stack *s) //피크 함수 
{
	if (isEmpty(s))   // 빈스택이면 
	{
		printf("Stack Empty\n"); // 메시지 출력 
		return; //종료
	}
	printf("%c", s->next->data);  // 맨위에 있는 데이터를 출력 
}
void Duplicate(stack **s, int n)   // 복사 함수 
{
	if (Size(*s) == n)  //스택이 가득차면 
	{
		printf("Stack FULL\n"); // 메시지 출력 
		return;   // 종료 
	}

	char data;   // 변수선언
	data = Pop(s);  // 팝한 데이터 저장 
	if (data != (char)NULL)   //정상적으로 데이터를 받았으면 
	{
		Push(s, n, data);    // 받은 데이터로 푸시 2번 
		Push(s, n, data);
	}
}
void upRotate(stack **s, int n)   // 회전 함수 
{
	if (n > Size(*s)) return;   // 크기보다 크면 종료

	stack *ptr = (*s)->next;   //임시 포인터 변수

	for (int i = 0; i < n - 1; i++)   //n-1번반복
	{
		Swap(&(ptr->data), &(ptr->next->data));   //맨 위 데이터부터 다음 노드와 데이터를 바꿔 데이터를 n-1번 내림 
		ptr = ptr->next;   //다음 노드로 
	}
}
void downRotate(stack **s, int n,int k)   // 회전함수
{
	char data;  // 데이터변수
	stack *ptrprev=NULL;  // 임시변수 이전 노드의 주소 
	if (n > Size(*s)) return;   // 크기보다 크면 종료 

	stack *ptr = (*s);   // 임시 포인터 변수
	for (int i = 0; i < n; i++) //n번 반복 끝이나면 ptr은 n번째 노드를 가리키고있음
	{
		ptrprev = ptr;  // 이전 노드의 주소 저장 
		ptr = ptr->next;  // 현재 노드의 주소 저장 
	}
	ptrprev->next = ptr->next;  // n번째 노드 연결해제
	data = ptr->data;		//n번째 노드 데이터 저장 
	free(ptr);  // 할당 해제
	Push(s, k, data);  //n번째 노드를 푸시해서 맨위로 
}
void printStack(stack *s)  // 스택 출력 함수
{
	stack *ptr = s->next;  // 임시 탐색 포인터변수
	while (ptr!=NULL)   //스택 끝까지 탐색
	{
		printf("%c", ptr->data);  //데이터 출력 
		ptr = ptr->next;		// 다음 노드로 
	}
	printf("\n");  //개행
}


int main()		//메인함수
{
	stack *st;		//스택 선언
	char op[7];    //연산 종류 

	int n, m;   // 변수 설정 
	char data;
	scanf("%d", &n);   //최대 크기 설정 
	initStack(&st, n);   //스택 초기화
	scanf("%d", &m);  //반복 횟수 설정 

	getchar();  //버퍼

	for (int i = 0; i < m; i++)  //m번 반복 
	{
		scanf("%s", op);  // 연산종류 입력 
		getchar();
		if (strcmp(op, "POP") == 0)   //pop이면 
		{
			data = Pop(&st);  //팝함수 호출 
		}
		else if (strcmp(op, "PUSH") == 0)  //push 이며ㅑㄴ 
		{
			scanf("%c", &data); //데이터 입력 
			Push(&st, n, data);  //push 함수 호출 
		}
		else if (strcmp(op, "PRINT") == 0)  // print 이면 
		{
			printStack(st);  //출력함수 호출 
		}
		else if (strcmp(op, "PEEK") == 0)   //peek 이면 
		{
			Peek(st);  //peek함수 호출 
		}
		else if (strcmp(op, "DUP") == 0)  //dup이면 
		{
			Duplicate(&st, n);  //dup 함수 호출 
		}
		else if (strcmp(op, "UpR") == 0)  //upr 이면 
		{
			int k;  //위치입력
			scanf("%d", &k); 
			upRotate(&st, k); // 함수호출 
		}
		else if (strcmp(op, "DownR") == 0)  //downr이면 
		{
			int k;  //위치입력 
			scanf("%d", &k);  
			downRotate(&st, k,n); // 함수호출 
		}
	}
	return 0;  //종료 
}