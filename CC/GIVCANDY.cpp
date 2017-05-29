#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// returns GCD(a,b)
ll euclid(ll a, ll b){
    if(b==0){
        return a;
    }
    else{
        return euclid(b, a%b);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        ll A,B,C,D;
        scanf("%lld %lld %lld %lld", &A, &B, &C, &D);
        ll G = euclid(C,D);
        ll diff = (ll) abs(A-B);
        ll k = diff/G;
        ll ans = min(diff - k * G, (k+1)*G - diff);
        printf("%lld\n", ans);
    }
}
