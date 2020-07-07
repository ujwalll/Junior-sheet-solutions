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
    while(t--)
    {
        ll n,r;
        double avg;
        cin>>n>>r>>avg;
        vector<pp> v;
        ll x,y,sum=0;
        REP(i,n){
            cin>>x>>y;
            v.push_back({y,x});
            sum+=x;
        }
        double ch=(double)sum/n;
        if(ch-avg>=0)return cout<<0,0;
        sort(v.begin(),v.end());
        ll ans=0;
        REP(i,n){
            ll diff=r-v[i].second;
            if(diff==0)continue;
            sum+=diff;
            ch=(double)sum/n;
            sum-=diff;
            if(ch<=avg){
                sum+=diff;
                ans+=diff*v[i].first;
            }
            else{
                ch=(double)sum/n;
                x=(ll)avg*n;
                ans+=(x-sum)*v[i].first;
                goto done;
            }
        }
        done:
        ;
        cout<<ans;
    }
    return 0;
}