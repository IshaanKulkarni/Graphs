// C++ code to detect cycles in a given undirected graph using BFS

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000];
bool cyclebfs(int source){
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
                return true;
            }
            if(visited[x]==0){
                q.push({x,current.first});
                visited[x]=1;
            }
            
        }
    }
    return false;
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
        if(cyclebfs(i)==true){
            cout<<"We have possible cycles!"<<endl;
            break;
        }
        cout<<"Sorry!No Cycles!"<<endl;
        }
        
        
    }
}