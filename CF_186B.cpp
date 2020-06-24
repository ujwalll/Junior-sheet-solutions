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
bool comp(const pair<double,int> &a,const pair<double,int> &b)
{
    return (a.first > b.first || (a.first==b.first && a.second<b.second));
}
int main()
{
  fastio();
  int t=1;
  //cin>>t;
  while(t--)
  {
    int n,t1,t2,k;
    cin>>n>>t1>>t2>>k;
    vector<pair<double,int>> ans;
    int x,y;
    for1(i,n)
    {
        cin>>x>>y;
        double u,v;
        u=x*t1;
        u=(double)(u-(u*k*0.01));
        u+=y*t2;
        v=y*t1;
        v=(double)(v-(v*k*0.01));
        v+=x*t2;
        v=max(u,v);
        ans.push_back({v,i});
    }
    sort(ans.begin(),ans.end(),comp);
    for(auto i:ans)
    cout<<fixed<<setprecision(2)<<i.second<<" "<<i.first<<"\n";
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