// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

#include<stdio.h>

int MinInOrder(int* numbers, int index1, int index2);

int Min(int* numbers, int length)
{
	if (numbers == NULL || length < 0)
	{
		return -1;
	}
	
	int index1 = 0;
	int index2 = length - 1;
	int middle = index1;  //  ��ֹ������ǰ0����ת������
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			return numbers[index2];
			break;
		}

		middle = (index1 + index2) / 2;

		if (numbers[index1] == numbers[index2] && numbers[middle] == numbers[index1])
		{
			return MinInOrder(numbers,index1,index2);
		}

		if (numbers[middle] >= numbers[index1])
		{
			index1 = middle;
		}
		else
		{
			index2 = middle;
		}
	}
	return numbers[index1];  // �����ת0��Ԫ�أ�numbers[index1] < numbers[index2],��һ����Ϊ��С�ģ������һ��numbers[index1]
}
int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (numbers[i] < result)
		{
			result = numbers[i];
		}
	}
	return result;
}



// ====================���Դ���====================

int main(int argc, char* argv[])
{
    // �������룬��������������һ����ת
    int array1[] = { 3, 4, 5, 1, 2 };
	int length = sizeof(array1)/sizeof(array1[0]);
	printf("%d\n",Min(array1,length));

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    length = sizeof(array2)/sizeof(array2[0]);
	printf("%d\n",Min(array2,length));

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    length = sizeof(array3)/sizeof(array3[0]);
	printf("%d\n",Min(array3,length));

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    length = sizeof(array4)/sizeof(array4[0]);
	printf("%d\n",Min(array4,length));

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    length = sizeof(array5)/sizeof(array5[0]);
	printf("%d\n",Min(array5,length));

    // ������ֻ��һ������
    int array6[] = { 2 };
    length = sizeof(array6)/sizeof(array6[0]);
	printf("%d\n",Min(array6,length));

    // ����nullptr
	int *array7 =NULL;
    length = 0;
	printf("%d\n",Min(array7,length));

    return 0;
}
