#include <iostream>
using namespace std;

void preencheMatrizInicial(int** m, int v);

void preencheRelacoes(int** m, int v, int& a);

void imprimeRelacoes(int** m , int v);

void filhosVertice(int** m, int v, int f[], int vD);

int main(){
    /*
     Possibilita Calcular(No momento):
        - Quantidade de Vértices
        - Quantidade de Arestas/arcos
        - Imprimir a matriz de relações do grafo
        - Identificar os filhos de um vértice no grafo
    */

    bool finalizar = false;
    cout << "                                         <Grafos em Algoritmos>\n";
    cout << "                                 Grafo: nao valorado e nao direcionado" << endl;

    int numVertices;

    while(finalizar != true){
        cout << "\n- Quantidade de Vertices do grafo: ";
        cin >> numVertices;

        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nErro: tipo de variavel invalido\n";
        }else{
            if(numVertices <= 1){
                cout << "\nErro: numero de vertices precisa ser >= 1\n";
            }else{
                int** relacoes = new int*[numVertices]; // declarando a matriz  
                for(int i=0; i<numVertices ; i++){
                    relacoes[i] = new int[numVertices];
                }

                preencheMatrizInicial(relacoes, numVertices);
    
                int numArestas = 0; // numero de relacoes = numero de arestas
                preencheRelacoes(relacoes, numVertices, numArestas);
    
                cout << "\n- Deseja saber os filhos de algum Vertice?\n";
                cout << "Resposta(1 ou 0): ";
    
                bool respostaFilhos;
    
                cin >> respostaFilhos;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nErro: tipo de variavel invalido\n";
                }else{
                    int filhos[numVertices]; // um vertice pode ter no maximo numVertices-1 filhos
    
                    cout << "Vertice Desejado: ";
                    int verticeDesejado;
                    cin >> verticeDesejado;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nErro: tipo de variavel invalido -> Considerando nao haver relacao\n";
                    }else{
                        verticeDesejado--;
                        filhosVertice(relacoes, numVertices, filhos, verticeDesejado);
                    }
                }
                imprimeRelacoes(relacoes, numVertices);
    
                cout << "Quantidade de Vertices: " << numVertices << endl;
                cout << "Quantidade de Arestas/Arcos: " << numArestas << endl;
                cout << "G(" << numVertices << "," << numArestas << ")\n";

                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "- Deseja calcular outro grafo?\n";
                cout << "Resposta(1 ou 0): ";

                bool respostaRepetir;
                cin >> respostaRepetir;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nErro: tipo de variavel invalido\n";
                }else{
                    if(respostaRepetir == false){
                        cout << "\nPrograma sendo Finalizado\n";
                        finalizar = true;
                    }
                }
                
                //deletando a matriz de relacoes
                for (int i = 0; i < numVertices; i++) {
                    delete[] relacoes[i]; 
                }
                delete[] relacoes;
            }
        } 
    }
    return 0;
}

void preencheMatrizInicial(int** m, int v){
    for(int i=0; i<v ; i++){
        for(int j=0; j<v ; j++){
            m[i][j] = 0;
        }
    }
}

void preencheRelacoes(int** m, int v, int& a){
    for(int i=0 ; i<v-1; i++){ // o ultimo vertice nao tem como se relaciona com outros
        for(int j=0; j<v ; j++){
            if((i != j) && (m[j][i] != 1)){
                cout << "\nO vertice " << i+1 << " possui relacao com vertice " << j+1 << "?\n";
                cout << "Resposta (1 ou 0): ";

                bool respostaRelacao; 
                cin >> respostaRelacao;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nErro: tipo de variavel invalido\n";
                }else{
                    if(respostaRelacao == true){ // possui relacao
                        m[i][j] = 1;
                        a++;
                    }
                }
            }
        }
    }
}

void filhosVertice(int** m, int v, int f[], int vD){
    int quantidade = 0;
    for(int i=vD; i<v ; i++){
        if(m[vD][i+1] == 1){
            f[quantidade] = i+1;
            quantidade++;
        }
    }
    if(quantidade == 0){
        cout << "\nVertice Desejado nao possui filhos\n";

    }else{
        cout << "Filhos de " << vD+1 << ": [ ";
        for(int i=0; i<quantidade ; i++){
            cout << f[i]+1 << " ";
        }
        cout << "]\n";
    }
}

void imprimeRelacoes(int** m , int v){
    cout << "\n :) ";
    for(int a=0; a<v ; a++){
        cout << "(" << a+1 << ") ";
    }
    cout << endl;
    for(int i=0; i<v ; i++){
        cout << "(" << i+1 << ")  "; 
        for(int j=0; j<v ; j++){
            cout << m[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}