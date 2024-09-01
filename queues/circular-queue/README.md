# Cicular Queue

* Very similar to our regular queue, just with a little extra modular arithmetic :)
* Define `SIZE` as any value (here, 8)
* Create ints `queue[SIZE], front, rear`
* Create funcitons to enqueue, dequeue and display

```c
void enqueue(int);
void dequeue();
void display();
```
## Various states of a circular queue
* Queue is empty  
`front == -1 && rear == -1`

* Queue is full  
`front == (rear+1)%SIZE`

* Queue contains a single element  
`rear == front`

## Finding the number of elements in a queue
```c
if (front <= rear)
    count = rear-front+1
else
    count = SIZE - front + rear + 1
```

## Enqueue
* 3 cases
1. queue is full
2. queue is empty
3. else `rear = rear+1 %SIZE`

## Dequeue
* also 3 cases
1. queue is full
2. queue is empty
3. else `front = front+1 %SIZE`

## Display
* Again, 3 cases
1. queue is empty - don't display
2. front <= rear:  
   iterate from front to rear
2. front > rear:  
   iterate from front to SIZE-1 in loop 1
   iterate from 0 to rear in loop 2



