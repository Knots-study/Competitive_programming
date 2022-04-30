//約数列挙
vector<ll>prime_number;
 
void prime(ll n){
    int r = sqrt(n);
    for(int i=1;i<r+1;i++){
        if(n%i==0){
            prime_number.push_back(n/i);
            prime_number.push_back(i);
        }
    }
}