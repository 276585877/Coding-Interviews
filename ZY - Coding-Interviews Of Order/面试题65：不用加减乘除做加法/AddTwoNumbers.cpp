// ������65�����üӼ��˳����ӷ�
// ��Ŀ��дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�ã�������������
// ����������š�

#include <stdio.h>

int Add(int num1, int num2)
{
	int sum = 0;
	int changenum = 0;

	do
	{
		sum = num1 ^ num2;
		changenum = (num1 & num2) << 1;

		num1 = sum;
		num2 = changenum;
	} while (num2 != 0); // num2 == 0 ��ʾ��û��Ҫ��λ����λ�������ٲ�����λ

	return sum;
}

//====================���Դ���====================
void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d\n", num1, num2, result);
    else
        printf("%d + %d is %d\n", num1, num2, result);
}

int main(int argc, char* argv[])
{
    Test(1, 2, 3);
    Test(111, 899, 1010);

    Test(-1, 2, 1); //-2147483647  -2147483648
    Test(1, -2, -1);

    Test(3, 0, 3);
    Test(0, -4, -4);

    Test(-2, -8, -10);

    return 0;
}

