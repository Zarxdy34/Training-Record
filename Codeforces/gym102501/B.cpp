#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;

unordered_map<string,int> M;
string ans;
int maxv,maxcnt;
int n;

int main()
{
	cin.tie(0);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		int v=++M[x];
		if (v>maxv) maxv=v,maxcnt=1,ans=x;
		else if (v==maxv) maxcnt++;
	}
	if (maxv>n-maxv) cout<<ans<<endl;
	else cout<<"NONE"<<endl;
}
