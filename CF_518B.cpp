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
map<char,int> mp;
int main()
{
    fastio();
    int tc=1;
    // cin>>t;
    while(tc--){
        string s,t;
        cin>>s>>t;
        REP(i,t.length()){
            mp[t[i]]++;
        }
        set<int> se;
        int y=0,w=0;
        REP(i,s.length()){
            if(mp[s[i]]>0){
                y++;
                mp[s[i]]--;
                se.insert(i);
            }
        }
        REP(i,s.length()){
            if(se.find(i)==se.end()){
                if(isupper(s[i])){
                    char c=tolower(s[i]);
                    if(mp[c]>0){
                        w++;
                        mp[c]--;
                    }
                }
                else{
                    char c=toupper(s[i]);
                    if(mp[c]>0){
                        mp[c]--;
                        w++;
                    }
                }
            }
        }
        cout<<y<<" "<<w;
    }
    return 0;
}