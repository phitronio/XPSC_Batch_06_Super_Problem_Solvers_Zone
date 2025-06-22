#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define FAST ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


void solve(int tt)
{
    int n, s;
    cin >> n >> s;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;

        if(x == y && dx == dy)
            ans++;
        else if(x + y == s && dx != dy)
            ans++;
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
