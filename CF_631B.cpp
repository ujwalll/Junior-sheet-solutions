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
int a[5005][5005];
map<int,ppi> mp1,mp2;
int main(){
    int tc=1;
    // cin>>tc;
    while(tc--){
        int n,m,k;
        cin>>n>>m>>k;
        for1(i,k){
            int t,r,ai;
            cin>>t>>r>>ai;
            r--;
            if(t==1){
                mp1[r]={i,ai};
            }
            else {
                mp2[r]={i,ai};
            }
        }
        rep(i,n){
            rep(j,m){
                if(mp1[i].first >= mp2[j].first)
                a[i][j]=mp1[i].second;
                else a[i][j]=mp2[j].second;
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}