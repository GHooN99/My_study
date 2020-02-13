#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Linear Search 선형검색 */

//실습 3-1
// 요소의 개수가 n인 배열에서 key와 일치하는 요소를 선형검색
/*
int search(const int x[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (key == x[i])	return i;
	}
	return -1;
}
int main()
{
	int *arr,n,i,key,idx;

	printf("배열 요소 개수 : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("배열 입력 : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("검색값 : ");
	scanf("%d", &key);

	idx = search(arr, n, key);

	if (idx > 0)
		printf("%d 번째에 존재", idx+1);
	else
		printf("검색 실패");


	free(arr);


	return 0;
}
*/
//보초법 -> 배열의 마지막요소에 key 를 두어 종료조건 검색 비용을 줄임??

/* Binary Search 이진 검색 */
/*
int b_search(const int arr[], int n, int key)
{
	int head = 0;
	int tail = n - 1;
	int center;
	do
	{
		center = (head + tail) / 2;

		if (arr[center] < key)
		{
			head = center + 1;
		}
		else if (key < arr[center])
		{
			tail = center - 1;
		}
		else
			return center;

	} while (head<=tail);
	return -1;
}

int main()
{
	int *arr, n, i, key, idx;

	printf("배열 요소 개수 : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("배열 입력 : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("검색값 : ");
	scanf("%d", &key);

	idx = b_search(arr, n, key);

	if (idx >= 0)
		printf("%d 번째에 존재", idx+1);
	else
		printf("검색 실패");


	free(arr);


	return 0;
}
*/

//연습문제 3
// 배열 요소 찾고 개수 찾기 (중복가능)
/*
int search(const int x[], int n, int key,int idx[])
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (key == x[i]) idx[k++]=i;
	}
	if (k==0)	return -1;
	else return k;
}
int main()
{
	int *arr, n, i, key, *idx;
	int check;

	printf("배열 요소 개수 : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);
	idx = calloc(n, sizeof(int));
	printf("배열 입력 : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("검색값 : ");
	scanf("%d", &key);

	check = search(arr, n, key,idx);

	if (check >= 0)
	{
		for(i=0;i<check;i++)
			printf("%d, ", idx[i]+1);
		printf("번쨰에 존재 개수는 %d 개",check);
	}
	else
		printf("검색 실패");


	free(arr);
	free(idx);

	return 0;
}
*/
//연습문제 5
// 중복된 값이 있는 이진 탐색
/*
int b_search2(const int arr[], int n, int key)
{
	int head = 0;
	int tail = n - 1;
	int center;
	do
	{
		center = (head + tail) / 2;

		if (arr[center] < key)
		{
			head = center + 1;
		}
		else if (key < arr[center])
		{
			tail = center - 1;
		}
		else
		{
			for (int k = 1; center - k>=0; k++)
			{
				if (arr[center] != arr[center - k])
				{
					return center - k+1;
					
				}
			}
		}

	} while (head <= tail);
	return -1;
}

int main()
{
	int *arr, n, i, key, idx;

	printf("배열 요소 개수 : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("배열 입력 : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("검색값 : ");
	scanf("%d", &key);

	idx = b_search2(arr, n, key);

	if (idx >= 0)
		printf("%d 번째에 존재", idx + 1);
	else
		printf("검색 실패");


	free(arr);


	return 0;
}
*/




