#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>

using std::vector;


void big_mul(const char* number, int length, int factor, char* result)
{
	if(factor==0)
	{
		memset(number, 0, length);
		return;
	}
	int tmpfactor = factor;
	int digits = 1;
	while(tmpfactor/=10) { digits++; }
	char interm[length+1];
	char final[length+digits+1];
	memset(final,0,length+digits+1);
	int now_f_digit = 0;
	while(factor)
	{
		int now_f = factor%10;
		memset(interm, 0, length+1);


		for (int i = 0; i < length; ++i)
		{
			int tmp = number[i]*now_f + interm[i];

			interm[i] = tmp%10;

			interm[i+1] += tmp/10;
		}

		for (int i = 0; i < length+1; ++i)
		{
			interm[i] += final[i+now_f_digit];
			final[i+now_f_digit] = interm[i]%10;
			final[i+now_f_digit+1] += interm[i]/10;
		}

		factor /= 10;
		now_f_digit++;
	}
	memcpy(result, final, length+digits+1);

}

int length_of(const char number[], const int BUFFER_SIZE)
{
	int idx = BUFFER_SIZE;
	char ch;
	while(!(ch=number[--idx])) {};

	return idx+1;
}

const int VECTOR_SIZE = 'z'-'0'+1;
vector<char> bucket_trans[VECTOR_SIZE];
int counter;
bool visited[VECTOR_SIZE];

void dfs(char ch)
{
	visited[ch-'0'] = true;
	counter++;
	const vector<char>& transv = bucket_trans[ch-'0'];
	for (uint i = 0; i < transv.size(); ++i)
	{
		char tran_ch = transv[i];
		if(!visited[tran_ch-'0']) { dfs(tran_ch); }
	}
}

int main(int argc, char const *argv[])
{
	const int BUFFER_SIZE = 1024;
	char tmp[BUFFER_SIZE];
	memset(tmp, 0, BUFFER_SIZE);
	tmp[0] = 1;

	char str[64];
	int k;

	scanf("%s", str);
	scanf("%d", &k);
	int i=0;
	char ch;

	char from, to;

	i = k;
	while(i--)
	{
		// http://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
		scanf(" %c %c", &from, &to);
		bucket_trans[from-'0'].push_back(to);
	}

	i = 0;
	while((ch=str[i++])!=0)
	{
		vector<char>& transv = bucket_trans[int(ch-'0')];
		if(transv.size())
		{
			counter=0;
			memset(visited, false, VECTOR_SIZE*sizeof(bool));
			dfs(ch);
			int length = length_of(tmp, BUFFER_SIZE);
			big_mul(tmp, length, counter, tmp);
		}
	}

	for (int i = length_of(tmp, BUFFER_SIZE)-1; i >=0; --i)
	{
		printf("%c", tmp[i]+'0');
	}
	printf("\n");

	return 0;
}