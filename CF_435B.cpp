#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int main()
{
    ll l=0,t=0,k,m = 0,x = 0,c=0,n;

    string s,s1="";

    cin>>s>>k;
    n = s.size();
    s1 += s;
    sort(s1.begin(),s1.end());
    reverse(s1.begin(),s1.end());

    while(1)
    {
        c = 0,x = s[t] - '0';

        for(ll i = t+1; i < min(n,t+1+(k-l)); i++)
        {
            if(s[i]-'0' > x)
            {
                m = i,x = s[i]-'0';
                c = 1;
            }
        }

        if(c==1)
        {
            for(ll i = m; i > t; i--)
            {
                swap(s[i],s[i-1]);
                l++;
            }
        }

        if(t==s.size()-1 || s==s1 || l==k)
        {
            break;
        }
        t++;
    }

    cout<<s<<endl;
}

