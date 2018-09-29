#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	node *left;
	node *right;
};

node *new_node(int value){
	node *temp = new node;
	temp->val = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node *insert(node *temp, int value){
	if(temp==NULL){
		return new_node(value);
	}
	else if(temp->val>value){
		temp->left = insert(temp->left, value);
	}
	else{
		temp->right = insert(temp->right, value);
	}
	return temp;
}

node *find(node *temp, int value){
    if(temp==NULL){
        cout << "Nao encontrado" << endl;
    }
    else if(temp->val == value){
        cout << "Valor: " << temp->val << " encontrado" << endl;
    }
    else if(temp->val>value){
        temp->left = find(temp->left, value);
    }
    else{
        temp->right = find(temp->right, value);
    }
    return temp;
}

int main(void){
	node *root=NULL;
	int x, t=0, k;
	while(cin >> x){
		root = insert(root, x);
		t++;
	}
		root = find(root, 10);
	return 0;
}
