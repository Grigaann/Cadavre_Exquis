//
// Created by Fenrisúlfr on 30/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef CADAVRE_EXQUIS_NODE_H
#define CADAVRE_EXQUIS_NODE_H

struct s_node;

typedef struct cell {
    char character;
    struct s_node* next_node;
    struct cell* next;
} t_cell, *p_cell;

typedef struct s_std_list {
    p_cell first;
} t_std_list;

t_std_list create_list();
p_cell add_cell(t_std_list list, char character);

typedef struct s_node {
    char character;
    char* word;
    t_std_list children;
} t_node, *p_node;

int exists(t_node* node);

#endif //CADAVRE_EXQUIS_NODE_H