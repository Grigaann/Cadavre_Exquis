//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"

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

void create_tree(t_tree* tree) {
    p_node first_node = create_node('-');
    tree->root = first_node;
}

void print_tree(p_node tree) {
    if (tree == NULL) {
        return;
    }
    printf("%c", tree->character);
    if (tree->A != NULL) {
        print_tree(tree->A);
    }
    if (tree->B != NULL) {
        print_tree(tree->B);
    }
    if (tree->C != NULL) {
        print_tree(tree->C);
    }
    if (tree->D != NULL) {
        print_tree(tree->D);
    }
    if (tree->E != NULL) {
        print_tree(tree->E);
    }
    if (tree->F != NULL) {
        print_tree(tree->F);
    }
    if (tree->G != NULL) {
        print_tree(tree->G);
    }
    if (tree->H != NULL) {
        print_tree(tree->H);
    }
    if (tree->I != NULL) {
        print_tree(tree->I);
    }
    if (tree->J != NULL) {
        print_tree(tree->J);
    }
    if (tree->K != NULL) {
        print_tree(tree->K);
    }
    if (tree->L != NULL) {
        print_tree(tree->L);
    }
    if (tree->M != NULL) {
        print_tree(tree->M);
    }
    if (tree->N != NULL) {
        print_tree(tree->N);
    }
    if (tree->O != NULL) {
        print_tree(tree->O);
    }
    if (tree->P != NULL) {
        print_tree(tree->P);
    }
    if (tree->Q != NULL) {
        print_tree(tree->Q);
    }
    if (tree->R != NULL) {
        print_tree(tree->R);
    }
    if (tree->S != NULL) {
        print_tree(tree->S);
    }
    if (tree->T != NULL) {
        print_tree(tree->T);
    }
    if (tree->U != NULL) {
        print_tree(tree->U);
    }
    if (tree->V != NULL) {
        print_tree(tree->V);
    }
    if (tree->W != NULL) {
        print_tree(tree->W);
    }
    if (tree->X != NULL) {
        print_tree(tree->X);
    }
    if (tree->Y != NULL) {
        print_tree(tree->Y);
    }
    if (tree->Z != NULL) {
        print_tree(tree->Z);
    }
}