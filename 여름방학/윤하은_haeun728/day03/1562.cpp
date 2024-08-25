#include <iostream>
 
#define MOD 1000000000

using namespace std;
 
int N, cmp, res;
long long dp[101][10][1 << 10];
 
void solve(){
    
    for(int i = 1; i <= 9; i++){
        dp[1][i][1 << i] = 1;
    }
    
    for(int n = 2; n <= 100; n++){
        for(int i = 0; i <= 9; i++){
            for(int k = 0; k < (1 << 10); k++){
                
                int offset = k | (1 << i);
                
                if(i == 0){
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][1][k]) % MOD;
                }
                else if(i == 9){
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][8][k]) % MOD;
                }
                else{
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][i-1][k]) % MOD;
                    dp[n][i][offset] = (dp[n][i][offset] + dp[n-1][i+1][k]) % MOD;
                }
            }
            
            
        }
    }
    
    long long ans = 0;
    for(int i = 0; i <= 9; i++){
        ans = (ans + dp[N][i][cmp]) % MOD;
    }
    cout << ans;
}
 
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    
    for(int i = 0; i <= 9; i++){
        cmp |= (1 << i);
    }
    
    solve();
    
    return 0;
}
