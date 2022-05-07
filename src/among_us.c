#include "among_us.h"

unsigned int primes_g[650] = { 
                                 179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                                 233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
                                 283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
                                 353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
                                 419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
                                 467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
                                 547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
                                 607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
                                 661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
                                 739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
                                 811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
                                 877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
                                 947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
                                1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
                                1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151, 
                                1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223, 
                                1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291, 
                                1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373, 
                                1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451, 
                                1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511, 
                                1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583, 
                                1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657, 
                                1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733, 
                                1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811, 
                                1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889, 
                                1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987, 
                                1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053, 
                                2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129, 
                                2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213, 
                                2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287, 
                                2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357, 
                                2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423, 
                                2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531, 
                                2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617, 
                                2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687, 
                                2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741, 
                                2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819, 
                                2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903, 
                                2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999, 
                                3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079, 
                                3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181, 
                                3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257, 
                                3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331, 
                                3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413, 
                                3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511, 
                                3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571, 
                                3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643, 
                                3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727, 
                                3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821, 
                                3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907, 
                                3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989, 
                                4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057, 
                                4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139, 
                                4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231, 
                                4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297, 
                                4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409, 
                                4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493, 
                                4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583, 
                                4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657, 
                                4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751, 
                                4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831, 
                                4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937, 
                                4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003, 
                                5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087, 
                                5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179, 
                            };

