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
        ll n;cin>>n;
        vector<ll> a,b,c;
        map<ll,bool> mp;
        ll x,y;
        REP(i,n){
            cin>>x>>y;
            a.push_back(x);
            b.push_back(y);
            c.push_back(x);
            c.push_back(y);
        }
        sort(c.begin(),c.end());
        REP(i,n/2){
            mp[a[i]]=true;
            mp[b[i]]=true;
        }
        REP(i,n){
            mp[c[i]]=true;
        }
        string ans1="",ans2="";
        REP(i,n){
            if(mp[a[i]])ans1+='1';
            else ans1+='0';
            if(mp[b[i]])ans2+='1';
            else ans2+='0';
        }
        cout<<ans1<<"\n"<<ans2;
    }
    return 0;
}