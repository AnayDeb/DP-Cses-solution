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
    Given n and m 
    and a grid , we need to find the min path sum in the grid.

    How will we do that?
    There are many subproblems which we can store in a dp state,
    and with that help we can find the ans for the bigger subproblem

    The dp state will be :
        dp[i][j] will give us the min path sum from that cell(i,j).

    The base case will be that:
        dp[n-1][m-1]=grid[n-1][m-1], because we need to reach there 
    
    The transition will be:
        At every step we can just simply say that min path at that cell
        will be min of down or right because the right path and left
        path will be calculated earlier and so we can use that value 
        to get the ans for the curr cell.

        Hence, dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];

    The final subproblem will be stored in dp[0][0], which is the ans.
*/
void solve() {
    int n,m;
    cin>>n>>m;

    vector<vi>grid(n,vi (m));
    rep(i,0,n-1){
        rep(j,0,m-1){
            cin>>grid[i][j];
        }
    }

    vector<vi>dp(n,vi (m));
    per(i,n-1,0){
        per(j,m-1,0){
            if(i==n-1 and j==m-1) dp[i][j]=grid[i][j];
            else if(i==n-1) dp[i][j]=dp[i][j+1]+grid[i][j];
            else if(j==m-1) dp[i][j]=dp[i+1][j]+grid[i][j];
            else dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
        }
    }
    debug(dp);
    cout<<dp[0][0]<<endl;
}

int32_t main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}