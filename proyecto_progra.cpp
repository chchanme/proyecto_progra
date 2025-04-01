#include <iostream>
#include <iomanip>

using namespace std;

//Prototipos void que pasan de los globales a lista de esructura y viceversa
void Globales_a_Lista();
void Lista_a_Globales();
//Prototipos void para copiar los globales a arreglo de estructura
void Editar_Inventario();
void Editar_Usuarios();
//Protoipos void
void Administrador();
void Administracion_cuentas_usuario();
void Mostrar_Inventario();
void ventas();
void Altas();
void Consultas();
void Bajas();
void Modificaciones();
void Contrasenia_Admin();
void Contrasenia_Vendedor();
void Altas_usuario();
void Bajas_usuario();
void Consultas_usuario();
void Modificaciones_usuario();
void Mostrar_usuario();
void Corte_Caja();
//Prototipos Int para buscar dentro de Arreglos de estructuras
int Buscar_Invent(string);
int Buscar_user(string);
//Prototpios void para buscar en los globales
int Buscar(string);

//Estructuras
struct inventario{
    int id;
    string producto;
    float PC;
    float PV;
    int existencias;
    int nivr;
    int st;
    //Apuntador interno de inventario para crear nuevos Nodos
    inventario *sig;
}Productos[100];
//Apuntadores de inventario
inventario *Inicio=NULL;
inventario *Fin=NULL;
inventario *Nuevo=NULL;
inventario *Temp=NULL;

//Arreglo de estructura de usuarios
struct Usuarios{
    string usuarios;
    int pass;
    int tipo;
    int status;
}users[100];


//variables globales inventario
int id[100]={2,4,1,3,5};
string producto[100]={"Leche","Pan","Agua","Huevos","Refresco"};
float PC[100]={12.35,5.5,13.39,22.4,10.99};
float PV[100]={15.5,7.95,18.55,30.39,14.75};
int existencias[100]={16,18,12,20,20};
int nivr[100]={5,6,4,7,8};
int st[100]={1,1,0,1,0};
int ingresos = 0;
int egresos = 0;
int totalprod = 5;
//Variables globales usuarios
string usuarios[10]={"admin","vend1","vend2"};
int pass[10]={123,123,123};
int tipo[10]={1,2,2};
int status[10]={1,1,1};
int total_user=3;


int main()
{
    Globales_a_Lista(); //Se llama la funcion para copiar de los globales a la lista de estructura, esto es para la funcion de altas
    int opcion;
    do{
        cout << "Menu principal." << endl;
        cout << "1. Administrador" << endl;
        cout << "2. Ventas" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin>> opcion;
        switch(opcion){
            case 1:Contrasenia_Admin();//se llama a la contraseña de administrador
                   break;
            case 2:Contrasenia_Vendedor();//Se llama a la contraseña de vendedor
                   break;
            case 3:cout << "Cerrando Sistema." << endl; //Se cierra el sistema
                   break;
            default: cout << "Opción inválida." << endl; //Mensaje cuando se ingresa cualquier otro numero
        }

    }while(opcion != 3);//Metodo while para que cuando se ingrese 3 se cierre el sistema

    return 0;
}

void Lista_a_Globales(){ //Funcion para copiar los datos de la lista de estructura a los globales
    int i = 0;
    Temp = Inicio;
    while(Temp!=NULL){//mientras Temp no llege a ser null pasara todos los datos de la lista a los globales
        id[i] = Temp->id;
        producto[i] = Temp->producto;
        PC[i] = Temp->PC;
        PV[i] = Temp->PV;
        existencias[i] = Temp->existencias;
        nivr[i] = Temp->nivr;
        st[i] = Temp->st;
        Temp = Temp->sig;
        i++;//Se aumenta i con eso la posicion en donde se guarda
    }
    totalprod = i;//Se actualiza el total de productos
}

void Globales_a_Lista(){//Metodo para que los globales se pasen a una lista de estructura
    int i;
    for(i=0;i<totalprod;i++){ //Metodo for para copiar todos los arreglos globales
        Nuevo =new(inventario); //Se crea un nuevo nodo de inventario
        Nuevo->producto = producto[i];
        Nuevo->id = id[i];
        Nuevo->PC = PC[i];
        Nuevo->PV = PV[i];
        Nuevo->existencias = existencias[i];
        Nuevo->nivr = nivr[i];
        Nuevo->st = st[i];
        Nuevo->sig=NULL;
        if(Inicio == NULL) { //se checa si inicio no es igual a null dando a entender si inicio no tiene aun un nodo
            Inicio = Nuevo;
            Fin = Nuevo;
        } else {
            Fin->sig = Nuevo; //fin se va cambiando de posicion hasta el ultimo elemento
            Fin = Nuevo;
        }
    }
}

