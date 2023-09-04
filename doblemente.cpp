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
    act = primero;
    int bus=0,enc=0;
    cout<<"ingrese el valor que quiere modificar\n";
    cin>>bus;
    if (primero!=NULL){
    	do{
    		if(act->nro==bus){
    			cout<< "el valor fue encontrado\n";
    			cout<< "ingrese el nuevo valor\n";
    			cin>> act->nro;
    			enc=1;
    			
			}
			act =act->sig;
		}while(act!=primero&&enc!=1);
		if(enc==0){
			cout<< "valor no encontrado\n";
		}
	}else{
		cout<< "lista vacia\n";
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
		buscar(lista,nro);
		system("pause");	
		break;
		case 3:
		borrar();
		system("pause");
		break;
		case 4:
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
   	primero=Nlista;
   	ultimo=Nlista;
   	primero->sig=primero;
   	primero->ant=ultimo;
   }else{
   	ultimo->sig= Nlista;
   	Nlista->ant=ultimo;
   	Nlista->sig=primero;
   	ultimo=Nlista;
   	primero->ant=ultimo;
   }
   

}

void mostrar(nodo *lista){
	nodo *act =new nodo(); 
    act = primero;
    if(primero!=NULL){
	  do{
	  	cout<<act->nro<<" -> ";
	  	act=act->sig;
	  }while(act!=primero);
	  		
	  
	}else{
		cout<<"la lista esta vacia";
	}
}

void buscar(nodo*lista,int b){
    bool band = false;
	nodo *act =new nodo();
    act = primero;
    int bus=0;
    cout <<"ingrese el valor que desea buscar\n "; 
    cin>> bus;
   if (act!=NULL)
   {
   	do{
   		if(act->nro==bus){
   			 cout<<"el valor "<<bus<<" encontrado\n";  
   			 band=true;
		   }
		   act=act->sig;
	   }while(act!=primero&&band !=true);
	   if(!band){
	   cout<<"el valor "<<bus<<"no se encuentra\n";
	   }
   }
   else{
   	cout<<"lsta vacia";
   }
	
}

void borrar(){
 bool band = false;
	nodo *act =new nodo();
    act = primero;
    nodo *ant =new nodo();
    ant=NULL;
    int bus=0;
    cout <<"ingrese el valor que desea buscar\n "; 
    cin>> bus;
   if (act!=NULL)
   {
   	do{
   		if(act->nro==bus){
   			 cout<<"el valor "<<bus<<" encontrado\n";  
   			 
   			 if(act==primero){
   			 	primero=primero->sig;
   			 	primero->ant=ultimo;
   			 	ultimo->sig=primero;
   			 	
				}else if(act==ultimo){
					ultimo=ant;
					ultimo->sig=primero;
					primero->ant=ultimo;
				}else{
					ant->sig =act->sig;
					act->sig->ant=ant;
				}
				cout<<"valor eliminado\n ";
				band=true;
		   }
		   ant=act;
		   act=act->sig;
	   }while(act!=primero&&band !=true);
	   if(!band){
	   cout<<"el valor "<<bus<<"no se encuentra\n";
	   }
   }
   else{
   	cout<<"lsta vacia";
   }
	
}
