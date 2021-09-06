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

int numDiv(ll N) {
    int ans = 1;                               
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
        int power = 0;                              
        while (N%p[i] == 0) { N /= p[i]; ++power; }  
        ans *= power+1;                              
    }
    return (N != 1) ? 2*ans : ans;              
}

int main() {
    sieve(10000000);                              
    printf("%lld\n", p.back());            
    return 0;
}