void Administrador(){
    int opcion;
    do{
        cout << "Administrador." << endl;
        cout << "1. Altas" << endl;
        cout << "2. Bajas" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Modificaciones" << endl;
        cout << "5. Mostrar inventario" << endl;
        cout << "6. Administracion de cuentas de usuario" << endl;
        cout << "7. Corte de caja general" << endl;
        cout << "8. Regresar al Menu anterior" << endl;
        cout << "Opcion: ";
        cin>> opcion;
        switch(opcion){
            case 1: Altas();
                    break;
            case 2: Bajas();
                    break;
            case 3: Consultas();
                    break;
            case 4: Modificaciones();
                    break;
            case 5: Mostrar_Inventario();
                    break;
            case 6: Administracion_cuentas_usuario();
                    break;
            case 7: Corte_Caja();
                    break;
            case 8:
                    break;
            default: cout << "Opcion invalida." << endl;
        }
    }while(opcion != 8);
}

void Contrasenia_Vendedor(){
    string usuario_temp;
    int i;
    int pass_temp;
    cout<<"Usuario: ";
    cin>>usuario_temp;
    while(i<total_user && usuario_temp != usuarios[i]) //Metodo para buscar el usuario en el arreglo
        i++;
    if(usuario_temp == usuarios[i]){
        cout<<"Contraseña: ";
        cin>>pass_temp;
        if(pass_temp==pass[i]){ //se valida si la contraseña es correcta
            if(tipo[i]==1){ // Revisa si el tipo es 1(administrador) en caso de que lo sea no lo dejara entrar
                cout<<"Este usuario no tiene permitido entrar a esta area."<<endl;
            }else{
                ventas(); //se llama la funcion
            }
        }else{
            cout<<"Contraseña incorrecta."<<endl;//Cuando la contraseña no es igual
        }
    }else{
        cout<<"usuario no valido."<<endl; //Cuando no se encuentra el usuario
    }
}

void Contrasenia_Admin(){
    string usuario_temp;
    int i;
    int pass_temp;
    cout<<"Usuario: ";
    cin>>usuario_temp;
    while(i<total_user && usuario_temp != usuarios[i]) //Metodo para buscar el usuario en el arreglo
        i++;
    if(usuario_temp == usuarios[i]){
        cout<<"Contraseña: ";
        cin>>pass_temp;
        if(pass_temp==pass[i]){
            if(tipo[i]==2){ //se revisa si el usuario no es vendedor si lo es no se le permite entrar
                cout<<"Este usuario no tiene permitido entrar a esta area."<<endl;
            }else{
                Administrador();
            }
        }else{
            cout<<"Contraseña incorrecta."<<endl;
        }
    }else{
        cout<<"usuario no valido."<<endl;
    }
}

void Administracion_cuentas_usuario(){
    int opcion;
    do{
        cout << "Administracion cuentas de usuario." << endl;
        cout << "1. Altas" << endl;
        cout << "2. Bajas" << endl;
        cout << "3. Consultas" << endl;
        cout << "4. Modificaciones" << endl;
        cout << "5. Mostrar cuentas de usuario" << endl;
        cout << "6. Regresar al menu anterior" << endl;
        cout << "Opcion: ";
        cin>> opcion;
        switch(opcion){
            case 1: Altas_usuario();
                    break;
            case 2: Bajas_usuario();
                    break;
            case 3: Consultas_usuario();
                    break;
            case 4: Modificaciones_usuario();
                    break;
            case 5: Mostrar_usuario();
                    break;
            case 6:
                    break;
            default: cout << "Opcion invalida." << endl;
        }
    }while(opcion != 6);
}

