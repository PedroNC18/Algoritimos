#include<iostream>
#include<vector>
using namespace std;

struct Grafo{
    int **matrix;
    int numEgde;
    vector<int> mark;
};

Grafo create_grafo(int n){
    Grafo grafo;
    grafo.matrix = new int*[n];
    for(int i=0;i<n;i++){
        grafo.matrix[i] = new int[n]; 
    }
    grafo.numEgde=0;
    grafo.mark.resize(n);
    return grafo;
}

int v_number(Grafo& grafo){
    return grafo.mark.size();
}

int e_number(Grafo& grafo){
    return grafo.numEgde;
}

int first(Grafo& grafo, int a){
    int v_size = v_number(grafo);
    for(int i=0;i<v_size;i++){
        if(grafo.matrix[a][i]!=0){
            return grafo.matrix[a][i];
        }
    }
    return v_size;
}

void setEdge(Grafo& grafo, int a, int b, int p){
    if(p==0) cout << "Tu eh doido rapaz?" << endl;
    if(grafo.matrix[a][b]==0) grafo.numEgde++;
    grafo.matrix[a][b]=p;
}

void delEdge(Grafo& grafo, int a, int b){
    if(grafo.matrix[a][b]!=0) grafo.numEgde--;
    grafo.matrix[a][b]=0;
}

bool isEdge(Grafo& grafo, int a, int b){
    if(grafo.matrix[a][b]==0) return false;
    return true;
}

int peso(Grafo& grafo, int a, int b){
    return grafo.matrix[a][b];
}

void setMark(Grafo& grafo, int a, int val){
    grafo.mark[a]=val;
}

int getMark(Grafo& grafo, int a){
    return grafo.mark[a];
}

void print_matrix(Grafo grafo){
    int v_size=v_number(grafo);
    cout << "  ";
    for(int i=0;i<v_size;i++){
        cout << i << " ";
    }
    cout << endl;
    for(int i=0;i<v_size;i++){
        cout << i << " ";
        for(int j=0;j<v_size;j++){
            cout << grafo.matrix[i][j] << " ";
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
    grafo = create_grafo(n);
    while(e--){
        cout << "Digite a aresta e o seu peso: ";
        cin >> a >> b >> p;
        setEdge(grafo, a, b, p);
    }
    cout << "Numero de arestas: " << e_number(grafo) << endl;
    cout << "Numero de vertices: " << v_number(grafo) << endl;
    print_matrix(grafo);

    return 0;
}
