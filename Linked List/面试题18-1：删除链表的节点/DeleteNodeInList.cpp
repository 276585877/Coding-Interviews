// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "LinkList.h"
void DeleteNode(BNode** pListHead, BNode* pToBeDeleted)
{
	if (!pListHead || !pToBeDeleted)
	{
		return;
	}

	// Ҫɾ���Ľڵ㲻��β�ڵ�
	if (pToBeDeleted->next != NULL)
	{
		BNode *pNext = pToBeDeleted->next;
		pToBeDeleted->data = pNext->data;
		pToBeDeleted->next = pNext->next;

		free(pNext);
		pNext = NULL;
	}

	// ����ֻ��һ���ڵ㣬ɾ��ͷ�ڵ㣨Ҳ��β�ڵ㣩
	else if (*pListHead == pToBeDeleted)
	{
		free(pToBeDeleted);
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	
	// �������ж���ڵ㣬ɾ��β�ڵ�
	else
	{
		BNode *pNode = *pListHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		free(pToBeDeleted);
		pToBeDeleted = NULL;
	}
}

// ====================���Դ���====================

// �������ж����㣬ɾ���м�Ľ��
void Test1()
{
	BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1->next->next);
	Show(N1);
}

// �������ж����㣬ɾ��β���
void Test2()
{
    BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1->next->next->next);
	Show(N1);
}


// �������ж����㣬ɾ��ͷ���
void Test3()
{
    BTlist N1;
	InitList(&N1);
	for (int i = 1; i < 5; i++)
	{
		Insert_tail(&N1,i);
	}
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    BTlist N1;
	InitList(&N1);
	Insert_tail(&N1,1);
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

// ����Ϊ��
void Test5()
{
    BTlist N1;
	InitList(&N1);
	Show(N1);
	DeleteNode(&N1,N1);
	Show(N1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

