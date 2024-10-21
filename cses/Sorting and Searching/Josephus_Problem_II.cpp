#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
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
using namespace __gnu_pbds;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bbt;
 
int32_t main(){
    io_o(); 
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
        bbt.insert(i);
    int cnt = 0;
    while(n){
        cnt = (cnt + k) % n;
        int val = *bbt.find_by_order(cnt);
        cout << val << " ";
        bbt.erase(val);
        n--;
    }
 
    return 0;
}
