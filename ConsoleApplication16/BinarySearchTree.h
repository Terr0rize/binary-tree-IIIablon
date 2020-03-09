#pragma once
#include "pch.h"
#include <iostream>
using namespace std;
template<class T>
class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		T data;
	};
	tree_node* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void insert(T);
	void remove(T);	
	bool search(T);
	void vivod(tree_node * p, T d);
	/*void vivod(T);*/
};

template <class T>
void BinarySearchTree<T>::insert(T d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	// ��� ����� ������?
	if (isEmpty()) root = t;
	else
	{
		//��� ������� ��� �������� ����
		tree_node* curr;
		curr = root;
		//����� �������� ����
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}


template <class T>
void BinarySearchTree<T>::remove(T d)
{
	bool found = false;
	if (isEmpty())
	{
		cout << "������ ������! " << endl;
		return;
	}
	tree_node* curr;
	tree_node* parent;
	curr = root;
	parent = (tree_node*)NULL;
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << "������ �� �������! " << endl;
		return;
	}

	// ���� � ����� ��������
	if ((curr->left == NULL && curr->right != NULL) || (curr->left != NULL
		&& curr->right == NULL))
	{
		if (curr->left == NULL && curr->right != NULL)
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;
			}
		}
		else // ����� ������� ������������, ������� ������� ���
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;
			}
		}
		return;
	}

	//�������� ����
	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent == NULL)
		{
			delete curr;

		}
		else
			if (parent->left == curr) parent->left = NULL;
			else parent->right = NULL;
		delete curr;
		return;
	}


	    //���� � 2 ������
		// �������� ���� ���������� ��������� � ������ ���������
	if (curr->left != NULL && curr->right != NULL)
	{
		tree_node* chkr;
		chkr = curr->right;
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			curr = chkr;
			delete chkr;
			curr->right = NULL;
		}
		else 
		{
			if ((curr->right)->left != NULL)
			{
				tree_node* lcurr;
				tree_node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree_node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;
				curr->right = tmp->right;
				delete tmp;
			}

		}
		return;
	}

}
template<class T>
//����� ������
void BinarySearchTree<T>::print_inorder()
{
	inorder(root);
}
template<class T>
//����� ������
void BinarySearchTree<T>::inorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);
	}
	else return;
}

template <class T>
bool BinarySearchTree<T>::search(T d)
{
	//����� ���������
	bool found = false;
	if (isEmpty())
	{
		cout << "������ �����! " << endl;
		return false;
	}
	tree_node* curr;
	tree_node* parent;
	curr = root;
	parent = (tree_node*)NULL;
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << "������ ����� �� �������! " << endl;
	}
	else
	{
		cout << "������ ����� �������! " << endl;
	}

	return found;
}

//template <class T>
//void BinarySearchTree<T>::vivod(tree_node* p, T d)
//{
//	if (p == NULL) return;
//	else //�����
//	{
//		vivod(p->left, ++d);
//		for (int i = 0; i < d; ++i) cout << "-";
//		cout << p->right << endl;
//		d--;
//	}
//	vivod(p->right, ++d);
//}