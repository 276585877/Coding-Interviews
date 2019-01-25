// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�


#include<stdio.h>
// ====================����1���ݹ�====================
long long Fibonacci_Solution1(unsigned int n)
{	if (n <= 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return Fibonacci_Solution1(n-1)  +  Fibonacci_Solution1(n-2);
}

// ====================����2��ѭ��====================
long long Fibonacci_Solution2(unsigned n)
{
	int result[2] = {0,1};
	if (n < 2)
	{
		return result[n];
	}

	long long firstnum = result[0];
	long long secondnum = result[1];
	long long thirdnum = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		thirdnum = firstnum + secondnum;
		firstnum = secondnum;
		secondnum = thirdnum;
	}
	return thirdnum;
}


// ====================���Դ���====================

int main(int argc, char* argv[])
{
	printf("%d\n",Fibonacci_Solution1(0));
	printf("%d\n",Fibonacci_Solution1(1));
	printf("%d\n",Fibonacci_Solution1(3));
	printf("%d\n",Fibonacci_Solution1(5));
	printf("%d\n",Fibonacci_Solution1(10));

	printf("%d\n",Fibonacci_Solution2(0));
	printf("%d\n",Fibonacci_Solution2(1));
	printf("%d\n",Fibonacci_Solution2(3));
	printf("%d\n",Fibonacci_Solution2(5));
	printf("%d\n",Fibonacci_Solution2(10));

	/*printf("%d\n",Fibonacci_Solution1(40));
	printf("%d\n",Fibonacci_Solution1(50));
	printf("%d\n",Fibonacci_Solution1(100));*/

	printf("%d\n",Fibonacci_Solution2(40));
	printf("%d\n",Fibonacci_Solution2(50));
	printf("%d\n",Fibonacci_Solution2(100));
	
    return 0;
}