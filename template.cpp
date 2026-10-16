// Hello! In my code, I use the template described on the following website:
// https://github.com/Maeblm/my-library/tree/main
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define rep(i,a,b) for (ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>=b; i--)
#define fore(i,a) for(auto &i:a)
#define pb push_back
#define _GLIBCXX_DEBUG
#define All(a) (a).begin(), (a).end()
#define YN(a) ((a) ? "Yes" : "No")
template <typename T> inline bool chmin(T& a, const T& b) {bool c=a>b; if(a>b) a=b; return c;}
template <typename T> inline bool chmax(T& a, const T& b) {bool c=a<b; if(a<b) a=b; return c;}
template <typename T> inline T gcd(T a,T b) {return (b==0)?a:gcd(b,a%b);}
template <typename T> inline T lcm(T a, T b) {return (a*b)/gcd(a,b);}
const int inf = INT_MAX / 2;
const ll linf = 1LL << 61;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vvvll = vector<vector<vector<ll>>>;

template<class T>
struct Edge {
    int from, to;
    T val;

    Edge(int f = -1, int t = -1, T v = -1)
        : from(f), to(t), val(v) {}
};

template <typename T>
void OUT(const T& x) {
    cout << x;
}
// ----- pair -----
template <typename T, typename U>
void OUT(const pair<T,U>& p) {
    cout << "(";
    OUT(p.first);
    cout << ", ";
    OUT(p.second);
    cout << ")";
}
// ----- vector -----
template <typename T>
void OUT(const vector<T>& v) {
    cout << "[ ";
    for (const auto& x : v) {
        OUT(x);
        cout << " ";
    }
    cout << "]";
}
// ----- set -----
template <typename T>
void OUT(const set<T>& s) {
    cout << "{ ";
    for (const auto& x : s) {
        OUT(x);
        cout << " ";
    }
    cout << "}";
}
// ----- map -----
template <typename K, typename V>
void OUT(const map<K,V>& mp) {
    cout << "{ ";
    for (const auto& [k,v] : mp) {
        OUT(k);
        cout << ": ";
        OUT(v);
        cout << ", ";
    }
    cout << "}";
}
// ----- queue -----
template <typename T>
void OUT(queue<T> q) {
    cout << "< ";
    while (!q.empty()) {
        OUT(q.front());
        cout << " ";
        q.pop();
    }
    cout << ">";
}
// ----- priority_queue -----
template <typename T>
void OUT(priority_queue<T> pq) {
    cout << "< ";
    while (!pq.empty()) {
        OUT(pq.top());
        cout << " ";
        pq.pop();
    }
    cout << ">";
}
// ----- stack -----
template <typename T>
void OUT(stack<T> st) {
    cout << "< ";
    while (!st.empty()) {
        OUT(st.top());
        cout << " ";
        st.pop();
    }
    cout << ">";
}
// ----- deque -----
template <typename T>
void OUT(const deque<T>& dq) {
    cout << "[ ";
    for (const auto& x : dq) {
        OUT(x);
        cout << " ";
    }
    cout << "]";
}
#define out(x) cerr << #x << ": ", OUT(x), cerr << '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(30);
    return 0;
}