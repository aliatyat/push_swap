#include "push_swap.h"

// Initialize a new stack
t_stack *init_stack(void)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return NULL; // Return NULL if memory allocation fails
    stack->top = NULL;
    return stack;
}

// Free the memory allocated for the stack
void free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;

    while (current)
    {
        next = current->next; // Save the next node
        free(current);        // Free the current node
        current = next;       // Move to the next node
    }
    free(stack); // Free the stack structure itself
}

// Convert a string to an integer
long ft_atol(const char *str)
{
    long res = 0;
    long sign = 1;

    // Handle optional sign
    if (*str == '-')
    {
        sign = -1;
        str++;
    }

    // Convert the string to an integer
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return res * sign;
}

// Check if the stack is sorted
int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0; // Stack is not sorted
        current = current->next;
    }
    return 1; // Stack is sorted
}

// Get the size of the stack
int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;

    while (current)
    {
        size++;          // Increment the size for each node
        current = current->next; // Move to the next node
    }
    return size;
}

#include <limits.h>

int is_valid_number(const char *str)
{
    int j = 0;

    while (str[j])
    {
        if (!(str[j] == '-' && j == 0 && str[j + 1] != '\0') 
            && !(str[j] >= '0' && str[j] <= '9'))
            return (0);
        j++;
    }
    if (INT_MAX < ft_atol(str))
        return (0);
    return (1);
}

int has_duplicates(int argc, char **argv)
{
    int i = 1;
    int j;

    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_atol(argv[i]) == ft_atol(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int validate_input(int argc, char **argv)
{
    int i = 1;

    while (i < argc)
    {
        if (!is_valid_number(argv[i]))
            return (0);
        i++;
    }
    if (has_duplicates(argc, argv))
        return (0);
    return (1);
}
