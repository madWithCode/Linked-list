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

void printLinkedList(struct node **head){
    struct node *curr_node = *head;
    while(curr_node != NULL){
        cout << curr_node->data << "\n"; 
        curr_node = curr_node->next;
    }
}

void deleteNode(struct node **head, int position){
    struct node *curr_node = *head;
    int counter = 1;
    
    if(position == 1){
        struct node *tmp = curr_node;
        *head = curr_node->next;
        free(tmp);
    }else{
        while(counter < position-1 && curr_node != NULL && curr_node->next != NULL){
            curr_node = curr_node-> next;
            counter++;
        }
    
        if(curr_node->next == NULL){
            cout << "no such node available" << "\n";
        }else{
            struct node *tmp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(tmp);
        }
        
    }
    cout << "deleted node" << "\n";
}

int main()
{
    struct node *head = NULL; 
    InsertLinkedList(&head, 1, 10);
    InsertLinkedList(&head,2,20);
    InsertLinkedList(&head,2,-50);
    InsertLinkedList(&head,2,60);
    InsertLinkedList(&head,1,5);
    InsertLinkedList(&head,6,21);
    printLinkedList(&head);
    deleteNode(&head,1);
    printLinkedList(&head);
    deleteNode(&head,4);
    printLinkedList(&head);
    return 0;
}
