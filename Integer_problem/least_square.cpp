/**
 *繰り返し二乗法
 *時間計算量:O(logn)
 *空間計算量:O(1)
**/

long long powpow(long long x,long long n){///通常のpow
    long long ret = 1;
    while(n>0){
        if(n&1)ret *= x;
        x *= x;
        n >>= 1; //nを1bit右にずらす
    }
    return ret;
}

long long powmod(long long x,long long n,long long m){//MODを取る時
    long long ret = 1;
    while(n>0){
        if(n&1)ret = ret * x % m;
        x = x * x % m;
        n >>= 1; //nを1bit右にずらす
    }
    return ret;
}
