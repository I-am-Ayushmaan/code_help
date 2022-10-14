#include <bits/stdc++.h>
using namespace std;


struct Node {
     int val;
     Node *left;
     Node *right;
      Node() : val(0), left(nullptr), right(nullptr) {}
      Node(int x) : val(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
 };

class BST{
    private:
    Node* root= new Node();
    public:

    BST(){}
    BST(int _v){
        root->val=_v;
    }
};

int main(void){
 


}