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
    int n; cin >> n;
    vi nums(n); REP(i, n) cin >> nums[i];
    sort(ALL(nums));
    int ans = 1, cur = 0;
    while(cur < n){
        if(ans < nums[cur]){
            cout << ans; 
            return 0;
        } else {
            ans += nums[cur];
        } cur++;
    }
    cout << ans;
    return 0;
}

/*

ans 意味着考慮前 cur 個硬幣的最大值 + 1；所有小於 ans 的金額都是湊的出來的，因此 ans 預設是 1，因爲 0 是我們初始能湊出的唯一金額。

如果 ans < nums[cur]，意味着 ans 到 nums[cur] 之間的數值湊不出來，那最小值是 ans。

如果 ans >= nums[cur]，意味着小於 ans + nums[cur] 的值我們都湊的出來，因爲任何小於 ans 的值我們都湊的出來，我們就能湊一個恰好的值，加上 nums[cur]，使其等於任意一個 ans 到 nums[cur] - 1 的值，因此 ans 更新爲 ans + nums[cur]。

*/

