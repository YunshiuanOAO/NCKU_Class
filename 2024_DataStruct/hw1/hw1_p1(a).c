#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct BinaryTree{
	struct BinaryTree *left;
	struct BinaryTree *right;
	struct BinaryTree *parent;
	char value;
};
typedef struct BinaryTree BinaryTree;

char expression[200];

void addNote(BinaryTree* tree){
	int len = strlen(expression);
	int now =0;
	tree->value = expression[now];
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	now++;
	
	while(now < len){
		//printf("now root -> %c\n" , tree->value);
		//printf("now ch -> %c\n",expression[now]);
		if(expression[now] == '/' || expression[now] == '-' || expression[now] == '+' || expression[now] == '*'){
			if(tree->left == NULL){
				tree->left = (BinaryTree *)malloc(sizeof(BinaryTree));
				tree->left->value = expression[now];
				
				tree->left->parent = tree;
				tree = tree->left;
				tree->left = NULL;
				tree->right = NULL;
			}else{
				tree->right = (BinaryTree *)malloc(sizeof(BinaryTree));
				tree->right->value = expression[now];
				
				tree->right->parent = tree;
				
				tree = tree->right;
				tree->left = NULL;
				tree->right = NULL;
				
				while(tree->right != NULL && tree->parent != NULL){
					tree = tree->parent;
				}
			}
			now++;
		}else{
			if(tree->left == NULL){
				tree->left = (BinaryTree *)malloc(sizeof(BinaryTree));
				
				tree->left->value = expression[now];
				
				tree->left->parent = tree;
				tree->left->left = NULL;
				tree->left->right = NULL;
				
			}else{
				tree->right = (BinaryTree *)malloc(sizeof(BinaryTree));
				
				tree->right->value = expression[now];
				
				tree->right->parent = tree;
				tree->right->left = NULL;
				tree->right->right = NULL;
				
				while(tree->right != NULL && tree->parent != NULL){
					tree = tree->parent;
					
				}
			}
			now++;
		}
	}
}

void inorderTraversal(BinaryTree* root) {
	if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%c", root->value);
    inorderTraversal(root->right);
}

int main(){
    scanf("%s",expression); 
    BinaryTree* root = (BinaryTree *)malloc(sizeof(BinaryTree));
    addNote(root);
	inorderTraversal(root);
}
