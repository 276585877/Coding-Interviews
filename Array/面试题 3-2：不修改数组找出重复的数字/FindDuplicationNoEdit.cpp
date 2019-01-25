// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

#include<stdio.h>

int countRange(const int* numbers, int length, int start, int end);

int getDuplication(const int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		return -1;
	}

	int start = 1;
	int end = length - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(numbers,length,start,middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}

		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
	if (numbers == NULL)
	{
		return 0;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= start && numbers[i] <= end)
		{
			++count;
		}
	}
	return count;
}



// ====================���Դ���====================

// ����ظ�������
void test1()
{
    int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// һ���ظ�������
void test2()
{
    int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// �ظ�����������������С������
void test3()
{
    int numbers[] =  { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// �ظ�����������������������
void test4()
{
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// ������ֻ����������
void test5()
{
    int numbers[] = { 1, 1 };;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// �ظ�������λ�����鵱��
void test6()
{
    int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// ����ظ�������
void test7()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// һ�������ظ�����
void test8()
{
    int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// û���ظ�������
void test9()
{
    int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}

// ��Ч������
void test10()
{
    int* numbers = nullptr;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int result = getDuplication(numbers,length);
	if (result == -1)
	{
		printf("Not Exist!\n");
	}
	else
	{
		printf("Exist!The duplicate number is %d\n",result);
	}
}
void main()
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
}