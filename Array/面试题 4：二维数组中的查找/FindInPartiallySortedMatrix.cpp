// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������

#include <stdio.h>

bool Find(int* matrix, int rows, int columns, int number)
{
	if (matrix == NULL)
	{
		return false;
	}
	
	int row  = 0;
	int column = columns - 1;
	while (row < rows && column < columns)
	{
		if (matrix[row * columns + column] == number)
		{
			return true;
		}
		else
		{
			if (number < matrix[row * columns + column])
			{
				column--;	// Ҫ���ҵ����ֱ����Ͻǵ�����С��������
			}
			else
			{
				row++;		// Ҫ���ҵ����ֱ����Ͻǵ����ִ�������
			}
		}
	}
	return false;
}

// ====================���Դ���====================

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	if (Find((int*)matrix,4,4,7))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,5))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,1))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,15))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,0))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    if (Find((int*)matrix,4,4,16))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

// ³���Բ��ԣ������ָ��
void Test7()
{
	int *matrix = NULL;
    if (Find(matrix,0,0,16))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}