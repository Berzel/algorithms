#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

/**
 * Define a Node ADT that will be used as nodes/cells on the linked list
 * 
 **/
struct Node {
  int val;
  Node *next;
};

/**
 * Create a new empty list. A sentinel is used to simplify other algorithms when adding or deleting from the list.
 * When sentinel is pointing to NULL then the list is empty
 * 
 * @return Node *sentinel A pointer to the sentinel node in the list. This node should not contain any meaniful value needed by the list
 **/
Node *createList(){
  Node *sentinel = (Node *) malloc(sizeof(Node));
  sentinel->next = (Node *) 0;
  return sentinel;
}

/**
 * Insert a new node at the end of the list i.e the new value is inserted as the last item to the list.
 * The algorithm returns a pointer to the tree so that in cases where the function is pure we can get a newly created tree 
 * with the new item added
 * 
 * @param Node *root  A pointer to the root node of the tree. This is effectively the sentinel of the list
 * @param int val The new value that is to be inserted at the end of the list
 * @return Node *root A pointer to the root of the tree with the new item added.
 **/
Node *insert(Node *root, int val){
  Node *ptr = root;

  while (ptr->next != (Node *) 0){
    ptr = ptr->next;
  }

  Node *new = (Node *) malloc(sizeof(Node));
  new->val = val;
  new->next = ptr->next;
  ptr->next = new;
  
  return root;
}

/**
 * Delete the first item from the list
 * 
 * @param Node *list  A pointer to the root of the list
 * @return Node *list A pointer to the root of the list with the item deleted
 **/
Node *delete_first(Node *list){
  list->next = list->next->next;
  return list;
}

/**
 * Print all the items in a list
 * 
 * @param Node *list  The pointer to the root of the list
 **/
void printList(Node *list){
  Node *ptr = list->next;

  while (ptr != (Node *) 0){
    printf("%d ", ptr->val);
    ptr = ptr->next;
  }
}

/**
 * Run some tests
 * 
 **/
int main(){
  Node *list = createList();
  int n = 10;

  for (int i = 4; i < n; ++i) {
    list = insert(list, i);
  }

  printf("======= Before Delete =====\n");
  printList(list);
  printf("\n");

  list = delete_first(list);

  printf("======= After Delete ======\n");
  printList(list);
  printf("\n");
  return 0;
}