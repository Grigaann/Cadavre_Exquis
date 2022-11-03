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

void print_tree(p_node tree, int it) {
    if (tree == NULL) {
        return;
    }
    for (int i = 0; i < it; i++) {
        printf("    ");
    }
    printf("%c\n", tree->character);
    if (tree->A != NULL) {
        print_tree(tree->A, it+1);
    }
    if (tree->B != NULL) {
        print_tree(tree->B, it+1);
    }
    if (tree->C != NULL) {
        print_tree(tree->C, it+1);
    }
    if (tree->D != NULL) {
        print_tree(tree->D, it+1);
    }
    if (tree->E != NULL) {
        print_tree(tree->E, it+1);
    }
    if (tree->F != NULL) {
        print_tree(tree->F, it+1);
    }
    if (tree->G != NULL) {
        print_tree(tree->G, it+1);
    }
    if (tree->H != NULL) {
        print_tree(tree->H, it+1);
    }
    if (tree->I != NULL) {
        print_tree(tree->I, it+1);
    }
    if (tree->J != NULL) {
        print_tree(tree->J, it+1);
    }
    if (tree->K != NULL) {
        print_tree(tree->K, it+1);
    }
    if (tree->L != NULL) {
        print_tree(tree->L, it+1);
    }
    if (tree->M != NULL) {
        print_tree(tree->M, it+1);
    }
    if (tree->N != NULL) {
        print_tree(tree->N, it+1);
    }
    if (tree->O != NULL) {
        print_tree(tree->O, it+1);
    }
    if (tree->P != NULL) {
        print_tree(tree->P, it+1);
    }
    if (tree->Q != NULL) {
        print_tree(tree->Q, it+1);
    }
    if (tree->R != NULL) {
        print_tree(tree->R, it+1);
    }
    if (tree->S != NULL) {
        print_tree(tree->S, it+1);
    }
    if (tree->T != NULL) {
        print_tree(tree->T, it+1);
    }
    if (tree->U != NULL) {
        print_tree(tree->U, it+1);
    }
    if (tree->V != NULL) {
        print_tree(tree->V, it+1);
    }
    if (tree->W != NULL) {
        print_tree(tree->W, it+1);
    }
    if (tree->X != NULL) {
        print_tree(tree->X, it+1);
    }
    if (tree->Y != NULL) {
        print_tree(tree->Y, it+1);
    }
    if (tree->Z != NULL) {
        print_tree(tree->Z, it+1);
    }
}