#include<bits/stdc++.h>
#define io_o() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fst first
#define scd second
#define endl "\n"
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) x.size()
#define REP(i,n) for(int i = 0; i < n; i++)
#define print1d(a) {for(auto v: a) cout << v << " "; cout << endl;}
#define int ll
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int32_t main(){
    io_o(); 
    int min_sum = 0;
    int sum = 0;
    int ans = -2e9;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        ans = max(ans, sum - min_sum);
        min_sum = min(min_sum, sum);
    }
    cout << ans;
    return 0;
}