/**
 * @brief Optional function to initialize tid structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize(void) {
    /*******a AND b INIT******/
    srand(time(0));
    p=find_the_prim(max_tid_g);
    if(!p)
        return 0;
    a=rand()%(p-1)+1;
    b=rand()%(p-1);
    /*******PLAYER INIT*******/
    players_tree=NULL;
    players_sentinel=(struct Player*)malloc(sizeof(struct Player));
    if(players_sentinel==NULL)
        return 0;
    players_sentinel->pid=-1;
    players_sentinel->is_alien=0;
    players_sentinel->evidence=0;
    players_sentinel->tasks=NULL;
    players_sentinel->parrent=NULL;
    players_sentinel->lc=NULL;
    players_sentinel->rc=NULL;

    /*******TASKS HT INIT********/
    int i;
    general_tasks_ht.count=0;
    general_tasks_ht.tasks=(struct HT_Task**)malloc(sizeof(struct HT_Tasks*)*max_tasks_g);
    for(i=0; i<max_tasks_g; i++)
        general_tasks_ht.tasks[i]=NULL;

    /******HASH COUNTERS INIT *******/
    hash_counter=0;
    list_counter=NULL;

    /******* QUEUE INIT *******/
    completed_tasks_pq.size=0;
    completed_tasks_pq.tasks=(struct HT_Task*)malloc(sizeof(struct HT_Task)*max_tasks_g);

	/******* MERGE ARRAYS INIT *******/
    array1=(struct Task**)malloc(sizeof(struct Task*)*max_tasks_g);
    array2=(struct Task**)malloc(sizeof(struct Task*)*max_tasks_g);
    array3=(struct Task**)malloc(sizeof(struct Task*)*max_tasks_g);
    return 1;
}

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {
    if(pid<0)
        return 0;
    if(is_alien!=1 && is_alien!=0)
        return 0;
    struct Player *new_player, *temp;
    int done;
    new_player=new_player_node(pid, is_alien);
    if(new_player==NULL)
        return 0;
    if(players_tree==NULL){
        players_tree=new_player;
        print_players();
        return 1;
    }
    temp=players_tree;
    done=0;
    while(!done){
        if(new_player->pid<=temp->pid){
            if(temp->lc!=players_sentinel){
                temp=temp->lc;
            }else{
                new_player->parrent=temp;
                temp->lc=new_player;
                done=1;
            }
        }else{
            if(temp->rc!=players_sentinel){
                temp=temp->rc;
            }else{
                new_player->parrent=temp;
                temp->rc=new_player;
                done=1;
            }
        }
    }
    print_players();
    return 1;
}

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
int insert_task(int tid, int difficulty) {
    if(tid<0)
        return 0;
    if(difficulty<1 || difficulty>3)
        return 0;
    int hash_code=hash_function(tid);
    if(hash_code==-1)
        return 0;           //hash function failed
    struct HT_Task *new_task_node=new_ht_task_node(tid, difficulty);
    if(new_task_node==NULL)
        return 0;         //failed
    new_task_node->next=general_tasks_ht.tasks[hash_code];
    general_tasks_ht.tasks[hash_code]=new_task_node;
    general_tasks_ht.count++;
    print_tasks();
    return 1;
}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks(void) {
	if(count_number_of_crewmates(players_tree)==0)
		return 0;   //there are no crewmates
    int done=0, found=0;
    for(hash_counter=0; hash_counter<max_tasks_g; hash_counter++){
        if(general_tasks_ht.tasks[hash_counter]!=NULL){
            list_counter=general_tasks_ht.tasks[hash_counter];
            found=1;
            break;
        }
    }
    if(!found)
        return 0;
    while(!done){
        in_order(players_tree, 'd');
        if(hash_counter==max_tasks_g && list_counter==NULL){
            done=1;
        }
    }
    print_double_tree();
    return 1;
}

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
int implement_task(int pid, int tid) {
    struct Player *player=find_player_with_pid(pid);
    struct Task *task;
    if(player==NULL)    //player not found
        return 0;
    if(player==players_sentinel)
        return 0;       //this node is sentinel
    if(player->is_alien)
        return 0;       //this player is an alien
    task=find_task_with_tid(player, tid);
    if(!task)
      return 0;     // task does not exist
    update_lc_counter(player->tasks, tid);
    enqueue(task->tid, task->difficulty);
    player->tasks=delete_task_node(player->tasks, tid);
    print_double_tree();
    printf("\n");
    //print_pq();
    return 1;
}

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
int eject_player(int pid_1, int pid_2) {
	struct Player *victim, *player;
	struct Task *victim_tasks;
	victim=find_player_with_pid(pid_1);
	player=find_player_with_pid(pid_2);
	if(victim==NULL || player==NULL)
		return 0;
	if(victim->is_alien || player->is_alien)
		return 0;
	victim_tasks=victim->tasks;

	if(!delete_player_node(pid_1))
        return 0;
    if(player->tasks==NULL && victim_tasks==NULL){
        //printf("(no need to merge))\n");
        print_double_tree();   //no need to call merge
        return 1;
    }
	player->tasks=merge(victim_tasks, player->tasks);
	print_double_tree();
    return 1;
}

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
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses){
    struct Player *victim, *player, *alien;
    struct Task *victim_tasks;
    victim=find_player_with_pid(pid_1);
    player=find_player_with_pid(pid_2);
    alien=find_player_with_pid(pid_a);
    if(!victim || !alien || !player)
        return 0;
    if(!alien->is_alien)
        return 0;
    if(victim->is_alien || player->is_alien)
        return 0;
    victim_tasks=victim->tasks;
    delete_player_node(pid_1);
    alien->evidence=alien->evidence+number_of_witnesses;
    if(player->tasks==NULL && victim_tasks==NULL){  //no need to call merge
        //printf("(no need to merge witnesses))\n");
        in_order(players_tree, 'e');
        return 1;
    }
    player->tasks=merge(victim_tasks, player->tasks);
    // use inorder to print double tree with player evidence
    in_order(players_tree, 'e');
    return 1;
}

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
int sabotage(int number_of_tasks, int pid) {
	struct Player *player=find_player_with_pid(pid);
    struct HT_Task *task;
	if(count_number_of_crewmates(players_tree)==0)
		return 0;                                         // there are no crewmates at the tree 
	if(player==NULL)
		return 0;                                 // couldnt find this player
	if(number_of_tasks>completed_tasks_pq.size)
		return 0;
	int i;
    // GO TO THE TARGET PLAYER
	for(i=0; i<number_of_tasks/2; i++)
		player=find_inorder_predecessor(player);

    // IF FOR EVERY TASK TO DEQUEUE FIND THE NEXT CREWMATE PLAYER
    for(i=0; i<number_of_tasks; i++){
        if(player->is_alien){
            while(player->is_alien)
                player=find_inorder_successor(player);
        }
        task=dequeue();
        assign_task(player, task->tid, task->difficulty);
        player=find_inorder_successor(player);
    }
    print_double_tree();
    return 1;
}

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
int vote(int pid_1, int pid_2, int vote_evidence) {
	struct Player *suspect=find_player_with_pid(pid_1);
	struct Player *player=find_player_with_pid(pid_2);
    struct Player *max_evidence_player;
    struct Task *max_evidence_player_tasks;
    int max_evidence=0;
    if(suspect==NULL || player==NULL)
		return 0;
	if(player->is_alien)
		return 0;
	suspect->evidence=suspect->evidence+vote_evidence;

	//FIND MAX EVIDENCE PLAYER
	find_max_evidence_player(players_tree, &max_evidence_player, &max_evidence);
	if(max_evidence_player==NULL)
		return 0;

	//HOLD MAX EVIDENCE PLAYERS TREE
	max_evidence_player_tasks=max_evidence_player->tasks;

	//DELETE MAX EVIDENCE PLAYER
	delete_player_node(max_evidence_player->pid);

	//MERGE THE EJECTED PLAYERS TREE WITH THE pid_2 PLAYERS TREE
	player->tasks=merge(max_evidence_player_tasks, player->tasks);

	// PRINT DOUBLE TREE WITH EVIDENCE
    //in_order(players_tree, 't');
	in_order(players_tree, 'e');
    return 1;
}


