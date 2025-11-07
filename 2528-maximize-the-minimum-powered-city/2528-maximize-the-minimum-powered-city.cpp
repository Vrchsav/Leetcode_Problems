class Solution {
public:
    long long maxPower(vector<int>& stations, int r, long long k) {
        int n = stations.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + stations[i];
        vector<long long> power(n);
        for (int i = 0; i < n; ++i) {
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            power[i] = pref[R + 1] - pref[L];
        }
        long long lo = 0, hi = *max_element(power.begin(), power.end()) + k;
        auto can = [&](long long x) {
            long long rem = k, add = 0;
            vector<long long> diff(n + 1, 0);
            for (int i = 0; i < n; ++i) {
                add += diff[i];
                long long cur = power[i] + add;
                if (cur < x) {
                    long long need = x - cur;
                    if (need > rem) return false;
                    rem -= need;
                    add += need;
                    int end = min(n - 1, i + 2 * r);
                    diff[end + 1] -= need;
                }
            }
            return true;
        };
        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (can(mid)) lo = mid; else hi = mid - 1;
        }
        return lo;
    }
};