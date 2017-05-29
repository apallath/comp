#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vL;

ll MOD = 1000000007;

int main(){
    int T, N, K;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d %d", &N, &K);
        vL lst(N);
        bool allneg = true;
        for(int i = 0; i < N; i++){
            scanf("%lld", &lst[i]);
            if(lst[i] >= 0) allneg = false;
        }
        sort(lst.begin(), lst.end(), [] (const auto& lhs, const auto& rhs) { return abs(lhs) < abs(rhs); });
        
        vL ansneg(0);
        vL anspos(0);

        ll a;

        bool neg = false;

        for(int i = N-1; i > N-K-1; i--){
            a = lst[i];
            if(a < 0){
                neg = !neg;
                ansneg.push_back(a);
            }
            else{
                anspos.push_back(a);
            }       
        }

        vL ans; //final answer
        bool fillans = true;

        if(neg){
            //case 1 -> check if all numbers in the array are negative
            if(allneg){
                for(int i = 0; i < K; i++){
                    a = lst[i];
                    ans.push_back(a); 
                }  
                fillans = false;      
            }
            else{
                ll lpos, lneg;
                bool case1 = false, case2 = false;

                //case 1 <- remove last negative, replace by largest positive. Is this possible?
                for(int i = N-K-1; i >= 0; i--){
                    if(lst[i] >= 0){
                        case1 = true;
                        lpos = lst[i];
                        break;
                    }
                }
                case1 = case1 && (ansneg.size() > 0);

                //case 2 <- remove last positive, replace by largest abs value negative. Is this possible?
                for(int i = N-K-1; i >= 0; i--){
                    if(lst[i] < 0){
                        case2 = true;
                        lneg = lst[i];
                        break;
                    }
                }
                case2 = case2 && (anspos.size() > 0);

                //if one of the cases doesn't occur
                if(case1 and !case2){
                    ansneg.pop_back();
                    anspos.push_back(lpos);
                }
                else if(case2 and !case1){
                    anspos.pop_back();
                    ansneg.push_back(lneg);
                }
                else if(case1 and case2){
                    //compare cases
                    if(lpos * anspos[anspos.size() - 1] > lneg * ansneg[ansneg.size() - 1]){
                        ansneg.pop_back();
                        anspos.push_back(lpos);
                    }
                    else{
                        anspos.pop_back();
                        ansneg.push_back(lneg);
                    }
                }
            }

        }
        
        if(fillans){   
            ans.insert(ans.end(), ansneg.begin(), ansneg.end());
            ans.insert(ans.end(), anspos.begin(), anspos.end());
        }

        ll finalans = 1;
        for(int i = 0; i < ans.size(); i++){
            finalans = (finalans * ans[i]) % MOD;
            if(finalans < 0){
                finalans = (finalans + MOD) % MOD;
            }
        }
        
        printf("%lld\n", finalans);
    }   
}
