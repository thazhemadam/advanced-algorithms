splay_trees: splay_tree_impl.o splay_tree_client.o
	gcc splay_tree_impl.o splay_tree_client.o -lm -o splay_trees

splay_tree_impl.o: splay_tree_impl.c splay_tree_impl.h
	gcc -c splay_tree_impl.c -o splay_tree_impl.o

splay_tree_client.o: splay_tree_client.c splay_tree_impl.h
	gcc -c splay_tree_client.c -lm -o splay_tree_client.o

clean:
	rm *.o splay_trees
