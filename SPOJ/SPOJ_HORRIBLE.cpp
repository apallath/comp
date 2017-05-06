//SPOJ - HORRIBLE
//Concept - Segment Tree
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef vector<long long> vi;
//range sum query
void build_tree(vi &tree, const vi &arr, long long node, long long left, long long right){
    if(left == right){
        tree[node] = arr[left];
    }
    else{
        long long mid = (left+right)/2;
        build_tree(tree, arr, 2*node, left, mid);
        build_tree(tree, arr, 2*node + 1, mid+1, right);
        long long lsum = tree[2*node], rsum = tree[2*node + 1];
        tree[node] = lsum+rsum;
    }
}
//Driver function to create tree
void create_tree(vi &tree, vi &lazy, const vi &arr){
    long long len = (long long)(2*pow(2.0, floor((log((double)arr.size()) / log(2.0)) + 1)));
    tree.assign(len, 0);
    lazy.assign(len, 0);
    build_tree(tree, arr, 1, 0, (long long)arr.size() - 1);
}
long long process_query(vi &tree, vi &lazy, long long node, long long left, long long right, long long i, long long j){
    if(lazy[node] != 0){
        tree[node] += (right - left + 1) * lazy[node];
        if(right != left){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(i>right || j<left) return 0; //segment disjolong long from query range
    if(left>=i && right<=j) return tree[node]; //segment inside query range
    long long mid = (left + right)/2;
    long long lsum = process_query(tree, lazy, 2*node, left, mid, i, j);
    long long rsum = process_query(tree, lazy, 2*node+1, mid+1, right, i, j);
    return lsum + rsum;
}
long long query(vi &tree, vi &lazy, const vi &arr, long long i, long long j){
    return process_query(tree, lazy, 1, 0, (long long)arr.size()-1, i, j);
}
void process_update(vi &tree, vi &lazy, long long node, long long left, long long right, long long i, long long j, long long value){
    if(lazy[node] != 0){
        tree[node] += (right - left + 1) * lazy[node];
        if(right != left){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(i>right || j<left) return;
    if(left>=i && right<=j){
        tree[node] += (right - left + 1) * value;
        if(right != left){
            lazy[2*node] += value;
            lazy[2*node+1] += value;
        }
        return;
    }
    long long mid = (left+right)/2;
    process_update(tree, lazy, 2*node, left, mid, i, j, value);
    process_update(tree, lazy, 2*node+1, mid+1, right, i, j, value);
    tree[node] = tree[2*node] + tree[2*node+ 1];
}
void update(vi &tree, vi &lazy, const vi &arr, long long i, long long j, long long value){
    process_update(tree, lazy, 1, 0, (long long)arr.size()-1, i, j, value);
}
//Driver code : SPOJ HORRIBLE
int main(){
    long long T;
    cin >> T;
    for(long long i = 0; i<T; i++){
        long long N, C;
        cin >> N >> C;
        vi A(N,0);
        vi tree, lazy;
        create_tree(tree, lazy, A);
        for(long long j = 0; j<C; j++){
            long long type;
            cin >> type;
            if(type == 0){
                long long p,q,value;
                cin >> p >> q >> value;
                update(tree, lazy, A, p-1, q-1, value);
            }
            else{
                long long p,q;
                cin >> p >> q;
                cout << query(tree, lazy, A, p-1 ,q-1) << endl;
            }
        }
    }
    return 0;
}
