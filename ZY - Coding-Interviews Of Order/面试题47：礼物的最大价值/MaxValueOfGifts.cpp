// ������47�����������ֵ
// ��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
// ����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ�
// �������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
// ����������õ����ټ�ֵ�����

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Max(int digit1,int digit2)
{
	int max = digit1 > digit2 ? digit1 : digit2;
	return max;
}


int getMaxValue_solution1(const int* values, int rows, int cols)
{
	if (values == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	int **maxValues = (int **)malloc(sizeof(int *) * rows);
	for (int i = 0; i < rows; i++)
	{
		maxValues[i] = (int *)malloc(sizeof(int) * cols);
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//��ǰ�����������һ���ܹ�ȡ�õ����ֵ����ʼ��Ϊ0
			int left = 0;
			int up = 0;

			if (i > 0)
			{
				//������ǵ�һ�У���ô����ȡ������һ������ֵ
				up = maxValues[i-1][j];
			}
			if (j > 0)
			{
				//������ǵ�һ�У�����ȡ�����һ������ֵ
				left = maxValues[i][j-1];
			}

			//�õ���ǰ���ܹ�ȡ�������ֵ   
			maxValues[i][j] = Max(up,left) + values[i * cols + j];
		}
	}

	int maxValue = maxValues[rows - 1][cols - 1];

	for (int i = 0; i < rows; i++)
	{
		free(maxValues[i]);
	}
	free(maxValues);

	return maxValue;
}


int getMaxValue_solution2(const int* values, int rows, int cols)
{
	if (values == NULL || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	//ֻ��һ�л�����������һ�е����ֵ
	int *maxValues = (int *)malloc(sizeof(int) * cols);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int left = 0;
			int up = 0;

			if (i > 0)
			{
				//ȡ����һ������ֵ
				up = maxValues[j];
			}
			if (j > 0)
			{
				//��Ϊ���һ������ֵ�ἰʱ���µ����棬��������ȡ�������һ�������  
				left = maxValues[j - 1];
			}

			//�Ե�ǰ�е�����ʵʱ���µ�����
			maxValues[j] = Max(left,up) + values[i * cols + j];
		}
	}
	int maxValue = maxValues[cols - 1];
	free(maxValues);
	return maxValue;
}

// ====================���Դ���====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{
    if(getMaxValue_solution1(values, rows, cols) == expected)
		printf("%s: solution1 passed.\n",testName);
    else
        printf("%s: solution1 FAILED.\n",testName);


    if(getMaxValue_solution2(values, rows, cols) == expected)
        printf("%s: solution2 passed.\n",testName);
    else
        printf("%s: solution2 FAILED.\n",testName);
}

void test1()
{
    // ��������
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //��������
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // һ������
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // һ��һ��
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // ��ָ��
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
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
