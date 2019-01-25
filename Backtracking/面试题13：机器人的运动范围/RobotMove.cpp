// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

/*

	��������12���ƣ��ɽ����񿴳�һ�� m * n �ľ���ͬ�������߽�����⣬ÿ�����Ӷ����ĸ����ڵĸ���
	�㷨˼��ʹ�û��ݷ���movingCountΪ��ʼ��������movingCountCoreΪ�����ܵ���ĸ��Ӹ����ĺ���
	check���������жϻ������ܷ��������Ϊ��row��col���ķ��񣬶�����getDigitSum�����õ�һ�����ֵ�λ��֮��

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);

int movingCount(int threshold, int rows, int cols)
{
	if (threshold < 0 || rows <= 0 || cols <= 0)
	{
		return 0;
	}
	bool *visited = (bool *)malloc(sizeof(bool) * (rows * cols));
	memset(visited,false,rows * cols);

	int count = movingCountCore(threshold,rows,cols,0,0,visited);
	
	free(visited);
	return count;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold,rows,cols,row,col,visited))
	{
		visited[row * cols + col] = true;
		count = 1 + movingCountCore(threshold,rows,cols,row - 1,col,visited)+\
					movingCountCore(threshold,rows,cols,row,col - 1,visited)+\
					movingCountCore(threshold,rows,cols,row + 1,col,visited)+\
					movingCountCore(threshold,rows,cols,row,col + 1,visited);
	}
	return count;
}


bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && col >= 0 && row < rows && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
	{
		return true;
	}
	return false;
}

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}



// ====================���Դ���====================


// ������ж���
void test1()
{
    printf("%d\n",movingCount(5, 10, 10));  // 21
}

// ������ж���
void test2()
{
    printf("%d\n",movingCount(15, 20, 20)); // 359
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    printf("%d\n",movingCount(10, 1, 100));	// 29
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    printf("%d\n",movingCount(10, 1, 10)); // 10
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    printf("%d\n",movingCount(15, 100, 1));  // 79
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    printf("%d\n",movingCount(15, 10, 1));  // 10
}

// ����ֻ��һ��һ��
void test7()
{
    printf("%d\n",movingCount(15, 1, 1));  // 1
}

// ����ֻ��һ��һ��
void test8()
{
    printf("%d\n",movingCount(0, 1, 1));  // 1
}

// �����˲��ܽ�������һ������
void test9()
{
    printf("%d\n",movingCount(-10, 10, 10));  // 0
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

    return 0;
}
