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

//Just call FactMod() in main function
ll Fact[N];
void FactMod()
{
   Fact[0]=1;
   for(ll i=1;i<N;i++)
   {
       Fact[i]=((Fact[i-1]*i)%mod);
   }
}

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



void solve(int tt)
{
    ll a, b, k;
    cin >> a >> b >> k;

    ll n = (a - 1) * k + 1;

    ll m = 1;
    
    for(ll i = n; i >= n - a + 1; i--)
    {
        m = (m * (i % mod)) % mod;
    }


    m *= InverseMod(Fact[a]);
    m %= mod;

    m = (m * k) % mod;
    m = (m * (b - 1)) % mod;
    m += 1;
    m %= mod;

    cout << n % mod << ' ' << m << nl;
    


}

int main()
{
    FAST;
    int tc = 1;
    cin >> tc;
    FactMod();
    for (int tt = 1; tt <= tc; tt++)
    {
        solve(tt);
    }

    return 0;
}
