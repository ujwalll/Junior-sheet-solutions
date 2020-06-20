#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1000000007;
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
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
////////////////////////////////////////////////////////////////////
int x0,x,y,ys;
int n;
map<pair<int,int>,bool> mp;
map<pair<int,int>,bool> vis;
map<pair<int,int>,int> dis;
bool isvalid(int a,int b)
{
    return (a>=1 && a<=1e9 && b>=1 && b<=1e9);
}

int BFS()
{
    queue<int> q;
    q.push(x0);
    q.push(ys);
    dis[{x0,ys}]=0;
    vis[{x0,ys}]=true;
    while(!q.empty())
    {
        int x1=q.front();q.pop();
        int y1=q.front();q.pop();
        if(x1==x && y1==y)
        return dis[{x1,y1}];
        vis[{x1,y1}]=true;
        REP(i,8)
        {
            int tx=x1+dx[i];
            int ty=y1+dy[i];
            if(mp[{tx,ty}] && isvalid(tx,ty) && !vis[{tx,ty}])
            {
                dis[{tx,ty}]=dis[{x1,y1}]+1;
                vis[{tx,ty}]=true;
                q.push(tx);
                q.push(ty);
            }
        }
    }
    return -1;
}
int solve()
{
    cin>>x0>>ys>>x>>y;
    cin>>n;
    int r,a,b;
    REP(i,n)
    {
        cin>>r>>a>>b;
        for(int j=a;j<=b;j++)
        {
            mp[{r,j}]=true;
        }
    }
    int u= BFS();
    return u;
}
int main()
{
  fastio();
  int t=1;
  //cin>>t;
  while(t--)
  {
    cout<<solve()<<"\n";
    //cout<<x<<" "<<y;
    //cout<<dis[{x,y}];
  }  
  return 0;
  //Read the stuff at the bottom
}
/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 :( )
* special cases (n=1?)
* 1LL<<i and not 1<<i
* overflow (int vs ll?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing :/
*/
/*lcm(gcd(N1, M), gcd(N2, M), ..., gcd(Nk, M)) = gcd(lcm(N1, ..., Nk), M)
gcd(lcm(N1, M), lcm(N2, M), ..., lcm(Nk, M)) = lcm(gcd(N1, ..., Nk), M).

If gcd(N1, N2) = 1, then
gcd(N1·N2, M) = gcd(N1, M)·gcd(N2, M)
lcm(N1·N2, M) = lcm(N1, M)·lcm(N2, M)/M.

lcm(M, N, P) · gcd(M, N) · gcd(N, P) · gcd(P, M) = NMP · gcd(N, M, P).
*/