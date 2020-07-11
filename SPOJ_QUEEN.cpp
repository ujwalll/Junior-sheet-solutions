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
int n,m;
char a[2000][2000];
int sx,sy,ex,ey;
int dist[2005][2005];
bool isvalid(int x,int y){
    return x>=0 && y>=0 && x<n && y<m && a[x][y]!='X';
}

void solve(){
    dist[sx][sy]=1;
    queue<pp> q;
    q.push({sx,sy});
    while(!q.empty()){
        pp u = q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int x1= u.first + dx[i];
            int y1 = u.second + dy[i];
            while(isvalid(x1,y1)){
                if(dist[x1][y1]==0){
                    dist[x1][y1]=dist[u.first][u.second]+1;
                    q.push({x1,y1});
                }
                else if(dist[x1][y1]!=dist[u.first][u.second]+1)break;
                x1+=dx[i];
                y1+=dy[i];
            }
        }
    }
    cout<<dist[ex][ey]-1<<"\n";
}
int main()
{
    fastio();
    int t=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        REP(i,n){
            REP(j,m){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    sx=i;
                    sy=j;
                }
                else if(a[i][j]=='F'){
                    ex=i;
                    ey=j;
                }
                dist[i][j]=0;
            }
        }
        solve();
    }
    return 0;
}