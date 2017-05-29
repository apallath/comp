//Warmup

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int T,N;
    scanf("%d\n", &T);
    for(int t = 0; t < T; t++){
        bool flag = false;
        scanf("%d\n", &N);
        vector<int> ls(N,0);
        for(int i = 0; i < N; i++){
            scanf("%d", &ls[i]);
        }
        int g = ls[0];
        for(int i = 1; i < N; i++){
            g = gcd(g, ls[i]);
            if (g == 1){
                printf("%d\n", N);
                flag = true;
                break;
            }
        }
        if(!flag)
            printf("%d\n", -1);
    }
}
