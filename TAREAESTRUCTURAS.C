//librerias a incluir
#include<stdio.h>
#include<stdlib.h>

//definiciones
struct Libro{
	    char* titulo;
        int AniodePublicacion;
        struct Libro *sig;
};

//prototipos
void AgregarNodo(struct Libro **);
void imprimir_lista(struct Libro *);
void ActualizarElemento(struct Libro* );
struct Libro* BuscarUltimo(struct Libro *);
struct Libro* Buscar_elemento_en_lista(struct Libro* ,int,char* );
char* Obtenertitulo();
int Obteneranio();
int lista_vacia(struct Libro*);
int sumar(int*,int);

int main()
{
    struct Libro *raiz=NULL;
    

    int elementos[]={1,2,3,4,5,6,7,8,9,10};
    int tamanio=(sizeof(elementos)/sizeof(int))-1;
    printf("%d",sumar(elementos,tamanio)); 
   
    return 0;
}

void AgregarNodo(struct Libro **raiz)
{
   struct Libro* NuevoElemento =(struct Libro*)malloc(sizeof(struct Libro));
   NuevoElemento->titulo=Obtenertitulo();
   NuevoElemento->AniodePublicacion=Obteneranio();

   //PRIMER CASO-LA LISTA ESTA VACIA (INSERTAR DATO AL PRINCIPIO DE LA LISTA)
    if(lista_vacia(*raiz)==-1)
    {
   		*raiz=NuevoElemento;
    	NuevoElemento->sig=NULL;
    }
    else
    {
    	
    //SEGUNDO CASO-LA LISTA NO ESTA VACIA (INSERTAR UN DATO AL FINAL DE LA LISTA)
    struct Libro* temporal=BuscarUltimo(*raiz);
    temporal->sig=NuevoElemento;
    
	}

}

int lista_vacia(struct Libro* lista)
{
    if(lista==NULL)
        return -1;
    else
        return 1;
}

struct Libro* Buscar_elemento_en_lista(struct Libro* lista,int valor,char* nombre)
{
	struct Libro* temporal;
	temporal=lista;
    if(lista_vacia(lista)!=-1)
    {
     while( temporal!=NULL && temporal->AniodePublicacion!=valor && temporal->titulo!=nombre )
 	{
 		temporal=temporal->sig;
	}
	return temporal;
    }
    else{
        printf("NO HAY ELEMENTOS EN LA LISTA, ASEGURATE DE HABER INGRESADO ELEMENTOS PRIMERO"); 
        break;
    }
 	
	
}

void ActualizarElemento(struct Libro* lista)
{
	struct Libro* actualizado;
	int anio=0,anionuevo=0;
	char *nombre=(char*)malloc(sizeof(char));
	char *nombrenuevo=(char*)malloc(sizeof(char));
	
	printf("INGRESA EL TITULO DEL LIBRO QUE BUSCAS: ");
	scanf("%s",nombre);
	printf("INGRESA EL ANIO DE PUBLICACION DEL LIBRO QUE BUSCAS:");
	scanf("%d",&anio);
	printf("INGRESA EL NUEVO TITULO DEL LIBRO : ");
	scanf("%s",nombrenuevo);
	printf("INGRESA EL NUEVO ANIO DE PUBLICACION DEL LIBRO:");
	scanf("%d",&anionuevo);
	
	actualizado=Buscar_elemento_en_lista(lista,anio,nombre);
	actualizado->titulo=nombrenuevo;
	actualizado->AniodePublicacion=anionuevo;
	
}

int Obteneranio()
{
	int valor=0;
	printf("INGRESA EL ANIO DE UBLICACION DEL LIBRO : ");
	scanf("%d",&valor);
	return valor;
}

char* Obtenertitulo()
{
	char *titulo=(char*)malloc(sizeof(char));
	printf("INGRESA EL TITULO DEL LIBRO : ");
	scanf("%s",titulo);
	return titulo;
}

struct Libro* BuscarUltimo(struct Libro *raiz)
{
	struct Libro *temporal;
    temporal=raiz;
    while(temporal->sig!=NULL)
    {
      temporal=temporal->sig;
    }  	
	return temporal; 
}

void imprimir_lista(struct Libro *raiz)
{
	printf("------------------------LOS ELEMENTOS EN TU LISTA SON------------------------\n");
	struct Libro* temporal;
	temporal=raiz;
	while(temporal!=NULL)
	{
		printf("EL TITULO ES: %s\n",temporal->titulo);
		printf("SU ANIO DE PUBLICACION ES: %d\n",temporal->AniodePublicacion);
		printf("\n");
		temporal=temporal->sig;
	}
}



int sumar(int* elementos,int n)
{
   if(n==0)
   		return elementos[n];
   else
   {
   		return elementos[n]+sumar(elementos,n-1);
   }
}
