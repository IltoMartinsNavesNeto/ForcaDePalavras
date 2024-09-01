#include <iostream>
#include <stdlib.h>
#include <time.h>

    using namespace std;
    const int quant_palavras = 5;

    char banco[quant_palavras][30] = {
        "cachorro",
        "computador",
        "cadeira",
        "automovel",
        "edificio"
        };

    char palavraSort[30];
    char palavraDigitada[30];

    int sorteia() {
        srand (time(NULL));
        return rand() % (quant_palavras);
    }

    void imprimePalavra(int palavra) {
        for(int i = 0; i < 30; i++){
            cout <<  banco[palavra][i];
        }
    }

    void copia(int indice) {
        for(int i = 0; i < 30; i++){
            palavraSort[i] = banco[indice][i];
        }
    }

    void limpaPalavraDigitadas(){
        for(int i = 0; i< 30; i++){
            palavraDigitada[i] = '_';
        }
    }

    void imprimeForca(int letrasErradas) {
        switch(letrasErradas){
        case 1:
            cout<<"  ______";
            cout<<" |";
            cout<<" |";
            cout<<" |";
            cout<<" |";
                break;

        case 2:
            cout<<"  ______";
            cout<<" |     O ";
            cout<<" |      \\";
            cout<<" |";
            cout<<" |";
                break;

        case 3:
            cout<<"  ______";
            cout<<" |     O ";
            cout<<" |     |\\";
            cout<<" |";
            cout<<" |";
                break;

        case 4:
            cout<<"  ______";
            cout<<" |     O ";
            cout<<" |    /|\\";
            cout<<" |";
            cout<<" |";
                break;

        case 5:
            cout<<"  ______";
            cout<<" |     O ";
            cout<<" |    /|\\";
            cout<<" |      \\";
            cout<<" |       ";

                break;
        case 6:
            cout<<"  ______";
            cout<<" |     O ";
            cout<<" |    /|\\";
            cout<<" |    / \\";
            cout<<" |       ";
                break;

        }
    }

    int main() {
        limpaPalavraDigitadas(); // função para limpar vetor da palavra digitada


        contadorLetrasDigitadas = 0; // contador de letras digitadas
        int indicePalavra = sorteia(); // sortear uma palavra

        char letrasDigitadas[26];
        int contadorLetras = 0;

        while(contadorLetras <= 6){


        }


        return 0;

    }
