#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Definition of a Binary Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Recursive serial inorder traversal of a Binary Tree
void serial_inorder(struct Node* root) {
    if (root == NULL) return;
    serial_inorder(root->left);
    printf("%d ", root->data);
    serial_inorder(root->right);
}

// OpenMP task parallel inorder traversal of a Binary Tree
void parallel_inorder(struct Node* root) {
    if (root == NULL) return;
    #pragma omp task shared(root)
    parallel_inorder(root->left);
    printf("%d ", root->data);
    #pragma omp task shared(root)
    parallel_inorder(root->right);
    #pragma omp taskwait
}

int main() {
    printf("Sourish gupta - 20BCE0453\n");
    // Constructing a Binary Tree
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 1;

    root->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->data = 2;

    root->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->data = 3;

    root->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->data = 4;

    root->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->right->data = 5;

    root->right->left = (struct Node*)malloc(sizeof(struct Node));
    root->right->left->data = 6;

    root->right->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->right->data = 7;

    // Adding 10 more nodes to the Binary Tree
    root->left->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->left->data = 8;

    root->left->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->right->data = 9;

    root->left->right->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->right->left->data = 10;

    root->left->right->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->right->right->data = 11;

    root->right->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->right->left->left->data = 12;

    root->right->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->left->right->data = 13;

    root->right->right->left = (struct Node*)malloc(sizeof(struct Node));
    root->right->right->left->data = 14;

    root->right->right->right = (struct Node*)malloc(sizeof(struct Node));
    root->right->right->right->data = 15;

    root->left->left->left->left = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->left->left->data = 16;

    root->left->left->left->right = (struct Node*)malloc(sizeof(struct Node));
    root->left->left->left->right->data = 17;

    // Serial inorder traversal
    double s1 = omp_get_wtime();
    serial_inorder(root);
    double s2 = omp_get_wtime();
    printf("\nSerial Execution Time: %f seconds\n", s2 - s1);

    // Parallel inorder traversal using OpenMP Task
    double p1 = omp_get_wtime();
    #pragma omp parallel
    {
        #pragma omp single
        parallel_inorder(root);
    }
    double p2 = omp_get_wtime();
    printf("\nParallel Execution Time: %f seconds\n", p2 - p1);

    return 0;
}