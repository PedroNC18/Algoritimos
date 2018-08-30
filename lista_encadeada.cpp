#include<iostream>

using namespace std;

struct lista{
    int val;
    lista *next;
    int ctn=0;
};

bool list_end(lista *head){
    if(head->next==nullptr){
        return true;
    }
    else{
        return false;
    }
}

lista *create_node(int val){
    lista *node=nullptr;
    node = new lista;
    node->val = val;
    node->next = nullptr;
    return node;
}

lista *create_node(int val, lista *nextval){
    lista *node=nullptr;
    node = new lista;
    node->val = val;
    node->next = nextval;
    return node;
}

lista *insert_node(lista *head, int val){
    lista *curr=nullptr;
    curr = head;
    while(!list_end(curr)){
        curr = curr->next;
    }
    curr->next = create_node(val);
    head->ctn++;
    return head;
}

lista *insert_node(lista *head, int val, int pos){
    lista *curr=nullptr;
    curr = head;
    while(pos--){
        curr = curr->next;
    }
    curr->next = create_node(val,curr->next);
    head->ctn++;
    return head;
}

void show(lista *head){
    lista *curr=nullptr;
    curr = head;
    while(!list_end(curr)){
        curr = curr->next;
        cout << curr->val << " ";
    }
    cout << "--->End of list" <<" with ctn = " << head->ctn << endl;
}

lista *delete_node(lista *head){
    lista *curr = nullptr;
    lista *old = nullptr;
    curr = head;
    old = head;
    while(!list_end(curr)){
        old = curr;
        curr = curr->next;
    }
    old->next = nullptr;
    head->ctn--;
    return head; 
}

lista *delete_node(lista *head, int pos){
    lista *curr = nullptr;
    lista *old = nullptr;
    curr = head;
    old = head;
    curr = curr->next;
    while(pos--){
        //cout << "entrei" << endl;
        old = curr;
        curr = curr->next;
    }
    old->next = curr->next;
    free(curr);
    head->ctn--;
    return head; 
}

int main(void){
    lista *head=nullptr;
    head = new lista;
    head->next=nullptr;
    head->ctn=0;
    int i, ctn=0;
    for(i=1;i<6;i++){
        head = insert_node(head, i);
    }
    show(head);
    head = insert_node(head, 0, 0);
    show(head);
    head = delete_node(head);
    show(head);
    head = delete_node(head,1);
    head = delete_node(head,2);
    show(head);
    free(head);
    return 0;
}
