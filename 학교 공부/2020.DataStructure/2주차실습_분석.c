#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//���� 1

 //O(a/b)�� modulo�Լ� �ۼ� 

int modulo(int a, int b)
{
	while (a - b >= 0)
	{
		a -= b;
	}
	return a;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));

	return 0;
}

//���� 2 

//��Ʈ��Ŀ��� �ִ� 1�� ã��
int mostOnes(int A[][100], int n)
{
	int row = 0, col = 0, max = 0; //0,0���� ���
	while(col != n && row != n) //������ ���� ����������
	{
		if (A[row][col] == 0) row++; //0�� �߰ߵǸ� ������
		else //1�� �߰ߵǸ� ����������
		{
			col++;
			max = row; //������ �������� �� ������Ʈ
		}
	}
	return max;
}
int main()
{
	int arr[100][100], n, i;
	scanf("%d", &n);

	for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("%d", mostOnes(arr, n));


	return 0;
}

//���� 3

int* prefixAverages1(int arr[], int n) // O(n^2)
{
	int *A = NULL;
	float k;
	A = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < i+1; j++)
		{
			sum = sum + arr[j];
		}
		k = (float)(i + 1);
		A[i] = (int)((sum / k) + 0.5);
	}

	return A;
}
int* prefixAverages2(int arr[], int n) // O(n)
{
	int *A = NULL;
	int sum =0;
	float k;
	A = (int*)calloc(n, sizeof(int));
	
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		k = (float)(i + 1);
		A[i] = (int)((sum / k) + 0.5);
	}

	return A;
}
int main()
{
	int *arr, *A1,*A2, n;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	A1 = prefixAverages1(arr, n);
	A2 = prefixAverages2(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d ", A1[i]);

	printf("\n");

	for (int i = 0; i < n; i++)
		printf("%d ", A2[i]);
	
	free(A1);
	free(A2);
	free(arr);

	return 0;
}

//���� 3-2
#include <time.h>
int* prefixAverages1(int arr[], int n) // O(n^2)
{
	int *A = NULL;
	float k;
	A = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < i + 1; j++)
		{
			sum = sum + arr[j];
		}
		k = (float)(i + 1);
		A[i] = (int)((sum / k) + 0.5);
	}

	return A;
}
int* prefixAverages2(int arr[], int n) // O(n)
{
	int *A = NULL;
	int sum = 0;
	float k;
	A = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		k = (float)(i + 1);
		A[i] = (int)((sum / k) + 0.5);
	}

	return A;
}
int main()
{
	clock_t start1, start2, end1, end2;
	float res1, res2;
	int i;
	int *arr, *A1, *A2, n;

	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++)
		arr[i] = rand();

	start1 = clock();
	A1 = prefixAverages1(arr, n);
	end1 = clock();
	res1 = (float)(end1 - start1);
	printf("%fms\n", res1);

	start2 = clock();
	A2 = prefixAverages2(arr, n);
	end2 = clock();
	res2 = (float)(end2 - start2) ;
	printf("%fms", res2);
	

	free(A1);
	free(A2);
	free(arr);

	return 0;
	
}