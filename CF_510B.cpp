#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1073741824;
#define pp pair<ll,ll>
typedef long long int ll;
bool isPowerOfTwo (ll x)  
{  
    return x && (!(x&(x-1)));  
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
// //const int dx[] = {1,0,-1,0,1,1,-1,-1};
// const int dy[] = {0,-1,0,1,1,-1,-1,1};
////////////////////////////////////////////////////////////////////
char a[51][51];
bool vis[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
bool flag;
bool isvalid(int x,int y)
{
    return (x<n && x>=0 && y<m && y>=0);
}

//string ans="ujwal";
void dfs(int i,int j,int x,int y)
{
    vis[i][j]=true;
    REP(l,4)
    {
        int x1=i+dx[l],y1=j+dy[l];
        if(isvalid(x1,y1) && a[i][j]==a[x1][y1] && (x1!=x || y1!=y))
        {
            if(vis[x1][y1])
            {
                flag=1;
                return;
            }
            dfs(x1,y1,i,j);
        }
        if(flag)
        return;
    }
    if(flag)return;
}
int main()
{
    fastio();
    int t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m;
        REP(i,n)
        {
            REP(j,m)
            cin>>a[i][j];
        }
        memset(vis,0,sizeof(vis));
        REP(i,n)
        {
            REP(j,m)
            {
                if(!vis[i][j])
                dfs(i,j,i,j);
            }
        }
        if(flag)cout<<"Yes";
        else
        cout<<"No";
    }
    return 0;
}