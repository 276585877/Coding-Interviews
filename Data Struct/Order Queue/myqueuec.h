#ifndef MYQUEUEC_H
#define MYQUEUEC_H

#include <stdio.h>
#include <malloc.h>

/* ����: ֻ�����ڱ��һ��(��βrear)���в��������������һ��(��ͷfront)����ɾ�����������Ա�
 * ����������Ϊ���  ɾ���������Ϊ����   ���о����Ƚ��ȳ����ص�
 */

/*=====���е���ӡ�����ʾ��ͼ========
 *
 *  ���� ----------------- ���
 *   <--- a1,a2,a3,...,an <---
 *      -----------------
 *
 *================================*/

typedef enum
{
    OK=0, //��ȷ
    ERROR=1,   //����
    TRUE=2,  //Ϊ��
    FALSE=3   //Ϊ��
}status;

typedef int ElemType;   //�궨����е���������
#define MAX_SIZE 10

/*һ��ʹ������洢���еĳ�Ϊ��̬˳�����
 *����ʹ�ö�̬�����ָ��ĳ�Ϊ��̬˳�����*/
// ��������Ƕ�̬˳����С�
typedef struct
{
    ElemType *pBase;    //����ָ��
    ElemType front;      //��ͷ����
    ElemType rear;       //��β����
    int maxSize;    //��ǰ������������
}queue;

//�����ն��� queueCapacity-��������
status initQueue(queue *PQueue,int queueCapacity);
//���ٶ���
void destroyQueue(queue *PQueue);
//��ն���
void clearQueue(queue *PQueue);
//�ж϶����Ƿ�Ϊ��
status isEmpityQueue(queue *PQueue);
//�ж϶����Ƿ�Ϊ��
status isFullQueue(queue *PQueue);
//��ö��г���
int getQueueLen(queue *PQueue);
//��Ԫ����� [�Ƚ��ȳ�ԭ���ڶ�β��λ�ò���] element-Ҫ����Ԫ��
status enQueue(queue *PQueue,ElemType element);
//��Ԫ�س���,ͬʱ������ӵ�Ԫ�� [�Ƚ��ȳ�ԭ���ڶ�ͷ��λ��ɾ��]
status deQueue(queue *PQueue,ElemType *pElement);
//��������
void queueTraverse(queue *PQueue);

#endif // MYQUEUEC_H