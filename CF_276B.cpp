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
int a[26];
int main()
{
    fastio();
    int t=1;
    // cin>>t;
    while(t--)
    {
        string s,u;
        cin>>s;
        u=s;
        int n=s.length();
        REP(i,n)
        {
            a[s[i]-'a']++;
        }
        int turn=0;
        while(1)
        {
            int o=0,e=0;
            int move=turn;
            REP(i,26){
                if(a[i]>0 && a[i]&1)
                o++;
                else if(a[i]>0)e++;
            }
            if(o==1)break;
            else if(o==2 && e==0)
            {
                turn^=1;
                break;
            }
            else if(o==2 && e!=0)
            {
                REP(i,26){
                    if(a[i]>0 && a[i]%2==0){
                        a[i]--;
                        turn^=1;
                        break;
                    }
                }
            }
            else if(o>2){
                REP(i,26){
                    if(a[i]>0 && a[i]&1){
                        a[i]--;
                        turn^=1;
                        break;
                    }
                }
            }
            else if(!o)break;
        }
        if(turn)cout<<"Second";
        else cout<<"First";
    }
    return 0;
}