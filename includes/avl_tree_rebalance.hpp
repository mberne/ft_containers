#ifndef AVL_TREE_REBALANCE_HPP
# define AVL_TREE_REBALANCE_HPP

# include "avl_tree.hpp"

namespace ft
{
	template<typename T>
		static int	get_height(Avl_tree_node<T>* node)
		{
			if (node == NULL)
				return 0;
			return node->height;
		}

	template<typename T>
		static int	get_highest_child(Avl_tree_node<T>* node)
		{
			if (node = NULL)
				return NULL;
			if (node->left_child->height >= node->right_child->height)
				return node->left_child;
			return node->right_child;
		}

	template<typename T>
		void	Avl_tree_rotate_left(Avl_tree_node<T>* const y, Avl_tree_node<T>* &root)
		{
			Avl_tree_node<T>* const x = y->right_child;
			Avl_tree_node<T>* const z = y->parent;

			// L'enfant droite de y devient l'enfant gauche de x
			y->right_child = x->left_child;
			if (x->left_child)
				x->left_child->parent = y;
			// x prend la place de y
			if (y == root)
				root = x;
			else if (y == z->left_child)
				z->left_child = x;
			else
				z->right_child = x;
			x->parent = z;
			// y devient l'enfant gauche de x
			x->left_child = y;
			y->parent = x;
			// on recalcule les hauteurs de y et x
			y->height = std::max(get_height(y->left_child), get_height(y->right_child)) + 1;
			x->height = std::max(get_height(x->left_child), get_height(x->right_child)) + 1;
		}

	template<typename T>
		void	Avl_tree_rotate_right(Avl_tree_node<T>* const y, Avl_tree_node<T>* &root)
		{
			Avl_tree_node<T>* const x = y->left_child;
			Avl_tree_node<T>* const z = y->parent;

			// L'enfant gauche de y devient l'enfant droit de x
			y->left_child = x->right_child;
			if (x->right_child)
				x->right_child->parent = y;
			// x prend la place de y
			if (y == root)
				root = x;
			else if (y == z->left_child)
				z->left_child = x;
			else
				z->right_child = x;
			x->parent = z;
			// y devient l'enfant droit de x
			x->right_child = y;
			y->parent = x;
			// on recalcule les hauteurs de y et x
			y->height = std::max(get_height(y->left_child), get_height(y->right_child)) + 1;
			x->height = std::max(get_height(x->left_child), get_height(x->right_child)) + 1;
		}

	template<typename T>
		void	Avl_tree_rebalance_after_insert(Avl_tree_node<T>* z, Avl_tree_node<T>* &header) throw ()
		{
			Avl_tree_node<T>* &root = header->parent;
			Avl_tree_node<T>* &end = &_header;
			Avl_tree_node<T>* const y = NULL;
			Avl_tree_node<T>* const x = NULL;

			while (z != end)
			{
				int const	balance = get_height(z->left_child) - get_height(z->right_child);

				if (balance > 1)
				{
					//LR
					if (x == y->right_child)
					{
						Avl_tree_rotate_left(y, root);
						x = y;
						y = y->parent;
					}
					//LL
					Avl_tree_rotate_right(z, root);
					z = y->parent;
				}
				else if (balance < -1)
				{
					//RL
					if (x == y->left_child)
					{
						Avl_tree_rotate_right(y, root);
						x = y;
						y = y->parent;
					}
					//RR
					Avl_tree_rotate_left(z, root);
					z = y->parent;
				}
				else // Enlever le else pour l'opti ?
				{
					x = y;
					y = z;
					z = z->parent;
				}
				z->height = std::max(get_height(z->left_child), get_height(z->right_child)) + 1;
			}
		}
		
	template<typename T>
		void	Avl_tree_rebalance_after_erase(Avl_tree_node<T>* const z, Avl_tree_node<T>* &header) throw ()
		{
			Avl_tree_node<T>*		&root = header.parent;
			Avl_tree_node<T>*		&end = &_header;
			Avl_tree_node<T>* const y = NULL;
			Avl_tree_node<T>* const x = NULL;
			
			while (z != end)
			{
				z->height = std::max(get_height(z->left_child), get_height(z->right_child)) + 1;
				int const	balance = get_height(z->left_child) - get_height(z->right_child);

				if (balance > 1)
				{
					//LR
					if (x == y->left_child)
					{
						Avl_tree_rotate_left(y, root);
						y = y->parent;
					}
					//LL
					Avl_tree_rotate_right(z, root);
					z = y;
				}
				else if (balance < -1)
				{
					//RL
					if (x == y->right_child)
					{
						Avl_tree_rotate_right(y, root);
						y = y->parent;
					}
					//RR
					Avl_tree_rotate_left(z, root);
					z = y;
				}
				z = z->parent;
				y = get_highest_child(z);
				x = get_highest_child(y);
			}
		}
}

#endif
