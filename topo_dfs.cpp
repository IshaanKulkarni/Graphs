// Code to implement topological sorting using DFS ans Stack data structure:


#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000];
stack<int>topo;
void dfs(int source){
    visited[source]=1;
    for(auto x:v[source]){
        if(visited[x]!=1){
            dfs(x);
        }
    }
    topo.push(source);
}

// Intuttion behind the method is that the child is always pushed into the stack before the parent!
void print(stack<int>st){
    while(!st.empty()){
    int s=st.top();
    cout<<s<<endl;
    st.pop();
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            dfs(i);
        }
    }
    print(topo);
}


// Note that there are several valis toposort orders and this algorithm merely outputs one of them!