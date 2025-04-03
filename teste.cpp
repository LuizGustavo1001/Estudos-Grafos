#include <iostream>
using namespace std;

void preencheInicial(int** m, int nV);

void imprimeRelacoes(int** m, int nV);

void BFS(int i, int f, int** m, int nV);

int main(){
    int numVertices=5;
    int** relacoes = new int*[5];

    for(int i=0; i<numVertices ; i++){
        relacoes[i] = new int[numVertices];
    }

    preencheInicial(relacoes, numVertices);
    relacoes[0][2] = 1;
    relacoes[0][4] = 1;
    relacoes[1][3] = 1;
    relacoes[2][1] = 1;
    relacoes[4][3] = 1;

    imprimeRelacoes(relacoes, numVertices);

    cout << "Inicio: ";
    int inicio;
    cin >> inicio;

    cout << "Fim: ";
    int fim;
    cin >> fim;
    inicio--;
    fim--;
    BFS(inicio, fim, relacoes, numVertices);

    return 0;
}


void preencheInicial(int** m, int nV){
    for(int i=0; i<nV ; i++){
        for(int j=0; j<nV ; j++){
            m[i][j] = 0;
        }
    }
}

void imprimeRelacoes(int** m, int nV){
    for(int i=0; i<nV ; i++){
        for(int j=0; j<nV ; j++){
           cout << m[i][j] <<  " ";
        }
        cout << endl;
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
            cout << "Menor distancia entre " << i+1 << " e "<< f+1  << ": "<< menorDistancia << " ";
        }
        delete[] distancias;
    }
}