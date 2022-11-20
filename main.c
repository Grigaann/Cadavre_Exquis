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
    int bool = 1;
    char which_tree;

    tree_list trees = initialize_trees();
    printf("Welcome in the Automatic sentences generator.\n");
    while(bool) {
        printf("\nEnter :\n 1 if you wish to see a tree\n"
               " 2 if you wish to search for a word\n"
               //" 3 if you wish to create a homemade sentence (wip)\n"
               //" 4 to get a random word (wip)\n"
               "\n 0 if you want to exit this program\n\n");
        scanf(" %d", &ans_menu1);
        switch (ans_menu1) {
            case 0:
                printf("See you later.");
                bool = 0;
                break;
            case 1:
                while (wrong_ans){
                    printf("\nWhich tree do you wish to see ?\n\n"
                           "Enter : \n1 if you wish to see the names\n"
                           "2 if you wish to see the adjectives\n"
                           "3 if you wish to see the verbs\n"
                           "4 if you wish to see the adverbs\n"
                           "0 if you want to go back\n");
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
                printf("Enter the base form of the word you are looking for :");
                scanf(" %s", wordeu);
                printf("Enter\n"
                       "'n' if it is a noun\n"
                       "'v' if it is a verb\n"
                       "'a' for an adjective\n"
                       "'A' for an adverb\n");
                scanf(" %c",&which_tree);
                switch (which_tree) {
                    case 'n':
                        word_in_tree(wordeu, trees.name_tree);
                        break;
                    case 'v':
                        word_in_tree(wordeu, trees.verb_tree);
                        break;
                    case 'a':
                        word_in_tree(wordeu, trees.adj_tree);
                        break;
                    case 'A':
                        word_in_tree(wordeu, trees.adv_tree);
                        break;
                }
                break;
            case 3:
                //create_sentence();
                break;
            case 4:
                printf(" %s", get_random_word(trees.name_tree));
                break;
            default:
                break;
        }
    }
    return 0;
}