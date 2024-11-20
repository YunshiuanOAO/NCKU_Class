#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;                // 節點的鍵值
    int npl;                // 零距 (null path length)
    struct Node* left;      // 左子樹
    struct Node* right;     // 右子樹
} Node;

// 創建新節點
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->npl = 0;
    node->left = node->right = NULL;
    return node;
}

// 合併兩棵左偏樹
Node* merge(Node* h1, Node* h2) {
    if (!h1) return h2;
    if (!h2) return h1;
    if (h1->key > h2->key) { // 保證 h1 是擁有較小鍵值的樹根
        Node* temp = h1;
        h1 = h2;
        h2 = temp;
    }

    h1->right = merge(h1->right, h2); // 將 h2 合併到 h1 的右子樹

    // 檢查並維護左偏性質
    if (!h1->left || (h1->left->npl < h1->right->npl)) {
        Node* temp = h1->left;
        h1->left = h1->right;
        h1->right = temp;
    }

    // 更新 h1 的零距
    h1->npl = (h1->right ? h1->right->npl : 0) + 1;

    return h1;
}

// 插入鍵值到左偏樹
Node* insert(Node* root, int key) {
    Node* newNode = createNode(key);
    return merge(root, newNode);
}

// 刪除最小值
Node* deleteMin(Node* root) {
    if (!root) return NULL;
    Node* left = root->left;
    Node* right = root->right;
    free(root);
    return merge(left, right);
}

// 前序遍歷左偏樹
void preOrder(Node* root) {
    if (root) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// 釋放整棵樹
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    
    // 插入一些節點
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);

    printf("前序遍歷: ");
    preOrder(root);
    printf("\n");

    // 刪除最小值
    root = deleteMin(root);
    printf("刪除最小值後的前序遍歷: ");
    preOrder(root);
    printf("\n");

    // 釋放樹
    freeTree(root);

    return 0;
}
