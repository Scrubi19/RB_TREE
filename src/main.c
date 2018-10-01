#include <stdio.h>
#include "rb_tree.h"
#include <time.h>
#define MAX 50000

int main()
{

	struct rbtree *tree_1 = NULL;

	char tmp[MAX][10];

	//double start_1 = clock();
    //srand(time(NULL));

	for( int i = 0; i < MAX; i++) {
		sprintf(tmp[i], "%d", i);
		tree_1 = rbtree_add(tree_1, i, tmp[i]);
	}

	//double end_1 = clock();

	//printf("used %f second in Adding 50k elements\n", difftime(end_1, start_1)/1000000);

	printf("min_value = %s\n", rbtree_min(tree_1));

	printf("max_value = %s\n", rbtree_max(tree_1));

	///////////////////////////////////////////////////////////////////////
	printf("~~~~~~~~~~~~~~\n");

    // double start_2 = clock();
    // srand(time(NULL));

	//int random = rand()%100000;
    //int random = 100000 + rand()%100000;
    //int random = 200000 + rand()%100000;
    //int random = 300000 + rand()%100000;
    //int random = 400000 + rand()%100000;
    //int random = 500000 + rand()%100000;
    //int random = 600000 + rand()%100000;
    //int random = 700000 + rand()%100000;
    //int random = 800000 + rand()%100000;
    //int random = 900000 + rand()%100000;

    // lookup(tree_1, random);
    // double end_2 = clock();

    // printf("used %f second in Adding elements\n", difftime(end_2, start_2)/1000000);
    
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

	x_node = lookup(tree_2, 14);

	rbtree_delete(tree_2, x_node);
	 
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

	rbtree_print(tree_2);

	//rbtree_free(tree_1);

	//rbtree_free(tree_2);

	//rbtree_print(tree_2);

	return 0;

}