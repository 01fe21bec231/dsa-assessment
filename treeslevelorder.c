#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void givespace(int c)
{
    for (int i = 0; i < c; i++)
        printf(" ");
}

void printTree(struct node* root, int lv)
{
    if (root == NULL)
        return;

    struct node* queue[100];  // Queue to store nodes
    int front = 0, rear = 0;  // Front and rear pointers of the queue

    queue[rear++] = root;  // Enqueue the root node

    while (front < rear)
    {
        int count = rear - front;

        while (count > 0) {
            struct node* node = queue[front++];
            givespace(lv * 4);
            printf("%d\n", node->data);

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;

            count--;
        }

        lv++;
    }
}

void random(struct node** root, FILE* file, int n)
{
    srand(time(NULL));
    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) {
        int num = rand();
        fprintf(file, "%d\t", num);

        // Construct the AVL tree while generating random numbers
        if (*root == NULL) {
            *root = create(num);
        } else {
            struct node* temp = *root;
            struct node* parent = NULL;
            while (temp != NULL) {
                parent = temp;
                if (num < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if (num < parent->data)
                parent->left = create(num);
            else
                parent->right = create(num);
        }
    }
}

int main() {
    struct node* root = NULL;
    FILE* file = fopen("random_numbers.txt", "a");

    int n = 10; // Number of random numbers to generate
    random(&root, file, n);
    fclose(file);

    printf("AVL Tree (Level Order Traversal):\n");
    printTree(root, 0);

    return 0;
}
