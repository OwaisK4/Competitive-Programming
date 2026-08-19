#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data = 0){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = nullptr;
    }
    void insert(Node*& r, int data){
        if (r == nullptr){
            r = new Node(data);
        }
        else{
            if (r->data > data){
                insert(r->left, data);
            }
            else{
                insert(r->right, data);
            }
        }
    }
    void printInorder(Node* r){
        if (r == nullptr){
            return;
        }
        printInorder(r->left);
        cout << r->data << " ";
        printInorder(r->right);
    }
};

int main(){
    mt19937 mt(seed);
    uniform_int_distribution<int> uid(0,100);

    BST tree;
    for (int i=0; i<10; i++){
        int value = uid(mt);
        tree.insert(tree.root, value);
    }
    tree.printInorder(tree.root);

    return 0;
}