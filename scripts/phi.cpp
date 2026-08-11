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

int primes[168];
bool comp[1001];
int phi[1000001];

int phicalc(int x) {
    if (phi[x] != 0)
        return phi[x];
    vector<int> fac;
    int num = x;
    for (auto u : primes) {
        if (x % u == 0)
            fac.push_back(u);
        else
            continue;
        while (x % u == 0)
            x /= u;
    }
    if (x != 1)
        fac.push_back(x);
    for (auto u : fac) {
        num /= u;
        num *= (u - 1);
    }
    return phi[x] = num;
}

int bpow(ll base, int exp, int mod) {
    ll ans = 1;
    while (exp) {
        if (exp & 1)
            ans = (ans * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return ans;
}

int inv(int x, int mod) {
    return bpow(x, phicalc(mod) - 1, mod);
}

int mod(int a, int b) {
    if (a < 0)
        a += b;
    return a;
}

int gcd(int a, int b) {
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    return gcd(a, b % a);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i<n; i++){
        if(phicalc(i)<=12){
            cout<<i<<": "<<phicalc(i)<<"\n";
        }
    }
}

int main() {
    cin.tie(nullptr);
    cin.exceptions(ios::failbit);
    ios_base::sync_with_stdio(false);
    int num = 0;
    for (int i = 2; i <= 1000; i++) {
        if (comp[i])
            continue;
        primes[num] = i;
        num++;
        for (int j = i * 2; j <= 1000; j += i) {
            comp[j] = 1;
        }
    }
    solve();
}
