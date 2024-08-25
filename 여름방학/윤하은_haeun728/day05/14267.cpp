#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<int> child[100001]; 
int result[100001] = {0,}; 

void getScore(int x){
    
    for(int i = 0; i < child[x].size(); i++){
        int nx = child[x][i]; 
        result[nx] += result[x]; 
        getScore(nx); 
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        int v;
        scanf("%d",&v);
        if(i == 1) continue;
        child[v].push_back(i);
    }

    while(m--){
        int receiver,score;
        scanf("%d %d",&receiver,&score);
        result[receiver] += score;
    }
    getScore(1);
    for(int i = 1; i <= n; i++) printf("%d ",result[i]);
    printf("\n");
}
