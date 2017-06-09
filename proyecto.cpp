/*
NOMBRE: --> YEISSON ESTIVEN 
APELLIDO: -->CASTRO CARDONA
ASIGNATUARA: Estrutura de datos
Proyecto final 
imformacion:
metodos de ordenamiento 
-burbuja
-quisort
-shell
-mezcla
busqueda
-Busqueda secuencial
-busqueda Binaria
archivo.txt
fecha: 09/06/2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int max = 1000;
int tamano,i,arreglo[max];

void menu();

void crearLista();

void crearListaRad();

void metodoBorbuja();

void Quicksort(int* arr, int izq, int der);

void metodoshell();

void mezcla(int vector[], int n);

void ordenar_numeros(int arreglo[], int lon);

void busquedaSecuencial();


void busquedaBinaria();

void mostrarlista();

int main(){
	
    
    menu();
    return 0;
}


void menu(){
    int opcion;
    do{
    	printf("\n|---------------------------------|");
        printf("\n|--------------MENU---------------|");
        printf("\n|---------------------------------|");
        printf("\n|1. Crear lista  personal         |");
        printf("\n|2. Crear una lista  ramdon       |");
        printf("\n|3. Mostrar lista                 |");
        printf("\n|4. Metodo borbuja                |");
        printf("\n|5. Metodo rapido                 |");
        printf("\n|6. Metodo shell                  |");
        printf("\n|7. Metodo mezcla                 |");
        printf("\n|8. Ordenar de abajo hacia arriba |");
        printf("\n|9. Busqueda secuencial           |");
        printf("\n|10.Busqueda binaria              |");
        printf("\n|0. Salir                         |");
        printf("\n|---------------------------------|");
        printf("\nIngrese una opcion:");
        scanf("%d", &opcion);
        switch(opcion){
            case 1: crearLista();
                break;
            case 2: crearListaRad();
                break;
            case 3: mostrarlista();
                break;
            case 4: metodoBorbuja();
                break;
            case 5: Quicksort(arreglo, 0, tamano);
                break;
            case 6: metodoshell();
                break;
            case 7: mezcla(arreglo,tamano);
            	break;
            case 8: ordenar_numeros(arreglo, tamano); 
            	break;
            case 9: busquedaSecuencial();
            	break;
            case 10: busquedaBinaria();
                break;
            case 0: exit(0);
                break;
            default: printf("\nOpcion Invalidad\n");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void crearLista(){
	system("pause");
    system("cls");
	
	printf("|-----------------------------------------------------|\n");
	printf("| Ingrese el tamaño y los numeros que desa ingrear    |\n");
	printf("|                                                     |\n");
	printf("|-----------------------------------------------------|\n");
	
		printf("ingrese el tamaño de la lista: ");
	scanf("%d",&tamano);
	
	for(i=0;i<tamano;i++){
		printf("Ingrese el Elemento : ");
		scanf("%d",&arreglo[i]);
		}
	
	
}

void crearListaRad(){
	
    
	  clock_t t_ini, t_fin;
  double secs;

  t_ini = clock();
  	int tamano;
	printf("ingrese el tamaño de la lista: ");
	scanf("%d",&tamano);
    int i= 0;
    int arreglo[tamano];
    srand(time(NULL));
    while(i <= tamano){
        arreglo[i]=rand()*(99999-(-99999)+1)+(-99999);
         i+= 1;
    }
    
    
    for(int i=0;i<tamano;i++) {
    	printf("%d\n",arreglo[i]);
    }
    printf("\nlista ordenada\n");
    int j,aux;
		for(i=1; i<tamano; i++){
		
		for(j=0; j<tamano-i; j++){
			
			if(arreglo[j]>arreglo[j+1]){
			    aux    = arreglo[j+1];
				arreglo[j+1] = arreglo[j];
				arreglo[j]   = aux;
			}
		}
	}
	for(int i=0;i<tamano;i++) {
    	printf("%d\n",arreglo[i]);
    }
  t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
}

void metodoBorbuja(){
 clock_t t_ini, t_fin;
  double secs;

  t_ini = clock();
  	int i,j,aux;
		for(i=1; i<tamano; i++){
		
		for(j=0; j<tamano-i; j++){
			
			if(arreglo[j]>arreglo[j+1]){
			    aux    = arreglo[j+1];
				arreglo[j+1] = arreglo[j];
				arreglo[j]   = aux;
			}
		}
	}
	
  t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
	
}
void Quicksort(int* arr, int izq, int der) { 
 clock_t t_ini, t_fin;
  double secs;

  t_ini = clock();
  int i = izq, j = der, tmp; 
     int p = arr[(izq + der) / 2]; 

     while (i <= j) 
     { 
          while (arr[i] < p) i++; 
          while (arr[j] > p) j--; 
          if (i <= j) 
           { 
               tmp = arr[i]; 
               arr[i] = arr[j]; 
               arr[j] = tmp; 
               i++; j--; 
          } 
     } 

     if (izq < j) 
          Quicksort(arr, izq, j); 
     if (i < der) 
          Quicksort(arr, i, der); 
  
  t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
     
} 

void metodoshell(){
	clock_t t_ini, t_fin;
	double secs;

  t_ini = clock();
  int cont,pasos,temp,i;
 
	for(cont=tamano/2;cont!=0;cont/=2)
		for(pasos=1;pasos!=0;){
			pasos=0;
			for(i=cont;i<tamano;i++)
				if(arreglo[i-cont]>arreglo[i]){
					temp=arreglo[i];
					arreglo[i]=arreglo[i-cont];
					arreglo[i-cont]=temp;
					pasos++;
				}
		}
	
  t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
}


void mezclar(int arreglo1[], int n1, int arreglo2[], int n2, int arreglo3[]){
    int x1=0, x2=0, x3=0;

    while (x1<n1 && x2<n2) {
        if (arreglo1[x1]<arreglo2[x2]) {
            arreglo3[x3] = arreglo1[x1];
            x1++;
        } else {
            arreglo3[x3] = arreglo2[x2];
            x2++;
        }
        x3++;
    }
    while (x1<n1) {
        arreglo3[x3] = arreglo1[x1];
        x1++;
        x3++;
    }
    while (x2<n2) {
        arreglo3[x3] = arreglo2[x2];
        x2++;
        x3++;
    }
}

void mezcla(int vector[], int n){
    int *vector1, *vector2, n1, n2,x,y;
    if (n>1){
        if (n%2 == 0)
            n1=n2=(int) n / 2;
        else{
            n1=(int) n / 2;
            n2=n1+1;
        }
        vector1=(int *) malloc(sizeof(int)*n1);
        vector2=(int *) malloc(sizeof(int)*n2);
        for(x=0;x<n1;x++)
            vector1[x]=vector[x];
        for(y=0;y<n2;x++,y++)
            vector2[y]=vector[x];
        mezcla(vector1, n1);
        mezcla(vector2, n2);
        mezclar(vector1, n1, vector2, n2, vector);
        free(vector1);
        free(vector2);
    }
}
void ordenar_numeros(int arreglo[], int lon){ 
        int Temp; 
         for(int i=0;i<lon;i++) 
                for(int j=0;j<lon-1;j++) 
                    if(arreglo[j]<arreglo[j+1]){// cambia "<" a ">" para cambiar la manera de ordenar 
                        Temp=arreglo[j]; 
                        arreglo[j]=arreglo[j+1]; 
                        arreglo[j+1]=Temp;} 

                 for(int i=0;i<lon;i++) 
                    printf("%d",arreglo[i] );
                        }


void busquedaSecuencial(){
	int i, dato=0;

bool estado = false;

printf("dame un dato a buscarn : "); 
scanf("%d",&dato); 

	for(i=0;i<tamano;i++) {
		if(arreglo[i]==dato) {
			estado =true;
			break;
		}
	}
	if(estado == true) {
		printf("dato enconntrado");
		
	}else{
		printf("dato no encontrado");
	}
}

void busquedaBinaria(){
	
	int inf,sup,mitad,dato,n=tamano,i; 

bool estado = false;

printf("ingrese numero ah buscar : "); 
scanf("%d",&dato); 
inf=0; 
sup=n; 
i=0;
while (inf<=sup && i<10){ 
	mitad=(inf+sup)/2; 
		if (arreglo[mitad]==dato) {  
				estado =true;
				break; 
		} 
		if (arreglo[mitad]>dato){ 
					sup=mitad; 
		} 
		if (arreglo[mitad]<dato){ 
				inf=mitad; 
		} 
	i++;		
	}

printf("dato %d encontrado posicion %d",dato,mitad);
	
}

void mostrarlista(){
	for(i=0;i<tamano;i++){
		printf(" \n %d\n",arreglo[i]);
	}
	
}
