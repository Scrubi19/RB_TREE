#include "rb_tree.h"

struct rbtree EmptyNode = {0, 0, COLOR_BLACK, NULL, NULL, NULL};
	
struct rbtree *NullNode = &EmptyNode;

struct rbtree *rbtree_add(struct rbtree *root, int key, char *value)
{
	struct rbtree *node, *parent = NullNode;
	/* Поиск листа для след.элемента */
	for (node = root; node != NullNode && node != NULL; ) {
		parent = node;
		if (key < node->key) {
			node = node->left;
		}
		else if (key > node->key) {
			node = node->right;
		}
		else
			return root;
	}
	node = malloc(sizeof(*node));
	if (node == NULL)
		return NULL;

	node->key = key;
	node->value = value;
	node->color = COLOR_RED;
	node->parent = parent;
	node->left = NullNode;
	node->right = NullNode;

	if (parent != NullNode) {
		if (key < parent->key)
			parent->left = node;
		else
			parent->right = node;
	} else {
		root = node;
	}
	return rbtree_fixup_add(root, node);
}

struct rbtree *rbtree_fixup_add(struct rbtree *root, struct rbtree *node)
{
	struct rbtree *uncle;
	//текущий лист красный
	while (node != root && node->parent->color == COLOR_RED) {
		if (node->parent == node->parent->parent->left) {
			//Узел находится слева от Grandfather
			uncle = node->parent->parent->right;
			if (uncle->color == COLOR_RED) {
				//1 случай - Дядя красный
				node->parent->color = COLOR_BLACK;
				uncle->color = COLOR_BLACK;
				node->parent->parent->color = COLOR_RED;
				node = node->parent->parent;
			} else {
				//Случай 2 & 3 - Дядя черный
				if (node == node->parent->right) {
					//Случай 2 --> Случай 3
					node = node->parent;
					root = rbtree_left_rotate(root, node);
				}
				//Случай 3
				node->parent->color = COLOR_BLACK;
				node->parent->parent->color = COLOR_RED;
				root = rbtree_right_rotate(root,
				                           node->parent->parent);
			}
		} else {
			//Узел находится справа от Grandfather
			//Cлучаи 4,5 и 6 
			uncle = node->parent->parent->left;
			if (uncle->color == COLOR_RED) {
				//Uncle is RED – case 4
				node->parent->color = COLOR_BLACK;
				uncle->color = COLOR_BLACK;
				node->parent->parent->color = COLOR_RED;
				node = node->parent->parent;
			} else {
				//Дядя черный
				if (node == node->parent->left) {
					node = node->parent;
					root = rbtree_right_rotate(root, node);
				}
				node->parent->color = COLOR_BLACK;
				node->parent->parent->color = COLOR_RED;
				root = rbtree_left_rotate(root, node->parent->parent);
			}
		}
	}
	root->color = COLOR_BLACK;
	return root;
}

struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node)
{
	struct rbtree *right = node->right;
	/* Делаем "node->right" ссылку */
	node->right = right->left;
	if (right->left != NullNode)
		right->left->parent = node;
	/* Делаем "right->parent" ссылку */
	if (right != NullNode)
		right->parent = node->parent;
	if (node->parent != NullNode) {
		if (node == node->parent->left)
			node->parent->left = right;
		else
			node->parent->right = right;
	} else {
		root = right;
	}
	right->left = node;
	if (node != NullNode)
		node->parent = right;
	return root;
}

struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node)
{
	struct rbtree *left = node->left;
	/* Делаем "node->right" ссылку */
	node->left = left->right;
	if (left->right != NullNode)
		left->right->parent = node;
	/* Делаем "right->parent" ссылку */
	if (left != NullNode)
		left->parent = node->parent;
	if (node->parent != NullNode) {
		if (node == node->parent->right)
			node->parent->right = left;
		else
			node->parent->left = left;
	} else {
		root = left;
	}
	left->right = node;
	if (node != NullNode)
		node->parent = left;
	return root;
}

// struct rbtree *lookup(struct rbtree *node, int key)
// {
//     if (node->key != key) {
//         if (key > node->key) {
//             lookup(node->right, key);
//         }else{
//             lookup(node->left, key);
//         }
//     }
//     if(node->key == key) {
//         return node;
//     }
//     if(node == NullNode && node->key != key) {
//     	return NULL;
//     }
//     return node;
// }

// struct rbtree *lookup(struct rbtree *node, int key)
// {
//     if(node->key == key) {
//     	return node;
//     }
//     if(node->key != key) {
//     	if (key > node->key) {
//              lookup(node->right, key);
//          }else{
//              lookup(node->left, key);
//          }
//     }
//     //return NULL;
// }
struct rbtree *lookup(struct rbtree *node, int key)
{
    while(1){
        if(key < node->key){
            if(node->left != NULL){
                node = node->left;
            } else {
                return NULL;
            }
        } else if (key > node->key){
            if(node->right != NULL){
                node = node->right;
            } else {
                return NULL;
            }
        } else {
            return node;
        }
    }
}


