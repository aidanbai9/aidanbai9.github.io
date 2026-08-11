// cf bits/extc++.h nonsense
#ifdef ONLINE_JUDGE
#define _EXT_CODECVT_SPECIALIZATIONS_H 1
#define _EXT_ENC_FILEBUF_H 1
#endif
#include "bits/extc++.h"

using namespace std;

using ll = long long;

template <typename T, typename... U>
void dbgh(const T& t, const U&... u) {
    cerr << t;
    ((cerr << " | " << u), ...);
    cerr << endl;
}

#ifdef DEBUG
#define dbg(...)                                              \
    cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]: "; \
    dbgh(__VA_ARGS__)
#else
#define dbg(...)
#define cerr   \
    if (false) \
    cerr
#endif

#define sz(x) int(std::size(x))
mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    auto rint = [&](long l, long r) -> long {
        return cowng() % (r - l + 1) + l;
    };
    int n = rint(3, 5), m = rint(2, min((n * (n - 1)) / 2, 10));
    cout << n << " " << m << "\n";
    set<pair<int, int>> edges;
    vector<int> order;
    for (int i = 0; i < n; i++) {
        order.push_back(i);
    }
    shuffle(order.begin(), order.end(), cowng);
    for (int i = 1; i < n; i++) {
        int a = rint(0, i - 1), b = i;
        if (rint(0, 1)) {
            swap(a, b);
        }
        edges.insert({a, b});
    }
    for (int i = 0; i < m - n + 1; i++) {
        int a = rint(0, n - 1), b = rint(0, n - 1);
        while (edges.count({a, b}) || (a == b)) {
            a = rint(0, n - 1), b = rint(0, n - 1);
        }
        edges.insert({a, b});
    }
    vector<pair<int, int>> fin;
    for (auto [a, b] : edges) {
        fin.push_back({order[a], order[b]});
    }
    shuffle(fin.begin(), fin.end(), cowng);
    for (auto [a, b] : fin) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    cin.exceptions(ios::failbit);
    ios_base::sync_with_stdio(false);
    solve();
}

/* stuff you should look for (Credits: Benq)
    int overflow, array bounds
    special cases (n=1?)
    do smth instead of nothing and stay organized
    WRITE STUFF DOWN
    DON'T GET STUCK ON ONE APPROACH
*/
