#ifndef SPLAY_TREE_IMPLH
#define SPLAY_TREE_IMPLH


/* 
 * struct dictionary: represents a dictionary that uses a splay tree
 * @root:       root of the splay tree
 */ 
struct dictionary {
        struct splay_tree_node* root;
};

/*
 * struct splay_tree_node: represents a splay tree's node
 * @key:        key in the dictionary
 * @value:      value associated with a key
 * @left:       pointer to the left child
 * @right:      pointer to the right child
 */ 
struct splay_tree_node {
        int key;
        int value;
        struct splay_tree_node* left;
        struct splay_tree_node* right;
        struct splay_tree_node* parent;
};

void zig(struct dictionary *, struct splay_tree_node *);

void zag(struct dictionary *, struct splay_tree_node *);

struct splay_tree_node* create_new_node(int, int);

void* make_new_dictionary(void);

void insert(void*, int, int);

int find(void*, int);

#endif
