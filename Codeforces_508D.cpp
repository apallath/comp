//Codeforces 508D -  Tanya and Password
//Concept - Euler Tours
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stack>
enum colors{WHITE, BLACK};
using namespace std;
typedef vector<int> vi; typedef vector<vi> vvi; typedef stack<int> si;

//depth-first search for reachability
int dfs(vvi &adjList, vi &status, int u){
    status[u] = BLACK;
    int count = 1;
    for(int j = 0; j < adjList[u].size(); ++j){
        int v = adjList[u][j];
        if(status[v] == WHITE){
            count += dfs(adjList, status, v);
        }
    }
    return count;
}

//get euler path/circuit
void euler(vvi &adjList, vi &answer, int start){
    stack<int> ansstack, curstack;
    curstack.push(start);
    while(!curstack.empty()){
        int u = curstack.top();
        if(adjList[u].size() == 0){
            curstack.pop(); ansstack.push(u);
        }
        else{
            int v = adjList[u].back(); adjList[u].pop_back();
            curstack.push(v);
        }
    }
    while(!ansstack.empty()){
        int p = ansstack.top(); ansstack.pop();
        answer.push_back(p); //reverse the order
        //cout << p << " ";
    }
}

int main(){
    int m;
    cin >> m;
    string enterchar; getline(cin, enterchar);
    vector<string> chits; map<string,int> vertices;
    map<int,string> revmap; //reverse mapping
    int curct = 0;
    map<string,int>::iterator it;
    //process vertices
    for(int i = 0; i < m; ++i){
        string s; getline(cin, s); chits.push_back(s);
        string a = s.substr(0,2), b = s.substr(1,2);
        it = vertices.find(a);
        if(it == vertices.end()){
            vertices[a] = curct; revmap[curct] = a; curct++;
        }
        it = vertices.find(b);
        if(it == vertices.end()){
            vertices[b] = curct; revmap[curct] = b; curct++;
        }
    }
    int n = curct;
    vvi adjList(n,vi(0)); vi indeg(n,0); vi outdeg(n,0);
    //process edges
    for(int i = 0; i < m; ++i){
        string a = chits[i].substr(0,2), b = chits[i].substr(1,2);
        int u = vertices[a], v = vertices[b];
        adjList[u].push_back(v); outdeg[u]++; indeg[v]++;
    }

    //checking if an euler path/tour exists
    int startv = -1, endv = -1; bool nopath = false;
    for(int i = 0; i < n; ++i){
        if(indeg[i] != outdeg[i]){
            if(indeg[i] == outdeg[i] + 1 && endv == -1) endv = i;
            else if(outdeg[i] == indeg[i] + 1 && startv == -1) startv = i;
            else { nopath = true; break; }
        }
    }
    //need to check if all the vertices are reachable from the starting vertex
    if(startv == -1) startv = 0; //in case an euler tour exists
    vi status(n,WHITE);
    if(dfs(adjList, status, startv) != n) nopath = true;
    if(nopath){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        vi answer;
        euler(adjList, answer, startv);
        for(int k = 0; k < answer.size()-1; ++k){
            cout << revmap[answer[k]][0];
        }
        cout << revmap[answer.back()];
    }
}

