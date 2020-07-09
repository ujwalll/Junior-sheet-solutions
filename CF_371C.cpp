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
    // cin>>t;
    while(t--){
        string s;cin>>s;
        ll nb=0,ns=0,nc=0;
        ll tone=0;
        REP(i,s.length()){
            if(s[i]=='B')nb++;
            else if(s[i]=='S')ns++;
            else nc++;
        }
        ll b,se,c,pb,ps,pc;
        cin>>b>>se>>c>>pb>>ps>>pc;
        ll ans=0,r;
        cin>>r;
        //ll mn=INT64_MAX;
        //ll cnt=0;
        ll l=0,h=100000000000000;
        while(l<=h){
            ll mid = (l+h)/2;
            ll cost=0;
            ll rb=nb*mid,rs=ns*mid,rc=nc*mid;
            rb = (rb>b)?rb-=b:0;
            if(rs>se)rs-=se;
            else rs=0;
            if(rc>c)rc-=c;
            else rc=0;
            cost = rb*pb + rs*ps + rc*pc;
            if(cost <= r){
                l=mid+1;
                ans=mid;
            }
            else h=mid-1;
        }
        cout<<ans;
    }
    return 0;
}