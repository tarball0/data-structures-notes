# Linked Lists

* A linked list can be represented in c using a self referring structure  

```c
typedef struct{
    int value;
    node* next;
} node;
```
* loads of uses for linked lists
* traversal O(n)
* insertion O(1)
* deletion O(1)  

* can increase cache misses though so may decrease performance  

### Insertion
* insert from front
```c
node new;
new->value = value;
new->next = head;
head = &new;
```

