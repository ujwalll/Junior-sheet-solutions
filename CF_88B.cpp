#include <bits/stdc++.h>
using namespace std;
char a[55][55];
int n,m,x;
int ok[128],ap[128];
char t[500011];
int dist(int p,int q,int r,int s)
{
	return (p-r)*(p-r)+(q-s)*(q-s);
}
int main()
{
	cin >>n>>m>>x;
	for(int i=0;i<n;i++)
	cin >>a[i];
	int shift=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(a[i][j]=='S')
		{
			shift=1;
			for(int u=0;u<n;u++)
			for(int v=0;v<m;v++)
			if(dist(i,j,u,v)<=x*x)
			ok[(int)a[u][v]]=1;
		}
		else
		ap[(int)a[i][j]]=1;
	}
	cin >>n;
	cin >>t;
	int ans=0,f=0;
	for(int i=0;t[i];i++)
	{
		if(t[i]>='A'&&t[i]<='Z')
		{
			if(!shift||!ap[t[i]+32])
			f=1;
			ans+=!ok[t[i]+32];
		}
		else if(!ap[(int)t[i]])
		f=1;
	}
	if(f)
	ans=-1;
	cout <<ans<<endl;
	return 0;
}
