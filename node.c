#include "node.h"


//NODE PART

// Function that initializes and returns a pointer to a node
p_node create_node(char character) {
    p_node ptr_node = malloc(sizeof(t_node));
    ptr_node->character = character;
    ptr_node->word = NULL;
    ptr_node->children = create_list();

    return ptr_node;
}


// LIST PART

// Function that initializes a std_list
t_std_list create_list() {
    t_std_list list;
    list.first = NULL;
    return list;
}


// Function that adds a cell at the end of a given std_list
p_cell add_cell(t_std_list list, char character) {

    // Initialize the cell
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->next = NULL;
    new_cell->next_node = create_node(character);


    // Add the brand-new cell at the end of the given std_list
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

// Function that finds the number of cells in a given list
int get_length(t_std_list list){
    int cpt = 0;
    p_cell cell = list.first;
    while (cell){
        cell = cell->next;
        cpt++;
    }
    return cpt;
}
