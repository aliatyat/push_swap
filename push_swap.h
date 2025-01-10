#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// Node structure for the stack
typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

// Stack structure
typedef struct s_stack
{
    t_node  *top;
} t_stack;

// Function prototypes
t_stack *init_stack(void);
void    free_stack(t_stack *stack);

void    sa(t_stack *a);
void    ra(t_stack *a);
void    rra(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);

int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);
int     validate_input(int argc, char **argv);
int     ft_atoi(const char *str);
int     get_smallest(t_stack *a);

void    sort_three(t_stack *a);
void    sort_five(t_stack *a, t_stack *b);
void    sort_large(t_stack *a, t_stack *b);

#endif
