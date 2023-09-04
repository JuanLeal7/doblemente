#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
    int nro;
    struct nodo *sig;  
    struct nodo *ant;
    
} *primero,*ultimo;

void insertar(nodo *&,int);
void mostrar(nodo*);
void buscar(nodo *,int);
void borrar();

void actualizar(nodo*lista,int b){
    bool band = false;
	nodo *act =new nodo();
    act = lista;
    
    while((act!=NULL)&&(act->nro <=b)){

     if(act->nro==b){
     	band=true;
	   }
	   act = act->sig;
    } 
    if(band= true){
    cout<<"El valor:"<<b<<" esta en la lista\n";
    cout<<"ingrese el nuevo valor\n";
    cin>> act->nro;
    }
    else{
	cout<<"El valor:"<<b<<" no esta en la lista\n";
    }
	
}

int main(){
    nodo *lista= NULL;
    int nro,m,nuevo;
    cout<<"cantidad de la lista\n";
    cin>>m;

for (int i=0 ; i < m ; i++)
{
    cout<<"ingrese el valor\n";
    cin>>nro;
    insertar(lista,nro); 	
}

int opc;
do{	

cout<<"OPCIONES\n";
cout<<"1.Mostrar lista\n";
cout<<"2.Buscar valor en la lista\n";
cout<<"3.Borrar valor de la lista\n";
cout<<"4.Actualizar valor\n";
cout<<"5.EXIT\n";
cin>>opc;


	switch(opc){
		case 1: 
		mostrar(lista);
		system("pause");
		break;
		case 2:
		cout<<"digite el valor que desea buscar\n";
		cin>>nro;
		buscar(lista,nro);
		system("pause");	
		break;
		case 3:
		borrar();
		system("pause");
		break;
		case 4:
		cout<<"digite el valor que desea actualizar\n";
		cin>>nro;
		actualizar(lista,nro);
		cout<<"lista actualizada\n";
		system("pause");
		break;
	}
	system("cls");	

   }while(opc !=5);

}

 void insertar(nodo *&lista,int n){
 
    nodo *Nlista = new nodo();
    Nlista -> nro =n;
    
   if(primero==NULL){
   	primero = Nlista;
   	primero->sig =NULL;
   	primero->ant=NULL;
   	ultimo = primero;
   }else{
   	ultimo->sig= Nlista;
   	Nlista->sig = NULL;
   	Nlista->ant=ultimo;
   	ultimo=Nlista;
   }
   

}

void mostrar(nodo *lista){
	nodo *act =new nodo(); 
    act = primero;
    if(primero!=NULL){
	
	  while(act!=NULL){
	  	cout<<act->nro<<" -> ";
		act=act->sig;
	  	
	  }
	}else{
		cout<<"la lista esta vacia";
	}
}

void buscar(nodo*lista,int b){
    bool band = false;
	nodo *act =new nodo();
    act = lista;
    
    while((act!=NULL)&&(act->nro <=b)){

     if(act->nro==b){
     	band=true;
	   }
	   act = act->sig;
    } 
    if(band= true){
    cout<<"El valor:"<<b<<" esta en la lista\n";
    }
    else{
	cout<<"El valor:"<<b<<" no esta en la lista\n";
    }
	
}

void borrar(){
 nodo* act=new nodo();
 act=primero;
 nodo*ant=new nodo();
 ant=NULL;
 bool enc=false;
 int bus=0;
 cout <<"ingrese el valor que desea eliminar\n ";
 cin>>bus;
 if(primero!=NULL){
 	
 	while(act!=NULL&& enc!=true){
 		
		 if(act->nro==bus)
		 cout<<"el valor "<<bus<<" encontrado\n";
		 	
		 	if(act==primero){
		 		primero =primero->sig;
		 		primero->ant=NULL;
		 		
			 }else if(act==primero){
			 	ant->sig=NULL;
			 	ultimo=ant;
			 	
			 }else{
			 	ant->sig=act->sig;
			 	act->sig->ant=ant;
			 }
 			cout<<"valor eliminado\n";
 			enc=true;
	 }
	 ant=act;
	 act=act->sig;
    }
    if(!enc){
    	cout<<"nodo no encontrado\n";
	}

 }

