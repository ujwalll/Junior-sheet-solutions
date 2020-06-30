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

int main()
{
    fastio();
    int t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k,l,r,stotal,sk;
        cin>>n>>k>>l>>r>>stotal>>sk;
        stotal-=sk;
        vector<ll> res;
        int ones=sk%k;
        REP(i,k)
        {
            int u=(sk/k) + (ones>0);
            ones--;
            res.push_back(u);
        }
        if(n!=k)
        ones=stotal%(n-k);
        REP(i,n-k)
        {
            int u=(stotal/(n-k)) + (ones>0);
            ones--;
            res.push_back(u);
        }
        for(auto i:res)
        cout<<i<<" ";
    }
    return 0;
}