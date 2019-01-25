// ������53��������0��n-1��ȱʧ������
// ��Ŀ��һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ������
// ���ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1��n������������ֻ��һ�����ֲ��ڸ�����
// �У����ҳ�������֡�

#include <stdio.h>

int GetMissingNumber(const int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;

	while (left <= right)
	{
		int middle = (left + right) >> 1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
			{
				return middle;
			}
			else
			{
				right = middle - 1;
			}
		}
		else
		{
			left = middle + 1;  
		}
	}
	if (left == length)
	{
		return length;
	}
	return -1;
}



// ====================���Դ���====================


// ȱʧ���ǵ�һ������0
void Test1()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 0
}

// ȱʧ�������һ������
void Test2()
{
    int numbers[] = { 0, 1, 2, 3, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 5
}

// ȱʧ�����м�ĳ������0
void Test3()
{
    int numbers[] = { 0, 1, 2, 4, 5 };
int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 3
}

// ������ֻ��һ�����֣�ȱʧ���ǵ�һ������0
void Test4()
{
    int numbers[] = { 1 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 0
}

// ������ֻ��һ�����֣�ȱʧ�������һ������1
void Test5()
{
    int numbers[] = { 0 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("%d\n",GetMissingNumber(numbers,length));  // 1
}

// ������
void Test6()
{
	int *numbers = NULL;
	int length = 0;
	printf("%d\n",GetMissingNumber(numbers,length));  // -1
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
}