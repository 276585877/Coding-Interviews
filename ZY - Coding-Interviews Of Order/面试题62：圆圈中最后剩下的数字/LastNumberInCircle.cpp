// ������62��ԲȦ�����ʣ�µ�����
// ��Ŀ��0, 1, ��, n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ����ԲȦ��
// ɾ����m�����֡�������ԲȦ��ʣ�µ����һ�����֡�

//===================Լɪ������===========================================
#if 0
int LastRemaining_Solution1(unsigned int n, unsigned int m, unsigned int k)
{
	if (n == 0 || m == 0)
	{
		return -1;
	}
	CTlist numbers;
	InitList(&numbers);
	for (unsigned int i = 1; i <= n; i++)
	{
		Insert_tail(&numbers,i);
	}

	int result = 0;
	for (int i = 1; i < k; i++)
	{
		numbers = numbers->next;
	}
	while (GetLength(&numbers) > 1)
	{
		for (unsigned int i = 1; i < m; i++)
		{
			numbers = numbers->next;
		}
		result = numbers->next->data;   // ���� ɾ��������һ��Ԫ�أ���Ϊ�������� ʣ������һ���ڵ�
		printf("%d ",numbers->data);
		Delete(&numbers,numbers->data);  // ɾ��mλ�õ�Ԫ��
	}
	return result;
}
int main()
{
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,4,2));  // 2
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,4,1)); // 1
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,1,4)); // 3
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(9,1,1)); // 9
	printf("\tThe RESULT IS %d\n",LastRemaining_Solution1(41,3,1)); // 9
}

#endif

#include <stdio.h>
#include "CricleList.h"

// ====================����1��ʹ�û�������ģ��====================
int LastRemaining_Solution1(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	CTlist numbers;
	InitList(&numbers);
	for (unsigned int i = 0; i < n; i++)
	{
		Insert_tail(&numbers,i);
	}

	int result = 0;
	while (GetLength(&numbers) > 1)
	{
		for (unsigned int i = 1; i < m; i++)
		{
			numbers = numbers->next;
		}
		result = numbers->next->data;   // ���� ɾ��������һ��Ԫ�أ���Ϊ�������� ʣ������һ���ڵ�
		Delete(&numbers,numbers->data);  // ɾ��mλ�õ�Ԫ��
	}
	return result;
}


// ====================����2====================
int LastRemaining_Solution2(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}

	int DelElem = 0;
	for (int i = 2; i <= n; i++)
	{
		DelElem = (DelElem + m) %  i;
		//printf("%d ",DelElem);
	}
	return DelElem;
}

// ====================��������===============================
void Test(unsigned int m,unsigned int n)
{
	printf("Solution1:%d\n",LastRemaining_Solution1(m,n));
	printf("Solution2:%d\n\n",LastRemaining_Solution2(m,n));
}

int main()
{
	Test(5,3); // 3
	Test(5,2); // 2
	Test(6,7); // 4
	Test(6,6); // 3
	Test(0,0); // -1
	Test(4000,997); // 1027
}

