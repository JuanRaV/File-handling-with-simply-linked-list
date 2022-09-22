#include <iostream>
#include"list.h"
#include"node.h"
#include"student.h"
using namespace std;

int main()
{
    list *lis=new list;
    student s;
    int opc,id=0;
    string nombre,carrera;

    do{
        system("cls");
        cout<<"==MENU==\n1.-Insert\n2.-Eliminar por Id\n3.-Buscar"<<endl;
        cout<<"4.-Tamanio\n5.-Imprimir\n6.-Vacia?\n7.-Recuperar\n8.-Exit"<<endl;cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            cout<<"--INSERT--"<<endl;
            cout<<"Escribe nombre: ";cin>>nombre;
            s.setName(nombre);
            cout<<"Escribe carrera: ";cin>>carrera;
            s.setDegree(carrera);
            id=id+1;
            s.setId(id);
            lis->addFront(s);
            lis->guardar();
            fflush(stdin);
            break;
        case 2:
            cout<<"--REMOVE--"<<endl;
            cout<<"Escriba el id del elemento a eliminar: ";cin>>id;
            lis->remove(id);
            lis->guardar1();
            system("pause");
            break;
        case 3:
            cout<<"--SEARCH--"<<endl;
            cout<<"Escriba el Id del elemento a buscar: ";cin>>id;
            lis->search(id); break;

        case 4:
            cout<<"--TAMANIO--"<<endl;
            cout<<lis->tamanio()<<endl;system("pause");

        case 5:
            cout<<"--IMPRIMIR--"<<endl;
            lis->print();break;
        case 6:
            cout<<"--VACIA--"<<endl;
            if(lis->empty()==true)
                cout<<"La lista SI esta vacia"<<endl;
            else
                cout<<"La lista NO esta vacia"<<endl;
            system("pause");break;
        case 7:
            cout<<"--Cargar--"<<endl;
            lis->cargar();

        case 8:
            break;
        }
    }while(opc!=8);
    return 0;
}
