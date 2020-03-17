#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;

int a[maxn];
char s[110];
int n;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",s);
		int len=strlen(s);
		if (s[0]=='-') continue;
		if (len>7) continue;
		int x=0;
		for (int i=0;i<len;i++) x=x*10+s[i]-'0';
		if (x>=maxn) continue;
		a[x]=1;
	}
	for (int i=0;i<maxn;i++) if (!a[i])
	{
		printf("%d\n",i);
		return 0;
	}
}
