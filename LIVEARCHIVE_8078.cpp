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
    cin>>t;
    int cs=0;
    while(t--){
        cs++;
        cout<<"Case "<<cs<<":\n";
        string s;
        cin>>s;
        int n=s.length();
        vector<int> ans(n+1,0);
        vector<vector<int>> stk(5,{n});
        map<char,int> mp = {{')', 4}, {'}', 1}, {']', 2}, {'>', 3},
            {'(', -4}, {'{', -1}, {'[', -2}, {'<', -3}};
        for(int i=n-1;i>=0;i--){
            int p=mp[s[i]];
            if(p>0){
                stk[p].push_back(i);
            }
            else{
                p=-p;
                int k=stk[p].back();
                bool ok = (k<n);
                for(int j=1;j<=4 && ok;j++){
                    if(stk[j].back() < k)ok=false;
                }
                if(ok){
                    ans[i]=k-i+1;
                    ans[i]+=ans[k+1];
                    stk[p].pop_back();
                }
                else{
                    stk.assign(5,{n});
                }
            }
        }
        ans.pop_back();
        for(auto i:ans)cout<<i<<"\n";
    }
    return 0;
}