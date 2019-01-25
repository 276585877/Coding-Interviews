// ������45���������ų���С����
// ��Ŀ������һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ
// �ӳ���������������С��һ����������������{3, 32, 321}�����ӡ����3����
// �����ųɵ���С����321323��

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* strNumber1, const void* strNumber2);

// int��������ʮ���Ʊ�ʾ���ֻ��10λ
const int g_MaxNumberLength = 10;
 
char *g_StrCombine1 = (char *)malloc(sizeof(char) * (g_MaxNumberLength * 2 + 1));
char *g_StrCombine2 = (char *)malloc(sizeof(char) * (g_MaxNumberLength * 2 + 1));
 
void PrintMinNumber(const int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		return;
	}
	char **strNumbers = (char **)malloc(sizeof(char *) * length);
	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = (char *)malloc(sizeof(char) * (g_MaxNumberLength + 1));
		sprintf(strNumbers[i],"%d",numbers[i]);
	}
	qsort(strNumbers,length,sizeof(char *),compare);
	for (int i = 0; i < length; i++)
	{
		printf("%s",strNumbers[i]);
	}
	printf("\n");
	free(strNumbers);
}

int compare(const void* strNumber1, const void* strNumber2)
{
	strcpy(g_StrCombine1,*(const char **)strNumber1);
	strcat(g_StrCombine1,*(const char **)strNumber2);

	strcpy(g_StrCombine2,*(const char **)strNumber2);
	strcat(g_StrCombine2,*(const char **)strNumber1);

	return strcmp(g_StrCombine1,g_StrCombine2);
}


// ====================���Դ���====================

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	PrintMinNumber(numbers,length);   // 12345
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    int length = sizeof(numbers)/sizeof(numbers[0]);
	PrintMinNumber(numbers,length);   // 321323
}

void Test3()
{
    int numbers[] = {3, 323, 32123};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	PrintMinNumber(numbers,length);   // 321233233
}

void Test4()
{
    int numbers[] = {1, 11, 111};
	int length = sizeof(numbers)/sizeof(numbers[0]);
	PrintMinNumber(numbers,length);   // 111111
}

// ������ֻ��һ������
void Test5()
{
    int numbers[] = {321};
    int length = sizeof(numbers)/sizeof(numbers[0]);
	PrintMinNumber(numbers,length);   // 321
}

void Test6()
{
	int *numbers = NULL;
    int length = 0;
	PrintMinNumber(numbers,length);   // NULL
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