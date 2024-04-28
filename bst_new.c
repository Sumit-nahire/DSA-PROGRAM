//slip 1:Q1
/* save this header file as btree.h */
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *create(struct node *root) {
    struct node *nw, *t;
    root = NULL;
    int n;
    
    printf("Enter how many nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        nw = (struct node*) malloc(sizeof(struct node));
        nw->left = nw->right = NULL;

        printf("Enter node data: ");
        scanf("%d", &nw->data);

        if(root == NULL) {
            root = nw;
        } else {
            t = root;
            while(t != NULL) {
                if(nw->data < t->data) {
                    if(t->left == NULL) {
                        t->left = nw;
                        break;
                    } else {
                        t = t->left;
                    }
                } else {
                    if(t->right == NULL) {
                        t->right = nw;
                        break;
                    } else {
                        t = t->right;
                    }
                }
            }
        }
    }

    return root;
}

struct node *insert(struct node *root, int x) {
    if(root == NULL) {
        struct node *nw = (struct node*) malloc(sizeof(struct node));
        nw->left = nw->right = NULL;
        nw->data = x;
        root = nw;
        return root;
    }
    if(x < root->data) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf(" %d", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root;
    int ch, x;
    do {
        printf("\n         MENU\n");
        printf("1. create.\n");
        printf("2. insert.\n");
        printf("3. inorder.\n");
        printf("4. exit.\n");
        
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                root = create(root);
                printf("Tree created succesfully.\n");
                break;
            case 2:
                printf("Enter data : ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
        }
    } while(ch < 4);

    return 0;
}