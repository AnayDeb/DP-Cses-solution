/*
 -> Anay Deb
 -> "Everything is EASY... just needs a little time!"
 -> Lets Fucking GOO!!
 */

#include <bits/stdc++.h>
using namespace std;


#ifdef LOCAL
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(long long x) {cerr << x;}
void _print(int x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(string x) {cerr << '"' << x << '"';}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template<class T, class V> void _print(const pair<T, V> &p);
template<class T> void _print(const vector<T> &v);
template<class T> void _print(const set<T> &v);
template<class T, class V> void _print(const map<T, V> &v);
template<class T, class V> void _print(const unordered_map<T, V> &v);
template<class T> void _print(stack<T> s);
template<class T> void _print(queue<T> q);

template<class T, class V> void _print(const pair<T, V> &p) {
    cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";
}
template<class T> void _print(const vector<T> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(const set<T> &v) {
    cerr << "{ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "}";
}
template<class T, class V> void _print(const map<T, V> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T, class V> void _print(const unordered_map<T, V> &v) {
    cerr << "[ "; for (const auto &i : v) {_print(i); cerr << " ";} cerr << "]";
}
template<class T> void _print(stack<T> s) {
    vector<T> res; while (!s.empty()) { res.push_back(s.top()); s.pop(); }
    reverse(res.begin(), res.end()); cerr << "top->"; _print(res);
}
template<class T> void _print(queue<T> q) {
    vector<T> res; while (!q.empty()) { res.push_back(q.front()); q.pop(); }
    cerr << "front->"; _print(res);
}


using ll=long long;
using pi=pair<int,int>;
using vi=vector<int>;
using vii=vector<pair<int,int>>;
using vil=vector<ll>;
using pil=pair<ll,ll>;
using viil=vector<pair<ll,ll>>;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#define per(i,a,b) for(int i = (a); i >= (b); --i)
#define pb push_back
#define Ceil(a,b) ((a+b-1)/b)
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
    We are given with a grid which has obstacles.
    There is a robot at the top left corner and we need to 
    bring the robot to the down right corner.

    The robot cannot go to a obstacle and can only go right and
    down.

    We need to find the total paths with out obstacles.

    There are several subproblems again so, we can just do 
    dp.

    The state of the dp gives us:
            dp[i][j] will give us the total ways from that cell to 
            down right corner.

    The base case will be the down right corner.

    The transition is simple as :
            dp[i][j]=dp[i+1][j]+dp[i][j+1].
*/
void solve() {
    int n;
    cin>>n;

    vector<vector<char>> grid(n,vector<char> (n));
    rep(i,0,n-1){
        rep(j,0,n-1) {
            cin>>grid[i][j];
        }
    }

    if(grid[0][0]=='*' or grid[n-1][n-1]=='*') {
        cout<<0<<endl;
        return;
    }

    const int mod=1e9+7;
    vector<vil> dp(n,vil (n,0));
    per(i,n-1,0){
        per(j,n-1,0){
            if(grid[i][j]=='*') dp[i][j]=0;
            else if(i==n-1 and j==n-1) dp[i][j]=1;
            else if(i==n-1) dp[i][j]=dp[i][j+1];
            else if(j==n-1) dp[i][j]=dp[i+1][j];
            else dp[i][j]=((dp[i][j])%mod+(dp[i][j+1])%mod+(dp[i+1][j])%mod)%mod;
        }
    }
    debug(dp);
    cout<<dp[0][0]<<endl;
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