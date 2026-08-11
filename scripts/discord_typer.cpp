#include "bits/extc++.h"

using namespace std;

#define sz(x) int(std::size(x))

int main() {
    string nums[10] = {"zero", "one", "two",   "three", "four",
                       "five", "six", "seven", "eight", "nine"};
    int c = 0;
    while (1) {
        c++;
        cout << "what do you want to type in discord?\n";
        cout << "do 'line maker' to get long space of I's\n";
        cout << "\n";
        string s;
        if (c != 1)
            cin.ignore();
        getline(cin, s);
        string ans = "";
        cout << "hidden?\n";
        bool hidden;
        cin >> hidden;
        cout << "gif?\n";
        bool gif;
        cin >> gif;
        if (gif) {
            for (int i = 0; i < sz(s); i++) {
                // cout<<(s[i]-'a')<<" ";
                if (-32 <= (s[i] - 'a') && (s[i] - 'a') <= -7) {
                    s[i] += 32;
                }
            }
            int arr[s.size()];
            map<char, int> m;
            for (int i = 0; i < sz(s); i++) {
                m[s[i]]++;
                arr[i] = m[s[i]];
            }
            if (hidden) {
                ans += "||";
            }
            for (int i = 0; i < sz(s); i++) {
                if (0 <= (s[i] - 'a') && (s[i] - 'a') <= 25) {
                    for (int j = 0; j < arr[i]; j++) {
                        ans += "https://tenor.com/view/letter-";
                        ans += s[i];
                        ans += "-gif-90637";
                        ans += to_string(45 + (s[i] - 'a'));
                    }
                } else if (s[i] == ' ') {
                    ans += "       ";
                } else {
                    ans += s[i];
                }
                ans += " ";
            }
            if (hidden) {
                ans += "||";
            }
            cout << ans << "\n";
            continue;
        }
        if (s == "line maker") {
            ans =
                "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
                "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
                "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
                "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII"
                "IIIII";
            cout << ans << "\n";
            continue;
        }
        for (int i = 0; i < sz(s); i++) {
            // cout<<(s[i]-'a')<<" ";
            if (-32 <= (s[i] - 'a') && (s[i] - 'a') <= -7) {
                s[i] += 32;
            }
        }
        cerr << s << "\n";
        for (int i = 0; i < sz(s); i++) {
            if (0 <= (s[i] - 'a') && (s[i] - 'a') <= 25) {
                if (hidden)
                    ans += "||";
                ans += ":regional_indicator_";
                ans += s[i];
                ans += ":";
                if (hidden)
                    ans += "||";
                ans += " ";
            } else if (s[i] == ' ') {
                ans += "    ";
            } else if (-49 <= (s[i] - 'a') && (s[i] - 'a') <= -40) {
                if (hidden)
                    ans += "||";
                ans += ":";
                ans += nums[(s[i] - 'a') + 49];
                ans += ":";
                if (hidden)
                    ans += "||";
                ans += " ";
            } else if (s[i] == '!') {
                if (hidden)
                    ans += "||:exclamation:|| ";
                else
                    ans += ":exclamation: ";
            } else if (s[i] == '?') {
                if (hidden)
                    ans += "||:question:|| ";
                else
                    ans += ":question: ";
            } else if (s[i] == '#') {
                if (hidden)
                    ans += "||:hash:|| ";
                else
                    ans += ":hash: ";
            } else if (s[i] == '=') {
                if (hidden)
                    ans += "||:heavy_equals_sign:|| ";
                else
                    ans += ":heavy_equals_sign: ";
            } else {
                if (hidden)
                    ans += "||";
                ans += s[i];
                if (hidden)
                    ans += "||";
                ans += " ";
            }
        }
        cout << ans << "\n";
    }
}
