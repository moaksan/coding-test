#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int x,y;
    node* left;
    node* right;
};

void preorder(node* ptr, vector<int>){
    if(ptr){
        preorder(ptr->left);
        preorder(ptr->right);
        
    }
}

bool cmp(vector<int> a, vector<int>b){
    return a[1]>b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    node n[nodeinfo.size()];
    
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    for(int i=0;i<nodeinfo.size();i++){
        n[i].x=nodeinfo[i][0];
        n[i].y=nodeinfo[i][1];
        n[i].left=NULL;
        n[i].right=NULL;
    }
    
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
