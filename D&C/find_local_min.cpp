#include<iostream>
using namespace std;
typedef struct BiTNode
{
    BiTNode *left;
    BiTNode *right;
    int val;
}BiTNode, *BiTree; // using pointer


void deleteTree(BiTree root)
{
    if(root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        delete(root);
        root = NULL;
    }
}

int max(int a, int b, int c)
{
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}


void preorder(BiTree node){
	if(node == NULL){
		return;
	} else {
		printf("node: %d \n", node->val);
	}
	
	preorder(node->left);
	preorder(node->right);
	
}

void createTree(BiTree &root)
{
    BiTree left1 = new(BiTNode);
    BiTree right1 = new(BiTNode);
    
    left1->left = NULL;
    left1->right = NULL;
    left1->val = 10;
    
    right1->left = NULL;
    right1->right = NULL;
    right1->val = 3;
    
    root->left = left1;
    root->right = right1;
    
    BiTree left1_l = new(BiTNode);
    BiTree left1_r = new(BiTNode);
    left1_l->left = left1_l->right = NULL;
    left1_l->val = 20;
    left1_r->left = left1_r->right = NULL;
    left1_r->val = 7;
    
    left1->left = left1_l;
    left1->right = left1_r;
    
    
    BiTree right1_l = new(BiTNode);
    BiTree right1_r = new(BiTNode);
    right1_l->left = right1_l->right = NULL;
    right1_l->val = 1;
    right1_r->left = right1_r->right = NULL;
    right1_r->val = 8;
    
    right1->left = right1_l;
    right1->right = right1_r;

}

int search_local_min(BiTree root){
	if(root->left == NULL){
		return root->val;
	}
	if(root->val < root->left->val && root->val < root->right->val){
		return root->val;
	} else {
		if(root->left->val < root->right->val){
			return search_local_min(root->left);
		} else {
			return search_local_min(root->right);
		}
	}
}

int main()
{
    BiTree root = new(BiTNode);
    root->right = root->left = NULL;
    root->val = 9;
    createTree(root);  
	
	// preorder traverse
	cout << "preorder traverse:" << endl;
	preorder(root);
    
    cout << "local min:" << search_local_min(root) << endl;
    deleteTree(root);
}
