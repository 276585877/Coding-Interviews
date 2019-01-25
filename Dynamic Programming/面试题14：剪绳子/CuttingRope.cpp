// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��

#include<stdio.h>
#include<stdlib.h>

// ====================��̬�滮====================
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}
	int *result = (int *)malloc(sizeof(int) * (length+1));
	//result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	result[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i/2; j++)
		{
			int res = result[j] * result[i-j];
			if (max < res)
			{
				max = res;
			}
			result[i] = max;
		}
	}
	max = result[length];
	free(result);
	return max;
}


// ====================���Դ���====================

void test1()
{
    int length = 1;
	printf("%d\n",maxProductAfterCutting_solution1(length));  // 0
}

void test2()
{
    int length = 2;
    printf("%d\n",maxProductAfterCutting_solution1(length)); // 1
}

void test3()
{
    int length = 3;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 2
}

void test4()
{
    int length = 4;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 4
}

void test5()
{
    int length = 5;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 6
}

void test6()
{
    int length = 6;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 9
}

void test7()
{
    int length = 7;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 12
}

void test8()
{
    int length = 8;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 18
}

void test9()
{
    int length = 9;
    printf("%d\n",maxProductAfterCutting_solution1(length));   // 27
}

void test10()
{
    int length = 10;
    printf("%d\n",maxProductAfterCutting_solution1(length));   // 36
}

void test11()
{
    int length = 50;
    printf("%d\n",maxProductAfterCutting_solution1(length));  // 86093442
}

int main(int agrc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();

    return 0;
}