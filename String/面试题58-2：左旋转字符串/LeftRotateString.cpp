// ������58������������ת�ַ���
// ��Ŀ���ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
// �붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����������ַ���"abcdefg"����
// ��2���ú�������������ת2λ�õ��Ľ��"cdefgab"��

#include <stdio.h>
#include <string.h>


void Reverse(char *pBegin,char *pEnd)
{
	if (pBegin == NULL || pEnd == NULL)
	{
		return;
	}

	while (pBegin < pEnd)
	{
		char tmp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = tmp;
		pBegin++;
		pEnd--;
	}
}

char* LeftRotateString(char* pStr, int n)
{
	if (pStr == NULL)
	{
		return NULL;
	}

	int length = strlen(pStr);

	if (n < 0 || n > length)
	{
		return NULL;
	}

	char *firstBegin = pStr;
	char *firstEnd = pStr + n - 1;
	char *secondBegin = firstEnd + 1;
	char *secondEnd = pStr + length - 1;

	Reverse(firstBegin,firstEnd);	// ��ת�ַ�����ǰ�벿��
	Reverse(secondBegin,secondEnd);  // ��ת�ַ����ĺ�벿��
	Reverse(firstBegin,secondEnd);  // ��ת�����ַ���
	return pStr;
}



// ====================���Դ���====================

// ���ܲ���
void Test1()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,2);
	printf("%s\n",expected);	// "cdefgab"
}

// �߽�ֵ����
void Test2()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,1);
	printf("%s\n",expected);	// "bcdefga"
}

// �߽�ֵ����
void Test3()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,6);
	printf("%s\n",expected);	// "gabcdef"
	
}

// ³���Բ���
void Test4()
{
	char *input = NULL;
	char *expected = LeftRotateString(input,6);
	printf("%s\n",expected);	// null
}

// ³���Բ���
void Test5()
{
    char input[] = "abcdefg";
    char *expected = LeftRotateString(input,0);
	printf("%s\n",expected);	// "abcdefg"
}

// ³���Բ���
void Test6()
{
    char input[] = "abcdefg";
	char *expected = LeftRotateString(input,7);
	printf("%s\n",expected);	// "abcdefg"

}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
