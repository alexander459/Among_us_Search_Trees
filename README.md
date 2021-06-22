# Among_us_Search_Trees
Language: C

This is a non virtual representation of the video game "Among us". This project uses data structures to store the players and the tasks and implements functions on them in specific time complexity. The project is splitted in two parts. The second part (this one) uses search trees, hash tables and priority queues.

In the game there are players and tasks. Players: The players can be either crewmates either impostors. The players are stored in a double linked binary search tree with sentinel node sorted by the players id. Each player has 3 attributes: their id, their role(crewmate/impostor) and their evidence. They also have a tree root for for their task tree as far as they are crewmates.

Tasks: There are 3 types of tasks which are formed by their difficulty. Tasks of difficulty 1, tasks of difficulty 2 and tasks of difficulty 3. Before they are distributed to the players, the tasks are stored in a hash table. This hash table uses a universal hashing function and seperated chainging to avoid colisions. The tasks are sorted by their difficulty.

When a task is implemented it is stored in a priotity queue. Difficult tasks have priority. For the program functionality there is a set of instructions: 

`P <pid> <is_alien>` This instruction signals the insertion of a new player in the players tree with id=pid and with role=is_alien. The player will be added in the tree (inordered) Time complexity O(log(n))

`T <tid> <difficulty>` This instruction signals the insertion of a new task with id=tid and difficulty=difficulty in the hash table. The tid is passed in the hash function. Time complexity: Hash function O(1), insertion ~O(n)

`D` During this event the tasks from the general task hash table are distributed to the players following a round robin algorithm according to the inorder traversal. Time complexity O(n) (n is the amount of the tasks in general task list).

`I <pid> <tid>` This instruction signals the implementation of a task with tid: tid by the player: pid. The task must be removed from the players task tree updating the left child counters. After the implementation the task is inserted in the priority queue

`E <pid1> <pid2>` This instructions signals the ejection of the player: pid1 by an impostor. The player is removed from the players list. Their task tree will be merged with the task tree of the player with pid: pid2. The merged tree has a height of log(n), the left child counters are updated and the time complexity is O(n1+n2) where n1 is the nodes of the one tree and n2 the nodes of the other one.

`W <pid1> <pid2> <pid_a > <number_witnesses>` This instructions signals the ejection of player: pid1 by the impostor: pid_a. However there are witnesses so the impostor with pid: pid_a will obtain number_witnesses evidence. The tasks of the pid1 player will be merged with the task tree of pid2 player followintg the same algorithm as at the E event.

`S <number_of_tasks> <pid>` This instruction signals a sabotage by an impostor. Number_of_tasks tasks will be removed from the priority queue and will be given back to the players according to the following algorithm: The first task is given to the player floor(number_of_tasks/2) positions after the pid player (Predecessor). For every other task find Successor and assign the task to their task tree

`V <pid1> <pid2> <vote_evidence>` This instruction signals a vote event by the the player: pid1. This player will also obtain vote_evidence evidence because they look suspicious. The player with the most evidence will be kicked be an algorithm like the E event merging their tree with that of the player: pid2.

`G <pid1> <pid2>` This instruction signals a Give Away Work event. The player with pid: pid1 will give the half of their tasks to a new player with pid: pid2 by the following algorithm: Count the number of the tree's nodes. Split in two equal parts. Time complexity: O(h) where h is the height of the player's: pid1 tree 

`F` This instruction indicates the termination of the game. During this event if the impostors are more than the crewmates then the impostors win. If there are no impostors or the completed tasks priority queue contains the number of the primary tasks then the crewmates win.

`X`: prints the players 
`Y`: prints the tasks from general task hash table
`Z`: prints the completed tasks queue
`U`: prints the players with their task tree
