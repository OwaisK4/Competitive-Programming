long long calculate(long long p, long long q) {
    long long mod = 998244353, expo;
    expo = mod - 2;

    // Loop to find the value
    // until the expo is not zero
    while (expo) {

        // Multiply p with q
        // if expo is odd
        if (expo & 1) {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;

        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}