void find_max_evidence_player(struct Player *root, struct Player **max_evidence_player, int *max){
    if(root==NULL)
        return;
    find_max_evidence_player(root->lc, max_evidence_player, max);
    if(root->evidence>*max){
        *max=root->evidence;
        *max_evidence_player=root;
    }
    find_max_evidence_player(root->rc, max_evidence_player, max);
}

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
int give_work(int pid_1, int pid_2) {
    struct Player *player, *new_player;
    int number_of_tasks;
    player=find_player_with_pid(pid_1);
    if(!player)
        return 0;
    if(player->is_alien)
        return 0;
    if(!register_player(pid_2, 0))
    	return 0;
    new_player=find_player_with_pid(pid_2);
    if(!new_player)
        return 0;
    struct Task *tree1=NULL, *tree2=NULL;
    number_of_tasks=count_total_tasks(player->tasks);
    tree2=split(player->tasks, &tree1, number_of_tasks/2);
    player->tasks=tree1;
    new_player->tasks=tree2;
    print_double_tree();
    return 1;
}


/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate(void) {
    int number_of_aliens=count_number_of_aliens(players_tree);
    int number_of_crewmates=count_number_of_crewmates(players_tree);
    if(number_of_aliens>number_of_crewmates){
        printf("Aliens win\n");
        return 1;
    }
    if(number_of_aliens==0){
        printf("Crewmates win\n");
        return 1;
    }
    if(general_tasks_ht.count==completed_tasks_pq.size){
        printf("Crewmates win\n");
        return 1;
    }
    printf("No one wins\n");
    return 0;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players(void) {
    if(players_tree==NULL) //NO PLAYERS IN THE TREE
        return 0;
    printf("Players = ");
    in_order(players_tree, 'p');
    printf("\n");
    return 1;
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks(void) {
    struct HT_Task *temp;
    int i;
    for(i=0; i<max_tasks_g; i++){
        if(general_tasks_ht.tasks[i]==NULL){
            printf("Chain %d: empty\n", i);
            continue;
        }
        printf("Chain %d: ", i);
        temp=general_tasks_ht.tasks[i];
        while(temp!=NULL){
            printf("%d,%d ", temp->tid, temp->difficulty);
            temp=temp->next;
        }
        printf("\n");
    }
    return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq(void) {
    int i;
    if(!completed_tasks_pq.size){
        printf("NO COMPLETED TASKS!\n\n");
        return 0;
    }
    printf("Total Completed Tasks: %d\n", completed_tasks_pq.size);
    printf("Completed Tasks = ");
    for(i=0; i<completed_tasks_pq.size; i++)
        printf("%d,%d ", completed_tasks_pq.tasks[i].tid, completed_tasks_pq.tasks[i].difficulty);
    printf("\n");
    return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree(void) {
    in_order(players_tree, 't');
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */
int free_all(void) {
	int i;
	struct HT_Task *temp, *next;
	
	free(array1);
	free(array2);
	free(array3);
	in_order_free_double_tree(players_tree);
	free(completed_tasks_pq.tasks);
	for(i=0; i<max_tasks_g; i++){
		temp=general_tasks_ht.tasks[i];
		while(temp!=NULL){
			next=temp->next;
			free(temp);
			temp=next;
		}
	}
	free(general_tasks_ht.tasks);
	free(players_sentinel);
	free(list_counter);
    return 1;
}

void in_order_free_double_tree(struct Player *root){
	if(root==players_sentinel)
		return;
	in_order_free_double_tree(root->lc);
	in_order_free_player_tasks(root->tasks);
	free(root);
	in_order_free_double_tree(root->rc);
}

void in_order_free_player_tasks(struct Task *root){
	if(root==NULL)
		return;
	in_order_free_player_tasks(root->lc);
	free(root);
	in_order_free_player_tasks(root->rc);
}


                                                /*#######################
                                                      NEW FUNCTIONS
                                                ########################*/
/**
* @brief Creates a node for the player tree
* 
* @return new_node on success
*         NULL on failure
*/
struct Player* new_player_node(int pid, int is_alien){
    struct Player *new_node;
    new_node=(struct Player*)malloc(sizeof(struct Player));
    if(new_node==NULL)
        return NULL;
    new_node->pid=pid;
    new_node->is_alien=is_alien;
    new_node->evidence=0;
    new_node->parrent=NULL;
    new_node->lc=players_sentinel;
    new_node->rc=players_sentinel;
    new_node->tasks=NULL;
    return new_node;
}

/**
* @brief Creates a node for the task tree
*
* @return new_node on success
*         NULL on failure
*/
struct Task* new_task_node(int tid, int difficulty){
    struct Task *new_node;
    new_node=(struct Task*)malloc(sizeof(struct Task));
    if(new_node==NULL)
        return NULL;
    new_node->tid=tid;
    new_node->difficulty=difficulty;
    new_node->lcnt=0;
    new_node->lc=NULL;
    new_node->rc=NULL;
    return new_node;
}

/**
 * @brief creates a new task node for the hash table
 *
 * @param tid the tid of the task
 * @param difficulty the difficulty of the task
 */
struct HT_Task *new_ht_task_node(int tid, int difficulty){
    struct HT_Task *node;
    node=(struct HT_Task*)malloc(sizeof(struct HT_Task));
    if(!node)
        return NULL;
    node->tid=tid;
    node->difficulty=difficulty;
    node->next=NULL;
    return node;
}


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
void in_order(struct Player *root, char choise){
    if(root==players_sentinel)
        return;
    in_order(root->lc, choise);
    switch (choise){
    	case 'p':
            printf("%d:%d ", root->pid, root->is_alien);
	    	/*if(root->parrent==NULL)
        		printf("pid %d, alien %d, lc %d, rc %d\n", root->pid, root->is_alien, root->lc->pid, root->rc->pid);
    		else
    	    	printf("pid %d, alien %d, lc %d, rc %d, parrent %d\n", root->pid, root->is_alien, root->lc->pid, root->rc->pid, root->parrent->pid);*/
    		break;
    	case 'd':
    		if(root->is_alien==0 && root!=players_sentinel){
        		if(hash_counter!=max_tasks_g || list_counter!=NULL){
           			assign_task(root, list_counter->tid, list_counter->difficulty);
            		list_counter=list_counter->next;
        		}
        		if(list_counter==NULL && hash_counter!=max_tasks_g){
            		hash_counter++;
            		for(hash_counter; hash_counter<max_tasks_g; hash_counter++){
                		if(general_tasks_ht.tasks[hash_counter]!=NULL){
                    		list_counter=general_tasks_ht.tasks[hash_counter];
                    		break;
                		}
            		}
        		}
    		}
    		break;
    	case 't':
    		printf("Player %d = ", root->pid);
    		if(!root->is_alien && root->tasks!=NULL)
       			print_players_tasks(root->tasks);
    		else
        		printf("NO TASKS");
    		printf("\n");
            break;
        case 'e':
            printf("Player %d,%d = ", root->pid, root->evidence);
            if(!root->is_alien && root->tasks!=NULL)
                print_players_tasks(root->tasks);
            else
                printf("NO TASKS");
            printf("\n");
            break;
    }
    in_order(root->rc, choise);
}


/**
 * @brief prints the players task tree
 *
 * @param tasks the task tree to be printed
 */
void print_players_tasks(struct Task *tasks){
    if(tasks==NULL)
        return;
    print_players_tasks(tasks->lc);
    printf("%d,%d ", tasks->tid, tasks->difficulty);
    print_players_tasks(tasks->rc);
}

    
                                                /*###################
                                                       HASHING
                                                ####################*/
/**
 * @brief returns the lower prime number so all the keys exist between {0, p-1}
 * 
 * @param max_tid_g the greatest key
 *
 * @return the prime number on success
 *         0 on failure
 */
int find_the_prim(int max_tid_g){
    int index=0, i;
    for(i=0; i<650; i++){
        if(primes_g[index]>=max_tid_g){
            return primes_g[index];
        }
        index++;
    }
    return 0;
}

/**
 * @brief the hash function. Takes a key and generades a hash code
 *
 * @param key The key
 *
 * @return the hash code
 */ 
int hash_function(int key){
    if(!p)
        return -1;
    return ((a*key+b)%p)%max_tasks_g;
}


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
struct Player* find_player_with_pid(int pid){
    struct Player *temp;
    players_sentinel->pid=pid;
    temp=players_tree;
    while(temp!=NULL && temp->pid!=pid){
        if(pid<temp->pid)
            temp=temp->lc;
        else if(pid>temp->pid)
            temp=temp->rc;
    }
    players_sentinel->pid=-1;
    if(temp==players_sentinel)
    	return NULL;
    return temp;
}

/**
 * @brief searches a task tree and finds the task with tid 'tid'
 *
 * @param tid the tid of the task
 * @param player the player to find the task at his tasks tree
 *
 * @return the task on success
 *         NULL on failure
 */
struct Task* find_task_with_tid(struct Player* player, int tid){
    struct Task *temp;
    int found=0;
    temp=player->tasks;
    while(temp!=NULL && !found){
        if(tid<temp->tid)
            temp=temp->lc;
        else if(tid>temp->tid)
            temp=temp->rc;
        else
            found=1;
    }
    if(!found)
        return NULL;
    return temp;
}

/**
 * @brief finds the node with the minimum tid
 *
 * @param root the root of a task subtree
 *
 * @return the minimum node
 */
struct Task* find_min_tid_task(struct Task* root){
    struct Task *min;
    min=root;
    while(min->lc!=NULL)
        min=min->lc;
    return min;
}

/**
 * @brief finds the node with the minimum pid
 *
 * @param root the players tree root
 *
 * @return the minimum node
 */
struct Player *find_min_pid_player(struct Player *root){
	struct Player *min;
	min=root;
	while(min->lc!=players_sentinel)
		min=min->lc;
	return min;
}

/**
 * @brief finds the node with the max pid
 *
 * @param root the players tree root
 *
 * @return the max node
 */
struct Player *find_max_pid_player(struct Player *root){
	struct Player *max;
	max=root;
	while(max->rc!=players_sentinel)
		max=max->rc;
	return max;
}

/**
 * @brief finds the predecessor of a player
 *
 * @param player the player to find his predecessor
 *
 * @return the predecessor of the player
 */
struct Player *find_inorder_predecessor(struct Player *player){
    struct Player* temp=player->parrent;
    struct Player* min_pid=find_min_pid_player(players_tree);
    if(player==min_pid)
    	return find_max_pid_player(players_tree);
    if(player->lc!=players_sentinel)
        return find_max_pid_player(player->lc); 
    while(temp!=players_sentinel && player==temp->lc){ 
        player=temp; 
        temp=temp->parrent; 
    } 
    return temp; 
}

/**
 * @brief finds the successor of a player
 *
 * @param player the player to find his successor
 *
 * @return the successor of the player
 */
struct Player *find_inorder_successor(struct Player *player){
    struct Player* temp=player->parrent;   
    struct Player* max_pid=find_max_pid_player(players_tree); 
    if(player==max_pid)
        return find_min_pid_player(players_tree);  //to return the first node again
    if(player->rc!=players_sentinel) 
        return find_min_pid_player(player->rc);
    while(temp!=players_sentinel && player==temp->rc){ 
        player=temp; 
        temp=temp->parrent; 
    } 
    return temp; 
}




                                            /*####################
                                                QUEUE FUNCTIONS
                                            #####################*/
/**
 * @brief enqueues a task in the queue
 *
 * @param tid the task id
 * @param difficulty the tasks difficulty
 */
int enqueue(int tid, int difficulty){
    if(completed_tasks_pq.size==general_tasks_ht.count)
        return 0;    //queue is full
    int i;
    i=completed_tasks_pq.size;
    while(i>0 && difficulty>completed_tasks_pq.tasks[(i-1)/2].difficulty){
        completed_tasks_pq.tasks[i].tid=completed_tasks_pq.tasks[(i-1)/2].tid;
        completed_tasks_pq.tasks[i].difficulty=completed_tasks_pq.tasks[(i-1)/2].difficulty;
        i=(i-1)/2;
    }
    completed_tasks_pq.tasks[i].tid=tid;
    completed_tasks_pq.tasks[i].difficulty=difficulty;
    completed_tasks_pq.size++;
    return 1;
}

/**
 * @brief decueues an element from the queue
 *
 * @return A pointer to the task on succeed
 *         NULL on failure
 */
struct HT_Task* dequeue(void){
	if(completed_tasks_pq.size==0)
		return NULL;         //queue is empty
    struct HT_Task *poped, last_leaf;
    int i=0, max_child, size;

    poped=new_ht_task_node(completed_tasks_pq.tasks[0].tid, completed_tasks_pq.tasks[0].difficulty);
    if(size==1){
        completed_tasks_pq.size=0;
        return poped;
    }
    completed_tasks_pq.size=completed_tasks_pq.size-1;
    size=completed_tasks_pq.size;
    
    last_leaf.tid=completed_tasks_pq.tasks[completed_tasks_pq.size].tid;
    last_leaf.difficulty=completed_tasks_pq.tasks[completed_tasks_pq.size].difficulty;

    
    while((2*i+1<size && last_leaf.difficulty<completed_tasks_pq.tasks[2*i+1].difficulty) || 
            (2*i+2<size && last_leaf.difficulty<completed_tasks_pq.tasks[2*i+2].difficulty)){
        if(2*i+2<size){
            if(completed_tasks_pq.tasks[2*i+1].difficulty>completed_tasks_pq.tasks[2*i+2].difficulty)
                max_child=2*i+1;
            else
                max_child=2*i+2;
        }else{
            max_child=size-1;
        }
        completed_tasks_pq.tasks[i].tid=completed_tasks_pq.tasks[max_child].tid;
        completed_tasks_pq.tasks[i].difficulty=completed_tasks_pq.tasks[max_child].difficulty;
        i=max_child;
    }
    completed_tasks_pq.tasks[i].tid=last_leaf.tid;
    completed_tasks_pq.tasks[i].difficulty=last_leaf.difficulty;
    return poped;
}


 											/*#####################
                                                DELETE FUNCTIONS
                                            ######################*/
/**
 * @brief delets a node from the players task tree
 *
 * @param root the root at the task tree
 * @param tid the tid to be deleted
 */
struct Task* delete_task_node(struct Task *root, int tid){
    struct Task *temp;
    if(root==NULL)
        return root;
    else if(tid<root->tid)
        root->lc=delete_task_node(root->lc,tid);
    else if (tid>root->tid)
        root->rc=delete_task_node(root->rc,tid);
    else {
        if(root->lc==NULL && root->rc==NULL) { 
            root=NULL;
        }else if(root->lc==NULL || root->rc==NULL){
            temp=root;
            if(root->lc==NULL){
                root=root->rc;
            }
            else{
                root=root->lc;
            }
        }else{
            temp=find_min_tid_task(root->rc);
            my_swap(&root->tid, &temp->tid);
            my_swap(&root->difficulty, &temp->difficulty);
            /* DONT SWAP THE LCNT !!! */
            root->rc=delete_task_node(root->rc,tid);
        }
    }
    return root;
}

/**
 * @brief deletes the victim node from the players tree
 *
 * @param pid the player to be deleted
 *
 * @return 1 on success
 *         0 on failure
 */
int delete_player_node(int pid){
	struct Player *target, *temp, *child;
    target=find_player_with_pid(pid);
    if(!target)
        return 0;
    if(target->lc==players_sentinel || target->rc==players_sentinel)
        temp=target;
    else
        temp=find_min_pid_player(target->rc);
    if(temp->lc!=players_sentinel)
        child=temp->lc;
    else
        child=temp->rc;
    if(child!=players_sentinel)
        child->parrent=temp->parrent;
    if(temp->parrent==NULL){     // delete the root. Roots parent points at zero
        players_tree=child;
        return 1;
    }
    else if(temp==temp->parrent->lc)
        temp->parrent->lc=child;
    else
        temp->parrent->rc=child;
    if(temp!=target){
        target->pid=temp->pid;
        target->is_alien=temp->is_alien;
        target->evidence=temp->evidence;
    }
    return 1;
}




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
int assign_task(struct Player *player, int tid, int difficulty){
    int done;
    struct Task *new_task, *temp;
    new_task=new_task_node(tid, difficulty);
    if(new_task==NULL)
        return 0;
    if(player->tasks==NULL){
        player->tasks=new_task;
        return 1;
    }
    temp=player->tasks;
    done=0;
    while(!done){
        if(new_task->tid<=temp->tid){
            temp->lcnt++;
            if(temp->lc!=NULL){
                temp=temp->lc;
            }else{
                temp->lc=new_task;
                done=1;
            }
        }else{
            if(temp->rc!=NULL){
                temp=temp->rc;
            }else{
                temp->rc=new_task;
                done=1;
            }
        }
    }
    return 1;
}

/**
 * @brief updates all the left subtree node counters before deleteng a node. IT CAN BE USED ONLY FOR DELETING
 *
 * @param root the root of the tasks tree
 * @param tid the node with tid to be deleted
 *
 * @return back the pointer
 */
struct Task* update_lc_counter(struct Task *root, int tid){
	// THE TASK EXISTS BECAUSE OF THE CHECK AT THE IMPLEMENT FUNCTION SO THE LOOP IS SAFE
    struct Task *temp=root;
    int found=0;
    while(!found){
        if(tid<temp->tid){
            temp->lcnt--;
            temp=temp->lc;
        }else if(tid>temp->tid){
            temp=temp->rc;
        }else{
            found=1;
        }
    }
    return root;
}

/**
 * @brief swaps 2 integers
 *
 * @param x, y the 2 integers
 */
void my_swap(int *x, int *y){
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}

/**
 * @brief splits a task tree in half
 *
 * @param players_tasks the task tree root
 * @param new_tree the new tree with the half tasks. it will be returned by reference
 * @param collect the nnumber of the nodes for every tree. collect*2 (+1) must be equal with the sum of the primary tree nodes
 *
 * @return the one of the 2 trees
 */
struct Task* split(struct Task *root, struct Task **new_tree, int collect){
    struct Task *new_root_1, *new_root_2, *link1=NULL, *link2=NULL;
    struct Task *current=root, *prev=NULL, *temp=NULL;
    if(!root)
        return NULL; //empty tree
    int collected=0, created_root1=0, created_root2=0;
    int decrease;
    while(current!=NULL && collected<collect){
        if(collected+current->lcnt+1<=collect){
            // there is space for the left subtree so take it all and move to the right
            collected=collected+current->lcnt+1;  //update the number of the collected nodes
            if(!created_root1){
                //create the root for the one tree
                created_root1=1;
                new_root_1=current;
                link1=current;
            }else{
                link1->rc=current;
                link1=current;
            }
            if(!created_root2 && collect==collected)
                //in case the tree must be splited in half
                new_root_2=current->rc;
            prev=current;
            current=current->rc;
            //break the node link
            prev->rc=NULL;
        }else{
            // there is no space for the left subtree so traverse it until it becomes small enough
            if(!created_root2){
                //create the root for the second tree
                created_root2=1;
                new_root_2=current;
                link2=current;
            }else{
                link2->lc=current;
                // at every link at left the count_total_tasks will help to update the lcnt of the parent node
                temp=new_root_2;
                while(temp!=NULL){
                    temp->lcnt=count_total_tasks(temp->lc);
                    temp=temp->lc;
                }
                
                link2=current;
            }
            prev=current;
            current=current->lc;

            //break the node link
            prev->lc=NULL;
            //update the lcnt
            decrease=prev->lcnt;
            updt(new_root_2, decrease);         
        }
    }
    *new_tree=new_root_2;

    return new_root_1;
}

/**
 * @brief every time a left link breaks this function updates all the previous lcnt.
 *
 * @param root the root to the tree. from this root will start the traversal goinig always to the left
 * @param decrease a number that shows how many lcnt to decrease
 */
void updt(struct Task* root, int decrease){
	struct Task *temp;
	temp=root;
	while(temp!=NULL){
    	temp->lcnt=temp->lcnt-decrease;
    	temp=temp->lc;
   	}
}




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
int count_number_of_aliens(struct Player *root){
    int sum=0;
    if(root==players_sentinel)
        return sum;
    sum=sum+count_number_of_aliens(root->lc);
    if(root->is_alien){
        sum++;
    }
    sum=sum+count_number_of_aliens(root->rc);
    return sum;
}

/**
 * @brief counts the number of the crewmates at the tree using inorder traversal
 *
 * @param root the root at the players tree
 *
 * @return the number of the crewmates
 */
int count_number_of_crewmates(struct Player *root){
    int sum=0;
    if(root==players_sentinel)
        return sum;
    sum=sum+count_number_of_crewmates(root->lc);
    if(!root->is_alien){
        sum++;
    }
    sum=sum+count_number_of_crewmates(root->rc);
    return sum;
}

/**
 * @brief counts the total players at the game
 *
 * @return the number of the total players
 */
int count_total_players(void){
    return count_number_of_crewmates(players_tree)+count_number_of_aliens(players_tree);
}

/**
 * @brief counts the total tasks of a player
 *
 * @param root the root of the players task tree
 *
 * @return the number of tasks
 */
int count_total_tasks(struct Task* root){
    int sum=0;
    if(root==NULL)
        return 0;
    sum=sum+count_total_tasks(root->lc);
    sum++;
    sum=sum+count_total_tasks(root->rc);
    return sum;
}





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
struct Task *merge(struct Task* victim_tasks, struct Task* player_tasks){
    int index1=0;
    int index2=0;

	in_order_store(victim_tasks, 1, &index1);
	in_order_store(player_tasks, 2, &index2);

	int i=0, j=0, index3=0;

	// merge the 2 arrays into the third one in O(n1+n2) time
	while(i<index1 && j<index2){
		if(array1[i]->tid<=array2[j]->tid){
			array3[index3]=array1[i];
			i++;
		}else{
			array3[index3]=array2[j];
			j++;
		}
		index3++;
	}
	while(i<index1){
		array3[index3]=array1[i];
		i++;
		index3++;
	}
	while(j<index2){
		array3[index3]=array2[j];
		j++;
		index3++;
	}
	//turn the array3 into a tree with logn heigh and give it to the player
	player_tasks=insert_array_to_tree(array3, 0, index3-1);

	//call the 2 functions to update the lcnt of every tree node
	inorder(player_tasks);
	inorder2(player_tasks);
	return player_tasks;
}

/**
 * @brief stores a tree in an array
 *
 * @param root the tree root
 * @param array Call with array=1 to store the elements at the array1
 *				Call with array=2 to store the elements at the array2
 * @param index points at the current array position. It will be returned by reference and will be the length of the array
 */
void in_order_store(struct Task *root, int array, int *index){
	if(root==NULL)
		return;
	in_order_store(root->lc, array, index);
	if(array==1)			//if array argument is 1 store the elements at the array1
		array1[*index]=root;
	else                    // else store them into array2
		array2[*index]=root;
    *index=*index+1;
	in_order_store(root->rc, array, index);
}

/**
 * @brief converts an array to a tree
 *
 * @param array the array with tha tasks to put in the tree
 * @param first_position the starting point of the array
 * @param last_position the last index of the array
 *
 * @return the tree root
 */
struct Task* insert_array_to_tree(struct Task **array, int first_position, int last_position){
	struct Task *temp;
	if(first_position>last_position)
    	return NULL;
    // split the arrasy in half
    int mid=(first_position+last_position)/2;
    //create a new tree node with tje middle element of the array
    temp=new_task_node(array[mid]->tid, array[mid]->difficulty);
    //do the same thing for every subtree recursively
    temp->lc=insert_array_to_tree(array, first_position, mid-1);
    temp->rc=insert_array_to_tree(array, mid+1, last_position); 
    return temp;
}

/* inorder AND inorder2 ARE USED TO UPDATE THE lcnt. IF THE TREE HAS logn HIGH AND EVERY LCNT CONTAINS THE SUBNODES
   A SOLUTION TO UPDATE lcnt IS TO DECREASE THE lcnt BY 1 AND THEN DEVIDE BY 2. SO inorder WILL UPDATE THE lcnt WITH THE
   SUM OF THE SUBNODES OF EVERY SINGLE NODE AND THE inorder2 WILL BE CALLED AFTER inorder AND DECREASE EVERY lcnt BY ONE 
   AND DIVIDE BY 2*/
/**
 * @brief using inorder counts all the subtrees of the root and stores the result at the lcnt of every node
 *
 * @param root the task tree root
 */
void inorder(struct Task *root){
	if(root==NULL)
		return;
	inorder(root->lc);
	//store in lcnt of every node the number of its subnodes + the root itself
	root->lcnt=count_total_tasks(root);
	inorder(root->rc);
}
/**
 * @brief for every lcnt does the following: decreases the lcnt by one and devides it with 2
 *
 * @param root the tree root
 */
void inorder2(struct Task *root){
	if(root==NULL)
		return;
	inorder2(root->lc);
	root->lcnt=root->lcnt-1;
	root->lcnt=root->lcnt/2;
	inorder2(root->rc);
}
