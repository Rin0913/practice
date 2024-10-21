#include<bits/stdc++.h>
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
    int n; cin >> n;
    vi nums(n);
    REP(i, n) cin >> nums[i];
    sort(ALL(nums));
    int mid;
    if(n % 2) mid = nums[n / 2];
    else mid = (nums[n / 2] + nums[(n - 1) / 2]) / 2;
    int ans = 0;
    REP(i, n) ans += abs(nums[i] - mid);
    cout << ans;
    return 0;
}
