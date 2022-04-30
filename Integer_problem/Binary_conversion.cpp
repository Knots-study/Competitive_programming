//10進数→2進数変換
string tobinary(int n){
    string r;
    while(n != 0){
        r += (n%2==0 ? "0" : "1");
        n /= 2;
    }
    return r;
}