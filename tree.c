//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"
#include <string.h>

p_node create_node(char character) {
    p_node node = malloc(sizeof(t_node));
    node->character = character;
    node->A = NULL;
    node->B = NULL;
    node->C = NULL;
    node->D = NULL;
    node->E = NULL;
    node->F = NULL;
    node->G = NULL;
    node->H = NULL;
    node->I = NULL;
    node->J = NULL;
    node->K = NULL;
    node->L = NULL;
    node->M = NULL;
    node->N = NULL;
    node->O = NULL;
    node->P = NULL;
    node->Q = NULL;
    node->R = NULL;
    node->S = NULL;
    node->T = NULL;
    node->U = NULL;
    node->V = NULL;
    node->W = NULL;
    node->X = NULL;
    node->Y = NULL;
    node->Z = NULL;
    return node;
}

t_tree* create_tree() {
    t_tree* tree = malloc(sizeof(t_node));
    p_node first_node = create_node('-');
    tree->root = first_node;
    return tree;
}

char* get_word(char* token) {
    char* word = malloc(sizeof(char) * strlen(token));
    int i = 0;
    while (token[i] != '\0') {
        if (token[i] == ' ') {
            word[i] = '\0';
            break;
        }
        word[i] = token[i];
        i++;
    }
    printf("word: %s", word);
    return word;
}

void print_tree(p_node tree, int depth) {
    if (tree == NULL) {
        return;
    }

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }

    printf("%c\n", tree->character);
    if (tree->A != NULL) {
        print_tree(tree->A, depth + 1);
    }
    if (tree->B != NULL) {
        print_tree(tree->B, depth + 1);
    }
    if (tree->C != NULL) {
        print_tree(tree->C, depth + 1);
    }
    if (tree->D != NULL) {
        print_tree(tree->D, depth + 1);
    }
    if (tree->E != NULL) {
        print_tree(tree->E, depth + 1);
    }
    if (tree->F != NULL) {
        print_tree(tree->F, depth + 1);
    }
    if (tree->G != NULL) {
        print_tree(tree->G, depth + 1);
    }
    if (tree->H != NULL) {
        print_tree(tree->H, depth + 1);
    }
    if (tree->I != NULL) {
        print_tree(tree->I, depth + 1);
    }
    if (tree->J != NULL) {
        print_tree(tree->J, depth + 1);
    }
    if (tree->K != NULL) {
        print_tree(tree->K, depth + 1);
    }
    if (tree->L != NULL) {
        print_tree(tree->L, depth + 1);
    }
    if (tree->M != NULL) {
        print_tree(tree->M, depth + 1);
    }
    if (tree->N != NULL) {
        print_tree(tree->N, depth + 1);
    }
    if (tree->O != NULL) {
        print_tree(tree->O, depth + 1);
    }
    if (tree->P != NULL) {
        print_tree(tree->P, depth + 1);
    }
    if (tree->Q != NULL) {
        print_tree(tree->Q, depth + 1);
    }
    if (tree->R != NULL) {
        print_tree(tree->R, depth + 1);
    }
    if (tree->S != NULL) {
        print_tree(tree->S, depth + 1);
    }
    if (tree->T != NULL) {
        print_tree(tree->T, depth + 1);
    }
    if (tree->U != NULL) {
        print_tree(tree->U, depth + 1);
    }
    if (tree->V != NULL) {
        print_tree(tree->V, depth + 1);
    }
    if (tree->W != NULL) {
        print_tree(tree->W, depth + 1);
    }
    if (tree->X != NULL) {
        print_tree(tree->X, depth + 1);
    }
    if (tree->Y != NULL) {
        print_tree(tree->Y, depth + 1);
    }
    if (tree->Z != NULL) {
        print_tree(tree->Z, depth + 1);
    }
}

t_tree** initialize_trees(){
    FILE* file = fopen("../assets/dictionary.txt", "r");

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
        if (fgets(line, sizeof(line), file)) {
            char* token = strtok(line, " ");
            while (token != NULL) {
                if (strstr(token, "Nom:Mas+SG") != NULL) {
                    get_word(token);
                } else if (strstr(token, "ADJ:Mas+SG") != NULL) {
                    printf("ADJECTIVE\n");
                } else if (strstr(token, "Ver:Inf") != NULL) {
                    printf("VERB\n");
                } else if (strstr(token, "Adv") != NULL) {
                    printf("ADVERB\n");
                }
                token = strtok(NULL, " ");
            }
        } else {
            break;
        }
    }

    fclose(file);
    return array_trees;
}



