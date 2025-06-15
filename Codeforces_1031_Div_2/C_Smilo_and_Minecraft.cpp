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
    int n, m, k;
    cin >> n >> m >> k;

    char s[n + 2][m + 2];
    int prefix_sum[n + 2][m + 2];
    memset(prefix_sum, 0, sizeof prefix_sum);

    ll sum = 0;


    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            if(s[i][j] == 'g')
                prefix_sum[i][j] = 1, sum++;

        }
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //     {
    //         cout << prefix_sum[i][j] << " ";
    //     }
    //     cout << nl;
    // }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            prefix_sum[i][j] += prefix_sum[i - 1][j];
            prefix_sum[i][j] += prefix_sum[i][j - 1];
            prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
        }
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 1; j <= m; j++)
    //     {
    //         cout << prefix_sum[i][j] << " ";
    //     }
    //     cout << nl;
    // }


    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i][j] == '.')
            {
                int mxr = min(n, i + k - 1);
                int mxc = min(m, j + k - 1);

                int mnr = max(1, i - k + 1);
                int mnc = max(1, j - k + 1);

                int ei_ongshe_gold_ache = prefix_sum[mxr][mxc] - prefix_sum[mnr - 1][mxc] - prefix_sum[mxr][mnc - 1] + prefix_sum[mnr - 1][mnc - 1];
                ans = max(ans, sum - ei_ongshe_gold_ache);
            }
        }
    }

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
