// ������30������min������ջ
// ��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min
// �������ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��


#include<stdio.h>
#include "stack.h"

int main()
{
	Sqstack st;
	InitStack(&st);
	Sqstack st1;
	InitStack(&st1);
	Push(&st,&st1,3);
	printf("min==%d\n",Min(&st1));
	
	Push(&st,&st1,4);
	printf("min==%d\n",Min(&st1));

	Push(&st,&st1,2);
	printf("min==%d\n",Min(&st1));

	Push(&st,&st1,1);
	printf("min==%d\n",Min(&st1));

	Show(&st);
	Show(&st1);
	
	int tmp = 0;
	Pop(&st,&st1,&tmp);
	printf("����%d\n",tmp);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));


	Pop(&st,&st1,&tmp);
	printf("����%d\n",tmp);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));
	
	Push(&st,&st1,0);
	Show(&st);
	Show(&st1);
	printf("min==%d\n",Min(&st1));

	return 0;
}
