#include "stdlib.h"
#include "stdio.h"

struct treeNode{
	struct treeNode* lChild;
	struct treeNode* rChild;
	struct treeNode* parent;
	char cstr;	
};
typedef struct treeNode TreeNode;

struct binaryTree{
	TreeNode* root;
};
typedef struct binaryTree BinaryTree;

void preOrder(TreeNode* current){

	if(!current)
		return;
	printf("%c ",current->cstr);
	preOrder(current->lChild);
	preOrder(current->rChild);
}
void inOrder(TreeNode* current){
	if(!current)
		return;
	inOrder(current->lChild);
	printf("%c ",current->cstr);
	inOrder(current->rChild);
}
void postOrder(TreeNode* current){
	if(!current)
		return;
	postOrder(current->lChild);
	postOrder(current->rChild);
	printf("%c ",current->cstr);
}

int main(){
	TreeNode *nodeA = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeA->cstr = 'A'; 
	TreeNode *nodeB = (TreeNode*)malloc(sizeof(TreeNode));
        nodeB->cstr = 'B'; 
	TreeNode *nodeC = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeC->cstr = 'C'; 
	TreeNode *nodeD = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeD->cstr = 'D'; 
	TreeNode *nodeE = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeE->cstr = 'E'; 
	TreeNode *nodeF = (TreeNode*)malloc(sizeof(TreeNode));
	nodeF->cstr = 'F'; 
	TreeNode *nodeG = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeG->cstr = 'G'; 
	TreeNode *nodeH = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeH->cstr = 'H'; 
	TreeNode *nodeI = (TreeNode*)malloc(sizeof(TreeNode));
       	nodeI->cstr = 'I'; 
		
	nodeA->lChild = nodeB; nodeA->rChild = nodeC; 
	nodeB->lChild = nodeD; nodeB->rChild = nodeE;
	nodeC->lChild = nodeF; nodeC->rChild = NULL;
	nodeD->lChild = NULL;  nodeD->rChild = NULL;
	nodeE->lChild = nodeG; nodeE->rChild = nodeH;
	nodeF->lChild = NULL;  nodeF->rChild = nodeI;
	nodeG->lChild = NULL; nodeG->rChild = NULL;
	nodeH->lChild = NULL; nodeH->rChild = NULL;
	nodeI->lChild = NULL; nodeI->rChild = NULL;


	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root = nodeA;
	printf("\nPre-Order:\t");
	preOrder(root);
	printf("\nIn-Order:\t");
	inOrder(root);
	printf("\nPost-Order:\t");
	postOrder(root);
}
