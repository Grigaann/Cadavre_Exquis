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

void add_cell(p_cell list, char character) {
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->character = character;
    new_cell->next = NULL;

    if (list == NULL) {
        list = new_cell;
    } else {
        p_cell current_cell = list->next;
        while (current_cell->next != NULL) {
            current_cell = current_cell->next;
        }
        current_cell->next = new_cell;
    }
}