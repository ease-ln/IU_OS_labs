#include <stdio.h>
#include <stdlib.h>
int counter = 3;
struct Node{
    int data;
    struct Node* next;
};

void print_list(struct Node* n){
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}

void insert_node(struct Node* n){
    int value,index;
    struct Node* temp;
    printf("Enter the index of a value after which insert new node:");
    scanf(" %d" , &index);
    if(counter<index || index<0){
        printf("Error0: element with this index does not exist");
        exit(0);
    }
    printf("Enter the integer value of new node:");
    scanf(" %d" , &value);

    for(int i=0; i<index;i++){
       n = n->next;
    }

    temp = n->next;
     n->next = (struct Node*)malloc(sizeof(struct Node));
     n->next->data = value;
     n->next->next = temp;
    counter++;

}

void delete_node(struct Node* n){
    int index = 0;
    printf("Enter the index of an element you want to delete:");
    scanf(" %d" , &index);
    if(counter<index || index<0){
        printf("Error0: element with this index does not exist");
        exit(0);
    }
    for(int i=0; i<index-1;i++){
       n = n->next;
    }
    n->next = n->next->next;
    counter--;
}

int main(){

 struct Node* head = NULL;
 struct Node* node1 = NULL;
 struct Node* node2 = NULL;
 struct Node* node3 = NULL;
  head  = (struct Node*)malloc(sizeof(struct Node));
  node1 = (struct Node*)malloc(sizeof(struct Node));
  node2 = (struct Node*)malloc(sizeof(struct Node));
  node3 = (struct Node*)malloc(sizeof(struct Node));

   head->data = 3;
   head->next = node1;

   node1->data = 10;
   node1->next = node2;

   node2->data = 2;
   node2->next = node3;

   node3->data = 1;
   node3->next = NULL;

   print_list(head);

   insert_node(head); //by index
   print_list(head);
   insert_node(head); //by index
   print_list(head);
   delete_node(head); //be index
   print_list(head);

   return 0;
}
