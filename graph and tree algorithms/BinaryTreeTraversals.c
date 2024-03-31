#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void Inorder(struct node* _node)
{
	if (_node == NULL)
		return;

	Inorder(_node->left);
	printf("%d ", _node->data);
	Inorder(_node->right);
}
void PreOrder(struct node* _node){

	if (_node == NULL)
		return;
 	printf("%d ", _node->data);
	PreOrder(_node->left);
	PreOrder(_node->right);

}
void PostOrder(struct node* _node){
		if (_node == NULL)
		return;
 
	PostOrder(_node->left);
	PostOrder(_node->right);
	printf("%d ", _node->data);
}
int main()
{
	struct node* root = newNode(100);
	//adding nodes to the tree
	root->left = newNode(20);
	root->right = newNode(1);
	root->right->right = newNode(666);
	root->left->left = newNode(-4);
	root->left->right = newNode(6);

	printf("Inorder traversal \n");
	Inorder(root);

	printf("\n Preorder traversal \n");
	PreOrder(root);

	printf("\n PostOrder traversal \n");
	PostOrder(root);

	getchar();
	return 0;
}
