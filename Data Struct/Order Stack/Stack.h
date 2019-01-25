#pragma once

#define STACK_LEN 20

typedef struct Sqstack
{
	int elem[STACK_LEN];
	int top;
}Sqstack,*Pstack;

void InitStack(Pstack ps);

bool IsFull(Pstack ps);

bool Push(Pstack ps,int val);

bool IsEmpty(Pstack ps);

bool Pop(Pstack ps,int *rtv);//ɾ��

bool GetTop(Pstack ps,int *rtv);//�õ�ջ��Ԫ�أ����ǲ�ɾ��

void Clear(Pstack ps);//top ָ��Ĳ���

void Destroy(Pstack ps);//����û�ж�̬�ڴ����

void Show(Pstack ps);