void Altas(){
    string Prod_temp;
    int i,indice,opcion;
    while(true){
        i=totalprod;
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){ //si se pone asterisco se cierra el menu de Altas
            break;
        }
        indice = Buscar(Prod_temp); //Con la funcion buscar, se busca el producto en el arreglo global
        if(indice == -1){
            Nuevo = new(inventario); //Cuando no se encuentra, significa que se puede agregar
            Nuevo->producto= Prod_temp;//Se crea un nodo nuevo en la lista de estructura guardando los datos del producto
            cout<<"Id: ";
            cin>> Nuevo->id;
            cout<<"Precio de compra: ";
            cin>>Nuevo->PC;
            cout<<"Precio de venta: ";
            cin>>Nuevo->PV;
            cout<<"Existencias: ";
            cin>>Nuevo->existencias;
            cout<<"Nivel de reorden: ";
            cin>>Nuevo->nivr;
            Nuevo->st = 1;
            Nuevo->sig=NULL;
            if(Inicio==NULL){ //se checa si inicio no es igual a null dando a entender si inicio no tiene aun un nodo
                Inicio = Nuevo; //Si es nulo inicio y fin seran igual a nuevo
                Fin = Nuevo;
            }else{
                Fin->sig = Nuevo; //sino fin se cambia d eposicion hasta la ultima de la lista
                Fin = Nuevo;
            }
            Lista_a_Globales(); //Funcion para que se actualicen los arreglo
        }else
            if(st[indice]==0){ //Si el estatus es 0 se pregunta si se desea cambiarlo
                cout<<"El producto ya existe pero dado de baja,Desea darlo de alta? (1=Si,0=No)"<<endl;
                cin>>opcion;
                if(opcion==1){
                    st[indice]=1;
                    cout<<"Producto dado de alta"<<endl; //Mensaje cuando se escribe 1 en el codigo
                }else;
        }else{
            cout<<"Producto Ya existente"<<endl;
        }
    }
}

void Editar_Usuarios(){ //Funcion para copiar los arreglos globales a un arreglo de estructura
    int i;
    for(i=0;i<total_user;i++){ //Ciclo for para copiar los datos
        users[i].usuarios = usuarios[i];
        users[i].pass = pass[i];
        users[i].tipo = tipo[i];
        users[i].status = status[i];
    }
}

void Editar_Inventario(){ //Funcion para copiar los datos de los arreglos de inventario a uno de estructura
    int i;
    for(i=0;i<totalprod;i++){
        Productos[i].id = id[i];
        Productos[i].producto = producto[i];
        Productos[i].PC = PC[i];
        Productos[i].PV = PV[i];
        Productos[i].existencias = existencias[i];
        Productos[i].nivr = nivr[i];
        Productos[i].st = st[i];
    }
}

void Bajas(){
    string Prod_temp;
    while(true){
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){
            break;
        }
        Temp=Inicio; //Usando listas de estructura se buscara el producto, primero con un apuntador temp se vuelve igual a inicio
        while(Temp!=NULL && Temp->producto != Prod_temp){
            Temp=Temp->sig; //Temp recorrera cada nodo de la lista hasta que deje de ser diferente a nulo y diferente del producto que se ingreso
        }
        if(Temp==NULL){
            cout<<"Producto no encontrado"<<endl;//en caso de que llegue a ser nulo es que no se encontro
        }else
            if(Temp->st==0){
                cout<<"El producto ya esta  dado de baja"<<endl; //Si el estatus esta dado de baja se mandara este mensaje
            }else{
                Temp->st = 0;
                cout<<"Producto dado de baja"<<endl; //Si no esta ya dado de baja se da de baja
            }
        Lista_a_Globales(); //Se actualizan los arreglos globales
    }
}

void Bajas_usuario(){
    string User_temp;
    int i,indice,opcion;
    while(true){
        i=total_user;
        cout<<"Usuario: ";
        cin>>User_temp; //Todos los temp son variables que unicamente se usan para editar o buscar
        if(User_temp == "*"){
            break;
        }
        indice = Buscar_user(User_temp); //se usa la funcion buscar para encontrar al usuario
        if(indice == -1){
            cout<<"Usuario no encontrado."<<endl;
        }else
            if(status[indice]==0){
                cout<<"EL usuario ya esta dado de baja."<<endl;
            }else{
                status[indice] = 0;
                cout<<"Usuario dado de baja."<<endl;
            }
    }
}

