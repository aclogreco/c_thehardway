# ex17_stack.py
# run this python3
# This short program implements and uses the Stack data structure.

# The Stack class
class Stack:
    def __init__(self):
        self.__storage = []

    def isEmpty(self):
        return len(self.__storage) == 0
    
    def push(self,p):
        self.__storage.append(p)
    
    def pop(self):
        return self.__storage.pop()


# Now, let's use the Stack class!!!

theStack = Stack()

# First, push some stuff onto the stack
print("\nEnter values to push onto the stack.\n")
for i in range(0, 10):
    value = input("Enter a value: ")
    theStack.push(value)

# Second, pop the stuff off the stack
print("\nPopping the values from the stack.\n")
while not theStack.isEmpty():
    print("Value: %r" % theStack.pop())
