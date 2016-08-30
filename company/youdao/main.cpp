#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int FLAG_POS = 0x1 << 7;
	char buffer[100000];
	int idx = 0;

	while(scanf("%c", &buffer[idx++])!=EOF){}

	int length = idx - 1;
	int scan_idx = 0;
	int filter_idx = 0;
	int inner_delete_counter = 0;
	while(scan_idx<length)
	{
		char now_ch = buffer[scan_idx];
		buffer[filter_idx++] = now_ch;
		int dup_counter = 0;
		while( scan_idx < length && now_ch==buffer[++scan_idx] ) { dup_counter++; }
		if(dup_counter>0) { inner_delete_counter++; buffer[filter_idx-1] |= FLAG_POS; }
	}

	int new_length = filter_idx;
	int counter = 0;
	for (int i = 0; i < new_length; ++i)
	{
		counter+=new_length-i-1;
		char l = buffer[i-1] & 0x7f;
		char r = buffer[i+1] & 0x7f;
		int flag = buffer[i] & FLAG_POS;
		if( (i+1<new_length && i-1>=0) 
			&& flag!=FLAG_POS
			&& l==r )
		{
			counter--;
		}
	}

	int total_counter = counter + inner_delete_counter;
	printf("%d", total_counter);
	return 0;
}
