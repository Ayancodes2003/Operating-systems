#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
typedef struct TreeNode {
    int processId;
    int parentId;
    struct TreeNode *child;
    struct TreeNode *sibling;
} TreeNode;

// Create a new tree node
TreeNode* createTreeNode(int processId, int parentId) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->processId = processId;
    newNode->parentId = parentId;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

// Display the process tree
void displayProcessTree(TreeNode* root, int depth) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("-> %d(parent:%d)\n", root->processId, root->parentId);

    displayProcessTree(root->child, depth + 1); // Display child nodes
    displayProcessTree(root->sibling, depth); // Display sibling nodes
}

int main() {
    // Create the process tree
    TreeNode* po = createTreeNode(0, -1);
    TreeNode* p1 = createTreeNode(1, 0);
    TreeNode* p2 = createTreeNode(2, 0);
    TreeNode* p3 = createTreeNode(3, 1);
    TreeNode* p4 = createTreeNode(4, 0);
    TreeNode* p5 = createTreeNode(5, 2);
    TreeNode* p7 = createTreeNode(7, 1);
    TreeNode* p8 = createTreeNode(8, 2);

    // Build the process tree
    po->child = p1;
    p1->child = p3;
    p3->sibling = p7;
    po->child->sibling = p2;
    p2->child = p5;
    p5->sibling = p8;
    po->child->sibling->sibling = p4;

    // Display the process tree
    printf("Process Tree:\n");
    displayProcessTree(po, 0);

    return 0;
}
