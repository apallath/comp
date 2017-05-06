//UVa10496 - Collecting Bleepers
//Concept - O(2^n n^2) DP for Travelling Salesman Problem
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring> //for memset
#include<limits>
using namespace std;
const int INF = numeric_limits<int>::max();

int T,xsize,ysize,n;
int x[11],y[11]; //vertices in Graph - Karel + max 10 Beepers
int memo[11][1<<11]; //memo table

int d(int p,int q){ //distance function
    int dval = abs(x[p]-x[q]) + abs(y[p]-y[q]);
    return dval;
}

//memoization technique
int tsp(int u, int S){
    //cost of partial path starting at 0 and ending at v, including the vertices in subset S.
    //S is subset representation using bitmask technique
    if(S == (1 << n) - 1){ //all points
        return d(u,0); //complete tha path
    }
    if(memo[u][S] != -1){ //already available
        return memo[u][S];
    }
    int ans = INF;
    for(int v = 0; v < n; v++){
        if(u != v && !(S & (1 << v))){ //if u != v and v has not been visited yet
            ans = min(ans, tsp(v, S|(1 << v)) + d(u,v));
        }
    }
    memo[u][S] = ans;
    return ans;
}

int main(){ //For UVa10496
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> xsize >> ysize;
        cin >> x[0] >> y[0]; //Karel
        cin >> n; //No of Bleepers
        for(int i = 1; i <= n; i++){
            cin >> x[i] >> y[i];
        }
        ++n; //now include 0 also
        memset(memo, -1, sizeof memo);
        cout << "The shortest path has length " << tsp(0,1) << endl;
    }
    return 0;
}
