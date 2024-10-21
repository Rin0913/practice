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
    int n, m, ans = 0; cin >> n >> m;
    REP(i, n) {
        ans += pow(m, gcd(i, n));
        ans %= MOD;
    }
    ans *= pow(n, MOD - 2);
    ans %= MOD;
    cout << ans;
    return 0;
}

// Using Burnside’s Lemma.
