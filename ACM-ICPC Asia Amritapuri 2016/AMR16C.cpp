#include<bits/stdc++.h>
using namespace std;
#define max 1000001
#define ll long long int

//Note : An even more optimized version of this code in Python did not pass (TLE)

int main(){
    //sieve for numbers till 10^6
    int prime[max];

    for(int i = 0; i < max; i++) 
        prime[i] = 1;    

    prime[0] = 0; 
    prime[1] = 0;

    for(int i = 2; i < (int)sqrt(max); i++){
        if(prime[i]){
            for(int j = i*i; j < max; j+=i) 
                prime[j] = 1; //i is the largest prime factor of that number           
        }
    }
    //read input
    int T; 
    cin >> T;
    for(int t = 0; t < T; t++){
        int n; 
        cin >> n;
        vector<ll> lst(n);

        for(int j = 0; j < n; j++){
            cin >> lst[j];        
        }

        sort(lst.begin(), lst.end()); //ascending
        reverse(lst.begin(), lst.end()); //reverse
    
        bool found = false;
    
        for(int i = 0; i < n; i++){
            ll pi = lst[i]; 
            ll sq = (ll) sqrt(pi);

            if((sq*sq == pi) && prime[(int)sq]){
                cout << i+1 << " ";
                found = true; 
                continue;
            }
            int j = 4;
            for(int j = 4; j <= 40; j++){
                ll chk = (ll) pow(pi, 1.0/j);
                if(((ll)pow(chk,j)) == pi){
                    if(prime[chk]){
                        cout << i+1 << " ";
                        found = true; 
                    }
                    continue;
                } 
            }
        }        

        if(found){
            cout << endl;
        }else{
            cout << "No supporter found." << endl;
        }            
                 
    }
    return 0;
}

