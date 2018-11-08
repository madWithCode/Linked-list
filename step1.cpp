#include <iostream> 

using namespace std;

struct node {
    int data;
    struct node *next;
};

void InsertLinkedList(struct node **head, int position, int data){
      // malloc return the pointer to the memory allocated, memory to accomodate size of struct s created
    struct node *linkNode = (node*) malloc(sizeof(struct node));
    struct node *curr_node;
    int counter = 1;
    //check if memory got allocated
    if(!linkNode){
        printf("memory error");
        return;
    }else{
        linkNode->data = data;
        linkNode->next = NULL;
    }
    
    // std::cout << head->data << std::endl;
    if(position == 1){
        linkNode->next = *head;
        *head = linkNode;
    }else{
        curr_node = *head;
        while(counter < position-1 && curr_node-> next != NULL){
            curr_node = curr_node-> next;
            counter++;
        }
        linkNode->next =  curr_node->next;
        curr_node->next = linkNode;
    }
}

int main()
{
    struct node *head = NULL; 
    InsertLinkedList(&head, 1, 10);
    cout << head->data << "\n";
    InsertLinkedList(&head,2,20);
    cout << head->next->data << "\n";
    InsertLinkedList(&head,5,-50);
  	cout << head->next->data << "\n";
    cout << head->next->next->data << "\n";
    return 0;
}
