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

int counter, total;

void hanoi(int n, int a, int b, int c) {
    if(n == 1) {
        counter ++;
        cout << a << " " << c << "\n "[counter == total];
        // we have to keep newline from ending.
        return;
    }
    hanoi(n - 1, a, c, b);
    hanoi(1, a, b, c);
    hanoi(n - 1, b, a, c);
}

int32_t main(){
    io_o(); 
    int n; cin >> n;
    total = pow(2, n) - 1;
    
    cout << total << endl;
    hanoi(n, 1, 2, 3);

    return 0;
}

