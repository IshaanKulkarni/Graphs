// C++ code for iterative version of DFS

#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000]={0};
void dfs(int source){
    stack<int>s;
    s.push(source);
    visited[source]=1;
    while(!s.empty()){
        int current=s.top();
        s.pop();
        cout<<current<<" ";
        for(auto x:v[current]){
            if(visited[x]!=1){
                visited[x]=1;
                s.push(x);   
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
            dfs(i);
        }
    }

}