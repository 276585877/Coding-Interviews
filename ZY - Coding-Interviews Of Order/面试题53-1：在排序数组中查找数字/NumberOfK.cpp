// ������53��һ�������������������г��ֵĴ���
// ��Ŀ��ͳ��һ�����������������г��ֵĴ���������������������{1, 2, 3, 3,3, 3, 4, 5}������3��
// ����3����������г�����4�Σ�������4��

#include <stdio.h>

int GetFirstK(const int* data, int length, int k, int start, int end);
int GetLastK(const int* data, int length, int k, int start, int end);

int GetNumberOfK(const int* data, int length, int k)
{
	if (data == NULL)
	{
		return 0;
	}
	int number = 0;
	if (length > 0)
	{
		int first = GetFirstK(data,length,k,0,length - 1);
		int last = GetLastK(data,length,k,0,length - 1);

		if (first > -1 && last > -1)
		{
			number = last - first + 1;
		}
	}
	return number;
}

int GetFirstK(const int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}
	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];
	
	if (middleData == k)
	{
		if ((middleIndex > 0 && data[middleIndex-1] != k) || middleIndex == 0)
		{
			return middleIndex;
		}
		else
		{
			end = middleIndex - 1;
		}
	}
	else if (middleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}
	return GetFirstK(data,length,k,start,end);
}

int GetLastK(const int* data, int length, int k, int start, int end)
{
	if (start > end)
	{
		return -1;
	}

	int middleIndex = (start + end) >> 1;
	int middleData = data[middleIndex];

	if (middleData == k)
	{
		if ((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
		{
			return middleIndex;
		}
		else
		{
			start = middleIndex + 1;
		}
	}
	else if (middleData > k)
	{
		end = middleIndex - 1;
	}
	else
	{
		start = middleIndex + 1;
	}
	return GetLastK(data,length,k,start,end);
}


// ====================���Դ���====================

// ���ҵ����ֳ�����������м�
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));   // 4
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  //4
}

// ���ҵ��������������Ľ�β
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  //4
}

// ���ҵ����ֲ�����
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,2));   // 0
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,0));  // 0
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,6));   // 0
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
    int data[] = {3, 3, 3, 3};
   int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));   // 4
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
    int data[] = {3, 3, 3, 3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,4));   // 0
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
    int data[] = {3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,3));  // 1
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
    int data[] = {3};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",GetNumberOfK(data,length,4));  // 0
}

// ³���Բ��ԣ������ָ��
void Test11()
{
	int *data = NULL;
    int length = 0;
	printf("%d\n",GetNumberOfK(data,length,3));  // 0
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
    Test10();
    Test11();

    return 0;
}
