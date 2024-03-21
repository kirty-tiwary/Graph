#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;


int v;
vector<list<int>> graph;
unordered_set<int> visited;
vector<vector<int>> result;

void addEdge(int src , int dest  , bool bi_dir = true){

        graph[src].push_back(dest);

        if(bi_dir){
            graph[dest].push_back(src);
        }
}

void display(){

    for(int i = 0 ; i<graph.size();i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
}

void dfs(int curr , int end, vector<int> & path){

    if(curr == end){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour) ){
         dfs(neighbour, end, path);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
}

void allPath(int src , int dest){
    vector<int> v;
    return dfs(src,dest,v);
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
    int e;
    cin>>e;
    visited.clear();
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdge(s,d,true);
    }
    display();
    

    int x,y;
    cin>>x>>y;
    allPath(x,y);
    cout<<"\n";
    cout<<result.size();
    for(auto path : result){
        for(auto el : path){
            cout<<el<<" ";
        }
        cout<<"\n";
    }
    
}

