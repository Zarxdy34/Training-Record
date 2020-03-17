#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxs=210;

map<string,int> M;
string name[maxs];
int mp[maxs][maxs];
int cnt[maxn];
int nxt[maxn],lst[maxs];
int a[maxn];
int n,s,l;

int main()
{
	cin.tie(0);
	cin>>s>>l>>n;
	for (int i=1;i<=s;i++) cin>>name[i];
	sort(name+1,name+1+s);
	for (int i=1;i<=s;i++) M[name[i]]=i;
	for (int i=0;i<l;i++)
	{
		string x,y;
		cin>>x>>y;
		int idx=M[x],idy=M[y];
		mp[idx][idy]=mp[idy][idx]=1;
	}
	for (int i=1;i<=s;i++) mp[i][i]=1;
	for (int i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		a[i]=M[x];
	}
	for (int i=1;i<=s;i++) lst[i]=n+1;
	for (int i=n;i>=1;i--)
	{
		int x=a[i];
		for (int j=1;j<=maxs;j++) if (!mp[x][j]) ++cnt[lst[j]];
		nxt[i]=lst[x];
		lst[x]=i;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=s;j++) if (lst[j]<=n && cnt[lst[j]]==0)
		{
			cout<<name[j]<<' ';
			for (int k=1;k<=maxs;k++) if (!mp[j][k]) --cnt[lst[k]];
			lst[j]=nxt[lst[j]];
			break;
		}
	}
	return 0;
}
