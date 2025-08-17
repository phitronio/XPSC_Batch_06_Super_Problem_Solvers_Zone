#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200005
#define mod 1000000007

vector<ll> adj[N];
ll fact[N];


void solve()
{
    ll n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        adj[i].clear();

    for(int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if(n == 2)
    {
        cout << 2 << '\n';
        return;
    }

    vector<ll> leaf(n + 1, 0);

    for(int i = 1; i <= n; i++)
        if(adj[i].size() == 1)
            leaf[i] = 1;

    vector<ll> v;
    ll ans = 1;

    for(int i = 1; i <= n; i++)
    {
        if(leaf[i] == 1)
            continue;
        
        ll cnt = 0;
        for(auto u: adj[i])
            if(leaf[u] == 0)
                cnt++;

        v.push_back(cnt);
        ans = (ans * fact[adj[i].size() - cnt]) % mod;
    }

    sort(v.begin(), v.end());

    if(v.size() == 1 && v[0] == 0)
        cout << (fact[n - 1] * 2LL) % mod << '\n';
    else if(v.size() == 2 && v[0] == 1 && v[1] == 1)
        cout << (ans * 4LL) % mod << '\n';
    else if(v.size() > 2 && v[0] == 1 && v[1] == 1 && v[2] == 2 && v.back() == 2)
        cout << (ans * 4LL) % mod << '\n';
    else
        cout << 0 << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for(ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }


    return 0;
}
