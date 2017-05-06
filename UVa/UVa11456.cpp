#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==0){
            cout << 0 << endl;
            continue;
        }
        vi arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        //LIS+LDS
        vi lis(n,1);
        vi lds(n,1);
        /*for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;*/
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(arr[j] > arr[i]){
                    lis[i] = max(lis[i], 1 + lis[j]);   
                    //cout << "LIS " << i << " " << j << " " << lis[i] << endl;
                }
                if(arr[j] < arr[i]){
                    lds[i] = max(lds[i], 1 + lds[j]);
                    //cout << "LDS " << i << " " << j << " " << lis[i] << endl;
                }      
            }
        }
        int val = lis[0] + lds[0] - 1;
        for(int i = 1; i < n; i++){
            val = max(val, lis[i] + lds[i] - 1);
        }
        cout << val << endl;
    }
}
