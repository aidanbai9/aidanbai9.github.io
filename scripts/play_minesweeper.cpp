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

ll rint(ll l, ll r) {
    return cowng() % (r - l + 1) + l;
}
constexpr int maxn = 1000;
int grid[maxn][maxn];
int guess[maxn][maxn];
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

void gengrid(int nummines) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            grid[i][j] = 0;
            guess[i][j] = -1;
        }
    }
    set<pair<int, int>> mines;
    for (int i = 0; i < nummines; i++) {
        int x = rint(0, n - 1), y = rint(0, m - 1);
        while (mines.count({x, y})) {
            x = rint(0, n - 1), y = rint(0, m - 1);
        }
        mines.insert({x, y});
        grid[x][y] = -1;
    }
    update();
}

bool outguess() {
    bool done = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (guess[i][j] != -1) {
                if (guess[i][j] == -10) {
                    cout << "* ";
                } else {
                    cout << guess[i][j] << " ";
                }
            } else {
                if (grid[i][j] != -1) {
                    done = 0;
                }
                cout << "X ";
            }
        }
        cout << "\n";
    }
    return done;
}

bool makeguess(int x, int y) {
    if (grid[x][y] != -1) {
        guess[x][y] = grid[x][y];
        return 1;
    } else {
        guess[x][y] = -10;
        return 0;
    }
}

void solve() {
    while (true) {
        cout << "enter dimentions: (don't troll, program will crash)\n";
        cin >> n >> m;
        /*cout << "discord messages?\n";
        bool discord = 0;
        cin >> discord;*/
        int nummines = max(ll(1), rint((n * m) / 6, (n * m) / 5));

        gengrid(nummines);
        {
            cout << "GIVE A GUESS\n";
            int x, y;
            cin >> x >> y;
            while (grid[x][y] == -1) {
                gengrid(nummines);
            }
            makeguess(x, y);
            outguess();
        }
        bool chill = 1;
        while (chill) {
            cout << "GIVE A GUESS\n";
            int x, y;
            cin >> x >> y;
            if (makeguess(x, y)) {
                cout << "GOOD\n";
            } else {
                chill = 0;
                cout << "COOKED\n";
            }
            if (outguess()) {
                chill = 0;
                cout << "YOU WIN\n";
            }
        }
        /*if (discord) {
            cout << ":flag_black: " << nummines << "\n";
        }*/
        // int cnt = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         /*if (!discord) {*/
        //         cout << grid[i][j] << " ";
        //         if (grid[i][j] == -1) {
        //             cnt++;
        //         }
        //         /*} else {
        //             if (grid[i][j] == -1) {
        //                 cout << "||:boom:|| ";
        //             } else {
        //                 cout << "||:" << vals[grid[i][j]] << ":|| ";
        //             }
        //         }*/
        //     }
        //     cout << "\n";
        // }
        // assert(cnt == nummines);
    }
}

int main() {
    cin.exceptions(ios::failbit);
    solve();
}
