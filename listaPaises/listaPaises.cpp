#include <iostream>
using namespace std;

/* Elabore un programa que contenga, dentro de su clase, dos funciones miembro y un puntero 
a lista simple. La primera función lee el código de área de un país y el número telefónico 
desde el teclado y las introduce en la lista, en un nuevo nodo cada una. La segunda función imprime 
en pantalla todos los números almacenados, y la cantidad de números que hay en la lista. 

id = número de veces que vas guardando datos

Su programa contará con lo siguiente: 

(5%) La estructura de nodo de la lista.
(5%) La clase, con sus partes privada y pública definidas. 
(10%) El cuerpo de la función de lectura (si desea puede ser una función que itera y otra función que lee), 
se deberá validar que el nombre de la persona, el código de área,  el número de teléfono, y id del teléfono 
que pertenece. 
(15%) El cuerpo de la función imprime el número de teléfono. 
(5%) La función main, que define el objeto e invoca a ambas funciones miembro. */  

// El Salvador, Costa Rica, Panamá

struct Node{
    string name;
    int acode, number;
    Node *next;
};

class List{
    private:
        Node *head;
    public:
        List();
        ~List();
        void read();
        void print();
};

List::List(){
    head = nullptr;
}

List::~List(){
    Node *p = head;
    while(head){
        p = head;
        head = head->next;
        delete p;
    }
}

/*void List::read(){            // normal way, without comprobation
    Node *nw = new Node;
    
    cout << "Nombre: "; getline(cin, nw->name); cout<<endl;

    cout << "El Salvador (+503) Costa Rica (+506) Panama (+507)\n";
    cout << "Codigo de area: +"; cin >> nw->acode;

    cout << "Numero de telefono: "; cin >> nw->number;
}*/

void List::read(){
    Node *nw = new Node; int len=0;

    cout << "Nombre: "; getline(cin, nw->name); cout<<endl; // name

    do{ // code
        cout << "El Salvador (+503) Costa Rica (+506) Panama (+507)\n";
        cout << "Codigo de area: +"; cin >> nw->acode; cin.ignore();
        
        if(nw->acode != 503 && nw->acode != 506 && nw->acode != 507)  // El Salvador, Costa Rica and Panama area codes, respectively
            cout << "- Codigo ingresado no valido -\n\n";

    } while (nw->acode != 503 && nw->acode != 506 && nw->acode != 507);

    
    // Digitos. ESA: 8 | CRI: 7 | PAN: 6
    // number
    
        if(nw->acode == 503){

            do{
                cout << "Numero de telefono: "; cin >> nw->number; cin.ignore();
                len = to_string(nw->number).length();

                if(len != 8)
                    cout << "- Solo se admiten 8 digitos -\n\n";
        
            } while (len != 8);    
        }

        if(nw->acode == 506){

            do{
                cout << "Numero de telefono: "; cin >> nw->number; cin.ignore();
                len = to_string(nw->number).length();

                if(len != 7)
                    cout << "- Solo se admiten 7 digitos -\n\n";
        
            } while (len != 7);    
        }

        if(nw->acode == 507){

            do{
                cout << "Numero de telefono: "; cin >> nw->number; cin.ignore();
                len = to_string(nw->number).length();

                if(len != 6)
                    cout << "- Solo se admiten 6 digitos -\n\n";
        
            } while (len != 6);
        }

    nw->next = nullptr;

    if(!head)
        head = nw;
    else{
        Node *p = head;
        while(p->next)
            p = p->next;
        p->next = nw; 
    }
}

void List::print(){
    int id=1;
    Node *p = head;

    if(p == nullptr)
        cout << "- No hay datos en la lista -";

    else{
        cout << "Mostrando lista...\n\n";
        
        while(p){
            cout << "ID: " << id << endl;
            cout << "Nombre: " << p->name << endl;
            cout << "Codigo de area: +" << p->acode << endl; 
            cout << "Numero telefonico: " << p->number << endl;
            p = p->next;
            cout<<endl; ++id;
        }
    }


}

void menu(){
    int r=0; List L;

    do{
    cout << "\n\nCODIGO DE AREA DE PAISES\n\n";
    cout << "1. Agregar datos\n2. Mostrar lista\n3. Salir\n\nRespuesta: "; cin >> r; cin.ignore(); cout<<endl;

        switch(r){
            case 1:
                L.read();
                break;

            case 2:
                L.print();
                break;

            case 3:
                break;

            default:
                cout << "- Ingrese una opcion valida -\n";
        }
    } while (r != 3);
}

int main(){ menu(); }