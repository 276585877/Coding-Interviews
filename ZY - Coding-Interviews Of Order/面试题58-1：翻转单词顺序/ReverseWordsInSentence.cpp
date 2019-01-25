// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

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

char* ReverseSentence(char *pData)
{
	if (pData == NULL)
	{
		return NULL;
	}
	
	char *pBegin = pData;
	char *pEnd = pData;
	while (*pEnd != '\0')
	{
		pEnd++;
	}

	pEnd--;

	Reverse(pBegin,pEnd);  // ��ת��������

	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin,--pEnd); // ��תÿ������
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}



// ====================���Դ���====================

// ���ܲ��ԣ��������ж������
void Test1()
{
    char input[] = "I am a student.";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"student. a am I";
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
    char input[] = "Wonderful";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"Wonderful";
}

// ³���Բ���
void Test3()
{
    char *input = NULL;
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"";
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
    char input[] = "";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"";
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
    char input[] = "   ";
	char *expected = ReverseSentence(input);
	printf("%s\n",expected);		//"    ";
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}