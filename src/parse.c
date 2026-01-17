#include <stdlib.h>
#include "push_swap.h"

// manage input parsing
   // check if values are valie
      // accept only numbers
      // no duplicates are present
   // store values in map structure
      // stack_a gets values
      // stack_b is empty
   
// check count and validity of input arguments
   // validity - only accepts numbers
// run decision tree
   // if argc = 0, do nothing
   // if argc = 1, already sorted, do nothing
   // if argc = 2, simple sort, one op
   // if argc = 3, simple sort, top 2 ops
   // if argc = 4, simple sort, top ?? ops
   // if argc = 5, simple sort, top ?? ops
   // else run sorter

int parse_input(t_map *map, int argc, char **argv)
{
   return (0);
}

int stack_from_list(t_map *map, int argc, char **argv){
   t_node   *stack;
   char     *val_list;
   int      i;

   stack = malloc(sizeof(t_node));
   val_list = argv[0];
   i = 0;
   if (!stack)
      return (1);
   while (argc > 0) {
      stack->value = atoi(argv[i]);
      stack = stack->next;
      argc--;
      i++;
   }
    
    return (0);
}

