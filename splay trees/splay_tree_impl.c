#include <stdio.h>
#include <stdlib.h>
#include "splay_tree_impl.h"

/*
 * Initialise the dictionary
 */
void *make_new_dictionary(void)
{
        struct dictionary* dict = (struct dictionary*)malloc(sizeof(struct dictionary));
        dict->root = NULL;
        return dict;
}

/*
 * zig is analogous to a typical right rotation
 * @dictionary: dictionary which contains the root of the splay tree
 * @node:       node whose position must be replaced by its left child
 */
void zig(struct dictionary *dictionary, struct splay_tree_node *node)
{
        struct splay_tree_node *child = node->left;
        node->left = child->right;

        if(child->right)
                child->right->parent = node;

        child->right=node;
        child->parent = node->parent;

        if(!node->parent)
                dictionary->root = child;

        else if(node == node->parent->left)
                node->parent->left=child;

        else
                node->parent->right=child;

        node->parent=child;
        return;
}

/*
 * zag is analogous to a typical right rotation.
 * @dictionary: dictionary which contains the root of the splay tree
 * @node:       node whose position must be replaced by its right child
 */
void zag(struct dictionary *dictionary, struct splay_tree_node * node)
{
        struct splay_tree_node *child = node->right;
        node->right = child->left;

        if(child->left)
                child->left->parent = node;

        child->left=node;
        child->parent=node->parent;

        if(!node->parent)
                dictionary->root = child;

        else if(node == node->parent->left)
                node->parent->left=child;

        else
                node->parent->right=child;

        node->parent=child;
        return;
}

/*
 * Perform the splay operation, where a node is relocated to the 
 * root of the splay tree, without breaking the BST-like characteristics.
 * @dictionary: dictionary which contains the root of the splay tree
 * @node:       node ("entry in dictionary") which is supposed to be
 *              relocated to the root of the tree
 */ 
void splay(struct dictionary *dictionary, struct splay_tree_node *node)
{
        while(node->parent){

                if(node->parent == dictionary->root) {
                        /* zig only*/
                        if(node == node->parent->left)
                                zig(dictionary, node->parent);
                        /* zag only*/
                        else
                                zag(dictionary, node->parent);
                }

                else {
                        struct splay_tree_node *parent = node->parent; 
                        struct splay_tree_node *grandparent = parent->parent;

                        /* zig-zig rotation */
                        if(node == parent->left && parent == grandparent->left){
                                zig(dictionary, grandparent);
                                zig(dictionary, parent);
                        }

                        /* zag-zag rotation */
                        else if(node == parent->right && parent == grandparent->right){
                                zag(dictionary, grandparent);
                                zag(dictionary, parent);
                        }

                        /* zig-zag rotation */
                        else if(node == parent->left && parent == grandparent->right){
                                zig(dictionary, parent);
                                zag(dictionary, grandparent);
                        }

                        /* zag-zig rotation */
                        else {
                                zag(dictionary, parent);
                                zig(dictionary, grandparent);
                        }
                }
        }

        return;
}

void preorder(struct splay_tree_node *node)
{
        if(node == NULL)
                return;
        printf("%d\t", node->key);
        preorder(node->left);
        preorder(node->right);
}
void inorder(struct splay_tree_node *node)
{
        if(node == NULL)
                return;
        inorder(node->left);
        printf("%d\t", node->key);
        inorder(node->right);
}
void postorder(struct splay_tree_node *node)
{
        if(node == NULL)
                return;
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->key);
}

/*
 * Initialize a new node ("entry in the dictionary") and return it.
 * @key: key to be associated with node
 * @value: associated with key
 */ 
struct splay_tree_node* create_new_node(int key, int value)
{
        struct splay_tree_node *node = (struct splay_tree_node *)malloc(sizeof(struct splay_tree_node));
        node->key=key;
        node->value=value;
        node->left=NULL;
        node->right=NULL;
        node->parent=NULL;
        return node;
}

/*
 * Insert a new key-value pair into a dictionary. 
 * Update the value in case of duplicate keys.
 * @dictionary: dictionary that consists the key-value pairs
 * @key:        key to be inserted
 * @value:      value associated with key
 */
void insert(void *dictionary, int key, int value)
{
        struct dictionary* dict = (struct dictionary *)dictionary;
        /* new node */        
        struct splay_tree_node* node = create_new_node(key, value);

        /* The tree is empty */
        if(dict->root == NULL) {
                dict->root = node;
                return;
        }

        struct splay_tree_node* temp = dict->root;
        struct splay_tree_node* parent = NULL;

        while(temp) {
                parent = temp;
                
                if(key == temp->key){
                        temp->value = value;
                        free(node);
                        node = temp;
                        goto exit;
                }

                else if(key < temp->key)
                        temp = temp->left;
                
                else
                        temp = temp->right;
        }

        node->parent = parent;
        if(key < parent->key)
                parent->left = node;
        else
                parent->right = node;

exit:
        splay(dict, node);
        return;
}

/*
 * Get the value associated with a key
 * Returns the value of the key if found else returns -1 
 * @dictionary: dictionary that consists the key-value pairs
 * @key:        key to be found
 */
int find(void *dictionary, int key)
{
        struct dictionary* dict = (struct dictionary *)dictionary;
        if(key == dict->root->key)
                return dict->root->value;
        
        struct splay_tree_node* temp = dict->root;

        while(temp){

                /* key found. */
                if(temp->key == key){
                        splay(dict, temp);
                        return temp->value;
                }

                else if(temp->key > key)
                        temp = temp->left;

                else
                        temp = temp->right;
        }
        /* key not found in the splay tree. */
        return -1;
}