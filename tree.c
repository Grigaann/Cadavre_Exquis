//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"
#include <string.h>

p_node create_node(char character) {
    p_node ptr_node = malloc(sizeof(t_node));
    ptr_node->character = character;
    ptr_node->word = NULL;
    ptr_node->children = create_list();

    return ptr_node;
}

t_tree* create_tree() {
    t_tree* tree = malloc(sizeof(p_node));
    p_node first_node = create_node('-');
    tree->root = first_node;
    tree->root->children = create_list();
    return tree;
}

char* get_word(char* token) {
    char* word = malloc(sizeof(char) * strlen(token));
    int i = 0;
    while (token[i] != '\0') {
        if (token[i] == '\t') {
            word[i] = '\0';
            break;
        }
        word[i] = token[i];
        i++;
    }
    return word;
}

void print_tree(p_node node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("%c", node->character);
    if(node->children.first != NULL){
        p_cell current_cell = node->children.first;

        while(current_cell->next != NULL) {
            printf("je suis la");
            print_tree(current_cell->next_node, depth + 1);
            current_cell = current_cell->next;
        }
    }
}

void add_word_to_tree(char* word, t_node* node, int iteration) {
    p_cell current_cell= node->children.first;
    if(iteration == strlen(word)-1) {
        node->word = word;
        printf("%s", word);
        return;
    } else {
        while(current_cell != NULL){
            if(current_cell->character == word[iteration]){
                return add_word_to_tree(word, current_cell->next_node, iteration + 1);
            }
            current_cell = current_cell->next;
        }

        p_cell added_cell = add_cell(node->children, word[iteration]);

        added_cell->next_node = create_node(word[iteration]);
    }

}

t_tree** initialize_trees(){
    FILE* file = fopen("../assets/dictionary_chill.txt", "r");

    if (file == NULL) {
        printf("\n!!!Error opening file!!!\n");
        exit(1);
    }

    t_tree* ptr_name_tree = create_tree();
    t_tree* ptr_adj_tree = create_tree();
    t_tree* ptr_verbs_tree = create_tree();
    t_tree* ptr_adverbs_tree = create_tree();
    t_tree* array_trees[4] = {ptr_name_tree, ptr_adj_tree, ptr_verbs_tree, ptr_adverbs_tree};

    while (1){
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL) {
            char* token = strtok(line, "\t");
            int i = 0;
            while (token != NULL) {

                i++;
                if (i == 2){

                    if (strstr(token, "Nom:Mas+SG") != NULL){ //TODO : changer node.word so that we can
                        printf("je suis la");
                        add_word_to_tree(get_word(token), ptr_name_tree->root, 0);
                    } else if (strstr(token, "Adj:Mas+SG") != NULL) {
                        printf("je suis la");
                        add_word_to_tree(get_word(token), ptr_adj_tree->root, 0);
                    } else if (strstr(token, "Ver:Inf") != NULL) {
                        printf("je suis la");
                        add_word_to_tree(get_word(token), ptr_verbs_tree->root, 0);
                    } else if (strstr(token, "Adv") != NULL) {
                        printf("je suis la");
                        add_word_to_tree(get_word(token), ptr_adverbs_tree->root, 0);
                    }
                }
                token = strtok(NULL, "\t");
            }
        } else {
            break;
        }
    }
    print_tree(ptr_adj_tree->root, 0);
    fclose(file);

    return array_trees;
}



