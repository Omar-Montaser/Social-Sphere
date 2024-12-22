// #include "Vector.h"
// #include "Queue.h"

#include <iostream>
#include <bits/stdc++.h>
#include "UserNode.h"
using namespace std;

vector<Metadata> reccomendFriends(vector<vector<int>>& userIds,int currentUser){
    vector<int> freq(2000,0),visited(2000,0);
    queue<Metadata>q;
    vector<Metadata> res;
    q.push(Metadata(currentUser));
    visited[currentUser]=1;
    while(!q.empty()){
        Metadata current=q.front();
        q.pop();
        for(int id:userIds[current.userID]){
            if(current.depth==1) freq[id]++;
            if(!visited[id]){
                visited[id]=1;
                if(current.depth!=0)
                    res.push_back(id);
                q.push(Metadata(id,current.depth+1));
            }
        }
    }
    for(auto& x:res){
        x.frequency=freq[x.userID];
    }
    return res;
}

int main(){
    UserNode u1("John"), u2("Jane"), u3("Bob"), u4("Alice"), u5("Charlie");
    vector<vector<int>> userNodes={{u2.id,u3.id,u5.id},
    {u1.id,u3.id,u4.id}, {u1.id,u2.id,u4.id},{u2.id,u3.id,u5.id}, {u1.id,u4.id}};
    vector<Metadata> ans=reccomendFriends(userNodes, u1.id);
    cout<<"Reccomended friends for "<<u1.username<<":\n";
    for(auto& x:ans) 
        cout<<x.userID<<" "<<x.frequency<<"\n";
}