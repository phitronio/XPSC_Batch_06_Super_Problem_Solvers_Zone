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

    vector<pair<pair<int, int>, int>> points;

    for(int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back({{x, y}, i});
    }

    sort(points.begin(), points.end());

    vector<pair<pair<int, int>, int>> xsmall, xbig;

    for(int i = 0; i < n/ 2; i++)
    {
        swap(points[i].first.first, points[i].first.second);
        xsmall.push_back(points[i]);
    }

    for(int i = n/2; i < n; i++)
    {
        swap(points[i].first.first, points[i].first.second);
        xbig.push_back(points[i]);
    }

    sort(xsmall.begin(), xsmall.end());
    sort(xbig.begin(), xbig.end());
    reverse(xbig.begin(), xbig.end());

    for(int i = 0; i < n/ 2; i++)
    {
        cout << xsmall[i].second << " " << xbig[i].second << "\n";
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
