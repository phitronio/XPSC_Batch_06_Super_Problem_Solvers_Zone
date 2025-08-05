#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n, s;
    cin >> n >> s;

    ll a_sum = 0;
    vector<ll> pre(3, 0);

    for(int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        pre[x]++;
        a_sum += x;
    }

    if(s < a_sum || s == a_sum + 1)
    {
        for(int i = 1; i <= pre[0]; i++)
            cout << 0 << " ";
        for(int i = 1; i <= pre[2]; i++)
            cout << 2 << " ";
        for(int i = 1; i <= pre[1]; i++)
            cout << 1 << " ";
        cout << '\n';
    }
    else
        cout << -1 << '\n';


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
