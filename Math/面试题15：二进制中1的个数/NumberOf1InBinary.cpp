// ������15����������1�ĸ���
// ��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ���������
// ��9��ʾ�ɶ�������1001����2λ��1������������9���ú������2��

#include <stdio.h>

int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		flag <<=  1;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count = 0;
	while (n != 0)
	{
		++count;
		n = n & (n-1);
	}
	return count;
}


// ====================���Դ���====================

int main(int argc, char* argv[])
{
    // ����0���ڴ��������0
    printf("%d  %d\n",NumberOf1_Solution1(0),NumberOf1_Solution2(0));

    // ����1���ڴ��������1
    printf("%d  %d\n",NumberOf1_Solution1(1),NumberOf1_Solution2(1));

    // ����10���ڴ��������2
    printf("%d  %d\n",NumberOf1_Solution1(10),NumberOf1_Solution2(10));

    // ����0x7FFFFFFF���ڴ��������31
    printf("%d  %d\n",NumberOf1_Solution1(0x7FFFFFFF),NumberOf1_Solution2(0x7FFFFFFF));

    // ����0xFFFFFFFF�����������ڴ��������32
    printf("%d  %d\n",NumberOf1_Solution1(0xFFFFFFFF),NumberOf1_Solution2(0xFFFFFFFF));

    // ����0x80000000�����������ڴ��������1
    printf("%d  %d\n",NumberOf1_Solution1(0x80000000),NumberOf1_Solution2(0x80000000));

    return 0;
}


