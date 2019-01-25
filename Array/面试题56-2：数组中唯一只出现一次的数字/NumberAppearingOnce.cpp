// ������56��������������Ψһֻ����һ�ε�����
// ��Ŀ����һ�������г���һ������ֻ����һ��֮�⣬�������ֶ����������Ρ���
// �ҳ��Ǹ��Գ���һ�ε����֡�

#include <stdio.h>

int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == NULL || length <= 0 )
	{
		return -1;
	}

	int bitSum[32] = {0};

	for (int i = 0; i < length; i++)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; j--)
		{
			int bit = numbers[i] & bitMask;
			if (bit != 0)
			{
				bitSum[j] += 1;
			}
			bitMask <<= 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;   // result ÿ������һλ
		result += bitSum[i] % 3;   // ÿ�ν��ұ�һλ����result
	}
	return result;
}



// ====================���Դ���====================

// �������ֶ���������Ψһ����������С��
void Test1()
{
    int numbers[] = { 1, 1, 2, 2, 3 ,2, 1};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3
}

// �������ֶ���������Ψһ�����ֵĴ�Сλ���м�
void Test2()
{
    int numbers[] = { 4, 3, 3, 2, 2, 2, 3 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 4
}

// �������ֶ���������Ψһ������������
void Test3()
{
    int numbers[] = { 4, 4, 1, 1, 1, 7, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 7
}

// Ψһ�������Ǹ���
void Test4()
{
    int numbers[] = { -10, 214, 214, 214 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // -10
}

// ����Ψһ�����֣��������ֶ��Ǹ���
void Test5()
{
    int numbers[] = { -209, 3467, -209, -209 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3467
}

// �ظ�������������Ҳ�и���
void Test6()
{
    int numbers[] = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 1023
}

// �������ֶ��Ǹ���
void Test7()
{
    int numbers[] = { -1024, -1024, -1024, -1023 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // -1023
}

// Ψһ��������0
void Test8()
{
    int numbers[] = { -23, 0, 214, -23, 214, -23, 214 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 0
}

// ����Ψһ�����֣��������ֶ���0
void Test9()
{
    int numbers[] = { 0, 3467, 0, 0, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",FindNumberAppearingOnce(numbers,length));  // 3467
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
}