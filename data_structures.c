#include <stdio.h>

#include <stdlib.h>

// Syllabus

// 1. Arrays
// - Traversal
// - Searching: Linear, Binary*
// - Insertion*
// - Deletion*
// - Sorting*: Selection, Bubble, Insertion, Merge, Quick, Radix
// - Multi-Dimentional*: Table, Matrix
// - Application*: Polynomial Aritmatic

// 2. Stack
// - Traversal
// - Push
// - Pop
// - Application*: Arithmatic operations

// 3. Queues
// - Traversal
// - Add
// - Remove
// - Circular Queue*
// - Priority Queue*
// - Dequeue*

// 4. Pointers

// 5. Linked lists
// - Create

// 6. Trees

// 7. Graphs

// 8. Files

// 9. Advanced

void print_new_line() {
  printf("\n");
}

void linked_list();

void print_stack_stats(int operations, int length, char * type) {
  print_new_line();
  print_new_line();
  printf("*****************  STATS FOR %s****************************", type);
  print_new_line();
  printf("Time Complexity: O( %d )", operations);
  print_new_line();
  printf("Space Complexity: O( %d )", length);
  print_new_line();
  printf("*********************************************");
  print_new_line();
  print_new_line();

}

void print_array_stats(int operations, int length, char * type) {
  print_new_line();
  print_new_line();
  printf("*****************  STATS FOR %s****************************", type);
  print_new_line();
  printf("Time Complexity: O( %d )", operations);
  print_new_line();
  printf("Space Complexity: O( %d )", length);
  print_new_line();
  printf("*********************************************");
  print_new_line();
  print_new_line();

}

void array_traversal(int * arr, int length) {
  int operations = 0;
  print_new_line();
  for (int i = 0; i < length; i++) {
    operations++;
    printf("%d  ", arr[i]);
    print_new_line();
  }
  print_array_stats(operations, length, "ARRAY TRAVERSAL");
}

void array_linear_search(int * arr, int length) {
  int q = 0, index = -1, operations = 0;
  printf("Please enter which element do you want to search?");
  print_new_line();

  scanf("%d", & q);
  print_new_line();

  for (int i = 0; i < length; i++) {
    operations++;
    if (arr[i] == q) {
      index = i;
      printf("---> Hey, I found %d at index %d (Zero based indexing)", q, i);
      print_new_line();
      break;
    }
  }

  if (index == -1) {
    printf("---> Mmm mm, Sorry couldn't find %d in the array :(", q);
    print_new_line();
  }
  print_array_stats(operations, length, "ARRAY LINEAR SEARCH");
}

void binarySearch(int arr[], int left_index, int right_index, int q, int * operations, int length) {
  * operations = * operations + 1;
  if (right_index >= left_index && q >= arr[left_index] && q <= arr[right_index]) {
    int mid_index = left_index + (right_index - left_index) / 2;

    if (arr[mid_index] == q) {
      print_new_line();
      printf("---> Hey I found %d at index %d", q, mid_index);
      print_new_line();
      return;
    } else if (arr[mid_index] > q) {
      binarySearch(arr, left_index, mid_index - 1, q, operations, length);
    } else if (arr[mid_index] < q) {
      binarySearch(arr, mid_index + 1, right_index, q, operations, length);
    }
  } else {
    print_new_line();
    printf("---> Mmm mm, Sorry couldn't find %d in the array :(", q);
    print_new_line();
  }
}

void array_binary_search(int * arr, int length) {
  print_new_line();
  printf("The sorted array is:");
  print_new_line();
  array_traversal(arr, length);

  printf("Which element do you want to search?");
  print_new_line();

  int q = 0;

  scanf("%d", & q);
  print_new_line();

  int operations = 0;

  binarySearch(arr, 0, length - 1, q, & operations, length);

  print_array_stats(operations, length, " BINARY SEARCH ");
}

void array_selection_sort(int * arr, int length) {
  int operations = 0;
  for (int i = 0; i < length - 1; i++) {
    operations++;
    int smallest_index = i;;
    for (int j = i + 1; j < length; j++) {
      operations++;
      if (arr[j] < arr[smallest_index]) {
        smallest_index = j;
      }
    }
    if (smallest_index != i) {
      int temp = arr[i];
      arr[i] = arr[smallest_index];
      arr[smallest_index] = temp;
    }
  }
  print_new_line();
  printf("Array sorted via selection sort");
  print_new_line();
  print_new_line();
  print_array_stats(operations, length, "ARRAY SELECTION SORT");

}

bool is_array_sorted_ascending(int * arr, int length) {
  bool sorted = true;
  for (int i = 1; i < length; i++) {
    if (arr[i - 1] > arr[i]) {
      sorted = false;
      break;
    }
  }
  return sorted;
}

