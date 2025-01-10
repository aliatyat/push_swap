#include "push_swap.h"

// Function to get the index of the smallest number in the stack
int get_smallest_index(t_stack *a)
{
    int smallest = a->top->value;
    int index = 0;
    int smallest_index = 0;
    t_node *current = a->top->next;

    while (current)
    {
        index++;
        if (current->value < smallest)
        {
            smallest = current->value;
            smallest_index = index;
        }
        current = current->next;
    }

    return smallest_index;
}

// Rotate stack 'a' to bring the smallest element to the top
void rotate_to_top(t_stack *a, int index)
{
    int size = stack_size(a);
    if (index <= size / 2)
    {
        while (index-- > 0)
            ra(a);
    }
    else
    {
        while (index++ < size)
            rra(a);
    }
}

// Sort larger stacks
void sort_large(t_stack *a, t_stack *b)
{
    // Step 1: Move the smallest elements to stack b until stack a has only 3 elements left
    while (stack_size(a) > 3)
    {
        int smallest_index = get_smallest_index(a);
        rotate_to_top(a, smallest_index);
        pb(a, b);  // Push the smallest element to stack b
    }

    // Step 2: Sort the remaining three elements in stack a
    sort_three(a);

    // Step 3: Push all elements back from stack b to stack a
    while (b->top)
    {
        pa(a, b);
        ra(a); // Rotate to maintain sorted order
    }
}