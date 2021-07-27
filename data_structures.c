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

void array_b_search(int * arr, int length, int start, int end, int q) {

  int middle = (end - start) / 2, index = -1;

  if (q == middle) {
    index = length / 2;
    print_new_line();
    printf("---> Hey, I found %d at %d", q, index);
    print_new_line();
    return;
  } else if (q < middle) {
    array_b_search(arr, length / 2, start, middle, q);
  } else if (q > middle) {
    array_b_search(arr, length / 2, middle, end, q);
  }

}

void array_binary_search(int * arr, int length, int start, int end) {
  print_new_line();
  printf("The sorted array is:");
  print_new_line();
  array_traversal(arr, length);

  printf("Which element do you want to search?");
  print_new_line();
  
  int q = 0;

  scanf("%d", & q);
  print_new_line();

  array_b_search(arr, length, start, end, q);
}

void array_selection_sort(int * arr, int length) {
  if (length == 1) {
    print_new_line();
    printf("Array sorted via selection sort");
    print_new_line();
    print_new_line();
    return;
  }
  int j, smallest_index = 0;
  for (j = 1; j < length; j++) {
    if (arr[j] < arr[smallest_index]) {
      smallest_index = j;
    }
  }
  int temp = arr[0];
  arr[0] = arr[smallest_index];
  arr[smallest_index] = temp;

  array_selection_sort(arr + sizeof(int), length - 1);
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
    array_selection_sort(arr, length);
    array_binary_search(arr, length, arr[0], arr[length - 1]);
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

    // case 2: stacks();
    // break;

    // case 3: queues();
    // break;

  default:
    print_new_line();
    printf("Please enter a valid choice");
    goto start;
  }

  return 0;
}