void arrays() {

  int length = 0, array_choice = 0;
  int * arr;

  printf("Please enter array length");
  print_new_line();

  scanf("%d", & length);
  print_new_line();

  arr = (int * ) malloc(length * sizeof(int));

  printf("Please enter array elements:");
  print_new_line();

  for (int i = 0; i < length; ++i) {
    scanf("%d", & arr[i]);
  }

  array_start: print_new_line();
  printf("Please enter what you want to do?");
  print_new_line();
  array_choice = 0;

  printf("1. Traversal");
  print_new_line();

  printf("2. Linear search");
  print_new_line();

  printf("3. Binary search");
  print_new_line();

  printf("4. Selection sort");
  print_new_line();

  printf("5. Bubble sort");
  print_new_line();

  printf("6. Insertion sort");
  print_new_line();

  printf("7. Merge sort");
  print_new_line();

  printf("8. Quick sort");
  print_new_line();

  printf("9. Radix sort");
  print_new_line();

  print_new_line();
  scanf("%d", & array_choice);

  switch (array_choice) {
  case 1:
    array_traversal(arr, length);
    goto array_start;
    break;

  case 2:
    array_linear_search(arr, length);
    goto array_start;
    break;

  case 3:
    if (!is_array_sorted_ascending(arr, length)) {
      printf("---> Array needs sorting");
      print_new_line();
      print_new_line();
      array_selection_sort(arr, length);
    }

    array_binary_search(arr, length);
    goto array_start;
    break;

    // case 4: array_selection_sort(arr, length);
    // break;

    // case 5: array_bubble_sort(arr, length);
    // break;

    // case 6: array_insertion_sort(arr, length);
    // break;

    // case 7: array_merge_sort(arr, length);
    // break;

    // case 8: array_quick_sort(arr, length);
    // break;

    // case 9: array_radix_sort(arr, length);
    // break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    goto array_start;
  }
}

void stack_traversal(int * stack, int length, int top) {
  int operations = 0;
  for (int i = length - 1; i >= 0; i--) {
    if (i > top) {
      printf("__");
      print_new_line();
    } else if (i == top || top == -1) {
      printf("%d <--- TOP", stack[i]);
      print_new_line();
    } else {
      printf("%d", stack[i]);
      print_new_line();
    }
    operations++;
  }

  print_stack_stats(operations, length, "STACK TRAVERSAL");
}

void stack_push(int * stack, int length, int * top) {
  if ( * top == length - 1) {
    print_new_line();
    printf("Sorry stack is full");
    print_new_line();
    return;
  }
  int e, operations = 0;
  print_new_line();
  printf("Please enter the element you wish to push");
  print_new_line();

  scanf("%d", & e);
  print_new_line();

  * top = * top + 1;
  stack[ * top] = e;
  operations++;

  print_new_line();
  printf("---> Element pushed");
  print_new_line();

  print_stack_stats(operations, length, "STACK PUSH");

  stack_traversal(stack, length, * top);

}

void stack_pop(int * stack, int length, int * top) {
  if ( * top == -1) {
    print_new_line();
    printf("Sorry stack is empty");
    print_new_line();
    return;
  }
  int e = stack[ * top], operations = 0;
  stack[ * top] = 0;
  operations++;
  * top = * top - 1;

  print_new_line();
  printf("---> Popped element: %d", e);
  print_new_line();

  print_stack_stats(operations, length, "STACK POP");

  stack_traversal(stack, length, * top);
}

void stacks() {
  int length = 0, choice = 0, top = -1;
  int * stack;
  print_new_line();
  printf("Please enter maximum length of stack");
  print_new_line();
  scanf("%d", & length);
  print_new_line();

  stack = (int * ) malloc(length * sizeof(int));

  stacks_start: print_new_line();
  printf("Please enter a choice:");

  print_new_line();
  printf("1. Push");

  print_new_line();
  printf("2. Pop");

  print_new_line();
  printf("3. Traversal");

  print_new_line();
  scanf("%d", & choice);
  print_new_line();

  switch (choice) {
  case 1:
    stack_push(stack, length, & top);
    goto stacks_start;
    break;

  case 2:
    stack_pop(stack, length, & top);
    goto stacks_start;
    break;

  case 3:
    stack_traversal(stack, length, top);
    goto stacks_start;
    break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    print_new_line();
    goto stacks_start;
  }
}

