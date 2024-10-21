#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fst first
#define scd second
#define endl "\n"
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define REP(i,n) for(int i = 0; i < n; i++)
#define print1d(a) {for(auto v: a) cout << v << " "; cout << endl;}
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;

int pow(int b, int e, int mod = MOD) {
    int ans = 1;
    while(e) {
        if(e & 1) ans = ans * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return ans;
}

int32_t main(){
    io_o(); 
    int n; cin >> n;
    vector<pii> num; vi pd = {1};
    int a1 = 1, a11 = 1, a2 = 1, a3 = 1;

    while(n--) {
        int x, k; cin >> x >> k;
        num.pb({x, k}),
        a1 *= k + 1, 
        a1 %= MOD, 
        a11 *= k + 1,
        a11 %= MOD - 1, 
        pd.pb(a11),
        a2 *= (pow(x, k + 1) - 1) % MOD * pow(x - 1, MOD - 2) % MOD,
        a2 %= MOD;
    }

    int cnt = num.size(); a11 = 1;
    reverse(ALL(num)); 
    for(auto [x, k]: num) 
        a3 *= pow(x, k * (1 + k) / 2 % (MOD - 1) *
                     (a11 * pd[--cnt] % (MOD - 1)) % (MOD - 1)
                 ),
        a11 *= k + 1, a11 %= MOD - 1,
        a3 %= MOD;

    cout << a1 << " " << a2 << " " << a3;
    return 0;
}

