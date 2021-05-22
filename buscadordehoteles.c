#include <stdio.h>
#include <string.h>
void pancarta();
int menuPrincipal();
int menuSecundario();
struct usuario {
	char nombre[100];
	char clave[10];
};
struct reserva {
	int numHotel;
	int numReserva;
	int dia_llegada;
	int dia_salida;
	int mes_llegada;
	int mes_salida;
	char ciudad[100];
	char pais[100];
	char hotel[100];
	float precio;
	int num_dias;
};

//Menu del trabajo:
int main() {
	char opcion;
	char opcion2;
	int i, j, dato, nUsuarios=0, nHoteles=0, comparador, comparador2;
	struct usuario usuarios[1000];
	struct reserva hoteles[5000];
	char nombre2;
	
	//Leer fichero Registro.txt
	FILE * pregistro;
	pregistro=fopen("Registro.txt","r");
	if(pregistro == NULL) {
		printf("No se ha podido abrir el fichero Registro correctamente\n");
		return 0;
	}
	while(fscanf(pregistro,"%s %s", usuarios[nUsuarios].nombre, usuarios[nUsuarios].clave) != EOF) {
		nUsuarios++;
	}	
	nUsuarios = i;		
	fclose(pregistro);
	
	//Leer fichero .txt
	
	
	//Pancarta
	pancarta();
	
	//Menu principal
	menuPrincipal();
	
	printf("Introduzca la opcion: \n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	switch(opcion) {
		case 'r':
		case 'R':
			//Registro de nuevo usuario
			i=nUsuarios+1;
			
			do{
				//Comprobar si ya existe el usuario:
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",usuarios[i].nombre);
				fflush(stdin);
				
				for(nUsuarios=0; nUsuarios<i; nUsuarios++) {
					comparador=strcmp(usuarios[nUsuarios].nombre, usuarios[i].nombre);
					if(comparador==0) {
						printf("El nombre de usuario introducido ya existe\n");
						break;
					} else if(comparador!=0) {
						printf("Se ha registrado el nombre introducido\n");
						break;
					}
				}
			}while(comparador==0);
			
			if (comparador== 0) {
					strcpy(usuarios[nUsuarios].nombre, usuarios[i].nombre);
			}
            fflush(stdin);
			//Clave
            printf("Introduzca su clave:\n");
			scanf("%s", &usuarios[i].clave);
			
					
			printf("Se ha registrado correctamente\n");
			break;			
			
		case 'i':
		case 'I':
			//Inicio de sesión
			i=nUsuarios+1;
				
			do{
				//Comprobamos que el usuario exista:
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",usuarios[i].nombre);
				fflush(stdin);
				
				for(nUsuarios=0; nUsuarios<i; nUsuarios++) {
					comparador=strcmp(usuarios[nUsuarios].nombre, usuarios[i].nombre);
					if(comparador==0) {
						do {
							//Comprobamos que la contraseña sea correcta
							printf("Introduzca su clave para acceder:\n");
							scanf("%s", usuarios[i].clave);
							for(nUsuarios=0;nUsuarios<i; nUsuarios++) {
								comparador2=strcmp(usuarios[nUsuarios].clave, usuarios[i].clave);
								if(comparador2==0) {
									printf("Te damos la bienvenida a Buscador de Hoteles\n");
									break;
								} else {
									printf("Clave incorrecta, por favor intentelo de nuevo.\n");
									break;
								}
							}
						} while(comparador2!=0);
						
					
					} else if(comparador==1) {
						printf("Usuario no existente, por favor intentelo de nuevo.\n");
						break;
					}
					
				}
			} while(comparador!=0);
			
			break;	
			
		case 's':
		case 'S':
			printf("Gracias por utilizar este programa\n");
			return 0;
		default:
			printf("La opcion es incorrecta\n");
			return 0;			
		}
	//Guardar la memoria en el .txt
    		pregistro = fopen("Registro.txt", "a"); 
    		if(pregistro==NULL) {
				printf("No se ha podido abrir el fichero Registro correctamente\n");
				return 0;
			}
    		for (nUsuarios= 0; nUsuarios < i; nUsuarios++) {
    			fprintf(pregistro, "%s %s\n", usuarios[i].nombre, usuarios[i].clave);
			}
    		fclose(pregistro);
    		fflush(stdin);
    		
    //Menu secundario:
	menuSecundario();
		
	do{
		printf("Introduzca la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion2);
		switch(opcion2) {
			case 'r':
			case 'R':
				printf("Ha seleccionado: hacer una reserva\n");
					i=nUsuarios+1;
					
					//Comprobamos que el usuario exista:
					do{
					printf("Introduzca el nombre de usuario:\n");
					scanf("%s",usuarios[i].nombre);
					fflush(stdin);
					
					for(nUsuarios==0; nUsuarios<i; nUsuarios++) {
					comparador=strcmp(usuarios[nUsuarios].nombre, usuarios[i].nombre);
					if(comparador==0) {
						printf("Se ha confirmado su usuario\n");
						break;
					} else if(comparador!=0) {
						printf("El nombre de usuario no existe\n");
						break;
					}
				}
				}while(comparador!=0);
				
				if (comparador!= 0) {
					strcpy(usuarios[nUsuarios].nombre, usuarios[i].nombre);
			}
			fflush(stdin);
			
			//Nombre
			printf("A nombre de quien desea hacer la reserva:\n");
			scanf("%s", &usuarios[i].nombreReserva);
			
			printf("Se ha hecho la reserva correctamente\n");
				break;
			case 'h':
			case 'H':
				printf("Buscar hoteles\n");
				break;
			case 'b':
			case 'B':
				printf("Borrar reserva\n");
				break;
			case 'c':
			case 'C':
				printf("Consultar reserva\n");
				break;
			case 'a':
			case 'A':
				printf("Seccion de comentarios\n");
				break;			
			case 's':
			case 'S':
				printf("Gracias por utilizar este programa\n");
				return 0;
			default:
				printf("La opcion es incorrecta\n");			
			}
	
	} while (opcion2 != 'S');
}
	
void pancarta(){
	printf("\t\t\t----------------------------------------------------------------------\n");
	printf("\t\t\t\t\t| Bienvenido al buscador de hoteles: |\n");
	printf("\t\t\t-----------------------------------------------------------------------\n");
}

int menuPrincipal(){
	printf("----------------------\n");
	printf("\tMenu:\n");
	printf("R--Registrarse\n");
	printf("I--Iniciar sesion\n");
	printf("S--Salir del programa\n");
	printf("----------------------\n");
}
	
int menuSecundario(){
	printf("--------------------------\n");
	printf("Que desea hacer?:\n");
	printf("R--Hacer una reserva\n");
	printf("H--Buscar hoteles\n");
	printf("B--Borrar reserva\n");
	printf("C--Consultar Reserva\n");
	printf("A--Seccion de comentarios\n");
	printf("S--Salir del programa\n");
	printf("--------------------------\n");
}
