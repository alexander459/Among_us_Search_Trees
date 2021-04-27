
#ifndef __AMONG_US_H_
#define __AMONG_US_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

/**
 * Structure defining a node of the players double linked tree
 * tree
 */
struct Player
{
    int pid;                        /*Player's identifier*/
    int is_alien;                   /*Alien flag*/
    int evidence;                   /*Amount of evidence*/
    struct Player *parrent;         /*Pointer to the parent node*/
    struct Player *lc;              /*Pointer to the left child node*/
    struct Player *rc;              /*Pointer to the right child node*/
    struct Task *tasks;             /*Pointer to the head of player's task tree*/
};

/**
 * Structure defining a node of the tasks sorted tree
 */
struct Task
{
    int tid;                        /*Task's identifier*/
    int difficulty;                 /*Task's difficulty*/
    int lcnt;                       /*Node's left child's node counter*/
    struct Task *lc;                /*Pointer to the left child node*/
    struct Task *rc;                /*Pointer to the right child node*/ 
};

struct HT_Task
{
    int tid;                        /*Task's identifier*/
    int difficulty;                 /*Task's difficulty*/
    struct HT_Task *next;           /*Pointer to the next node*/
};

struct General_Tasks_HT
{
    int count;                      /*Count of tasks*/
    struct HT_Task **tasks;         /*General tasks hash table*/
};

struct Completed_Tasks_PQ
{
    int size;                       /*Count of completed tasks*/
    struct HT_Task *tasks;         /*Completed tasks priority queue*/
};

unsigned int max_tasks_g; /* Max number of tasks */
unsigned int max_tid_g;   /* Max task tid */



/* Primes for your universal hashing implementation */
extern unsigned int primes_g[650];

/* Global variable, pointer to the head of the players tree */
struct Player *players_tree;

/* Global variable, pointer to the head of the tasks tree */
struct General_Tasks_HT general_tasks_ht;

/* Global variable, pointer to the top of the completed task's priority queue */
struct Completed_Tasks_PQ completed_tasks_pq;

/* Global variables, arrays used for merging tasks trees */
struct Task **array1, **array2, **array3;

/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize(void);

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien);

/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty);

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks(void);

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid);

/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
int eject_player(int pid_1, int pid_2);

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses);

/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid);

/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence);

/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2);

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate(void);

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players(void);

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks(void);

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq(void);

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree(void);

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */

int free_all(void);


/* a, b and p for the implementation of the universal hashing */
unsigned int a;
unsigned int b;
unsigned int p;  

/* Global variable, list counter for the hash tables chains */
struct HT_Task *list_counter;

/* Global variable, counter for the hash tables array */
int hash_counter;

/* Global variable, pointer to the sentinel node of the players tree */
struct Player *players_sentinel;




												/*#######################
												      NEW FUNCTIONS
												########################*/
/**
* @brief Creates a node for the player tree
* 
* @return new_node on success
*         NULL on failure
*/
struct Player* new_player_node(int pid, int is_alien);

/**
* @brief Creates a node for the players task tree
*
* @return new_node on success
*         NULL on failure
*/
struct Task* new_task_node(int tid, int difficulty);

/**
 * @brief creates a new task node for the hash table
 *
 * @param tid the tid of the task
 * @ @param difficulty the difficulty of the task
 */
struct HT_Task *new_ht_task_node(int tid, int difficulty);




											    /*#########################
										    		IN-ORDER FUNCTIONS
												#########################*/
/**
 * @brief implements an inorder traversal. prints the players
 *
 * @param the players tree root
 * @param choise the choise to implement p for printing players
 *                                       d for distribute
 *                                       t for player traversal and printing double tree
 *                                       e for player traversal and printing double tree with evidence
*/
void in_order(struct Player *root, char choise);

/**
 * @brief prints the players task tree
 *
 * @param tasks the task tree to be printed
 */
void print_players_tasks(struct Task *tasks);


	
												/*###################
													   HASHING
												####################*/
/**
 * @brief returns the lower prime number
 * so all the keys exist between {0, p-1}
 * 
 * @param max_tid_g the greatest key
 *
 * @return the prime number on success
 *         0 on failure
 */
int find_the_prim(int max_tid_g);

/**
 * @brief the hash function. Takes a key and generades a hash code
 *
 * @param key The key
 *
 * @return the hash code
 */ 
int hash_function(int key);




												/*######################
													LOOK UP FUNCTIONS
												#######################*/
/**
 * @brief searches the tree and finds the player with pid 'pid'
 *
 * @param pid the pid of the player
 *
 * @return the player on success
 *         NULL on failure
 */
struct Player *find_player_with_pid(int pid);

/**
 * @brief searches a task tree and finds the task with tid 'tid'
 *
 * @param tid the tid of the task
 * @param player the player to find the task at his tasks tree
 *
 * @return the task on success
 *         NULL on failure
 */
 struct Task* find_task_with_tid(struct Player* player, int tid);

/**
 * @brief finds the node with the minimum tid
 *
 * @param root the root of a task subtree
 *
 * @return the minimum node
 */
struct Task* find_min_tid_task(struct Task* root);

/**
 * @brief finds the node with the minimum pid
 *
 * @param root the players tree root
 *
 * @return the minimum node
 */
struct Player *find_min_pid_player(struct Player *root);

/**
 * @brief finds the node with the max pid
 *
 * @param root the players tree root
 *
 * @return the max node
 */
struct Player *find_max_pid_player(struct Player *root);

/**
 * @brief finds the successor of a player
 *
 * @param player the player to find his successor
 *
 * @return the successor of the player
 */
