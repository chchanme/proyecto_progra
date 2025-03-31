#include <iostream>
#include <iomanip>

using namespace std;

void admin();
void ventas();
void ticket();
void corte_caja();
void mostrar_Inventario();
void altas();
void bajas();
void consultas();
void modificaciones();
int id[10] = {2,4,1,3,5};
string producto[10] = {"leche", "pan", "agua", "huevos", "refresco"};
string reo[10] = {5,6,4,7,8};//reorden
float pc[10] = {12.35,5.5,13.39,22.4,10.99};//precio de compra
float pv[10] = {15.5,7.95,18.55,30.39,14.75};//precio de venta
int Existencias[10] = {16,18,12,5,5};
int stat[10] = {1,1,1,1,1};//es el estatus
int loginadmin();
string usuarios[10]={"admin", "ventas1", "ventas2"};
int pass[10]={123,123,123};
int tipo[10]={1,2,3};
int st[10]={1,1,1};
int total_users=3;

int loginadmin() {
    string usuario_temp;
    int contra_temp;
    int i = 0; 
    cout << "usuario: ";
    cin >> usuario_temp;

    while(i < total_users && usuario_temp != usuarios[i]) {
        i++;
    }
    if(i < total_users && usuario_temp == usuarios[i]) {
        cout << "contraseña: ";
        cin >> contra_temp;

        if(pass_temp == pass[i]) {
            return 1; 
        } else {
            cout << "datos invalidos" << endl;
            return 0;
        }
    } else {
        cout << "Usuario no válido" << endl;
        return 0;
    }
}

int main() {
    int opcion;
    do {
        cout << "menu principal" << endl;
        cout << "1. administrador" << endl;
        cout << "2. ventas" << endl;
        cout << "3. salir" << endl;
        cout << " opcion: " << endl;
        cin >> opcion;
        switch (opcion) {
            case 1: administrador();
                    break;
            case 2: ventas();
                    break;
            default: cout << "datos incorrectos" << endl;
        }
    } while(opcion != 2);
    return 0;
}

void Administrador() int opcion;
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
}

void ticket() {
}

void corte() {
}

void altas() {
}

void Bajas() {
  
}

void Consultas() {
}

void Modificaciones() {
}


void Mostrar_Inventario() {
    }
   
