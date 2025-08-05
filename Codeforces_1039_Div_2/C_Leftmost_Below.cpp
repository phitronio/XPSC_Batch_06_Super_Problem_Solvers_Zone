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
    ll n;
    cin >> n;
    vector<ll> b(n);

    for(auto &u: b)
        cin >> u;

    ll mn = b[0];
    for(int i = 1; i < n; i++)
    {
        if(b[i] >= mn * 2)
        {
            cout << "NO\n";
            return;
        }
        mn = min(mn, b[i]);
    }

    cout << "YES\n";
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
