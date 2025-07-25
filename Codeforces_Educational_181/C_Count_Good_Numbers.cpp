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

ll f(ll k, ll l, ll r)
{
    return r / k - (l - 1) / k;
}

void solve(int tt)
{
    ll l, r;
    cin >> l >> r;

    ll count = 0;

    count += f(2, l, r);
    count += f(3, l, r);
    count += f(5, l, r);
    count += f(7, l, r);

    count -= f(6, l, r);
    count -= f(10, l, r);
    count -= f(14, l, r);
    count -= f(15, l, r);
    count -= f(21, l, r);
    count -= f(35, l, r);

    count += f(30, l, r);
    count += f(42, l, r);
    count += f(70, l, r);
    count += f(105, l, r);

    count -= f(210, l, r);

    cout << (r - l + 1) - count << "\n";
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
