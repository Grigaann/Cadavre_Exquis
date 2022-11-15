
#include "tree.h"
#include "node.h"

int main() {

    tree_list trees = initialize_trees();
    print_tree(trees.name_tree->root, 0);

    /*
    t_tree* tree = create_tree();
    tree->root->children = create_list() ;
    tree->root->children.first = add_cell(tree->root->children, 'a');


    tree->root->children.first->next = add_cell(tree->root->children, 'b');


    tree->root->children.first->next->next_node->children.first = add_cell(tree->root->children.first->next->next_node->children, 'e');


    tree->root->children.first->next->next_node->children.first->next_node->children.first =
            add_cell(tree->root->children.first->next->next_node->children.first->next_node->children, 'l');
    tree->root->children.first->next->next_node->children.first->next_node->children.first->next_node->word = "bel";


    tree->root->children.first->next->next_node->children.first->next = add_cell(tree->root->children.first->next->next_node->children, 'i');


    print_tree(tree->root, 0);
    printf("%d \n", is_exist_list(tree->root->children.first,'a'));
    is_exist_tree("bel",tree);*/
    return 0;
}