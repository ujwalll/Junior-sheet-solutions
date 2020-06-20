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
int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
////////////////////////////////////////////////////////////////////
bool vis[20][20];
int moves[20][20];

bool isvalid(int x,int y)
{
    if(x<8 && x>=0 && y<8 && y>=0)return true;
    return false;
}

int BFS(int srcx,int srcy,int destx,int desty)
{
    moves[srcx][srcy]=0;
    vis[srcx][srcy]=true;
    queue<int> q;
    q.push(srcx),q.push(srcy);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        int y=q.front();q.pop();
        if(x==destx && y==desty)
        return moves[x][y];
        for(int i=0;i<8;i++)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(isvalid(x1,y1) && !vis[x1][y1])
            {
                moves[x1][y1]=moves[x][y]+1;
                q.push(x1);
                q.push(y1);
                vis[x1][y1]=1;
            }
        }
    }
}
int main()
{
  fastio();
  //freopen("uva.txt","rt",stdin);
  char st1[5],st2[5];
  while(scanf("%s%s", st1, st2)!=EOF)
  {
    memset(vis,0,sizeof(vis));
    memset(moves,-1,sizeof(moves));
    int mov = BFS(st1[1]-'1',st1[0]-'a',st2[1]-'1',st2[0]-'a');

    printf("To get from %s to %s takes %d knight moves.\n", st1, st2, mov);
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