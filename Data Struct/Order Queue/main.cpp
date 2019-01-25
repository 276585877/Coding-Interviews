#include <stdio.h>
#include "myqueuec.h"

int main(void)
{
    int value;          //���ڱ�����ӵ�Ԫ��
    //�������ж���
    queue *PQueue = (queue *)malloc(sizeof(queue));
    if(!PQueue->pBase)
    {
        printf("�����ж�������ڴ�ʧ��\n");
        return -1;
    }

    //���ó�ʼ�����еĺ���
    initQueue(PQueue,MAX_SIZE);
    //���ó��Ӻ���
    //enQueue(PQueue, 1);
    //enQueue(PQueue, 2);
    //enQueue(PQueue, 3);
    //enQueue(PQueue, 4);
    //enQueue(PQueue, 5);
    //enQueue(PQueue, 6);
    //enQueue(PQueue, 7);
    //enQueue(PQueue, 8);

	for(int i = 0;i < 10;i++)
	{
		enQueue(PQueue,i);    //0-7
	}



    //���ñ������еĺ���
    queueTraverse(PQueue);
    //���ó��Ӻ���
    if(deQueue(PQueue, &value))
    {
        printf("����һ�Σ�Ԫ��Ϊ��%d\n", value);
    }
    queueTraverse(PQueue);
    if(deQueue(PQueue, &value))
    {
        printf("����һ�Σ�Ԫ��Ϊ��%d\n", value);
    }
    queueTraverse(PQueue);

    free(PQueue);
    PQueue = NULL;

    getchar();
    return 0;
}
