#include "bst.h"
#include <iostream>

using namespace std;

bool equalCheck(node *lhs, node *rhs)
{
    if (lhs == NULL && rhs == NULL){
        return true;
    }
    if ((lhs == NULL && rhs != NULL) || (lhs != NULL && rhs == NULL)){
        return false;
    }

    return equalCheck(lhs->left, rhs->left) && equalCheck(lhs->right, rhs->right);
}

int main(void)
{
	//btree binary_tree_1;
	//btree binary_tree_2;
	btree btreeArr[50];
	int n, k, temp;
	std::cin >> n >> k;
	int cnt = n;
	//cout << cnt << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cin >> temp;
			btreeArr[i].insert(temp);
		}
		//cout << "btreeArr[" << i << "] : \n" << "rootCount -> " << btreeArr[i].root_count << "\nrightChildCount -> " << btreeArr[i].rightchild_count << "\nleftChildCount -> " << btreeArr[i].leftchild_count << endl;
	}
	for (int i = 0; i < 50; i++)
	{
		for (int j = 1; j < 50; j++)
		{
			if ((equalCheck(btreeArr[i].root_f(),btreeArr[j].root_f()) == true) && (btreeArr[i].root_count != 0) && (i != j) )
			{
				//cout << "Equal Shape : " << i << " " << j << endl;
				cnt--;
				//cout << cnt << endl;
			}
		}
	}
	for (int i = 0; i < 50; i++)
	{
		btreeArr[i].destroy_tree();
	}
	cout << cnt << endl;
	//system("pause");

	return 0;
}
