#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define pb push_back
#define new_vet vector<vector<pair<int,int>>>
using namespace std;
 
struct Grafo {
    int numEdge;
    vector<int> mark, grau;
    new_vet lista;
};
 
void create_grafo(Grafo &grafo, int n){
    grafo.lista.resize(n);
    grafo.numEdge=0;
    grafo.mark.resize(n);
    grafo.grau.resize(n);
}
 
int v_number(Grafo &grafo){
    return grafo.mark.size();
}
 
int e_number(Grafo &grafo){
    return grafo.numEdge;
}
 
int first(Grafo &grafo, int a){
    return grafo.lista[a][0].first;
}
 
int next(Grafo &grafo, int a, int w){
    int i;
    int v_size=grafo.lista[a].size();
    for(i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==w){
            i++;
            break;
        }
    }
    if(i>=v_size){
        cout << "Nao existe" << endl;
        return -1;
    }
    return grafo.lista[a][i].first;    
}
 
void setEdge(Grafo& grafo, int a, int b, int p){
    int v_size=grafo.lista[a].size(), i;
    grafo.numEdge++;
    //cout << v_size << endl;
    for( i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            grafo.lista[a][i].second=p;
            grafo.grau[b]++;
            break;
        }
    }
    if(i<v_size) return;
    grafo.lista[a].pb(make_pair(b, p));
    grafo.grau[b]++;
    sort(grafo.lista[a].begin(), grafo.lista[a].end());
}
 
void delEdge(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
           grafo.lista[a].erase(grafo.lista[a].begin()+i);
            grafo.numEdge--;
            break;
        }
    }
}
 
bool isEdge(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            return true;
        }
    }
    return false;
}
 
int weight(Grafo &grafo, int a, int b){
    int v_size=grafo.lista[a].size();
    for(int i=0;i<v_size;i++){
        if(grafo.lista[a][i].first==b){
            return grafo.lista[a][i].second;
        }
    }
}
 
void setMark(Grafo &grafo, int a, int val){
    grafo.mark[a]=val;
}
 
int getMark(Grafo &grafo, int a){
    return grafo.mark[a];
}

void print_lista(Grafo& grafo, int n){
    int i, j;
    for( i=0;i<n;i++){
        int str=grafo.lista[i].size();
        cout << i << "   ";
        for(j=0;j<str;j++){
            cout << grafo.lista[i][j].first << " ";
        }
        if(j==0)cout << "Lista vazia";
        cout << endl;
        cout << "    ";
        for(j=0;j<str;j++){
            cout << grafo.lista[i][j].second << " ";
        }
        cout << endl; 
    }
}

void topo(Grafo& grafo){
    vector<int> lista;
    int v_size=v_number(grafo);
    for(int i=0;i<v_size;i++) if(grafo.grau[i]==0) lista.pb(i);
    int ini=0;
    while(ini<lista.size()){
        int atual= lista[ini];
        ini++;
        for(int i=0;i<grafo.lista[atual].size();i++){
            int v=grafo.lista[atual][i].first;
            grafo.grau[v]--;
            if(grafo.grau[v]==0) lista.push_back(v);
        }
    }
    if(lista.size()<v_number(grafo)) cout << "Deu merda" << endl;
    else{
        for(int i=0;i<v_size;i++){
            cout << lista[i] << " ";
        }
        cout << endl;
    }
}

int main(void){
    Grafo grafo;
    int i, n, e, a, b, p;
    cout << "Digite o numero de vertices: ";
    cin >> n;
    cout << "Digite o numero de arestas: ";
    cin >> e;
    create_grafo(grafo, n);
    while(e--){
        cout << "Digite a aresta: ";
        cin >> a >> b;
        setEdge(grafo, a, b, 1);
    }
    cout << "Numero de arestas: " << e_number(grafo) << endl;
    cout << "Numero de vertices: " << v_number(grafo) << endl;
    print_lista(grafo, n);
    topo(grafo);
 
    return 0;
}
