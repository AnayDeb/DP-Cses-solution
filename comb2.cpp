/*
 * -> Anay Deb
 * -> "Everything is EASY... just needs a little time!"
 * -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;

using pi=pair<int,int>;
using vi=vector<int>;
using vii=vector<pair<int,int>>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define endl '\n'


// ---- GCD -----
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

// ----- LCM -----
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ------ PRIME CHECK -----
bool isPrime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return false;
    return true;
}
// ------- SOLVE FUNCTION ------
/*
   Observations:-
   -> These is a Cses combination problem-
   -> These is 2d dp where we need to calculate the number of ways
   we get a sum of x with the coins in a ordered_way which means
   we cannot use coins like 5,2,2 ,we have to use it like 2,2,5 to
   get the sum 9.
   -> We define a 2d dp where dp[i][j] defines the number of ways to 
   get sum j with coins greater than indices i can be used or has
   been used.
   -> We would return the dp[0][x], which means every coins is used 
   and the no.s of ways to get the sum x is dp[0][x].
*/
void solve() {
    const int mod=1e9+7;
    int n,x;
    cin>>n>>x;

    vi a(n);
    rep(i,0,n-1) cin>>a[i];

    vector<vi> dp(n+1,vi (x+1,0));
    rep(i,0,n-1) dp[i][0]=1;

    per(i,n-1,0){
        rep(sum,1,x){
            int skip=dp[i+1][sum];
            
            int take=0;
            if(sum>=a[i]){
                take=dp[i][sum-a[i]];
            }

            dp[i][sum]=(skip+take)%mod;
        }
    }

    cout<<dp[0][x]<<endl;
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