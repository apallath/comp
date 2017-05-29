#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

typedef long long ll;

//A[i] can go up to 10^9, sqrt of 10^9 is approx 31623
#define SQN 32000

//prime number sieve till SQN
bool isprime[SQN];
vector<int> primes;

void genprimes(){
    for(int i = 0; i < SQN; i++){
        isprime[i] = true;    
    }
    for(int i = 2; i < SQN; i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j = i; j < SQN; j+=i){
                isprime[j] = false;
            }
        }
    }
}

//finding primes with frequencies
map<int,int> prfact;

void factorize(int x){
    for(int i = 0; i < primes.size(); i++){
        if(x % primes[i]){
            continue; //x > 1 clause handles update
        }
        int ct = 0;
        while(x % primes[i] == 0){
            x /= primes[i];
            ct++;
        }
        prfact[primes[i]] += ct; //this is safe...
    }    
    if(x > 1){
        //after checking with ALL primes till SQRT(MAX), still not 1
        //=> what's left is a PRIME factor > SQRT(MAX)
        prfact[x] += 1; //...so is this
    }
}


long long modExp(long long x, long long n, long long p){
    long long ans = 1;
    while(n > 0){
        if(n % 2 == 1){ //odd
            ans = (ans * x) % p;
        }
        n /= 2;
        x = (x*x) % p;
    }     
    return ans % p;   
} 

int main(){
    genprimes();

    int n;
    scanf("%d", &n);
    int A[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
        factorize(A[i]);
    }

    bool justdoit = true;

    for(map<int,int>::iterator it = prfact.begin(); it!= prfact.end(); it++){
        if(it->second % n != 0){
            justdoit = false; break;
        }
    }   

    if(justdoit){
        cout << "justdoit" << endl;
    }
    else{
        long long ans = 1;
        int val, reqval;
    
        for(map<int,int>::iterator it = prfact.begin(); it!= prfact.end(); it++){
            val = it->second;
            if(it->second % (n+1) != 0){
                reqval = (n+1) - (val % (n+1));
            }
            ans *= modExp(it->first, reqval, MOD); 
            ans = ans % MOD;
        }   

        ans = ans % MOD;

        cout << ans << endl;
    }    

    

    
}
