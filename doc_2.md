# Program 2 – Infix to Postfix Conversion 

# 1. Data Structure Definition
This program uses two stacks implemented as arrays with corresponding `top` variables to track the current position:
- Operator Stack (`opStack`) 
  - Stores operators (`+`, `-`, `*`, `/`, `^`) and parentheses during the conversion from infix to postfix notation.  
  - Uses a character array `opStack` and an integer `top` to indicate the current top position.

- Value Stack (`valStack`) 
  - Used during evaluation of the postfix expression to hold integer operands and intermediate results.  
  - Uses an integer array `valStack` and an integer `valTop` to track the top element.

# 2. Description of Functions Implemented

1. `void push(char op)`
   - Pushes a character (operator or parenthesis) onto the operator stack.  
   - Checks if the stack is full before pushing and prints an error message if so.
2. `char pop()`
   - Pops and returns the top character from the operator stack.  
   - Returns `-1` if the stack is empty.

3. `int priority(char op)`  
   - Returns the precedence value of an operator.  
   - `+` and `-` have precedence 1; `*` and `/` have precedence 2; `^` has precedence 3; other characters return 0.

4. `void toPostfix(char infix[], char postfix[])`
   - Converts an infix expression (string) to postfix notation using the operator stack.  
   - Operands (alphanumeric characters) are added directly to the postfix output.  
   - Handles parentheses by pushing `'('` and popping operators until `'('` when a `')'` is encountered.  
   - Pops operators from the stack while the incoming operator has lower or equal precedence than the operator at the top of the stack.  
   - Stores the postfix expression in the `postfix` array.

5. `int evalPostfix(char postfix[])`
   - Evaluates a postfix expression by scanning through it and using the value stack to compute the result.  
   - Pushes digits as integers onto the stack.  
   - Pops two operands for each operator, applies the operation, and pushes the result back on the stack.  
   - Supports addition, subtraction, multiplication, division, and exponentiation.  
   - Returns the final computed integer result.

# 3.Organization of `main()`
- Declares arrays to hold the infix input and postfix output expressions.
- Prompts the user to enter an infix expression (without spaces).  
- Calls `toPostfix()` to convert the infix expression to postfix.  
- Prints the postfix expression.  
- Calls `evalPostfix()` to evaluate the postfix expression and prints the result.  
- Returns 0 to indicate successful execution.

## 4. Sample Output

Enter expression: 5+63-2^2
Postfix: 56322^-+
Result: 21
