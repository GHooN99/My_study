#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// ���� 1 


void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void reverse(int arr[], int a, int b) //reverse a to b
{
	for (int i = 0; i < (b-a+1)/2; i++)
		swap(&arr[a+i], &arr[b-i]);
}
void changeArr(int arr[], int R_arr[],int m)
{
	for (int i = 0; i < 2*m; i+=2) // m  �� �ݺ� 
		reverse(arr, R_arr[i], R_arr[i + 1]);
}

int main()
{
	int n,m;
	int arr[100],R_arr[200];
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);

	for (int i = 0; i < m*2; i++)
		scanf("%d", &R_arr[i]);

	changeArr(arr,R_arr,m);

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);


	return 0;
}

// ���� 2

void changeArr(int arr[], int R_arr[], int m)
{
	int	*saved_arr = (int*)calloc(m, sizeof(int));

	for (int i = 0; i < m; i++)
		saved_arr[i] = arr[R_arr[i]];

	for (int i = 0; i <  m-1; i++)  
		arr[R_arr[i + 1]] = saved_arr[i];
	
	free(saved_arr);
}
int main()
{
	int n, m;
	int arr[100], R_arr[200];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	scanf("%d", &m);

	for (int i = 0; i < m ; i++)
		scanf("%d", &R_arr[i]);

	changeArr(arr, R_arr, m);

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	return 0;
}

// ���� 3

int main()
{

	int arr[100][100];
	int n;
	int cnt = 1;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < n; j++)
				arr[i][j] = cnt++;
		}
		else
		{
			for (int j = n-1; j >=0; j--)
				arr[i][j] = cnt++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	return 0;
}


// ���� 4

int main()
{
	int arr[100][100] = { 0 };
	int n,m;
	int cnt = 1;
	scanf("%d %d", &n,&m);

	int row = 0, col = -1; //���� 
	int rot = 1; //���� 
	int num_col = m;
	int num_row = n-1; // �ϳ� �ٰ� �����ϴ���..

	while (cnt<=n*m)
	{

		for (int i = 0; i < num_col; i++) // ���η� ��� 
		{
			col =col + 1*rot;
			arr[row][col] = cnt++;
		}
		num_col--; //-1 ������ �ش�..
		
		for (int i = 0; i < num_row; i++) // ���η� 
		{
			row +=1*rot;
			arr[row][col] = cnt++;
		}
		num_row--;
		//���� ���� ������ �Ųٷ� 
		rot = rot * -1; // ���� 

	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	return 0;
}






// ���� 5

int main()
{
	int arr[100][100] = { 0 };
	int n, m;
	int col_loc = 0;
	int row_loc = 1;
	int row, col;
	int cnt = 1;
	scanf("%d %d", &n, &m);

	//for (int i = 0; i < n+m; i++) //n+m�� ĥ�� 
	//{
	if (n <= m)
	{
		while (col_loc < m)//���� ���� ���� 
		{
			//row����
		   // col���� 
			for (row = 0, col = col_loc; col >= 0 && row < n; row++, col--)
				arr[row][col] = cnt++;
			col_loc++;
		}
		col_loc--;

		while (row_loc < n)
		{
			for (row = row_loc, col = col_loc; col >= row_loc && row < n; row++, col--)
				arr[row][col] = cnt++;
			row_loc++;
		}
	}
	else
	{
		while (col_loc < m)//���� ���� ���� 
		{
			//row����
		   // col���� 
			for (row = 0, col = col_loc; col >= 0 && row < n; row++, col--)
				arr[row][col] = cnt++;
			col_loc++;
		}
		col_loc--;



		for (int i = 0; i < n - m; i++) //n-m�� �ݺ�
		{
			for (row = row_loc, col = col_loc; col >= 0; row++, col--)
				arr[row][col] = cnt++;
			row_loc++;
		}
		
		while (row_loc < n)
		{
			for (row = row_loc, col = col_loc;  row < n; row++, col--)
				arr[row][col] = cnt++;
			row_loc++;
		}


	}





	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %d", arr[i][j]);
		printf("\n");
	}

	return 0;
}
