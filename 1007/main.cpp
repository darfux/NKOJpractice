#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	uint32_t n;
	scanf("%u", &n);

	int factors[512];

	int idx = 0;

	for (uint32_t i = 2; i <= n; ++i)
	{
		while(n != i)
		{
			if(n%i == 0)
			{
				factors[idx++] = i;
				n /= i;
			}
			else { break; }
		}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; ++i)
	{
		printf("%d ", factors[i]);
	}
	printf("%d", n);

	return 0;
}