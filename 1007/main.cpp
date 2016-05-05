#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	uint32_t n;
	scanf("%u", &n);

	while(n>3)
	{
		if((n&1)==1)
		{
			printf("3 ");
			n-=3;
		}
		else
		{
			printf("2 ");
			n-=2;
		}
	}
	printf("%d", n);

	return 0;
}