void Consultas_usuario(){
    Editar_Usuarios(); //Se llama desde un inicio a la funcion de editar usuarios que copia los arreglos globales a un arreglo estructuraro
    string User_temp;
    int i,indice,opcion;
    while(true){
        i=total_user;
        cout<<"Usuario: ";
        cin>>User_temp;
        if(User_temp == "*"){ //Si se da asterisco se cierra la funcion
            break;
        }
        indice = Buscar_user(User_temp); //se llama la funcion de Buscar para el producto
        if(indice==-1){
            cout<<"Usuario no encontrado."<<endl; //si no se encuentra
        }else
            if(users[indice].status==1){ //En caso de que se encuentre se usa el arreglo estructuraro para mostrar el usuario
                cout<<"Usuario"<<setw(10)<<"Contrasenia"<<setw(19)<<"Tipo"<<setw(10)<<"Status"<<endl;
                cout<<users[indice].usuarios<<setw(10)<<users[indice].pass<<setw(10)<<users[indice].tipo<<setw(10)<<users[indice].status<<endl;
            }else{
                cout<<"Usuarios dados de baja no se pueden consultar."<<endl;
            }
    }
}

void Consultas(){
    Editar_Inventario(); //Se llama a editar inventario para copiar al arreglo estructurado los arreglos globales
    string Prod_temp;
    int i;
    int indice;
    while(true){
        i=0;
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){
            break;
        }
        indice=Buscar_Invent(Prod_temp); // Se llama a buscar para encontrar el producto
        if(indice==-1){
            cout<<"Producto no encontrado"<<endl; //Cuando no se encuentra
        }else
            if(Productos[indice].st==1){ //Si se encuentra se usa el arreglo de estructura para mostrar el prodcto
            cout<<"ID"<<setw(10)<<"Producto"<<setw(10)<<"PC"<<setw(8)<<"PV"<<setw(15)<<"Existencias"<<setw(15)<<"Niv.Reorden"<<setw(12)<< "Status" <<endl;
            cout<< Productos[indice].id<<setw(10)<<Productos[indice].producto<<setw(11)<<Productos[indice].PC<<
            setw(10)<<Productos[indice].PV<<setw(10)<<Productos[indice].existencias<<setw(13)<<Productos[indice].nivr<<setw(15)<< Productos[indice].st <<endl;
        }else{
            cout<<"Productos dados de baja no se pueden consultar."<<endl;
        }
    }
}

void Mostrar_usuario(){
    Editar_Usuarios(); //Se llama a la funcion para que copie los arreglos globales al estructurado
    int i;
    cout<<setw(40)<<"Mostrar inventario."<<endl;
    cout<<"Usuario"<<setw(10)<<"Contrasenia"<<setw(10)<<"Tipo"<<setw(10)<<"Status"<<endl;
    for(i=0;i<total_user;i++) //Se usa un ciclo for con el que mientras i sea menor al total de usuarios imprimira cada usuario
        if(users[i].status==1)
        cout<<users[i].usuarios<<setw(10)<<users[i].pass<<setw(10)<<users[i].tipo<<setw(10)<<users[i].status<<endl;
    cout<<endl;
}

void Corte_Caja(){
    cout<<setw(40)<<"Corte de caja general."<<endl;
    cout<<"Ingresos: "<<ingresos<<endl;
    cout<<"Egresos: "<<egresos<<endl;
    cout<<"Utilidad: "<<ingresos - egresos<<endl;
}

