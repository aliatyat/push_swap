#include "push_swap.h"

// Function to get the smallest number in the stack
int get_smallest(t_stack *a)
{
    if (!a || !a->top)
        return 0; // Or an error code for empty stack

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
    if (stack_size(a) < 3)
        return;

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
        int index = 0;
        t_node *current = a->top;

        // Find the index of the smallest element
        while (current)
        {
            if (current->value == smallest)
                break;
            current = current->next;
            index++;
        }

        // Rotate to bring the smallest element to the top
        if (index <= stack_size(a) / 2)
        {
            while (index-- > 0)
                ra(a);
        }
        else
        {
            index = stack_size(a) - index;
            while (index-- > 0)
                rra(a);
        }

        pb(a, b);  // Push the smallest element to stack B
    }

    sort_three(a);

    while (b->top)
        pa(a, b);  // Push all elements back to stack A
}


#include "push_swap.h"

// Get the index of a value in the stack
int get_index(t_stack *stack, int value)
{
    t_node *current = stack->top;
    int index = 0;

    while (current)
    {
        if (current->value == value)
            return index; // Return the index as soon as we find the value
        current = current->next;
        index++;
    }

    return -1; // Value not found
}


// Function to push elements in chunks from A to B
void push_chunks(t_stack *a, t_stack *b, int chunk_size)
{
    int total_elements = stack_size(a);
    int chunk_start = 0;
    int chunk_end = chunk_size;

    while (chunk_start < total_elements)
    {
        int i = 0;
        while (i < total_elements)
        {
            int value = a->top->value;
            if (value >= chunk_start && value < chunk_end)
            {
                pb(a, b); // Push to stack B if in current chunk
                i = 0; // Restart the scan after each push
            }
            else
            {
                ra(a); // Rotate stack A to find next element
                i++;
            }
        }
        chunk_start += chunk_size;
        chunk_end += chunk_size;
    }
}

int get_max(t_stack *stack)
{
    int max = stack->top->value;
    t_node *current = stack->top->next;

    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

// Function to bring elements back to A from B in sorted order
void push_back_to_a(t_stack *a, t_stack *b)
{
    while (b->top)
    {
        int max = get_max(b); // Get the largest element in B
        while (b->top->value != max)
        {
            if (get_index(b, max) <= stack_size(b) / 2)
                rb(b); // Rotate upwards
            else
                rrb(b); // Rotate downwards
        }
        pa(a, b); // Push back to stack A
    }
}

// Main sorting function for large stacks
void sort_large(t_stack *a, t_stack *b)
{
    int chunk_size = 20; // Adjust chunk size for better optimization
    push_chunks(a, b, chunk_size);
    push_back_to_a(a, b);
}
