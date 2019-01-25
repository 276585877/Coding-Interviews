// ������43����1��n������1���ֵĴ���
// ��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ���������
// ����12����1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ====================����һ====================
int NumberOf1(unsigned int n);

int NumberOf1Between1AndN_Solution1(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; i++)
	{
		number += NumberOf1(i);
	}
	return number;
}

int NumberOf1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
		{
			number++;
		}
		n /= 10;
	}
	return number;
}


// ====================������====================
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumberOf1Between1AndN_Solution2(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	char strN[50];
	sprintf(strN,"%d",n);
	return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
	if (!strN || *strN < '0' || *strN >'9' || *strN == '\0')
	{
		return 0;
	}
	
	int first = *strN - '0';
	unsigned int length = (unsigned)strlen(strN);
	if (length == 1 && first == 0)
	{
		return 0;
	}
	if (length == 1 && first > 0)
	{
		return 1;
	}
	
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = PowerBase10(length-1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;  // ȥ�����λ���� 1
	}

	int numOtherDigits  = first * (length -1)  * PowerBase10(length - 2); // 1346 ���� 11345 ��11346 ���� 21345 ʣ�µ� 4 λ���� 2 * 4 * 10^3
	int numRecursive = NumberOf1(strN + 1);
	return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

// ====================���Դ���====================


void Test1()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(1),NumberOf1Between1AndN_Solution2(1)); // 1
}
void Test2()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(5),NumberOf1Between1AndN_Solution2(5)); // 1
}
void Test3()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(10),NumberOf1Between1AndN_Solution2(10)); // 2
}

void Test4()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(55),NumberOf1Between1AndN_Solution2(55)); // 16
}
void Test5()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(99),NumberOf1Between1AndN_Solution2(99)); // 20
}
void Test6()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(10000),NumberOf1Between1AndN_Solution2(10000)); // 4001
}
void Test7()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(21345),NumberOf1Between1AndN_Solution2(21345)); // 18821
}
void Test8()
{
	printf("solution1 == %d,solution2 == %d\n",NumberOf1Between1AndN_Solution1(0),NumberOf1Between1AndN_Solution2(0)); // 0
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}
