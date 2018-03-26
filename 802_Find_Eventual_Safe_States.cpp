/*
2018/3/26  Leet Code ： 802 Find Eventual Safe States
    
    將每一點做DFS，若有重複拜訪點，用flag做紀錄(可能產生Loop)
    
*/
#include <iostream>
#include <vector>
#include "memory.h"

using namespace std;

class Solution {
public:
    int visit[500000]={0};
    int flag=0;
    vector <int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i=0;i<graph.size();i++){
            memset( visit, 0, ( graph.size()+1 ) * sizeof(int) );
            flag=0;
            visit[i]=1;
            DFS(graph,i);
            if(flag==0)
                ans.push_back(i);
            //cout<<endl;
        }
        return ans;
    }
    
    
    
    void DFS(vector<vector<int>>& graph, int p ){
        visit[p]=1;
        //cout<<p<<" ";
        for(int j=0;j<graph[p].size();j++){
            if(visit[ graph[p][j] ] == 1 )
                flag=1;
            else{
                visit[ graph[p][j] ]=1;
                DFS(graph,graph[p][j]);
            }
        }
        return;
    }
    
};

int main(){
    
    Solution start;
    vector <vector <int>> Q2;
    vector <int> Q1;
    Q1.push_back(1);
    Q1.push_back(2);
    Q2.push_back(Q1);
    Q1.clear();
    Q1.push_back(2);
    Q1.push_back(3);
    Q2.push_back(Q1);
    Q1.clear();
    Q1.push_back(5);
    //Q1.push_back(2);
    Q2.push_back(Q1);
    Q1.clear();
    Q1.push_back(0);
    //Q1.push_back(2);
    Q2.push_back(Q1);
    Q1.clear();
    Q1.push_back(5);
    //Q1.push_back(2);
    Q2.push_back(Q1);
    Q1.clear();
    Q2.push_back(Q1);
    Q2.push_back(Q1);
    
    
    vector<int> A; 
    A=start.eventualSafeNodes(Q2);
    //cout<<Q2.size()<<endl;
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    /*cout<<endl<<endl;
    for(int i=0;i<Q2.size();i++){
        for(int j=0;j<Q2[i].size();j++)
            cout<<Q2[i][j]<<" ";
        cout<<endl;
    }*/
    
    
    return 0;
}
