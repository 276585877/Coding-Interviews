// ������56��һ����������ֻ����һ�ε���������
// ��Ŀ��һ�����������������������֮�⣬���������ֶ����������Ρ���д����
// �ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

#include <stdio.h>

unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == NULL || length < 2)
	{
		return;
	}

	int resultOR = 0;
	for (int i = 0; i < length; i++)
	{
		resultOR ^= data[i];
	}

	int indexOf1 = FindFirstBitIs1(resultOR);
	
	*num1 = *num2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (IsBit1(data[i],indexOf1))
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

unsigned int FindFirstBitIs1(int num)		// �ҵ�num���ұ������һ����1��λ��
{
	int indexBit = 0;
	while ((num & 1) == 0 && (indexBit < 8 * sizeof(int)))
	{
		num >>= 1;
		indexBit++;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)		// �ж�����num�ĵ�indexBitλ�ǲ���1
{
	num >>= indexBit;
	return (num & 1);
}


// ====================���Դ���====================

void Test1()
{
    int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	int length = sizeof(data) / sizeof(data[0]);
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(data,length,&num1,&num2);
	printf("%d,%d\n",num1,num2);  // 4 6
}

void Test2()
{
    int data[] = { 4, 6 };
    int length = sizeof(data) / sizeof(data[0]);
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(data,length,&num1,&num2);
	printf("%d,%d\n",num1,num2);  // 4 6
}

void Test3()
{
    int data[] = { 4, 6, 1, 1, 1, 1 };
    int length = sizeof(data) / sizeof(data[0]);
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(data,length,&num1,&num2);
	printf("%d,%d\n",num1,num2);  // 4 6
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}