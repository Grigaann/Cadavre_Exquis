#include "tree.h"
#include "node.h"
#include "sentences.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int wrong_ans=1;
    char wordeu[100];
    int ans_menu1, ans_menu2;

    tree_list trees = initialize_trees();
    printf("Welcome in this simulation.\n");
    while(1) {
        printf("\n          This is the menu :\n\n"
               "Enter 1 if you wish to see the tree\n"
               "Enter 2 if you wish to search for a word\n"
               //"Enter 3 if you wish to create a homemade sentence\n"
               "4 for random word\n"
               "Enter 0 if you want to exit this program\n"
               " Your choice :");
        scanf("%d", &ans_menu1);
        switch (ans_menu1) {
            case 0:
                printf("See you later.");
                exit(3);
            case 1:
                while (wrong_ans){
                    printf("\nWhich tree do you wish to see ?\n\n"
                           "Enter 1 if you wish to see the names\n"
                           "Enter 2 if you wish to see the adjectives\n"
                           "Enter 3 if you wish to see the verbs\n"
                           "Enter 4 if you wish to see the adverbs\n"
                           "Enter 0 if you want to exit this menu\n"
                           " Your choice :");
                    scanf("%d", &ans_menu2);
                    switch (ans_menu2) {
                        case 0:
                            wrong_ans=0;
                            break;
                        case 1:
                            print_tree(trees.name_tree->root, 0);
                            wrong_ans=0;
                            break;
                        case 2:
                            print_tree(trees.adj_tree->root, 0);
                            wrong_ans=0;
                            break;
                        case 3:
                            print_tree(trees.verb_tree->root, 0);
                            wrong_ans=0;
                            break;
                        case 4:
                            print_tree(trees.adv_tree->root, 0);
                            wrong_ans=0;
                            break;
                        default:
                            wrong_ans=1;
                            break;
                    }
                }
                break;
            case 2:
                printf("Enter the word you are looking for :");
                scanf(" %s", wordeu);
                word_in_tree(wordeu, trees.name_tree);
                break;
            case 3:
                //create_sentence();
                break;
            case 4:
                printf("%s", get_random_word(trees.name_tree));
                break;
            default:
                break;
        }
    }
    return 0;
}