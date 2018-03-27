/*
*/
#include <iostream>
#include <vector>
#include <utility>
#include "memory.h"

using namespace std;

class Solution {
public:
    int visit[50000]={0};
    vector <int> temp;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& arr) {
        int maxx =1e9;
        vector< vector<int>> maps;
        for(int i=0;i<numCourses;i++){
            vector<int> Q;
            maps.push_back(Q);
        }
        for(const auto& num :  arr){
            //cout<<num.first<<" "<<num.second<<endl;
            maps[ get<1>(num) ].push_back( get<0>(num) );
        }
        for(int i=0;i<numCourses;i++)
            if(!maps[i].empty())
                for(int j=0;j<maps[i].size();j++)
                    cout<<i<<" "<<maps[i][j]<<endl;
        cout<<"start"<<endl;
        
        for(int i=0;i<numCourses;i++){
            memset(visit,0,50000*sizeof(int));
            temp.clear();
            DFS(maps,i);
            if(temp.size()==numCourses)
                return temp;
        }
        
        vector <int> temp;
        return temp;
    }
    
    void DFS(vector<vector<int>> maps,int s){
        visit[s]=1;
        temp.push_back(s);
        for(int i=0;i<maps[s].size();i++){
            if(visit[ maps[s][i] ] !=1)
                DFS(maps,maps[s][i]);
        }
        
    }
    
    
};

int main(){
    
    int len=4;
    Solution ans;
    vector< pair<int,int> > p;
    p.push_back(make_pair(1,0));
    p.push_back(make_pair(2,0));
    p.push_back(make_pair(3,1));
    p.push_back(make_pair(3,2));
    
    vector <int> a;
    a=ans.findOrder(len,p);
    
    for(int i=0;i<len;i++)
        cout<<a[i]<<" ";
    
    return 0;
}
