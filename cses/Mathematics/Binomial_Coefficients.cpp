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

const int MOD = 1e9 + 7, MAX = 1e6 + 5;
int f[MAX];

int pow(int b, int e, int mod = MOD) {
    int ans = 1;
    while(e) {
        if(e & 1) ans = ans * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return ans;
}

void gen_factorial() {
    f[0] = f[1] = 1;
    for(int i = 2; i < MAX; i++)
        f[i] = f[i - 1] * i % MOD;
}

#define mi(x) pow(x, MOD - 2)

int32_t main(){
    io_o(); gen_factorial();
    int n; cin >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        cout << (f[a] * mi(f[a - b]) % MOD * mi(f[b]) % MOD) << "\n "[n == 0];
    }
    return 0;
}

