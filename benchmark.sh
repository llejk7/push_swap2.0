#!/bin/bash

# Number of tests
TEST_COUNT=10

# Number of elements
NUMBERS=(5 100 500)

# Loop through sizes
for n in "${NUMBERS[@]}"; do
    echo "Benchmarking $n numbers:"
    total_ops=0
    for ((i = 0; i < TEST_COUNT; i++)); do
        # Generate random input
        ARG=$(seq -$n $n | shuf | head -$n | tr '\n' ' ')
        
        # Run push_swap and count operations
        ops=$(./push_swap $ARG | wc -l)
        
        # Verify correctness
        result=$(./push_swap $ARG | ./checker $ARG)
        
        # Accumulate operations and print results
        total_ops=$((total_ops + ops))
        echo "Test $((i + 1)): $ops operations ($result)"
    done

    # Calculate and print average operations
    avg_ops=$((total_ops / TEST_COUNT))
    echo "Average operations for $n numbers: $avg_ops"
    echo "--------------------------------------"
done
