// ������35����������ĸ���
// ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
// ��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
// ����⣬����һ��m_pSibling ָ�������е����������nullptr��

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ComplexList.h"

ComplexListNode* CreateNode(int data)
{
	ComplexListNode *pNode = (ComplexListNode *)malloc(sizeof(ComplexListNode));
	assert(pNode != NULL);
	pNode->data = data;
	pNode->next = NULL;
	pNode->slbing = NULL;
	return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
	if (pNode != NULL)
	{
		pNode->next = pNext;
		pNode->slbing = pSibling;
	}
}


void PrintList(ComplexListNode* pHead)
{
	ComplexListNode *pNode = pHead;
	while (pNode != NULL)
	{
		printf("data==%d\n",pNode->data);
		if (pNode->slbing != NULL)
		{
			printf("sibing==%d\n",pNode->slbing->data);
		}
		else
		{
			printf("no sibing\n");
		}
		pNode = pNode->next;
	}
}
