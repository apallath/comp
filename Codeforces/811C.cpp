#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
    int n;
    cin >> n;
    //1-based indexing
    vi a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    //calculate first and last occurrences of each element - O(n)
    vi f(5001,-1), l(5001,-1);
    for(int i = 1; i <= n; i++){
        if(f[a[i]] == -1) f[a[i]] = i;
        l[a[i]] = i;
    }

    vi DP(n+1,0);
    DP[0] = 0;

    for(int i = 1; i <= n; i++){
        set<int> dist;
        DP[i] = DP[i-1]; //default

        for(int j = i; j > 0; j--){            
            
            dist.insert(a[j]); //insert into set - insertion only happens if distinct

            bool valid = true;
            for(int k = j; k <= i; k++){      
                if(!(f[a[k]] >= j and l[a[k]] <= i)){
                    valid = false;
                    break;
                }
            }
            if(valid){
                int xorval = 0;
                for(set<int>::iterator it = dist.begin(); it != dist.end(); it++){
                    xorval ^= (*it);
                }
                DP[i] = max(DP[i], DP[j-1] + xorval);
                break;
            }
        }       
    }

    cout << DP[n] << endl;
    
}
