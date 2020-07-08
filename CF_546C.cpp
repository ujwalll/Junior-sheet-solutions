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
    while(t--)
    {
        int n;cin>>n;
        queue<int> p1,p2;
        int k1,k2;
        cin>>k1;
        REP(i,k1){
            cin>>k2;
            p1.push(k2);
        }
        cin>>k1;
        REP(i,k1){
            cin>>k2;
            p2.push(k2);
        }
        int cnt=0;
        while(!p1.empty() && !p2.empty()){
            int tp1=p1.front(),tp2=p2.front();
            p1.pop(),p2.pop();
            if(cnt>10000)return cout<<-1,0;
            if(tp1>tp2){
                p1.push(tp2);
                p1.push(tp1);
                cnt++;
            }
            else
            {
                p2.push(tp1);
                p2.push(tp2);
                cnt++;
            }
        }
        cout<<cnt<<" ";
        if(p1.empty())cout<<2;
        else cout<<1;
    }
    return 0;
}