void Mostrar_Inventario(){
    Editar_Inventario(); //Se llama a la funcion para que copie los arreglos globales a estructurado
    int i,j,opcion;
    cout<<setw(40)<<"Mostrar inventario."<<endl;
    cout<<"Ordenado por:"<<endl;
    cout<<"1.Por Id."<<endl;
    cout<<"2.Por Producto"<<endl;
    cout<<"3.Regresar al menu anterior"<<endl;
    cout<<"Opcion: ";
    cin>>opcion;
    switch(opcion){ //Si se selecciona ordenado por id se usa un for anidado junto con el swap para ordenarlos
        case 1: for(i=0;i<totalprod-1;i++){
                    for(j=0;j<totalprod-i-1;j++){
                        if(Productos[j].id>Productos[j+1].id){ //esto se revisa que si el id es mayor a la posicion siguiente se cambia
                            swap(Productos[j].id, Productos[j + 1].id);
                            swap(Productos[j].producto, Productos[j + 1].producto);
                            swap(Productos[j].PC, Productos[j + 1].PC);
                            swap(Productos[j].PV, Productos[j + 1].PV);
                            swap(Productos[j].existencias, Productos[j + 1].existencias);
                            swap(Productos[j].nivr, Productos[j + 1].nivr);
                            swap(Productos[j].st, Productos[j + 1].st);
                        }
                    }
                }
                cout<<"ID"<<setw(10)<<"Producto"<<setw(10)<<"PC"<<setw(8)<<
                "PV"<<setw(15)<<"Existencias"<<setw(15)<<"Niv.Reorden"<<setw(12)<<
                 "Status"<<setw(10)<<"Resurtir" <<endl;
                for(i=0;i<totalprod;i++) //Una ves ordenados se usa un for para imprimirlos
                    if(Productos[i].st==1){
                        cout<< Productos[i].id<<setw(10)<<Productos[i].producto<<setw(11)<<Productos[i].PC<<
                        setw(10)<<Productos[i].PV<<setw(10)<<Productos[i].existencias<<setw(13)<<Productos[i].nivr<<
                        setw(15)<<Productos[i].st<<(Productos[i].existencias<Productos[i].nivr ?"        *" : "") <<endl; //al final de esta linea se pregunta si las existencias son menor o igual a reorden, de ser asi se agrega el asterisco
                    }
                cout<<endl;
                break;
        case 2: for(i=0;i<totalprod-1;i++){ //El caso 2 es igual solo que con el Producto, en este caso verificaria el ASCI de cada producto
                    for(j=0;j<totalprod-i-1;j++){
                        if(Productos[j].producto > Productos[j + 1].producto){
                            swap(Productos[j].id, Productos[j + 1].id);
                            swap(Productos[j].producto, Productos[j + 1].producto);
                            swap(Productos[j].PC, Productos[j + 1].PC);
                            swap(Productos[j].PV, Productos[j + 1].PV);
                            swap(Productos[j].existencias, Productos[j + 1].existencias);
                            swap(Productos[j].nivr, Productos[j + 1].nivr);
                            swap(Productos[j].st, Productos[j + 1].st);
                        }
                    }
                }
                cout<<"ID"<<setw(10)<<"Producto"<<setw(10)<<
                "PC"<<setw(8)<<"PV"<<setw(15)<<"Existencias"<<setw(15)<<
                "Niv.Reorden"<<setw(12)<< "Status"<<setw(10)<<"Resurtir" <<endl;
                for(i=0;i<totalprod;i++)
                    if(Productos[i].st==1){ //Una vez ordenados los agrega
                        cout<< Productos[i].id<<setw(10)<<Productos[i].producto<<setw(11)<<Productos[i].PC<<
                        setw(10)<<Productos[i].PV<<setw(10)<<Productos[i].existencias<<setw(13)<<
                        Productos[i].nivr<<setw(15)<<Productos[i].st<<(Productos[i].existencias<Productos[i].nivr ?"        *" : "") <<endl;
                    }
                cout<<endl;
                break;
        case 3:
                break;
    }
}

int Buscar(string Prod_temp){ //Funcion Buscar
    int i=0;
    while(i<totalprod && Prod_temp != producto[i]) //Mientras i sea menor al totalprod y el producto diferente de i se ira aumentando
            i++;
        if(i==totalprod)//Si llega a ser igual quiere decir que no se encontro regresando un -1
            return -1;
        else //Si es igual nos regresa el valor de i que es donde se encontro (La posicion)
            return i;
}

int Buscar_Invent(string Prod_temp){ //Funcion de buscar inventario pero dentro del arreglo de estructura
    int i=0;
    while(i<totalprod && Prod_temp != Productos[i].producto) //Mismo procedimiento solo cambia si tambien es diferente de Producto.producto
            i++;
        if(i==totalprod)
            return -1;
        else
            return i;
}

int Buscar_user(string User_temp){ //Funcion para buscar usuarios
    int i=0;
    while(i<total_user && User_temp != usuarios[i]) //Metodo
        i++;
    if(i== total_user) //Si no se encuentra regresa un-1
        return -1;
    else
        return i;
}

