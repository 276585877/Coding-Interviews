// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��



#include <stdio.h>

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������

bool duplicate(int numbers[], int length, int *duplication)
{
	if (numbers == NULL || length <= 0)
	{
		return false;
	}
	
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] > length-1)
		{
			return false;
		}
	}

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;
}



// ====================���Դ���====================

// �ظ�����������������С������
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// �ظ�����������������������
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications = 0;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}

}

// �����д��ڶ���ظ�������
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// û���ظ�������
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// ��Ч������- ��ָ��
void test5()
{
    int* numbers = NULL;
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
	}
}

// ��Ч������ - ����Ϊn���������0~n-1֮�������
void test6()
{
    int numbers[] = { 2, 1, 3, 9, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	int duplications = 0;
	if (duplicate(numbers,length,&duplications))
	{
		printf("Exist!The duplicate number is %d\n",duplications);
	}
	else
	{
		printf("Not Exist!\n");
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
}