void print_queue_stats(int operations, int length, char * type) {
  print_new_line();
  print_new_line();
  printf("*****************  STATS FOR %s****************************", type);
  print_new_line();
  printf("Time Complexity: O( %d )", operations);
  print_new_line();
  printf("Space Complexity: O( %d )", length);
  print_new_line();
  printf("*********************************************");
  print_new_line();
  print_new_line();
}
void queue_traversal(int * queue, int length, int rear) {
  print_new_line();
  int operations = 0;

  for (int i = 0; i < length; i++) {
    operations++;
    if (rear == -1 && i == 0) {
      printf("(F) (R)");
    } else if (i == 0) {
      printf("(F) %d ", queue[i]);
    } else if (i < rear) {
      printf(" %d ", queue[i]);
    } else if (i == rear) {
      printf(" %d (R)", queue[i]);
    } else if (i > rear) {
      printf(" __ ");
    }
  }
  print_new_line();
  print_new_line();

  print_queue_stats(operations, length, " QUEUE TRAVERSAL ");
}

void queue_add(int * queue, int length, int * rear) {
  if ( * rear == length - 1) {
    print_new_line();
    printf("Sorry queue is full");
    print_new_line();
    return;
  }
  int e, operations = 0;
  print_new_line();
  printf("Please enter the element you wish to add.");
  print_new_line();

  scanf("%d", & e);

  * rear = * rear + 1;
  queue[ * rear] = e;
  operations++;

  print_new_line();
  printf("%d added to queue", e);
  print_new_line();

  print_queue_stats(operations, length, " QUEUE ADD ");

  queue_traversal(queue, length, * rear);

}

void queue_remove(int * queue, int length, int * rear) {
  if ( * rear == -1) {
    print_new_line();
    printf("Sorry queue is empty");
    print_new_line();
    return;
  }

  int e = queue[0], operations = 0;

  for (int i = 0; i < * rear; i++) {
    queue[i] = queue[i + 1];
  }
  * rear = * rear - 1;

  print_new_line();
  printf("Removed element is %d", e);
  print_new_line();

  print_queue_stats(operations, length, " QUEUE REMOVE ");

  queue_traversal(queue, length, * rear);

}

void queues() {
  int * queue;
  int length = 0, choice = 0, rear = -1;

  print_new_line();
  printf("Please enter maximum length of queue");
  print_new_line();

  scanf("%d", & length);
  queue = (int * ) malloc(length * sizeof(int));

  queues_start: print_new_line();
  printf("Please enter choice:");

  print_new_line();
  printf("1. Add");

  print_new_line();
  printf("2. Remove");

  print_new_line();
  printf("1. Traversal");

  print_new_line();
  scanf("%d", & choice);

  switch (choice) {
  case 1:
    queue_add(queue, length, & rear);
    goto queues_start;
    break;

  case 2:
    queue_remove(queue, length, & rear);
    goto queues_start;
    break;

  case 3:
    queue_traversal(queue, length, rear);
    goto queues_start;
    break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    goto queues_start;

  }

}

int main() {
  start: int ds_choice = 0;
  print_new_line();
  printf("********************  WELCOME ***************************");
  print_new_line();
  print_new_line();
  printf("Please enter which data structure you want to use?");

  print_new_line();
  printf("1. Array");

  print_new_line();
  printf("2. Stack");

  print_new_line();
  printf("3. Queue");
  print_new_line();

  print_new_line();
  printf("4. Linked Lists");
  print_new_line();

  print_new_line();
  scanf("%d", & ds_choice);
  print_new_line();

  switch (ds_choice) {
  case 1:
    arrays();
    break;

  case 2:
    stacks();
    break;

  case 3:
    queues();
    break;

  case 4:
    linked_list();
    break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    goto start;
  }

  return 0;
}

struct node {
  int value;
  struct node * next;
};

void append(struct node * head) {
  struct node * new_node = (struct node * ) malloc(sizeof(struct node));

  printf("new node value");
  scanf("%d", & new_node -> value);

  head -> next = new_node;
  head = new_node;

  print_new_line();
  printf("added");
}

void print(struct node * first) {
  struct node * iterator = first;
  while (iterator != NULL) {
    printf("%d -> ", iterator -> value);
    iterator = iterator -> next;
  }
}

void linked_list() {
  int choice = 0;

  print_new_line();

  struct node * first = (struct node * ) malloc(sizeof(struct node));

  print_new_line();
  printf("first node value");
  scanf("%d", & first -> value);
  first -> next = NULL;

  struct node * head = first;

  ll_start: print_new_line();
  printf("1. append to LL");

  print_new_line();
  printf("2. print LL");

  printf("choice");
  scanf("%d", & choice);

  switch (choice) {
  case 1:
    append(head);
    goto ll_start;
    break;

  case 2:
    print(first);
    goto ll_start;
    break;
  }
}
