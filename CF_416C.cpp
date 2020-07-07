#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)
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
struct re{
    int ind,p,am;
};
vector<re> v;
bool comp(const re a, const re b){
    return a.am > b.am;
}
int main()
{
    fastio();
    int t=1;
    // cin>>t;
    while(t--)
    {
        int n;cin>>n;
        REP(i,n){
            int x,y;
            cin>>x>>y;
            v.push_back({i+1,x,y});
        }
        int k;cin>>k;
        vector<ppi> a;
        REP(i,k){
            int x;
            cin>>x;
            a.push_back({x,i+1});
        }
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        sort(v.begin(),v.end(),comp);
        int i=0,j=0;
        vector<ppi> ans;
        ll sum=0; 
        while(i<n && a.size()){
            if(v[i].p > a[j].first){
                i++;
                continue;
            }
            while(j<a.size() && a[j].first >= v[i].p){
                j++;
            }
            j--;
            sum+=v[i].am;
            ans.push_back({v[i].ind,a[j].second});
            a.erase(a.begin()+j);
            i++;
            j=0; 
        }
        cout<<ans.size()<<" "<<sum<<"\n";
        for(auto i:ans)cout<<i.first<<" "<<i.second<<"\n";
     }
    return 0;
}