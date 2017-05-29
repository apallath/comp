#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long mult(long long a, long long b){
    long long ans = 0;

    a %= MOD; b %= MOD;
    while(b > 0){
        if(b % 2 != 0){
            ans = (ans + a) % MOD;
        }
        a = a*2 % MOD;
        b /= 2;
    }
    return ans % MOD;
}

long long mod_exp(long long x, long long y){
    long long ans = 1;

    while(y > 0){
        if(y % 2 == 1){
            ans = (ans * x) % MOD;
        }
        y/=2;
        x = x*x % MOD;            
    }
    return ans % MOD;
}

int main(){
    int n;

    scanf("%d\n", &n);

    vector<long long> lst(n,0);

    for(int i = 0; i < n; i++){
        scanf("%lld", &lst[i]);
    }

    sort(lst.begin(), lst.end());

    long long sm = 0;

    for(int i = 0; i < n; i++){
        sm += mult(lst[i], (mod_exp(2,i) - mod_exp(2,n-i-1) + MOD));
    }

    printf("%lld\n", sm % MOD);
}

