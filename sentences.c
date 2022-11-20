#include "sentences.h"
#include "node.h"
#include <stdlib.h>

void create_sentence(){}

char* get_random_word(t_tree* tree){

    p_node current_node = tree->root;
    p_cell current_cell;
    int tree_depth = get_depth(current_node);

    do{
        // Selects a random depth depending on the maximum depth of the tree
        int rand_depth = rand()%tree_depth;


        // Goes through the nodes
        for (int depth = 0 ; depth < rand_depth; depth++){
            // Selects a random cell in the node
            int rand_cell = rand()%get_length(current_node->children);
            current_cell = current_node->children.first;

            // Goes through the cells
            for (int curr_cell = 0; curr_cell < rand_cell; ++curr_cell) {
                current_cell = current_cell->next;
            }
        }
    }while (current_cell->next->next_node->word == NULL);

    for (int letter=0;current_cell->next_node->word[letter]!='\0';letter++)
        printf("word is %c\n",current_cell->next_node->word[letter]);
    return current_cell->next_node->word;
}