// ������49������
// ��Ŀ�����ǰ�ֻ��������2��3��5��������������Ugly Number�����󰴴�С��
// ���˳��ĵ�1500������������6��8���ǳ�������14���ǣ���Ϊ����������7��
// ϰ�������ǰ�1������һ��������

#include <stdio.h>
#include <stdlib.h>

// ====================Solution1��ֱ�۵�������Ч====================
bool IsUgly(int number)
{
	while (number % 2 == 0)
	{
		number /= 2;
	}
	while (number % 3 == 0)
	{
		number /= 3;
	}
	while (number % 5 == 0)
	{
		number /= 5;
	}

	return (number == 1) ? true : false;
}

int GetUglyNumber_Solution1(int index)
{
	if (index <= 0)
	{
		return 0;
	}
	
	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;
		if (IsUgly(number))
		{
			++uglyFound;
		}
	}
	return number;
}

// ====================Solution2���Կռ任ʱ��====================
int Min(int number1, int number2, int number3);

int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int *pUglyNumbers = (int *)malloc(sizeof(int) * index);
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultipy2 = pUglyNumbers;
	int *pMultipy3 = pUglyNumbers;
	int *pMultipy5 = pUglyNumbers;
	
	while (nextUglyIndex < index)
	{
		int min = Min(*(pMultipy2) * 2 , *(pMultipy3) * 3 , *(pMultipy5) * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pMultipy2 * 2 <= pUglyNumbers[nextUglyIndex])
		{
			pMultipy2++;
		}
		while (*pMultipy3 * 3 <= pUglyNumbers[nextUglyIndex])
		{
			pMultipy3++;
		}
		while (*pMultipy5 * 5 <= pUglyNumbers[nextUglyIndex])
		{
			pMultipy5++;
		}

		nextUglyIndex++;
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	free(pUglyNumbers);
	return ugly;
}

int Min(int number1, int number2, int number3)
{
	int min = (number1 > number2) ? number2 : number1;
	min = (min > number3) ? number3 : min;
	return min;
}



// ====================���Դ���====================


int main(int argc, char* argv[])
{
	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(1));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(1));	// 1

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(2));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(2));	// 2

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(3));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(3));	// 3

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(4));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(4));	// 4
   
	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(5));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(5));	// 5

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(6));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(6));	// 6

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(7));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(7));	// 8

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(8));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(8));	// 9

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(9));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(9));	// 10

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(10));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(10));	// 12

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(11));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(11));	// 15

	//printf("solution1 ===> %d\n",GetUglyNumber_Solution1(1500));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(1500));	// 859963392

	printf("solution1 ===> %d\n",GetUglyNumber_Solution1(0));
	printf("solution2 ===> %d\n\n",GetUglyNumber_Solution2(0));	// 0

    return 0;
}
