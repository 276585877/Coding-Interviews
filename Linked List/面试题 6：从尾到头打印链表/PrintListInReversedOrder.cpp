// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��

#include<stdio.h>
#include<assert.h>
#include "LinkList.h"

void PrintListReversingly_Recursively(Node* pHead)
{
	if (pHead->next != NULL)
	{
		PrintListReversingly_Recursively(pHead->next);
		printf("%d ",pHead->next->data);	// 	pHead->next == NULL �᷵�� �ϲ㺯�� ��� pHead->next->data ���һ���ڵ�����
	}
}


// ====================���Դ���====================


// 1->2->3->4->5
void Test1()
{
	Node list;
	InitList(&list);
	Insert_tail(&list,1);
	Insert_tail(&list,2);
	Insert_tail(&list,3);
	Insert_tail(&list,4);
	Insert_tail(&list,5);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

// ֻ��һ����������: 1
void Test2()
{
    Node list;
	InitList(&list);
	Insert_tail(&list,1);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

// ������
void Test3()
{
    Node list;
	InitList(&list);
	PrintListReversingly_Recursively(&list);
	printf("\n");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}



