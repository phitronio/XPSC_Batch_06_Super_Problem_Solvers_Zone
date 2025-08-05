#include <bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
// ordered_set ms
// ms.order_of_key(k) ~~ Number of items strictly smaller than k .
// ms.find_by_order(k); ~~ K-th element in a set (counting from zero).


void solve()
{
    ll n;
    cin >> n;
    ll p[n];
    ordered_set shamne, pechone;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        pechone.insert(p[i]);
    }

    pechone.erase(p[0]);
    shamne.insert(p[0]);

    ll ans = 0;
    for(int i = 1; i < n - 1; i++)
    {
        pechone.erase(p[i]);
        ll age = shamne.size() - shamne.order_of_key(p[i]);
        ll pore = pechone.size() - pechone.order_of_key(p[i]);
        shamne.insert(p[i]);

        ans += min(age, pore);
    }

    cout << ans << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }


    return 0;
}
