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
#define N 5005

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};


ll n, m;
ll dp[N][N];

ll f(int index, int neya_hoiche)
{
    if(index > n)
    {
        return 1;
    }

    if(dp[index][neya_hoiche] != -1)
        return dp[index][neya_hoiche];

    ll nibo_na = f(index + 1, neya_hoiche);

    ll nibo = ((n - index + 1) * (index - neya_hoiche) * f(index + 1, neya_hoiche + 1)) % m;

    return dp[index][neya_hoiche] = (nibo + nibo_na) % m;
}

void solve(int tt)
{
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << f(1,0) << "\n";
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
