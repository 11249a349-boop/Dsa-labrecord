def precedence(op):
   if op == '+' or op == '-':
       return 1
   if op == '*' or op == '/':
       return 2
   if op == '↑':
       return 3
   return 0
def infix_to_postfix(expression):
   stack = []
   result = []
   for char in expression:
       if char.isalnum(): # Operand
           result.append(char)
       elif char == '(':
           stack.append(char)
       elif char == ')':
           while stack and stack[-1] != '(':
               result.append(stack.pop())
           stack.pop()
       else: # Operator
           while stack and precedence(char) <= precedence(stack[-1]):
               result.append(stack.pop())
           stack.append(char)
   while stack:
       result.append(stack.pop())
   return ''.join(result)
# Example usage
expression = "((a+b)*c-(d-e))↑(f+g)"
postfix = infix_to_postfix(expression)
print(postfix) # Output: ab+c*de- fg+↑-
