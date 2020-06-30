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

int main() {
    double a,x,y;
    cin>>a>>x>>y;
    if((int)y%(int)a==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        int l=y/a;
        l++;
        if(l%2==1 && l!=1)
        {
            if(x>-a && x<a && x!=0)
            {
               int k=l/2;
               k*=3;
               if(x>0)
               cout<<k+1<<endl;
               else
               cout<<k<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
        }
        else
        {
            double k=a/2;
            if(x>(-a/2) && x<a/2)
            {
                if(l==1 || l==2)
                {
                    cout<<l<<endl;
                }
                else
                {
                   int p=l/2;
                   p--;
                   cout<<l+p<<endl;
                }
            }
            else
            {
                cout<<-1<<endl;
            }
        }
    }
}