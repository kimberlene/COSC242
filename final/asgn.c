/**asgn.c file for COSC242 assignment.
   Written on Thursday the 13th of September
   @author Joe Marshall marjo989
   @author Rik Karmakar karri390
   @author Kim Sharma shaki694
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "tree.h"
#include "htable.h"
#include "mylib.h"
#include <math.h>
#include <time.h>

/**is_prime method
   @param n the number we want to check
   @return 1 if n is prime, 0 if not
   This method takes an integer and determines whether it is prime
*/
static int is_prime(int n){
    int i;
    for(i = 2; i < n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

/**print_info method
   @param freq the frequency
   @param word the word
   This method is to be passed to our other printing methods
*/
static void print_info(int freq, char *word) {
    printf("%-4d %s\n", freq, word);
}

/**print_help method
   this method is only called when an invalid command is entered.
*/
static void print_help(){
    printf("Perform tasks using a hash table or binary tree,"
            "By default, words read from stdin are added,"
            "to the data structure before printing them,"
            "along with their frequencies, to stdout.\n");
    printf(" -T : Use a tree data structure (default is hash table)");
    printf(" -c FILENAME : Check spelling of words in FILENAME using words"
              "from stdin as dictionary.  Print unknown words to"
              "stdout, timing info etc to stderr (ignore -o & -p)");
    printf(" -d : Use double hashing (linear probing is the default)");
    printf(" -e :  Display entire contents of hash table on stderr");
    printf(" -o : Output the tree in DOT form to file 'tree-view.dot'");
    printf(" -p : Print hash table stats instead of frequencies & words");
    printf(" -r : Make the tree an RBT (the default is a BST)");
    printf(" -s SNAPSHOTS : Show SNAPSHOTS stats snapshots (if -p is used)");
    printf(" -t TABLESIZE : Use the first prime >= TABLESIZE as htable size");
    printf(" -h : Display this message");    
}

/**The mighty main*/
int main(int argc, char **argv){
    clock_t start_t, end_t;
    double total_t;
    
    FILE *check;

    FILE *dot;  

    char *doc_name = NULL;

    int table_size = 113;

    const char *optstring = "Tc:deoprs:t:h";

    char command;

    /**Default 10 unless -s command given*/
    int stat_snapshots = 10;

    tree t;

    htable h;

    char word[256];

    int unknown = 0;

    /**For Command line arguments*/
    unsigned int structure_type = 0;
    unsigned int collision_resolution = 0;
    unsigned int display_contents = 0;
    unsigned int output_tree = 0;
    unsigned int print_stats = 0;
    unsigned int check_spell = 0;
    unsigned int tree_type = 0;

    if(argc > 0){
        while((command = getopt(argc, argv, optstring)) != EOF){
            switch(command){
                case 'T':
                    structure_type = 1;
                    break;
                case 'c':
                    doc_name = optarg;
                    check_spell = 1;
                    break;
                case 'd':
                    collision_resolution = 1;
                    break;
                case 'e':
                    display_contents = 1;
                    break;
                case 'o':
                    output_tree = 1;
                    break;
                case 'p':
                    print_stats = 1;
                    break;
                case 'r':
                    tree_type = 1;
                    break;
                case 's':
                    stat_snapshots = atoi(optarg);
                    break;
                case 't':
                    /**Use first prime greater or equal than default table size*/
                    table_size = atoi(optarg);
                    while(!is_prime(table_size)){
                        table_size++;
                    }
                    break;
                default:
                    print_help();
                    exit(EXIT_FAILURE);
            }
        }

        /**Make sure files used are valid*/
        if(check_spell == 1){
            check = fopen(doc_name, "r");
            if(check == NULL){
                fprintf(stderr, "Check file not found\n");
                exit(EXIT_FAILURE);
            }
        }

        /**If we want to use a tree*/
        if(structure_type == 1){
            /**Determine type of tree*/
            if(tree_type == 1){
                t = tree_new(RBT);
            }else{
                t = tree_new(BST);
            }
            
            if (check_spell == 1){
                /**Time the input*/
                start_t = clock();
            }
            
            /**Insert into the tree*/
            while(getword(word, sizeof word, stdin) != EOF){
                t = tree_insert(t, word);

            }
            
            if (check_spell == 1){
                end_t = clock();
                total_t = (end_t- start_t) / (double)CLOCKS_PER_SEC;



                /**Time the searching*/
                start_t = clock();
                while(getword(word, strlen(word), check)){
                    if(tree_search(t, word) != 1){
                        /**If not in dictionary, increment unknown word count*/
                        printf("%s\n", word);
                        unknown++;
                    }
                }
                
                /**Print out fill time */
                printf("Fill time: %5f\n", total_t);
                end_t = clock();
                total_t = (end_t- start_t) / (double)CLOCKS_PER_SEC;

                /**Print out search time*/
                printf("Search time: %5f\n", total_t);
                printf("Unknown words: %d\n", unknown);
            }

            /**If we are passed -o as an argument*/
            if(output_tree == 1 && check_spell != 1){
                printf("Creating dot file 'tree-view.dot'\n");
                dot = fopen("tree-view.dot", "w");
                tree_output_dot(t, dot);
            }
            
            tree_preorder(t, print_info);
                
        }else{
            /**We want to use a hash table*/

            /**Determine hashing strategy*/
            if(collision_resolution == 1){
                h = htable_new(table_size, DOUBLE_H);
            }else{
                h = htable_new(table_size, LINEAR_P);
            }

            if (check_spell == 1){
                /**Time the input*/
                start_t = clock();
            }

            /**Insert into the hash table*/
            while(getword(word, sizeof word, stdin) != EOF){
                htable_insert(h, word);
            }
            
            if (check_spell == 1){
                end_t = clock();
                total_t = (end_t- start_t) / (double)CLOCKS_PER_SEC;

                

                /**Time the searching*/
                start_t = clock();
                while(getword(word, sizeof word, check) != EOF){
                    if(htable_search(h, word) != 1){
                        /**If not in dictionary, increment unknown word count*/
                        printf("%s\n", word);
                        unknown++;
                    }
                }

                /**Print out fill time */
                printf("Fill time: %5f\n", total_t);
                
                end_t = clock();
                total_t = (end_t- start_t) / (double)CLOCKS_PER_SEC;

                printf("Search time: %5f\n", total_t);
                printf("Unknown words: %d\n", unknown);
            }

            /**If we are passed command -e*/
            if(display_contents == 1){
                htable_print_entire_table(h, stderr);
            }

            /**If we are passed command -p*/
            /**If -s was passed, it changes the default
               value of stat_snapshots. Otherwise, use
               default value of 10. */
            if(print_stats == 1 && check_spell != 1){
                htable_print_stats(h, stdout, stat_snapshots);
            } else if (check_spell != 1) {
                htable_print(h, print_info);
            }
        }
    }
    return EXIT_SUCCESS;
} 
