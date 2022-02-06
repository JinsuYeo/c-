#include <iostream>

using namespace std;

typedef struct node *tree_node;
typedef struct node {
    char data;
    char left, right;
    tree_node left_node, right_node;
} node;

node nodes[27];

void preorder(tree_node ptr) {
    if(ptr) {
        cout << ptr->data;
        preorder(ptr->left_node);
        preorder(ptr->right_node);
    }
}

void inorder(tree_node ptr) {
    if(ptr) {
        inorder(ptr->left_node);
        cout << ptr->data;
        inorder(ptr->right_node);
    }
}

void postorder(tree_node ptr) {
    if(ptr) {
        postorder(ptr->left_node);
        postorder(ptr->right_node);
        cout << ptr->data;
    }
}

int main(){
    int n{};
    cin >> n;
    
    for (int i{1}; i <= n; i++) {
        cin >> nodes[i].data;
        cin >> nodes[i].left;
        cin >> nodes[i].right;
        nodes[i].left_node = NULL;
        nodes[i].right_node = NULL;
    }
    
    for (int i{1}; i <= n; i++) {
        for (int j{1}; j <= n; j++) {
            if(nodes[i].left == nodes[j].data) nodes[i].left_node = &nodes[j];
            else if(nodes[i].right == nodes[j].data) nodes[i].right_node = &nodes[j];
            else continue;
        }
    }
    
    preorder(&nodes[1]);
    cout << "\n";
    inorder(&nodes[1]);
    cout << "\n";
    postorder(&nodes[1]);
    
    return 0;
}
