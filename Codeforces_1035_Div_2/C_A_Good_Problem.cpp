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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;

    if(n & 1)
    {
        cout << l << '\n';
        return;
    }

    if(n == 2)
    {
        cout << -1 << '\n';
        return;
    }

    ll x = 1;
    while(x <= l)
    {
        x *= 2LL;
    }

    if(x > r)
    {
        cout << -1 << '\n';
    }
    else if(k >= n - 1)
    {
        cout << x << '\n';
    }
    else
        cout << l << '\n';



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
