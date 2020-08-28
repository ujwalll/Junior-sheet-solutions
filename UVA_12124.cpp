/*
    author:ujwalll
*/
#pragma GCC optimize("O2")
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
ll n,bgt;
map<string,vector<pp>> mp;
map<string,vector<pp>>::iterator it;
vector<pp>::iterator j;
int main(){
    int tc=1;
    cin>>tc;
    while(tc--){
        cin>>n>>bgt;
        mp.clear();
        string s,t;ll x,y;
        rep(i,n){
            cin>>s>>t>>x>>y;
            mp[s].push_back({y,x});
        }
        ll ans=0;
        ll l=0,r= 1000000000;
        while(l<=r){
            ll mid=(l+r)/2;
            ll cost=0;
            for(it=mp.begin();it!=mp.end();it++){
                ll ch=1000000;
                for(j=(it->second).begin();j!=(it->second).end();j++){
                    if(j->first >= mid){
                        ch=min(ch,j->second);
                    }
                }
                cost+=ch;
                if(cost>bgt)break;
            }
            if(cost<=bgt){
                ans=max(ans,mid);
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}