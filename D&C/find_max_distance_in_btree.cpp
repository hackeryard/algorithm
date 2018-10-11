#include<iostream>
using namespace std;
typedef struct BiTNode
{
    BiTNode *left;
    BiTNode *right;
    int h;
    int val;
}BiTNode, *BiTree; // using pointer

void createTree(BiTree &root)
{
    BiTree left1 = new(BiTNode);
    BiTree right1 = new(BiTNode);
    
    left1->left = NULL;
    left1->right = NULL;
    left1->val = 2;
    left1->h = 0;
    right1->left = NULL;
    right1->right = NULL;
    right1->val = 90;
    right1->h = 0;

    root->left = left1;
//    root->right = right1;
	root->right = NULL;

    BiTree left2 = new(BiTNode);
    left2->left = NULL;
    left2->right = NULL;
    left2->val = 3;
    left2->h = 0;
    
    BiTree right2 = new(BiTNode);
    right2->left = NULL;
    right2->right = NULL;
    right2->val = 4;
    right2->h = 0;
    
    left1->left = left2;
    left1->right = right2;

    BiTree left3 = new(BiTNode);
    left3->left = NULL;
    left3->right = NULL;
    left3->val = 5;
    left3->h = 0;
    BiTree right3 = new(BiTNode);
    right3->left = NULL;
    right3->right = NULL;
    right3->val = 6;
    right3->h = 0;
    
    left2->left = left3;
    left2->right = right3;
    
    
    BiTree right3_l = new(BiTNode);
    right3_l->left = NULL;
    right3_l->right = NULL;
    right3_l->val = 7;
    right3_l->h = 0;
    
    right2->left = right3_l;
//    right2->right = right3_l;
	right2->right = NULL;
}

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

/*
int height(BiTree root)
{
    if(root == NULL)
        return 0;
    else 
        return height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
        //存在未保存调用结果的问题 也即时间复杂度会增加 修改为get_height函数 
}
*/

// Note that 层数和深度相差1 
int height(BiTree root)
{
	if(root == NULL){
//		root->h = 0;
//		printf("height: %d\n", root->h);
		return 0;
	} else {
		int left_height = height(root->left);
		int right_height = height(root->right);
		root->h = (left_height>right_height)?left_height+1:right_height+1;
		printf("height: %d\n", root->h);
		return root->h;
	}
}

int get_height(BiTree node){
	if(node == NULL){
		return 0;
	} else {
		return node->h;
	}	
}

int max(int a, int b, int c)
{
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}

int treeDistance(BiTree root)
{
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root->right == NULL)
        return 0;
    int dis = max(get_height(root->left) + get_height(root->right), treeDistance(root->left), treeDistance(root->right));
    return dis;
}

void preorder(BiTree node){
	if(node == NULL){
		return;
	} else {
		printf("node val: %d, height: %d\n", node->val, node->h);
	}
	
	preorder(node->left);
	preorder(node->right);
	
}

int main()
{
    BiTree root = new(BiTNode);
    root->right = root->left = NULL;
    root->val = 9;
    root->h = 0;
    createTree(root);  
	
	// preorder traverse
	cout << "preorder traverse:" << endl;
	preorder(root);
    cout << "root height:" << height(root) << endl;
    preorder(root);
    cout << "tree max distance:" << treeDistance(root) << endl;
    cout << "_____________________" << endl;
    
    deleteTree(root);
}
