#ifndef RB_TREE
#define RB_TREE

enum Color {COLOR_RED, COLOR_BLACK, NONE};

#include<stdio.h>
#include <stdlib.h>

struct rbtree {
	int key;
	char *value;	
	int color;

	struct rbtree *parent;
	struct rbtree *left;
	struct rbtree *right;
};

struct rbtree *rbtree_fixup_add(struct rbtree *root, struct rbtree *node);

struct rbtree *rbtree_add(struct rbtree *root, int key, char *value);

struct rbtree *rbtree_left_rotate(struct rbtree *root, struct rbtree *node);

struct rbtree *rbtree_right_rotate(struct rbtree *root, struct rbtree *node);

char *rbtree_min(struct rbtree *tree);

char *rbtree_max(struct rbtree *tree);

void print_struct(struct rbtree *node);

int rbtree_print(struct rbtree *root);

struct rbtree *lookup(struct rbtree *node, int key);

void rbtree_free(struct rbtree *root);

void transplant(struct rbtree *root, struct rbtree *node1, struct rbtree *node2);

struct rbtree *rbtree_delete(struct rbtree *root, struct rbtree *del);

struct rbtree *tree_minimum(struct rbtree *tree);

struct rbtree *rbtree_delete_fixup(struct rbtree *root, struct rbtree *del);

#endif