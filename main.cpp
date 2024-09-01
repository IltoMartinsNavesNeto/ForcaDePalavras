#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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

    void imprimePalavraDigitada() {
        cout << "\n     "<<strlen(palavraSort)<<" letras \n\n    ";
        for(int i = 0; i < strlen(palavraSort); i++){
            cout <<  palavraDigitada[i] << " ";
        }
    }

    void copia(int indice) {
        for(int i = 0; i < 30; i++){
            palavraSort[i] = banco[indice][i];
        }
    }

    void limpaPalavraDigitadas(){
        for(int i = 0; i< strlen(palavraSort); i++){
            palavraDigitada[i] = '_';
        }
    }

    void imprimeForca(int letrasErradas) {
        switch(letrasErradas){
         case 0:
            cout<<"  _____ "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 1:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 2:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |    | "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 3:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /| "<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 4:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |      "<<endl;
            cout<<" |      "<<endl;
            break;
        case 5:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   /  "<<endl;
            cout<<" |      "<<endl;
            break;
        case 6:
            cout<<"  _____ "<<endl;
            cout<<" |    O "<<endl;
            cout<<" |   /|\\"<<endl;
            cout<<" |   / \\"<<endl;
            cout<<" |       "<<endl;
            break;
        }
    }

    bool verificaLetra(char letra, char vetor[26]) {
        for(int i = 0; i<strlen(vetor); i++) {
            if (letra == vetor[i]){
                return true;
            }
        }
        return false;
    }

    void substitui (char letra) {
        for(int i = 0; i<strlen(palavraDigitada); i++) {
            if (palavraSort[i] == letra){
                palavraDigitada[i] = letra;
            }
        }
    }

    void imprimeLetrasDigitadas(char letras[26], int tamanho) {
        cout << "\n\nLetras digitdas: ";
        for(int i = 0;i < tamanho; i++){
            cout << letras[i] << ", ";
        }
        cout << "\n\n";
    }

    bool palavraCompleta(){
        for(int i =0; i< strlen(palavraSort);i++){
            if(palavraDigitada[i] == '_'){
                return false;
            }
        }
        return true;
    }

    int main() {


        int indicePalavra = sorteia(); // sortear uma palavra

        copia(indicePalavra);

        limpaPalavraDigitadas(); // função para limpar vetor da palavra digitada

        int contadorLetrasDigitadas = 0; // contador de letras digitadas


        char letrasDigitadas[26];
        int contadorLetras = 0;
        int contadorErros = 0;
        char letra;

        while(contadorErros < 6){
            system("cls");
            imprimeForca(contadorErros);
            imprimePalavraDigitada();
            imprimeLetrasDigitadas(letrasDigitadas, contadorLetrasDigitadas);
            cout << "\n\n Tentativas restantes: " << 6-contadorErros<<"\n\n";
            cout << "\n\n";
            cout << "Digite uma letra: ";
            cin >> letra;
            letra = tolower(letra);
            if(verificaLetra(letra, letrasDigitadas)){
                cout << "Letra ja foi digitada! Tente novamente!\n\n";
                system("pause");
            }
            else{
                letrasDigitadas[contadorLetrasDigitadas] = letra;
                contadorLetrasDigitadas++;

                if(verificaLetra(letra, palavraSort)) {
                    substitui(letra);
                }else{
                    cout << "\nLetra incorreta! Tente novamente!\n\n";
                    contadorErros++;
                    system("pause");
                }
            }

            if(contadorErros >= 6){
                system("cls");
                cout << "\n\n\tSuas tentativas acabaram!\n Reinicie para tentar novamente\n";
                system("pause");
                return 0;
            }
            if(palavraCompleta()){
                cout << "\n\n\tPARABENS \n VOCE ACERTOU A PALAVRA!\n";
                system("pause");
                return 0;
            }
        }


        return 0;

    }
