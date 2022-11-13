//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"
#include <string.h>



//function that initialize a node and returns a pointer this one
p_node create_node(char character) {
    p_node ptr_node = malloc(sizeof(t_node));
    ptr_node->character = character;
    ptr_node->word = NULL;
    ptr_node->children = create_list();

    return ptr_node;
}


//function that initialize a tree
t_tree* create_tree() {
    t_tree* tree = malloc(sizeof(p_node));
    p_node first_node = create_node('-');
    tree->root = first_node;
    tree->root->children = create_list();
    tree->root->children.first = NULL;
    return tree;
}


//function to get the base form of a string coming from the dictionary
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


//function that print the tree (useful for testing and debugging)
void print_tree(p_node node, int depth) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("\t");
    }

    printf("%c\n", node->character);
    if(node->children.first != NULL){
        p_cell current_cell = node->children.first;
        do {

            print_tree(current_cell->next_node, depth + 1);
            current_cell = current_cell->next;
        } while(current_cell != NULL);


    }
}


//function that adds a word to a given tree
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


//function to create and fill all the 4 trees (names, adjectives, verbs and adverbs)
tree_list initialize_trees()
{
    FILE *file = fopen("../assets/dictionary_testing.txt", "r");

    if (file == NULL) {
        printf("\n!!!Error opening file!!!\n");
        exit(1);
    }

    tree_list treeList;


    //creates the empty 4 trees
    treeList.name_tree = create_tree();
    treeList.adj_tree = create_tree();
    treeList.verb_tree = create_tree();
    treeList.adv_tree = create_tree();

    while (1)
    {
        char line[256];
        if (fgets(line, sizeof(line), file) != NULL)
        {
            char *token = strtok(line, "\t");
            char *motflechi = token;
            token = strtok(NULL, "\t");
            char *motbase = token;
            token = strtok(NULL, "\t");
            char *genre = token;

            while (token != NULL)
            {
                if (strcmp(motflechi, motbase) == 0) {
                    if (strstr(genre, "Nom:") != NULL) {
                        printf("nom, %s, %s, %s \n", motflechi,motbase,genre);
                        add_word_to_tree(motbase, treeList.name_tree->root, 0);
                    } else if (strstr(genre, "Adj:") != NULL) {
                        printf("adj, %s, %s, %s \n", motflechi,motbase,genre);
                        add_word_to_tree(motbase, treeList.adj_tree->root, 0);
                    } else if (strstr(genre, "Ver:") != NULL) {
                        printf("ver, %s, %s, %s \n", motflechi,motbase,genre);
                        add_word_to_tree(motbase, treeList.verb_tree->root, 0);
                    } else if (strstr(genre, "Adv") != NULL) {
                        printf("adv, %s, %s, %s \n", motflechi,motbase,genre);
                        add_word_to_tree(motbase, treeList.adv_tree->root, 0);
                    }
                }
                token = NULL;
            }
        }
        else
        {
            break;
        }


    }
    fclose(file);

    return treeList;
}

