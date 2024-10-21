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

int n;
vi a;

int ms(int l, int r) {
    
    if(l == r) return 0;

    int mid = (l + r) / 2;
    int ans = 0;
    
    ans += ms(l, mid);;
    ans += ms(mid + 1, r);
    vi tmp;

    int i = l, j = mid + 1;
    while(i <= mid and j <= r) {
        if(a[i] > a[j]) tmp.pb(a[j]), ans += mid - i + 1, j++;
        else tmp.pb(a[i]), i++;
    }
    while(i <= mid) tmp.pb(a[i]), i++;
    while(j <= r) tmp.pb(a[j]), j++;

    for(int idx = l; idx <= r; idx ++) a[idx] = tmp[idx - l];
    return ans;
}

int32_t main(){
    io_o(); 
    cin >> n; 
    a.resize(n);
    REP(i, n) cin >> a[i];
    cout << ms(0, n-1);
    return 0;
}

