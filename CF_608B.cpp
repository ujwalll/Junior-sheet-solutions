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
int zero[200005],one[200005];

int main()
{
    fastio();
    int t=1;
    // cin>>t;
    while(t--)
    {
    string s,t;
    cin>>s>>t;
    ll n=t.size();
    ll zero[n+1]={},ones[n+1]={};
    for1(i,n)
    {
        ones[i]=ones[i-1];
        zero[i]=zero[i-1];
        if(t[i-1]=='1') ones[i]++;
        else zero[i]++;
    }
    ll ans=0;
    ll m=s.size();
    REP(i,m)
    {if(s[i]=='1') ans+=zero[i+n-m+1]-zero[i];
    else ans+=ones[i+n-m+1]-ones[i];}
    
    cout<<ans<<endl;
 
    }
    return 0;
}