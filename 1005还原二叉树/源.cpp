#include<iostream>
#include<vector>
using namespace std;
const int maxn = 33;
vector<int> layer, pre, in, post;

struct node {
	int data;
	node *lchild, *rchild;
};

node* newNode(int x) {
	node* root = new node;
	root->data = x;
	root->rchild = root->rchild = NULL;
	return root;
}

node* creatTree(vector<int> layer, int inL, int inR) {
	if (layer.size() == 0) {
		return NULL;
	}
	node* root = newNode(layer[0]);
	int k;
	int x = layer[0];
	for (k = inL; k < inR; k++) {
		if (in[k] == x)
			break;
	}
	vector<int> leftLayer, RightLayer;
	for (int i = 1; i < layer.size(); i++) {
		bool isleft = false;
		for (int j = inL; j < k; j++) {
			if (layer[i] == in[j]) {
				isleft = true; break;
			}
		}
		if (isleft) {
			leftLayer.push_back(layer[i]);
		} else
			RightLayer.push_back(layer[i]);
	}
	root->lchild = creatTree(leftLayer, inL, k - 1);
	root->rchild = creatTree(RightLayer, k + 1, inR);
	return root;
}

void preOrder(node* root) {
	if (root == NULL)return;
	pre.push_back(root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void postOrder(node* root) {
	if (root == NULL)return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	post.push_back(root->data);
}
int main() {
	int n;
	cin>> n;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		layer.push_back(temp);
	}
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		in.push_back(temp);
	}
	node* root = creatTree(layer, 0, n - 1);
	postOrder(root);
	preOrder(root);
	for (int i = 0; i < n; i++) {
		printf("%d", pre[i]);
		if (i < n - 1)
			printf(" ");
		else
			printf("\n");
	}
	for (int i = 0; i < n; i++) {
		printf("%d", post[i]);
		if (i < n - 1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}