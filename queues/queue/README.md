# Queue

* Define `SIZE` as any value (here, 8)
* Create ints `queue[SIZE], front, rear`
* Create funcitons to enqueue, dequeue and display

```c
void enqueue(int);
void dequeue();
void display();
```

## Enqueue
* 3 cases
1. queue is full: do nothing
2. queue is empty: `set front = rear = 0`
3. else `rear++`

## Dequeue
* also 3 cases
1. queue is full: `set front = rear = -1`
2. queue is empty
3. else `front++`

## Display
* display from front to rear



