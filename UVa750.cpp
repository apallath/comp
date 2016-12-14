//UVa750 - 8 Queens [AC]
//Concept - Backtracking
#include<cstdio>
#include<cmath> //for abs
using namespace std;
//indexing is from 1 to 8
int placement[9]; int rfix, cfix; //index : column, value : row
int line_number; //for output format

bool can_place(int col, int row){
    for(int prevcol = 1; prevcol < col; prevcol++){
        //cannot place on same row or diagonal as already placed queen
        //same diagonal => |col - prevcol| == |placement[col] - placement[prevcol]|
        if(row == placement[prevcol] || abs(col - prevcol) == abs(row - placement[prevcol]))
            return false;
    }
    return true;
}
int backtrack(int col){
    if(col == cfix){
        if(can_place(cfix,rfix)){
            placement[cfix] = rfix;
            if(col == 8){
                printf("%2d      %d", ++line_number, placement[1]);
                for(int j = 2; j <=8 ; j++){ printf(" %d", placement[j]); }
                printf("\n");
            }
            else{
                backtrack(col+1);
            }
        }
    }
    else{
        for(int row = 1; row <= 8; row++){
            if(can_place(col, row)){
                placement[col] = row;
                if(col == 8){
                    printf("%2d      %d", ++line_number, placement[1]);
                    for(int j = 2; j <=8 ; j++){ printf(" %d", placement[j]); }
                    printf("\n");
                }
                else{
                    backtrack(col+1);
                }
            }
        }
    }
}
int main(){
    int tests;
    scanf("%d", &tests);
    bool lbreak = false;
    for(int t = 0; t < tests; t++){
        scanf("%d %d", &rfix, &cfix);
        if(lbreak) {printf("\n");}
        lbreak = true;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        line_number = 0;
        backtrack(1);
    }
}
