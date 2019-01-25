// ������22�������е�����k�����
// ��Ŀ������һ����������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ�������������β����ǵ�����1����㡣����һ��������6����㣬
// ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3�������
// ֵΪ4�Ľ�㡣



#include<stdio.h>
#include<stdlib.h>
#include<vld.h>
#include "Linklist.h"

BNode* FindKthToTail(BNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}

	BNode *pFast = pListHead;
	BNode *pSlow = pListHead;

	for (unsigned int i = 0; i < k-1; i++)
	{
		if (pFast->next != NULL)
		{
			pFast = pFast->next;
		}
		else
		{
			return NULL; // �������еĽڵ����С��k��
		}
	}

	while (pFast->next != NULL)
	{
		pFast = pFast->next;
		pSlow = pSlow->next;
	}
	return pSlow;
}



// ====================���Դ���====================
// ����Ҫ�ҵĽ���������м�
void Test1()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,2);
	printf("%d\n",result->data);   // 4
	Destroy(N);
}

// ����Ҫ�ҵĽ���������β���
void Test2()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,1);
	printf("%d\n",result->data);   //  5
	Destroy(N);
}

// ����Ҫ�ҵĽ���������ͷ���
void Test3()
{
   BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,5);   //   1
	printf("%d\n",result->data);
	Destroy(N);
}

// ���Կ�����
void Test4()
{
    BTlist N;
	InitList(&N);
	BNode *result = FindKthToTail(N,100);
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
}

// ��������ĵڶ���������������Ľ������
void Test5()
{
	BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,6);  // NULL
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
	Destroy(N);
}

// ��������ĵڶ�������Ϊ0
void Test6()
{
    BTlist N;
	InitList(&N);
	Insert_tail(&N,1);
	Insert_tail(&N,2);
	Insert_tail(&N,3);
	Insert_tail(&N,4);
	Insert_tail(&N,5);
	BNode *result = FindKthToTail(N,0);
	if (result == NULL)
	{
		printf("NULL\n"); // NULL

	}
	Destroy(N);
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

