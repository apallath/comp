#include<bits/stdc++.h>
using namespace std;

//trie
#define NO_NODE -1
const int MAXX = 1000010;
const int ALPHA = 26; //all alphabets are lower case
const int ROOT = 0;
int cnode = 1;

int trie[MAXX][ALPHA]; //bob's vocabulary
int paths[MAXX]; //count of leaf paths from each node

void init_trie(){
    memset(trie,NO_NODE,sizeof(trie));
    memset(paths,0,sizeof(paths));
}
int insert(string s){   
    int t = ROOT;
    for(int i = 0; i < s.length(); i++){        
        int c = s[i] - 'a';
        if(trie[t][c] == NO_NODE){
            trie[t][c] = cnode++; //next available node
        }           
        t = trie[t][c]; //get next trie node      
        paths[t]++; //new path
   }     
}
int getcount(string s){
    int j = 0;
    int gamelen = 0;    
    int avl = s.length();
    int t = ROOT;

    while(j < s.length()){
        if(avl==0) break;
        int c = s[j] - 'a';
        if(trie[t][c] == NO_NODE) break; //character not found

        t = trie[t][c];
        avl = min(avl-1,paths[t]-1);
        gamelen += 1;  
        j += 1;
    }   
    return gamelen;
    
}

//io and algo
int main(){
    int n,m;
    scanf("%d %d\n", &n, &m); //vocab sizes of alice and bob
    vector<string> alice(n);
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        alice[i] = s;
    }
    init_trie();
    for(int i = 0; i < m; i++){
        string s;
        getline(cin,s);
        insert(s);
    }

    long total = 0;
    long total1 = 0;

    for(int i = 0; i < n; i++){
        total += getcount(alice[i]);
    }
    cout << total <<endl;
}

    

