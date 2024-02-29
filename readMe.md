# ToDo

sort_big -> init_cheapest_exec -> exec_router -> executoooooorr!!!!
-------------calc_c_node_exec

init_cheapest_exec()

-   Test for functionality

calc_node_c_exec()

-   check that highest and lowest node dont overwrite each other
-   check that the normal function doesnt overwrite its self

calc_node_c_exec_continued()

-   Continue and add conditions for higher & lower

exec_router

-   Build exec router, which knows the combination of rotations
-   route to executooor.c functions

free_memory()

-   handle any leaks that may have happened

## PUSH_SWAP

### Initializing global var struct

### Parsing

Parameters are stored as STR in ARGV. Convert to INT and check validity

-   atoi (with double)
-   throw error if any char is not DIGIT and exit program
    -   Error format: display "Error" followed by a ’\n’ on the STANDARD ERROR
        -   include stderror lib

### Validation

Check for:

-   Non Int
-   > MAX_INT
-   < MIN_INT
-   Duplicates

### INDEXING

-   "pre-sort" Stack A, assigning an order index to every Node

### SORTING

#### Sort 3

#### Sort 4

#### Sort high number of params

### OUTPUT

-   simple linked list
-   contains the commands as strings
-   go through whole list and group duplicates
    -   ra, rb => rr
    -   rra, rrb => rrr
    -   ra, rr, rb => rr, rr (jump over rr (and and others except pa, pb, sa, sb) instructions)
-   actually output to STDOUT

# BONUS

## CHECKER

-   Takes a random amount of numbers, and the corresponding stack operations to solve it, and checks if they are correct.
-   throw ERROR if:
    -   Stack A not fully ordered
    -   Stack B not empty at end
    -

# PROBLEM

4

3
1
5

# DESCENDING SOLUTION ( AtoB )

5 is > than 4 -> rotate to BOTTOM!!!
4315

3 is < than 4 -> rotate to TOP!!!
4315

# PROBLEM

4

5
1
3

# ASCENDING SOLUTION ( BtoA )

5 is > than 4 -> rotate to TOP!!!
4513

3 is < than 4 -> rotate to BOTTOM!!!
