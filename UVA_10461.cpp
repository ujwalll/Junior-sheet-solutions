#include <bits/stdc++.h>
using namespace std;

#define llint long long
#define pb push_back

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

llint v, e;
cin >> v >> e;
llint t = 1;
while (v != 0 || e != 0)
{
    llint arr[v+1];
    for (int i = 1; i <= v; i++)    cin >> arr[i];

    llint sum = 0;
    for (int i = 1; i <= v; i++)    sum += arr[i];

    vector<llint> adj1[v+1];
    bool vis1[v+1];
    vector<llint> adj2[v+1];
    bool vis2[v+1];

    while (e--)
    {
        llint x, y;
        cin >> x >> y;
        adj1[x].pb(y);
        adj2[y].pb(x);
    }

    cout << "Case #" << t++ << ":" << endl;

    llint q;
    cin >> q;
    while (q--)
    {
        for (llint i = 1; i <= v; i++)
        {
            vis1[i] = false;
            vis2[i] = false;
        }

        llint s;
        cin >> s;

        llint mint = -arr[s];
        queue <llint> q1;
        vis1[s] = true;
        q1.push(s);
        while (!q1.empty())
        {
            llint p = q1.front();
            q1.pop();
            mint += arr[p];
            for (llint i = 0; i < adj1[p].size(); i++)
            {
                llint c = adj1[p][i];
                if (vis1[c] == false)
                {
                    q1.push(c);
                    vis1[c] = true;
                }
            }
        }

        llint maxt = sum;
        queue <llint> q2;
        vis2[s] = true;
        q2.push(s);
        while (!q2.empty())
        {
            llint p = q2.front();
            q2.pop();
            maxt -= arr[p];
            for (llint i = 0; i < adj2[p].size(); i++)
            {
                llint c = adj2[p][i];
                if (vis2[c] == false)
                {
                    q2.push(c);
                    vis2[c] = true;
                }
            }
        }

        cout << maxt - mint << endl;
    }
    cout << endl;
    cin >> v >> e;
}

}
