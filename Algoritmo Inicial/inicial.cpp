#include <iostream>
using namespace std;

void preencheMatrizInicial(int** m, int v);

void preencheRelacoes(int** m, int v, int& a);

void imprimeRelacoes(int** m , int v);

void filhosVertice(int** m, int v, int f[], int vD);

//void BFS(int** m, int nV, int vI, int vF);

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
                    if(respostaFilhos == 1){
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
                }
                /*
                cout << "\n-Calcular distancia entre 2 pontos no Grafo\n";
                cout << "Resposta( 1 ou 0 ): ";
                bool respostaBFS;
                cin >> respostaBFS;

                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nErro: tipo de variavel invalido\n";
                }else{
                    if(respostaBFS == true){
                        int primeiroVertice;
                        int segundoVertice;

                        cout << "Primeiro: ";
                        cin >> primeiroVertice;

                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "\nErro: tipo de variavel invalido ->  Nao foi possivel realizar a BFS\n";
                        }else{
                            cout << "Segundo: ";
                            cin >> segundoVertice;

                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\nErro: tipo de variavel invalido ->  Nao foi possivel realizar a BFS\n";
                            }else{
                                primeiroVertice--;
                                segundoVertice--;
                                BFS(relacoes, numVertices, primeiroVertice, segundoVertice);
                            }
                        }    
                    }
                }
                */

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
    for(int i=0 ; i<v; i++){
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
    for(int i=0; i<v ; i++){
        if(m[vD][i] == 1){
            f[quantidade] = i+1;
            quantidade++;
        }
    }
    if(quantidade == 0){
        cout << "\nVertice Desejado nao possui filhos\n";

    }else{
        cout << "Filhos de " << vD+1 << ": [ ";
        for(int i=0; i<quantidade ; i++){
            cout << f[i] << " ";
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

/*

void BFS(int** m, int nV, int vI, int vF){
    
    if(m[vI][vF] == 1){
        cout << "\nDistancia de " << vI+1 << " ate " << vF+1 << ": 1 unidade de medida(filho)\n"; 
    }else{
        int distancias[nV];

        for (int i = 0; i < nV; i++) {
            distancias[i] = 0;
        }

        int i = vI;
        int j = 0;
        while((vI != vF)){
            if(m[vI][i] == 1){ // achou um filho
                int novoI = 0;
                int novoVI = i; // novo vertice inicial indicando o caminho que deve ser seguido

                distancias[j] += 1;
                while(novoVI != vF){ // achar o caminho do filho ate o vertice desejado e armazenar no vetor de distancias
                    if(m[novoVI][novoI] == 1){
                        novoVI = novoI;
                        distancias[j] += 1;
                        novoI=0;
                    }else{
                        novoI++;
                    }
                }
                j++; // proximo filho que o vertice pode ter
                i++;
            }else{
                i++;
            }
        }
        cout << endl;
        int menorDistancia = distancias[0];
        for(int i=0; i<nV; i++){
            if((distancias[i] < menorDistancia) and (distancias[i]!= 0)){
                menorDistancia = distancias[i];
            }

        }
        cout << "Menor distancia entre o vertice " << vI+1 << " e o vertice " << vF+1 << ": " << menorDistancia << endl;
        
        if(menorDistancia == -1){
            cout << "\nVertice " << vI+1 << " nao possui ligacao com o vertice " << vF+1 << endl;
        }
    }
}

*/