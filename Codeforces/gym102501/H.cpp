#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;

int head[maxn],nxt[maxn<<1],E[maxn<<1],Ecnt;
int st[maxn];
int ansq[maxn],ansn;
int n,m,T;

void Add_Edge(int x,int y)
{
	nxt[++Ecnt]=head[y];head[y]=Ecnt;E[Ecnt]=x;
}

int q[maxn];
void BFS(int s)
{
	q[1]=s;
	int top=1,tail=1;
	if (st[s]==0) st[s]=s;
	else st[s]=-1;
	while (top<=tail)
	{
		int x=q[top++];
		for (int i=head[x];i;i=nxt[i]) if (E[i]!=T && st[E[i]]!=-1 && (st[E[i]]==0 || st[E[i]]!=s))
		{
			q[++tail]=E[i];
			if (st[E[i]]==0) st[E[i]]=s;
			else st[E[i]]=-1;
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&T);T++;
	while (m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add_Edge(x+1,y+1);
	}
	for (int i=head[T];i;i=nxt[i]) BFS(E[i]);
	for (int i=head[T];i;i=nxt[i]) if (st[E[i]]==E[i])
		ansq[++ansn]=E[i];
	sort(ansq+1,ansq+1+ansn);
	printf("%d\n",ansn);
	for (int i=1;i<=ansn;i++) printf("%d\n",ansq[i]-1);
}
