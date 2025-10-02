class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;  // division by zero
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX; // overflow case

        bool isPositive = (dividend >= 0) == (divisor >= 0);

        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            int q = 0;
            while (a >= (b << (q + 1))) {
                q++;
            }
            ans += (1LL << q);
            a -= (b << q);
        }

        if (!isPositive) ans = -ans;
        return (ans > INT_MAX || ans < INT_MIN) ? INT_MAX : (int)ans;
    }
};
