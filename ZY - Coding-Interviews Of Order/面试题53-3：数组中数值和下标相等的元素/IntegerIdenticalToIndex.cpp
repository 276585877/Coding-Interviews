// ������53����������������ֵ���±���ȵ�Ԫ��
// ��Ŀ������һ�������������������ÿ��Ԫ�ض�������������Ψһ�ġ�����ʵ
// ��һ�������ҳ�����������һ����ֵ�������±��Ԫ�ء����磬������{-3, -1,
// 1, 3, 5}�У�����3�������±���ȡ�

#include <stdio.h>

int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (right + left) >> 1;
		if (numbers[middle] == middle)
		{
			return middle;
		}
		if (numbers[middle] > middle)   // ��middleֵ ���� �� �±꣬���ұ�����Ԫ�ض���ֵ�����±�
		{
			right = middle - 1;  // ��middle�����
		}
		else
		{
			left = middle + 1;  // �ұ���
		}
	}
	return -1;
}



// ====================���Դ���====================

void Test1()
{
    int numbers[] = { -3, -1, 1, 3, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 3
}

void Test2()
{
    int numbers[] = { 0, 1, 3, 5, 6 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 0
}

void Test3()
{
    int numbers[] = { -1, 0, 1, 2, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 4
}

void Test4()
{
    int numbers[] = { -1, 0, 1, 2, 5 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
}

void Test5()
{
    int numbers[] = { 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // 0
}

void Test6()
{
    int numbers[] = { 10 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
}

void Test7()
{
	int *numbers = NULL;
    int length = -1;
	printf("%d\n",GetNumberSameAsIndex(numbers,length));  // -1
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
}