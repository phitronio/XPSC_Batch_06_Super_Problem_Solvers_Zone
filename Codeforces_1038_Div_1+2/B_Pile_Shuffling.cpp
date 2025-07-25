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

    ll total_move = 0, lagbe = 0, ache = 0;

    for(int i = 1; i <= n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > d)
        {
            total_move += (b - d);
            total_move += a;

            if(a > c)
                ache += (a - c);
            else
                lagbe += (c - a);
        }
        else if(c > a)
        {
            lagbe += (c - a);
        }
    }

    cout << total_move + lagbe - ache << "\n";
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
