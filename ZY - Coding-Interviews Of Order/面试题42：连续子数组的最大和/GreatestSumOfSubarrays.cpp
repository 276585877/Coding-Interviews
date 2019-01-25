// ������42�����������������
// ��Ŀ������һ���������飬������������Ҳ�и�����������һ���������Ķ����
// �����һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��

#include <stdio.h>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if (pData == NULL || nLength <= 0)
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;

	for (int i = 0; i < nLength; i++)
	{
		if (nCurSum < 0)
		{
			nCurSum = pData[i];
		}
		else
		{
			nCurSum += pData[i];
		}
		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}
	return nGreatestSum;
}



// ====================���Դ���====================

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
	int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   //  18
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   // -1
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    int length = sizeof(data)/sizeof(data[0]);
	printf("%d\n",FindGreatestSumOfSubArray(data,length));   // 25
}

// ��Ч����
void Test4()
{
	int *data = NULL;
    int length = 0;
	printf("%d\n",FindGreatestSumOfSubArray(data,length)); // null
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}
