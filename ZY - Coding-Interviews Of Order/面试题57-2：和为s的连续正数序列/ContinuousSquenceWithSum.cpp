// ������57��������Ϊs��������������
// ��Ŀ������һ������s����ӡ�����к�Ϊs�������������У����ٺ�������������
// ��������15������1+2+3+4+5=4+5+6=7+8=15�����Խ����ӡ��3����������1��5��
// 4��6��7��8��

#include <stdio.h>

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
	//if (sum < 3)   // sum < 3 û��������������
	//{
	//	return;
	//}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) >> 1;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small,big);
		}
		
		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small,big);
			}
		}
		big++;
		curSum += big;
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; i++)
	{
		printf("%d ",i);
	}
	printf("\n");
}


// ====================���Դ���====================
void Test(int sum)
{
	printf("sum==%d\nBegin:\n",sum);
    FindContinuousSequence(sum);
	printf("END\n\n");
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(3);
    Test(4);
    Test(9);
    Test(15);
    Test(100);

    return 0;
}
