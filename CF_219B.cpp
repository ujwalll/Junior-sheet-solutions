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

int main()
{
    fastio();
    ll s,n,c=1,need=0,cur=1;
    string s1;
    cin>>s>>n;
    s1=to_string(s);
    c=s;
    while(c>=10){
           need=0;
           while(c%10 !=9)
           {
               c--;
               need++;
           }
           need*=cur;
           if(n>=need)
           {
               n-=need;
               s-=need;
           }
            else break;
       cur*=10;
       c/=10;
    }
    cout<<s;
   return 0;
}