//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"
#include <string.h>

p_node create_node(char character) {
    p_node node = malloc(sizeof(t_node));
    node->character = character;
    node->word = NULL;
    node->a = NULL;
    node->b = NULL;
    node->c = NULL;
    node->d = NULL;
    node->e = NULL;
    node->f = NULL;
    node->g = NULL;
    node->h = NULL;
    node->i = NULL;
    node->j = NULL;
    node->k = NULL;
    node->l = NULL;
    node->m = NULL;
    node->n = NULL;
    node->o = NULL;
    node->p = NULL;
    node->q = NULL;
    node->r = NULL;
    node->s = NULL;
    node->t = NULL;
    node->u = NULL;
    node->v = NULL;
    node->w = NULL;
    node->x = NULL;
    node->y = NULL;
    node->z = NULL;

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
        if (token[i] == '\t') {
            word[i] = '\0';
            break;
        }
        word[i] = token[i];
        i++;
    }
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
    if (tree->a != NULL) {
        print_tree(tree->a, depth + 1);
    }
    if (tree->b != NULL) {
        print_tree(tree->b, depth + 1);
    }
    if (tree->c != NULL) {
        print_tree(tree->c, depth + 1);
    }
    if (tree->d != NULL) {
        print_tree(tree->d, depth + 1);
    }
    if (tree->e != NULL) {
        print_tree(tree->e, depth + 1);
    }
    if (tree->f != NULL) {
        print_tree(tree->f, depth + 1);
    }
    if (tree->g != NULL) {
        print_tree(tree->g, depth + 1);
    }
    if (tree->h != NULL) {
        print_tree(tree->h, depth + 1);
    }
    if (tree->i != NULL) {
        print_tree(tree->i, depth + 1);
    }
    if (tree->j != NULL) {
        print_tree(tree->j, depth + 1);
    }
    if (tree->k != NULL) {
        print_tree(tree->k, depth + 1);
    }
    if (tree->l != NULL) {
        print_tree(tree->l, depth + 1);
    }
    if (tree->m != NULL) {
        print_tree(tree->m, depth + 1);
    }
    if (tree->n != NULL) {
        print_tree(tree->n, depth + 1);
    }
    if (tree->o != NULL) {
        print_tree(tree->o, depth + 1);
    }
    if (tree->p != NULL) {
        print_tree(tree->p, depth + 1);
    }
    if (tree->q != NULL) {
        print_tree(tree->q, depth + 1);
    }
    if (tree->r != NULL) {
        print_tree(tree->r, depth + 1);
    }
    if (tree->s != NULL) {
        print_tree(tree->s, depth + 1);
    }
    if (tree->t != NULL) {
        print_tree(tree->t, depth + 1);
    }
    if (tree->u != NULL) {
        print_tree(tree->u, depth + 1);
    }
    if (tree->v != NULL) {
        print_tree(tree->v, depth + 1);
    }
    if (tree->w != NULL) {
        print_tree(tree->w, depth + 1);
    }
    if (tree->x != NULL) {
        print_tree(tree->x, depth + 1);
    }
    if (tree->y != NULL) {
        print_tree(tree->y, depth + 1);
    }
    if (tree->z != NULL) {
        print_tree(tree->z, depth + 1);
    }
}

void add_word_to_tree(char* word, t_node* node, int iteration) {
    if(strstr(node->word, &word[iteration]) != NULL){
        if(word[iteration] == 'a'){
            return add_word_to_tree(word, node->a, iteration + 1);
        }
        if(word[iteration] == 'b'){
            return add_word_to_tree(word, node->b, iteration + 1);
        }
        if(word[iteration] == 'c'){
            return add_word_to_tree(word, node->c, iteration + 1);
        }
        if(word[iteration] == 'd'){
            return add_word_to_tree(word, node->d, iteration + 1);
        }
        if(word[iteration] == 'e'){
            return add_word_to_tree(word, node->e, iteration + 1);
        }
        if(word[iteration] == 'f'){
            return add_word_to_tree(word, node->f, iteration + 1);
        }
        if(word[iteration] == 'g'){
            return add_word_to_tree(word, node->g, iteration + 1);
        }
        if(word[iteration] == 'h'){
            return add_word_to_tree(word, node->h, iteration + 1);
        }
        if(word[iteration] == 'i'){
            return add_word_to_tree(word, node->i, iteration + 1);
        }
        if(word[iteration] == 'j'){
            return add_word_to_tree(word, node->j, iteration + 1);
        }
        if(word[iteration] == 'k'){
            return add_word_to_tree(word, node->k, iteration + 1);
        }
        if(word[iteration] == 'l'){
            return add_word_to_tree(word, node->l, iteration + 1);
        }
        if(word[iteration] == 'm'){
            return add_word_to_tree(word, node->m, iteration + 1);
        }
        if(word[iteration] == 'n'){
            return add_word_to_tree(word, node->n, iteration + 1);
        }
        if(word[iteration] == 'o'){
            return add_word_to_tree(word, node->o, iteration + 1);
        }
        if(word[iteration] == 'p'){
            return add_word_to_tree(word, node->p, iteration + 1);
        }

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
                    add_word_to_tree(get_word(token), ptr_name_tree->root, 0);
                } else if (strstr(token, "ADJ:Mas+SG") != NULL) {
                    add_word_to_tree(get_word(token), ptr_adj_tree->root, 0);
                } else if (strstr(token, "Ver:Inf") != NULL) {
                    add_word_to_tree(get_word(token), ptr_verbs_tree->root, 0);
                } else if (strstr(token, "Adv") != NULL) {
                    add_word_to_tree(get_word(token), ptr_adverbs_tree->root, 0);
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



