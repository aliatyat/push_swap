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
int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

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

// Validate the input arguments
int validate_input(int argc, char **argv)
{
    int i = 1;

    while (i < argc)
    {
        int j = 0;

        // Check each character of the argument
        while (argv[i][j])
        {
            if ((argv[i][j] == '-' && j == 0 && argv[i][j + 1] != '\0') ||
                (argv[i][j] >= '0' && argv[i][j] <= '9'))
            {
                j++;
                continue;
            }
            return 0; // Invalid input
        }
        i++;
    }
    return 1; // All inputs are valid
}
