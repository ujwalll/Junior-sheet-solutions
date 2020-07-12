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
int cnt[100005];
void solve(){
    int n;
    cin>>n;
    int a[n+1];for1(i,n)cin>>a[i];
    for1(i,n){
        if(n%i==0 && n/i >= 3){
            memset(cnt,0,sizeof(cnt));
            for1(j,n)cnt[j%i]+=a[j];
            bool ok=1;
            for(int j=0;j<i;j++){
                if(cnt[j]==n/i){
                    cout<<"YES";
                    return;
                }
            }
        }
    }
    cout<<"NO";
}

int main(){
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
}