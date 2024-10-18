# monty
## Resources
[How do I use extern to share variables between source files in C?](https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files)
[Stacks and Queues in C](https://data-flair.training/blogs/stacks-and-queues-in-c/)
[Stack operations](https://www.digitalocean.com/community/tutorials/stack-in-c)
[Queue operations](https://www.edureka.co/blog/queue-in-c/)
## Learning Objectives

What is a stack, and when to use it
### What is a Stack?
A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle. This means that the last element added to the stack is the first one to be removed. Imagine stacking plates: you place one plate on top of another, and to remove a plate, you have to take off the top one first.

- Push operation: Adds an element to the top of the stack.
- Pop operation: Removes and returns the top element of the stack.
- Peek operation: Returns the top element without removing it.
A stack can be implemented in various ways in C, including using arrays or linked lists.

#### Stack Implementation in C (Using an Array):
```c
#include <stdio.h>
#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Push an element onto the stack
int push(Stack* s, int value) {
    if (s->top == MAX - 1) {
        return -1; // Stack overflow
    }
    s->arr[++(s->top)] = value;
    return 0;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (s->top == -1) {
        return -1; // Stack underflow
    }
    return s->arr[(s->top)--];
}

// Peek at the top element
int peek(Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 10);
    push(&s, 20);
    printf("Top element is %d\n", peek(&s)); // 20
    
    printf("Popped element is %d\n", pop(&s)); // 20
    printf("Top element is now %d\n", peek(&s)); // 10
    
    return 0;
}
```
#### When to Use a Stack
Stacks are commonly used when the operations on the data follow a Last In, First Out order. Here are some scenarios where stacks are particularly useful:

**1. Function Call Management (Recursion)**
The system call stack keeps track of active function calls. When a function is called, its details (parameters, local variables, return address) are pushed onto the stack. When the function completes, its data is popped from the stack.
Example: Recursive algorithms rely on stacks for maintaining the current state of each recursive call.
**2. Backtracking**
When solving problems like the **N-Queens problem, maze traversal**, or other puzzles, a stack can be used to backtrack.
Example: As you try out solutions, you push them onto the stack. If a solution doesn’t work, you backtrack by popping it off the stack.
**3. Expression Evaluation and Parsing**
Stacks are used to evaluate arithmetic expressions (e.g., converting infix expressions to postfix or evaluating postfix expressions).
Example: During the parsing of an arithmetic expression, operators and operands are pushed onto the stack and evaluated in a structured order.
**4. Undo Mechanism in Applications**
Many software applications (such as text editors, photo editing software, etc.) implement an **undo** feature using stacks. The actions are pushed onto the stack as they are performed, and the undo function pops the last action to revert the change.
Example: In a text editor, if you make several changes, you can undo them in reverse order using a stack.
**5. Balanced Parentheses and Delimiter Matching**
Stacks are useful for checking if parentheses (or other delimiters) in an expression are properly balanced.
Example: When parsing an expression like ((a + b) * (c + d)), a stack can be used to ensure each opening parenthesis has a corresponding closing parenthesis.
**6. Browser History or Navigation**
A web browser’s back and forward functionality can be implemented using two stacks: one for the history of visited pages (back stack) and one for pages that can be visited again (forward stack).
Example: When you navigate back to a previous page, the current page is pushed onto the forward stack.
#### Advantages of Using a Stack
- Simple and efficient for LIFO operations.
- Easily implemented using arrays or linked lists.
- Useful in scenarios where you need to reverse the order of operations or navigate back and forth between elements.
#### Disadvantages of Using a Stack
- Limited by size: Stacks using arrays have a fixed size, which can lead to stack overflow if the stack exceeds its capacity.
- Not suitable for accessing elements randomly or managing large datasets with non-LIFO access patterns.
In conclusion, a stack is ideal when you need to manage data in a LIFO order, and it's widely used in algorithms, programming languages, and software applications for function call management, backtracking, parsing, and more.
</details>
<details>
<summary>What is a queue, and when to use it</summary>

### What is a Queue?
A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. In a queue, the first element added is the first one to be removed, similar to how people stand in line: the first person to join the line is the first to be served.

- Enqueue operation: Adds an element to the back of the queue.
- Dequeue operation: Removes and returns the front element from the queue.
- Peek operation: Returns the front element without removing it.
A queue can be implemented using arrays or linked lists in C, and it has a wide range of applications in computing.

#### Queue Implementation in C (Using an Array):
```c
#include <stdio.h>
#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Enqueue an element
int enqueue(Queue* q, int value) {
    if (isFull(q)) {
        return -1; // Queue overflow
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = value;
    return 0;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1; // Queue underflow
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        // Reset the queue after the last element is dequeued
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

// Peek at the front element
int peek(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->arr[q->front];
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front element is %d\n", peek(&q)); // 10

    printf("Dequeued element is %d\n", dequeue(&q)); // 10
    printf("Front element is now %d\n", peek(&q)); // 20

    return 0;
}
```
#### When to Use a Queue
Queues are useful when data needs to be processed in the order of arrival (FIFO), where the first element entered is the first one to be processed. Below are some scenarios where queues are commonly used:

**1. Task Scheduling (Operating System Queues)**
-CPU scheduling uses queues to manage processes waiting for execution. When multiple processes are waiting for CPU time, they are placed in a queue. The process that has been waiting the longest gets executed first.
Example: Round-robin scheduling uses a queue to cycle through processes waiting for the CPU.
**2. Breadth-First Search (BFS) in Graphs**
In graph traversal algorithms like BFS, a queue is used to explore nodes level by level. Starting from a node, the algorithm enqueues all its adjacent nodes and processes them in the order they were added.
Example: BFS is useful in finding the shortest path in an unweighted graph.
**3. Producer-Consumer Problem**
A queue is often used to manage communication between producer and consumer processes in multi-threaded applications. The producer adds tasks to the queue, and the consumer processes and removes them in the order they arrived.
Example: In web servers, incoming HTTP requests are stored in a queue, and worker threads process them one by one.
**4. Printing Queues**
A printer processes print jobs in the order they are received. Each print job is placed in a queue, and the printer prints them in the same sequence.
Example: In a shared office printer, jobs are queued up, and each is printed in the order it was submitted.
**5. IO Buffers**
When reading or writing data from devices (like hard drives, networks, etc.), data is stored in a queue (buffer) until it can be processed.
Example: Network packets arriving at a network interface are stored in a queue before being processed by the network stack.
**6. Handling Asynchronous Data (Event Queues)**
In event-driven programming, events are often queued for handling by an event handler. The events are processed in the order they were added to the queue.
Example: GUI frameworks use event queues to manage user inputs like mouse clicks or keyboard presses.
**7. Customer Service Systems (Help Desk)**
In customer service systems, customers are placed in a queue, and agents serve them in the order they arrived.
Example: A call center where incoming calls are handled on a first-come, first-served basis.
#### Advantages of Using a Queue
Ideal for FIFO (First In, First Out) scenarios, ensuring fair processing order.
Efficient for managing tasks where order is critical, such as task scheduling or processing.
Can be easily implemented using arrays or linked lists.
#### Disadvantages of Using a Queue
- Fixed size when implemented using arrays, leading to queue overflow if the queue becomes full.
- Queue underflow can occur if trying to dequeue from an empty queue.
- Limited random access: Queues only allow access to the front and rear elements, not to arbitrary elements in the middle.
#### Types of Queues
1. Simple Queue (FIFO): Basic queue where elements are added at the rear and removed from the front.
2. Circular Queue: A variation of a simple queue where the last position is connected back to the first position, allowing better memory utilization.
3. Priority Queue: Each element has a priority, and the element with the highest priority is dequeued first, regardless of when it was added.
4. Deque (Double-ended Queue): Allows elements to be added or removed from both the front and rear ends.

</details>
<details>
<summary>What are the common implementations of stacks and queues</summary>

Stacks and queues are fundamental data structures, and they can be implemented in various ways. Here's an overview of common implementations for both:

### 1. Stack Implementations:
A stack operates on the principle of **LIFO** (Last In, First Out), meaning the last element added to the stack is the first one to be removed.

#### 1.1. Array-based Stack:

**- Description:** The stack is implemented using a fixed-size array.
**- Pros:** Simple and efficient for small, fixed-sized data.
**- Cons:** The size of the stack is limited to the size of the array, and resizing the array (if needed) can be costly.
**- Operations:** ``push()`` to add an element to the top, ``pop()`` to remove the top element, and ``peek()`` to get the top element.

Example
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an element onto the stack
void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

// Pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// Peek at the top element of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);
    printf("Top of stack: %d\n", peek(&s));  // Output: 20
    printf("Popped: %d\n", pop(&s));  // Output: 20
    printf("Popped: %d\n", pop(&s));  // Output: 10
    return 0;
}
```
#### 1.2. Linked List-based Stack:
**- Description:** The stack is implemented using a singly linked list where each node contains a value and a reference to the next node.
**- Pros:** Dynamically sized, no limit on the stack size as long as memory is available.
**- Cons:** Slightly more overhead than an array due to the use of pointers.
**- Operations:** Similar to the array-based stack, but nodes are added/removed at the head of the list.

Example
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push a node to the stack
void push(Node** top, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

// Pop a node from the stack
int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

// Peek at the top element of the stack
int peek(Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

int main() {
    Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    printf("Top of stack: %d\n", peek(stack));  // Output: 20
    printf("Popped: %d\n", pop(&stack));  // Output: 20
    printf("Popped: %d\n", pop(&stack));  // Output: 10
    return 0;
}
```
### 2. Queue Implementations:
A queue operates on the principle of **FIFO** (First In, First Out), meaning the first element added to the queue is the first one to be removed.

#### 2.1. Array-based Queue:
**- Description:** The queue is implemented using an array with two pointers, front and rear, to track the front and rear of the queue.
**- Pros:** Simple and efficient for fixed-sized data.
**- Cons:** The array can fill up, requiring resizing or circular queue techniques to prevent wasted space.
**- Operations:** ``enqueue()`` to add an element to the rear, ``dequeue()`` to remove an element from the front, and ``peek()`` to see the front element.

Example
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Enqueue an element into the queue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = value;
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->data[q->front++];
}

// Peek at the front element of the queue
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front of queue: %d\n", peek(&q));  // Output: 10
    printf("Dequeued: %d\n", dequeue(&q));  // Output: 10
    printf("Dequeued: %d\n", dequeue(&q));  // Output: 20
    return 0;
}
```
#### 2.2 Linked List-based Queue:
**- Description:** A queue is implemented using a singly linked list where each node contains a value and a reference to the next node. A ``front`` pointer points to the first node, and a ``rear`` - pointer points to the last node.
**- Pros:** Dynamically sized, and no need to manage resizing.
**- Cons:** More memory overhead due to pointers.
**- Operations:** Same as the array-based queue.
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Initialize the queue
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

// Enqueue an element into the queue
void enqueue(Queue* q, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue an element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

// Peek at the front element of the queue
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

int main() {
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("Front of queue: %d\n", peek(&q));  // Output: 10
    printf("Dequeued: %d\n", dequeue(&q));  // Output: 10
    printf("Dequeued: %d\n", dequeue(&q));  // Output: 20
    return 0;
}

```

