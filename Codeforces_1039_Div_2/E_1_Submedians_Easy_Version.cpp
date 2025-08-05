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

ll n, k, lft, rt;
ll a[300005];

bool good(ll m)
{
    vector<ll> prefix(n + 1, 0);

    for(int i = 1; i <= n; i++)
    {
        if(a[i] >= m)
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1] - 1;
    }

    ll mn = 0, mnidx = 1;

    for(int i = k, j = 1; i <= n; i++, j++)
    {
        if(prefix[i] >= mn)
        {
            lft = mnidx;
            rt = i;
            return true;
        }
        if(prefix[j] < mn)
        {
            mn = prefix[j];
            mnidx = j + 1;
        }
    }

    return false;
}

void solve(int tt)
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    ll l = 0, r = n + 1;
    while(l + 1 < r)
    {
        ll m = (l + r) / 2;
        if(good(m))
            l = m;
        else 
            r = m;
    }

    cout << l << " " << lft << " " << rt << "\n";
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
