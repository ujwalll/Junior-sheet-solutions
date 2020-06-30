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
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
////////////////////////////////////////////////////////////////////

vector<pair<int,int>> adj[105];
bool vis[105],cvis[105];
int ans=0;
void dfs(int cur,int end,int col)
{
  if(vis[cur])
  return;
  vis[cur]=1;
  if(cur==end)
  {
    ans++;
    return;
  }
  for(auto j:adj[cur])
  {
    if(j.second==col && !vis[j.first])
    {
      dfs(j.first,end,col);
    }
  }
}
int main()
{
  fastio();
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    int x,y,z;
    REP(i,m)
    {
      cin>>x>>y>>z;
      adj[x].push_back({y,z});
      adj[y].push_back({x,z});
    }
    int q;
    cin>>q;
    while(q--)
    {
      cin>>x>>y;
      for(auto i:adj[x])
      {
        if(!cvis[i.second])
        {
          cvis[i.second]=1;
          dfs(x,y,i.second);
          memset(vis,0,sizeof(vis));
        }
      }
      memset(cvis,0,sizeof(cvis));
      cout<<ans<<"\n";
      ans=0;
    }
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