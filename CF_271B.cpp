#include <bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1073741824;
#define pp pair<ll,ll>
#define ppi pair<int,int>
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
vector<int> pr;
bool ch[1000005];
void f(){
    memset(ch,true,sizeof(ch));
    for(int i=2;i<1000000;i++){
        for(int j=i+i;j<1000000;j+=i){
            if(ch[j])ch[j]=false;
        }
    }
    for(int i=2;i<1000000;i++){
        if(ch[i])pr.push_back(i);
    }
}
int main(){
    int tc=1;
    // cin>>tc;
    while(tc--){
        f();
        int n,m;
        cin>>n>>m;
        int a[n][m];
        rep(i,n){
            rep(j,m)cin>>a[i][j];
        }
        ll ans=INT64_MAX,cnt=0;
        rep(i,n){
            rep(j,m){
                int u = lower_bound(pr.begin(),pr.end(),a[i][j]) - pr.begin();
                cnt+=pr[u]-a[i][j];
            }
            ans=min(ans,cnt);
            cnt=0;
        }
        rep(i,m){
            rep(j,n){
                int u = lower_bound(pr.begin(),pr.end(),a[j][i]) - pr.begin();
                cnt+=pr[u]-a[j][i];
            }
            ans=min(ans,cnt);
            cnt=0;
        }
        cout<<ans;
    }

}