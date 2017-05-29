#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(){
    int n,m;
    cin >> n >> m;
    vi lst(n);
    for(int i = 0; i < n; i++){
        cin >> lst[i];       
    }   
    int l, r, x, cnt;
    for(int i = 0; i < m; i++){
        cin >> l >> r >> x; l--; r--; x--;
        cnt = 0;
        for(int i = l; i <= r; i++){
            if(lst[i] < lst[x]) cnt++;
        }
        if(l+cnt == x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}
