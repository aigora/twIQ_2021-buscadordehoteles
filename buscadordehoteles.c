#include <stdio.h>
#include <string.h>
struct ususario {
	char nombre[100];
	int clave;
}

int main() {
	char opcion;
	char opcion2;
	int i, dato;
	FILE * fregistro;
	struct usuario crear[100]
	
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
			printf("Aqui el usuario se registraria\n");
			fregistro=fopen("Registro.txt","r");
			
			if(fregistro == NULL) {
				printf("No se ha podido abrir el fichero Registro correctamente\n");
				return 0;
			}
			
			fscanf(fregistro,"%d",&dato);			
			fclose(fregistro);
			printf("El dato leido es %d\n", dato);
			
			
			while(
				
			do{
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",crear[i].nombre);
				

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
			printf("Aqui el usuario iniciaria sesion\n");

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
	do{
		
		
	
	
	
	
}
