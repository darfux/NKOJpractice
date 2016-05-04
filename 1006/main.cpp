#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define out_of_bound_test(idx) if(idx<0||idx>=n) { continue; }

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char mine[n][n+1];
	char reveal[n][n+1];

	int16_t number[n][n];

	memset(number, -1, sizeof(int16_t)*n*(n+1));
	bool boom = false;


	for (int i = 0; i < n; ++i) { scanf("%s", (char*)(mine[i])  ); }
	for (int i = 0; i < n; ++i) { scanf("%s", (char*)(reveal[i])); }

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(reveal[i][j]=='.') { continue; }	
			if(mine[i][j]=='*')   { boom=true;}
			int16_t& point = number[i][j]; 							
			point = 0; 												
			for (int row = -1; row <= 1; ++row) 					
			{ 														
				int idx_row = i+row; 								
				out_of_bound_test(idx_row); 						
				for (int col = -1; col <= 1; ++col) 					
				{ 													
					int idx_col = j+col; 							
					out_of_bound_test(idx_col);									
					mine[idx_row][idx_col]=='*' ? point++ : 0; 												
				}													
			}														
		}
	}

	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int point = number[i][j];
			if(point>=0)
			{
				ch = (mine[i][j]=='*' ? '*' : '0'+ point);
			}
			else
			{
				ch = (mine[i][j]=='*' && boom ? '*' : '.');
			}
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}