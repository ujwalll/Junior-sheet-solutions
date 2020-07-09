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

long long C(int n,int m){
    long long z = 1;
    for(int i=0; i<m; i++)
        z = z*(n-i)/(i+1);
    return z;
}

int main(){
    int n,m,p; 
    cin>>n>>m>>p;
    cout<<C(n+m,p)-C(n,p)-C(m,p)-C(n,1)*C(m,p-1)-C(n,2)*C(m,p-2)-C(n,3)*C(m,p-3);
    return 0;
}