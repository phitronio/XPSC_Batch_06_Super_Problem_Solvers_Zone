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

    vector<int> a(n), b(n);
    set<int> s;

    for (auto &u : a)
        cin >> u, s.insert(u);
    for (auto &u : b)
        cin >> u;

    int mnb = INT_MAX, mxa = 0;
    for(int i = 0, j = n - 1; i < n; i++, j--)
    {
        mnb = min(mnb, b[i]);

        if(*s.begin() > mnb)
        {
            cout << n - i << nl;
            return;
        }

        if(s.size() == 1 && mxa > mnb)
        {
            cout << n - i << nl;
            return;
        }

        if(s.size() > 1 && mxa > mnb)
        {
            auto it = s.begin();
            it++;
            if(*it > mnb)
            {
                cout << n - i << nl;
                return;
            }
        }

        s.erase(a[j]);
        mxa = max(mxa, a[j]);
    }

    cout << 0 << nl;

    

    
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
