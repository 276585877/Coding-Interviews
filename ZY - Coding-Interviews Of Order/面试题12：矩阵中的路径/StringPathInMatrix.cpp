// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H



/*

˼·�����ȶ���һ���������͵ľ��󣬴˾�����ַ������С��ͬ��������ʶ·���Ƿ��Ѿ�������ÿ�����ӵ���
		����Ƕ��ѭ�����α����ַ������е�ÿһ��Ԫ�أ�������һ���ȶԺ��������ж�
		�ȶԺ�������ƣ��������е�ĳһ����Ԫ�����ַ����±�Ϊpathlength���ַ����ʱ���Ӹø������ڵ�����
		����4��������ƥ�����ַ����±�Ϊpathlength+1���ַ���ȵģ���4�����Ӷ�û���ҵ������ַ����±�Ϊ
		pathlength���ַ����ַ������еĶ�λ����ȷ�����ǻص�ǰһ���ַ� ��--pathlength��,Ȼ�����¶�λ

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
	{
		return false;
	}

	bool *visited = (bool *)malloc(sizeof(bool) * (rows * cols));
	memset(visited,0,rows * cols);

	int pathLength = 0;
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < cols; col++)
		{
			if (hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
			{
				return true;
			}
		}
	}
	free(visited);
	return false;
}

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
	{
		return true;
	}

	bool hasPath = false;
	if (row >= 0 && col >= 0 && row < rows && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		++pathLength;
		visited[row *cols + col] = true;

		hasPath = hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited)||\
					hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited);
		
		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}
	return hasPath;
}

// ====================���Դ���====================
//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";
	if (hasPath(matrix,5,8,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";
	if (hasPath(matrix,3,4,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";
	if (hasPath(matrix,1,1,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";
	if (hasPath(matrix,1,1,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
}

void Test12()
{
	const char* matrix = NULL;
	const char* str = NULL;
    if (hasPath(matrix,0,0,str))
	{
		printf("EXIST!\n");
	}
	else
	{
		printf("NOT EXIST!\n");
	}
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
    Test10();
    Test11();
    Test12();

    return 0;
}

