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
    vector<int> b(n);

    for(auto &u: b)
        cin >> u;

    int lc = 1;
    for(int i = 1; i < n; i++)
    {
        if(b[i] % b[i - 1] != 0)
        {
            int y = gcd(b[i], b[i - 1]);
            int x = b[i - 1] / y;

            lc = lcm(x, lc);
        }
    }

    cout << lc << '\n';


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
