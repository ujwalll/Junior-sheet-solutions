#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
const int INF = 1<<29;
const int MOD=1073741824;
//#define pp pair<ll,ll>
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
        vector<int> first,second;
        int x;
        cin>>n;
        ll sumf=0,sums=0;
        int move=0;
        REP(i,n)
        {
            cin>>x;
            if(x>=0)
            {
                first.push_back(x);
                sumf+=x;
            }
            else {second.push_back(abs(x));sums+=abs(x);}
            if(i==n-1)
            {
                if(x>0)move=1;
                else move=0;
            }
        }
        if(sumf>sums)cout<<"first";
        else if(sums>sumf)cout<<"second";
        else
        {
            REP(i,min(first.size(),second.size()))
            {
                if(first[i]>second[i])
                return cout<<"first",0;
                if(second[i]>first[i])
                return cout<<"second",0;
            }
            if(move==1)cout<<"first";
            else cout<<"second";
        }
        
    }
    return 0;
}