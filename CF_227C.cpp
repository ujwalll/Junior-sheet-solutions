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
long long binpow(long long a, long long b,ll m) {
    long long res = 1;
    a%=m;
    while (b > 0) {
        if (b & 1)
            res = res * a%m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
////////////////////////////////////////////////////////////////////

void solve(){
    ll n,m;
    cin>>n>>m;
    ll x = binpow(3,n,m);
    cout<<(x-1+m)%m<<"\n";
}

int main(){
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
}