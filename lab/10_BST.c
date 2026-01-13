/*a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Exit
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) return create(data);
    if (data < root->data) 
    root->left = insert(root->left, data);
    else if (data > root->data) 
    root->right = insert(root->right, data);
    return root;
}

void inorder(struct node* root) {
    if (root) { inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right); }
}

void preorder(struct node* root) {
    if (root) { printf("%d ", root->data); 
        preorder(root->left); 
        preorder(root->right); }
}

void postorder(struct node* root) {
    if (root) { postorder(root->left); 
        postorder(root->right); 
        printf("%d ", root->data); }
}

void search(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->data) 
        { printf("\nKey Found!"); return; }

        if (key < root->data) 
        root = root->left;
        else root = root->right;
    }
    printf("\nKey NOT Found!");
}

int main() {
    struct node* root = NULL;
    int ch, n, i, val, key;
    while (1) {
        printf("\n1.Create 2.Search 3.Traverse 4.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter N: "); scanf("%d", &n);
                    printf("Enter values: ");
                    for(i=0; i<n; i++) { scanf("%d", &val); root = insert(root, val); }
                    break;
                    
            case 2: printf("Enter key: "); scanf("%d", &key); search(root, key); break;
            case 3: printf("\nPreorder: "); preorder(root);
                    printf("\nInorder:  "); inorder(root);
                    printf("\nPostorder: "); postorder(root); break;
            case 4: exit(0);
        }
    }
    return 0;
}