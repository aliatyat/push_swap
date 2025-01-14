import subprocess
import random

def generate_random_input(size):
    return random.sample(range(1, size + 1), size)

def run_push_swap(input_list):
    result = subprocess.run(['./push_swap'] + input_list, capture_output=True, text=True)
    return result.stdout.strip()

def run_checker(input_list, operations):
    process = subprocess.Popen(['./checker'] + input_list, stdin=subprocess.PIPE, stdout=subprocess.PIPE, text=True)
    output, _ = process.communicate(operations)
    return output.strip()

def main():
    num_tests = 100
    max_num = 100

    for i in range(num_tests):
        input_list = list(map(str, generate_random_input(max_num)))
        operations = run_push_swap(input_list)
        result = run_checker(input_list, operations)

        if result != "OK":
            print(f"Test {i + 1}: Failed with input {input_list}")
            print(f"Operations: {operations}")
            print(f"Result: {result}")
            return

        print(f"Test {i + 1}: Passed")

    print("All tests passed!")

if __name__ == "__main__":
    main()