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

const int maxn=1e6;
int deg[maxn];
bool vis[maxn];
vector<ll> adj[maxn];
ll x,y;
void dfs(int s)
{
    vis[s]=1;x++;
    for(auto j:adj[s])
    {
        y++;
        if(!vis[j])dfs(j);
    }
}
int main()
{
    fastio();
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        //int x,y;
        REP(i,m)
        {
            cin>>x>>y;
            //deg[x]++,deg[y]++;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for1(i,n)
        {
            if(!vis[i])
            {
                x=0,y=0,dfs(i);
                ll c=x*(x-1)/2;
                y/=2;
                if(y!=c)
                {
                    cout<<"NO";
                    return 0;
                }
            }
        }
        cout<<"YES";
    }
    return 0;
}