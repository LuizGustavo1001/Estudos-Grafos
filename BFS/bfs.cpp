#include <iostream>
using namespace std;

void preencheMatrizInicial(int** m, int v);

void menu();

void preencheRelacoes(int** m, int nV, int& nA);

void imprimeRelacoes(int** m , int v);

void filhosVertice(int** m, int v, int f[], int vD);

void BFS(int i, int f, int** m, int nV);

int main(){

     /*
     Possibilita Calcular(No momento):
        - Quantidade de Vértices
        - Quantidade de Arestas/arcos
        - Imprimir a matriz de relações do grafo
        - Identificar os filhos de um vértice no grafo
        - Calcular o menor caminho entre 2 arestas
    */

    cout << "                                         <Grafos em Algoritmos>\n";
    cout << "                                 Grafo: nao valorado e nao direcionado" << endl;

    int numVertices;

    cout << "Numero de Vertices: ";
    cin >> numVertices;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nErro: tipo de variavel invalido\n";
    }else{
        if(numVertices <= 0 ){
            cout << "\nErro: Numero de vertices precisa ser maior ou igual a 1\n";
        }else{
            // criando a matriz que armazena as relacoes entre os vertices
            int** relacoes = new int*[numVertices];
            for(int i=0; i<numVertices ; i++){
                relacoes[i] = new int[numVertices];
            }

            preencheMatrizInicial(relacoes, numVertices);

            cout <<"                                         <Preenchendo as Relacoes>\n";

            int numArestas = 0;

            preencheRelacoes(relacoes, numVertices, numArestas);

            int respostaInicial=0;

            do{
                menu();
                cin >> respostaInicial;
                switch(respostaInicial){
                    case 1:{ // G=(V,E)
                        cout << "\nG=(" << numVertices << "," << numArestas << ")\n";
                        cout << "Grafo possui " << numVertices << " vertices e" << numArestas << " arestas\n";
                        break;
                    }
                    case 2:{ //BFS entre 2 vertices
                        int verticeInicial;
                        cout << "-Distancia entre o vertice: ";
                        cin >> verticeInicial;

                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "\nErro: tipo de variavel invalido\n";
                        }else{
                            int verticeFinal;
                            cout << "-Ate o vertice: ";
                            cin >> verticeFinal;

                            if(cin.fail()){
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "\nErro: tipo de variavel invalido\n";
                            }else{
                                BFS(verticeInicial-1, verticeFinal-1, relacoes, numVertices);
                            }
                        }
                        break;
                    }
                    case 3:{ // imprimir a matriz de relacoes
                        cout << "\n<Matriz de Relacoes>\n";
                        imprimeRelacoes(relacoes, numVertices);
                        break;
                    }
                    case 4:{ // vizinhos/filhos de um vertice
                        cout << "\nVertice Desejado: ";
                        int verticeDesejado;
                        cin >> verticeDesejado;
                        if(cin.fail()){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "\nErro: tipo de variavel invalido\n";
                        }else{
                            int* filhos = new int[numVertices]; // maximo de filhos que um Vertice pode ter = numVertices-1
                            filhosVertice(relacoes, numVertices, filhos, verticeDesejado-1);
                        }
                        break;
                    }
                    case 5:{ // finalizar
                        cout << "\nPrograma Finalizando\n";
                        break;
                    }
                    default:{
                        cout << "\nErro: resposta fora do intervalo de validacao, retornando ao comeco do codigo\n";
                        break;
                    }
                }
            }while(respostaInicial != 5);
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

void menu(){
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout << "\n1) Definicao do grafo\n";
    cout << "2) BFS entre 2 vertices\n";
    cout << "3) Imprimir Matriz de relacoes\n";
    cout << "4) Identificar filhos/vizinhos de um vertice\n";
    cout << "5) Finalizar programa\n";
    cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";

    cout << "Resposta ( 1 ate 4 ): ";

}

void preencheRelacoes(int** m, int nV, int& nA){
    for(int i=0; i<nV ; i++){
        for(int j=0; j<nV ; j++){
            if((i != j) and (m[j][i] != 1)){
                cout << "\nVertice " << i+1 << " possui relacao com vertice " << j+1 << " ?\n";
                cout << "Resposta( 1 ou 0 ): ";
                bool respostaRelacoes;
                cin >> respostaRelacoes;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "\nErro: tipo de variavel invalido - Considerando que nao ha relacao\n";
                }else{
                    if(respostaRelacoes == true){// possui relacao
                        m[i][j] = 1;
                        nA++; // cada relacao representa uma aresta do grafo
                    }
                }
            }
        }
    }
    cout << "                                         <Relacoes Preenchidas>\n";
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

void filhosVertice(int** m, int v, int f[], int vD){
    int quantidade = 0;
    for(int i=0; i<v ; i++){
        if(m[vD][i] == 1){
            f[quantidade] = i+1;
            quantidade++;
        }
    }
    if(quantidade == 0){
        cout << "\nVertice " << vD+1 << " nao possui filhos\n";
    }else{
        cout << "\nFilhos de " << vD+1 << ": [ ";
        for(int i=0; i<quantidade ; i++){
            cout << f[i] << " ";
        }
        cout << "]\n";
    }
}


void BFS(int i, int f, int** m, int nV){
    if(m[i][f] == 1){ 
        // f eh filho de i
        cout << "Como " << f+1 << " eh filho de " << i+1 << ", Distancia = 1" << endl;
    }else{ // f nao possui ligacao direta com i
        int* distancias = new int[nV];
        int dis = 0;
        for(int j=0; j<nV ; j++){
            distancias[j] = 0;
        }

        for(int j=0; j<nV ; j++){
            if(m[i][j] == 1){ // j eh filho de i
                int novoI = j;
                int k = 0;
                while((k < nV) and (novoI != f)){
                    if(m[novoI][k] == 1){
                        distancias[dis] += 1;
                        novoI = k;
                        k = 0;
                    }else{
                        k++;
                    }
                }
                dis++;
            }
        }
        if(distancias[0] == 0){ // nao foi detectado nenhum caminho possível de I para F
            cout << "\nNenhum caminho possivel detectado de " << i+1 << " para " << f+1 << endl;
        }else{
            int menorDistancia = distancias[0];
            for(int l=0; l<nV ; l++){
                if((distancias[l] <  menorDistancia) and (distancias[l] != 0)){
                    menorDistancia = distancias[l];
                }
            }
            cout << "Menor distancia entre " << i+1 << " e "<< f+1  << ": "<< menorDistancia+1 << " ";
        }
        delete[] distancias;
    }
}