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

int pow(int b, int e, int mod) {
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
    while(n--) {
        int a, b, c; cin >> a >> b >> c;
        cout << pow(a, pow(b, c, MOD - 1), MOD) << "\n "[n == 0];
    }
    return 0;
}

/*

Obviously, pow(a, pow(b, c)) % MOD != pow(a, pow(b, c) % MOD) % MOD.

By Fermat's little theorem, pow(a, MOD - 1) % MOD = 1.

Hence, if we want to calculate pow(a, X) when X is large,
we can calculate pow(a, X % (MOD - 1)) instead.

*/
