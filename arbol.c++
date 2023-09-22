#include <iostream>
#include <conio.h>

using namespace std;

struct nodo
{
    int numero;
    nodo * izquierda;
    nodo * derecha;
    nodo * padre;
};

nodo *arbol = NULL ;
void menu();

int main(){

    menu();
    getch();
    return 0;
}


nodo *crear(int n, nodo * padre){
    nodo *nuevo = new nodo();

    nuevo->numero = n;
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;
    nuevo->padre = padre;

    return nuevo;
}

void insertar(nodo *&arbol,int n, nodo * padre){
    if (arbol == NULL)
    {
        nodo * nuevo2 = crear(n,padre);
        arbol = nuevo2;
    }
    else
    {
        int raiz = arbol->numero;
        if (n > raiz)
        {
            insertar(arbol->derecha,n,arbol);
        }
        else{
            insertar(arbol->izquierda,n,arbol);
        }
        
    }

}

void show(nodo *arbol,int c){

    if (arbol == NULL){
        return;
    }
    else
    {
        show(arbol->derecha,c+1);
        for (int i = 0; i < c; i++)
        {
            cout<<"-->";
        }
        cout<<arbol->numero<<endl;
        show(arbol->izquierda,c+1);
        
        
    }
}

bool busqueda(nodo *arbol,int n){
    if (arbol == NULL)
    {
       return false;
    }else if (arbol->numero == n)
    {
        return true;
    }
    else if (n < arbol ->numero)
    {
        return busqueda(arbol->izquierda,n);
    }
    else
    {
        return busqueda(arbol->derecha,n);
    }
    
    
    
    
}

void preorden(nodo * arbol){
    if (arbol == NULL)
    {
        return;
    }else
    {
        cout<<arbol->numero<<"->";
        preorden(arbol->izquierda);
        preorden(arbol->derecha);
        
    }
}

void posorden(nodo * arbol){
    if (arbol == NULL)
    {
        return;
    }else
    {
        posorden(arbol->izquierda);
        posorden(arbol->derecha);
        cout<<arbol->numero<<"->";
        
    }
}

void inorden(nodo * arbol){
    if (arbol == NULL)
    {
        return;
    }else
    {
        inorden(arbol->izquierda);
        cout<<arbol->numero<<"->";
        inorden(arbol->derecha);
        
    }
}

void modificar(nodo *nodoModificar, int Valor) {
    if (nodoModificar) {
        nodoModificar->numero = Valor;
    }
}

nodo *buscarNodo(nodo *arbol, int valor) {
    if (arbol == NULL || arbol->numero == valor) {
        return arbol;
    }

    if (valor < arbol->numero) {
        return buscarNodo(arbol->izquierda, valor);
    } else {
        return buscarNodo(arbol->derecha, valor);
    }
    return NULL; 
}




nodo *min(nodo * arbol){
    if (arbol == NULL)
    {
        return NULL;
    }
    if (arbol->izquierda)
    {
        return min(arbol->izquierda);
    }
    else
    {
        return arbol;
    }
    
}

void remplazar(nodo *arbol, nodo* nuevo) {
    if (arbol->padre) {
        if (arbol->padre->izquierda == arbol) {
            arbol->padre->izquierda = nuevo;
        } else if (arbol->padre->derecha == arbol) {
            arbol->padre->derecha = nuevo;
        }
    }
    if (nuevo) {
        nuevo->padre = arbol->padre;
    }
}


void borrar(nodo *borr){
    borr->izquierda = NULL;
    borr->derecha = NULL;

    delete borr;
}

void del(nodo *nododel){
    if (nododel->izquierda && nododel->derecha)
    {
        nodo * menor = min(nododel->derecha);
        nododel->numero = menor->numero;
        del(menor);
    } else if (nododel->izquierda)
    {
        remplazar(nododel,nododel->izquierda);
        borrar(nododel);
    }
    else if (nododel->derecha)
    {
        remplazar(nododel,nododel->derecha);
        borrar(nododel);
    }
    else
    {
        remplazar(nododel,NULL);
        borrar(nododel);
    }
    
    
    
}

void eliminar(nodo * arbol,int x){
    if (arbol == NULL)
    {
        return;
    }
    else if (x < arbol->numero)
    {
        eliminar(arbol->izquierda,x);
    }
    else if (x > arbol->numero)
    {
        eliminar(arbol->derecha,x);
    }
    else{
        del(arbol);
    }
    
}






void menu(){
int opcion, numero,cont=0,cam;
    do
    {
        cout<<"\n"<<endl;
        cout<<"1. Ingresar datos al arbol"<<endl;
        cout<<"2. Mostrar arbol"<<endl;
        cout<<"3. Buscar en el arbol"<<endl;
        cout<<"4. Forma de Preorden"<<endl;
        cout<<"5. Forma de Posorden"<<endl;
        cout<<"6. Forma de Inorden"<<endl;
        cout<<"7. Modificar numero en el arbol"<<endl;
        cout<<"8. Eliminar numero"<<endl;
        cout<<"9. Cerrar el programa"<<endl;
        cout<<"Numero:  ";
        cout<<"\n"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1: cout<<"Numero a insertar"<<endl;
        cin>>numero;
        insertar(arbol,numero,NULL);
            break;
        
        case 2:
        cout<<"\nArbol:\n";
        show(arbol,cont);
        cout<<"\n";
            break;

        case 3: cout<<"Digite numero a buscar: ";
                cin>>numero;
                if (busqueda(arbol,numero)==true)
                {
                    cout<<"El elemento "<<numero<<" Fue encontrado"<<endl;
                }
                else{
                    cout<<" Elemento no encontrado"<<endl;
                }
                
            break;

         case 4: cout<<"Arbol en preorden "<<endl;
         preorden(arbol);
            break;


        case 5: cout<<"Arbol en posorden "<<endl;
         posorden(arbol);
            break;

         case 6: cout<<"Arbol en Inorde "<<endl;
         inorden(arbol);
            break;

         case 7: 
                cout << "Numero a cambiar: " << endl;
                cin >> cam;
                cout << "Nuevo valor: " << endl;
                cin >> numero;
                if (busqueda(arbol, cam)) {
        nodo *nodocambio = buscarNodo(arbol, cam); // Implement buscarNodo function
        if (nodocambio) {
            modificar(nodocambio, numero);
        }
    } else {
        cout << "El elemento " << cam << " no se encuentra en el árbol." << endl;
    }
    break;

        case 8: cout<<"Numero a eliminar "<<endl;
        cin>>numero;
         eliminar(arbol,numero);
         cout<<"\n";
            break;
          
        
        default:
            break;
        }





    } while (opcion<9);

}