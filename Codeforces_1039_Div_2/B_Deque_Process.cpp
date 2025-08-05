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
    ll n;
    cin >> n;

    vector<ll> p(n);

    for(auto &u: p)
        cin >> u;

    ll l = 0, r = n - 1, flag = 0;
    string ans;
    while(l <= r)
    {
        if(l == r)
        {
            ans += "L";
        }
        else if(flag == 0)
        {
            if(p[l] < p[r])
                ans += "LR";
            else
                ans += "RL";
        }
        else
        {
            if(p[l] > p[r])
                ans += "LR";
            else
                ans += "RL";
        }

        l++;
        r--;
        flag ^= 1;
    }

    cout << ans << "\n";
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
