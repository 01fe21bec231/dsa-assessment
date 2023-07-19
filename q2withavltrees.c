#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct node* node) {
    if (node == NULL)
        return 0;
    else
        return node->height;
}

int getBalance(struct node* node) {
    if (node == NULL)
        return 0;
    else
        return height(node->left) - height(node->right);
}

struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct node* insert(struct node* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct node* minValueNode(struct node* node)
 {
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            struct node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printSpaces(int count) {
    for (int i = 0; i < count; i++)
        printf(" ");
}

void printTree(struct node* root, int level) {
    if (root == NULL)
        return;

    int i;
    printTree(root->right, level + 1);
    printSpaces(level * 4);
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}

void generateRandomNumbers(struct node** root, FILE* file, int n) {
    srand(time(NULL));
    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) {
        int num = rand();
        fprintf(file, "%d\t", num);

        // Construct the AVL tree while generating random numbers
        if (*root == NULL)
            *root = newNode(num);
        else
            *root = insert(*root, num);
    }
}

void display(struct node* root) {
    printf("AVL Tree:\n");
    printTree(root, 0);
    printf("\n");
}

int main() {
    struct node* root = NULL;
    FILE* file = fopen("random_numbers.txt", "w");

    int n = 10; // Number of random numbers to generate
    generateRandomNumbers(&root, file, n);
    fclose(file);

    printf("Initial AVL Tree:\n");
    display(root);

    int ch, numdel;

    while (1) {
        printf("1. Delete a node\n");
        printf("2. Display AVL Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the number to delete: ");
                scanf("%d", &numdel);
                root = deleteNode(root, numdel);
                printf("AVL Tree after deletion:\n");
                display(root);
                break;
            case 2:
                display(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
