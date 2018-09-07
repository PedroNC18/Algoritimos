#include<iostream>

using namespace std;

void selection_sort(int vet[], int n){
	int i, j, min;
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(vet[j]<vet[min]){
				min = j;
			}
		}
		int aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
    
	int vet[100000], vetn=0;
	cin >> vetn;
	int i;
	for(i=0;i<vetn;i++){
		cin >> vet[i];
	}
	
	//---(COLOCAR UMA FUNCAO SORT NESSE LUGAR)----\\

	for(i=0;i<vetn;i++){
		cout << vet[i] << " ";
	}
	return 0;
}