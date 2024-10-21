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


int solve(int n, int k) {
    if(n == 1) return 1;

    if(k * 2 <= n) return k * 2;
    if(k * 2 == n + 1) return 1;
    
    int ans = solve(n / 2, k - (n + 1) / 2);
    
    if(n % 2) return ans * 2 + 1;
    else return ans * 2 - 1;
}

int32_t main(){
    io_o(); 
	int n; cin >> n;
	while(n--) {
		int n, k; cin >> n >> k;
        cout << solve(n, k) << "\n "[n == 0];
	}
    return 0;
}


/*

1 2 3 4 5 6 7
  ^   ^   ^
^

it becomes,

n = 3, k = 1

3 5 7

We take the floor of n / 2 on purpose.
So that we can easily convert the index after the operation into the index before that.

1 -> 3
2 -> 5
3 -> 7

For the case n is odd, before = after * 2 + 1.

---

n = 6, k = 5

1 2 3 4 5 6
  ^   ^   ^

it becomes,

1 3 5

Hence, for the case n is even, before = after * 2 - 1.

*/
