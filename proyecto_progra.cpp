#include <iostream>
#include <iomanip>

using namespace std;
void mostrar_inventario();
void administrador();
void ventas();
int id[100] = {2, 4, 1, 3, 5};
string producto[100] ={"leche", "pan", "agua", "huevo", "refresco"};
float pc[100] = {12, 35, 5.5, 13.39, 22.4, 10.99};
float pv[100] = {15.5, 7.95, 18.95, 30.39, 14.55};
int existencias[100] = {16, 18, 12, 20, 30};
int nr[100] = {5, 6, 4, 7, 8};
int st[100] = {1, 1, 1, 1, 1};
int totalprod = 5;

int main() {
    int opcion;
    do{
        cout <<"menu principal" << endl;
        cout <<"1. administrador" << end;
        cout <<"2. ventas" << end;
        cout <<"3. salir" << end;
        cout <<"4. opcion" << end;
        cin >>opcion;
        switch (opcion){
            case 1: cout << "altas" endl;
                break;
            case 2: cout << "bajas" endl;
                break;
            case 3: cout << "consultas" << endl;
                break;
            case 4: cout << "modificaciones" << endl;
                break;
            case 5: cout << "mostrar inventario" << endl;
                    mostrar_inventario();
                break;
            case 6: cout << "administracion de cuentas de usuario" << endl;
                break;
            case 7: cout << "corte de caja general" << endl;
                break;
            case 8: cout << "volver al menu anterior" << endl;
                break;
            default: cout << "valor invalido" << endl << endl;
            }
    }while (opcion != 8);
}

void ventas() {
    cout <<"este menu es de ventas" << endl;
    
}

void mostrar_inventario(){
    int i;
    for(i=0; i<totalprod;i++)
    cout << setw(10) << id[i] << setw(10) << producto[i] << setw(10)
}