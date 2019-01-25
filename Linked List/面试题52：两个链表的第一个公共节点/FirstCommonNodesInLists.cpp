// ������52����������ĵ�һ���������
// ��Ŀ���������������ҳ����ǵĵ�һ��������㡣

#include <stdio.h>
#include <math.h>
#include "LinkList.h"


BNode* FindFirstCommonNode(BNode *pHead1, BNode *pHead2)
{
	int length1 = GetLength(pHead1);
	int length2 = GetLength(pHead2);
	int length = length1 - length2;

	BNode *pLong = pHead1;
	BNode *pShort = pHead2;

	if (length1 < length2)
	{
		pLong = pHead2;
		pShort = pHead1;
		length = length2 - length1;
	}

	for (int i = 0; i < length; i++)
	{
		pLong = pLong->next;
	}

	while (pLong != NULL && pShort != NULL && pLong != pShort)
	{
		pLong = pLong->next;
		pShort = pShort->next;
	}

	BNode *pFirstCommonNode = pLong;
	return pFirstCommonNode;
}



// ====================���Դ���====================

// ��һ����������������м�
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
	BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,6);
	Insert_tail(&N1,7);

	Insert_tail(&N2,4);
	Insert_tail(&N2,5);

	N2->next->next = N1->next->next->next;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// û�й������
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	
	Insert_tail(&N2,5);
	Insert_tail(&N2,6);
	Insert_tail(&N2,7);

	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// ������������һ�����
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	Insert_tail(&N1,7);

	Insert_tail(&N2,5);
	Insert_tail(&N2,6);

	N2->next->next = N1->next->next->next->next;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// ��������ǵ�һ�����
// 1 - 2 - 3 - 4 - 5
// ����������ȫ�غ�   
void Test4()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);
	Insert_tail(&N1,3);
	Insert_tail(&N1,4);
	Insert_tail(&N1,5);

	N2 = N1;
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// ���������������һ��������
void Test5()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	Insert_tail(&N1,1);
	Insert_tail(&N1,2);

	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
}

// ��������������ǿ�����
void Test6()
{
    BTlist N1;
	BTlist N2;
	InitList(&N1);
	InitList(&N2);
	
	BNode *N3 = FindFirstCommonNode(N1,N2);
	if (N3 == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		printf("%d\n",N3->data);
	}
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