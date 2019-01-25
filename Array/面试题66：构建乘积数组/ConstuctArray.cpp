// ������66�������˻�����
// ��Ŀ������һ������A[0, 1, ��, n-1]���빹��һ������B[0, 1, ��, n-1]����
// ��B�е�Ԫ��B[i] =A[0]��A[1]���� ��A[i-1]��A[i+1]������A[n-1]������ʹ�ó�����

#include <stdio.h>

void BuildProductionArray(const int *arrayA, int ALength, int *arrayB)
{
	if (arrayA == NULL || ALength <= 0)
	{
		return;
	}
	arrayB[0] = 1;
	for (int i = 1; i < ALength; i++)
	{
		arrayB[i] = arrayB[i - 1] * arrayA[i - 1];   // ������
	}
	int temp = 1;
	for (int i = ALength - 2; i >= 0; i--)
	{
		temp *= arrayA[i + 1];
		arrayB[i] *= temp;        // ������
	}
}


//================= �������� =================

void test(const int *arrayA, int ALength, int *arrayB)
{
	BuildProductionArray(arrayA,ALength,arrayB);
	for (int i = 0; i < ALength; i++)
	{
		printf("%d ",arrayB[i]);
	}
	printf("\n");
}

void test1()
{
    // ����������û��0
    int input[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 120, 60, 40, 30, 24 }
}

static void test2()
{
    // ������������һ��0
    int input[] = { 1, 2, 0, 4, 5 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 0, 0, 40, 0, 0 }
    
}

static void test3()
{
    // ����������������0
    int input[] = { 1, 2, 0, 4, 0 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 0, 0, 0, 0, 0 }
}

static void test4()
{
    // ��������������������
    int input[] = { 1, -2, 3, -4, 5 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { 120, -60, 40, -30, 24 }
}

static void test5()
{
    // ����������ֻ����������
    int input[] = { 1, -2 };
    int length = sizeof(input)/sizeof(input[0]);
	int expected[] = { 0, 0, 0, 0, 0 };
	test(input,length,expected);	// { -2, 1 }
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
