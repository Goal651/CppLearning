#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>

struct TreeNode {
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T d) {
        data = d;
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* f = q.front();
        q.pop();
        cout << "Enter number of children of " << f->data << endl;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int childData;
            cout << "Enter " << i << "th child of " << f->data << endl;
            int n;
            cin >> n;
            TreeNode<int> *child = new TreeNode<int>(n);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;

}


void printTree(TreeNode<int> *root) {
    if(root == NULL) {
        return ;
    }

    cout << root->data << ":";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}

void printTreeLevelWise(TreeNode<int> *root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    int counter = 0;
    while(!q.empty()) {
        TreeNode<int>* f = q.front();
        counter++;
        q.pop();
        cout << f->data << ":";
        for(int i = 0; i < f->children.size(); i++) {
            cout << f->children[i]->data << ",";
        }
        cout << endl;
        for(int i = 0; i < f->children.size(); i++) {
            q.push(f->children[i]);
        }
    }
    cout << "The number of nodes is " << counter << endl;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    cout << "printin level wise" << endl;
    printTreeLevelWise(root);
    return 0;
}