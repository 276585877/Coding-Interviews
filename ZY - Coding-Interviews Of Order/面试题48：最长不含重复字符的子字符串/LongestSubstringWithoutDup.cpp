// ������48��������ظ��ַ������ַ���
// ��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
// �ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int longestSubstringWithoutDuplication(const char *str)
{
	int curLength = 0;
	int maxLength = 0;

	int *position = (int *)malloc(sizeof(int) * 26);
	for (int i = 0; i < 26; i++)
	{
		position[i] = -1;
	}

	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int prevIndex = position[str[i] - 'a'];
		if (prevIndex < 0 || i - prevIndex > curLength)
		{
			curLength++;
		}
		else
		{
			if (curLength > maxLength)
			{
				maxLength = curLength;
			}
			curLength = i - prevIndex;
		}
		position[str[i] - 'a'] = i;
	}

	if (curLength > maxLength)
	{
		maxLength = curLength;
	}
	free(position);
	return maxLength;
}


// ====================���Դ���====================

void test(const char *input, int expected)
{
    int output = longestSubstringWithoutDuplication(input);
    if(output == expected)
		printf("passed, with input: %s\n",input);
    else
		printf("FAILED, with input: %s\n",input);
}

void test1()
{
    const char *input = "abcacfrar";  // cfra
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const char *input = "acfrarabc";  // rabc
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const char *input = "arabcacfr";   // acfr
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const char *input = "aaaa";   // a
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const char *input = "abcdefg";  // abcdefg
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const char *input = "aaabbbccc";  // bc
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const char *input = "abcdcba";  // dcba
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const char *input = "abcdaef";   // bcdaef
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const char *input = "a";  // a
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const char *input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}
