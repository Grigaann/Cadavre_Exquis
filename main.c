#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"

int main() {
    t_tree* tree = malloc(sizeof(t_node)*5);
    create_tree(tree);
    tree->root->A = create_node('A');
    tree->root->A->C = create_node('C');
    tree->root->A->D = create_node('D');
    print_tree(tree->root, 0);
}