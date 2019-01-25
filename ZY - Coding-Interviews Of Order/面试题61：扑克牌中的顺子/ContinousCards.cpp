// ������61���˿��Ƶ�˳��
// ��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����5�����ǲ��������ġ�
// 2��10Ϊ���ֱ���AΪ1��JΪ11��QΪ12��KΪ13������С�����Կ����������֡�

#include <stdio.h>
#include <stdlib.h>

int Compare(const void *arg1, const void *arg2);

bool IsContinuous(int* numbers, int length)
{
	if (numbers == NULL || length < 1)
	{
		return false;
	}

	qsort(numbers,length,sizeof(int),Compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	// ͳ��������0�ĸ���
	for (int i = 0; i < length && numbers[i] == 0; i++)
	{
		numberOfZero++;
	}

	// ͳ�������еļ����Ŀ
	int small = numberOfZero;   // ���������Ѿ������� ��numberOfZero��λ�õ�Ԫ��Ϊ��һ����Ϊ0��Ԫ��
	int big = small + 1;
	while (big < length)
	{
		if (numbers[small] == numbers[big])
		{
			return false;  // �ж��ӣ���������˳��
		}
		numberOfGap += numbers[big] - numbers[small] - 1;
		small = big;
		big++;
	}
	return (numberOfGap > numberOfZero) ? false : true;
}

int Compare(const void *arg1, const void *arg2)
{
	return *(int *)arg1 - *(int *)arg2;
}



// ====================���Դ���====================
void Test(int* numbers, int length)
{
    if (IsContinuous(numbers,length))
	{
		printf("Is Continuous\n");
	}
	else
	{
		printf("Isn't Continuous\n");
	}

}

void Test1()
{
    int numbers[] = { 1, 3, 2, 5, 4 };
	int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test2()
{
    int numbers[] = { 1, 3, 2, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test3()
{
    int numbers[] = { 0, 3, 2, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test4()
{
    int numbers[] = { 0, 3, 1, 6, 4 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test5()
{
    int numbers[] = { 1, 3, 0, 5, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test6()
{
    int numbers[] = { 1, 3, 0, 7, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test7()
{
    int numbers[] = { 1, 0, 0, 5, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test8()
{
    int numbers[] = { 1, 0, 0, 7, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

void Test9()
{
    int numbers[] = { 3, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

void Test10()
{
    int numbers[] = { 0, 0, 0, 0, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // true
}

// �ж���
void Test11()
{
    int numbers[] = { 1, 0, 0, 1, 0 };
    int length = sizeof(numbers)/sizeof(numbers[0]);
	Test(numbers,length);  // false
}

// ³���Բ���
void Test12()
{
	int *numbers = NULL;
    int length = 0;
	Test(numbers,length);  // false
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
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}

