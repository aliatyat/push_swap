#include "push_swap.h"

// Swap the top two elements of stack A
void sa(t_stack *a)
{
    if (a->top && a->top->next)
    {
        int tmp = a->top->value;
        a->top->value = a->top->next->value;
        a->top->next->value = tmp;
        write(1, "sa\n", 3);
    }
}

// Rotate stack A upwards
void ra(t_stack *a)
{
    if (!a->top || !a->top->next)
        return;

    t_node *first = a->top;
    t_node *last = a->top;

    while (last->next)
        last = last->next;

    a->top = first->next;
    first->next = NULL;
    last->next = first;

    write(1, "ra\n", 3);
}

// Reverse rotate stack A downwards
void rra(t_stack *a)
{
    if (!a->top || !a->top->next)
        return;

    t_node *prev = NULL;
    t_node *last = a->top;

    while (last->next)
    {
        prev = last;
        last = last->next;
    }

    prev->next = NULL;
    last->next = a->top;
    a->top = last;

    write(1, "rra\n", 4);
}

// Push the top of stack A to stack B
void pb(t_stack *a, t_stack *b)
{
    if (!a->top)
        return;

    t_node *tmp = a->top;
    a->top = a->top->next;

    tmp->next = b->top;
    b->top = tmp;

    write(1, "pb\n", 3);
}

// Push the top of stack B to stack A
void pa(t_stack *a, t_stack *b)
{
    if (!b->top)
        return;

    t_node *tmp = b->top;
    b->top = b->top->next;

    tmp->next = a->top;
    a->top = tmp;

    write(1, "pa\n", 3);
}
