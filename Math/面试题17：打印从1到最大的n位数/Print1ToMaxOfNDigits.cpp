// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

/*
	˼·�����ǵ��������⣬��������ַ���ģ��ӷ��Ľⷨ
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
void Print1ToMaxOfNDigits_1(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = (char *)malloc(sizeof(char) * (n+1));
	memset(number,'0',n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	free(number);
}

bool Increment(char* number) // number�� 1 �ĺ��� ���ж��Ƿ񵽴����� n λ��
{
	bool isEnd = false;
	int nTakeOver = 0;
	int Llength = strlen(number);

	for (int i = Llength-1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == Llength-1)  // ��λ
		{
			nSum++;
		}
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isEnd = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isEnd;
}


void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}

		if (!isBeginning0)
		{
			printf("%c",number[i]);
		}
	}
	printf("\t");
}


// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    //Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}

