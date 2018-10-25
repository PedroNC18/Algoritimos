#include <iostream>
#include <vector>
#define TIPE int
#define pb push_back
using namespace std;
 
void create_union(int n, vector<TIPE>&pai, vector<TIPE>&peso){
   for(int i=0;i<=n;i++){
       pai.pb(i);
   }  
    peso.resize(n);
   
}
 
TIPE find(int x, vector<TIPE>&pai){
    if(pai[x]==x) return x;
    return pai[x] = find(pai[x], pai);
}
 
void join(int x, int y, vector<TIPE>&pai, vector<TIPE>&peso){
    x = find(x, pai);
    y = find(y, pai);
    if(x==y) return;
    if(peso[x]<peso[y]){
        pai[x] = y;
    }
    else if(peso[x]>peso[y]){
        pai[y] = x;
    }
    else{
        pai[x] = y;
        peso[y]++;
    }
 
}
 
int main(){
    int casos;
    cin >> casos;
    while(casos--){
        vector<TIPE> pai, peso;
        int p, n, aux1, aux2, maximo;
        cin >> p >> n;
        create_union(p, pai, peso);
        while(n--){
            cin >> aux1 >> aux2;
            join(aux1, aux2, pai, peso);
        }
        maximo = decubra_max(n, pai);
        cout << maximo <<  endl;
    }
    return 0;
}
