#include "TAD.h"
#include <time.h>
#include <unistd.h>

int numeroAleatorio(int menor, int maior) {
    return rand()%(maior-menor+1) + menor;
}

int main(){
    fila f1;
    unsigned int tempo;
    int valor;
    bool ok;

    char inicio = 'a';
    srand((unsigned)time(0));

    system("clear");
    while(inicio != 'q'  && inicio != 'Q'){
        cout << "========================================================" << endl;
        cout << "                         Genius                         " << endl;
        cout << "========================================================" << endl;
        cout << endl << "Menu:" << endl;
        cout <<  "i/I - Iniciar" << endl;
        cout << "q/Q - Sair" << endl << endl << "R:";
        cin >> inicio;

        system("clear");

        char dificuldade = '0';
        if(inicio == 'i' || inicio == 'I'){
            while(dificuldade != '1' && dificuldade != '2' && dificuldade != '3'){
                cout << "========================================================" << endl;
                cout << "                         Genius                         " << endl;
                cout << "========================================================" << endl;
                cout << endl << "Dificuldade: " << endl;
                cout <<  "1 - Fácil" << endl;
                cout << "2 - Médio" << endl;
                cout << "3 - Difícil" << endl << endl << "R:";
                cin >> dificuldade;

                system("clear");
            }
            
            switch (dificuldade){
                case '1':
                    tempo = 2000000;
                    break;
        
                case '2':
                    tempo = 1000000;
                    break;
                case '3':
                    tempo = 500000;
                    break;
            }

            bool erro = false;

            for(int i = 0; i < 2; i++){
                int aleatorio = numeroAleatorio(1, 100);
                f1.fila::insere(aleatorio,&ok);
            }

            do{
                int aleatorio = numeroAleatorio(1, 100);
                f1.fila::insere(aleatorio,&ok);
                cout << "========================================================" << endl;
                cout << "                         Genius                         " << endl;
                cout << "========================================================" << endl;
                cout << endl << "Se prepare! Decore a sequência a baixo!" << endl << endl;
                usleep(2000000);
                system("clear");

                for(int i = 0; i < f1.fila::get_tamanho(); i++){
                    f1.fila::retira(&valor, &ok);

                    cout << "========================================================" << endl;
                    cout << "                         Genius                         " << endl;
                    cout << "========================================================" << endl;
                    cout << endl << "Se prepare! Decore a sequência a baixo!" << endl << endl;

                    usleep(100000);    

                    cout << valor << endl;  

                    usleep(tempo); 

                    system("clear");
                    f1.fila::insere(valor, &ok);
                }

                system("clear");
                cout << "========================================================" << endl;
                cout << "                         Genius                         " << endl;
                cout << "========================================================" << endl;
                cout << endl << "Legal! Agora digite a seqência!" << endl << endl;

                int contador = 0, valor_usuario;
                while(erro == false && contador < f1.fila::get_tamanho()){
                    contador++;
                    cout << "R: ";
                    cin >> valor_usuario;
                    f1.fila::retira(&valor, &ok);
                    if(valor != valor_usuario){
                        erro = true;
                    }
                    f1.fila::insere(valor, &ok);
                }

                system("clear");

                if(erro == false){
                    cout << "========================================================" << endl;
                    cout << "                         Genius                         " << endl;
                    cout << "========================================================" << endl;
                    cout << endl << "Parabéns! Você acertou a sequência!!!" << endl;
                    cout << "Vamos para a próxima rodada!" << endl;

                    usleep(2000000);

                    system("clear");
                }

                system("clear");
            }while(erro == false);

            char lixo;
            cout << "========================================================" << endl;
            cout << "                         Genius                         " << endl;
            cout << "========================================================" << endl;
            cout << endl << "Que pena, você perdeu ;(" << endl;
            cout << "Aperte qualquer tecla para ir ao menu." << endl << endl;
            cin >> lixo;
            system("clear");

            f1.fila::destroi();
        }
    }

    cout << "Jogo Encerrado!!!" << endl;
    return 0;
}
