#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, y[100], x[100], radius[100];

struct TreeNode {
	vector<TreeNode*> children;
};

// 지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다.
int longest;

int height(TreeNode* root);
int solve(TreeNode* root);
TreeNode* getTree(int root);
int sqr(int x);
int sqrdist(int a, int b);
bool encloses(int a, int b);
bool isChild(int parent, int child);

int main() {
	int C; cin >> C;
	while (C--) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> y[i] >> x[i] >> radius[i];
		
		TreeNode* T = getTree(0);
		cout << solve(T) << '\n';
	}
	return 0;
}

//root를 루트로 하는 서브트리의 높이를 반환한다.
int height(TreeNode* root) {
	//각 자식을 루트로 하는 서브트리의 높이를 계산한다.
	vector<int> heights;
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));

	// 만약 자식이 하나도 없다면 0을 반환한다.
	if (heights.empty()) return 0;
	sort(heights.begin(), heights.end());
	//root를 최상위 노드로 하는 경로를 고려하자.
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	// 트리의 높이는 서브트리 높이의 최대치에 1을 더해 계산한다.
	return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산한다.
int solve(TreeNode* root) {
	longest = 0;
	//트리의 높이와 최대 잎-잎 경로 길이 중 큰것을 선택한다.
	int h = height(root);
	return max(longest, h);
}

// root 성벽을 루트로 하는 트리를 생성한다.
TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	for (int ch = 0; ch < n; ch++)
		// ch 성벽이 root 성벽에 직접적으로 포함되어 있다면
		// 트리를 만들고 자손 목록에 추가한다.
		if (isChild(root, ch)) ret->children.push_back(getTree(ch));
	return ret;
}

// x^2을 반환한다.
int sqr(int x) {
	return x * x;
}

// 두 성벽 a,b의 중심점간의 거리의 제곱을 반환한다.
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

// 성벽 a가 성벽 b를 포함하는지 확인한다.
bool encloses(int a, int b) {
	return radius[a] > radius[b] && sqrdist(a, b) < sqr(radius[a] - radius[b]);
}

bool isChild(int parent, int child) {
	if (!encloses(parent, child)) return false;
	for (int i = 0; i < n; i++)
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child)) return false;
	return true;
}