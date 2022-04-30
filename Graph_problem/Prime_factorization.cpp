//素因数分解
vector<int>prime_number;
 
void prime(int n){
    int r = sqrt(n);
    for(int i=2;i<r+1;i++){
        while(n%i==0){
            n /= i;
            prime_number.push_back(i);
        }
    }
    if(n>1)prime_number.push_back(n);
}