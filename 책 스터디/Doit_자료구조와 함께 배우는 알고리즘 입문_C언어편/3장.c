#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Linear Search �����˻� */

//�ǽ� 3-1
// ����� ������ n�� �迭���� key�� ��ġ�ϴ� ��Ҹ� �����˻�
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

	printf("�迭 ��� ���� : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("�迭 �Է� : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("�˻��� : ");
	scanf("%d", &key);

	idx = search(arr, n, key);

	if (idx > 0)
		printf("%d ��°�� ����", idx+1);
	else
		printf("�˻� ����");


	free(arr);


	return 0;
}
*/
//���ʹ� -> �迭�� ��������ҿ� key �� �ξ� �������� �˻� ����� ����??

/* Binary Search ���� �˻� */
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

	printf("�迭 ��� ���� : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("�迭 �Է� : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("�˻��� : ");
	scanf("%d", &key);

	idx = b_search(arr, n, key);

	if (idx >= 0)
		printf("%d ��°�� ����", idx+1);
	else
		printf("�˻� ����");


	free(arr);


	return 0;
}
*/

//�������� 3
// �迭 ��� ã�� ���� ã�� (�ߺ�����)
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

	printf("�迭 ��� ���� : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);
	idx = calloc(n, sizeof(int));
	printf("�迭 �Է� : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("�˻��� : ");
	scanf("%d", &key);

	check = search(arr, n, key,idx);

	if (check >= 0)
	{
		for(i=0;i<check;i++)
			printf("%d, ", idx[i]+1);
		printf("������ ���� ������ %d ��",check);
	}
	else
		printf("�˻� ����");


	free(arr);
	free(idx);

	return 0;
}
*/
//�������� 5
// �ߺ��� ���� �ִ� ���� Ž��
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

	printf("�迭 ��� ���� : ");
	scanf("%d", &n);

	arr = malloc(sizeof(int)*n);

	printf("�迭 �Է� : ");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf("�˻��� : ");
	scanf("%d", &key);

	idx = b_search2(arr, n, key);

	if (idx >= 0)
		printf("%d ��°�� ����", idx + 1);
	else
		printf("�˻� ����");


	free(arr);


	return 0;
}
*/




