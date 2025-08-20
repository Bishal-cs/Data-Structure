# **Data Structure**
Generally any problem that has to be solved by the computer involves the use of data if data is arranged in a Some systematic way that gets a structure and becomes a meaningful there are many ways in which data can be organised or structured. To provide an appropriate structure to the data we needed to know about the data structure. Data structure can be defined as systematic way to organise the data so that it can be used efficiently.

## What is Abstract Data Type (ADT) ?
- **Abstract Data Type** is a mathematical model or consept that depends a data logically. It specifies a set of data and collection of operations that can be performed on the data. The defenation of **Abstract Data Type**(ADT) only mention what type of operations can be performed but not how the operations can be performed. It is called Abstract cause its gives implementation implemeted view.
The process of the providing only the essentials and hiding the details is known as abstruction.

   - **Examples:** Stack ADT, Queue ADT, Linked List ADT.

- **Data Structure** is a programming consept that is used to implemented and abstruct data-type. It is the phyisical implementation of **ADT**.
All operations specified in ADT are implemented through the functions.
ADT is a logical view of data and operations to manupulate of data. Data Structure actule representation of data and algorithms to manupulate the data.

# Linked List :
 - List is a collection of simmilar type of elements. There two ways of maintaining a list in memory.
   1. By array we can store the simmilar type of value or elements.
   2. By linked list we can store the simmilar type of value also.

---

   ### Types of Linked List:
   1. Single Linked List. 
      - [Click to Jump in Single Documentation.](./Linked%20List/Single_LinkedList.md)
      - [Click to Jump in Single Programs.](./Linked%20List/Single_LinkedList.c)

   2. Doubly Linked List.
      - [Click to Jump in Doubly Documentation.](./Linked%20List/Doubly_LinkedList.md)
      - [Click to Jump in Doubly Programs.](./Linked%20List/Doubly_LinkedList.c)

   3. Circular Linked List.
      - [Click to Jump in Circular Documentation.](./Linked%20List/Circular_LinkedList.md)
      - [Click to Jump in Circular Programs.](./Linked%20List/Circular_LinkedList.c)
   ---
   ### Apps of Linked List:
   1. Polynomial Arithmatic with linked list. 
      - [Click to Jump in Polynomial Documentation.](./Linked%20List/Polynomial_App_LinkedList.md)
      - [Click to Jump in Polynomial Programs.](./Linked%20List/Polynomial_App_LinkedList.c)
   ---

# Stack:
 - Stack is a linear list data data structure where the insertin and deletion are allowed in one end. Called top of the stack which points the top most element od the stack. We can insert the element through the top pointer & also delete from the top pointer.

 The insertion operation in stack is known as *PUSH* & Delete operation is known as *POP*. Before any element, we must check whethere there is a space in the stack or not. If there is not engouh space the stack is said to be *Overflow* condition & the new element cannot be pushed in this schenerio if we wnat to perform the pop operation & check that the stack is empty or not. If the stack is empty the stack is said to be *underflow* condition.

 We can see that the element which is pushed / inserted last - that element is poped out / delete from the stack. That is the reson or this beheviour is called ***LIFO(Last In First Out)*** data structure. 
 
---
   ### Stack implementations:
   1. Stack Implementation in array.
      - [Click to Jump in stack in array Documentation.](./Stack/array_in_stack.c)
      - [Click to Jump in stack in array Programs.](./Stack/stack.md)

   2. Stack Implementation in Linked List.
      - [Click to Jump in stack in Linked List Documentation.](./Stack/Linked_List_in_Stack.c)
      - [Click to Jump in stack in Linked List Programs.](./Stack/stack.md)

---