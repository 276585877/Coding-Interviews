// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣


#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

BNode* ReverseList(BNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	BNode *pReversedHead = NULL;
	BNode *pNode = pHead;
	BNode *pPrev = NULL;
	while (pNode != NULL)
	{
		BNode *pNext = pNode->next;
		if (pNext == NULL)
		{
			pReversedHead = pNode;
		}
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pReversedHead;
}


// ====================���Դ���====================
BNode* Test(BNode* pHead)
{
    printf("The original list is: \n");
	Show(pHead);

    BNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    Show(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Test(N);
}

// ���������ֻ��һ�����
void Test2()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Test(N);
}

// ���������
void Test3()
{
    BTlist N;
	InitList(&N);
	Test(N);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}
