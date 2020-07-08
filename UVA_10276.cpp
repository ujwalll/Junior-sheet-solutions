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
const int maxn=55;
ll a[maxn];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        bool flag=false;
        ll i=1;
        while(1){
            if(flag==true)break;
            flag=true;
            for1(j,n){
                if(!a[j]){
                    a[j]=i;
                    i++;
                    flag=false;
                    break;
                }
                ll u=a[j]+i;
                u=sqrt(u);
                if(u*u == (a[j]+i)){
                    a[j]=i;
                    i++;
                    flag=false;
                    break;
                }
            }
            //cout<<i<<"\n";
        }
        if(i>1e5)cout<<"-1\n";
        else cout<<i-1<<"\n";
    }
    return 0;
}