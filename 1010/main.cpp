#include <stdio.h>
#define INF 0x3f3f3f3f
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);

	char fake_seats[n+3];
	scanf("%s", &fake_seats[1]);
	fake_seats[0] = fake_seats[n+1] = 'P';
	fake_seats[n+2] = 0;

	char* seats = &fake_seats[1];

	int i;
	for (i = 0; i < n/2; ++i)
	{
		char current, l, r;
		for (int j = -1; j <= 1; j+=2)
		{
			int idx = (n-1)/2+i*j;
			current = seats[idx];
			l = seats[idx-1];
			r = seats[idx+1];
			if(current=='E'&&(l=='E'||r=='E'))
			{
				printf("%d\n", idx);
				i = INF; break;
			}
		}
	}
	if(i<INF)
	{
		printf("-1\n");
	}
	return 0;
}
