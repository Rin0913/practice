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

int fpow(int b, int e, int mod = MOD) {
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
    int n, m; cin >> n; m = (n / 2 * 2) * (n / 2 * 2);
    int ans = 0;
    if(n % 2)
        ans = fpow(2, n * n) + fpow(2, m / 2 + n) + 2 * fpow(2, m / 4 + n / 2 + 1);
    else
        ans = fpow(2, m) + fpow(2, m / 2) + 2 * fpow(2, m / 4);
    ans = ans % MOD * fpow(4, MOD - 2) % MOD;
    cout << ans;
    return 0;
}

