#include <stdio.h>
#include <string.h>
void pancarta();
int menuPrincipal();
int menuSecundario();
int menuPaises();
int menuCiudadesEspannya();
int menuCiudadesFrancia();
int menuCiudadesItalia();
int menuCiudadesInglaterra();
int menuCiudadesAlemania();
int menuCiudadesPortugal();
int menuPreciosMadrid();
int menuPreciosBarcelona();
int menuPreciosParis();
int menuPreciosLyon();
int menuPreciosRoma();
int menuPreciosVenecia();
int menuPreciosLondres();
int menuPreciosBath();
int menuPreciosBerlin();
int menuPreciosMunich();
int menuPreciosLisboa();
int menuPreciosOporto();


struct usuario {
	char nombre[100];
	char clave[10];
};
struct reserva {
	int dia_llegada;
	int dia_salida;
	int mes_llegada;
	int mes_salida;
	int numReferencia;
	char nombreReserva[100];
	
};
struct hotel {
	int numHotel;
	char pais[100];	
	char ciudad[100];
	char hotel[100];	
	float precio;
};
struct comentario {
	char mensaje[200];
};

int datosUsuarios(struct usuario usuarios[]);
int seccionComentarios(struct comentario comentarios[]);
int datosReservas(struct reserva reservas[]);
//int datosHoteles(struct hotel hoteles[]);

