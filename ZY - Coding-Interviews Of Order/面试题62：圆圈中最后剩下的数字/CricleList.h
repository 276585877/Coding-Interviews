#pragma once
typedef struct CList
{
	int data;
	struct CList *next;
}CList,*CTlist;

void InitList(CTlist *plist);  //��ʼ��

bool Insert_head(CTlist *plist,int val);  //ͷ�巨

bool CreateLoop(CTlist *plist);

bool Insert_tail(CTlist *plist,int val);

CList *Search(CTlist *plist,int key);

CList *Search_pri(CTlist *plist,int key);

bool Delete(CTlist *plist,int key);

int GetLength(CTlist *plist);

void Show(CTlist *plist);
