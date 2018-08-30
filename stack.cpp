/*© Copyright 2018 Todos os direitos reservados a Marcos Oliveira*/ 

#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;

typedef struct pilha{
        int val;
	struct pilha * next;
}pilha;


int tope(pilha * top){
	return top->val;
}

bool empty(pilha * head){
	if(head->next == nullptr){
		return true;
	}else{
		return false;
	}
}

pilha * pop(int & val,pilha* head){
	pilha * cur = nullptr;
	pilha * old = nullptr;

	old = head;
	cur = head;

	while(!empty(cur)){
		old=cur;
		cur=cur->next;
	}

	val = cur->val;

	old->next = nullptr;

	delete cur;

	return old;
}





pilha * push(int v , pilha * top){
	pilha * n = nullptr;
	
	n = new pilha;
	
	n->val = v;
	n->next = nullptr;

	top->next=n;

	return n;
}

void show(pilha * head){
	pilha * cur = nullptr;

	cur = head->next;

	while(cur!= nullptr){
		cout << cur->val << endl;
		cur=cur->next;
	}
	
	cout << endl;	
}



int main(void){

	pilha * head = nullptr;
	pilha * top = nullptr;
	int val = 0;

	head = new pilha;

	head->val = INF;
	head->next = nullptr;
	
	top = head;

	top = push(0,top);

	//show(head);

	top = push(1,top);
	top = push(2 ,top);

	//show(head);

	top = pop(val,head);

	//cout << val << endl;

	top = push(50,top);
	top = push(30,top);

	while(!empty(head)){
		cout << tope(top)<<endl;
		top = pop(val,head);
	}	

   return 0;
}
