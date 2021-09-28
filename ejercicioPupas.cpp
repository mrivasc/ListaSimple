#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/*Ingresar la cantidad de pupusas que los clientes desean, si quiere que sean de arroz 
o de maíz, si las quieren con Coca-Cola o no, y de qué ingredientes las quieren, 
que permite agregarlas a la lista y mostrar las órdenes.*/

struct Node{
    string dough, drink, ingr;
    Node *next;
};

class List{
    private:
        Node *head;

    public:
        List();
        ~List();
        void order();
        void showOrder();
};

List::List(){
    head = nullptr;
}

List::~List(){
    Node *p=nullptr;

    p = head;
    while(head){
        p = head;
        head = head->next;
        delete p;
    }
}

void menu(){
    List L;
    int r=0, pupas=0;

    do
    {
        cout << "\n\n\tPUPAS DONIA MISI\n\n";
        cout << "1. Agregar orden\n2. Mostrar orden\n3. Salir\n\nRespuesta: ";
        cin >> r; cout << endl;

        switch (r){
        case 1:
            cin.ignore();
            cout << "Cantidad de pupas: "; cin >> pupas; cout << endl << endl;
            if(pupas <= 0)
                break;
            else{
                cout << "\tAgregando datos...\n\n";

                for(int i=0 ; i<pupas ; i++){
                cout << "Orden #" << i+1 << endl;

                L.order();
                }
            }
            break;

        case 2:
            cin.ignore();
            L.showOrder();
            break;

        case 3:
            break;

        default:
            cout << "-- Ingrese una opcion valida --";
        }
    } while (r != 3);
}

void List::order(){
    Node *newN = new Node;
    int dough = 0, drink = 0, ingr = 0;

    do{
        cout << "Tipo de masa... (1) Arroz (2) Maiz\n";
        cout << "Respuesta: ";
        cin >> dough;

        if(dough <= 0 || dough > 2)
            cout << "-- Opcion invalida --\n";
            
    } while (dough != 1 && dough != 2);

    if (dough == 1)
        newN->dough = "Arroz";
    else if (dough == 2)
        newN->dough = "Maiz";
    cin.ignore();
    cout << endl;


    do{
        cout << "Agregar Coca-Cola... (1) Si (2) No\n";
        cout << "Respuesta: ";
        cin >> drink;

        if(drink <= 0 || drink > 2)
        cout << "-- Opcion invalida --\n";

    } while (drink != 1 && drink != 2);

    if (drink == 1)
        newN->drink = "Con coquita fresca";
    else if (drink == 2)
        newN->drink = "Sin coquita";
    cout << endl;
    cin.ignore();

    cout << "Ingrediente... \n"; 
    cout << "Digite su ingrediente (tenemos de todo): "; getline(cin, newN->ingr); cout << endl << endl;

    newN->next = nullptr;

    if (!head)
        head = newN;
    else{
        Node *p = head;
        while (p->next)
        p = p->next;
        p->next = newN;
    }
}

void List::showOrder()
{
    Node *p = head;
    int n = 1;

    cout << "\tMostrando lista...\n\n";

    if (!p)
        return;
    else{
        while (p){
            cout << "Orden #" << n << "\n";
            cout << "Masa: " << p->dough << endl;
            cout << "Bebida: " << p->drink << endl; 
            cout << "Ingrediente: " << p->ingr << endl << endl;
            p = p->next;
            n++;
        }
    }
}

int main() { menu(); system("pause");}