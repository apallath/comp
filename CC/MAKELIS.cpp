#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct LIS{
    vi vec; //all data
    int length = 0; //length of LIS
    int count = 0; //number of LIS
};

//Arithmetic operations on LIS structures

LIS mult(LIS A, LIS B){
    //return LIS with count = A.count * B.count
    //special cases
    if(A.count == 0){
        return A;
    }
    if(B.count == 0){
        return B;
    }
    if(A.count == 1){
        return B;    
    }
    if(B.count == 1){
        return A;
    }
    LIS ans = A;
    for(int i = 0; i < B.vec.size(); i++){
        B.vec[i] += A.vec.size();
    }
    ans.vec.insert(ans.vec.end(), B.vec.begin(), B.vec.end());
    ans.length = A.length + B.length;
    ans.count = A.count * B.count;
    return ans;
}

LIS add(LIS A, LIS B){
    //return LIS with count = A.count + B.count
    int diff = abs(A.length - B.length);
    if(A.count == 0){
        return B;
    }
    if(B.count == 0){
        return A;
    }
    if(A.length < B.length){
        //extend A
        vi ext;
        for(int i = 1; i <= diff; i++){
            ext.push_back(A.vec.size() + i);   
        }
        A.vec.insert(A.vec.end(), ext.begin(), ext.end());
    }   
    if(B.length < A.length){
        //extend B
        vi ext;
        for(int i = 1; i <= diff; i++){
            ext.push_back(B.vec.size() + i);   
        }
        B.vec.insert(B.vec.end(), ext.begin(), ext.end());
    }   
    LIS ans;
    for(int i = 0; i < A.vec.size(); i++){
        A.vec[i] += B.vec.size();
    }
    ans.vec.insert(ans.vec.end(), A.vec.begin(), A.vec.end());
    ans.vec.insert(ans.vec.end(), B.vec.begin(), B.vec.end());
    ans.length = max(A.length, B.length);
    ans.count = A.count + B.count;
    return ans;
}


int main(){
    LIS one;
    vi onev({1});
    one.vec = onev; one.length = 1; one.count = 1;

    LIS two;
    vi twov({2,1});
    two.vec = twov; two.length = 1; two.count = 2;

    LIS three;
    vi threev({3,2,1});
    three.vec = threev; three.length = 1; three.count = 3;
    
    //LIS one = {{1},1,1}, two = {{2,1},1,2}, three = {{3,2,1},1,3};

    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int K;
        cin >> K;
        LIS ans;
        stack<int> st;  
        while(K > 0){
            st.push(K % 3);
            K /= 3;
        }   
        int begin = st.top(); st.pop(); 
        if(begin == 1){
            ans = one;
        }
        else if(begin == 2){
            ans = two;
        }
        while(!st.empty()){
            int a = st.top(); st.pop();
            if(a == 0){
                ans = mult(ans, three);
            }
            else if(a == 1){
                ans = mult(ans, three);
                ans = add(ans, one);
            }
            else{
                ans = mult(ans, three); 
                ans = add(ans, two);    
            }

        }
        cout << ans.vec.size() << endl;
        for(int i = 0; i < ans.vec.size(); i++){
            printf("%d ", ans.vec[i]);
        }
        printf("\n");
    }

}
