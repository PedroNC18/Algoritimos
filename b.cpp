#include<iostream>

using namespace std;

struct lista{
    int val;
    lista *next;
};

bool empty(lista *head){
    if(head->next==NULL){
        return true;
    }else{
        return false;
    }

}

lista *create_node(int val){
    lista *node=NULL;
    node = (lista*)malloc(sizeof(lista));
    node->val = val;
    node->next = NULL;
    return node;
}

lista * create_node(int val,lista* suc){
	lista *node=NULL;
    node = (lista*)malloc(sizeof(lista));
    node->val = val;
    node->next = suc;
    return node;
}

lista *insert_node(lista *head, int val){
    lista *curr=NULL;
    curr = head;
    while(!empty(curr)){
        curr = curr->next;
    }
    curr->next = create_node(val);
    return head;

}

lista *insert_node(lista *head, int val,int pos){
    lista *curr=NULL;
    int at=0;

    curr = head;
    while(at<pos){
        curr = curr->next;
        at++;
    }

    if(curr->next!=nullptr){
    	curr->next = create_node(val,curr->next);
    }else{
    	curr->next = create_node(val);
    }
    return head;

}

void show(lista *head){
    lista *curr=NULL;
    curr = head;
    while(!empty(curr)){
        curr = curr->next;
        cout << curr->val << " ";
    }
    cout <<"--/null" <<endl;
}

lista *pop_back(lista *head){
    lista *curr=head;
    lista *old=head;
    while(!empty(curr)){
        old = curr;
        curr = curr->next;
    }
    old->next = NULL;
    free(curr);
    return head;

}

int main(){
    lista *head=nullptr;
    head = (lista*)malloc(sizeof(lista));
    head->next=nullptr;


    head = insert_node(head,19);
    head = insert_node(head,24);

    for(int i=0;i<8;i++){
        head = insert_node(head,(i+3)%5);
    } 
    show(head);
    for(int i=0;i<5;i++){
        head = pop_back(head);
        show(head);
    }
    for(int i = 0; i<10; i++){
        head = insert_node(head,i);
        show(head);
    }
    
    while(!empty(head)){
        show(head);
        head = pop_back(head);
    }

   	head = insert_node(head,50,0); 

    free(head);

    return 0;
}