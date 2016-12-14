//UVa10360 - Rat Attack [AC]
//Concept - Summed Area Tables (https://en.wikipedia.org/wiki/Summed_area_table)
#include<iostream>
#include<cmath> //for max
const int ts = 1025; //max grid size
using namespace std;

int rats[ts][ts];
int sat[ts][ts]; //summed area table
int max_x, max_y, max_eff; //coordinates of max effectiveness
//O(n^2) pre-computation
void init(){
    for(int x = 0; x < ts; x++){
        for(int y = 0; y < ts; y++){
            rats[x][y] = 0;
            sat[x][y] = 0;
        }
    }
}
void compute_sat(){
    for(int i = 0; i < ts; i++){
        sat[i][0] = rats[i][0];
        sat[0][i] = rats[0][i];
    }
    for(int x = 1; x < ts; x++){
        for(int y = 1; y < ts; y++){
            sat[x][y] = rats[x][y] + sat[x-1][y] + sat[x][y-1] - sat[x-1][y-1];
        }
    }
}
int get_sat(int x,int y){
    if(x<0 || y<0) return 0;
    else return sat[min(x,ts-1)][min(y,ts-1)]; //in case goes out of grid
}
//finding max populated grid
void compute_effectiveness(int d){
    compute_sat();
    max_eff = 0; max_x = 0; max_y = 0;
    for(int x = 0; x < ts; x++){
        for(int y = 0; y < ts; y++){
            int cur_eff = get_sat(x+d,y+d) - get_sat(x+d,y-d-1) - get_sat(x-d-1,y+d) + get_sat(x-d-1,y-d-1);
            if(cur_eff > max_eff){
                max_eff = cur_eff; max_x = x; max_y = y;
            }
        }
    }
}
int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int d; cin >> d;
        int P; cin >> P;
        init();
        for(int p = 0; p < P; p++){
            int x,y,pop; cin >> x >> y >> pop;
            rats[x][y] = pop;
        }
        compute_effectiveness(d);
        cout << max_x << " " << max_y << " " << max_eff << endl;
    }
    return 0;
}


