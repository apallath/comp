#include<bits/stdc++.h>
using namespace std;

int main(){
    long long triangles[1000001];
    for(int i = 0; i <= 3; i++) triangles[i] = 0;
    for(long long n = 4; n<=1000000; n++){
        long long i = (n-3)/2;
        if(n%2 == 0)
            triangles[n] = triangles[n-1] + i + 1;
        else
            triangles[n] = triangles[n-1] + i;        
    }
    for(long long n = 1; n <=1000000; n++){
        triangles[n] = triangles[n] + triangles[n-1];
    }
    long long n;
    while(true){
        scanf("%lld", &n);
        if(n < 3) break;
        printf("%lld\n", triangles[n]);
    }

}


