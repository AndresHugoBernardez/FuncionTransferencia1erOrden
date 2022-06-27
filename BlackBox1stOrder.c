
//
//               Programa de Andrés Bernárdez
//              



//  BlackBox1stOrder versión 1
//       
//
// (Tareas para futuras versiones:  Calcular Tao y Retardo usando la hora y no un contador.  En vez de usar fgetc, usar fread)
// 
//


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>//Booleanos


double RetornoDePrograma[10]={0,0,0,0,0,0,0,0,0,0};


long int ValorHora(char * hora)
{
	int i,j;
	
	char cadena[10];
	long int valor,numero;
	
	j=0;
	i=0;
	numero=0;
	while(hora[i]!='\0')
	{
		if(hora[i]!=':')
		cadena[j]=hora[i];
		else
		{
			numero=numero*60;
			cadena[j]='\0';
			valor=atol(cadena);
			numero=numero+valor;
			j=-1;

		}
		i++;
		j++;
	}
	
			numero=numero*60;
			cadena[j]='\0';
			valor=atol(cadena);
			numero=numero+valor;
			j=-1;
	
	return(numero);
}


int ComprobarHora(char * hora)
{
	int error=0;
	error=0;
	//00:00:00
	if((hora[0]<'6'&&hora[0]>='0')&&(hora[1]<='9'&&hora[1]>='0')&&(hora[2]==':')&&(hora[3]<'6'&&hora[3]>='0')&&(hora[4]<='9'&&hora[4]>='0')&&(hora[5]==':')&&(hora[6]<'6'&&hora[6]>='0')&&(hora[7]<='9'&&hora[0]>='0'))
	return(0);
	else
	return(101);
	
	
}

double char2double(char c)
{
	double numero=0;
	numero=0;
	if(c>47&&c<58)
	 numero=((double)c)-48;
	 return(numero);
}

// El "." es el separador de decimales. CONDICION: El string debe terminar en un numero.
double string2double(char cadena[])

{
	int i;
	bool Decimales=false;
	double divisor=10, numero=0;
	
	
	//inicializaciÃ³n del while
	i=0;
	Decimales=false;
	divisor=10;
	numero=0;
	while(cadena[i]!='\0')
	{
		if(cadena[i]==',')
		{
			// ATENCION se saltea un caracter, asegurarse que el string no termine en "," y que haya un numero despues
			i++;
		}
		if(cadena[i]=='.')
		{
			Decimales=true;
			// ATENCION se saltea un caracter, asegurarse que el string no termine en "." y que haya un numero despues
			i++;
		}
		if(Decimales)
		{
			numero=numero+char2double(cadena[i])/divisor;
			divisor=divisor*10;			
		}
		else
		{
			numero=numero*10+char2double(cadena[i]);
		}
		i++;
		
	}
	return(numero);
	
}



int ObtenerCadenaColumna(char cadena[],FILE * archivo,int ColumnaSeleccionada,char caracterActual)

{
	char caracter;
	int ColumnaActual,i=0, error=0;
	
	error=0;
	caracter=caracterActual;
	ColumnaActual=0;
	// Posicionarse en la columna deseada
	while(caracter!=EOF&&caracter!='\n'&&ColumnaActual<ColumnaSeleccionada)
	{
		
				
		while(caracter!=EOF&&caracter!='\n'&&caracter!=13&&ColumnaActual<ColumnaSeleccionada)
		{
			caracter=fgetc(archivo);
			//printf("%c",caracter);
			if(caracter==',')
			{
				ColumnaActual++;
				//printf("<col:%d:%d>",ColumnaActual,ColumnaSeleccionada);
				
			}
		}


	
	}
	
	


	
					
	if(ColumnaActual!=ColumnaSeleccionada&&caracter!=EOF&&caracter!='\n'&&caracter!=13) 
	{
		
		printf("\n No se ha encontrado la Columna\n\n");
		error=21;
			
		}
					
					
	//----------------
	else
	{
					
	
		//Obtener cadena
		//--------------------------------------------
		i=0;
		if(caracter==',')caracter=fgetc(archivo); 
		cadena[i]=caracter;
		while(caracter!=EOF&&caracter!='\n'&&caracter!=13&&caracter!=',')
		{
			cadena[i]=caracter;
			caracter=fgetc(archivo);
			i++;	
		}
		cadena[i]='\0';
		//----------------------------------------------
	}
	
	
	return(error);
}
//-----------------------------------------------------
//*****************************************************
//*****************************************************
//*****************************************************
//*****************************************************
//*****************************************************
//*****************************************************



