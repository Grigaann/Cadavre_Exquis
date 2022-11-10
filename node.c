//
// Created by Fenrisúlfr on 30/10/2022.
//
#include "node.h"


//NODE PART

int exists(t_node* node){
    return node != NULL;
}



// LIST PART

t_std_list create_list() {
    t_std_list list;
    list.first = NULL;
    return list;
}

p_cell add_cell(t_std_list list, char character) {
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->character = character;
    new_cell->next = NULL;

    if (list.first != NULL) {
        p_cell current_cell = list.first;
        while (current_cell->next != NULL) {
            current_cell = current_cell->next;
        }
        current_cell->next = new_cell;
    } else {
        list.first = new_cell;
    }

    return new_cell;
}