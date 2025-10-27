//binary tree traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
//pre-order

typedef struct node TreeNode;
TreeNode* createNewNode(int val){
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void preOrder(TreeNode *root){
	if(root != NULL){
		printf("%d ",root->data);
		preOrder(root->left);  
		preOrder(root->right);
	}
}
void InOrder(TreeNode *root){
	if(root != NULL){
		InOrder(root->left); 
		printf("%d ",root->data); 
		InOrder(root->right);
	}
}
void postOrder(TreeNode *root){
	if(root != NULL){
		postOrder(root->left);  
		postOrder(root->right);
		printf("%d ",root->data);
	}
}
void levelOrder( struct node *root) {
    //queue
    struct node *q[500];
    int front = 0;
    int rear = 0;
    q[rear] = root;
    rear++;
    //run a loop as long queue is not empty
    while(front!=rear){
        struct node *dn = q[front++];
        printf("%d ",dn->data);
        if(dn->left!=NULL){
            q[rear]=dn->left;
            rear++;
        }
        if(dn->right!=NULL){
            q[rear]=dn->right;
            rear++;
        }
        free(dn);
    }
}
int main(){
	//Create Nodes
	TreeNode *node1 = createNewNode(10);
	TreeNode *node2 = createNewNode(20);
	TreeNode *node3 = createNewNode(30);
	TreeNode *node4 = createNewNode(40);
	TreeNode *node5 = createNewNode(50);
	TreeNode *node6 = createNewNode(60);
	TreeNode *node7 = createNewNode(70);
	//connection
	node1->left = node2;
	node1->right = node3;
	
	node2->left = node4;
	node2->right = node5;
	
	node3->left = node6;
	node3->right = node7;
	
	TreeNode *root = node1; //root node
	preOrder(root);
	InOrder(root);
	postOrder(root);
	levelOrder(root);

}
/*
	Post order-->40,50,20,60,70,30,10
	-------
	call 1
	-------
void postorder(10){
	if(10!= NULL){
		inorder(20);
		inorder(30);
		printf("%d",root->data);
	}
}
	------
	call 2
	------
void postorder(20){
	if(20!= NULL){
		inorder(40);
		inorder(50);
		printf("%d",root->data);
	}
}
void postorder(40){
	if(40!= NULL){
		inorder(NULL);
		inorder(root->right);
		printf("%d",root->data);
	}
}


*/
