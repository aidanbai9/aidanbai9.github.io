// cf bits/extc++.h nonsense
#ifdef ONLINE_JUDGE
#define _EXT_CODECVT_SPECIALIZATIONS_H 1
#define _EXT_ENC_FILEBUF_H 1
#endif
#include "bits/extc++.h"

using namespace std;
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using namespace __gnu_pbds;

template <typename T>
using indexed_set = tree<T,
                         null_type,
                         std::less<T>,
                         rb_tree_tag,
                         tree_order_statistics_node_update>;

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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); i--)

mt19937_64 cowng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int maxn = 1000;
int grid[maxn][maxn];
int dirs[8][2] = {{-1, 0},  {1, 0},  {0, 1},  {0, -1},
                  {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int n, m;
string vals[10] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
bool inb(int x, int y) {
    return (0 <= x) && (x < n) && (0 <= y) && (y < m);
}
void update() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == -1) {
                continue;
            }
            int ans = 0;
            for (auto [dx, dy] : dirs) {
                if (inb(i + dx, j + dy)) {
                    ans += (grid[i + dx][j + dy] == -1);
                }
            }
            grid[i][j] = ans;
        }
    }
}

void solve() {
    auto rint = [&](long l, long r) -> long {
        return cowng() % (r - l + 1) + l;
    };
    while (true) {
        cout << "enter dimentions: (don't troll, program will crash)\n";
        cin >> n >> m;
        cout << "discord messages?\n";
        bool discord = 0;
        cin >> discord;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                grid[i][j] = 0;
            }
        }
        set<pair<int, int>> mines;
        int nummines = max(long(1), rint((n * m) / 6, (n * m) / 5));
        for (int i = 0; i < nummines; i++) {
            int x = rint(0, n - 1), y = rint(0, m - 1);
            while (mines.count({x, y})) {
                x = rint(0, n - 1), y = rint(0, m - 1);
            }
            mines.insert({x, y});
            grid[x][y] = -1;
        }
        update();
        if (discord) {
            cout << ":flag_black: " << nummines << "\n";
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!discord) {
                    cout << grid[i][j] << " ";
                } else {
                    if (grid[i][j] == -1) {
                        cout << "||:boom:|| ";
                    } else {
                        cout << "||:" << vals[grid[i][j]] << ":|| ";
                    }
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    cin.exceptions(ios::failbit);
    solve();
}
