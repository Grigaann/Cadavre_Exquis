#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"

int main() {
    t_tree* tree = malloc(sizeof(t_node)*5);
    create_tree(tree);
    tree->root->A = create_node('A');
    print_tree(tree->root);
}