void Modificaciones_usuario(){
    string User_temp;
    int i,indice,opcion;
    int tipo_nuevo, Status_nuevo, Nueva_contrasenia;
    string Nuevo_nombre;
    while(true){
        i=total_user;
        cout<<"Usuario: ";
        cin>>User_temp;
        if(User_temp == "*"){
            break;
        }
        indice=Buscar_user(User_temp); //Se llama a la funcion buscar
        if(indice==-1){
            cout<<"Usuario no encontrado."<<endl;
        }else
            if(status[indice]==0){
                cout<<"Productos dados de baja no se puedne modificar."<<endl;
            }else{
                cout<<"Que deseas cambiar?"<<endl;
                cout<<"1.Nombre."<<endl;
                cout<<"2.Contrasenia."<<endl;
                cout<<"3.Tipo."<<endl;
                cout<<"4.Status."<<endl;
                cout<<"5.Regresar al menu anterior."<<endl;
                cout<<"Opcion: ";
                cin>>opcion;
                switch(opcion){
                    case 1: cout<<"Nuevo Nombre: ";
                            cin>>Nuevo_nombre;
                            usuarios[indice] = Nuevo_nombre;
                            cout<<"Nombre cambiado."<<endl;
                            break;
                    case 2: cout<<"Contrasenia nueva: ";
                            cin>>Nueva_contrasenia;
                            pass[indice] = Nueva_contrasenia;
                            cout<<"Contrasenia cambiada."<<endl;
                            break;
                    case 3: cout<<"Tipo nuevo: ";
                            cin>>tipo_nuevo;
                            tipo[indice] = tipo_nuevo;
                            cout<<"Tipo cambiado."<<endl;
                            break;
                    case 4: cout<<"Status Nuevo: ";
                            cin>>Status_nuevo;
                            status[indice] = Status_nuevo;
                            cout<<"Nr cambiado."<<endl;
                            break;
                    case 5:
                            break;
                }
            }
    }
}

void Modificaciones(){
    string Prod_temp;
    int opcion;
    while(true){
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "*"){
            break;
        }
        Temp=Inicio; //Se usa metodo de buscar dentro de la lista de estructura
        while(Temp!=NULL && Temp->producto != Prod_temp){
            Temp = Temp->sig; //Temp se vuelve el siguiente nodo hasta que lo encuentre
        }
        if(Temp==NULL){ //Si no lo encuentra
            cout<<"Producto no encontrado"<<endl;
        }else
            if(Temp->st==0){
                cout<<"Productos dados de baja no se pueden modificar."<<endl;
            }else{
                cout<<"Que deseas cambiar?"<<endl;
                cout<<"1.Precio de compra."<<endl;
                cout<<"2.Precio de venta."<<endl;
                cout<<"3.Existencias."<<endl;
                cout<<"4.Numero de reorden."<<endl;
                cout<<"5.Regresar al menu anterior."<<endl;
                cout<<"Opcion: ";
                cin>>opcion;
                switch(opcion){
                    case 1: cout<<"PC nuevo: ";
                            cin>>Temp->PC;
                            cout<<"Precio de compra cambiado."<<endl;
                            break;
                    case 2: cout<<"PV nuevo: ";
                            cin>>Temp->PV;
                            cout<<"Precio de venta cambiado."<<endl;
                            break;
                    case 3: cout<<"Nuevas existencias: ";
                            cin>>Temp->existencias;
                            cout<<"Existencias cambiadas."<<endl;
                            break;
                    case 4: cout<<"Nr nuevo: ";
                            cin>>Temp->nivr;
                            cout<<"Nr cambiado."<<endl;
                            break;
                    case 5:
                            break;
                }
                Lista_a_Globales();
            }
    }
}

void Altas_usuario(){
    string User_temp;
    int i,indice,opcion;
    while(true){
        i=total_user;
        cout<<"Usuario: ";
        cin>>User_temp;
        if(User_temp == "*"){
            break;
        }
        indice = Buscar_user(User_temp); //Se usa la funcion de buscar para el usuario
        if(indice==-1){
            usuarios[i] = User_temp;
            cout<<"Contraseña: ";
            cin>>pass[i];
            cout<<"Tipo: ";
            cin>>tipo[i];
            status[i]=1;
            total_user++;
        }else
            if(status[indice]==0){
                cout<<"El usuario ya existe pero dado de baja,Desea darlo de alta? (1=Si,0=No)"<<endl;
                cin>>opcion;
                if(opcion==1){
                    st[indice]=1;
                    cout<<"Usuario dado de alta"<<endl;
                }else;
            }else{
                cout<<"Usuario Ya existente"<<endl;
        }
    }
}