double* main( int argc, char *argv[] ) 
{
	FILE * archivo;
	char caracter,cadena[200],*direccion,*inicio,*fin,dato[5]="";//[200]="Libro3.csv";
	bool seguir=false;
	int ColumnaEscalon, ColumnaTiempo, ColumnaSalida,ColumnaActual,error=0,filaactual,j;
	long int  HoraInicio,HoraFin,HoraActual,HoraTao,Hora2Tao,Hora3Tao,Hora10porCiento,HoraEscalon, EmpezarEnFila,TerminarEnFila,i,PosicionInicial,PosicionFinal,PosicionFinalAnterior,PosicionRetardo, PosicionTao,Posicion2Tao,Posicion3Tao,TiempoTao,Tiempo2Tao,Tiempo3Tao, Tiempo10porCiento, TiempoRetardoAjustado,TaoFinal;
	double Muestreo,TaoAjustado,RetardoAjustado,Ganancia,EscalonInicio,EscalonFin,SalidaRetardo,SalidaInicio,SalidaFinal,SalidaTao,Salida2Tao,Salida3Tao,SalidaDiferencia;
	
	
	printf("\n Andres Bernardez's Softwares\n\n---------------------");
	archivo=NULL;
	
	error=0;
		i=0;
	
	Muestreo=1;
	EmpezarEnFila=0;
	TerminarEnFila=0;
	ColumnaTiempo=0;
	
	HoraInicio=0;
	HoraFin=0;
	
	inicio=dato;
	fin=dato;
	
	if(argc==1)
	{
		printf("\n Faltan Parametros! \n ");
		error=10;
	}
	else
	{
		if(argv[1][0]!='-')
		{
			error=19;
			printf("\n Error al ingresar argumentos\n");
		}
		else for(j=1;j<argc&&!error;j++)
		{
		
		if(argv[j][0]=='-')
		{
			switch(argv[j][1])
			{
			
			case 'd':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
								{
									j++;
									direccion=argv[j];
									
									
								}
							else
							{
								printf("\n Falta direccion archivo.\n ");
								error=11;
							}
						}
						else
						{
							printf("\n Falta Direccion archivo.\n ");
							error=11;
						}
						
						break;
			case 'I':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
								{
									j++;
									inicio=argv[j];
									
									if(ComprobarHora(inicio)){
										
										printf("\n Error al ingresar dato de hora inicio, el modelo es '00:00:00'\n");
										error=23;
									}
									
									
								}
							else
							{
								printf("\n Falta hora inicio.\n ");
								error=11;
							}
						}
						else
						{
							printf("\n Falta Hora inicio.\n ");
							error=11;
						}
						
						break;
			case 'F':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
								{
									j++;
									fin=argv[j];
									if(ComprobarHora(fin)){
										
										printf("\n Error al ingresar dato de hora final, el modelo es '00:00:00'\n");
										error=23;
									}
									
								}
							else
							{
								printf("\n Falta hora final.\n ");
								error=11;
							}
						}
						else
						{
							printf("\n Falta Hora final.\n ");
							error=11;
						}
						
						break;
						
			case 'i':
						if(argc>j)
						{
							if(argv[j+1][0]!='-')
							{
								
								j++;
								EmpezarEnFila=atol(argv[j]);
								
								
								
							}
							else
							{
								printf("\n Falta fila de comienzo\n ");
								error=12;
							}
						}
						else
						{
							printf("\n Falta Fila de comienzo.\n ");
							error=12;
						}
						
						break;
				case 'f':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
							{
								j++;
								TerminarEnFila=atol(argv[j]);
								if(TerminarEnFila==0)
								{
									error=16;
									printf("\n Dato no valido para final de fila");
								}
								
								
							}
							else
							{
								printf("\n Falta ingresar fila final\n ");
								error=12;
							}
						}
						else
						{
							printf("\n Falta ingresar Fila final.\n ");
							error=12;
						}
						
						break;
				
					
				case 't':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
							{
								j++;
								ColumnaTiempo=atoi(argv[j]);
								if(ColumnaTiempo==0)
								{
									error=21;
									printf("\n Dato no valido para Columna de la hora (-t)\n");
								}
								
								ColumnaTiempo--;
								
							}
							else
							{
								printf("\n Falta indicar columna de la hora\n ");
								error=21;
							}
						}
						else
						{
							printf("\n Falta Indicar columna del escalon.\n ");
							error=13;
						}
						
						break;		
				case 'e':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
							{
								j++;
								ColumnaEscalon=atoi(argv[j]);
								if(ColumnaEscalon==0)
								{
									error=17;
									printf("\n Dato no valido para Columna del Escalon (-e)\n");
								}
								
								ColumnaEscalon--;
								
							}
							else
							{
								printf("\n Falta indicar columna del escalon\n ");
								error=13;
							}
						}
						else
						{
							printf("\n Falta Indicar columna del escalon.\n ");
							error=13;
						}
						
						break;
						
				case 's':
						if(argc>j)
						{
							
							if(argv[j+1][0]!='-')
							{
								j++;
								ColumnaSalida=atoi(argv[j]);
								if(ColumnaSalida==0)
								{
									error=18;
									printf("\n Dato no valido para columna de salida (-s)\n");
								}
								
								
								ColumnaSalida--;
								
							}
							else
							{
								printf("\n Falta indicar Columna de salida\n ");
								error=14;
							}
						}
						else
						{
							printf("\n Falta Indicar columna de salida\n ");
							error=14;
						}
						
						break;
				
				case 'm':
						if(argc>j)
						{
							if(argv[j+1][0]!='-')
							{
								
								j++;
								Muestreo=atof(argv[j]);
								if(Muestreo==0)
								{
									error=18;
									printf("\n Dato no valido para Tiempo de muestreo (-m)\n");
								}
								
								
								
								
							}
							else
							{
								printf("\n Falta indicar tiempo de muestreo\n ");
								error=14;
							}
						}
						else
						{
							printf("\n Falta Indicar tiempo de muestreo\n ");
							error=14;
						}
						
						break;
						
				case 'h':
						printf("\n");
						printf(" Ayuda del programa\n");
						printf("\n");					
						printf("-d direccion:  *Ingresa la direccion del archivo\n");
						printf("-i numero:  Ingresa la primera fila del archivo donde se analizaran datos (empezando en 0, por defecto es 0)\n");
						printf("-f numero:  Ingresa la ultima fila del archivo que se analizaran datos (empezando en 0, no puede ser 0)\n");
						printf("-I 00:00:00 :  Ingresa la hora de la primera fila del archivo donde se analizaran datos \n");
						printf("-F 00:00:00 :  Ingresa la hora de la ultima fila del archivo donde se analizaran datos \n");
						printf("-t entero:  *Ingresa la columna donde se encuentran los datos de la hora (empezando en 1)\n");
						printf("-e entero:  *Ingresa la columna donde se encuentran los datos del Escalon(empezando en 1)\n");
						printf("-s entero:  *Ingresa la columna donde se encuentra la salida del Escalon (empezando en 1)\n");
						printf("-m flotante: Ingresa el tiempo de MUESTREO en segundos  que transcurre entre una fila y la otra (por defecto es 1 segundo)\n");
						printf("-h:  Ayuda del programa\n");
						printf("\n");
						printf(" Son obligatorios los campos con '*'\n");
						printf(" Es obligatorio usar un inicio o un fin de uno de los 2 modos.\n");
						printf(" Ejemplo 1: BlackBox1stOrder -d TEMP.CSV -I 19:04:00  -F 19:20:10  -t 2 -e 5 -s 3\n");
						printf(" Ejemplo 2: BlackBox1stOrder -d TEMP.CSV -i 30  -f 2000  -t 2 -e 5 -s 3\n");
						printf("\n");
						
						error=1234;
						
					
					
					
						break;
				default:
					{
						printf("\n Ha ingresado una opcion no valida!\n");
						error=15;
					}
			}
			
			
				
			}
			else{
				printf("\n ha ingresado parametros invalidos u omitido algo. No se entiende lo siguiente:'%s'\n",argv[j]);
				error=20;
			}
		}
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	

	
	
	//printf("\n dir:[%s]   inicio:%ld fin:%ld Esc:%d Sal:%d Tiem:%lf\n",direccion,EmpezarEnFila,TerminarEnFila,ColumnaEscalon,ColumnaSalida,Muestreo);
	

	if(!error)
	{
	HoraInicio=ValorHora(inicio);
	HoraFin=ValorHora(fin);
	
	printf("\nHORAS %s:%ld >>%s:%ld>\n",inicio,HoraInicio,fin,HoraFin);
	if((HoraInicio>=HoraFin&&(inicio[0]!='\0'&&fin[0]!='\0'))||(inicio=='\0'&&fin[0]!='\0'))
	{
		printf("\n Error en los valores de las horas, la hora de inicio debe ser anterior a la hora de fin\n");
		error=28;
	}
	
	
	if(direccion[0]=='\0')
	{
		printf("\nFalta Archivo\n");
		error=18;
	}
	if(EmpezarEnFila>=TerminarEnFila&&fin[0]=='\0')
	{
		printf("\n Error al ingresar la primer y ultima fila\n");
		error=18;
	}
	
	}
		if(9<error&&error<30)
	{
		printf(" ingrese '-h' para recibir ayuda\n");
	}
	
	
	
	
	
	if(!error)
	{
	

	if(EmpezarEnFila==0) printf("\n Se empezara desde el primer dato del archivo\n");
	
	printf(" Abriendo archivo...");
	

	// Aunque se leera un archivo de texto, se trabaja en modo binario y por ello se tiene en cuenta el caracter CR (Retorno de linea ASCII:13)  ya que 
	//se detecto error al usar archivos de texto grandes con el caracter LF (Fin de linea ASCII:10)
	archivo=fopen(direccion,"rb");
	if (archivo==NULL)
	{
		error=8;
		printf("\n\nERROR AL ABRIR ARCHIVO...\n verifique que el nombre y la direccion sean correctos\n");
	}
	else
	{
     printf("ok!\n");

	//i=0;
	caracter='a';
	

	
	
	
	fseek(archivo,0,SEEK_SET);
	//PosicionInicial=0;
	
	
	//Saltear primera fila
	while(caracter!=EOF&&caracter!='\n')
	{
		caracter=getc(archivo);
	}
	
	
		
		
		if(inicio[0]=='\0')
		{
		    PosicionInicial=ftell(archivo);
		
		
			// Salteando hasta la fila EmpezarEnFila
		
			for(i=0;i<EmpezarEnFila&&caracter!=EOF;i++)
			{
				
				caracter='a';
				while(caracter!=EOF&&caracter!='\n')
				{
					caracter=getc(archivo);
				}
				PosicionInicial=ftell(archivo);
				
			}
			if(caracter==EOF)
			{
				printf("\n No hay datos en la fila:%ld \n Ultimo dato leido en fila:%ld\n",EmpezarEnFila,i);
				error=101;
			}

		}
		else
		{
			
			// Salteando hasta el valor inicio
			
			printf("\n Salteando hasta la hora inicial...");
		//Buscando inicio del siguiente escalon	
			
			seguir=true;
			i=0;
			while(caracter!=EOF&&!error&&seguir)
			{
				PosicionInicial=ftell(archivo);
	
				caracter=fgetc(archivo);
				error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
				
				
				if(!error)
				{
					HoraActual=ValorHora(cadena);
					//printf("HORA: %s  >%ld >>%ld >%s\n",cadena,HoraActual,HoraInicio,inicio);
					if(HoraActual>=HoraInicio)
					{
						printf("ok!\n");
						seguir=false;
					}
					
				}
					//Salteando fila
				if(seguir&&!error)
				while(caracter!=EOF&&caracter!='\n')
				{
					caracter=getc(archivo);
				}
				i++;
	

			}
			
			if(!error)
			{
				if(HoraActual>=HoraInicio)
				{
					i--;
					if(HoraFin>0)
					TerminarEnFila=HoraFin-HoraInicio+i-1;
					
					
				}
				else
				{
					printf("\n Error: No se encontró el inicio de hora:%s \n",inicio);
								error=505;
				}
				
			}
			
		}
	}
	}
	
	if(!error)
	{
		//cargando el primer valor
		caracter=getc(archivo);
		i--;
	    fseek(archivo,PosicionInicial,SEEK_SET);
		error=ObtenerCadenaColumna(cadena,archivo,ColumnaEscalon,caracter);
		
		//Salteando fila
		while(caracter!=EOF&&caracter!='\n')
		{
			caracter=getc(archivo);
		}
		
	}
	
	

	
	if(!error)
	{
	
		//Estableciendo el criterio incial
		EscalonInicio=string2double(cadena);
		
	
					
		printf("\nBuscando Escalon...\n");
		//Buscando inicio del escalon		
		seguir=true;	
		
		while(caracter!=EOF&&!error&&seguir)
		{
			PosicionInicial=ftell(archivo);
			//if(caracter=='\n')PosicionInicial++;
			
			caracter=fgetc(archivo);
			
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaEscalon,caracter);
			
			if(!error)
			{
				if(string2double(cadena)!=EscalonInicio)
				{
					EscalonFin=string2double(cadena);
					seguir=false;
					
				}
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
			i++;
		}
		
		if(!error)
		{
		
		printf("ok!\nCargando Informacion...\n");
		//cargando informacion
		fseek(archivo,PosicionInicial,SEEK_SET);
		

		caracter=fgetc(archivo);
		error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
		}
		if(!error)
		{
			SalidaInicio=string2double(cadena);
		
			printf("ok!\n Buscando Salida tendiendo a infinito...\n");
		//Buscando inicio del siguiente escalon	
			fseek(archivo,PosicionInicial,SEEK_SET);
			PosicionFinal=PosicionInicial;			
			seguir=true;
		}
		while(caracter!=EOF&&!error&&seguir)
		{
			PosicionFinal=ftell(archivo);

			caracter=fgetc(archivo);
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaEscalon,caracter);
			

			if(!error)
			{
				if(string2double(cadena)!=EscalonFin)
				{
					printf("\n Se finaliza en el siguiente escalon\n");
					seguir=false;
				}
				else
				{
					PosicionFinalAnterior=PosicionFinal;
				}
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
			i++;

			if(i>=TerminarEnFila) 
			{
				printf("\n Se finaliza en la fila %ld\n",TerminarEnFila);
				seguir=false;

			}
		}
		if(caracter==EOF) printf("\n No se encontró siguiente escalón, se toma el último valor de la lista\n");
		
		if(!error)
		{
		
			//cargando informacion
			
			fseek(archivo,PosicionFinalAnterior,SEEK_SET);

			caracter=fgetc(archivo);

			
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
			
			if(!error)
			{
				SalidaFinal=string2double(cadena);
				fseek(archivo,PosicionInicial,SEEK_SET);

				caracter=fgetc(archivo);

			
				error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
				
				printf("----------------\n");
				printf("  Escalon Inicial = %lf Salida en Inicio = %lf HORA : %s\n",EscalonInicio,SalidaInicio,cadena);
				
				fseek(archivo,PosicionFinalAnterior,SEEK_SET);

				caracter=fgetc(archivo);
			
				error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
				printf("    Escalon Final = %lf     Salida Final = %lf HORA : %s ", EscalonFin, SalidaFinal ,cadena );
				printf("\n\n-------\n");
			}
			
		
		//  LA INFORMACION ESTA LISTA
		
		
		// Obteniendo Tao
		printf("\n Calculando Tao...");
		SalidaDiferencia=SalidaFinal-SalidaInicio;
		SalidaTao=SalidaInicio+SalidaDiferencia*(1-0.36787944117);
		Salida2Tao=SalidaInicio+SalidaDiferencia*(1-0.13533528323);
		Salida3Tao=SalidaInicio+SalidaDiferencia*(1-0.04978706836);
		SalidaRetardo=SalidaInicio+SalidaDiferencia*0.1;
		
		printf("Ok!\n--------------\n");
		printf("La diferencia de la salida al momento del Escalon y al final es %lf\n",SalidaDiferencia);
		printf("Al alcanzar el 10%% del valor final la Salida sera:%lf\n",SalidaRetardo);
		printf("En Tao la Salida sera:%lf\n",SalidaTao);
		printf("En 2 Tao la Salida sera:%lf\n",Salida2Tao);
		printf("En 3 Tao la salida sera:%lf\n",Salida3Tao);
		
		
		printf("\n------------------\n");
		
		printf("\n Buscando 10%% del valor final...");
		//Buscando inicio del siguiente escalon	
		fseek(archivo,PosicionInicial,SEEK_SET);
		Tiempo10porCiento=-1;			
		seguir=true;
		
		}
		printf("\n");
		while(caracter!=EOF&&!error&&seguir)
		{
			PosicionRetardo=ftell(archivo);

			caracter=fgetc(archivo);
			Tiempo10porCiento++;
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
			
			
			if(!error)
			{
				if(SalidaDiferencia>0){
				
					if(string2double(cadena)>=SalidaRetardo)
					{
						seguir=false;
					}
				}
				else
				{
					if(string2double(cadena)<=SalidaRetardo)
					{
						seguir=false;
					}
				}
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
	
		}
		
		if(!error)
		{
		
		//cargando informacion
		printf("ok!\n    El 10%% se alcanza en =%ld muestras\n Buscando Tao.....",Tiempo10porCiento);
		fseek(archivo,PosicionRetardo,SEEK_SET);

		
		TiempoTao=-1;
		
		seguir=true;
		}
		while(caracter!=EOF&&!error&&seguir)
		{
			PosicionTao=ftell(archivo);

			caracter=fgetc(archivo);
			
			TiempoTao++;
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
			
			if(!error)
			{
				if(SalidaDiferencia>0)
				{
				
					if(string2double(cadena)>=SalidaTao)
					{
						seguir=false;
					}
				}
				else
				{
					if(string2double(cadena)<=SalidaTao)
					{
						seguir=false;
					}
				}
				
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
	
		}
		
		if(!error)
		{
			printf("ok!\n Tiempo desde el comienzo del escalon hasta Tao= %ld muestras\n",TiempoTao+Tiempo10porCiento);
	
		
		
		//cargando informacion
		printf("\n\n Buscando 2 Tao.....");

		fseek(archivo,PosicionTao,SEEK_SET);
		
		Tiempo2Tao=-1;
		
		seguir=true;
		}
		while(caracter!=EOF&&!error&&seguir)
		{
			Posicion2Tao=ftell(archivo);
			

			caracter=fgetc(archivo);
			
			Tiempo2Tao++;
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
			
			if(!error)
			{
				if(SalidaDiferencia>0)
				{
				
					if(string2double(cadena)>=Salida2Tao)
					{
						seguir=false;
					}
				}
				else
				{
					if(string2double(cadena)<=Salida2Tao)
					{
						seguir=false;
					}
				}
				
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
	
		}
		
		if(!error)
		{
			printf("ok!\n Tiempo desde 1 Tao a 2 Tao= %ld muestras\n",Tiempo2Tao);
	
		
		
//cargando informacion
		printf("\n\n Buscando 3 Tao.....");

		fseek(archivo,Posicion2Tao,SEEK_SET);	
		
		Tiempo3Tao=-1;
		
		seguir=true;
		}
		while(caracter!=EOF&&!error&&seguir)
		{
			Posicion3Tao=ftell(archivo);
			

			caracter=fgetc(archivo);
			
			Tiempo3Tao++;
			error=ObtenerCadenaColumna(cadena,archivo,ColumnaSalida,caracter);
			
			if(!error)
			{
				if(SalidaDiferencia>0)
				{
				
					if(string2double(cadena)>=Salida3Tao)
					{
						seguir=false;
					}
				}
				else
				{
					if(string2double(cadena)<=Salida3Tao)
					{
						seguir=false;
					}
				}
				
			}
				//Salteando fila
			if(seguir&&!error)
			while(caracter!=EOF&&caracter!='\n')
			{
				caracter=getc(archivo);
			}
	
		}
		
		if(!error)
		{
			printf("ok!\n Tiempo desde 2 Tao hasta 3 Tao= %ld muestras\n",Tiempo3Tao);
	
		}		
					
	

		
	}
	

	

	//if (i>99) printf("error i\n"); else printf("no i\n");
	if(!error)
	{
	

	printf("calculando Resultados....");
	Ganancia=SalidaDiferencia/(EscalonFin-EscalonInicio);

	TaoFinal=Tiempo3Tao+Tiempo2Tao;	
	TaoFinal=TaoFinal/2;

	TiempoRetardoAjustado=Tiempo10porCiento+TiempoTao-TaoFinal;
	printf("ok!\n");
	
	
	printf("-----------------------------------------------\n");
	
	
	fseek(archivo,PosicionInicial,SEEK_SET);
	caracter=fgetc(archivo);
	error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
	
	printf("Hora de inicio Escalon:%s\n",cadena);
	fseek(archivo,PosicionRetardo,SEEK_SET);
	caracter=fgetc(archivo);
	error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
	
	printf("Hora de 10%%:%s\n",cadena);
	
	fseek(archivo,PosicionTao,SEEK_SET);
	caracter=fgetc(archivo);
	error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
	
	printf("Hora de Tao:%s\n",cadena);
	
	fseek(archivo,Posicion2Tao,SEEK_SET);
	caracter=fgetc(archivo);
	error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
	
	printf("Hora de 2 Tao:%s\n",cadena);
	
	fseek(archivo,Posicion3Tao,SEEK_SET);
	caracter=fgetc(archivo);
	error=ObtenerCadenaColumna(cadena,archivo,ColumnaTiempo,caracter);
	
	printf("Hora de 3 Tao:%s\n",cadena);
	
	
	
	
	
	printf("-----------------------------------------------\n");
	printf(" RESULTADOS:\n");
	printf(" Ganancia=%lf     Tiempo desde Tao1 a TAO2:%ld // Tiempo desde Tao2 a TAO3:%ld // Tao promedio:%ld\n",Ganancia,Tiempo2Tao,Tiempo3Tao,TaoFinal);    
	printf("  Tiempo desde el escalon al 10%% :%ld    // Tiempo desde el escalon hasta el primer Tao: %ld\n",Tiempo10porCiento,TiempoTao+Tiempo10porCiento); 
	printf(" Retardo calculado:%ld\n",TiempoRetardoAjustado);
	printf("-----------------------------------------------\n");
	
	
	
	
	RetardoAjustado=((double)TiempoRetardoAjustado)*Muestreo;
	TaoAjustado=((double)TaoFinal)*Muestreo;

	printf("Ajustando valores con el tiempo de muestreo: %lf\n",Muestreo);
	printf("Ganancia=%lf\n",Ganancia);
	printf("Tao=%lf\n",TaoAjustado);
	printf("Retardo=%lf\n",RetardoAjustado);
	printf("\nFIN CORRECTO DEL PROGRAMA!\n");
	printf("-----------------------------------------------\n");
	RetornoDePrograma[0]=Ganancia;
	RetornoDePrograma[1]=TaoAjustado;
	RetornoDePrograma[2]=RetardoAjustado;
	}

if(archivo!=NULL)fclose(archivo);

if (error&&error!=1234)
{

printf("\n\n ERROR N:'%d' ENCONTRADO \n EL PROGRAMA HA FINALIZADO\n",error);
}
	
	
	return(RetornoDePrograma);
	
}
