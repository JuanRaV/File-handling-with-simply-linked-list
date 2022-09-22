#include "list.h"
#include"node.h"
#include <iomanip>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;
list::list()
{
    h=nullptr;
}
void list::addFront(student s)
{
    node *tmp=new node(s);
    if(h==nullptr){
        h=tmp;
    }else{
        tmp->setNext(h);
        h=tmp;
    }
}
void list::guardar(){
    fstream File;

    File.open("file01.txt",ios::app);
    File<<h->getStudent().getId();
    File<<"|";
    File<<h->getStudent().getName();
    File<<"|";
    File<<h->getStudent().getDegree();

    File<<"*";
    File.close();
    fflush(stdin);}
void list::guardar1(){

    fstream File;
    node *aux=h;
    File.open("file01.txt",ios::out);
    while(aux!=nullptr){
    File<<aux->getStudent().getId();
    File<<"|";
    File<<aux->getStudent().getName();
    File<<"|";
    File<<aux->getStudent().getDegree();

    File<<"*";
    aux=aux->getNext();
    }

    File.close();
    fflush(stdin);}

void list::cargar(){
/// el constructor de ifstream abre el archivo
/// Se abre el archivo y se configura de modo binary
 ifstream file( "file01.txt", ios::in | ios::binary);

 /// sale del programa si ifstream no pudo abrir el archivo
 /// Verifica que se haya abierto bien el archivo
 if ( !file.is_open() )
 {
 cerr << "No se pudo abrir el archivo" << endl;
 exit( EXIT_FAILURE );
 } // fin de if

 int id; // el número de cuenta
 string nombre; // el nombre del propietario de la cuenta
 string carrera; // el saldo de la cuenta

 /// muestra en pantalla los titulos y configura su espacio

 cout << left << setw( 10 ) << "Id" << setw( 13 )
 << "Nombre" << "Carrera" << endl << fixed << showpoint;

/// seekg desplazamiento en el archivo "handle"   end, beg(inning) cur(rent)
 file.seekg(0,file.end);
 int length=file.tellg();
 //cout<<length;  /// despliga en tamaño de lectura
 file.seekg(0,file.beg);

 /// crea un buffer para recupera todo la informacion en formato binario
 char *buffer = new char [length];
 file.read (buffer,length);

 /// convertimos nuestro buffer en formato flujo de cadena stringstream

 string registro;
 string campo;
 bool flag=true;

 stringstream ss(buffer);
  /// recupera registro a registro de nuestro SS
  /// se puede usar una bandera o verificamos que los caracteres extraidos no sin imprimibles
student s;

while(getline(ss,registro,'*') and  ss.eofbit and flag)//and flag)
  {
       stringstream ss_reg(registro);
       /// en caso de no conocer cuantos registro se usa este ciclo y se puede hacer un try catch para
       ///  cuidar las conversiones en caso de ser necesarias
      /* while( getline(ss_reg,campo,'|'))
       {
         cout<<campo<<" ";
       }*/

        try{
          getline(ss_reg,campo,'|');
          id=stoi(campo);  /// convierte de string to int
            s.setId(id);
          getline(ss_reg,campo,'|');
          nombre=campo;      /// se quede en el mismo tipo de dato
            s.setName(nombre);
          getline(ss_reg,campo,'|');
          carrera=campo;
             s.setDegree(carrera);
             addFront(s);
        cout << left << setw( 10 ) << id << setw( 13 ) << nombre
        << setw( 7 ) << setprecision( 2 ) << right << carrera << endl;
            /*
            Se puede evitar con ss.eofbit
            Cuando da lectura a los utimos caracteres no imprimibles como un registro, arroja un error
            el cual tiene que estar cuidado con un try catch  y activar la bandera para que no leea mas
            caracteres de nuestro ss o ss_reg
            */
         } catch (invalid_argument const &e) {
                  //cout << "Bad input: std::invalid_argument thrown" << endl;
                  flag=false;
                  }
           catch (out_of_range const &e) {
                  //cout << "Integer overflow: std::out_of_range thrown" <<endl;
                  flag=false;
                  }
        fflush(stdin);
     }
      system("pause");
    fflush(stdin);
}
void list::print()
{
    node *aux=h;
    if(!h)
        cout<<"Empty list..."<<endl;
    else{
        cout<<left
        <<setw(0)<<"ID |"
        <<setw(9)<<"     Nombre     |"
        <<setw(17)<<"   Carrera  "<<endl;
        cout<<"--------------------------------"<<endl;
        while(aux){
            cout<<left
            <<setw(3)<<aux->getStudent().getId()
            <<"|"<<setw(9)<<aux->getStudent().getName()
            <<"       |"<<setw(17)<<aux->getStudent().getDegree()<<endl;
            aux=aux->getNext();
        }
    }
    cout<<endl;
    system("pause");
}

void list::remove(int id)
{
    node *aux=h;
    node *ant=nullptr;
    bool band = true;
    if(h!=nullptr){
        while(aux && band){
            if(id!=aux->getStudent().getId()){
                ant=aux;
                aux=aux->getNext();
            }else{
            band=false;}
        }
    if(aux==nullptr){
        cout<<"No existe el dato"<<endl;
    }else if(aux==h){
        h=h->getNext();
        cout<<"Elemento con ID "<<aux->getStudent().getId()<<" eliminado CORRECTAMENTE"<<endl;
        delete aux;
    }else{
        ant->setNext(aux->getNext());
        cout<<"Elemento "<<aux->getStudent().getId()<<" eliminado correctamente"<<endl;
        delete aux;
    }
    }else
        cout<<"Lista vaciaa..."<<endl;

}

void list::search(int id)
{
    bool band=false;
    node *actual=h;
    while(actual ){
        if(actual->getStudent().getId()==id){
            cout<<"---Elemento encontrado---"<<endl;
            cout<<"Id: "<<actual->getStudent().getId()<<endl;
            cout<<"Nombre: "<<actual->getStudent().getName()<<endl;
            cout<<"Carrera: "<<actual->getStudent().getDegree()<<endl;
            band=true;
            }
            actual=actual->getNext();
        }


        if(band==false)
            cout<<"El elemento '"<<id<<"' NO esta en la lista"<<endl;
        system("pause");
    }


bool list::empty()
{
    node *aux=h;
    if(aux!=nullptr)
        return false;
    else
        return true;
}
int list::tamanio()
{
    int cont=0;
    node *aux=h;
    while(aux){
        cont++;
        aux=aux->getNext();
    }return cont;
}
/*void list::inicializa()
{

}


void list::vaciar()
{

}
*/
