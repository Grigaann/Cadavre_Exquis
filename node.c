//
// Created by Fenrisúlfr on 30/10/2022.
//
#include "node.h"


//NODE PART

int exists(t_node* node){
    return node != NULL;
}



// LIST PART

//function to initialize a std_list with a first = NULL
t_std_list create_list() {
    t_std_list list;
    list.first = NULL;
    return list;
}


//function to add a cell at the end of a given std_list
p_cell add_cell(t_std_list list, char character) {

    //these 3 lines initialize the cell
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->character = character;
    new_cell->next = NULL;

    //the following lines permits to add the brand-new cell at the end of the given std_list
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
