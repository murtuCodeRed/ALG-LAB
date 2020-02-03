#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left; 
    struct Node* right;
};

typedef struct Node Node;

Node* getNode(int data){
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = data;
    t->right = t->left = NULL;

    return t;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int getHeight(Node* t){
    if(t == NULL)
        return 0;
    
    return 1 + max(getHeight(t->left), getHeight(t->right));
}

int getDiam(Node* t){
    if(t == NULL)
        return 0;

    int l_h = getHeight(t->left);
    int r_h = getHeight(t->right);
    int l_d = getDiam(t->left);
    int r_d = getDiam(t->right);
    return max(l_h + r_h + 1, max(l_d, r_d));
}

int main(){
    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->right->right = getNode(5);

    printf("Diam = %d\n", getDiam(root));
}