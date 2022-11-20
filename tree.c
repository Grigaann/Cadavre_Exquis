#include "tree.h"
#include <string.h>


// Function that initializes a tree
t_tree* create_tree() {
    t_tree* tree = malloc(sizeof(p_node));
    p_node first_node = create_node('-');
    tree->root = first_node;
    tree->root->children = create_list();
    tree->root->children.first = NULL;
    return tree;
}

// Function that gets the depth of a given tree
int get_depth(p_node node){
    // Leaf is reached
    if (!node->children.first)
        return 0;

    // Check for all children
    int max_depth = 0;
    p_cell it = node->children.first;
    while (it != NULL){
        int depth_it = get_depth(it->next_node);
        // Compare and find the maximum depth between them
        if (max_depth < depth_it) {
            max_depth = depth_it;
        }
        it = it->next;
    }
    return max_depth + 1 ;
}


// Function that print the tree (useful for testing and debugging)
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


// Function that adds a word to a given tree
void add_word_to_tree(char* word, t_node* node, int iteration) {
    p_cell current_cell= node->children.first;
    // End of the word
    if(word[iteration] == '\0') {
        node->word = malloc((strlen(word)+1)*sizeof(char));
        int t;
        // Add the word letter by letter
        for(t=0;t< strlen(word);t++){
            node->word[t]=word[t];
        }
        node->word[t]='\0';
        return;
    }

    // Create the first node of the tree with the corresponding character
    if(node->children.first == NULL){
        node->children.first = add_cell(node->children, word[iteration]);
        return add_word_to_tree(word, node->children.first->next_node, iteration + 1);
    }

    // Base case
    while (1){
        // Create a node if needed
        if (current_cell == NULL){
            current_cell = add_cell(node->children, word[iteration]);
        }
        // Go deeper in the tree and go to the next letter
        if(current_cell->next_node->character == word[iteration]){
            return add_word_to_tree(word, current_cell->next_node, iteration + 1);
        }
        // Go through the list
        current_cell = current_cell->next;
    }
}


// Function which returns and fill all the 4 trees (names, adjectives, verbs and adverbs)
tree_list initialize_trees(){
    // Open file
    FILE *file = fopen("../assets/dictionary_chill.txt", "r");
    if (file == NULL) {
        printf("\n!!!Error opening file!!!\n");
        exit(1);
    }

    tree_list treeList;
    // Create the empty 4 trees
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
                // Make sure the word we read in the file is its Base form.
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
            // No more line, closes while loop and ends the function
            break;
        }
    }
    // Closes the file we opened earlier
    fclose(file);
    return treeList;
}

// Function which verify if a given word exists in one of the four tree.
void word_in_tree(char* word,t_tree* list){
    p_node tmp;
    tmp = list->root;
    int i = 0;
    int yes = 0;

    // Compare each letter in the word
    while(word[i] != '\0'){
        p_cell p = tmp->children.first;
        int j = 0, k = 0, exist;
        while(k == 0){
            // Check if the character exists in the node
            if (p->next_node->character == word[i]){
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

        // The variable 'exist' gives us the number of times we need to go to the next cell of the node to get our character
        if(exist != -1){
            //If the character has been found in the list of the node
            p_cell p2= tmp->children.first;
            for(int n = 1; n < exist; n++){
                p2 = p2->next;
            }
            tmp = p2->next_node;
        }else{
            // If the character has not been found in the t_std_list of the node, then it stops the while loop
            yes = 1;
            break;
        }
        i++;
    }
    if (!yes && tmp->word != NULL){
        // If the word contains in the node of the last character of the given word is equal to the given character then we found that the word exists in the tree
        if(strstr(tmp->word, word) != NULL) {
            printf("The word '%s' exists in the tree.\n", word);

        }
    }else{
        printf("This word doesn't exist in the tree.\n");
    }
}
