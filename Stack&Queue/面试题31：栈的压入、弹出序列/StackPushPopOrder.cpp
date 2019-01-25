// ������31��ջ��ѹ�롢��������
// ��Ŀ�����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ���������
// ��Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ���������1��2��3��4��
// 5��ĳջ��ѹջ���У�����4��5��3��2��1�Ǹ�ѹջ���ж�Ӧ��һ���������У���
// 4��3��5��1��2�Ͳ������Ǹ�ѹջ���еĵ������С�


#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
	if (pPush == NULL || pPop == NULL)
	{
		return false;
	}
	if (pPush != NULL && pPop != NULL && nLength > 0)
	{
		const int *NextPush = pPush;
		const int *NextPop = pPop;

		Sqstack stack;
		InitStack(&stack);

		while (NextPop - pPop < nLength)
		{
			int topElem = 0;
			GetTop(&stack,&topElem);
			while (IsEmpty(&stack) || topElem != *NextPop)
			{
				if (NextPush - pPush == nLength)
				{
					break;
				}
				Push(&stack,*NextPush);
				NextPush++;
				GetTop(&stack,&topElem);
			}

			GetTop(&stack,&topElem);
			if (topElem != *NextPop)
			{
				break;
			}
			int popElem = 0;
			Pop(&stack,&popElem);
			NextPop++;
		}

		if (IsEmpty(&stack) && NextPop - pPop == nLength)
		{
			return true;
		}
	}
	return false;
}

// ====================���Դ���====================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(IsPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else
        printf("failed.\n");
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    
    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    
    Test("Test2", push, pop, nLength, true);
}

void Test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    
    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2};
    
    Test("Test4", push, pop, nLength, false);
}

// push��pop����ֻ��һ������
void Test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
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

    return 0;
}
