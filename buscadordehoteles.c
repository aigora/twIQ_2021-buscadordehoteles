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
	char nombreReserva[100];
	int numReserva;
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

struct comentario {
	char mensaje[200];
};

//Menu del trabajo:
int main() {
	char mensaje[200];
	char opcion, opcion2, opcion3, opcion4, opcion5, opcion6, opcion7, opcion8, opcion9, opcion10, opcion11, opcion12, opcion13, opcion14, opcion15, opcion16, opcion17, opcion18, opcion19, opcion20, opcion21;
	int i, j, opcionComentario, dato, nUsuarios=0, nReservas=0, nHoteles=0, nComentarios=0, comparador, comparador2, comparador3, comparador4, comparador5;
	struct usuario usuarios[1000];
	struct reserva hoteles[5000];
	struct comentario comentarios[5000];
	
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
	
	// Lectura del fichero Hoteles.txt
	FILE * fhoteles;
	fhoteles = fopen("Hoteles.txt", "r");
	if (fhoteles == NULL) {
		printf("No se ha podido abrir el fichero Hoteles correctamente\n");
		return 0;
	}		
	while (fscanf(fhoteles, "%d %c %c %c %f", &hoteles[nHoteles].numHotel, hoteles[nHoteles].pais, hoteles[nHoteles].ciudad, hoteles[nHoteles].hotel, &hoteles[nHoteles].precio) != EOF) {
		nHoteles++;
	} 
	fclose(fhoteles);
	
	//Leer fichero Comentarios.txt
	FILE * fentrada;
	fentrada = fopen("Comentarios.txt", "r");
	if (fentrada == NULL) {
		printf("No se ha podido abrir el fichero Comentarios correctamente\n");
		return 0;
	}	
	while (fscanf(fentrada, "%s", comentarios[nComentarios].mensaje) != EOF) {
		nComentarios++;
	} 
	fclose(fentrada);
	
	//Leer fichero Reserva.txt
	FILE*freserva;
	freserva = fopen("Reserva.txt", "r");
	if (freserva == NULL) {
		printf("No se ha podido abrir el fichero Reserva correctamente\n");
		return 0;
	}
	while (fscanf(freserva, "%d %d %d %d %d %d", &hoteles[nHoteles].numReserva, &hoteles[nHoteles].mes_llegada, &hoteles[nHoteles].dia_llegada, &hoteles[nHoteles].mes_salida, &hoteles[nHoteles].dia_salida, &hoteles[nHoteles].numHotel) != EOF) {
		nReservas++;
	}
	fclose(freserva);
	
	
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
			//Inicio de sesi�n
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
							//Comprobamos que la clave sea correcta
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
					
				do{
					printf("Introduzca el nombre de usuario:\n");
					scanf("%s",usuarios[i].nombre);
					fflush(stdin);
					
					for(nUsuarios==0; nUsuarios<i; nUsuarios++) {
					comparador=strcmp(usuarios[nUsuarios].nombre, usuarios[i].nombre);
						if(comparador==1) {
							printf("Se ha confirmado su usuario\n");
							break;
						} else if(comparador==0) {
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
				printf("Ha seleccionado: Buscar hoteles\n");
				do {
					menuPaises();
					printf("Introduzca la opcion: \n");
					fflush(stdin);
					scanf("%c", &opcion3);
					switch(opcion3) {
						case '1':
							printf("Ha elegido Espannya como lugar de destino\n");
							do {
								menuCiudadesEspannya();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion4);
								switch(opcion4) {
									case '1': 
										printf("Ha elegido Madrid como lugar de destino\n");
										do {
											menuPreciosMadrid();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion5);
											switch(opcion5) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													//Hay que añadir scanf para mes, dia y hora de ida he igual de salida
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										} while(opcion5<1 || opcion5>3);
									    break;
									case '2': 
										printf("Ha elegido Barcelona como lugar de destino\n");
										do {
											menuPreciosBarcelona();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion6);
											switch(opcion6) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										} while(opcion6<1 || opcion6>3);
										break;
								}
							} while(opcion4<1 || opcion4>2);
							break;
						case '2':
							printf("Ha elegido Francia como lugar de destino\n");
							do {
								menuCiudadesFrancia();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion7);
								switch(opcion7) {
									case '1': 
										printf("Ha elegido París como lugar de destino\n");
										do {
											menuPreciosParis();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion8);
											switch(opcion8) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										} while(opcion8<1 || opcion8>3);
									    break;
									case '2': 
										printf("Ha elegido Lyon como lugar de destino\n");
										do {
											menuPreciosLyon();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion9);
											switch(opcion9) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										} while(opcion9<1 || opcion9>3);
										break;
								}
							}  while(opcion7<1 || opcion7>2);
							break;
						case '3':
							printf("Ha elegido Italia como lugar de destino\n");
							do {
								menuCiudadesItalia();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion10);
								switch(opcion10) {
									case '1': 
										printf("Ha elegido Roma como lugar de destino\n");
										do {
											menuPreciosRoma();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion11);
											switch(opcion11) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion11<1 || opcion11>3);
									    break;
									case '2': 
										printf("Ha elegido Venecia como lugar de destino\n");
										do {
											menuPreciosVenecia();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion12);
											switch(opcion12) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion12<1 || opcion12>3);
										break;
								}
					        }while(opcion10<1 || opcion10>2);
							break;
						case '4':
							printf("Ha elegido Inglaterra como lugar de destino\n");
							do {
								menuCiudadesInglaterra();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion13);
								switch(opcion13) {
									case '1': 
										printf("Ha elegido Londres como lugar de destino\n");
										do {
											menuPreciosLondres();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion14);
											switch(opcion14) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion14<1 || opcion14>3);
									    break;
									case '2': 
										printf("Ha elegido Bath como lugar de destino\n");
										do {
											menuPreciosBath();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion15);
											switch(opcion15) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion15<1 || opcion15>3);
										break;
								}
							}while(opcion13<1 || opcion13>2);
							break;
						case '5':
							printf("Ha elegido Alemania como lugar de destino\n");
							do {
								menuCiudadesAlemania();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion16);
								switch(opcion16) {
									case '1': 
										printf("Ha elegido Berlín como lugar de destino\n");
										do {
											menuPreciosBerlin();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion17);
											switch(opcion17) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion17<1 || opcion17>3);
									    break;
									case '2': 
										printf("Ha elegido Múnich como lugar de destino\n");
										do {
											menuPreciosMunich();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion18);
											switch(opcion18) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion18<1 || opcion18>3);
										break;
								}
							}while(opcion16<1 || opcion16>2);
							break;
						case '6':
							printf("Ha elegido Portugal como lugar de destino\n");
							do {
								menuCiudadesPortugal();
								printf("Introduzca la opcion: \n");
								fflush(stdin);
								scanf("%c", &opcion19);
								switch(opcion19) {
									case '1': 
										printf("Ha elegido Lisboa como lugar de destino\n");
										do {
											menuPreciosLisboa();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion20);
											switch(opcion20) {
											    case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion20<1 || opcion20>3);
									    break;
									case '2': 
										printf("Ha elegido Oporto como lugar de destino\n");
										do {
											menuPreciosOporto();
											printf("Introduzca la opcion: \n");
											fflush(stdin);
											scanf("%c", &opcion21);
											switch(opcion21) {
												case '1': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '2': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
												case '3': 
													printf("Por último ingrese la fecha de ida:\n");
													break;
											}
										}while(opcion21<1 || opcion21>3);
										break;
								}
						    }while(opcion19<1 || opcion19>2);
							break;
					}
				}while(opcion3<1 || opcion3>6);
				break;
			case 'b':
			case 'B':
				printf("Ha seleccionado: Borrar reserva\n");
				nHoteles = sizeof(hoteles)/sizeof(hoteles[0]);
					
				for(nReservas=0;nReservas<nHoteles; nReservas++) {
					if(hoteles[nReservas].numReserva==usuarios[i].numReserva) {
						comparador4=1;
						break;
					}
				}
					
				if (comparador4 !=0){
//  borramos el registro/ Falta una linea justo aqui		
				}else {
					printf("No se han encontrado reservas a su nombre");	
				}
							
				break;
			case 'c':
			case 'C':
				printf("Ha seleccionado: Consultar reserva\n");
				// Obtenemos el numero de registros del array de reservas
				nHoteles = sizeof(hoteles)/sizeof(hoteles[0]);
				
				for(nReservas=0;nReservas<nHoteles; nReservas++) {
					if(hoteles[nReservas].numReserva==usuarios[i].numReserva) {
						comparador3=1;
						printf("Tu número de reserva es\n", usuarios[i].numReserva);
						printf("El pais elegido es:\n", hoteles[nReservas].pais);
						printf("La ciudad elegida es:\n", hoteles[nReservas].ciudad);
// rellenar el resto con mes, dia y hora de llegada y salida
					
						printf("El pais elegido es:\n", hoteles[nReservas].numReserva);
						printf("Tu número de reserva es\n", hoteles[nReservas].numReserva);
						printf("El pais elegido es:\n", hoteles[nReservas].numReserva);
						printf("Tu número de reserva es\n", hoteles[nReservas].numReserva);
						printf("El pais elegido es:\n", hoteles[nReservas].numReserva);
						printf("Tu número de reserva es\n", hoteles[nReservas].numReserva);
						printf("El pais elegido es:\n", hoteles[nReservas].numReserva);
						printf("Tu número de reserva es\n", hoteles[nReservas].numReserva);														
						break;
					} 
				}
				if(comparador3!=0) {
					printf("No se han encontrado reservas");
					break;
				}
				
				break;
			case 'a':
			case 'A':
				printf("Ha seleccionado la opcion: 'Seccion de comentarios'\n");
				printf("Si desea leer comentarios pulse 1\n");
				printf("Si desea escribir un comentario pulse 2\n");
				scanf("%d", &opcionComentario);
				switch(opcionComentario) {
					case 1:
						for (i = 0; i < nComentarios; i++) {
								printf("%s", comentarios[i].mensaje);
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
				printf("Gracias por utilizar este programa\n");		
				return 0;
			default:
				printf("La opcion es incorrecta\n");			
		}
			
			//Guardar la memoria en Comentarios.txt
			fentrada = fopen("Comentarios.txt", "a");
			if (fentrada == NULL) {
				printf("No se ha podido abrir el fichero Comentarios correctamente\n");
				return 0;
			}	
			for (nComentarios=0; nComentarios<i; nComentarios++) {
				fprintf(fentrada, "%s\n", comentarios[i].mensaje);
			}	
			fclose(fentrada);
			fflush(stdin);
			
			//Reescribir el fichero Reserva.txt
    		FILE * freserva;
    		freserva = fopen("Hoteles.txt", "w"); 
    		for (i=0; i<nHoteles; i++) {
    			fprintf(freserva, "%d %d %d %d %d %d", &hoteles[nHoteles].numReserva, hoteles[nHoteles].mes_llegada, hoteles[nHoteles].dia_llegada, hoteles[nHoteles].mes_salida, hoteles[nHoteles].dia_salida, &hoteles[nHoteles].numHotel);
			}
    		fclose(freserva);
    		return 0;
	
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
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--74.00€-NH_Hotels\n");
	printf("2--105.30€-Four_Seasons\n");
	printf("3--53.00€-Airbnb\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosBarcelona() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--64.00€-Hotel_Vela\n");
	printf("2--42.90€-Airbnb\n");
	printf("3--76.30-El_Palace\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosParis() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--64.35€-Airbnb\n");
	printf("2--76.96€-Elysees\n");
	printf("3--68.73€-Novotel\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosLyon() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--46.52€-Airbnb\n");
	printf("2--52.13€-Fourviere\n");
	printf("3--41.23€-Lagrange\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosRoma() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--47.23€-Airbnb\n");
	printf("2--34.56€-NH\n");
	printf("3--64.23€-Melia\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosVenecia() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--53.21€-Ibis\n");
	printf("2--60.20€-Hilton\n");
	printf("3--52.03€-Airbnb\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosLondres() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--69.05€-Premier_Inn\n");
	printf("2--42.06€-Ibis\n");
	printf("3--46.05€-Airbnb\n");
	printf("-------------------------------------------------------\n");
}
int menuPreciosBath() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--50.23€-NH\n");
	printf("2--32.75€-Airbnb\n");
	printf("3--42.35€-Holiday_Inn\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosBerlin() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--50.00€-Radisson_Blu_Hotel\n");
	printf("2--42.30€-Nook\n");
	printf("3--46.78€-Melia\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosMunich() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--38.20€-NH\n");
	printf("2--32.45€-Airbnb\n");
	printf("3--46.80€-Amba\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosLisboa() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--40.30€-Airbnb\n");
	printf("2--32.60€-NH\n");
	printf("3--60.13€-Luxury\n");
	printf("-------------------------------------------------------\n");
}

int menuPreciosOporto() {
	printf("-------------------------------------------------------\n");
	printf("Ahora seleccione el precio que desea pagar por noche:\n");
	printf("1--60.00€-Avid\n");
	printf("2--43.20€-Airbnb\n");
	printf("3--52.23€-Melia\n");
	printf("-------------------------------------------------------\n");
}