//Menu del trabajo:
int main() {
	char opcion, opcion2;
	int opcionComentarios;
	int opcion3, opcion4, opcion5, opcion6, opcion7, opcion8, opcion9;
	int i, r, h, j=0, k, dato, nUsuarios, nComentarios=0, nReservas=0, nHoteles, comparador, comparador2;
	struct usuario usuarios[100];
	struct comentario comentarios[5000];
	struct reserva reservas[1000];
	struct hotel hoteles[1000];
	
	//Leer fichero Registro.txt
	nUsuarios = datosUsuarios(usuarios);
	
	//Leer fichero Comentarios.txt
	nComentarios = seccionComentarios(comentarios);
	
	//Leer fichero Reserva.txt
	nReservas = datosReservas(reservas);
	
	//Leer fichero Hoteles.txt
//	nHoteles = datosHoteles(hoteles);
	
	
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
				//nUsuarios++;
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
			//Inicio de sesi�n
			j=nUsuarios+1;
				
			do{
				//Comprobamos que el usuario exista:
				printf("Introduzca el nombre de usuario:\n");
				scanf("%s",usuarios[j].nombre);
				fflush(stdin);
				
				for(nUsuarios=0; nUsuarios<j; nUsuarios++) {
					comparador=strcmp(usuarios[nUsuarios].nombre, usuarios[j].nombre);
					if(comparador==0) {
						do {
							//Comprobamos que la contrase�a sea correcta
							printf("Introduzca su clave para acceder:\n");
							scanf("%s", usuarios[j].clave);
							for(nUsuarios=0;nUsuarios<j; nUsuarios++) {
								comparador2=strcmp(usuarios[nUsuarios].clave, usuarios[j].clave);
								if(comparador2==0) {
									printf("Te damos la bienvenida a Buscador de Hoteles\n");
									break;
								} else {
									printf("Clave incorrecta, por favor intentelo de nuevo.\n");
									break;
								}
							}
						} while(comparador2!=0);
						
						break;
					} else if(comparador!=0) {
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
			FILE * pregistro;
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
	do{
		menuSecundario();
		printf("Introduzca la opcion: \n");
		fflush(stdin);
		scanf("%c", &opcion2);
		switch(opcion2) {
			case 'r':
			case 'R':
				printf("Ha seleccionado: hacer una reserva\n");
				
				//Numero de referencia del hotel
				printf("Introduzca el numero de referencia del hotel, si no lo sabe, reinicie el programa y seleccione la opcion 'Buscar hoteles'\n");
				scanf("%d", &reservas[nReservas].numReferencia);
			
	            
				do {
					//Nombre	
					printf("A nombre de quien desea hacer la reserva:\n");
					scanf("%s", &reservas[nReservas].nombreReserva);
					for (r=0; r<nReservas; r++) {
						if (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)==0) {
							printf("Ya existe ese nombre, intentelo de nuevo.\n");
							break;
						} else if (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)!=0) {
							printf("Nombre de reserva aceptado, puede continuar.\n");
							
							break;
						}
					}					
				} while (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)==0);
				//Fechas
				printf("Introduzca el dia de llegada:\n");
				scanf("%d", &reservas[nReservas].dia_llegada);
				printf("Introduzca el mes de llegada (en numeros):\n");
				scanf("%d", &reservas[nReservas].mes_llegada);
				printf("Introduzca el dia de salida:\n");
				scanf("%d", &reservas[nReservas].dia_salida);
				printf("Introduzca el mes de salida (en numeros):\n");
				scanf("%d", &reservas[nReservas].mes_salida);
				
				printf("Se ha hecho la reserva correctamente\n");	
				break;
			case 'h':
			case 'H':
				printf("Ha seleccionado: Buscar hoteles\n");
				menuPaises();
				printf("Introduzca la opcion: \n");
				fflush(stdin);
				scanf("%c", &opcion3);
				switch(opcion3) {
					case '1':
						printf("Ha elegido Espannya como lugar de destino\n");
						menuCiudadesEspannya();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion4);
						switch(opcion4) {
							case '1': 
								printf("Ha elegido Madrid como lugar de destino\n");
								menuPreciosMadrid();
							    break;
							case '2': 
								printf("Ha elegido Barcelona como lugar de destino\n");
								menuPreciosBarcelona();
								break;
						}
						break;
					case '2':
						printf("Ha elegido Francia como lugar de destino\n");
						menuCiudadesFrancia();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion5);
						switch(opcion5) {
							case '1': 
								printf("Ha elegido París como lugar de destino\n");
								menuPreciosParis();
							    break;
							case '2': 
								printf("Ha elegido Lyon como lugar de destino\n");
								menuPreciosLyon();
								break;
						}
						break;
					case '3':
						printf("Ha elegido Italia como lugar de destino\n");
						menuCiudadesItalia();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion6);
						switch(opcion6) {
							case '1': 
								printf("Ha elegido Roma como lugar de destino\n");
								menuPreciosRoma();
							    break;
							case '2': 
								printf("Ha elegido Venecia como lugar de destino\n");
								menuPreciosVenecia();
								break;
						}
						break;
					case '4':
						printf("Ha elegido Inglaterra como lugar de destino\n");
						menuCiudadesInglaterra();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion7);
						switch(opcion7) {
							case '1': 
								printf("Ha elegido Londres como lugar de destino\n");
								menuPreciosLondres();
							    break;
							case '2': 
								printf("Ha elegido Bath como lugar de destino\n");
								menuPreciosBath();
								break;
						}
						break;
					case '5':
						printf("Ha elegido Alemania como lugar de destino\n");
						menuCiudadesAlemania();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion8);
						switch(opcion8) {
							case '1': 
								printf("Ha elegido Berlín como lugar de destino\n");
								menuPreciosBerlin();
							    break;
							case '2': 
								printf("Ha elegido Múnich como lugar de destino\n");
								menuPreciosMunich();
								break;
						}
						break;
					case '6':
						printf("Ha elegido Portugal como lugar de destino\n");
						menuCiudadesPortugal();
						printf("Introduzca la opcion: \n");
						fflush(stdin);
						scanf("%c", &opcion9);
						switch(opcion9) {
							case '1': 
								printf("Ha elegido Lisboa como lugar de destino\n");
								menuPreciosLisboa();
							    break;
							case '2': 
								printf("Ha elegido Oporto como lugar de destino\n");
								menuPreciosOporto();
								break;
						}
						break;
				}
				break;
			case 'b':
			case 'B':
				printf("Borrar reserva\n");
				break;
			case 'c':
			case 'C':
				printf("Ha seleccionado: consultar reserva\n");
				do {
					//Nombre	
					printf("Introduzca el nombre con el que hizo la reserva:\n");
					scanf("%s", &reservas[nReservas].nombreReserva);
					for (r=0; r<nReservas; r++) {
						if (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)==0) {
							printf("El nombre de reserva introducido es correcto.\n");
							printf("Para el nombre: %s\tFecha de llegada:%d / %d \t Fecha de salida:%d / %d \t Numero de referencia del hotel:%d\n", reservas[r].nombreReserva, reservas[r].dia_llegada, reservas[r].mes_llegada, reservas[r].dia_salida, reservas[r].mes_salida, reservas[r].numReferencia);
							break;
						} else if (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)!=0) {
							printf("Nombre de reserva aceptado no existente, intentelo de nuevo.\n");
							break;
						}
					}					
				} while (strcmp(reservas[nReservas].nombreReserva, reservas[r].nombreReserva)!=0);
				
				break;
			case 'a':
			case 'A':
				printf("Ha seleccionado la opcion: 'Seccion de comentarios'\n");
				printf("Si desea leer comentarios pulse 1\n");
				printf("Si desea escribir un comentario pulse 2\n");
				scanf("%d", &opcionComentarios);
				switch(opcionComentarios) {
					case 1:
						for (k = 0; k < nComentarios; k++) {
								printf("%s", comentarios[k].mensaje);
								printf("\n");
						}
						break;
					case 2:
						printf("Escriba su comentario, para ello ponga una barra baja (_) entre las palabras (donde deberia ir el espacio):\n");
						scanf("%s", &comentarios[nComentarios].mensaje);
						break;
					default:
						printf("La opcion es incorrecta\n");
				}
				break;			
			case 's':
			case 'S':
				//Salir del programa
				

				
				printf("Gracias por utilizar este programa\n");
				return 0;
			default:
				printf("La opcion es incorrecta\n");			
		}
			
		

	} while (opcion2 != 'S' && opcion2 != 's');
	
	//Guardar la memoria en Comentarios.txt
		FILE * fentrada;
		fentrada = fopen("Comentarios.txt", "a");
		if (fentrada == NULL) {
			printf("No se ha podido abrir el fichero Comentarios correctamente\n");
			return 0;
		}	
		for (nComentarios=0; nComentarios<k; nComentarios++) {
			fprintf(fentrada, "%s\n", comentarios[k].mensaje);
		}	
		fclose(fentrada);
		fflush(stdin);
		
		//Guardar memoria en Reserva.txt
		FILE * freserva;
		freserva = fopen("Reserva.txt", "a");
		if (fentrada == NULL) {
			printf("No se ha podido abrir el fichero Reserva correctamente\n");
			return 0;
		}
		for (nReservas=0; nReservas<r; nReservas++) {
			fprintf(freserva,"%s %d %d %d %d %d\n", reservas[r].nombreReserva, &reservas[r].dia_llegada, &reservas[r].mes_llegada, &reservas[r].dia_salida, &reservas[r].mes_salida, &reservas[r].numReferencia);
		}
		fclose(freserva);
		fflush(stdin);
	
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
int datosUsuarios(struct usuario usuarios[]) {
	//Leer fichero .txt
	int nUsuarios = 0, i=0;
	FILE * pregistro;
	pregistro = fopen("Registro.txt", "r");
	if (pregistro == NULL){
		printf("No se ha podido abrir el fichero Registro correctamente\n");
		return 0;
	}
	while (fscanf(pregistro, "%s %s", usuarios[i].nombre, usuarios[i].clave) != EOF) {
		//printf("%s %s\n", usuarios[i].nombre, usuarios[i].clave);
		i++;
		nUsuarios++;
	}
	fclose(pregistro);
	return nUsuarios;
}
int seccionComentarios(struct comentario comentarios[]) {
	//Leer fichero Comentarios.txt
	int nComentarios = 0, k=0;
	FILE * fentrada;
	fentrada = fopen("Comentarios.txt", "r");
	if (fentrada == NULL) {
		printf("No se ha podido abrir el fichero Comentarios correctamente\n");
		return 0;
	}	
	while (fscanf(fentrada, "%s", comentarios[k].mensaje) != EOF) {
		k++;
		nComentarios++;
	} 
	fclose(fentrada);
	return nComentarios;
}
int datosReservas(struct reserva reservas[]) {
	//Leer fichero Reserva.txt
	int nReservas = 0, r=0;
	FILE * freserva;
	freserva = fopen("Reserva.txt", "r");
	if (freserva == NULL) {
		printf("No se ha podido abrir el fichero Reserva correctamente\n");
		return 0;
	}
	while (fscanf(freserva, "%s %d %d %d %d %d", reservas[r].nombreReserva, &reservas[r].dia_llegada, &reservas[r].mes_llegada, &reservas[r].dia_salida, &reservas[r].mes_salida, &reservas[r].numReferencia) != EOF) {
		r++;
		nReservas++;
	}
	fclose(freserva);
	return nReservas;
}
/*
int datosHoteles(struct hotel hoteles[]) {
	int nHoteles = 0, h=0;
	FILE * fhoteles;
	fhoteles = fopen("Reserva.txt", "r");
	if (fhoteles == NULL) {
		printf("No se ha podido abrir el fichero Reserva correctamente\n");
		return 0;
	}
	while (fscanf(fhoteles, "%d %s %s %s %f", &hoteles[h].numHotel, hoteles[h].pais, hoteles[h].ciudad, hoteles[h].hotel, &hoteles[h].precio) != EOF) {
		h++;
		nHoteles++;
	}
	fclose(fhoteles);
	return nHoteles;
}*/

