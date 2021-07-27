// Hello world! Cplayground is an online sandbox that makes it easy to try out
// code.

#include <stdio.h>

#include <stdlib.h>

void print_new_line() {
  printf("\n");
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
  for (int i = 0; i < length; i++) {
    operations++;
    printf("index %d has element: %d", i, arr[i]);
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

void binarySearch(int arr[], int left_index, int right_index, int q) {
  if (right_index >= left_index) {
    int mid_index = left_index + (right_index - left_index) / 2;

    // If the element is present at the middle
    // itself
    if (arr[mid_index] == q)
      print_new_line();
    printf("---> Hey I found %d at index %d", q, mid_index);
    print_new_line();
    return;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid_index] > q)
      binarySearch(arr, left_index, mid_index - 1, q);
    else
      // Else the element can only be present
      // in right subarray
      binarySearch(arr, mid_index + 1, right_index, q);
  } else {
    print_new_line();
    printf("---> Mmm mm, Sorry couldn't find %d in the array :(", q);
    print_new_line();
  }

  // We reach here when element is not
  // present in array
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

  binarySearch(arr, 0, length - 1, q);
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

  }
}

void stack_push(int * stack, int length, int * top) {
  if ( * top == length - 1) {
    print_new_line();
    printf("Sorry stack is full");
    print_new_line();
    return;
  }
  int e;
  print_new_line();
  printf("Please enter the element you wish to push");
  print_new_line();

  scanf("%d", & e);
  print_new_line();

  * top = * top + 1;
  stack[ * top] = e;

  print_new_line();
  printf("---> Element pushed");
  print_new_line();

  stack_traversal(stack, length, * top);

}

void stack_pop(int * stack, int length, int * top) {
  if ( * top == -1) {
    print_new_line();
    printf("Sorry stack is empty");
    print_new_line();
    return;
  }
  int e = stack[ * top];
  * top = * top - 1;

  print_new_line();
  printf("---> Popped element: %d", e);
  print_new_line();

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
  scanf("%d", & ds_choice);
  print_new_line();

  switch (ds_choice) {
  case 1:
    arrays();
    break;

  case 2:
    stacks();
    break;

    // case 3: queues();
    // break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    goto start;
  }

  return 0;
}
