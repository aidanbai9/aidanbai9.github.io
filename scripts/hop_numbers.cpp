#include "bits/extc++.h"

using namespace std;

using ll = long long;

#define sz(x) int(std::size(x))

template <typename T, typename... U>
void dbgh(const T& t, const U&... u) {
    cerr << t;
    ((cerr << " | " << u), ...);
    cerr << "\n";
}
#ifdef DEBUG
#define dbg(...)                                            \
    cerr << "L" << __LINE__ << "[" << #__VA_ARGS__ << "]:"; \
    dbgh(__VA_ARGS__)
#else
#define dbg(...)
#define cerr   \
    if (false) \
    cerr
#endif

string sequence[10];
vector<string> cur;
string base[5];
string space = "   ";

void out(string x) {
    int n = sz(x);
    for (int row = 0; row < 5; row++) {
        string s = "";
        for (int i = 0; i < n; i++) {
            int dig = (x[i] - '0');
            s += base[(sequence[dig][row] - '0')];
            s += space;
        }
        cout << s << "\n";
    }
}

void solve() {
    cout << "how many digits per row?\n";
    int dig;
    cin >> dig;
    cout << "what number? (please input a nonnegative integer otherwise "
            "program will "
            "crash)\n";
    string x;
    cin >> x;
    int n = sz(x);
    for (int i = 0; i < n; i += dig) {
        out(x.substr(i, min(dig, n - i)));
        cout << "\n";
    }
}

int main() {
    base[0] = "hop";
    base[1] = "hophophop";
    base[2] = "hop      ";
    base[3] = "      hop";
    base[4] = "hop   hop";
    sequence[0] = "14441";
    sequence[1] = "00000";
    sequence[2] = "13121";
    sequence[3] = "13131";
    sequence[4] = "44133";
    sequence[5] = "12131";
    sequence[6] = "12141";
    sequence[7] = "13333";
    sequence[8] = "14141";
    sequence[9] = "14131";
    solve();
}
