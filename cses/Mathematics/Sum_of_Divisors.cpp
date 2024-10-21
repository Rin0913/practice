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
const int MUL2 = (MOD + 1) / 2;

int calc_nxt(int n, int x) {
    int l = x, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(n / x > n / mid) r = mid;
        else l = mid + 1;
    }
    return l - (n / x != n / l);
}

int32_t main(){
    io_o(); 
    int n; cin >> n;
    int m = sqrt(n) + 1, ans = 0;
    for(int i = 1; i < m; i++) {
        ans += n / i * i, ans %= MOD;
    }
    while(m <= n) {
        int nxt = min(n, calc_nxt(n, m));
        int num = nxt - m + 1;
        int sum = num % MOD * ((m + nxt) % MOD) % MOD * MUL2 % MOD;
        ans += (n / m) % MOD * sum % MOD, ans %= MOD;
        m = nxt + 1;
    }
    cout << ans;
    return 0;
}

/*  Each iteration, it would go through m to nxt, for nxt is the 
 *  largest number s.t n // m == n // nxt.
 *  
 *  The number of possibilities of n / x is sqrt(n),
 *  so we just need to do the iteration for sqrt(n) times,
 *  and each time requires log(n) for binary searching.
 *
 *  Hence the time complexity is O(sqrt(n)log(n)).
 */