</details>
<details>
<summary>What is the proper way to use global variables</summary>

### Global Variables in C:
Using global variables in C or any other programming language should be done cautiously, as they can lead to code that is hard to debug, maintain, and reuse. However, if used properly in controlled situations, global variables can be helpful. Here are some guidelines and best practices for using global variables:

#### 1. Limit Scope of Global Variables
Avoid making variables global unless necessary. The more global variables, the harder it becomes to trace code execution. Instead, try to:
**- Use local variables:** Keep variables local to functions or blocks wherever possible.
**- Limit global variables to file scope:** In C, you can use static to make a global variable accessible only within the file it is declared in.
Example (file-scoped global variable):
```c
// file1.c
static int counter = 0;  // Only accessible in file1.c
```
#### 2. Use Global Variables for Truly Global State
If the state needs to be shared across multiple functions or files, global variables can be used. However, they should represent entities that are inherently global to the entire application, like configuration settings or hardware states.

#### 3. Proper Naming Conventions
Global variables should be clearly named to avoid naming conflicts and should follow specific conventions that differentiate them from local variables. A common convention is to use a prefix or suffix:
Example:
```c
int g_configValue = 0;  // "g_" prefix indicates global scope
```
#### 4. Encapsulate Global Variables in Functions
Instead of directly accessing global variables, it’s better to encapsulate them inside getter and setter functions. This provides better control and future extensibility.
Example:
```c
int g_configValue = 0;  // Global variable

int getConfigValue() {
    return g_configValue;
}

void setConfigValue(int value) {
    g_configValue = value;
}
```
#### 5. Use ``extern`` for Global Variables Across Files
If you need to share a global variable across multiple files, declare the variable in one file and use the ``extern`` keyword in other files to access it.
Example:
```c
// file1.c
int g_count = 0;  // Definition of the global variable

// file2.c
extern int g_count;  // Declaration of the same variable
void incrementCount() {
    g_count++;
}
```
#### Example of Proper Usage of a Global Variable
```c
#include <stdio.h>

// Global variable declaration
int g_appConfig = 0;  // Prefix 'g_' to denote it's global

// Getter and Setter functions for encapsulation
int getAppConfig() {
    return g_appConfig;
}

void setAppConfig(int configValue) {
    g_appConfig = configValue;
}

// Example function that uses the global variable
void updateConfig() {
    int config = getAppConfig();
    config += 1;  // Modify the global variable indirectly
    setAppConfig(config);
}

int main() {
    printf("Initial config: %d\n", getAppConfig());
    setAppConfig(10);
    printf("Updated config: %d\n", getAppConfig());
    updateConfig();
    printf("After increment: %d\n", getAppConfig());
    return 0;
}
```
</details>

