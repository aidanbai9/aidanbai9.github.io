#include "bits/extc++.h"

using namespace std;

int dp[20000];
int aimove[20000];
int tpow[10] = {1, 3, 9, 27, 81, 243, 729, 729 * 3, 729 * 9, 729 * 27};

vector<int> conv(int x) {
    vector<int> res;
    for (int i = 0; i < 9; i++) {
        res.push_back(x % 3);
        x /= 3;
    }
    reverse(res.begin(), res.end());
    return res;
}

int rev(vector<int> arr) {
    int x = 0;
    for (int i = 0; i < 9; i++) {
        x *= 3;
        x += arr[i];
    }
    return x;
}

void outb(vector<int> arr) {
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            cout << arr[j * 3 + k] << " ";
        }
        cout << "\n";
    }
}

vector<array<int, 3>> win;

bool alldone(vector<int> arr) {
    bool done = 1;
    for (auto u : arr) {
        if (u == 0) {
            done = 0;
        }
    }
    for (auto [a, b, c] : win) {
        if (arr[a] == arr[b] && arr[b] == arr[c] && arr[a] != 0) {
            done = 1;
        }
    }
    return done;
}

void solve() {
    int n = 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;
    win.push_back({0, 3, 6});
    win.push_back({1, 4, 7});
    win.push_back({2, 5, 8});
    win.push_back({0, 1, 2});
    win.push_back({3, 4, 5});
    win.push_back({6, 7, 8});
    win.push_back({0, 4, 8});
    win.push_back({2, 4, 6});
    vector<pair<int, int>> ord;
    for (int i = n - 1; i >= 0; i--) {
        int cnt = 0;
        vector<int> arr = conv(i);
        for (int j = 0; j < 9; j++) {
            cnt += (arr[j] != 0);
        }
        ord.push_back({cnt, i});
    }
    sort(ord.rbegin(), ord.rend());
    for (auto [num, i] : ord) {
        vector<int> arr = conv(i);
        for (auto [a, b, c] : win) {
            if (arr[a] == 1 && arr[b] == 1 && arr[c] == 1) {
                dp[i] = 1;
            }
            if (arr[a] == 2 && arr[b] == 2 && arr[c] == 2) {
                dp[i] = 2;
            }
        }
        if (dp[i] == 1 || dp[i] == 2) {
            continue;
        }
        if (alldone(arr)) {
            continue;
        }
        bool doom = 1;
        for (int j = 0; j < 9; j++) {
            if (arr[j] == 0) {
                vector<int> trans = arr;
                trans[j] = 1;
                for (auto& u : trans) {
                    if (u == 1) {
                        u = 2;
                    } else if (u == 2) {
                        u = 1;
                    }
                }
                if (dp[rev(trans)] != 1) {
                    doom = 0;
                    aimove[i] = j;
                }
                if (dp[rev(trans)] == 2) {
                    dp[i] = 1;
                    aimove[i] = j;
                    break;
                }
            }
        }
        if (doom) {
            dp[i] = 2;
            for (int j = 0; j < 9; j++) {
                if (arr[j] == 0) {
                    aimove[i] = j;
                }
            }
        }
    }
    cout << "play tic tac toe\n";
    cout << "do you want to go first (0 or 1)\n";
    bool first = 0;
    cin >> first;
    vector<int> board(9, 0);
    if (!first) {
        int val = rev(board);
        board[aimove[val]] = 1;
        cout << "my move\n";
    }
    while (!alldone(board)) {
        outb(board);
        cout << "what is your move (input a point (x,y) from (0,0) to (2,2))\n";
        int x, y;
        cin >> x >> y;
        board[3 * x + y] = 2;
        cout << "your move\n";
        if (alldone(board)) {
            break;
        }
        outb(board);
        int val = rev(board);
        assert(conv(rev(board)) == board);
        assert(board[aimove[val]] == 0);
        board[aimove[val]] = 1;
        cout << "my move\n";
        if (alldone(board)) {
            outb(board);
            cout << "i win lil bro\n";
            return;
        }
    }
    cout << "ur lucky we tied\n";
}

int main() {
    solve();
}
