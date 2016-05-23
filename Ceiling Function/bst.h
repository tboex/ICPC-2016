#pragma once
#include <vector>
#include <math.h>

struct node
{
	int key_value;
	node *left;
	node *right;
};

class btree
{
public:
	btree();
	~btree();
	int count;
	int root_count = 0;
	int leftchild_count = 0;
	int rightchild_count = 0;
        int emptychild_count = 0;
	void insert(int key);
	node *search(int key);
	void destroy_tree();
	bool equalTreeShape(btree alt_tree);
        node *root_f();
	//bool equalCheck(Node *lhs, Node *rhs);
private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);

	node *root;
};
