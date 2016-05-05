#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

#define reverse(str) \
	do{ \
		int l = strlen(str);\
		for (int i = 0; i < l/2; ++i)\
		{\
			std::swap(str[i], str[l-i-1]);\
		}\
	}while(0);

int main(int argc, char const *argv[])
{
	char A[10], B[10];
	scanf("%s %s", A, B);

	reverse(A); reverse(B);

	int C, D;
	sscanf(A, "%d", &C); sscanf(B, "%d", &D);

	int S = C+D;
	char buffer[11];
	sprintf(buffer, "%d", S);

	int result;
	reverse(buffer);
	sscanf(buffer, "%d", &result);

	printf("%d\n", result);	
	return 0;
}