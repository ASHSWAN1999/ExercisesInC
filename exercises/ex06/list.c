/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
  Node *current = *list;
  Node *prev;

    if((current)==NULL) { //handles empty list
      return -1;
    }
    else {
      int val = (current)->val;
      prev = current; //stores pointer to popped node so it can be freed
      *list = (current)->next;
      free(prev);
      return val;
    }
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *new = make_node(val, NULL);
    new->next = *list;
    *list = new;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
  Node *current = *list;
  Node *prev;

  if(current == NULL) { //handles empty list
    return 0;
  }
  else if (current->val == val) { //handles removing first node
    prev = current;
    *list = current->next;
    free(prev);
    return 1;
  }
  else { //loops through remaining nodes
    while(current->val != val) {
      if(current->next == NULL) {
        return 0;
      }
      prev = current;
      current = current->next;
    }

    prev->next = current->next; //points to node one beyond next
    free(current);

    return 1;
  }
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    if(*list == NULL) { //handles empty list
      return;
    }
    else if((*list)->next == NULL) { //handles list length 1
      return;
    }
    else { //reverses lists longer than length 1
      Node *prev = *list;
      Node *current = prev->next;
      Node *temp = current->next;

      prev->next = NULL; //first node becomes the last

      while(temp != NULL) { //points each next to the previous node
        current->next = prev;
        prev = current;
        current = temp;
        temp = current->next;
      }

      current->next = prev;
      *list = current; //reassigns head of the list
    }
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    // printf("%i\n", retval);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 11);
    print_list(list);
    //
    reverse(list);
    print_list(list);
}
