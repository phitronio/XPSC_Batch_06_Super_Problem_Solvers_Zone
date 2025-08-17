#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;
    vector<pair<ll,ll>> v;

    for(int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if(x < a[i])
            swap(x, a[i]);
        ans += (x - a[i]);
        v.push_back({a[i], x});
    }

    sort(v.begin(), v.end());

    ll mn = LLONG_MAX;
    for(int i = 1; i < n; i++)
    {
        if(v[i].first <= v[i - 1].second)
        {
            cout << ans << '\n';
            return;
        }
        mn = min(mn, v[i].first - v[i - 1].second);
    }

    cout << ans + mn * 2 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }


    return 0;
}
