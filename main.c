
#include "tree.h"
#include "node.h"

int main() {

    //tree_list trees = initialize_trees();
    //print_tree(trees.name_tree->root, 0);

    t_tree* tree = create_tree();
    tree->root->children = create_list() ;
    tree->root->children.first = add_cell(tree->root->children, 'a');
    tree->root->children.first->next_node = create_node('A');
    tree->root->children.first->next = add_cell(tree->root->children, 'b');
    tree->root->children.first->next->next_node = create_node('B');
    tree->root->children.first->next->next_node->children.first = add_cell(tree->root->children, 'e');
    tree->root->children.first->next->next_node->children.first->next_node = create_node('E');
    print_tree(tree->root, 0);
    return 0;
}