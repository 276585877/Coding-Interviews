// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿
// ���磬���� 1->2->3->3->4->4->5
// ��㱻ɾ��֮��1->2->5


#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"
void DeleteDuplication(BNode** pHead)
{
	if (*pHead == NULL)
	{
		return;
	}

	BNode *pPreNode = NULL;
	BNode *pNode = *pHead;
	while (pNode != NULL)
	{
		BNode *pNext = pNode->next;
		bool needDel = false;
		if (pNext != NULL && pNext->data == pNode->data)
		{
			needDel = true;
		}

		if (!needDel)
		{
			pPreNode = pNode;
			pNode = pNode->next;
		}
		else
		{
			int data = pNode->data;
			BNode *pDel = pNode;
			while (pDel != NULL && pDel->data == data)
			{
				pNext = pDel->next;
				free(pDel);
				pDel = NULL;
				pDel = pNext;
			}
			if (pPreNode == NULL)
			{
				*pHead = pNext;
			}
			else
			{
				pPreNode->next = pNext;
			}
			pNode = pNext;
		}
	}
}

// ====================���Դ���====================

// ĳЩ������ظ���
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// û���ظ��Ľ��
void Test2()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Insert_tail(&N,6);
	Insert_tail(&N,7);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// ����һ�����֮���������н���ֵ����ͬ
void Test3()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// ���н���ֵ����ͬ
void Test4()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// ���н�㶼�ɶԳ���
void Test5()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,4);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// �����������֮��������㶼�ɶԳ���
void Test6()
{
   	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	Insert_tail(&N,5);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");

}

// ������ֻ���������ظ��Ľ��
void Test7()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// �����ֻ��һ�����
void Test8()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// �����ֻ�������ظ��Ľ��
void Test9()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,1);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
}

// ������
void Test10()
{
    BTlist N;
	InitList(&N);
	Show(N);
	DeleteDuplication(&N);
	Show(N);
	printf("\n");
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

    return 0;
}