## More Info
### Data structures
Please use the following data structures for this project. Don’t forget to include them in your header file.
```c
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```
### Compilation & Output
Your code will be compiled this way: ``$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty``
- Any output must be printed on ``stdout``
- Any error message must be printed on ``stderr``
    + Here is a link to a [GitHub repository](https://github.com/ku1ik/stderred) that could help you making sure your errors are printed on stderr

### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

#### Monty byte code files
Files containing Monty byte codes usually have the ``.m`` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```bash
$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
$
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```
#### The monty program
- Usage: ``monty file``
    + where ``file`` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message ``USAGE: monty file``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- If, for any reason, it’s not possible to open the file, print the error message ``Error: Can't open file <file>``, followed by a new line, and exit with the status ``EXIT_FAILURE``
    + where ``<file>`` is the name of the file
- If the file contains an invalid instruction, print the error message ``L<line_number>: unknown instruction <opcode>``, followed by a new line, and exit with the status ``EXIT_FAILURE``
    + where is the line number where the instruction appears.
    + Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
    + it executed properly every line of the file
    + it finds an error in the file
    + an error occured
- If you can’t malloc anymore, print the error message ``Error: malloc failed``, followed by a new line, and exit with status ``EXIT_FAILURE``.
- You have to use ``malloc`` and ``free`` and are not allowed to use any other function from man malloc (realloc, calloc, …)
## Tasks
### 0. push, pall
Implement the ``push`` and ``pall`` opcodes.
**The push opcode**
The opcode ``push`` pushes an element to the stack.
- Usage: ``push <int>``
    + where ``<int>`` is an integer
- if ``<int>`` is not an integer or if there is no argument given to push, print the error message ``L<line_number>: usage: push integer``, followed by a new line, and exit with the status ``EXIT_FAILURE``
    + where is the line number in the file
- You won’t have to deal with overflows. Use the ``atoi`` function
**The pall opcode**
The opcode ``pall`` prints all the values on the stack, starting from the top of the stack.
- Usage ``pall``
- Format: see example
- If the stack is empty, don’t print anything
```bash
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1
```
### 1. pint
**The pint opcode**
The opcode ``pint`` prints the value at the top of the stack, followed by a new line.
- Usage: ``pint``
- If the stack is empty, print the error message ``L<line_number>: can't pint``, stack empty, followed by a new line, and exit with the status ``EXIT_FAILURE``
```bash
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m 
1
2
3
```
### 2. pop
**The pop opcode**
The opcode ``pop`` removes the top element of the stack.
- Usage: ``pop``
- If the stack is empty, print the error message ``L<line_number>: can't pop an empty stack``, followed by a new line, and exit with the status ``EXIT_FAILURE``
```bash
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m 
3
2
1
2
1
1
```
### 3. swap
**The swap opcode**
The opcode ``swap`` swaps the top two elements of the stack.
- Usage: ``swap``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't swap, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
```bash
$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m 
3
2
1
2
3
1
```
### 4. add
**The add opcode**
The opcode ``add`` adds the top two elements of the stack.
- Usage: ``add``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't add, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    + The top element of the stack contains the result
    + The stack is one element shorter
```bash
$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall

$ ./monty bytecodes/12.m 
3
2
1
5
1
```
### 5. nop
**The nop opcode**
The opcode nop doesn’t do anything.
Usage: ``nop``

### 6. sub
**The sub opcode**
The opcode ``sub`` subtracts the top element of the stack from the second top element of the stack.
- Usage: ``sub``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't sub, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    + The top element of the stack contains the result
    + The stack is one element shorter
```bash
$ cat bytecodes/19.m 
push 1
push 2
push 10
push 3
sub
pall
$ ./monty bytecodes/19.m 
7
2
1
```
### 7. div
**The div opcode**
The opcode ``div`` divides the second top element of the stack by the top element of the stack.
- Usage: ``div``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't div, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    + The top element of the stack contains the result
    + The stack is one element shorter
- If the top element of the stack is ``0``, print the error message ``L<line_number>: division by zero``, followed by a new line, and exit with the status ``EXIT_FAILURE``

### 8. mul
**The mul opcode**
The opcode ``mul`` multiplies the second top element of the stack with the top element of the stack.

- Usage: ``mul``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't mul, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    + The top element of the stack contains the result
    + The stack is one element shorter

### 9. mod
**The mod opcode**
The opcode ``mod`` computes the rest of the division of the second top element of the stack by the top element of the stack.
- Usage: ``mod``
- If the stack contains less than two elements, print the error message ``L<line_number>: can't mod, stack too short``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
    + The top element of the stack contains the result
    + The stack is one element shorter
- If the top element of the stack is ``0``, print the error message ``L<line_number>: division by zero``, followed by a new line, and exit with the status ``EXIT_FAILURE``

### 10. comments
Every good language comes with the capability of commenting. When the first non-space character of a line is ``#``, treat this line as a comment (don’t do anything).

### 11. pchar
**The pchar opcode**
The opcode ``pchar`` prints the char at the top of the stack, followed by a new line.
- Usage: ``pchar``
- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- If the value is not in the ascii table (man ascii) print the error message ``L<line_number>: can't pchar, value out of range``, followed by a new line, and exit with the status ``EXIT_FAILURE``
- If the stack is empty, print the error message ``L<line_number>: can't pchar, stack empty``, followed by a new line, and exit with the status ``EXIT_FAILURE``
```bash
$ cat bytecodes/28.m 
push 72
pchar
$ ./monty bytecodes/28.m 
H
```
### 12. pstr
**The pstr opcode**
The opcode ``pstr`` prints the string starting at the top of the stack, followed by a new line.
- Usage: ``pstr``
- The integer stored in each element of the stack is treated as the ascii value of the character to be printed
- The string stops when either:
    + the stack is over
    + the value of the element is 0
    + the value of the element is not in the ascii table
- If the stack is empty, print only a new line
```bash
$ cat bytecodes/31.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
$ ./monty bytecodes/31.m 
School
```
### 13. rotl
**The rotl opcode**
The opcode ``rotl`` rotates the stack to the top.
- Usage: ``rotl``
- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- ``rotl`` never fails
```bash
$ cat bytecodes/35.m 
push 1
push 2
push 3
push 4
push 5
push 6
push 7
push 8
push 9
push 0
pall
rotl
pall
$ ./monty bytecodes/35.m 
0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0
```
### 14. rotr
**The rotr opcode**
The opcode ``rotr`` rotates the stack to the bottom.
- Usage: ``rotr``
- The last element of the stack becomes the top element of the stack
- ``rotr`` never fails

### 15. stack, queue
**The stack opcode**
The opcode ``stack`` sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- Usage: ``stack``
**The queue opcode**
The opcode ``queue`` sets the format of the data to a queue (FIFO).
- Usage: ``queue``

When switching mode:
- The top of the stack becomes the front of the queue
- The front of the queue becomes the top of the stack
```bash
$ cat bytecodes/47.m
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
$ ./monty bytecodes/47.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
```
### 16. Brainf*ck
Write a Brainf*ck script that prints ``School``, followed by a new line.
- All your Brainf*ck files should be stored inside the ``bf`` sub directory
- You can install the bf interpreter to test your code: ``sudo apt-get install bf``
- Read: [Brainf*ck](https://en.wikipedia.org/wiki/Brainfuck)
```bash
julien@ubuntu:~/monty/bf$ bf 1000-school.bf 
School
```
### 17. Add two digits
Add two digits given by the user.
- Read the two digits from stdin, add them, and print the result
- The total of the two digits with be one digit-long (<10)
```bash
julien@ubuntu:~/monty/bf$ bf ./1001-add.bf
81
9julien@ubuntu:~/monty/bf$
```
### 18. Multiplication
Multiply two digits given by the user.
- Read the two digits from stdin, multiply them, and print the result
- The result of the multiplication will be one digit-long (<10)
```bash
julien@ubuntu:~/monty/bf$ bf 1002-mul.bf
24
8julien@ubuntu:~/monty/bf$
```
### 19. Multiplication level up
Multiply two digits given by the user.
- Read the two digits from stdin, multiply them, and print the result, followed by a new line
```bash
julien@ubuntu:~/monty/bf$ bf 1003-mul.bf 
77
49
julien@ubuntu:~/monty/bf$ 
```