#pragma	warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1-1
/*
void index_down(char *str, int index)
{
	int end = strlen(str), i;

	for (i = index; i<end; i++)
	{
		str[i] = str[i+1];
	}

}

void index_up(char *str,int index)
{
	int end = strlen(str),i;

	for (i = end; i >= index; i--)
	{
		str[i + 1] = str[i];
	}
}

int isnumber(char *str, int index)
{
	int i,k,num;

	 num = (int)(str[index] - '0');
	for (i = index; str[i]; i++)
	{
		for (k = 1;k<2; k++)
		{
			if ('0' <= str[i + k] && str[i + k] <= '9')
			{
				if(num * 10 + (int)(str[i + k] - '0')<27)
				num = num * 10 + (int)(str[i + k] - '0');
				
			}
			else
				break;
		}

		return num;

	}

}

void change_str(char *str, int n)
{
	int i,j,k,num;
	char change;
	for (i = 0; str[i]; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] = str[i] + n;
		}

		else if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - n;
		}

		else if ('0' <= str[i] && str[i] <= '9')
		{

			change= 'A' + isnumber(str, i)-1;

			num = isnumber(str, i);

			for (j = num; j > 0; j=j/10)
			{
				if(j>=10)
				index_down(str, i + 1);
			}

			for (k = 0; k < n; k++)
			{
				str[i+k] =change;

				if (k != n - 1)
					index_up(str, i + 1);

				else
				{
					i=i+n-1;
				}
					
			}
		}
		
		else
		{
			str[i] =' ';
		}


	}

}

int main()
{

	char str[40];
	int n;

	scanf("%s", str);
	scanf("%d",& n);
	
	
	change_str(str,n);
	printf("%s", str);
	

	return 0;

}


*/
//1-2
/*
void index_down(char *str, int index)
{
	int end = strlen(str), i;

	for (i = index; i < end; i++)
	{
		str[i] = str[i + 1];
	}

}

void index_up(char *str, int index)
{
	int end = strlen(str), i;

	for (i = end; i >= index; i--)
	{
		str[i + 1] = str[i];
	}
}

int isnumber(char *str, int index)
{
	int i, k, num;

	num = (int)(str[index] - '0');
	for (i = index; str[i]; i++)
	{
		for (k = 1; k < 2; k++)
		{
			if ('0' <= str[i + k] && str[i + k] <= '9')
			{
				if (num * 10 + (int)(str[i + k] - '0') < 27)
					num = num * 10 + (int)(str[i + k] - '0');

			}
			else
				break;
		}

		return num;

	}

}

void change_str(char *str, int n)
{
	int i, j, k, num;
	char change;
	for (i = 0; str[i]; i++)
	{
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] = str[i] + n;
		}

		else if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] = str[i] - n;
		}

		else if ('0' <= str[i] && str[i] <= '9')
		{

			change = 'A' + isnumber(str, i) - 1;

			num = isnumber(str, i);

			for (j = num; j > 0; j = j / 10)
			{
				if (j >= 10)
					index_down(str, i + 1);
			}

			for (k = 0; k < n; k++)
			{
				str[i + k] = change;

				if (k != n - 1)
					index_up(str, i + 1);

				else
				{
					i = i + n - 1;
				}

			}
		}

		else
		{
			str[i] = ' ';
		}


	}

}

int change(char *str1, char *str2)
{
	int ok[3] = { 0 };

	int i,j;

	char changed_str1[50];
	char changed_str2[50];

	for (i = 1; i <= 10; i++)
	{
		
		 strcpy(changed_str1,str1);
		 change_str(changed_str1, i);	

		 for (j = 1; j <= 10; j++)
		 {
			 strcpy(changed_str2, str2);
			 change_str(changed_str2, i);

			 if (!strcmp(str2, changed_str1))
				 ok[0]++;
			 if (!strcmp(str1, changed_str2))
				 ok[1]++;
		 }

	}


	if (ok[0] && ok[1])
		return 3;

	else if (ok[0])
		return 1;
	else if (ok[1])
		return 2;
	else
		return 0;




	

}

int main()
{

	char str1[50],str2[50];
	
	gets(str1);
	gets(str2);
	

	printf("%d", change(str1, str2));


	return 0;
}
*/
//2
/*
void sep_num(char *str,int *nums)
{
	int i, j, k=0, idx = 0;
	char anum[3][20] = { "\0" };

	for (i = 3; i<=strlen(str); i++)
	{
		if (str[i]!=' ')
		{
			k = 0;
			for (j = i; str[j] != ' '&& str[j]; j++)
			{
				anum[idx][k] = str[j];
				k++;
			}
			i = j;

			nums[idx]=atoi(anum[idx]);
					idx++;

		}
	
	}

}


int cal(char *str)
{
	int result=0;

	char oprtor[5]="\0";

	int nums[3];

	strncpy(oprtor, str, 3);
	
	sep_num(str, nums);

	

	


	if (!strcmp("add", oprtor))
		result = nums[0] + nums[1];


	else if (!strcmp("sub", oprtor))
	{ 
		result = nums[0] - nums[1];
	}

	else if (!strcmp("mul", oprtor))
	{
		result = nums[0] * nums[1];
	}

	else if (!strcmp("div", oprtor))
	{
		result = nums[0] / nums[1];
	}


	return result;

}

int main()
{

	char str[100] = "\0";

	gets_s(str,50);
	if(cal(str))
		printf("%d", cal(str));


	return 0;

}
*/
//3-1
/*
int find_str(char *str1, char *str2)
{
	int i,j,k, cnt = 0;

	for (i = 0; i<=strlen(str1); i++)
	{

		if (str1[i] == str2[0])
		{
			if (strlen(str2) == 1)
				cnt++;
			else
			{
				for (j = 0; j <strlen(str2); i++, j++)
				{
					if (str2[j] != str1[i])
						break;


				}
				i--;
				if (j == strlen(str2))
					cnt++;
			}
		}


	}


	return cnt;
}
int main()
{
	char str1[100] = "\0";
	char str2[100] = "\0";


	gets_s(str1, 100);
	gets_s(str2, 100);
	
	printf("%d", find_str(str1, str2));


	return 0;
}
*/
//3-2
/*
int isalpha(char x)
{
	if (('a' <= x&&x <= 'z') || ('A' <= x && x <= 'Z'))
		return 1;
	else
		return 0;
}
int isword(char *str1, int index,int strlen)
{
	if (index - strlen > 0)
	{
		if (isalpha(str1[index + 1]) || isalpha(str1[index - strlen]))
			return 1;
		else
			return 0;
	}
	else if (isalpha(str1[index + 1]))
		return 1;
}
int find_str(char *str1, char *str2)
{
	int i, j, k, cnt = 0;

	for (i = 0; i <= strlen(str1); i++)
	{
		if (str1[i] == str2[0])
		{
				for (j = 0; j < strlen(str2); i++, j++)
				{
					if (str2[j] != str1[i])
						break;
				}
				i--;
				if (j == strlen(str2))
				{
					if(!isword(str1,i,j))
						cnt++;
				}
		}
	}
	return cnt;
}
int main()
{
	char str1[100] = "\0";
	char str2[100] = "\0";

	gets_s(str1, 100);
	gets_s(str2, 100);

	printf("%d", find_str(str1, str2));

	return 0;
}
*/
//4-1
/*
int isnumber(char x)
{
		if ('0' <= x && x <= '9')
			return 1;
		else
			return 0;

}
int setnum(char *str, float *fnum)
{
	int i,j,k,idx=0;
	char rtnum[100][100] = { "\0" };

	for (i = 0; i < strlen(str); i++)
	{
		if (isnumber(str[i]))
		{
			for (j = i,k=0;;k++, j++)
			{
				if (!isnumber(str[j]))
					break;
				else
				{
					rtnum[idx][k] = str[j];
				}
			}
			fnum[idx] = (float)atoi(rtnum[idx]);
			idx++;

			i = j-1;
		}
		
	}
	return idx;

}
int main()
{
	char str[101];
	float fnum[101];
	int n;

	gets_s(str, 100);

	n=setnum(str,fnum);

	for(int i=0;i<n;i++)
	printf(" %.0f", fnum[i]);


	return 0;

}
*/
//4-2
/*
int isnumber(char x)
{
	if ('0' <= x && x <= '9')
		return 1;
	else if (x == '-')
		return 2;
	else
		return 0;

}
int setnum(char *str, float *fnum)
{
	int i, j, k, idx = 0;
	char rtnum[100][100] = { "\0" };

	for (i = 0; i < strlen(str); i++)
	{
		if (isnumber(str[i]))
		{
			for (j = i, k = 0;; k++, j++)
			{
				if (!isnumber(str[j]))
					break;

				else if (isnumber(str[j]) == 2)
				{
					if (k > 0)
					{
						if (isnumber(str[j - 1]) == 1)
							break;
					}
					rtnum[idx][k] = str[j];
					if (isnumber(str[j + 1]) == 0)
					{
						j++;

						if (isnumber(str[j + 1]) == 2)
						{
							j++;
						}

					}

				}
				else
				{
					rtnum[idx][k] = str[j];
				}
			}

			fnum[idx] = (float)atoi(rtnum[idx]);
			idx++;

			i = j - 1;
		}

	}
	return idx;

}
int main()
{
	char str[101];
	float fnum[101];
	int n;

	gets_s(str, 100);

	n = setnum(str, fnum);

	for (int i = 0; i < n; i++)
		printf(" %.0f", fnum[i]);


	return 0;

}
*/
//4-3
/*
float add(float *result,int n)
{
	float num = 0;
	for (int i = 0; i < n; i++)
		num += result[i];
	return num;

}
int isnumber(char x)
{
	if ('0' <= x && x <= '9')
		return 1;
	else if (x == '-')
		return 2;
	else
		return 0;

}
void oprtor(char *str, int n,char *op)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (!isnumber(str[i])||isnumber(str[i])==2)
		{
			if (str[i] != ' ')
			{
				op[k] = str[i];
				k++;
			}
		}
	}
	str[k] = ' ';
}
int ismuldiv(char x)
{
	if (x == '*')
		return 1;
	else if (x == '/')
		return 2;
	else
		return 0;

}
int mul_div(float *fnum, char *op, int n, float *result)
{
	int j, k, size, idx, cnt = 0;

	for (int i = 0, idx = 0; i < n; i++, idx++)
	{
		if (!ismuldiv(op[i]))
		{
			result[idx] = fnum[i];
		}

		else  
		{
			cnt++;
			for (j = 1; ; j++)
			{
				if (!ismuldiv(op[i + j]))
				{
					if (j == 1)
					{
						if (ismuldiv(op[i]) == 1)
							result[idx] = fnum[i] * fnum[i + 1];
						if (ismuldiv(op[i]) == 2)
							result[idx] = fnum[i] / fnum[i + 1];

					}
					break;
				}
				else
				{
					cnt++;
					for (k = 0; ; k++)
					{
						if (!ismuldiv(op[i + k]))
							break;
						if (ismuldiv(op[i+k]) == 1)
							fnum[i] = fnum[i] * fnum[i +k+ 1];
						if (ismuldiv(op[i+k]) == 2)
							fnum[i] = fnum[i] / fnum[i +k+ 1];
					}
					result[idx] = fnum[i];
					if (k>=2)
					j = j + k-2;
				}
			}
			i = i + j;
		}
	}
		size = n - cnt;
		return size;
}
int setnum(char *str, float *fnum)
{
	int i, j, k, idx = 0;
	char rtnum[100][100] = { "\0" };

	for (i = 0; i < strlen(str); i++)
	{
		if (isnumber(str[i]))
		{
			for (j = i, k = 0;; k++, j++)
			{
				if (!isnumber(str[j]))
					break;

				else if (isnumber(str[j]) == 2)
				{
					if (k > 0)
					{
						if (isnumber(str[j - 1]) == 1)
							break;
					}
					rtnum[idx][k] = str[j];
					if (isnumber(str[j + 1]) == 0)
					{
						j++;
						if (isnumber(str[j + 1]) == 2)
						{
							j++;
						}
					}
				}
				else
				{
					rtnum[idx][k] = str[j];
				}
			}
			fnum[idx] = (float)atoi(rtnum[idx]);
			idx++;
			i = j - 1;
		}
	}
	return idx;
}
int main()
{
	char str[101],op[10]="\0";
	float fnum[101];
	float resultnum[101] = { 0 };
	int n,sizenum;

	gets_s(str, 100);

	n = setnum(str, fnum);
	oprtor(str, strlen(str), op);
	sizenum=mul_div(fnum, op, n, resultnum);

	printf("%f", add(resultnum,sizenum));

	return 0;
}
*/
