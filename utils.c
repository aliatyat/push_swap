#include "push_swap.h"

int stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;

    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;

    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}

int validate_input(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if ((argv[i][j] == '-' && j == 0 && argv[i][j + 1] != '\0') || (argv[i][j] >= '0' && argv[i][j] <= '9'))
                continue;
            return (0);
        }
    }
    return (1);
}

int ft_atoi(const char *str)
{
    int res = 0;
    int sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
        res = res * 10 + (*str++ - '0');
    return (res * sign);
}
