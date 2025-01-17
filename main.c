#include "push_swap.h"

// Initialize stack A and B
void initialize_stacks(t_stack **a, t_stack **b)
{
    *a = init_stack();
    *b = init_stack();
}

// Validate input and initialize stack A
int handle_input(int argc, char **argv, t_stack *a, t_stack *b)
{
    if (argc < 2 || !validate_input(argc, argv))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return (0);
    }
    return (1);
}

// Populate stack A with input values
int populate_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
    int     i;
    t_node  *new_node;

    i = argc - 1;
    while (i > 0)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
        {
            write(2, "Error\n", 6);
            free_stack(a);
            free_stack(b);
            return (0);
        }
        new_node->value = ft_atol(argv[i]);
        new_node->next = a->top;
        a->top = new_node;
        i--;
    }
    return (1);
}

// Choose sorting algorithm based on stack size
void choose_sort(t_stack *a, t_stack *b)
{
    if (is_sorted(a))
        return;
    if (stack_size(a) <= 3)
        sort_three(a);
    else if (stack_size(a) <= 5)
        sort_five(a, b);
    else
        sort_large(a, b);
}

// Free both stacks and exit the program
int cleanup_and_exit(t_stack *a, t_stack *b, int code)
{
    free_stack(a);
    free_stack(b);
    return (code);
}

// Main function
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    initialize_stacks(&a, &b);
    if (!handle_input(argc, argv, a, b))
        return (1);
    if (!populate_stack(a, b, argc, argv))
        return (1);
    choose_sort(a, b);
    return (cleanup_and_exit(a, b, 0));
}
