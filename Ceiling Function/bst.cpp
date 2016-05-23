#define NULL nullptr
#include "bst.h"

btree::btree()
{
	root = NULL;
}

btree::~btree()
{
	//destroy_tree();
}

node* btree::root_f()
{
    return root;
}

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leftchild_count++;
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			rightchild_count++;
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}

node *btree::search(int key, node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key_value)
			return leaf;
		if (key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void btree::insert(int key)
{
	emptychild_count += 2;
	if (root != NULL) {
		insert(key, root);
	}
	else
	{
		root_count++;
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

/*bool equalCheck(Node *lhs, Node *rhs)
{
    if (lhs == null && rhs == null)
        return true;
    if ((lhs == null && rhs != null) || (lhs != null && rhs == null))
        return false;

    return equalCheck(lhs.left(), rhs.left()) && equalTrees(lhs.right(), rhs.right())
}*/

node *btree::search(int key)
{
	return search(key, root);
}

void btree::destroy_tree()
{
	destroy_tree(root);
}


bool btree::equalTreeShape(btree alt_tree)
{
	if ((root_count == alt_tree.root_count) && (leftchild_count == alt_tree.leftchild_count) && (rightchild_count == alt_tree.rightchild_count))
	{
		return true;
	}
	else
	{
		return false;
	}
}
