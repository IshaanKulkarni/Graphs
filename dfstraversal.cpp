// C++ code for recursive DFS

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000]={0};
void dfs(int source){
    cout<<source<<" ";
    visited[source]=1;
    for(auto x:v[source]){
        if(visited[x]!=1){
            dfs(x);
        }
    }

}
int main(){
    int vertices,e;
    cin>>vertices>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=vertices;i++){
        if(visited[i]!=1){
            dfs(i);
        }
    }
}