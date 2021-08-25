#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];
int visited[1000000]={0};
int colour[100000]={-1};
bool bfsbipartite(int source){
    queue<int>q;
    visited[source]=1;
    q.push(source);
    colour[source]=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        // Operations on the node go here:
        for(auto x:v[current]){

            if(visited[x]!=1){
                visited[x]=1;
                q.push(x);
                if(colour[current]==1){
                    colour[x]=0;
                }
                if(colour[current]==0){
                    colour[x]=1;
                }
            }

            if(visited[x]==1&&colour[x]==colour[current]){
                return false;
            }
            
        }
    }
    return true;
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
    bool k;
    for(int i=1;i<=vertices;i++){
        if(visited[i]!=1){
            k=bfsbipartite(i);
            // cout<<k<<" "<<i<<endl;
            if(k==false){
                break;
            }
        }
    }
    if(k==true){
        cout<<"We have a Bipartite graph!"<<endl;
    }
    else{
        cout<<"We dont have a Bipartite graph!"<<endl;
    }

    // cout<<"colour array:"<<" ";
    // for(int i=1;i<=vertices;i++){
    //     cout<<colour[i]<<" ";
    // }
    // cout<<endl;
}