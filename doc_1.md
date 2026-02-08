
# Balanced parentheses checker using stack in C

## a. How the data structures are defined
This program checks whether a given mathematical expression has balanced parentheses (including (), {}, and []) using a stack data structure. The program pushes opening brackets onto a stack and pops them when closing brackets appear to verify proper matching.

### Explanation
- `stack[MAX]`: An array of characters used to store opening brackets temporarily.
- `top`: An integer that tracks the index of the top element in the stack.
    `top = -1` → stack is empty, 
    `top = MAX - 1` → stack is full
- Last-In-First-Out (LIFO) principle is followed.

---

## b. Functions implemented

### 1. `push(char v)`
- This function inserts an opening bracket into the stack.
- It first checks whether the stack is full.
- If free space is available, the bracket is added and `top` is increased.
- This function is called whenever an opening bracket is found in the expression.

### 2. `pop()`
- This function removes and returns the top element from the stack.
- It checks whether the stack is empty.
- If the stack is not empty, the top element ( matching opening bracket ) is removed and returned.
- This function is called when a closing bracket is found in the expression.
- Closing bracket is just for checking.

### 3. `balance(char exp[])`
- This is the main logic function to check balanced parentheses.
- It scans the input expression one character at a time using a loop equal to the length of the expression.
- Opening brackets are pushed onto the stack using `push()`.
- When a closing bracket appears, `pop()` removes the top element and checks for a match.
- If a mismatch is found, the function returns `0`, indicating the expression is unbalanced.
- At the end, if the stack is empty, the expression is considered balanced and returns 1.

---

## c. Overview of `main()`
The `main()` function manages the overall execution of the program. It performs the following steps:

- Declares a string expr to store the user’s input.
- Prompts the user to enter a mathematical expression.
- Calls isBalanced(expr) to verify bracket balance:
    Returns 1 → prints Balanced
    Returns 0 → prints Not Balanced
- Ends program with return 0.

Note: This version uses scanf("%s", expr); so the input should not contain spaces.
