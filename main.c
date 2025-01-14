#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a = init_stack();
    t_stack *b = init_stack();

    if (argc < 2 || !validate_input(argc, argv))
    {
        write(2, "Error\n", 6);
        free_stack(a);
        free_stack(b);
        return 1;
    }

    int i = argc - 1;
    while (i > 0)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
            return (free_stack(a), free_stack(b), write(2, "Error\n", 6), 1);
        new_node->value = ft_atoi(argv[i]);
        new_node->next = a->top;
        a->top = new_node;
        i--;
    }

    if (is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        return 0;
    }

    // Choose sorting method based on size
    int size = stack_size(a);
    if (size <= 3)
        sort_three(a);
    else if (size <= 5)
        sort_five(a, b);
    else
       sort_large(a, b);

    free_stack(a);
    free_stack(b);
    return 0;
}
