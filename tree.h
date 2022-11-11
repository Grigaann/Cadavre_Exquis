//
// Created by Fenrisúlfr on 30/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#ifndef CADAVRE_EXQUIS_TREE_H
#define CADAVRE_EXQUIS_TREE_H

typedef struct s_tree {
    p_node root;
} t_tree;

typedef struct s_list_tree{
    t_tree* name_tree;
    t_tree* adj_tree;
    t_tree* verb_tree;
    t_tree* adv_tree;
} tree_list;

p_node create_node(char character);
void print_tree(p_node node, int depth);
t_tree* create_tree();
tree_list initialize_trees();
char* get_word(char* token);

#endif //CADAVRE_EXQUIS_TREE_H