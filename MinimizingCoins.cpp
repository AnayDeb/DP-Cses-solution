#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);

#define int long long
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,a,b) for(int i = (a); i < (b); i++)

// ===== GCD =====
int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

// ===== LCM =====
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// ===== PRIME CHECK =====
bool isPrime(int n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;
    for(int i = 3; i * i <= n; i += 2)
        if(n % i == 0) return false;
    return true;
}

// ===== SOLVE FUNCTION =====
void solve() {
	int n,s; cin>>n>>s;
	vi a(n);
	rep(i,0,n) cin>>a[i];
	vi dp(s+1,LLONG_MAX);
	dp[0]=0;//min no. of ways to get the sum 0; 
	rep(i,1,s+1){
		rep(j,0,n){
			if(a[j]<=i and dp[i-a[j]]!=LLONG_MAX) dp[i]=min(dp[i],1+dp[i-a[j]]);
		}
	}
	cout<<((dp[s]==LLONG_MAX)?-1:dp[s])<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}