struct Player *find_inorder_successor(struct Player *player);

/**
 * @brief finds the predecessor of a player
 *
 * @param player the player to find his predecessor
 *
 * @return the predecessor of the player
 */
struct Player *find_inorder_predecessor(struct Player *player);



                                            /*####################
                                                QUEUE FUNCTIONS
                                            #####################*/
/**
 * @brief enqueues a task in the queue
 *
 * @param tid the task id
 * @param difficulty the tasks difficulty
 */
int enqueue(int tid, int difficulty);

/**
 * @brief decueues an element from the queue
 *
 * @return A pointer to the task on succeed
 *         NULL on failure
 */
struct HT_Task* dequeue(void);



                                            /*#####################
                                                DELETE FUNCTIONS
                                            ######################*/
/**
 * @brief delets a node from the players task tree. Used for implement event
 *
 * @param root the root at the task tree
 * @param tid the tid to be deleted
 */
struct Task* delete_task_node(struct Task *root, int tid);

/**
 * @brief deletes the victim node from the players tree
 *
 * @param pid the player to be deleted
 *
 * @return 1 on success
 *         0 on failure
 */
int delete_player_node(int pid);



											/*###################
												OTHER FUNCTIONS
											####################*/
/**
 * @brief assignes a new task at a player task tree
 *
 * @param player the player to assign the task
 * @param tid the task with tid to assign at the player
 * @param difficulty the difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int assign_task(struct Player *player, int tid, int difficulty);

/**
 * @brief updates all the left subtree node counters before deleteng a node. IT CAN BE USED ONLY FOR DELETING
 *
 * @param root the root of the tasks tree
 * @param tid the node with tid to be deleted
 *
 * @return back the pointer
 */
struct Task* update_lc_counter(struct Task *root, int tid);

/**
 * @brief swaps 2 integers
 *
 * @param x, y the 2 integers
 */
void my_swap(int *x, int *y);

/**
 * @brief splits a task tree in half
 *
 * @param players_tasks the task tree root
 * @param new_tree the new tree with the half tasks. it will be returned by reference
 * @param collect the nnumber of the nodes for every tree. collect*2 (+1) must be equal with the sum of the primary tree nodes
 *
 * @return the one of the 2 trees
 */
struct Task* split(struct Task *player_tasks, struct Task **new_tree, int collect);

/**
 * @brief every time a left link breaks this function updates all the previous lcnt. USED ONLY FOR THE SPLIT
 *
 * @param root the root to the tree. from this root will start the traversal goinig always to the left
 * @param decrease a number that shows how many lcnt to decrease
 */
void updt(struct Task* root, int decrease);



                                                /*#########################
                                                      MERGE FUNCTIONS
                                                ##########################*/
/**
 * @brief merges 2 task trees at logn high
 *
 * @param victim_tasks the tree root of the victims tasks
 * @param players_tasks the tree root of the players tasks
 *
 * @return the merged tree root
 */
struct Task *merge(struct Task* victim_tasks, struct Task* player_tasks);

/**
 * @brief stores a tree in an array
 *
 * @param root the tree root
 * @param array Call with array=1 to store the elements at the array1
 *              Call with array=2 to store the elements at the array2
 * @param index points at the current array position. It will be returned by reference and will be the length of the array
 */
void in_order_store(struct Task *root, int array, int *index);

/**
 * @brief converts an array to a tree
 *
 * @param array the array with tha tasks to put in the tree
 * @param first_position the starting point of the array
 * @param last_position the last index of the array
 *
 * @return the tree root
 */
struct Task* insert_array_to_tree(struct Task **array, int first_position, int last_position);

/* inorder AND inorder2 ARE USED TO UPDATE THE lcnt. IF THE TREE HAS logn HIGH AND EVERY LCNT CONTAINS THE SUBNODES
   A SOLUTION TO UPDATE lcnt IS TO DECREASE THE lcnt BY 1 AND THEN DEVIDE BY 2. SO inorder WILL UPDATE THE lcnt WITH THE
   SUM OF THE SUBNODES OF EVERY SINGLE NODE AND THE inorder2 WILL BE CALLED AFTER inorder AND DECREASE EVERY lcnt BY ONE 
   AND DIVIDE BY 2*/
/**
 * @brief using inorder counts all the subtrees of the root and stores the result at the lcnt of every node
 *
 * @param root the task tree root
 */
void inorder(struct Task *root);
/**
 * @brief for every lcnt does the following: decreases the lcnt by one and devides it with 2
 *
 * @param root the tree root
 */
void inorder2(struct Task *root);


                                                /*############################
                                                          COUNTERS
                                                #############################*/
/**
 * @brief counts the number of the aliens at the tree using inorder traversal
 *
 * @param root the root at the players tree
 *
 * @return the number of the aliens
 */
int count_number_of_aliens(struct Player *root);

/**
 * @brief counts the number of the crewmates at the tree using inorder traversal
 *
 * @param root the root at the players tree
 *
 * @return the number of the crewmates
 */
int count_number_of_crewmates(struct Player *root);

/**
 * @brief counts the total players at the game
 *
 * @return the number of the total players
 */
int count_total_players(void);

/**
 * @brief counts the total tasks of a player
 *
 * @param root the root of the players task tree
 *
 * @return the number of tasks
 */
int count_total_tasks(struct Task* root);
void find_max_evidence_player(struct Player *root, struct Player **max_evidence_player, int *max);

void in_order_free_double_tree(struct Player *root);
void in_order_free_player_tasks(struct Task *root);
#endif /* __AMONG_US_H_ */
