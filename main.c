#include <stdio.h>

#include "tree.h"
#include "node.h"

int main() {
    t_tree** trees = initialize_trees();
    print_tree(trees[2]->root, 0);
    return 0;
}