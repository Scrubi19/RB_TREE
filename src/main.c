#include <stdio.h>
#include "rb_tree.h"
#include <time.h>

int main(int argc, char **argv)
{

	// struct rbtree *tree_1 = NULL;

	// char tmp[50000][10];

	// double start = clock();
 //    srand(time(NULL));

	// for( int i = 0; i < 50000; i++) {
	// 	sprintf(tmp[i], "%d", i);
	// 	tree_1 = rbtree_add(tree_1, i, tmp[i]);
	// }

	// double end = clock();

	// printf("used %f second in Adding 50k elements\n", difftime(end, start)/1000000);

	// printf("min_value = %s\n", rbtree_min(tree_1));

	// printf("max_value = %s\n", rbtree_max(tree_1));

	///////////////////////////////////////////////////////////////////////
	printf("~~~~~~~~~~~~~~\n");
	struct rbtree *tree_2 = NULL;

	tree_2 = rbtree_add(tree_2, 11, "11");
	tree_2 = rbtree_add(tree_2, 2, "2");
	tree_2 = rbtree_add(tree_2, 7, "7");
	tree_2 = rbtree_add(tree_2, 5, "5");
	tree_2 = rbtree_add(tree_2, 8, "8");
	tree_2 = rbtree_add(tree_2, 1, "1");
	tree_2 = rbtree_add(tree_2, 14, "14");
	tree_2 = rbtree_add(tree_2, 15, "15");

	rbtree_print(tree_2);

	struct rbtree *x_node = NULL;

	x_node = lookup(tree_2, 7);

	rbtree_delete(tree_2, x_node);

	//rbtree_print(tree_2);

	//printf("Search = %s\n",(lookup(tree_2, 15))->value);

	//rbtree_free(tree_1);

	//rbtree_free(tree_2);

	//rbtree_print(tree_2);

	return 0;

}