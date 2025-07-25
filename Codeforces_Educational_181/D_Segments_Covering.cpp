#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define HA cout << "YES" << '\n';
#define NA cout << "NO" << '\n';
#define nl '\n'
#define mod 998244353
#define N 500005

ll fx[] = {0, 0, 1, -1, 1, 1, -1, -1};
ll fy[] = {1, -1, 0, 0, -1, 1, -1, 1};

ll PowerMod(ll a, ll n)
{
   if(n==0) return 1;
   ll x=PowerMod(a,n/2);
   if(n%2==0) return (x*x)%mod;
   return ((x*x)%mod*a)%mod;
}

ll InverseMod(ll a)
{
   return PowerMod(a%mod,mod-2);
}


int main()
{
    FAST;
    ll n, m;
    cin >> n >> m;

    ll quotient = 1, dhorlam_nai = 1;
    vector<ll> jodi_thake(n + 1);
    vector<vector<pair<ll,ll>>> ekhane_shesh(m + 1);

    for(int i = 1; i <= n; i++)
    {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;

        quotient = (quotient * q) % mod;
        ll diff = q - p;
        dhorlam_nai = (dhorlam_nai * diff) % mod;
        jodi_thake[i] = (p * InverseMod(diff)) % mod;
        ekhane_shesh[r].push_back({i, l});
    }

    vector<ll> dp(m + 1, 0);
    dp[0] = 1;

    for(ll i = 1; i <= m; i++)
    {
        for(auto [idx, l]: ekhane_shesh[i])
        {
            dp[i] += (jodi_thake[idx] * dp[l - 1]);
            dp[i] %= mod;
        }
    }

    cout << (((dp[m] * dhorlam_nai) % mod) * InverseMod(quotient)) % mod<< "\n";

    return 0;
}
