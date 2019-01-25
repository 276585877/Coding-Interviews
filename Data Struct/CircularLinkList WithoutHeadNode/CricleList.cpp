#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include "CricleList.h"

void InitList(CTlist *plist)  //��ʼ��
{
	*plist = NULL;
}

CList *GetNode(int val)
{
	CList *pGet = (CList *)malloc(sizeof(CList));
	assert(pGet != NULL);
	pGet->data = val;
	pGet->next = NULL;
	return pGet;
}

bool Insert_head(CTlist *plist,int val)  //ͷ�巨
{
	CList *pGet = GetNode(val);
	assert(pGet != NULL);
	
	pGet->next = *plist;
	*plist = pGet;

	return true;
}

bool CreateLoop(CTlist *plist)  // ͷ�巨����
{
	if (*plist != NULL)
	{
		CList *p = *plist;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = *plist;
	}
	return true;
}

bool Insert_tail(CTlist *plist,int val)
{
	CList *pGet = GetNode(val);
	assert(pGet != NULL);
	
	if (*plist == NULL) // ���׽ڵ�
	{
		*plist = pGet;
		pGet->next = *plist;
	}
	else // ���׽ڵ�,��Ҫ���ҵ�ǰ���ڵ�
	{
		CList *p = *plist;
		while (p->next != *plist)
		{
			p = p->next;
		}
		p->next = pGet;
		pGet->next = *plist;
	}
	return true;
}

bool IsEmpty(CTlist *plist)
{
	return *plist == NULL;
}

CList *Search(CTlist *plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		return NULL;
	}
	CList *p = *plist;
	while (p->next != *plist)
	{
		if (p->data == key)
		{
			return p;
		}
		p = p->next;
	}
	if (p->data == key)
	{
		return p;
	}
	return NULL;
}

CList *Search_pri(CTlist *plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		return NULL;
	}
	CList *p = *plist;
	while (p->next != *plist)
	{
		if (p->next->data == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool Delete(CTlist *plist,int key)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		return false;
	}
	CTlist pDel = Search(plist,key);
	if (pDel != *plist) // ɾ�����׽ڵ�
	{
		CTlist pDelpri = Search_pri(plist,key);
		pDelpri->next = pDel->next;
		free(pDel);
		pDel = NULL;
		return true;
	}
	else   //ɾ���׽ڵ�
	{
		CTlist p = *plist;
		while (p->next != *plist)
		{
			p = p->next;
		}
		p->next = pDel->next;
		*plist = pDel->next;
		

		free(pDel);
		pDel = NULL;
		return true;
	}
	return false;
}

int GetLength(CTlist *plist)
{
	int length = 0;
	CList *p = *plist;
	while (p->next != *plist)
	{
		length++;
		p = p ->next;
	}
	return length+1;
}

void Show(CTlist *plist)
{
	CList *p = *plist;
	while (p->next != *plist)
	{
		printf("%d ",p->data);
		p = p ->next;
	}
	printf("%d ",p->data);
	printf("%d ",p->next->data);
	printf("%d ",p->next->next->data);
	printf("\n");
}

