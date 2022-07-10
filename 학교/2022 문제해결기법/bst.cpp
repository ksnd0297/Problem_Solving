#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

typedef int element; // 이진 탐색 트리 element의 자료형을 char로 정의
typedef struct treeNode {
	int key; // 데이터 필드
	struct treeNode* left; // 왼쪽 서브 트리 링크 필드
	struct treeNode* right; // 오른쪽 서브 트리 링크 필드
}treeNode;

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, int x) {
	treeNode* p;
	p = root;
	while (p != NULL) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, int x) {
	treeNode* newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);

	return p;
}

// 루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
treeNode* deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;
	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) { // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 자식 노드를 한 개 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) child = p->left;
		else child = p->right;

		if (parent != NULL) {
			if (parent->left == p) parent->left = child;
			else parent->right = child;
		}
		else root = child;
	}

	// 삭제할 노드가 자식 노드를 두 개 가진 경우
	else {
		succ_parent = p;
		succ = p->right;
		while (succ->left != NULL) {
			succ_parent = succ;
			succ = succ->left;
		}
		if (succ_parent->right == succ) succ_parent->right = succ->right;
		else succ_parent->left = succ->right;
		p->key = succ->key;
		p = succ;
	}
	free(p);
	return root;
}

int getHeightNode(treeNode* tree) {
	int ret = 0;
	if (tree != NULL) {
		if (tree->key == NULL && tree->right == NULL) {
			ret = 1;
		}
		else {
			int leftChildHeight = getHeightNode(tree->left);
			int rightChildHeight = getHeightNode(tree->right);
			if (leftChildHeight >= rightChildHeight) ret = leftChildHeight + 1;
			else ret = rightChildHeight + 1;
		}
	}
	return ret;
}


int main() {
	freopen("bst.inp", "r", stdin);
	freopen("bst.out", "w", stdout);

	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char ch; int key;
	while (1) {
		cin >> ch >> key;
		if (key == -1) break;

		if (ch == 'i') root = insertNode(root, key);
		else if (ch == 'd') root = deleteNode(root, key);
	}
	cout << getHeightNode(root) - 1;
	return 0;
}