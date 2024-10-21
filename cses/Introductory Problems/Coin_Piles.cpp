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

int32_t main(){
    io_o(); 
    // x -> # of operation for removing 2 left coins and 1 right coin
    // y -> # of operation for removing 1 left coin and 2 right coins
    
    // 2x + y = a, x + 2y = b
    // 3x + 3y = a + b, (a + b) / 3 = x + y

    // Make sure x and y are integers and non-negative
    
    int n; cin >> n;

    while(n--) {
        int a, b, k; cin >> a >> b, k = (a + b) / 3;
        
        if((a + b) % 3 == 0 and a >= k and b >= k)
            cout << "YES" << "\n "[!n];
        else
            cout << "NO" << "\n "[!n];
            // a technique for no breakline in the end here :)
    }

    return 0;
}

