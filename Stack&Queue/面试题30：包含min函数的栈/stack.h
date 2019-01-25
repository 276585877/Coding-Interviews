#pragma once

#define STACK_LEN 20

typedef struct Sqstack
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;

void InitStack(Pstack ps);

bool IsFull(Pstack ps);

bool Push(Pstack ps,Pstack ps1,int val);

bool IsEmpty(Pstack ps);

bool Pop(Pstack ps,Pstack ps1,int *rtv);//ɾ��

int Min(Pstack ps);

bool GetTop(Pstack ps,int *rtv);//�õ�ջ��Ԫ�أ����ǲ�ɾ��

void Clear(Pstack ps);//top ָ��Ĳ���

void Show(Pstack ps);