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

int n, k, ans = 0;
vi primes;

void calc(int i = 0, int prod = 1, int cnt = 1) {
    if(i == k) {
        return;
    }
    if(prod <= (n + primes[i] - 1) / primes[i])
        calc(i + 1, prod * primes[i], !cnt), 
        ans += n / (prod * primes[i]) * (cnt * 2 - 1);
    calc(i + 1, prod, cnt);
}

int32_t main(){
    io_o(); 
	cin >> n >> k; primes.resize(k);
    REP(i, k) cin >> primes[i];
    calc();
    cout << ans;
    return 0;
}

