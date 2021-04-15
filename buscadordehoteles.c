#include <stdio.h>
#include <string.h>
struct ususario {
	char nombre[100];
	int clave;
};
struct reserva {
	int dia;
	int mes;
	char ciudad[100];
	char pais[100];
	char hotel[100];
	float precio;
};

int main() {
	char opcion;
	char opcion2;
	int i, dato, contador=0, comp;
	FILE * fregistro;
	struct usuario usuario[100]
	
	printf("----------------------\n");
	printf("\tMenu:\n");
	printf("R--Registrarse\n");
	printf("I--Iniciar sesion\n");
	printf("S--Salir del programa\n");
	printf("----------------------\n");
	
	printf("Introduzca la opcion: \n");
	fflush(stdin);
	scanf("%c", &opcion);
	
	switch(opcion) {
		case 'r':
		case 'R':
			fregistro=fopen("Registro.txt","r");
			
			if(fregistro == NULL) {
				printf("No se ha podido abrir el fichero Registro correctamente\n");
				return 0;
			}
			
			while(fscanf(fregistro,"%d %s %s %d", &contador+1, usuario[contador].nombre, usuario[contador].clave, &dato) != EOF) {
				printf("%d %s %s %d", contador+1, usuario[contador].nombre, usuario[contador].clave, dato);
				contador++;
			}
			
			i=contador+1;
				
			do{
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",usuario[i].nombre);
				
				for(contador=0; contador<i; contador++) {
					comp=strcmp(usuario[contador].nombre, usuario[i].nombre);
					if(comp==0) {
						printf("El nombre de usuario introducido ya existe\n");
						break;
					}
					
					else if(comp==1) {
						printf("Se ha registrado el nombre introducido\n");
						break;
					}
					
				}
			}
			while(comp=0);			
						
			fclose(fregistro);
			
			fregistro=fopen("Registro.txt","w");
			if(fregistro==NULL) {
				printf("No se ha podido abrir el fichero Registro correctamente\n");
				return 0;
			}
			printf("Introduzca su clave:\n");
			scanf("%d", &usuario[i].clave);
			printf("%d %s %d\n", i, usuario[i].nombre, usuario[i].clave);
			for(i=0; i<=contador; i++) {
				fprintf(fregistro, "%d %s %d\n", i, usuario[i].nombre, usuario[i].clave);
				printf("%d %s %d\n", i, usuario[i].nombre, usuario[i].clave);
			}
			fclose(fregistro);
			break;			
				

			printf("--------------------------\n");
			printf("Que desea hacer?:\n");
			printf("R--Hacer una reserva\n");
			printf("H--Buscar hoteles\n");
			printf("B--Borrar reserva\n");
			printf("C--Consultar Reserva\n");
			printf("A--Seccion de comentarios\n");
			printf("S--Salir del programa\n");
			printf("--------------------------\n");
			
			
				
			do{
				printf("Introduzca la opcion: \n");
				fflush(stdin);
				scanf("%c", &opcion2);
				switch(opcion2) {
					case 'r':
					case 'R':
						printf("Hacer una reserva\n");
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
			break;
		case 'i':
		case 'I':
			
			fregistro=fopen("Registro.txt","r");
			
			if(fregistro == NULL) {
				printf("No se ha podido abrir el fichero Registro correctamente\n");
				return 0;
			}
			
			
			while(fscanf(fregistro,"%d %s %s %d", &contador+1, usuario[contador].nombre, usuario[contador].clave, &dato) != EOF) {
				printf("%d %s %s %d", contador+1, usuario[contador].nombre, usuario[contador].clave, dato);
				contador++;
			}
			
			i=contador+1;
				
			do{
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",usuario[i].nombre);
				
				for(contador=0; contador<=i; contador++) {
					comp=strcmp(usuario[contador].nombre, usuario[i].nombre);
					if(comp==0) {
						do {
							printf("Introduzca su clave para acceder:\n");
							scanf("%d", usuario[i].clave);
							for(contador=0;contador<=i; contador++) {
								if(usuario[i].clave == usuario[contador].clave) {
									printf("Te damos la bienvenida a Buscador de Hoteles\n");
									break;
								}
								else {
									printf("Clave incorrecta, por favor intentelo de nuevo.\n");
									break;
								}
							}
						}
						while(usuario[i].calve != usuario[contador].clave);
						break;
					}
					
					else if(comp==1) {
						printf("Usuario no existente, por favor intentelo de nuevo.\n");
						break;
					}
					
				}
			}
			while(comp==1);
			fclose(fregistro);
			break;	
			
			
			printf("--------------------------\n");
			printf("Que desea hacer?:\n");
			printf("R--Hacer una reserva\n");
			printf("H--Buscar hoteles\n");
			printf("B--Borrar reserva\n");
			printf("C--Consultar Reserva\n");
			printf("A--Seccion de comentarios\n");
			printf("S--Salir del programa\n");
			printf("--------------------------\n");
				
				do{
					printf("Introduzca la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion2);
					switch(opcion2) {
						case 'r':
						case 'R':
							printf("Hacer una reserva\n");
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
				break;
			case 's':
			case 'S':
				printf("Gracias por utilizar este programa\n");
				return 0;
			default:
				printf("La opcion es incorrecta\n");			
		}
	} while (opcion != 'S');
