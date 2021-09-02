#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[100000]={0};
bool dfs(int source,int parent){
    visited[source]=1;
    for(auto x:v[source]){
        if(visited[x]!=1){
            if(dfs(x,source)) return true;
        }
        else if(x!=parent){
            return true;
        }    
    }
    return false;
}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bool k;
    for(int i=1;i<=n;i++){
        if(visited[i]!=1){
            k=dfs(i,-1);
        }
    }

    if(k==true){
        cout<<"cycle"<<endl;
    }
    if(k==false){
        cout<<"No Cycle"<<endl;
    }
}