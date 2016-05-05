#include <stdio.h>
#include <stdint.h>
#include <algorithm>
#include <vector>
#include <utility>

using std::vector;

#define BOARD_LEFT -9999
struct i2pair
{
	int start;
	int end;
};

bool comp(i2pair p1, i2pair p2) { return p1.end<p2.end; }

int main(int argc, char const *argv[])
{
	uint32_t n;
	scanf("%u", &n);
	vector<i2pair> posters(n);
	for (uint i = 0; i < n; ++i)
	{
		int l,r;
		scanf("%d %d", &l, &r);

		i2pair& p = posters[i];
		l<r ?  0 : (std::swap(l, r), 0);
		p.start = l; p.end = r;
	}


	std::sort(posters.begin(), posters.end(), comp);

	int num = 0;
	int end = BOARD_LEFT;
	for (uint i = 0; i < posters.size(); ++i)
	{
		i2pair& p = posters[i];
		p.start>=end ? num++, end = p.end : 0;
	}

	printf("%d\n", num);

	return 0;
}