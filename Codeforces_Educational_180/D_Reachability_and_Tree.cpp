#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define HA cout << "YES" << '\n';
#define NA cout << "NO" << '\n';
#define nl '\n'
#define mod 1000000007
#define N 500005

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};

void solve(int tt)
{
    int n;
    cin >> n;
    vector<int> adj[n + 2];

    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
    {
        if(adj[i].size() == 2)
        {
            cout << "YES\n";

            // cout << i << nl;

            queue<int> q;
            vector<int> ans(n + 2, -1);
            ans[i] = 0;
            ans[adj[i][0]] = 0;
            ans[adj[i][1]] = 1;

            cout << i << " " << adj[i][0] << "\n";
            cout << adj[i][1] << " " << i << "\n";

            q.push(adj[i][0]);
            q.push(adj[i][1]);
        
            while(q.size())
            {
                auto v = q.front();
                // cout << v << "->";
                q.pop();
        
                for(auto c: adj[v])
                {
                    if(ans[c] != -1)
                    continue;
                    
                    // cout << c << ", ";
                    if(ans[v])
                    {
                        cout << v <<  " " << c << "\n";
                    }
                    else
                        cout << c << " " << v << "\n";
                    
                    ans[c] = (ans[v] ^ 1);
                    q.push(c);
                }

                // cout << nl;
            }

            return;
        }

    }

    cout << "NO\n";
    
}

int main()
{
    FAST;
    int tc = 1;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }

    return 0;
}
