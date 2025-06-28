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
    ll n, m;
    cin >> n >> m;

    if(m < n || m > (n * (n + 1)) / 2)
    {
        cout << -1 << '\n';
        return;
    }

    if(m < 2 * n)
    {
        cout << m - n + 1 << '\n';
        for(int i = 2; i <= n; i++)
        {
            cout << 1 << ' ' << i << '\n';
        }
        return;
    }

    cout << n << '\n';
    cout << 1 << ' ' << n << '\n';
    m -= (2 * n - 1);

    for(int i = n - 1; i >= 2; i--)
    {
        if(m >= i - 1)
        {
            cout << i << ' ' << n <<'\n';
            m -= (i - 1);
        }
        else
            cout << 1 << ' ' << i << '\n';
    }
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
