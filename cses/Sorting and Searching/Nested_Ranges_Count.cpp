#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
/**
order_of_key(k) : nums strictly smaller than k
find_by_order(k): index from 0
**/
#pragma GCC optimize("O3","unroll-loops")
#define IO cin.tie(0), ios::sync_with_stdio(0)
using namespace std;
#define int long long
typedef pair<int,int> pii;
 
int32_t main(){
    IO;
    int t, r;
    cin >> t;
    vector<int> a(t), b(t), aa(t), bb(t);
    vector<pii> v(t);
    map<pii,int> mp;
 
    for(auto &[l, r]: v){
        cin >> l >> r;
        r *= -1;
        mp[{l,-r}] = mp.size();
    }
    sort(v.begin(),v.end());
 
    for(auto &n: v) n.second *= -1 ;
    
    multiset cnt;
    r = v[0].second;
    for(int i = 0; i < t; i++){
        cnt.insert(v[i].second);
        a[i] = cnt.size() - cnt.order_of_key(v[i].second)-1;
    }
 
    cnt.clear();
    r = v.back().second;
    for(int i = v.size() - 1 ; i > -1 ; i--){
        cnt.insert(v[i].second);
        b[i] = cnt.order_of_key(v[i].second+1)-1;
    }
 
    for(int i = 0; i < t; i++){
        aa[mp[v[i]]] = a[i];
        bb[mp[v[i]]] = b[i]; 
    }
    for(int i = 0; i < t; i++) cout << bb[i] << " " ;
    cout << endl ;
    for(int i = 0; i < t; i++) cout << aa[i] << " " ;
    cout << endl ;
}
