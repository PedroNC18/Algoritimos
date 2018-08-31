#include <iostream>
#define INF 0x3f3f3f

using namespace std;

struct pilha {
    int val;
    pilha *next;
};
int ctn=0;
pilha *push(pilha *top, int val){
    pilha *p=nullptr;
    p = new pilha;
    p->val = val;
    p->next = top;
    ctn++;
    return p;
}

pilha *pop(pilha *top){
    pilha *temp=top;
    top = top->next;
    ctn--;
    delete temp;
    return top;
}

void show(pilha *top){
    pilha *curr=nullptr;
    curr = top;
    while(curr->next!=nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << "Fim da lista, " << "ctn: " << ctn << endl;
}

int main(void){
    pilha *top=nullptr;
    top = new pilha;
    top->next = nullptr;
    top->val = INF;
    int i;
    for(i=1;i<=6;i++){
        top = push(top, i);
        show(top);
    }
    while(top->next!=nullptr){
        top = pop(top);
        show(top);
    }
    return 0;
}