void ventas(){
    string Prod_temp;
    int i,indice, Cantidad_temp, opcion;
    float TotalVenta = 0;
    float Acumulo = 0;
    float TotalCosto = 0;
    int conteoProd = 0;

    struct Ticket{
        string producto;
        int cantidad;
        float PrecioUni;
        float subtotal;
        float costo;
    };
    Ticket Venta[50];
    while(true){
        cout<<"Producto: ";
        cin>>Prod_temp;
        if(Prod_temp == "**"){
            cout<<setw(40)<<"Corte de caja."<<endl;
            cout<<"Ingresos: "<<TotalVenta<<endl;
            cout<<"Egresos: "<<TotalCosto<<endl;
            cout<<"Ganancia: "<<TotalVenta - TotalCosto<<endl;
            ingresos += TotalVenta;//La variable global ingresos se va sumando con todos los tickets para el corte de caja general
            egresos += TotalCosto;
            break;
        }
        if(Prod_temp == "*"){
            if(conteoProd == 0){
                cout<<"No se vendio ningun producto."<<endl;
            }else{
                cout<<setw(50)<<"Abarrotes Paco"<<endl;
                cout<<"Producto    "<<"Cantidad    "<<setw(15)<<"Precio Unitario"<<setw(15)<< "Subtotal" << endl;
                for(i=0;i<conteoProd;i++){
                    TotalCosto += Venta[i].costo;
                    cout<<Venta[i].producto<<setw(12)<<Venta[i].cantidad<<setw(15)<<Venta[i].PrecioUni<<setw(18)<<Venta[i].subtotal<<endl;
                }
                cout<<setw(80)<<"Total: "<<Acumulo<<endl;
                TotalVenta += Acumulo;
                Acumulo = 0;
                conteoProd = 0;
                }
        }
        indice = Buscar(Prod_temp);
        if(indice == -1){
            cout<<"Producto no existente."<<endl;
        }else
            if(st[indice]==0){
                cout<<"Productos dados de baja no se pueden vender."<<endl;
            }else
                if(existencias[indice]<=0){
                    cout<<"No quedan existencias, compra no posible."<<endl;
                }else{
                cout<<"Cantidad: ";
                cin>>Cantidad_temp;
                if(Cantidad_temp>existencias[indice]){
                    cout<<"No hay "<<Cantidad_temp<<" Solo hay "<<existencias[indice]<<
                    " Desea hacer la compra de solo "<<existencias[indice]<<"? (1=Si,0=No)"<<endl;
                    cout<<"Opcion: ";
                    cin>>opcion;
                    if(opcion==1){
                        Cantidad_temp=existencias[indice];
                    }else{
                        cout<<"Compra cancelada para este producto."<<endl;
                    }
                }
                existencias[indice] -= Cantidad_temp;//se resta la cantidad que se pidio a las existencias
                Temp = Inicio;
                while (Temp != NULL && Temp->producto != Prod_temp){
                    Temp = Temp->sig;
                }
                if(Temp!=NULL){
                    Temp->existencias -=Cantidad_temp;
                }
                //metodo para guardar los datos de los productos que se venden, junto su precio
                Venta[conteoProd].producto = producto[indice];//conteo prod ademas de ser el conteo de lo que se esta vendiendo, sirve como  i
                Venta[conteoProd].cantidad = Cantidad_temp;//ya que su valor es 0 por lo que va a guardar todos los datos en el recuadro 0 del arreglo
                Venta[conteoProd].PrecioUni = PV[indice];
                Venta[conteoProd].subtotal = Cantidad_temp * PV[indice];
                Venta[conteoProd].costo = Cantidad_temp * PC[indice];
                Acumulo += Venta[conteoProd].subtotal; //sumando los subtotales para el precio final
                conteoProd++;
            }
    }
}


void Mostrar_Inventario() {
    int indices_reorden[Contador_productos], c = 0;
    cout << setw(5) << "Id" << setw(10) << "Producto" << setw(10) << "Pc" << setw(10)  << "Pv" << setw(15) << "Existencias" << setw(10) << "Reorden" << setw(10) << "Status" << setw(10) << endl;
    for(int i = 0; i < Contador_productos; i++) {
        if (Status[i] == 1) {
            cout << setw(5) << Id[i] << setw(10) << Producto[i] << setw(10) << Pc[i] << setw(10) << Pv[i] << setw(15) << Existencias[i] << setw(10) << Reorden[i] << setw(10) << Status[i] << setw(10) << endl;
        }
        if (Existencias[i] < Reorden[i]) {
            indices_reorden[c] = i;
            c++;
        }
    }
   
