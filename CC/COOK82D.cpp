#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

const ll MOD = 1000000007;

//condition for all subgraphs to have Euler Tour - all vertices have even degree

ll modExp(ll x, ll n, ll p){
    ll ans = 1;
    while(n > 0){
        if(n % 2 == 1){ //odd
            ans = (ans * x) % p;
        }
        n /= 2;
        x = (x*x) % p;
    }     
    return ans % p;   
} 

//Hash with MOD - cannot use bitset directly with constraints
//Seriously, this is weird...
void setb(ll &bset, vector<int> &curdeg, int u, int v){
    if(curdeg[u] == 1){
        curdeg[u] = 0;
        bset -= modExp(2,u,MOD);  
        bset %= MOD; 
    }
    else if(curdeg[u] == 0){
        curdeg[u] = 1;
        bset += modExp(2,u,MOD);  
        bset %= MOD; 
    }
    if(curdeg[v] == 1){
        curdeg[v] = 0;
        bset -= modExp(2,v,MOD);  
        bset %= MOD; 
    }
    else if(curdeg[v] == 0){
        curdeg[v] = 1;
        bset += modExp(2,v,MOD);  
        bset %= MOD; 
    }
}

int main(){
    int N, M;
    scanf("%d %d",&N,&M);

    vector<ll> deg(M+1,0);
    vector<int> curdeg(N,0);

    vector<ii> edge;

    int u, v;
    for(int i = 0; i < M; i++){
        scanf("%d %d",&u, &v);
        edge.push_back(make_pair(u,v));
    }   
    for(int i = 0; i < M; i++){
        deg[i+1] = deg[i];
        setb(deg[i+1], curdeg, edge[i].first, edge[i].second);    
    }

    int Q,l,r;
    scanf("%d",&Q);
    //xor captures number of edges between l and r mod 2
    for(int i = 0; i < Q; i++){
        scanf("%d %d", &l, &r); 
        if((deg[r] - deg[l-1]) == 0){
            printf("Yes\n");
        }
        else{
            printf("No\n");    
        }            
    }
        
}
