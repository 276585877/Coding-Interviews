// ������63����Ʊ���������
// ��Ŀ�������ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У������������׸ù�
// Ʊ���ܻ�õ������Ƕ��٣�����һֻ��Ʊ��ĳЩʱ��ڵ�ļ۸�Ϊ{9, 11, 8, 5,
// 7, 12, 16, 14}������������ڼ۸�Ϊ5��ʱ�����벢�ڼ۸�Ϊ16ʱ����������
// �ջ���������11��

#include <stdio.h>

int MaxDiff(const int* numbers, unsigned length)
{
	if (numbers == NULL || length < 2)
	{
		return 0x80000000;
	}

	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i-1] < min)
		{
			min = numbers[i-1];
		}

		int curMaxDiff = numbers[i] - min;
		if (curMaxDiff > maxDiff)
		{
			maxDiff = curMaxDiff;
		}
	}
	return maxDiff;
}




// ==================== Test Code ====================
void Test(const int* numbers, unsigned length)
{
	printf("%d\n",MaxDiff(numbers, length));
}

void Test1()
{
    int numbers[] = { 4, 1, 3, 2, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 4
}

// �۸����
void Test2()
{
    int numbers[] = { 1, 2, 4, 7, 11, 16 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 15
}

// �۸�ݼ�
void Test3()
{
    int numbers[] = { 16, 11, 7, 4, 2, 1 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // -1
}

// �۸�ȫ����ͬ
void Test4()
{
	int numbers[] = { 16, 16, 16, 16, 16 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 0
}

void Test5()
{
    int numbers[] = { 9, 11, 5, 7, 16, 1, 4, 2 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 11
}

void Test6()
{
    int numbers[] = { 2, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // 2
}

void Test7()
{
    int numbers[] = { 4, 2 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // -2
}

void Test8()
{
	int *numbers = NULL;
	int length = 0;
	Test(numbers,length);  // 
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
