//逆元
long long powmod(long long x,long long n,long long m){//MODを取る時
    long long ret = 1;
    while(n>0){
        if(n&1)ret = ret * x % m;
        x = x * x % m;
        n >>= 1; //nを1bit右にずらす
    }
    return ret;
}

//a^{-1}modを計算する
long long modinv(long long a,long long mod){
    return powmod(a,mod-2,mod);
}