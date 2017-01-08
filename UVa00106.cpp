#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

int gcd(int a, int b){
    return b==0? a : gcd(b,a%b);
}
int printans(int N){
    int lim = int(ceil(sqrt(N)));
    //cout << lim << endl;
    int used[N+1];
    memset(used,0,sizeof(used));
    int ct = 0;
    for(int m = 1; m <= lim; m++){
        for(int n = 2; n <= lim; n+=2){
            if(gcd(m,n) == 1){ //relatively prime
                int a = abs(m*m - n*n);
                int b = 2*m*n;
                int c = m*m + n*n;
                if(c <= N){   
                    //cout << a << " " << b << " " << c << endl;
                    ct += 1;   
                    for(int k = 1; k*c<=N; k++) {
		                used[k*a] = 1;
				        used[k*b] = 1;
				        used[k*c] = 1;
	                }     
                }
            }    
        }
    }
    int pct = 0;
    for(int i = 1; i <= N; i++){
        if(used[i] == 1){
            used[i] = 0;
        }
        else{   
            pct += 1;
        }
    }
    cout << ct << " " << pct << endl;            
}

int main(){
    int n;
    while(cin >> n){
        printans(n);            
    }
}
