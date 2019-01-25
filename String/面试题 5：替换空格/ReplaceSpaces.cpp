// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <stdio.h>
#include <string.h>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
void ReplaceBlank(char str[], int length)
{
	if (str == NULL || length <= 0)
	{
		return;
	}

	// ����ո񳤶�,�ַ�������
	int blanklen = 0;
	int oldlen = 0;
	char *p = str;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			blanklen++;
		}
		p++;
		oldlen++;
	}

	int newlen = oldlen + blanklen * 2;
	if (newlen > length)
	{
		return;
	}
	int lenstr  = oldlen;

	while (lenstr >= 0)
	{
		if (str[lenstr] == ' ')
		{
			str[newlen--] = '0';
			str[newlen--] = '2';
			str[newlen--] = '%';
		}
		else
		{
			str[newlen--] = str[lenstr];
		}
		lenstr--;
	}
}


// ====================���Դ���====================
// �ո��ھ����м�
void Test1()
{
    const int length = 100;
    char str[length] = "hello world";
	ReplaceBlank(str,length);
	printf("%s\n",str);
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;
    char str[length] = " helloworld";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;
    char str[length] = "helloworld ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// �����������ո�
void Test4()
{
    const int length = 100;
    char str[length] = "hello  world";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// ����nullptr
void Test5()
{
	char *str = NULL;
	ReplaceBlank(str,0);
	printf("%s\n",str);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;
    char str[length] = "";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;
    char str[length] = " ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;
    char str[length] = "helloworld";
    ReplaceBlank(str,length);
	printf("%s\n",str);
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;
    char str[length] = "   ";
    ReplaceBlank(str,length);
	printf("%s\n",str);
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

    return 0;
}