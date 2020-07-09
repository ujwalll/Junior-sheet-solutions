#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1073741824;
#define pp pair<ll,ll>
#define ppi pair<ll,ll>
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
ll sum[100005];
ll cnt[100005];
struct re{
    ll l,r,d;
};
int main()
{
    fastio();
    int t=1;
    // cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll a[n];
        REP(i,n){
            cin>>a[i];
        }
        vector<re> v;
        ll x,y,d;
        REP(i,m){
            cin>>x>>y>>d;
            x--;y--;
            v.push_back({x,y,d});
        }
        REP(i,k){
            cin>>x>>y;
            x--;y--;
            cnt[x]++;cnt[y+1]--;
        }
        for1(i,m){
            cnt[i]+=cnt[i-1];
        }
        REP(i,m){
            sum[v[i].l]+=v[i].d*cnt[i];
            sum[v[i].r + 1]-=v[i].d*cnt[i];
        }
        a[0]+=sum[0];
        cout<<a[0]<<" ";
        for1(i,n){
            sum[i]+=sum[i-1];
            if(i!=n){
                cout<<a[i]+sum[i]<<" ";
            }
        }

    }   
    return 0;
}