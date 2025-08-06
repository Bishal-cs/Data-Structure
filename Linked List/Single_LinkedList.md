# Single Linked List:
   - A single Linked List is made up of structure nodes where each nodes have two parts - The first part is DATA and The second part is Link part of the node.
---

![Single linked list node structure](/Linked%20List/images/Single_Linked_list_structure.png)
---

   The begning of the list is marked by a special name - **Start The start pointer points to the first node of the list.**
   The link part of each node points to the next node in the list. But link of last node should be **NULL**
   
---

![Single linked list Examples](/Linked%20List/images/Single_Linked_List_Example.png)
---
   - 1st node = start.
   - 2nd node = start -> link.
   - 3rd node = start -> link -> link || 2nd -> link.

---
     
```
struct node {
   int data;
   struct node * link;
};
struct node *start = NULL;
```

## Operations Of Single Linked List -
- [Click to Jump in Programs.](Single_LinkedList.c)
