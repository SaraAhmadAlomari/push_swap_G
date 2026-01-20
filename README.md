*This activity has been created as part of the 42 curriculum by saalomar,gmagable*

# Push_swap

## Description
Push_swap is a sorting algorithm project where the goal is to sort a stack of integers with the minimum number of operations using only a predefined set of operations.
The project emphasizes algorithm optimization, stack manipulation, and efficient handling of data structures. The program must output the list of operations to sort the stack and can provide a benchmarking mode.
## Instructions
- **sa**: *swap a* - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb**: *swap b* - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss**: sa and sb at the same time.
- **pa**: *push a* - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb**: *push b* - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- **ra**: *rotate a* - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb**: *rotate b* - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr**: ra and rb at the same time.
- **rra**: *reverse rotate a* - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb**: *reverse rotate b* - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr**: rra and rrb at the same time.
### Compilation
```bash
make
```
## Execution
## Simple run with numbers as arguments
```bash
./push_swap 3 2 1
```

## Check if the operations correctly sort the stack
```bash
./push_swap 3 2 1 | ./checker_os 3 2 1
```

```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_os $ARG
```

## Run with a large inputs
```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l
```

## Run with arguments
```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_os $(cat args.txt)
```
## Run with bench output
```bash
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_os $ARG
```
## Algorithm Choice
For this project, several sorting strategies were considered to optimize the number of operations required by the push_swap program. The chosen algorithms and justifications are as follows:

- **Simple Sort (2-5 elements):** A tailored series of swap (`sa`, `sb`) and rotate (`ra`, `rra`) operations are used to sort very small stacks efficiently.
- **Medium Sort (up to ~100 elements):** A chunk-based approach is applied, where the stack is divided into smaller ranges ("chunks"). Elements are pushed to the auxiliary stack `b` and then reintegrated into stack `a` in order. This reduces the total number of moves.
- **Complex Sort (large stacks up to 500 elements):** sorts numbers using their binary representation. It repeatedly distributes elements between stack A and stack B according to the value of each bit, starting from the least significant bit to the most significant bit. After processing each bit, the elements are collected back into stack A. This method efficiently sorts large datasets in ascending order with a time complexity of O(n log n).

The selection of each algorithm is based on the disorder of the stack:
For low disorder (< 0.2), it uses a simple algorithm (O(n));
For medium disorder (0.2 – 0.5), it uses a medium algorithm (chunk) with O(n√n) complexity;
For high disorder (≥ 0.5), it switches to radix sort (O(n log n));
The benchmarking feature (`--bench`) was used to validate the efficiency of these strategies in practice.

## Resources
- [42 Push_swap subject](https://github.com/topics/pushswap-42)
- Tutorials and algorithm references:
  - [Sorting algorithms overview](https://en.wikipedia.org/wiki/Sorting_algorithm)
  - [Stack data structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

### AI Assistance
AI was used for:
- Clarifying algorithmic approaches.
- Suggesting efficient ways to implement `ft_printf` with `stderr` support.
- Debugging and explaining buffer/pipe behavior.
