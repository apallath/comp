//UVa725 - Division [AC]
//Concept - Iterative Complete Search
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
int main(){
    bool lbreak = false;
    while(true){
        scanf("\n%d", &n);
        bool found = false;
        if(n==0) {break;}
        if(lbreak) printf("\n"); //line break between test cases only - else Presentation Error
        lbreak = true;
        for(int f = 1234; f < 50000; f++){
            bitset<10> used;
            int a = n*f; int dig;
            if(a>98765) {continue;}
            int da = a; int df = f;
            for(int i = 1; i <= 5; ++i){
                dig = da%10; da = da/10;
                if(!used.test(dig)){
                    used.set(dig);
                }
            }
            for(int i = 1; i <= 5; ++i){
                dig = df%10; df = df/10;
                if(!used.test(dig)){
                    used.set(dig);
                }
            }
            if(used.count() == 10){
                found = true;
                printf("%05d / %05d = %d\n", a, f, n);
            }
        }
        if(!found){
            printf("There are no solutions for %d.\n", n);
        }
    }
    return 0;
}
