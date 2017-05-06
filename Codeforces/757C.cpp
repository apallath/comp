#include<bits/stdc++.h>
using namespace std;

#define modval 1000000007
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long int ll;
typedef map<int,ll> mill;
typedef map<int,int> mii;

map<int,ll> factmap;

void init(){
    factmap[0] = 1;
}

ll fact(int n){
    if(factmap.find(n) == factmap.end()){
        factmap[n] = n * fact(n-1) % modval;            
    }           
    return factmap[n];
}

int main(){
    int n,m;
    scanf("%d %d",&n, &m);

    init();

    vector<mii> lstdict(m+1);
    vvii vec;

    for(int gym = 0; gym < n; gym++){
        int size;
        scanf("%d", &size);
        for(int p = 0; p < size; p++){
            int member;
            scanf("%d", &member);    
            if(lstdict[member].find(gym) == lstdict[member].end()){ 
                lstdict[member][gym] = 0;
            }  
            lstdict[member][gym] += 1;
        }
    }

    for(int poke = 1; poke <= m; poke++){
        vii temp;
        //red black tree => sorted order
        for(mii::iterator it = lstdict[poke].begin(); it != lstdict[poke].end(); it++){
            temp.push_back(*it);
        }
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    int ct = 1;
    ll ans = 1;

    for(int i = 1; i < m; i++){
        if(vec[i] == vec[i-1]){
            ct += 1;
        }
        else{
            ans = ans * fact(ct) % modval;
            ct = 1;
        }
    }
    ans = ans * fact(ct) % modval;

    cout << ans << endl;
    
}