int menuPaises() {
	printf("--------------------------------\n");
	printf("Seleccione un país de destino:\n");
	printf("1--Espannya\n");
	printf("2--Francia\n");
	printf("3--Italia\n");
	printf("4--Inglaterra\n");
	printf("5--Alemania\n");
	printf("6--Portugal\n");
	printf("--------------------------------\n");
}

int menuCiudadesEspannya() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--Madrid\n");
	printf("2--Barcelona\n");
	printf("----------------------------------------\n");
}

int menuCiudadesFrancia() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--París\n");
	printf("2--Lyon\n");
	printf("----------------------------------------\n");
}

int menuCiudadesItalia() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--Roma\n");
	printf("2--Venecia\n");
	printf("----------------------------------------\n");
}

int menuCiudadesInglaterra() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--Londres\n");
	printf("2--Bath\n");
	printf("----------------------------------------\n");
}

int menuCiudadesAlemania() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--Berlín\n");
	printf("2--Múnich\n");
	printf("----------------------------------------\n");
}

int menuCiudadesPortugal() {
	printf("----------------------------------------\n");
	printf("Ahora seleccione una ciudad de destino:\n");
	printf("1--Lisboa\n");
	printf("2--Oporto\n");
	printf("----------------------------------------\n");
}

int menuPreciosMadrid() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--74.00 euros/noche\tNH_Hotels\tNumero de referencia:1\n");
	printf("2--105.30 euros/noche\tFour_Seasons\tNumero de referencia:2\n");
	printf("3--53.00 euros/noche\tAirbnb\tNumero de referencia:3\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosBarcelona() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--64.00 euros/noche\tHotel_Vela\tNumero de referencia:4\n");
	printf("2--42.90 euros/noche\tAirbnb\tNumero de referencia:5\n");
	printf("3--76.30 euros/noche\tEl_Palace\tNumero de referencia:6\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosParis() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--64.35 euros/noche\tAirbnb\tNumero de referencia:7\n");
	printf("2--76.96 euros/noche\tElysees\tNumero de referencia:8\n");
	printf("3--68.73 euros/noche\tNovotel\tNumero de referencia:9\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosLyon() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--46.52 euros/noche\tAirbnb\tNumero de referencia:10\n");
	printf("2--52.13 euros/noche\tFourviere\tNumero de referencia:11\n");
	printf("3--41.23 euros/noche\tLagrange\tNumero de referencia:12\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosRoma() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--47.23 euros/noche\tAirbnb\tNumero de referencia:13\n");
	printf("2--34.56 euros/noche\tNH\tNumero de referencia:14\n");
	printf("3--64.23 euros/noche\tMelia\tNumero de referencia:15\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosVenecia() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--53.21 euros/noche\tIbis\tNumero de referencia:16\n");
	printf("2--60.20 euros/noche\tHilton\tNumero de referencia:17\n");
	printf("3--52.03 euros/noche\tAirbnb\tNumero de referencia:18\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosLondres() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--69.05 euros/noche\tPremier_Inn\tNumero de referencia:19\n");
	printf("2--42.06 euros/noche\tIbis\tNumero de referencia:20\n");
	printf("3--46.05 euros/noche\tAirbnb\tNumero de referencia:21\n");
	printf("-----------------------------------------------------------------\n");
}
int menuPreciosBath() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--50.23 euros/noche\tNH\tNumero de referencia:22\n");
	printf("2--32.75 euros/noche\tAirbnb\tNumero de referencia:23\n");
	printf("3--42.35 euros/noche\tHoliday_Inn24\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosBerlin() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--50.00 euros/noche\tRadisson_Blu_Hotel\tNumero de referencia:25\n");
	printf("2--42.30 euros/noche\tNook\tNumero de referencia:26\n");
	printf("3--46.78 euros/noche\tMelia\tNumero de referencia:27\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosMunich() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--38.20 euros/noche\tNH\tNumero de referencia:28\n");
	printf("2--32.45 euros/noche\tAirbnb\tNumero de referencia:29\n");
	printf("3--46.80 euros/noche\tAmba\tNumero de referencia:30\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosLisboa() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--40.30 euros/noche\tAirbnb\tNumero de referencia:31\n");
	printf("2--32.60 euros/noche\tNH\tNumero de referencia:32\n");
	printf("3--60.13 euros/noche\tLuxury\tNumero de referencia:33\n");
	printf("-----------------------------------------------------------------\n");
}

int menuPreciosOporto() {
	printf("-----------------------------------------------------------------\n");
	printf("Para este destino, ofrecemos los siguientes hoteles:\n");
	printf("Recuerde el numero de referencia para poder hacer una reserva\n");
	printf("1--60.00 euros/noche\tAvid\tNumero de referencia:34\n");
	printf("2--43.20 euros/noche\tAirbnb\tNumero de referencia:35\n");
	printf("3--52.23 euros/noche\tMelia\tNumero de referencia:36\n");
	printf("-----------------------------------------------------------------\n");
}
