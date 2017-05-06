#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef vector<int> vi;

int binarySearch(vi &seq, vi &lisidx, int l, int r, int t){
    int m = (l+r)/2;
    if(l>r){ return l; }
    if(seq[lisidx[m]] == seq[t]){return m;}
    if(seq[lisidx[m]] < seq[t]){return binarySearch(seq, lisidx, m+1, r, t);}
    if(seq[lisidx[m]] > seq[t]){return binarySearch(seq, lisidx, l, m-1, t);}
}
int main(){ //For UVa00481
    int temp;
    vi seq; //contains sequence
    while(cin>>temp){ seq.push_back(temp); }
    vi lisidx; //indices of elements in LIS
    vi parent(seq.size()); //parent pointers of each index in seq
    lisidx.push_back(0); parent[0] = -1;
    for(int x = 1; x < seq.size(); x++){
        int last = lisidx[lisidx.size() - 1];
        if(seq[x] > seq[last]){
            parent[x] = last;
            lisidx.push_back(x);
        }
        else{
            int idx = binarySearch(seq,lisidx,0,lisidx.size()-1,x);
            if(idx == 0)
                parent[x] = -1;
            else
                parent[x] = lisidx[idx-1];
            lisidx[idx] = x;
        }
    }

    cout << lisidx.size() << endl;
    cout << "-" << endl;
    stack<int> st;
    int g = lisidx[lisidx.size() - 1];
    while(g != -1){
        st.push(g);
        g = parent[g];
    }
    while(!st.empty()){
        cout << seq[st.top()] << endl;
        st.pop();
    }

}
