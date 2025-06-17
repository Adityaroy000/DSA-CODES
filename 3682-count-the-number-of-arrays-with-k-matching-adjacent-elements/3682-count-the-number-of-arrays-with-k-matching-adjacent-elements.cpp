#include <vector>
#include <cstdint> // for int64_t
using namespace std;

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int mod = 1'000'000'007;
        int d = n - 1;
        if (k > d) return 0;
        int r = k;
        if (r > d - r) r = d - r;
        int64_t C = 1;
        if (r) {
            vector<int> inv(r + 1);
            inv[1] = 1;
            for (int i = 2; i <= r; ++i) {
                inv[i] = int64_t(mod - mod / i) * inv[mod % i] % mod;
            }
            for (int i = 1; i <= r; ++i) {
                C = C * (d - r + i) % mod;
                C = C * inv[i] % mod;
            }
        }

        auto modpow = [&](int64_t base, int exp) {
            int64_t res = 1;
            while (exp) {
                if (exp & 1) res = res * base % mod;
                base = base * base % mod;
                exp >>= 1;
            }
            return res;
        };

        return int((int64_t(m) * C % mod) * modpow(m - 1, d - k) % mod);
    }
};
