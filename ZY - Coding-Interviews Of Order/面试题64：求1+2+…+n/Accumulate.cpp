// ������64����1+2+��+n
// ��Ŀ����1+2+��+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
// �ȹؼ��ּ������ж���䣨A?B:C����

//===========����һ��ʹ�� && �Ķ�·����==========
#include <stdio.h>

int add(int n, int *sum)
{
	n && add(n - 1, sum);
	return (*sum += n);
}

#if 0
int main()
{
	int sum  = 0;
	int n = 100;
	printf("%d\n",add(n,&sum));
}
#endif

//===========��������ʹ�ú���ָ�� ==========
typedef unsigned int(*fun)(unsigned int);
unsigned int Teminator(unsigned int n)
{
	return 0;  // �ݹ����������0ֵ
}

unsigned int Sum(unsigned int n)
{
	static fun f[2] = {Teminator, Sum};
	return n + f[!!n](n - 1);  // n����ʱ��!!nΪ 1 ,����Sum���еݹ����㣻nΪ��ʱ���ݹ������!!nΪ 0������Teminator�����ݹ�
}


// ====================���Դ���====================
void Test(const unsigned int n)
{
	printf("%d\n",Sum(n));
}

void Test1()
{
    const unsigned int number = 1;
    Test(number);  //	1 
}

void Test2()
{
    const unsigned int number = 5;
    Test(number);	// 15

}

void Test3()
{
    const unsigned int number = 10;
    Test(number);  // 55
}

void Test4()
{
    const unsigned int number = 0;
    Test(number);  // 0
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}