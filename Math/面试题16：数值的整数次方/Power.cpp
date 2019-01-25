// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣


/*
	˼·�����ڲ���Ҫ���۴������⣬������Ϊ���ף�������Ҫ���ǵ�ϸ�ڽ϶࣬�ֱ��������ָ��
	С��1��������Ϊ0������ָ��Ϊ����ʱ�������ȶ�ָ�������ֵ��������η�����ȡ���������ǹ涨
	������baseΪ0��ָ���Ǹ���ʱ������ֱ�ӷ���0�Ϳ��ԣ������0������
*/
#include <stdio.h>

bool g_InvalidInput = false;
bool equal(double num1, double num2);
double PowerWithUnsignedExponent(double base, unsigned int exponent);

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.000000;
	}
	unsigned int absExponent = (unsigned int)(exponent);

	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double result = PowerWithUnsignedExponent(base,absExponent);
	if (exponent < 0)
	{
		result = 1.0/result;
	}
	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1.0;
	}
	if (exponent == 1)
	{
		return base;
	}
	double result = PowerWithUnsignedExponent(base,exponent >> 1);
	result *= result;

	if ((exponent & 0x1) == 1)  // ˵��ָ��Ϊ����
	{
		result *= base;
	}
	return result;
}

#if 0
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result = 1.0;
	for (int i = 0; i <= exponent; i++)
	{
		result *= result;
	}
	return result 
}
#endif

bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
	{
		return true;
	}
	return false;
}


 //====================���Դ���====================

int main()
{
     //������ָ����Ϊ����
	printf("%lf\n",Power(2,3));  // 8
    // ����Ϊ������ָ��Ϊ����
    printf("%lf\n",Power(-2,3));  // -8

	// ָ��Ϊ����
	printf("%lf\n",Power(2,-3));  // 0.125

	// ָ��Ϊ0
	printf("%lf\n",Power(2,0));  // 1
  
	// ������ָ����Ϊ0
	printf("%lf\n",Power(0,0));  // 1
  
	// ����Ϊ0��ָ��Ϊ����
	printf("%lf\n",Power(0,4));  // 0
   
	// ����Ϊ0��ָ��Ϊ����
	printf("%lf\n",Power(0,-1));  // 0
    return 0;
}