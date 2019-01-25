// ������39�������г��ִ�������һ�������
// ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
// ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
// ������5�Σ��������鳤�ȵ�һ�룬������2��

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == NULL || length <= 0 )
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}
bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}
	bool isMoreThanHalf = true;
	if (times * 2 < length)
	{
		isMoreThanHalf = false;
		g_bInputInvalid = true;
	}
	return isMoreThanHalf;
}

void Swap(int *arr,int low,int high)
{
	int temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

int Partition(int *arr,int low,int high)
{
	srand((unsigned)time(NULL));
	Swap(arr,low,low + rand()%(high - low + 1));

	int start = low;
	int end = high;
	int index = arr[low];
	while (start < end)
	{
		while (start < end && arr[end] >= index )  { end--; }
		arr[start] = arr[end];
		while (start < end && arr[end] <= index)   { start++; }
		arr[end] = arr[start];
	}
	arr[start] = index;
	return start;
}


// ====================����1====================
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
	if (CheckInvalidArray(numbers,length))
	{
		return 0;
	}
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers,start,end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers,start,end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers,start,end);
		}
	}

	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers,length,result))
	{
		return 0;
	}
	return result;
}

// ====================����2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
	if (CheckInvalidArray(numbers,length))
	{
		return 0;
	}
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if(numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if (!CheckMoreThanHalf(numbers,length,result))
	{
		return 0;
	}
	return result;
}

// ====================���Դ���====================

// ���ڳ��ִ����������鳤��һ�������
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

// �����ڳ��ִ����������鳤��һ�������
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

// ���ִ����������鳤��һ������ֶ������������ǰ�벿��
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

// ���ִ����������鳤��һ������ֶ�����������ĺ�벿��
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

// �����ָ��
void Test5()
{
    int numbers[] = {1};
    int length = sizeof(numbers)/sizeof(numbers[0]);
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

// �����ָ��
void Test6()
{
	int *numbers = NULL;
    int length = 0;
	printf("solution1 == %d\n",MoreThanHalfNum_Solution1(numbers,length));
	printf("solution2 == %d\n",MoreThanHalfNum_Solution2(numbers,length));
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

