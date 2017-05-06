#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        int n; cin >> n;
        vi val(n); vi w(n);
        for(int i = 0; i < n; i++){
            cin >> val[i];
        }
        for(int i = 0; i < n; i++){
            cin >> w[i];
        }    
        vi lis(n); vi lds(n);
        for(int i = n-1; i >= 0; i--){
            lis[i] = w[i];
            lds[i] = w[i];
            for(int j = i+1; j < n; j++){
                if(val[j] > val[i]){
                    lis[i] = max(lis[i], w[i] + lis[j]);    
                }
                if(val[j] < val[i]){
                    lds[i] = max(lds[i], w[i] + lds[j]);
                }
            }
        }
        int lval = lis[0], dval = lds[0];
        for(int i = 0; i < n; i++){
            lval = max(lval, lis[i]);
            dval = max(dval, lds[i]);
        }
        cout << "Case " << t << ". ";
        if(lval >= dval){
            cout << "Increasing (" << lval << "). Decreasing (" << dval << ")." << endl;   
        }
        else{
            cout << "Decreasing (" << dval << "). Increasing (" << lval << ")." << endl; 
        }
    }    
}
