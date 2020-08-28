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
enum Color { white, black };
const int mx=105;
vector<int> adj[mx];
vector<Color> curColor;
vector<int> ans,ch;
int n,k;
bool check(int cur){
    for(auto i:adj[cur]){
        if(i==cur || curColor[i]==black)
        return false;
    }
    return true;
}

void solve(int cur){
    if(cur==n){
        if(ch.size()>ans.size()){
            ans=ch;
        }
        return;
    }
    //Turn into black if possible
    if(check(cur)){
        curColor[cur]=black;
        ch.push_back(cur);
        solve(cur+1);
        ch.pop_back();
        curColor[cur]=white;
    }
    solve(cur+1);//Leave it white
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int x,y;
        REP(i,n){
            adj[i].clear();
        }
        ch.clear();
        ans.clear();
        curColor = vector<Color>(n,white);
        REP(i,k){
            cin>>x>>y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        solve(0);
        cout<<ans.size()<<"\n";
        string space = "";
        for(auto i:ans)cout<<space<<i+1,space=" ";
        cout<<"\n";
    }
}