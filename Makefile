all:
	gcc -Wall src/main.c src/rb_tree.c -o tree

clean:
	rm tree