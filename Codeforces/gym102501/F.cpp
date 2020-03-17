#include <bits/stdc++.h>
using namespace std;
const int maxn=60;

long long X[maxn],Y[maxn];
int n,p;
long long ans;

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		scanf("%d",&p);
		long long res=0;
		for (int i=0;i<p;i++) scanf("%lld%lld",&X[i],&Y[i]);
		for (int i=0;i<p-1;i++) res+=X[i]*Y[i+1]-X[i+1]*Y[i];
		res+=X[p-1]*Y[0]-X[0]*Y[p-1];
		if (res<0) res=-res;
		ans+=res;
	}
	printf("%lld\n",ans/2);
}
