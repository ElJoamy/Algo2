#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                             
vll p;                                           

void sieve(ll upperbound) {                     
    _sieve_size = upperbound+1;                  
    bs.set();                                     
    bs[0] = bs[1] = 0;                           
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
        p.push_back(i);                            
    }
}

bool isPrime(ll N) {                            
    if (N < _sieve_size) return bs[N];           
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
        return true;                                 
} 

vll primeFactors(ll N) {                       
    vll factors;     
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        while (N%p[i] == 0) {                   
            N /= p[i];                               
            factors.push_back(p[i]);                   
        }
    if (N != 1) factors.push_back(N);  
    return factors;
}

int main() {
    sieve(10000000);                            
    printf("%lld\n", p.back());               
    for (int i = p.back()+1; ; ++i)
        if (isPrime(i)) {
            printf("The next prime beyond the last prime generated is %d\n", i);
            break;
        }
    printf("%d\n", isPrime((1LL<<31)-1));          
    printf("%d\n", isPrime(136117223861LL));       
    printf("\n");
    vll r = primeFactors((1LL<<31)-1);          
    for (auto &pf : r)
        printf("> %d\n", pf);
    r = primeFactors(136117223861LL);              
    for (auto &pf : r)
        printf("> %d\n", pf);                       
    r = primeFactors(142391208960LL);         
    for (auto &pf : r)
       printf("> %d\n", pf);                     
    r = primeFactors(9999973LL*9999973LL);     
    for (auto &pf : r)
        printf("> %d\n", pf);
         printf("\n");
   return 0;
}
