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

    int a[n + 2];

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = -1;

    if(n == 2)
    {
        if(abs(a[1] - a[2]) <= 1)
            cout << 0 << '\n';
        else
            cout << -1 << '\n';

        return;
    }

    for(int i = 2; i < n; i++)
    {
        if(abs(a[i] - a[i - 1]) <= 1 || abs(a[i] - a[i + 1]) <= 1)
        {
            ans = 0;
            break;
        }
        if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
        {
            ans = 1;
        }
    }

    cout << ans << '\n';

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
