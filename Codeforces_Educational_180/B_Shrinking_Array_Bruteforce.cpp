#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define nl '\n'

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};

void solve(int tt)
{
    ll n;
    cin >> n;
    ll a[n + 2];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    ll ans = LLONG_MAX;
    for(ll i = 1; i <= n; i++)
    {
        ll mn = LLONG_MAX;
        ll l = 1e9, r = -1e9;
        for(ll j = i - 1; j >= 1; j--)
        {
            l = min(l , a[j]);
            r = max(r, a[j]);

            if(r < a[i] - 1 || l > a[i] + 1)
                continue;
            mn = min(mn, i - j - 1);
                break;
        }

        l = 1e9, r = -1e9;
        for(ll j = i + 1; j <= n; j++)
        {
            l = min(l , a[j]);
            r = max(r, a[j]);

            if(r < a[i] - 1 || l > a[i] + 1)
                continue;
            mn = min(mn, j - i - 1);
                break;
        }

        ans = min(ans, mn);
    }

    if(ans == LLONG_MAX) 
        cout << -1 << nl;
    else 
        cout << ans << nl;
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
