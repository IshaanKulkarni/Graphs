// C++ code to find shortest distance between 2 nodes in a directed acyclic wwighted graph:
// Think by intuition about why sorting the vector by second value is necessary inside the shortest_dist function

#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[100000];
int visited[100000]={0};
int dist[100000]={INT_MAX};

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}

int shortest_distance(int n,int m){
    queue<int>q;
    visited[n]=1;
    dist[n]=0;
    q.push(n);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        sort(v[current].begin(),v[current].end(),sortbysec);
        for(auto x:v[current]){
            if(visited[x.first]!=1){
                visited[x.first]=1;
                q.push(x.first);
                dist[x.first]=dist[current]+x.second;
            }
        }
    }
    return dist[m];

}
int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
    }
    int a,b;
    cin>>a>>b;
    cout<<"Shortest distance is::";
    cout<<shortest_distance(a,b)<<endl;


    // cout<<"Debugger"<<endl;

    // for(int i=0;i<n;i++){
    //     cout<<i<<" "<<dist[i]<<endl;
    // }
}