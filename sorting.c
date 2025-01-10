#include "push_swap.h"

// Function to get the smallest number in the stack
int get_smallest(t_stack *a)
{
    int smallest = a->top->value;
    t_node *current = a->top->next;

    while (current)
    {
        if (current->value < smallest)
            smallest = current->value;
        current = current->next;
    }

    return smallest;
}

// Sort three elements
void sort_three(t_stack *a)
{
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third)
        rra(a);
}

// Sort five elements
void sort_five(t_stack *a, t_stack *b)
{
    while (stack_size(a) > 3)
    {
        int smallest = get_smallest(a);
        while (a->top->value != smallest)
            ra(a);  // Rotate until the smallest element is at the top
        pb(a, b);  // Push the smallest element to stack b
    }
    sort_three(a);
    while (b->top)
        pa(a, b);
}

// Sort larger stacks
void sort_large(t_stack *a, t_stack *b)
{
    // Step 1: Move the smallest elements to stack b until stack a has only 3 elements left
    while (stack_size(a) > 3)
    {
        int smallest = get_smallest(a);
        while (a->top->value != smallest)
            ra(a);  // Rotate until the smallest element is at the top
        pb(a, b);  // Push the smallest element to stack b
    }

    // Step 2: Sort the remaining three elements in stack a
    sort_three(a);

    // Step 3: Push all elements back from stack b to stack a
    while (b->top)
        pa(a, b);
}