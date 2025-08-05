#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n;
    cin >> n;

    map<ll, pair<ll, ll>>mp;
    for(int i = 1; i <= n; i++)
    {
        ll l, r;
        cin >> l >> r;
        mp[l] = max(mp[l], {r, i});
    }

    cout << mp.size() << '\n';

    for(auto [F, S]: mp)
        cout << S.second << " ";
    cout << '\n';
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
