#include <stdio.h>
#include <vector>
#include <algorithm>

using std::vector;
typedef std::vector<long long int>::iterator Itor;

int main(int argc, char const *argv[])
{
	Test t = Test();
	long long int a;
	vector<long long int> ar; Itor it;
	char ch;
	while((ch = getc(stdin))!=EOF){ if(ch<='9' && ch>='0') break; }
	if(ch==EOF){
		printf("%s", "");
		return 0;
	}

	ungetc(ch, stdin);
	while(scanf("%lld%*[^0-9]", &a)!=EOF) { ar.push_back(a); }
	std::sort( ar.begin(), ar.end() );
	
	for (it=ar.end()-1; it!=ar.begin(); --it) { printf("%lld ", *it); }
	printf("%lld", *it);
	return 0;
}