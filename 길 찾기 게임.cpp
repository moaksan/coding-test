#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int num,x,y;
    node* left;
    node* right;
};

void preorder(node* ptr, vector<int> v){
    if(ptr){
        v.push_back(ptr->num);
        preorder(ptr->left, v);
        preorder(ptr->right, v);
    }
}

bool cmp(node a, node b){
    return a.y>b.y;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    node n[nodeinfo.size()];
    
    for(int i=0;i<nodeinfo.size();i++){
        n[i].num=i+1;
        n[i].x=nodeinfo[i][0];
        n[i].y=nodeinfo[i][1];
        n[i].left=NULL;
        n[i].right=NULL;
    }
    
    sort(n, n+nodeinfo.size(), cmp);
    
    node* ptr=&n[0];
    for(int i=1;i<nodeinfo.size();i++){
        while(true){
            if(n[i].x<ptr->x){
                if(ptr->left==NULL){
                    ptr->left=&n[i];
                    break;
                }
                else
                    ptr=ptr->left;
            }
            else{
                if(ptr->right==NULL){
                    ptr->right=&n[i];
                    break;
                }
                else
                    ptr=ptr->right;
            }
        }
    }
    
    
    
    return answer;
}
