#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"

int main() {
    t_tree* ptr_tree = create_tree();
    ptr_tree->root->A = create_node('A');
    ptr_tree->root->A->C = create_node('C');
    ptr_tree->root->A->D = create_node('D');
    print_tree(ptr_tree->root, 0);
}