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

vi primes;

void gen(int n) {
    vi isPrime(n + 1, true); 

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
            primes.push_back(i);
        }
    }
}

int calc(int x) {
    int ans = 1;
    for (int p: primes) {
		if(p * p > x) break;
        if (x % p == 0) {
            int cnt = 0;
            while (x % p == 0) x /= p, cnt ++;
            ans *= cnt + 1;
        }
    }
    ans *= 1 + (x != 1); // it states that x is prime
    return ans;
}

int32_t main(){
    io_o(); gen(1e6 + 5);
	int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << calc(x) << "\n "[n == 0];
    }
    return 0;
}

