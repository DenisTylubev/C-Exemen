#include <iostream>
#include<Windows.h>
#include <stdio.h>


using namespace std;


int Trinatri(int** a, int i, int j, int b)
{
	int l = i / 3,
		p = j / 3;
	for (int z(l * 3), i = z; i < z + 3; ++i)
		for (int m(p * 3), k = m; k < m + 3; ++k)
			if (a[i][k] == b) return 1;
	return 0;
	
}

int Vertical(int** a, int i, int b)
{
	for (int j = 0; j < 9; ++j)
		if (a[i][j] == b) return 1;
	return 0;
}

int Horizont(int** a, int j, int b)
{
	for (int i = 0; i < 9; ++i)
		
		if (a[i][j] == b) return 1;
	return 0;
}

void InitializationMas(int** a)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			a[i][j] = -1;
	
}

void Sudoku(int** a)
{
	for (int i = 0; i < 9; ++i)
	{
		
		for (int j = 0; j < 9; ++j)
		{
			
			int c = 9;
			for (int h = 1; h < 10; ++h)
				if (Trinatri(a, i, j, h) || Horizont(a, j, h) || Vertical(a, i, h))
					--c;
			if (!c)
			{
				InitializationMas(a);
				Sudoku(a);
				return;
			}
			int b = rand() % 9 + 1;
			while (Trinatri(a, i, j, b) || Horizont(a, j, b) || Vertical(a, i, b))
				b = rand() % 9 + 1;
			a[i][j] = b;
		}
	}
}

void ShowMas(int** a)
{
	
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			
			printf("%3d", a[i][j]);
		printf("\n\n");

	}
	

}

int main()
{

	int** a = (int **)calloc(9, sizeof(int *));
	for (int i = 0; i < 9; ++i)
		a[i] = (int *)calloc(9, sizeof(int));
	InitializationMas(a);
	Sudoku(a);
	ShowMas(a);
	
	system("pause");
	
}