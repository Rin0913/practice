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
    vi pos(n + 1);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for(int i = n; i > 1; i--){
        if(pos[i] <= pos[i - 1]) ans ++;
    }
    cout << ans;
    return 0;
}

/*

舉個例子，如果 4 在 3 的前面，那麼我們就一定要走 2 輪才能帶走他們。

那我們需要考慮例如 5 和 3 嗎？其實不用，因爲我們考慮 5 和 4 的時候，會先把 5 收走，再考慮 4 和 3 的時候，會把 4 收走，如此下去，全部數字都會被收走。

*/

