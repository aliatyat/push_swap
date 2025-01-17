#include "push_swap.h"

// Bubble sort an array
void bubble_sort(int *values, int size)
{
    int temp;
    int i = 0;

    while (i < size - 1)
    {
        int j = 0;
        while (j < size - i - 1)
        {
            if (values[j] > values[j + 1])
            {
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

// Assign ranks to stack nodes based on sorted values
void assign_ranks(t_stack *a, int *values, int size)
{
    t_node *current;
    int i;

    current = a->top;
    while (current)
    {
        i = 0;
        while (i < size)
        {
            if (current->value == values[i])
            {
                current->value = i;
                break;
            }
            i++;
        }
        current = current->next;
    }
}

// Map values in the stack to their ranks
void map_to_indices(t_stack *a)
{
    int size = stack_size(a);
    int *values = malloc(sizeof(int) * size);
    t_node *current;
    int i = 0;

    if (!values)
        exit(1); // Handle memory allocation error
    current = a->top;
    while (current)
    {
        values[i++] = current->value;
        current = current->next;
    }
    bubble_sort(values, size);
    assign_ranks(a, values, size);
    free(values);
}

// Perform one bitwise pass of the radix sort
void bitwise_pass(t_stack *a, t_stack *b, int bit)
{
    int size = stack_size(a);
    int i = 0;

    while (i < size)
    {
        if (((a->top->value >> bit) & 1) == 0)
            pb(a, b); // Push numbers with 0 in the bit to B
        else
            ra(a); // Rotate numbers with 1 in the bit in A
        i++;
    }
    while (b->top)
        pa(a, b); // Move all elements back from B to A
}

// Sort large stacks using radix sort
void sort_large(t_stack *a, t_stack *b)
{
    int max_bits = 0;
    int size = stack_size(a);
    int i = 0;

    map_to_indices(a);
    while ((size - 1) >> max_bits)
        max_bits++;
    while (i < max_bits)
    {
        bitwise_pass(a, b, i);
        i++;
    }
}
