
#include "tree.h"
#include "node.h"

#include <stdio.h>
#include "random.h"

int main() {
    grand(10);
    return 0;
}
/*int main() {

    tree_list trees = initialize_trees();
    tree_list treeList;
    treeList.name_tree = create_tree();
    add_word_to_tree("bonjour",treeList.name_tree->root,0);
    printf("\n   |second word|\n\n");
    add_word_to_tree("bonsoir",treeList.name_tree->root,0);
    printf("\n");
    print_tree(trees.name_tree->root, 0);


    /*t_tree* tree = create_tree();
    tree->root->children = create_list() ;
    tree->root->children.first = add_cell(tree->root->children, 'a');


    tree->root->children.first->next = add_cell(tree->root->children, 'b');


    tree->root->children.first->next->next_node->children.first = add_cell(tree->root->children.first->next->next_node->children, 'e');


    tree->root->children.first->next->next_node->children.first->next_node->children.first =
            add_cell(tree->root->children.first->next->next_node->children.first->next_node->children, 'l');
    tree->root->children.first->next->next_node->children.first->next_node->children.first->next_node->word = "bel";


    tree->root->children.first->next->next_node->children.first->next = add_cell(tree->root->children.first->next->next_node->children, 'i');


    print_tree(tree->root, 0);
    char wordeu[100];
    printf("Verify your word is in the tree : ");
    scanf(" %s", wordeu);
    word_in_tree(wordeu,trees.name_tree);
    return 0;
}*/