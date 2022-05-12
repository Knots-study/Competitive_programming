/*  eratosthenes_sieve(n)
    入力：整数 n
    出力：nまでの数字が素数か判定したvector（i番目がtrueならiは素数）
    計算量：O(nloglogn)
*/
vector<bool> eratosthenes_sieve(int n) {
    vector<bool> prime(n + 1, true);
    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}
