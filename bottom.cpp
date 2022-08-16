#include "bits/stdc++.h"
using namespace std;
#define MAX_HEIGHT 1e5 + 9;
struct Node{
 int data;
 Node* left;
 Node* right;
};
Node* newNode(int val){
 Node* temp = new Node;
 temp->data = val;
 temp->left = temp->right = NULL;
 return temp;
}
Node* build(string S){
 if(S.length()==0||S[0]=='N') return NULL;
 vector<string> ip;
 istringstream iss(S);
 for(string s; iss >> s;){
  ip.push_back(s);
 }
 Node* root = newNode(stoi(ip[0]));
 queue<Node*> Q;
 Q.push(root);
 int i = 1;
 while(!Q.empty() and i < ip.size()){
   Node* curr = Q.front();
   Q.pop();
   string currval = ip[i];
   if(currval != "N"){
     curr->left = newNode(stoi(currval));
     Q.push(curr->left);
  }
   i++;
   if(i>=ip.size()) break;
   currval = ip[i];
   if(currval != "N"){
    curr->right = newNode(stoi(currval));
    Q.push(curr->right);
  }
  i++;
  }
 return root;
}
class Solution{
 public:
 vector<int> bottomView(Node* root){
   vector<int> res;
   if(!root) return res;
   map<int,int> mp;
   queue<pair<Node*,int>> Q;
   Q.push({root,0});
   while(!Q.empty()){
   pair<Node*,int> temp = Q.front();
   Node* node = temp.first;
   int hd = temp.second;
   mp[hd] = node->data;
   Q.pop();
   if(node->left){
    Q.push({node->left,hd - 1});
   }
   if(node->right){
    Q.push({node->right,hd + 1});
   }
  }
  for(auto it : mp){
   res.push_back(it.second);
  }
 return res;
 }
};
int main(){
 int t;
string tc;
getline(cin,tc);
t = stoi(tc);
 while(t--){
   string s,ch;
   getline(cin,s);
   Node* root = build(s);
   Solution ob;
   vector<int> res = ob.bottomView(root);
   for(int i : res) cout<< i <<" ";
 }
return 0;
}
