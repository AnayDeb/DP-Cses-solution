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
	int n; cin>>n;
	const int mod=1e9+7;
	vi dp(n+1,0);
	dp[0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=6;++j){
			if(j<=i) dp[i]=(dp[i]+dp[i-j])%mod; 
		}
	}
	cout<<dp[n]<<endl;
}

int32_t main() {
    fast;

    int t = 1;
    while(t--) solve();

    return 0;
}

