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

int main(){
    int tc=1;
    // cin>>tc;
    while(tc--){
        int a1,a2,a3,a4,a5,a6;
        cin>>a1>>a2>>a3>>a4>>a5>>a6;
        cout<<(a1+a2+a3)*(a1+a2+a3) - (a1*a1) - (a3*a3) - (a5*a5);
    }
}