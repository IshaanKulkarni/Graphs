// C++ program to calculate number of cycles in a graph using BFS
#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000];
int cyclebfs(int source){
    queue<pair<int,int>>q;
    visited[source]=1;
    q.push({source,-1});
    int cycle=0;
    while(!q.empty()){
        pair<int,int>current=q.front();
        q.pop();
        // cout<<current.first<<" ";
        // All node operations go here!
        for(auto x:v[current.first]){
            if(visited[x]==1&&x!=current.second){
                cycle++;
            }
            if(visited[x]==0){
                q.push({x,current.first});
                visited[x]=1;
            }
            
        }
    }
    // Point to ponder:: Why return cycle/2 instead of cycle?
    return cycle/2;
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
    int cycles=0;
    for(int i=1;i<=vertices;i++){
        if(visited[i]!=1){
            cycles+=cyclebfs(i);
        }
    }
    cout<<cycles<<endl;
}