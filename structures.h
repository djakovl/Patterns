#pragma once
#include <stack>
#include <vector>
struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class Stack {
	Node* top;
public:
	Stack() : top(nullptr) {}
	bool isEmpty() const { return top == nullptr; }

	void pop() {
		if (isEmpty()) return;
		Node* tmp = top;
		top = top->next;
		delete tmp;
	}

	void push(int n) {
		Node* new_el = new Node(n);
		new_el->next = top;
		top = new_el;
	}

	int peek() const { return top->data; }
};

class Queue {
	Node* front;
	Node* end;
public:
	Queue() : front(nullptr), end(nullptr) {}
	bool isEmpty() const { return front == nullptr; }

	int peek() const { return front->data; }

	void push(int n) {
		Node* new_el = new Node(n);
		if (isEmpty()) {
			front = end = new_el;
		}
		else {
			end->next = new_el;
			new_el = end;
		}
	}

	void pop() {
		if (isEmpty()) return;
		Node* tmp = front;
		front = front->next;
		if (!front) end = nullptr;
		delete tmp;
	}
};

class Deque {
	Node* front;
	Node* end;
public:
	Deque() : front(nullptr), end(nullptr) {}
	bool isEmpty() const { return front == nullptr; }
	int peekFront() const { return front->data; }
	int peekEnd() const { return end->data; }

	void pushFront(int n) {
		Node* new_el = new Node(n);
		if (isEmpty()) {
			front = end = new_el;
		}
		else {
			new_el->next = front;
			front->prev = new_el;
			front = new_el;
		}
	}
	void pushEnd(int n) {
		Node* new_el = new Node(n);
		if (isEmpty()) {
			front = end = new_el;
		}
		else {
			end->next = new_el;
			new_el->prev = end;
			end = new_el;
		}
	}

	void popFront() {
		if (isEmpty()) return;
		Node* tmp = front;
		front = front->next;
		if (front) {
			front->next = nullptr;
		}
		else {
			front = nullptr;
			end = nullptr;
		}
		delete tmp;
	}

	void popEnd() {
		if (isEmpty()) return;
		Node* tmp = end;
		end = end->prev;
		if (end) {
			end->next = nullptr;
		}
		else {
			front = nullptr;
			end = nullptr;
		}
		delete tmp;
	}
};


struct TNode {
	int data;
	TNode* left;
	TNode* right;
	TNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

class BinaryTree {
	TNode* root = nullptr;

	int height(TNode* node) {
		if (!node) return 0;
		int lh = height(node->left),
			rh = height(node->right);
		return 1 + ((lh > rh) ? lh : rh);
	}
	int isBalanced(TNode* node) {
		if (!node) return 0;
		int lh = isBalanced(node->left),
			rh = isBalanced(node->right);
		if (lh == -1) return -1;
		if (rh == -1) return -1;
		if (abs(lh - rh) > 1) return -1;
		return 1 + ((lh > rh) ? lh : rh);
	}

	TNode* deleteNode(TNode* node, int key) {
		if (!node) return nullptr;

		if (key < node->data) {
			node->left = deleteNode(node->left, key);
		}
		else if (key > node->data) {
			node->right = deleteNode(node->right, key);
		}
		else {
			if (!node->left && !node->right) {
				delete node;
				return nullptr;
			}
			else if (!node->left) {
				TNode* tmp = node->right;
				delete node;
				return tmp;
			}
			else if (!node->right) {
				TNode* tmp = node->left;
				delete node;
				return tmp;
			}
			else {
				TNode* succ = node->right;
				while (succ->left) succ = succ->left;
				node->data = succ->data;
				node->right = deleteNode(node->right, succ->data);
			}
		}
		return node;
	}

	void inorder(TNode* node, std::vector<int>& v) {
		if (!node) return;
		inorder(node->left, v);
		v.push_back(node->data);
		inorder(node->right, v);
	}

	void destroy(TNode* node) {
		if (!node) return;
		destroy(node->left);
		destroy(node->right);
		delete node;
	}

	TNode* buildBalanced(const std::vector<int>& v, int l, int r) {
		if (l > r) return nullptr;
		int m = (l + r) / 2;
		TNode* node = new TNode(v[m]);
		node->left = buildBalanced(v, l, m - 1);
		node->right = buildBalanced(v, m + 1, r);
		return node;
	}

public:
	bool isEmpty() {
		return root == nullptr;
	}

	void add(int d) {
		TNode* tmp = root;
		if (isEmpty()) {
			root = new TNode(d); return;
		}
		while (true)
		{
			if (d == tmp->data) { return; }
			if (d < tmp->data) {
				if (tmp->left == nullptr) { tmp->left = new TNode(d); return; }
				tmp = tmp->left;
			}
			else if (d > tmp->data) {
				if (tmp->right == nullptr) { tmp->right = new TNode(d); return; }
				tmp = tmp->right;
			}
		}
	}

	void DFS() {
		if (isEmpty()) return;
		std::stack<TNode*> st;
		st.push(root);
		while (!st.empty()) {
			TNode* cur = st.top();
			st.pop();
			printf("%d ", cur->data);
			if (cur->right) st.push(cur->right);
			if (cur->left) st.push(cur->left);
		}
	}

	void balance() {
		if (isBalanced() || isEmpty()) return;
		std::vector<int> vals;
		inorder(root, vals);
		destroy(root);
		root = buildBalanced(vals, 0, (int)vals.size() - 1);
	}

	bool isBalanced() {
		return isBalanced(root) != -1;
	}

	void deleteNode(int key) {
		root = deleteNode(root, key);
	}
};