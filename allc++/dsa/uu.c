#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NULL_PTR 0

// Global arrays to represent the binary tree
int INFO[MAX_SIZE];       // Stores node data
int LEFT[MAX_SIZE];       // Stores indices of left children
int RIGHT[MAX_SIZE];      // Stores indices of right children
int STACK[MAX_SIZE];      // Stack for traversal
int ROOT;                 // Index of root node
int AVAIL = 0;            // Pointer to next available index

// Initialize the AVAIL list (linked list of free indices)
void initAvail() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        LEFT[i] = i + 1;
    }
    LEFT[MAX_SIZE - 1] = NULL_PTR;
}

// Allocate a new node from AVAIL list
int allocateNode() {
    if (AVAIL == NULL_PTR) {
        printf("Error: No space available\n");
        exit(1);
    }
    int newNode = AVAIL;
    AVAIL = LEFT[AVAIL];
    return newNode;
}

// Function to process a node (prints the data)
void process(int data) {
    printf("%d ", data);
}

// Inorder traversal function
void inorder(int* info, int* left, int* right, int root) {
    int top = 1;
    STACK[1] = NULL_PTR;
    int ptr = root;

    // Step 2: Push leftmost path onto stack
    while (ptr != NULL_PTR) {
        top = top + 1;
        STACK[top] = ptr;
        ptr = left[ptr];
    }

    // Step 3: Pop node from stack
    ptr = STACK[top];
    top = top - 1;

    // Step 4: Backtracking loop
    while (ptr != NULL_PTR) {
        // Step 5: Apply PROCESS to INFO[PTR]
        process(info[ptr]);

        // Step 6: Right child?
        if (right[ptr] != NULL_PTR) {
            ptr = right[ptr];
            // Go to Step 3
            while (ptr != NULL_PTR) {
                top = top + 1;
                STACK[top] = ptr;
                ptr = left[ptr];
            }
            ptr = STACK[top];
            top = top - 1;
        } else {
            // Step 7: Pop node
            ptr = STACK[top];
            top = top - 1;
        }
    }
}

// Main function to test the inorder traversal
int main() {
    // Initialize AVAIL list
    initAvail();

    // Create a sample binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    // Allocate nodes
    ROOT = allocateNode();
    INFO[ROOT] = 1;
    LEFT[ROOT] = allocateNode();
    RIGHT[ROOT] = allocateNode();
    INFO[LEFT[ROOT]] = 2;
    INFO[RIGHT[ROOT]] = 3;
    LEFT[RIGHT[ROOT]] = NULL_PTR;
    RIGHT[RIGHT[ROOT]] = NULL_PTR;
    LEFT[LEFT[ROOT]] = allocateNode();
    RIGHT[LEFT[ROOT]] = allocateNode();
    INFO[LEFT[LEFT[ROOT]]] = 4;
    INFO[RIGHT[LEFT[ROOT]]] = 5;
    LEFT[LEFT[LEFT[ROOT]]] = NULL_PTR;
    RIGHT[LEFT[LEFT[ROOT]]] = NULL_PTR;
    LEFT[RIGHT[LEFT[ROOT]]] = NULL_PTR;
    RIGHT[RIGHT[LEFT[ROOT]]] = NULL_PTR;

    // Perform inorder traversal
    inorder(INFO, LEFT, RIGHT, ROOT);

    return 0;
}