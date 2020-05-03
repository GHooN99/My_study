#pragma warning(disable:4996)
#include <stdio.h>
//1번
/*
int main()
{
	char ch[21];
	char *i;
	scanf("%s", ch);

	for (i = ch; *i; i++)
	{
		if ('a' <= *i&&*i <= 'z')
			printf("%c", *i);
	}
	return 0;
}

//2번 

int main()
{
	char ch[10]="\0";
	int n,i=0;


	scanf("%d", &n);

	while (n > 0)
	{
		*(ch + i) = '0'+(char)(n % 10);
		n = n / 10;
		i++;
	}
	printf("%s", ch);
	return 0;
}

//3번
int main()
{
	char ch[101]="\0",*pch,*pch2,tmp;

	scanf("%s", ch);

	for (pch=ch;*pch;pch++)
	{

		printf("%s\n", ch);
		tmp = *ch;
		for (pch2 = ch; *(pch2+1); pch2++)
		{
				*pch2 = *(pch2 + 1);
				
		}
		*pch2 = tmp;

	}

	return 0;
}

//4번

int strlen(char *x)
{
	int i;
	for (i = 0; *(x + i); i++)
	{}
	return i;
}
int strcmp(char *x,char *y)
{
	int i;
	for (i = 0; *(x + i) && *(y + i); i++)
	{
		if (*(x + i) != *(y + i))
			return 0;
	}
	return 1;
}
int main()
{
	char ch1[101], ch2[101];

	scanf("%s", ch1);
	scanf("%s", ch2);

	printf("%d %d", strlen(ch1), strcmp(ch1, ch2));

	return 0;
}

//5번

int len(char *x)
{
	int i;
	for (i = 0; *(x + i); i++)
	{
	}
	return i;

}
void index_up(char *x, int n)
{
	int i;
	for (i = n+len(x); i>=n; i--)
	{
		*(x + i + 1) = *(x + i);
		
	}
}
void insert(char *x, char*y,int n)
{
	
	int i,k;
	char tmp;
	for (i = n,k=0; *(x + i) && *(y +k); i++,k++)
	{
		index_up(x,i);
		*(x + i) = *(y + k);
		
	}


}
int main()
{
	char str1[50]="\0", str2[50]="\0";
	int n;

	scanf("%s", str1);
	scanf("%s", str2);

	scanf("%d", &n);

	insert(str1, str2,n);

	printf("%s", str1);
	

	return 0;
}

//6번

void swap(char *x, char*y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
int len(char *x)
{
	int i;
	for (i = 0; *(x + i); i++)
	{
	}
	return i;

}

void index_up(char *x, int n)
{
	int i;
	for (i = n + len(x); i >= n; i--)
	{
		*(x + i + 1) = *(x + i);

	}
}

void reverse_str(char *x)
{
	int i;
	
		for (i = 0; i < (len(x)/2); i++)
		swap((x + i), (x + len(x) - 1 - i));
	

}
void insert(char *x, char*y, int n,int reverse)
{

	if (reverse)
		reverse_str(y);

	int i, k;
	char tmp;
	for (i = n, k = 0; *(x + i) && *(y + k); i++, k++)
	{
		index_up(x, i);
		*(x + i) = *(y + k);

	}


}
int main()
{
	char str1[50] = "\0", str2[50] = "\0";
	int n,re;

	scanf("%s", str1);
	scanf("%s", str2);

	scanf("%d", &n);
	scanf("%d", &re);

	insert(str1, str2, n,re);

	printf("%s", str1);


	return 0;
}

//7번

int main()
{

	char *str1[9] = { "one", "two","three", "four", "five", "six", "seven" ,"eight" ,"nine" };
	char *str2[3] = { "THO","HUN","TEN" };
	int d[4];
	int n, i, di;
	int num;

	scanf("%d", &n);

	for (i = 0; n > 0; i++, n = n / 10)
		d[i] = n % 10;

	di = i;

	for (i = di - 1; i >= 0; i--)
	{
		num = d[i];
		if (i >= 1)
		{
			if (num)
				printf("%s %s ", str1[num - 1], str2[3 - i]);
		}
		else
			if (num)
				printf("%s", str1[num - 1]);

	}




	return 0;
}

//8번

#include <string.h>

int main()
{
	char str1[51], str2[51];
	char str[102];
	int s;

	scanf("%s", str1);
	scanf("%s", str2);

	s=strcmp(str1, str2);

	if (s < 0)
	{
		strcpy(str, str2);

		strcat(str, str1);
	}
	else
	{
		strcpy(str, str1);
		strcat(str, str2);
	}

	printf("%s", str);




	return 0;

}

//9번

#include <string.h>
int check(char *ch)
{
	int i, n = strlen(ch);
	for (i = 0; i < n / 2; i++)
	{
		if (ch[i] != ch[n - i - 1])
			return 0;
	}
	return 1;
}
int main()
{
	char ch[31];

	scanf("%s", ch);

	printf("%d %d",strlen(ch),check(ch));



	return 0;

}

//10번 
#include <string.h>
int main()
{
	char ch[101][101];

	int n,i;

	scanf("%d", &n);

	getchar();

	for (i = 0; i < n; i++)
		gets(ch[i]);
	
	int index = 0, min = 200, len;
	for (i = 0; i < n; i++)
	{
			len = strlen(ch[i]);
			if (len < min)
			{
				min = len;
				index = i;
			}
		}
		printf("%s",ch[index] );

	return 0;
}
//11번 


int strcheck(char *str1, char *str2)
{
	int i, k = 0;

	for (i = 0; str1[i]; i++)
	{
	
		if (str1[i] == str2[0])
		{
			for (k=1;str2[k];k++)
			{
				if (str1[i + k] != str2[k])
				{
					break;
				}
				
			}
			if (k == strlen(str2))
				return 1;
		}

	}

	return 0;

}
int main()
{
	char str1[81], str2[11];

	scanf("%s", str1);
	scanf("%s", str2);


	printf("%d %d", strlen(str1), strcheck(str1, str2));

	return 0;
}

//12 번 
int checkstr(char *str1, char *str2)
{
	int cnt = 0;
	int i, k;
	
	for (i = 0; str1[i]; i++)
	{
		if (str1[i] == str2[0])
		{
			if (strlen(str2) > 1)
			{
				for (k = 1; str2[k]; k++)
				{
					if (str1[i + k] != str2[k])
					{
						break;
					}

				}
				if (k == strlen(str2))
				{
					cnt++;
					i += (strlen(str2)-1);
				}
			}
			else
			cnt++;
		}
		
	}
	return cnt;

}

int main()
{
	char str1[101], str2[101];
	
	gets(str1);
	gets(str2);



	printf("%d", checkstr(str1, str2));

	return 0;
}
*/




