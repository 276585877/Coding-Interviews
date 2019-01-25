// ������59��һ�����������ڵ����ֵ
// ��Ŀ������һ������ͻ������ڵĴ�С�����ҳ����л�������������ֵ�����磬
// �����������{2, 3, 4, 2, 6, 2, 5, 1}���������ڵĴ�С3����ôһ������6��
// �������ڣ����ǵ����ֵ�ֱ�Ϊ{4, 4, 6, 6, 6, 5}��

#include <stdio.h>
#include "deque.h"

void maxInWindows(int *num, unsigned int length,unsigned int size)
{
	int maxInWindow = 0;
	if (length >= size && size >= 1)
	{
		Queue qu;
		InitQueueS(&qu);

		for (unsigned int i = 0; i < size; i++)
		{
			while (!IsEmpty(&qu) && num[i] >= num[Get_back(&qu)])   // �ѵ�ǰԪ��С�Ķ���Ԫ��ȫ���޳���Ȼ��ѵ�ǰԪ�ش����β
			{
				Pop_back(&qu);
			}
			Push_back(&qu,i);
		}

		for (unsigned int i = size; i < length; i++)
		{
			maxInWindow = num[Get_front(&qu)];  // �������ڵ����ֵ����λ�ڶ��е�ͷ��
			printf("%d ",maxInWindow);

			while (!IsEmpty(&qu) && num[i] >= num[Get_back(&qu)])
			{
				Pop_back(&qu);
			}
			if (!IsEmpty(&qu) && Get_front(&qu) <= (int)(i - size))
			{
				Pop_front(&qu);
			}
			Push_back(&qu,i);
		}
		maxInWindow = num[Get_front(&qu)];
		printf("%d ",maxInWindow);
		printf("\n");
	}
	else
	{
		printf("NULL\n");
	}
}
// ====================���Դ���====================

void Test1()
{
    int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,3);  // 4, 4, 6, 6, 6, 5
}

void Test2()
{
    int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,3);  // 3, 3, 5, 5, 6, 7
}

// �������鵥������
void Test3()
{
    int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,4);  // 7, 9, 11, 13, 15
}

// �������鵥���ݼ�
void Test4()
{
    int num[] = { 16, 14, 12, 10, 8, 6, 4 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,5);  // 16, 14, 12
}

// �������ڵĴ�СΪ1
void Test5()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,1);  // 10, 14, 12, 11
}

// �������ڵĴ�С��������ĳ���
void Test6()
{
    int num[] = { 10, 14, 12, 11 };
   unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,4);  // 14
}

// �������ڵĴ�СΪ0
void Test7()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,0);  // NULL
}

// �������ڵĴ�С������������ĳ���
void Test8()
{
    int num[] = { 10, 14, 12, 11 };
    unsigned int length = sizeof(num)/sizeof(num[0]);
	maxInWindows(num,length,5);  // NULL
}

// ��������Ϊ��
void Test9()
{
    int *num = NULL;
    unsigned int length = 0;
	maxInWindows(num,length,5);  // NULL
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