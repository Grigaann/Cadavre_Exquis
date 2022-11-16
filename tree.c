//
// Created by FenrisÃºlfr on 30/10/2022.
//
#include "tree.h"
#include <string.h>



//function that initialize a tree
t_tree* create_tree() {
    t_tree* tree = malloc(sizeof(p_node));
    p_node first_node = create_node('-');
    tree->root = first_node;
    tree->root->children = create_list();
    tree->root->children.first = NULL;
    return tree;
}


//function to get the base form of a string coming from the dictionary
char* get_word(char* token) {
    char* word = malloc(sizeof(char) * strlen(token));
    int i = 0;
    while (token[i] != '\0') {
        if (token[i] == '\t') {
            word[i] = '\0';
            break;
        }
        word[i] = token[i];
        i++;
    }
    return word;
}


//function that print the tree (useful for testing and debugging)
void print_tree(p_node node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("%c\n", node->character);
    if(node->children.first != NULL){
        p_cell current_cell = node->children.first;
        do {
            print_tree(current_cell->next_node, depth + 1);
            current_cell = current_cell->next;
        } while(current_cell != NULL);
    }
}


//function that adds a word to a given tree
void add_word_to_tree(char* word, t_node* node, int iteration) {
    p_cell current_cell= node->children.first;
    if(word[iteration] == '\0') {
        node->word = malloc((strlen(word)+1)*sizeof(char));
        int t;
        for(t=0;t< strlen(word);t++){
            node->word[t]=word[t];
        }
        node->word[t]='\0';
        return;
    }
    if(node->children.first == NULL){
        node->children.first = add_cell(node->children, word[iteration]);
        return add_word_to_tree(word, node->children.first->next_node, iteration + 1);
    }
    while (1){
        if (current_cell == NULL){
            current_cell = add_cell(node->children, word[iteration]);
        }
        if(current_cell->character == word[iteration]){
            return add_word_to_tree(word, current_cell->next_node, iteration + 1);
        }
        current_cell = current_cell->next;
    }
}


//function which returns and fill all the 4 trees (names, adjectives, verbs and adverbs)
tree_list initialize_trees(){
    FILE *file = fopen("../assets/dictionary_testing.txt", "r");
    if (file == NULL) {
        printf("\n!!!Error opening file!!!\n");
        exit(1);
    }
    tree_list treeList;
    //creates the empty 4 trees
    treeList.name_tree = create_tree();
    treeList.adj_tree = create_tree();
    treeList.verb_tree = create_tree();
    treeList.adv_tree = create_tree();
    // Read the file line by line
    while (1){
        char line[256];
        // Take each line and returns NULL when end of file
        if (fgets(line, sizeof(line), file) != NULL){
            char *token = strtok(line, "\t");
            // Stores the first word of the line
            char *motflechi = token;
            token = strtok(NULL, "\t");
            // Stores the base form of the word
            char *motbase = token;
            token = strtok(NULL, "\n");
            // Stores the type of the word
            char *genre = token;

            while (token != NULL){
                //Make sure the word we read in the file is its Base form.
                if (strcmp(motflechi, motbase) == 0) {
                    //Check if the word read in the txt is a noun
                    if (strstr(genre, "Nom:") != NULL) {
                        add_word_to_tree(motbase, treeList.name_tree->root, 0);
                    //Check if the word read in the txt is an Adjective
                    } else if (strstr(genre, "Adj:") != NULL) {
                        add_word_to_tree(motbase, treeList.adj_tree->root, 0);
                    //Check if the word read in the txt is a Verb
                    } else if (strstr(genre, "Ver:") != NULL) {
                        add_word_to_tree(motbase, treeList.verb_tree->root, 0);
                    //Check if the word read in the txt is an Adverb
                    } else if (strstr(genre, "Adv") != NULL) {
                        add_word_to_tree(motbase, treeList.adv_tree->root, 0);
                    }
                }
                token = NULL;
            }
        }else{
            //No more line, closes while loop and ends the function
            break;
        }
    }
    //Closes the file we opened earlier
    fclose(file);
    return treeList;
}

//Function which verify if a given word exists in one of the four tree.
void word_in_tree(char* word,t_tree* list){
    p_node tmp;
    tmp = list->root;
    int i = 0;
    int yes = 0;
    //Compares each letter in the word...
    while(word[i] != '\0'){
        p_cell p = tmp->children.first;
        int j = 0, k = 0, exist;
        while(k == 0){
            //...Checks if the character exists in the node
            if (p->character == word[i]){
                j++;
                k = 1;
            }else{
                j++;
                if (p->next == NULL){
                    break;
                }else{
                    p = p->next;
                }
            }
        }
        if(k == 1){
            exist = j;
        }else{
            exist = -1 ;
        }

        //The variable exist gives us the number of times we need to go to the next cell of the node to get our character
        if(exist != -1){
            //If the character has been found in the list of the node
            p_cell p2= tmp->children.first;
            for(int n = 1; n < exist; n++){
                p2 = p2->next;
            }
            tmp = p2->next_node;
        }else{
            //If the character has not been found in the t_std_list of the node, then it stops the while loop
            yes = 1;
            break;
        }
        i++;
    }
    if (!yes){
        // If the word contains in the node of the last character of the given word is equal to the given character then we found that the word exists in the tree
        printf("This word exists in the tree !");

    }else{
        printf("This word doesn't exist in the tree");
    }
}
