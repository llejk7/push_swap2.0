#include "../inc/push_swap.h"
#include <stdio.h>

t_stack *create_stack(int *values, int size) {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    stack->size = 0;
    for (int i = size - 1; i >= 0; i--) {
        t_node *new_node = malloc(sizeof(t_node));
        new_node->value = values[i];
        new_node->next = stack->top;
        stack->top = new_node;
        stack->size++;
    }
    return stack;
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int values_a[] = {3, 2, 1};
    t_stack *stack_a = create_stack(values_a, 3);
    t_stack *stack_b = malloc(sizeof(t_stack));
    stack_b->top = NULL;
    stack_b->size = 0;

    printf("Initial stack_a: ");
    print_stack(stack_a);

    printf("Pushing to stack_b:\n");
    push(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    printf("Swapping stack_a:\n");
    swap(stack_a);
    print_stack(stack_a);

    printf("Rotating stack_a:\n");
    rotate(stack_a);
    print_stack(stack_a);

    printf("Reverse rotating stack_a:\n");
    reverse_rotate(stack_a);
    print_stack(stack_a);

    return 0;
}
