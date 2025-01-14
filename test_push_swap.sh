#!/bin/bash

# Number of tests to run
NUM_TESTS=100
# Maximum number of elements in the stack
MAX_NUM=100

# Function to generate a random list of numbers
generate_random_input() {
    python3 -c "import random; print(' '.join(map(str, random.sample(range(1, $MAX_NUM+1), $MAX_NUM))))"
}

# Loop to run multiple tests
for i in $(seq 1 $NUM_TESTS); do
    # Generate random input
    INPUT=$(generate_random_input)
    
    # Run push_swap with the generated input
    OPERATIONS=$(./push_swap $INPUT)
    
    # Verify the output using checker
    RESULT=$(echo "$OPERATIONS" | ./checker $INPUT)
    
    # Check if the result is OK
    if [ "$RESULT" == "OK" ]; then
        echo "Test $i: Passed"
    else
        echo "Test $i: Failed with input $INPUT"
        echo "Operations: $OPERATIONS"
        echo "Result: $RESULT"
        exit 1
    fi
done

echo "All tests passed!"