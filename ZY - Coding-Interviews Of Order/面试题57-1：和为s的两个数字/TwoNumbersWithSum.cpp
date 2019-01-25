// ������57��һ������Ϊs����������
// ��Ŀ������һ����������������һ������s���������в�����������ʹ������
// �ĺ�������s������ж�����ֵĺ͵���s���������һ�Լ��ɡ�

#include <stdio.h>

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool result = false;
	if (data == NULL || length <= 0 || num1 == NULL || num2 == NULL)
	{
		return result;
	}

	int start = 0;
	int end = length - 1;
	
	while (start < end)
	{
		long long curSum = data[start] + data[end];
		if (curSum == sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			result = true;
			break;
		}
		else if (curSum < sum)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	return result;
}



// ====================���Դ���====================

void Test(int *data,int length,int sum)
{
	int num1 = 0;
	int num2 = 0;
	if (FindNumbersWithSum(data,length,sum,&num1,&num2))
	{
		printf("%d,%d\n",num1,num2);
	}
	else
	{
		printf("NULL\n");
	}
}


// ���ں�Ϊs���������֣�����������λ��������м�
void Test1()
{
    int data[] = {1, 2, 4, 7, 11, 15};
	int length = sizeof(data)/sizeof(data[0]);
	int sum = 15;
	Test(data,length,sum);
}

// ���ں�Ϊs���������֣�����������λ�����������
void Test2()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    int length = sizeof(data)/sizeof(data[0]);
	int sum = 17;
	Test(data,length,sum);
}

// �����ں�Ϊs����������
void Test3()
{
    int data[] = {1, 2, 4, 7, 11, 16};
    int length = sizeof(data)/sizeof(data[0]);
	int sum = 10;
	Test(data,length,sum);
}

// ³���Բ���
void Test4()
{
	int *data = NULL;
    int length = 0;
	int sum = 0;
	Test(data,length,sum);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}