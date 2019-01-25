// ������44������������ĳһλ������
// ��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
// �������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
// ������������λ��Ӧ�����֡�


#include <stdio.h>
#include <math.h>

int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if (index < 0)
	{
		return 0;
	}

	int digit = 1;
	while (true)
	{
		int numbers = countOfIntegers(digit);
		if (index < numbers * digit)
		{
			return digitAtIndex(index,digit);
		}
		index -= numbers * digit;
		digit++;
	}
	return -1;
}

int countOfIntegers(int digits)
{
	if (digits == 1)
	{
		return 10;
	}
	int count =	pow((double)10,digits - 1);
	return 9 * count;
}


int digitAtIndex(int index, int digits)
{
	int number = beginNumber(digits) + index / digits;
	int indexFromNum = digits - index % digits;
	for (int i = 1; i < indexFromNum; i++)
	{
		number /= 10;
	}
	return number % 10;
}


int beginNumber(int digits)
{
	if (digits == 1)
	{
		return 0;
	}
	return pow((double)10,digits - 1);
}


// ====================���Դ���====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if(digitAtIndex(inputIndex) == expectedOutput)
		printf("%s:passed\n",testName);
	else
		printf("%s:FAILED\n",testName);
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // ����99�����һλ��9
	test("Test6", 190, 1);  // ����100�ĵ�һλ��1
	test("Test7", 1000, 3); // ����370�ĵ�һλ��3
	test("Test8", 1001, 7); // ����370�ĵڶ�λ��7
	test("Test9", 1002, 0); // ����370�ĵ���λ��0
	return 0;
}