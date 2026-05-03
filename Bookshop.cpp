/*
  Anay Deb
  "Everything is EASY... just needs a little time!"
  Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<pair<int,int>>;
using vil = vector<ll>;
using pil = pair<ll,ll>;
using viil = vector<pair<ll,ll>>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define Ceil(a,b) ((a+b-1)/b)
#define endl '\n'

// ------- SOLVE FUNCTION ------
/*
    ?Problem:- 
    Here the problem is classic knapsack problem where we have
    a limited price through which we can pick items , we need to 
    try to take as many items as possible.


    !Observations:-

    Here dp[i][j] denotes no. of book pages we can buy with the
    price j.

    !similarly, the transition->
        dp[i][j]=max(dp[i-1][j],page[i]+dp[i-1][j-price[i]]).
*/
void solve() {
    int n,x;
    cin>>n>>x;

    vi price(n+1),page(n+1);
    rep(i,1,n) cin>>price[i];
    rep(i,1,n) cin>>page[i];

    vector<vi> dp(n+1,vi (x+1,0));

    rep(i,1,n){
        rep(j,1,x){
            dp[i][j]=max(dp[i-1][j],(j>=price[i]?dp[i-1][j-price[i]]+page[i]:0));
        }
    }

    debug(dp);
    cout<<dp[n][x]<<endl;
}

int32_t main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}