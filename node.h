//
// Created by Fenrisúlfr on 30/10/2022.
//
#include <stdio.h>
#include <stdlib.h>
#ifndef CADAVRE_EXQUIS_NODE_H
#define CADAVRE_EXQUIS_NODE_H

typedef struct s_node {
    char character;
    char* word;
    struct s_node* a;
    struct s_node* b;
    struct s_node* c;
    struct s_node* d;
    struct s_node* e;
    struct s_node* f;
    struct s_node* g;
    struct s_node* h;
    struct s_node* i;
    struct s_node* j;
    struct s_node* k;
    struct s_node* l;
    struct s_node* m;
    struct s_node* n;
    struct s_node* o;
    struct s_node* p;
    struct s_node* q;
    struct s_node* r;
    struct s_node* s;
    struct s_node* t;
    struct s_node* u;
    struct s_node* v;
    struct s_node* w;
    struct s_node* x;
    struct s_node* y;
    struct s_node* z;
} t_node, *p_node;

int exists(t_node* node);

#endif //CADAVRE_EXQUIS_NODE_H