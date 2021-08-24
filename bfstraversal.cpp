// C++ code for BFS Traversal

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000]={0};
void bfs(int source){
    queue<int>q;
    visited[source]=1;
    q.push(source);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        cout<<current<<" ";
        // All node operations go here!
        for(auto x:v[current]){
            if(visited[x]==0){
                q.push(x);
                visited[x]=1;
            }
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
            bfs(i);
        }
    }
}