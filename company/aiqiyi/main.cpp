#include <stdio.h>
#include <algorithm>

int r, c;
int** ar;
int** vm;

int search(int row, int col, int pre)
{
	if(row<0 || row>=r || col<0 || col>=c) { return 0; }


	int self = ar[row][col];
	if(self>=pre) { return 0; }
	int result = vm[row][col];
	if(result != -1) { return result;}


	int up		= search(row-1, col, self);
	int down	= search(row+1, col, self);
	int right	= search(row, col+1, self);
	int left	= search(row, col-1, self);

	int tmp[] = {up, down, right, left};

	int max = *std::max_element(tmp,tmp+4);

	result = max>0? max+1 : 1;
	vm[row][col] = result;
	return result;
}


int main(int argc, char const *argv[])
{
	scanf("%d %d", &r, &c);


	ar = new int*[r];
	vm = new int*[r];

	for (int i = 0; i < r; ++i)
	{
		ar[i] = new int[c];
		vm[i] = new int[c];
		for (int j = 0; j < c; ++j)
		{
			scanf("%d", &ar[i][j]);
			vm[i][j] = -1;
		}
	}


	int max = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int tmp = search(i, j, 0x3f3f3f3f);
			if(tmp>max) { max = tmp; }
		}
	}


	printf("%d", max);

	for (int i = 0; i < r; ++i)
	{
		delete[] ar[i];
		delete[] vm[i];
	}
	delete[] ar;
	delete[] vm;

	return 0;
}
