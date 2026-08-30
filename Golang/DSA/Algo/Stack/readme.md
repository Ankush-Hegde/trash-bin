1. Expression Evaluation & Parsing (Infix, Postfix, Prefix)

    Compilers use stacks to evaluate mathematical expressions (like 3 + 4 * 2) or convert Infix notation (human readable) into Postfix / Reverse Polish Notation (machine friendly).
    - Why it uses a stack: Operators have precedence. Stacks hold operators until their lower-precedence counterparts or closing parentheses are met.

2. Next Greater Element (Monotonic Stack)
    Finds the first greater element to the right for each element in an array.
    - Why it uses a stack: You maintain a "monotonic decreasing" stack. If the current number is bigger than the index on top of the stack, you've found the "next greater element" for that item and can pop it.

3. Remove middle element in stack<br>(space complexity is $o(n)$)
    - uses two stack 
    - using recuression

4. reverse stack
    - using another stack
    - recuressive

5. Valid Parentheses (Matching Brackets)
    
    Verifies if an expression containing (), {}, and [] is structurally balanced. Open brackets must be closed by the same type in the correct order.
    - Why it uses a stack: Every time you see a closing bracket, it must match the most recent open bracket you encountered.

6. Design a Min Stack ($O(1)$ minimum retrieval)
    
    Designing a standard stack that can return its minimum value at any moment in constant time.
    
    - Why it uses a stack: You track history. By keeping a second "min-tracking" stack, you remember what the minimum was at every single level of the primary stack.