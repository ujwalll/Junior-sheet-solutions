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
ll a,b;
ll solve(ll x){
    ll l1=0,l2=0;
    while(a%x==0)l1++,a/=x;
    while(b%x==0)l2++,b/=x;
    return abs(l1-l2);
}

int main()
{
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
        cin>>a>>b;
        ll a2=0,a3=0,a5=0,b2=0,b3=0,b5=0;
        if(a==b)cout<<0;
        else{
            ll ans=0;
            ans+=solve(2);
            ans+=solve(3);
            ans+=solve(5);
            if(a!=b)cout<<-1;
            else cout<<ans;
        }
    }
    return 0;
}