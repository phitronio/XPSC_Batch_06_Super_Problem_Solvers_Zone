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
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b;
    for(auto &u: a)
    {
        cin >> u;
        b.push_back(u);
    }

    if(k <= 2)
    {
        cout << "YES\n";
        return;
    }

    sort(b.begin(), b.end());

    int val = b[k - 2];

    deque<int> dq;

    for(auto u: a)
    {
        if(u <= val)
        {
            dq.push_back(u);
        }
    }

    int cnt = dq.size() - (k - 1);

    while(dq.size() > 1)
    {
        if(dq.front() == dq.back())
        {
            dq.pop_back();
            dq.pop_front();
        }
        else if(cnt && dq.front() == val)
        {
            dq.pop_front();
            cnt--;
        }
        else if(cnt && dq.back() == val)
        {
            dq.pop_back();
            cnt--;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";




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
