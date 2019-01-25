#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "LinkList.h"

void InitList(BTlist *plist)
{
	*plist = NULL;
}

static BNode *GetNode(int val)
{
	BNode* pGet = (BNode *)malloc(sizeof(BNode));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

bool Insert_head(BTlist *plist,int val)
{
	BTlist pGet = GetNode(val);
	assert(pGet != NULL);
	pGet->next = *plist;
	*plist = pGet;
	return true;
}


bool Insert_tail(BTlist *plist,int val)
{
	BTlist p = *plist;
	BTlist cur = GetNode(val);
	if (p == NULL)  // ����Ϊ�յ����
	{
		*plist = cur;
	}
	else
	{
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = cur;
		return true;
	}
	return false;
}


bool Insert_pos(BTlist *plist,int pos,int val)
{
	if (pos < 0 || pos > GetLength(*plist))
	{
		return false;
	}
	BTlist p = *plist;
	BTlist cur = GetNode(val);

	if (p == NULL)   // ��������Ϊ�յ����
	{
		*plist = cur;
	}
	else if (pos != 0) 
	{
		for (int i = 0; i < pos-1; i++)
		{
			p = p->next;
		}
		cur->next = p->next;
		p->next = cur;
		return true;
	}
	else  // �ײ�����
	{
		cur->next = *plist;
		*plist = cur;
		return true;
	}
	return false;
}


BNode *Search(BTlist plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		return NULL;
	}
	BTlist p = plist;
	while (p != NULL)
	{
		if (p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}


BNode *Search_pri(BTlist plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(plist) || plist == NULL)
	{
		return NULL;
	}
	BTlist p = plist;
	while (p != NULL)
	{
		if (p->next->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}



bool Delete(BTlist *plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(*plist))
	{
		return false;
	}
	BTlist pDel = Search(*plist,key);
	if (pDel != *plist) // ɾ�����׽ڵ�
	{
		BTlist pDelpri = Search_pri(*plist,key);
		pDelpri->next = pDel->next;
		free(pDel);
		pDel = NULL;
		return true;
	}
	else   //ɾ���׽ڵ�
	{
		*plist = pDel->next;
		free(pDel);
		pDel = NULL;
		return true;
	}
	return false;
}


void Destroy(BTlist plist)
{
	assert(plist != NULL);
	BTlist p = NULL;
	while (plist != NULL)
	{
		p = plist->next;  // ָ��p����plist����һ�ڵ����Ϣ
		free(plist);  // �ͷ�plist
		plist = p;   
	}
}


void Show(BTlist plist)
{
	BTlist p = plist;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}


int GetLength(BTlist plist)
{
	int len = 0;
	BTlist p = plist;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}


bool IsEmpty(BTlist plist)
{
	if (plist == NULL)
	{
		return true;
	}
	return false;
}
