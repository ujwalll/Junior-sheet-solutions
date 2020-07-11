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
void solve(){
    ll n,k;
    cin>>n>>k;
    string s;cin>>s;
    vector<ll> v;
    REP(i,n){
        if(s[i]=='1')v.push_back(i);
    }
    ll sum=0;
    REP(i,v.size()){
        int ind = lower_bound(v.begin(),v.end(),v[i]+k)-v.begin();
        if(ind==v.size() || v[ind]!=v[i]+k){
            sum+=(ind-i)*2 - 1;
        }
        else sum+=(ind-i+1)*2 - 1;
    }
    ll x= 1LL*n*n;
    ll gc=__gcd(x,sum);
    sum=sum/gc;
    x=x/gc;
    if(sum==0){
        cout<<"0/1\n";
    }
    else{
        cout<<sum<<"/"<<x<<"\n";
    }
}

int main(){
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
}