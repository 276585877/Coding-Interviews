#pragma once
typedef struct Node
{
	int data;
	Node *next;
}Node,*List;

void InitList(List plist);//��ʼ��������

bool Insert_head(List plist,int val);//ͷ�巨

bool Insert_tail(List plist,int val);//β�巨

bool Insert_pos(List plist,int pos,int val);//pos λ�ò���

bool IsEmpty(List plist);//�Ƿ�Ϊ��

Node *Search_pre(List plist,int key);//���� key ��ǰ��

bool Delete(List plist,int key);//ɾ�� key ������

void Destroy(List plist);//�ݻٺ���������ж�̬�����ڴ棩

int GetLength(List plist);//�õ��������ĳ���

void Show(List plist);//��ӡ������