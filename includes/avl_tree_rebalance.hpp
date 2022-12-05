#ifndef AVL_TREE_REBALANCE_HPP
# define AVL_TREE_REBALANCE_HPP

# include "avl_tree.hpp"

namespace ft
{
    template<typename T>
	    static int		get_height(Avl_tree_node<T>* node)
	    {
	    	if (node == NULL)
	    		return 0;
	    	return node->height;
	    }

    template<typename T>
        void	Avl_tree_rotate_left(Avl_tree_node<T>* const x, Avl_tree_node<T>* &root)
        {
            Avl_tree_node<T>* const y = x->right_child;
            Avl_tree_node<T>* const z = x->parent;

            // L'enfant droite de x devient l'enfant gauche de y
            x->right_child = y->left_child;
            if (y->left_child)
                y->left_child->parent = x;
            // y prend la place de x
            if (x == root)
                root = y;
            else if (x == z->left_child)
                z->left_child = y;
            else
                z->right_child = y;
            y->parent = z;
            // x deviens l'enfant gauche de y
            y->left_child = x;
            x->parent = y;
        }

    template<typename T>
        void	Avl_tree_rotate_right(Avl_tree_node<T>* const x, Avl_tree_node<T>* &root)
        {
            Avl_tree_node<T>* const y = x->left;
            Avl_tree_node<T>* const z = x->parent;

            // L'enfant gauche de x devient l'enfant droit de y
            x->left_child = y->right_child;
            if (y->right_child)
                y->right_child->parent = x;
            // y prend la place de x
            if (x == root)
                root = y;
            else if (x == z->left_child)
                z->left_child = y;
            else
                z->right_child = y;
            y->parent = z;
            // x devient l'enfant droit de y
            y->right_child = x;
            x->parent = y;
        }

    template<typename T>
        void	Avl_tree_rebalance_after_insert(Avl_tree_node<T>* node, Avl_tree_node<T>* parent, Avl_tree_node<T>* &root) throw ()
        {
            while (node != root)
            {
                Avl_tree_node<T>* const	parent = node->parent;
                Avl_tree_node<T>* const	grand_parent = parent->parent;
                int const	balance = get_height(node->left_child) - get_height(node->right_child);

                if (balance > 1)
                {
                    //LR
                    if (node == parent->right_child)
                    {
                        node = parent;
                        Avl_tree_rotate_left(node, root);
                    }
                    //LL
                    Avl_tree_rotate_right(grand_parent, root);
                }
                else if (balance < -1)
                {
                    //RL
                    if (node == parent->left_child)
                    {
                        node = parent;
                        Avl_tree_rotate_right(node, root);
                    }
                    //RR
                    Avl_tree_rotate_left(grand_parent, root);
                }
                else
                    node = parent;
                node->height = std::max(get_height(node->left_child), get_height(node->right_child)) + 1;
            }
        }
}

#endif
