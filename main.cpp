//PROYECTO FINAL
//FUNDAMENTOS DE PROGRAMACION
//CESAR ARTURO MARTINEZ VALENZUELA
//A00517067
#include <iostream>
#include <ctime>
using namespace std;
char cMatTablero[5][8];
char cArrFiguras[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//LLENA LA MATRIZ CON LETRAS AL AZAR
void llenaTablero()
{
    int iR, iC, iContFicha, iValorFicha;
    
    // primero inicializa el arreglo con espacios en blanco
    for (iR = 0; iR < 5; iR++)
        for (iC = 0; iC < 8; iC++)
            cMatTablero[iR][iC] = ' ';
    
    srand((int)time(0));
    for (iValorFicha = 0, iContFicha = 0; iValorFicha < 10;
         iContFicha = 0, iValorFicha++)
    {
        do
        {
            iR = rand() % (5);
            iC = rand() % (8);
            if (cMatTablero[iR][iC] == ' ')
            {
                cMatTablero[iR][iC] = cArrFiguras[iValorFicha];
                iContFicha++;
            }
        } while (iContFicha != 4); // debo poner 4 Fichas de cada numero
    }
}
//IMPRIME EL TABLERO DE JUEGO
void imprimirTablero(){
    int num = 1;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++)
        {
            //PARA COMPENSAR POR EL ESPACIO EN BLANCO DE LOS NUMEROS DE UN SOLO DIGITO
            if(num < 10){
                cout << "( " << num << ") " << cMatTablero[i][j] << " ";
            }
            else{
                cout << "(" << num << ") " << cMatTablero[i][j] << " ";
            }
            num++;
        }
        cout << endl;
    }
}
//CHECAR SI ESTA LIBRE
bool libre(int fila, int columna){
    if(columna==0||columna==7){
        return true;
    }
    if(cMatTablero[fila][columna-1]==' '||cMatTablero[fila][columna+1]==' '){
        return true;
    }
    return false;
}
//CHECAR SI LAS FICHAS SELECCIONADAS SON VALIDAS
bool valida(int a,int b){
    if((a<1 || a>40)||(b<1 || b>40)){
        cout<<"LA FICHA NO EXISTE"<<endl;
        return false;
    }
    if(a==b){
        cout<<"LAS FICHAS INGRESADAS SON LA MISMA"<<endl;
        return false;
    }
    int afila = (a-1)/8;
    int acolumna = a-(afila*8)-1;
    if(cMatTablero[afila][acolumna]==' '){
        return false;
    }
    int bfila = (b-1)/8;
    int bcolumna = b-(bfila*8)-1;
    if(cMatTablero[bfila][bcolumna]==' '){
        return false;
    }
    if(cMatTablero[afila][acolumna]!=cMatTablero[bfila][bcolumna]){
        return false;
    }
    if(libre(afila,acolumna)==false or libre(bfila,bcolumna)==false){
        return false;
    }
    return true;
}
int main(){
    int ficha1,ficha2,fichasRestantes=40;
    char continuar;
    llenaTablero();
    do{
        imprimirTablero();
        cout<<"QUEDAN "<<fichasRestantes<<" FICHAS"<<endl;
        cout<<"FICHA 1: "<<endl;
        cin>>ficha1;
        cout<<"FICHA 2: "<<endl;
        cin>>ficha2;
        if(valida(ficha1,ficha2)==true){
            fichasRestantes-=2;
            int fila1 = (ficha1-1)/8;
            int col1 = ficha1-(fila1*8)-1;
            cMatTablero[fila1][col1]=' ';
            int fila2 = (ficha2-1)/8;
            int col2 = ficha2-(fila2*8)-1;
            cMatTablero[fila2][col2]=' ';
            imprimirTablero();
            cout<<"QUEDAN "<<fichasRestantes<<" FICHAS"<<endl;
            if(fichasRestantes==0){
                cout<<"JUEGO COMPLETADO. BIENVENIDO A HARVARD"<<endl;
                cout<<"INGRESA N PARA SALIR DEL JUEGO"<<endl;
            }
        }
        else
            cout<<"NEL ESTA MAL"<<endl;
        cout<<"LE QUIERES SEGUIR? (s/n): ";
        cin>>continuar;
        continuar=tolower(continuar);
    }while(continuar=='s');
    return 0;
}

