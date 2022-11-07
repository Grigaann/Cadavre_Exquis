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

p_node create_node(char character);
void print_tree(p_node tree, int depth);
t_tree* create_tree();

#endif //CADAVRE_EXQUIS_TREE_H