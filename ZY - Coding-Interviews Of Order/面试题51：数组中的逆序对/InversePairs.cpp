// ������51�������е������
// ��Ŀ���������е������������ǰ��һ�����ִ��ں�������֣���������������
// ��һ������ԡ�����һ�����飬�����������е�����Ե�������


/*
		˼·��
		�鲢����ĺϲ����̡���Ҫ�ǿ��Ǻϲ�������������ʱ���������������
		���������������У����������±꣺�����������е�ĩβ��ÿ�αȽ�����ĩβֵ�����ǰĩβ���ں�ĩβֵ�����С������е�ǰ���ȡ�������ԣ�
		���򲻹�������ԡ�Ȼ��ѽϴ�ֵ���������������ĩβ��������Ҫ�������������кϲ����������鲢����
		������ÿ���ںϲ�ǰ���ȵݹ�ش������Ρ��Ұ�Σ������Ұ�����������Ұ�ε���������ɵõ����ټ������Ұ�κϲ�ʱ����Եĸ�����
		�ܸ���=�����+�Ҹ���+���Һϲ�ʱ�ĸ���
		ע�⣺
		ע��InversePairsCore�βε�˳����(data,copy)�����ݹ����ʱʵ����(copy,data)��
		Ҫ���׵ݹ麯��InversePairsCore�����þ����ˣ����Ƕ�data�����Ұ�ν��кϲ������Ƶ���������copy������
		���data��copy�������鶼������ġ�
*/
#include <stdio.h>
#include <stdlib.h>

int InversePairsCore(int* data, int* copy, int start, int end);

int InversePairs(int* data, int length)
{
	if (data == NULL || length < 0)
	{
		return 0;
	}
	int *copy = (int *)malloc(sizeof(int) * length);
	
	for (int i = 0; i < length; i++)
	{
		copy[i] = data[i];
	}
	int count = InversePairsCore(data,copy,0,length - 1);
	free(copy);
	return count;
}

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) >> 1;

	int left = InversePairsCore(copy,data,start,start + length);
	int right = InversePairsCore(copy,data,start + length + 1,end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;

	while (i >= start && j >= start + length + 1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; i--)
	{
		copy[indexCopy--] = data[i];
	}

	for (; j >= start + length + 1; j--)
	{
		copy[indexCopy--] = data[j];
	}
	return left + right + count;
}


// ====================���Դ���====================
void Test(char* testName, int* data, int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(InversePairs(data, length) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// �ݼ���������
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// ������������
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ��һ������
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// ������ֻ���������֣���������
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// ������ֻ���������֣��ݼ�����
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// ����������ȵ�����
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
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

    return 0;
}