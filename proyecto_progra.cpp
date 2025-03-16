#include <iostream>
#include <iomanip>

using namespace std;
void consultas();
void mostrar_inventario();
void administrador();
void ventas();
void altas();
int id[100] = {2, 4, 1, 3, 5};
string producto[100] ={"leche", "pan", "agua", "huevo", "refresco"};
float pc[100] = {12, 35, 5.5, 13.39, 22.4, 10.99};//precio de compra
float pv[100] = {15.5, 7.95, 18.95, 30.39, 14.55};//precio de venta
int existencias[100] = {16, 18, 12, 20, 30};
int nr[100] = {5, 6, 4, 7, 8};//numero de reorden
int st[100] = {1, 1, 1, 1, 1};//estatus
int total_prod = 5;

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
                    altas();
                break;
            case 2: cout << "bajas" endl;
                break;
            case 3: cout << "consultas" << endl;
                    consultas();
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
void altas(){
     string Prod_temp;
    int i,indice,opcion;
    while(true){
        i=totalprod;
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){
            break;
        }
        indice = Buscar(Prod_temp);
        if(indice == -1){
        producto[i] = Prod_temp;
        cout<<"Id: ";
        cin>>id[i];
        cout<<"Precio de compra: ";
        cin>>pc[i];
        cout<<"Precio de venta: ";
        cin>>pv[i];
        cout<<"Existencias: ";
        cin>>existencias[i];
        cout<<"nivel de reorden: ";
        cin>>nr[i];
        st[i]=1;
        totalprod++;
        }else
            if(st[indice]==0){
            cout<<"El producto ya existe pero dado de baja,Desea darlo de alta? (1=Si,0=No)"<<endl;
            cin>>opcion;
                if(opcion==1){
                    st[i]=1;
                    cout<<"Producto dado de alta"<<endl;
                }else;
        }else{
            cout<<"Producto Ya existente"<<endl;
        }
    }
}
void consultas(){
    string prod_temp;
    int i;
    int indice;
    i = totalprod;
    while(true){
        i=0;
        cout << "producto:";
        cin >> prod_temp;
        if (prod_temp == "*")
            break;
        while (i < totalprod && prod_temp != producto[i]) {
            i++;
        if (i == totalprod)
            cout << "producto no existente";
        else { 
            cout << setw(10) << id[i] << setw(10) << producto[i] << setw(10)
            }
        }
    }
}

void mostrar_inventario(){
    int i;
    for(i=0; i<totalprod;i++)
    cout << setw(10) << id[i] << setw(10) << producto[i] << setw(10)
}

void Bajas(){
    string Prod_temp;
    int i,indice;
    while(true){
        i=0;
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){
            break;
        }
        indice=Buscar(Prod_temp);
        if(indice==-1){
            cout<<"Producto no encontrado"<<endl;
        }else
            if(st[indice]==0){
                cout<<"El producto ya esta  dado de baja"<<endl;
        }else{
            st[indice] = 0;
            cout<<"Producto dado de baja"<<endl;
        }
    }
}
