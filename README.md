*This project has been created as part of the 42 curriculum by aalvarad.*

---

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using the smallest possible number of operations, with only two stacks (`a` and `b`) and a limited set of instructions.

### Available operations

| Operation | Description |
|-----------|-------------|
| `sa` / `sb` | Swap the two top elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push the top element of b onto a / a onto b |
| `ra` / `rb` | Rotate stack a / b (top goes to bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b (bottom goes to top) |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm used — Radix Sort (LSD binary)

For inputs larger than 5 elements, the project uses a **binary LSD radix sort** (Least Significant Bit first).

**How it works:**
1. **Indexing** — each node is assigned a rank (`index`) from `0` (smallest) to `n-1` (largest). This step is O(n²).
2. **Sorting** — the stack is sorted bit by bit, from the least significant to the most significant. At each pass:
   - if the current bit is `0` → push to stack b (`pb`)
   - if the current bit is `1` → rotate to the bottom of stack a (`ra`)
   - once all elements are processed, push everything back from b to a (`pa`)

After `log₂(n)` passes, stack a is fully sorted.

**Complexity:** O(n × log₂n) stack operations — for 500 elements this produces roughly 4 500 operations.

**Small inputs** are handled with dedicated functions:
- 2 elements → at most 1 swap
- 3 elements → at most 2 operations (5 cases handled manually)
- 4–5 elements → push the smallest to b, sort the rest, push back

### Project structure

```
push_swap/
├── includes/
│   └── push_swap.h          # All prototypes and the t_node struct
├── src/
│   ├── main.c               # Entry point
│   ├── parse_args.c         # Tokenizes argv (handles both "1 2 3" and 1 2 3)
│   ├── parse_numbers.c      # Validates tokens, builds int array
│   ├── parse_utils.c        # is_valid_number_str, fits_in_int
│   ├── error.c              # error_exit: writes "Error\n" to stderr and exits
│   ├── free.c               # free_tokens
│   ├── stack_utilis.c       # create_node, stack_add_back/front, stack_size, stack_last
│   ├── stack_ops.c          # stack_clear, build_stack
│   ├── ops_swap.c           # sa, sb, ss (+ silent variants)
│   ├── ops_push.c           # pa, pb
│   ├── ops_rotate.c         # ra, rb, rr (+ silent variants)
│   ├── ops_rrotate.c        # rra, rrb, rrr (+ silent variants)
│   ├── small_sort.c         # sort_two, sort_three, sort_five, find_min_pos, is_sorted
│   └── radix_sort.c         # indexer, get_max_bits, radix_sort, sort_stack, bring_min_to_top
└── libft/                   # Personal C library
```

> **Note:** The bonus part (checker program) was not implemented due to time constraints.

---

## Instructions

### Compilation

```bash
make
```

This builds the `push_swap` binary. Other rules:

```bash
make clean    # remove object files
make fclean   # remove object files and binary
make re       # fclean + all
```

### Execution

```bash
./push_swap 3 2 1 5 4
```

Or with a quoted string:

```bash
./push_swap "3 2 1 5 4"
```

The program prints the list of operations to stdout, one per line.

### Testing

Count the number of operations produced:

```bash
./push_swap 3 2 1 5 4 | wc -l
```

### Memory leaks

**macOS:**

```bash
leaks --atExit -- ./push_swap 3 2 1 5 4
```

**Linux (Valgrind):**

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1 5 4
```

The key line to look for:

```
==PID== LEAK SUMMARY:
==PID==    definitely lost: 0 bytes in 0 blocks  
```

---

## Resources

### Documentation & references

- [CS50 Harvard — Data Structures lectures](https://cs50.harvard.edu/x/) — used to build a solid understanding of linked lists, stacks, and algorithm complexity before starting the project
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — reference for the LSD binary radix sort principle
- [42 push_swap subject](https://cdn.intra.42.fr/pdf/pdf/199556/en.subject.pdf) — official project specification

### AI usage

- **Claude (Anthropic)** was used as a personal tutor throughout the project: explaining concepts (linked lists, sorting algorithms, bitwise operations), reviewing code logic, enforcing the 42 norm (norminette), and debugging. It did not write the core algorithm — its role was to explain, review, and correct format.
- **NotebookLM (Google)** was used to generate study sheets from course materials and documentation, in order to better understand and retain the concepts covered in the project.
