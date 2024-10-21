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
    int n,m; cin>>n>>m;
    int l = 1;
    int ind[n+2] = {0}, a[n+1] = {0};
    ind[n+1] = n+1;
    for (int i = 1; i <= n; i++) {
		int x; cin>>x;
		ind[x] = i;
		a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++) {
		if (l > ind[i]) 
		c++;
		l = ind[i];
    }
    while(m--) {
		int x,y; cin>>x>>y;
		int r = a[x], s = a[y];
		swap(a[x], a[y]);
		if (r != 1 and ind[r-1] <= ind[r] && ind[r-1] > y) c++;
		if (r != 1 and ind[r-1] > ind[r] && ind[r-1] <= y) c--;
		if (r != n and ind[r] <= ind[r+1] && y > ind[r+1]) c++;
		if (r != n and ind[r] > ind[r+1] && y <= ind[r+1]) c--;
		ind[r] = y;
		if (s != 1 and ind[s-1] <= ind[s] && ind[s-1] > x) c++;
		if (s != 1 and ind[s-1] > ind[s] && ind[s-1] <= x) c--;
		if (s != n and ind[s] <= ind[s+1] && x > ind[s+1]) c++;
		if (s != n and ind[s] > ind[s+1] && x <= ind[s+1]) c--;
		ind[s] = x;
		cout<<c<<"\n "[m == 0];
    }
}