void rbtree_free(struct rbtree *root)
{
    if (root->value != NULL) {
    	root->key = 0;
    	root->value = NULL;
    	root->color = 2;//None
        rbtree_free(root->left);
        rbtree_free(root->right);
        //root->left = NULL;
        //root->right = NULL;
        //root = NULL;
        free(root);
        //root = NULL;
    }
    //free(NullNode);
}

char *rbtree_min(struct rbtree *tree) 
{
    while (tree->left != NULL && tree->left != NullNode) {
        tree = tree->left;
    }
        return tree->value;
}

struct rbtree *tree_minimum(struct rbtree *tree) 
{
    while (tree->left != NULL && tree->left != NullNode) {
        tree = tree->left;
    }
        return tree;
}

char *rbtree_max(struct rbtree *tree) 
{
    while (tree->right != NULL && tree->right != NullNode) {
        tree = tree->right;
    }
        return tree->value;
}

void print_struct(struct rbtree *one_node)
{
	#define RED "\x1b[41m"
	#define BLACK "\x1b[40m"
	#define DEFAULT "\x1b[49m"

    if (one_node->color)
        printf(BLACK "key: %d\nvalue: %s" DEFAULT "\n", 
            one_node->key, 
            one_node->value
        );
    else
        printf(RED "key: %d\nvalue: %s" DEFAULT "\n", 
            one_node->key, 
            one_node->value
        );

    #undef RED
	#undef BLACK
	#undef DEFAULT
}

int rbtree_print(struct rbtree *root)
{
	if(root == NULL) {
    	printf("Tree Clear\n");
    	return -1;
    }
    if (root != NullNode)
    {
        print_struct(root);
        rbtree_print(root->left);
        rbtree_print(root->right);
    }
    if(root == NullNode) {
    	printf("\n----------\n");
    }
    return 0;
}

void transplant(struct rbtree *root,struct rbtree *node1, struct rbtree *node2)
{
	if(node1->parent == NullNode) {
		root = node2;
	}else if(node1 == node1->parent->left) {
		node1->parent->left = node2;
	} else {
		node1->parent->right = node2;
		node2->parent = node1->parent;
	}
}

struct rbtree *rbtree_delete(struct rbtree *root, struct rbtree *del)
{
	struct rbtree *y_node,*x_node = NULL;
	y_node = del;
	int original_color = y_node->color;
	if(del->left == NullNode) {
		x_node = del->right;
		transplant(root, del, del->right);
	} else if(del->right == NullNode) {
		x_node = del->left;
		transplant(root, del, del->left);
	} else {
		y_node = tree_minimum(del->right);
		original_color = y_node->color;
		x_node = y_node->right;
		if(y_node->parent == del) {
			x_node->parent = y_node;
		} else {
			transplant(root, y_node, y_node->right);
			y_node->right = del->right;
			y_node->right->parent = y_node;
		}
		transplant(root, del, y_node);
		y_node->left = del->left;
		y_node->left->parent = y_node;
		y_node->color = del->color;
	}
	if(original_color == COLOR_BLACK) {
	 	rbtree_delete_fixup(root, x_node);
	}
	return root;

}

struct rbtree *rbtree_delete_fixup(struct rbtree *root, struct rbtree *x_node)
{
	struct rbtree *w_node = NULL;
	while(x_node != root && x_node->color == COLOR_BLACK) {
		if(x_node == x_node->parent->left) {
			w_node = x_node->parent->right;
			if(w_node->color == COLOR_RED) {
				w_node->color = COLOR_BLACK;
				x_node->parent->color = COLOR_RED;
				rbtree_left_rotate(root, x_node->parent);
				w_node = x_node->parent->right;
			}
			if(w_node->left->color == COLOR_BLACK && w_node->right->color == COLOR_BLACK) {
				w_node->color = COLOR_RED;
				x_node = x_node->parent;
			}
			else if(w_node->right->color == COLOR_BLACK) {
				w_node->left->color = COLOR_BLACK;
				w_node->color = COLOR_RED;
				rbtree_right_rotate(root, x_node->parent);
				w_node = x_node->parent->right;
			}
			w_node->color = x_node->parent->color;
			x_node->parent->color = COLOR_BLACK;
			w_node->right->color = COLOR_BLACK;
			rbtree_left_rotate(root, x_node->parent);
			x_node = root;

		}
		else {
			if(x_node == x_node->parent->right) {
			w_node = x_node->parent->left;
			if(w_node->color == COLOR_RED) {
				w_node->color = COLOR_BLACK;
				x_node->parent->color = COLOR_RED;
				rbtree_right_rotate(root, x_node->parent);
				w_node = x_node->parent->left;
			}
			if(w_node->right->color == COLOR_BLACK && w_node->left->color == COLOR_BLACK) {
				w_node->color = COLOR_RED;
				x_node = x_node->parent;
			}
			else if(w_node->left->color == COLOR_BLACK) {
				w_node->right->color = COLOR_BLACK;
				w_node->color = COLOR_RED;
				rbtree_left_rotate(root, x_node->parent);
				w_node = x_node->parent->left;
			}
			w_node->color = x_node->parent->color;
			x_node->parent->color = COLOR_BLACK;
			w_node->left->color = COLOR_BLACK;
			rbtree_right_rotate(root, x_node->parent);
			x_node = root;
			}
		}
	}
	x_node->color = COLOR_BLACK;
	return root;
}