#include <vector>
#include <cstdio>
#include <queue>

#define N 1000010

using std::vector;

vector< vector<int> > map(N, vector<int>(0, 0));

bool isTaller(int p, int q){
    std::queue<int> Q;
    for(int i = 0; i < map[p].size(); ++i){
        Q.push(map[p][i]);
    }
    while(!Q.empty()){
        int front = Q.front();
        Q.pop();
        if(front == q)
            return true;
        for(int i = 0; i < map[front].size(); ++i){
            Q.push(map[front][i]);
        }
    }
    return false;
}


int main(){
    //freopen("S4/s4.6-5.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    
    int nPeople, mComparisons, p, q;
    
    scanf("%d %d", &nPeople, &mComparisons);
    
    while(mComparisons--){
        scanf("%d %d", &p, &q);
        map[p].push_back(q);
    }
    
    scanf("%d %d", &p, &q);
    
    if(isTaller(p, q))
        printf("yes\n");
    else if(isTaller(q, p))
        printf("no\n");
    else
        printf("unknown\n");
    
    return 0;
}
