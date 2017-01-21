#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

//Union-Find
void init(vi &parent, vi &sz, int n){
    parent.assign(n,0); sz.assign(n,1);
    for(int i = 0; i<n; i++) parent[i] = i;
}
int get_parent(vi &parent, int i){
    return parent[i] == i ? i : parent[i] = get_parent(parent, parent[i]);
}
bool uf_find(vi &parent, int i, int j){
    return get_parent(parent, i) == get_parent(parent, j);
}
void uf_union(vi &parent, vi &sz, int i, int j){
    int pi = get_parent(parent, i), pj = get_parent(parent, j);
    if(sz[pi]<=sz[pj]) parent[pi] = pj;
    else parent[pj] = pi;
}
int main(){
    int n;
    cin >> n;
    vi parent;
    vi sz;
    init(parent,sz,n);
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        j--;
        uf_union(parent,sz,i,j);    
    }
    set<int> parents;
    for(int i = 0; i < n; i++){
        parents.insert(get_parent(parent, i));
    }   
    cout << parents.size() << endl;
}
