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
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=1;
        string nb="ujwal";
        string x;
        ll cnt=0;
        REP(j,n)
        {
            cin>>x;
            if(x.length()==1 && x[0]=='0')
            return cout<<0,0;
            int o=0,z=0,e=0;
            REP(i,x.length())
            {
                if(x[i]=='0')z++;
                else if(x[i]=='1')o++;
                else e++;
            }
            if(e==0 && o<=1)
            cnt+=z;
            else nb=x;
        }
        if(nb=="ujwal")cout<<1;
        else
        cout<<nb;
        while(cnt--)cout<<0;
    }
    return 0;
}