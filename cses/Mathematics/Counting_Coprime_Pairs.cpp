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

const int MAX = 1e6 + 5;

int pf[MAX], m[MAX], cur[MAX];

void gen_primes() {
    // pf[i] would be the least prime factor of i.
    for(int i = 2; i < MAX; i++) {
        if(!pf[i]) {
            for(int j = i; j < MAX; j += i)
                pf[j] = i;
        }
    }
}

void gen_mobius() {
    m[1] = 1;
    for(int i = 2; i < MAX; i++) {
        if(pf[i / pf[i]] == pf[i]) m[i] = 0; // pf[i] squared.
        else m[i] = -1 * m[i / pf[i]]; // 1 prime factor more.
    }
}

int32_t main(){
    io_o(); gen_primes(); gen_mobius();
    int n, ans = 0; cin >> n;
    REP(i, n) {
        int x; cin >> x;
        cur[x]++;
    }
    for(int gcd = 1; gcd < MAX; gcd++) {
        int cnt = 0;
        for(int i = gcd; i < MAX; i += gcd)
            cnt += cur[i];
        ans += m[gcd] * cnt * (cnt - 1) / 2;
    }
    cout << ans;
    return 0;
}

