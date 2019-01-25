// ������46�������ַ�����ַ���
// ��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
// ���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣��
// ��12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
// "mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int GetTranslationCount(const char *number);

int GetTranslationCount(int number)
{
	if (number < 0)
	{
		return 0;
	}
	char numberInString[100];
	itoa(number,numberInString,10);
	return GetTranslationCount(numberInString);
}

int GetTranslationCount(const char *number)
{
	int length = strlen(number);
	int *counts = (int *)malloc(sizeof(int) * length);
	int count = 0;

	for (int i = length - 1; i >= 0; i--)
	{
		count = 0;
		if (i < length - 1)
		{
			count = counts[i + 1];
		}
		else
		{
			count = 1;
		}

		if (i < length - 1)
		{
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;
			if (converted >= 10 && converted <= 25)
			{
				if (i < length - 2)
				{
					count += counts[i + 2];
				}
				else
				{
					count  += 1;
				}
			}
		}
		counts[i] = count;
	}
	count = counts[0];
	free(counts);
	return count;
}



// ====================���Դ���====================

void Test1()
{
    int number = 0;
	printf("%d\n",GetTranslationCount(number));  // 1
}

void Test2()
{
    int number = 10;
    printf("%d\n",GetTranslationCount(number));  // 2
}

void Test3()
{
    int number = 125;
	printf("%d\n",GetTranslationCount(number));  // 3

}

void Test4()
{
    int number = 126;
	printf("%d\n",GetTranslationCount(number));  // 2
}

void Test5()
{
    int number = 426;
	printf("%d\n",GetTranslationCount(number));  // 1
}

void Test6()
{
    int number = 100;
	printf("%d\n",GetTranslationCount(number));  // 2
}

void Test7()
{
    int number = 101;
	printf("%d\n",GetTranslationCount(number));  // 2
}

void Test8()
{
    int number = 12258;
	printf("%d\n",GetTranslationCount(number));  // 5
}

void Test9()
{
    int number = -100;
	printf("%d\n",GetTranslationCount(number));  // 0
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
    Test9();

    return 0;
}
