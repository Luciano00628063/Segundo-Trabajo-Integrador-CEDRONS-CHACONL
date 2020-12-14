#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

struct fecha{
	int dia;
	int mes;
	int ano;
};

struct user{
	char usuario[10];
	char contrasena[32];
};

struct mascota{
	char apeNom[60];
	char domicilio[60];
	int dni;
	char localidad[60];
	fecha nac;
	float peso;
	char tel[25];
};

struct turno{
	int matricula;
	fecha cita;
	int dni;
	char evolucion[380];
};

void inicio(int &bandera);
void registroM();
void registroT();
void listado();

main()
{
	system("color 0b");	
	int bandera=0;
	int opcion;	
	
	do{
		printf("==========================================");
		printf("\n\t   Modulo Administracion");
		printf("\n==========================================");
		printf("\n1.- Iniciar Sesion.");
		printf("\n2.- Registrar Mascota.");
		printf("\n3.- Registrar Turno.");
		printf("\n4.- Listado de Atenciones por Veterinario y Fecha.");
		printf("\n5.- Cerrar la aplicacion.");
		printf("\n------------------------------------------");
		printf("\nIngrese una opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			
			case 1:
				system("cls");
				inicio(bandera);
				system("pause");
				system("cls");
				break;
				
			case 2:
				system("cls");
				if(bandera==1)	registroM();
				else
				{
					printf("\n\n------------------------------ERROR!--------------------------------------------");
					printf("\n\tNo puede hacer uso del programa si no ha iniciado sesion antes.\n\n");
					printf("\n--------------------------------------------------------------------------------");
				}
				system("pause");
				system("cls");
				break;				
				
			case 3:
				system("cls");
				if(bandera==1)	registroT();
				else
				{
					printf("\n\n------------------------------ERROR!--------------------------------------------");
					printf("\n\tNo puede hacer uso del programa si no ha iniciado sesion antes.\n\n");
					printf("\n--------------------------------------------------------------------------------");
				}
				system("pause");
				system("cls");
				break;				

			case 4:
				system("cls");
				if(bandera==1)	listado();
				else
				{
					printf("\n\n------------------------------ERROR!--------------------------------------------");
					printf("\n\tNo puede hacer uso del programa si no ha iniciado sesion antes.\n\n");
					printf("\n--------------------------------------------------------------------------------");
				}
				system("pause");
				system("cls");
				break;
				
			case 5:
				system("cls");
				printf("Se cerrara la aplicacion\n\n");
				system("pause");
				system("cls");
				break;
								
				
		};
		
	}while(opcion!=5);	
	
	
}


void inicio(int &bandera)
{
	user ingreso,auxiliar;
	char password[32];
	int b=0;
	
	FILE *puntero;
	puntero=fopen("Usuarios.dat","ab+");

	
	printf("\nINICIO DE SESION");
	printf("\n----------------");
	_flushall();
	printf("\n\nNombre de usuario: ");
	gets(ingreso.usuario);
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	
	while(b==0)
	{		
		while(!feof(puntero))
		{
			
				if(strcmp(ingreso.usuario,auxiliar.usuario)==0)
				{
					b=1;
					printf("Ingrese la contrasena: ");
					_flushall();
					gets(ingreso.contrasena);
	
					while(strcmp(ingreso.contrasena,auxiliar.contrasena)!=0)
					{
						b=0;
						printf("\n\n------------------------------ERROR!--------------------------------------------");
						printf("\nLa contrasena ingresada no coincide con el nombre de usuario.\nIntente nuevamente: ");
						_flushall();
						gets(ingreso.contrasena);
					}
					b=1;
				}
				fread(&auxiliar,sizeof(auxiliar),1,puntero);
		}
		if(b==0)
		{
			printf("\n\n------------------------------ERROR!--------------------------------------------");
			printf("\nEl nombre ingresado no coincide con ningun usuario registrado.\nIntente nuevamente: ");
			_flushall();
			gets(ingreso.usuario);
		}
		rewind(puntero);
		
	}
	
	if(b==1)
	{
		printf("\nSe ha iniciado sesion con exito!\n\n");
		bandera=1;
	}
	
	fclose(puntero);
	
}

void registroM()
{
	FILE *puntero;
	puntero=fopen("Mascotas.dat","ab+");
	mascota ingreso;
	
	printf("========================================");
	printf("\n          REGISTRO DE MASCOTAS");
	printf("\n========================================");
	
	
	printf("\n\nINGRESO DE LA INFORMACION DE LA MASCOTA");
	printf("\n.-Ingrese el Nombre y Apellido: ");
	_flushall();
	gets(ingreso.apeNom);
	
	printf(".- Ingrese el domicilio: ");
	_flushall();
	gets(ingreso.domicilio);
	
	printf(".- Ingrese el DNI del dueño: ");
	scanf("%d",&ingreso.dni);
	
	printf(".- Ingrese la localidad: ");
	_flushall();
	gets(ingreso.localidad);
	
	printf(".- Ingrese la fecha de nacimiento: ");
	printf("\t Dia: ");
	scanf("%d",&ingreso.nac.dia);
	while(ingreso.nac.dia<1 or ingreso.nac.dia>31)
	{
		printf("\n\n------------------------------ERROR!--------------------------------------------");
		printf("\nIngrese un dia que sea valido.");
		scanf("%d",&ingreso.nac.dia);
	}
	
	printf("\t Mes: ");
	scanf("%d",&ingreso.nac.mes);
	while(ingreso.nac.mes<1 or ingreso.nac.mes>12)
	{
		printf("\n\n------------------------------ERROR!--------------------------------------------");
		printf("\nIngrese un mes que sea valido.");
		scanf("%d",&ingreso.nac.mes);
	}
	
	printf("\t Ano: ");
	scanf("%d",&ingreso.nac.ano);
	
	printf("\n.- Ingrese el peso de la mascota: ");
	scanf("%f",&ingreso.peso);
	
	printf("\n.- Ingrese el telefono del dueño: ");
	_flushall();
	gets(ingreso.tel);
	
	fwrite(&ingreso,sizeof(ingreso),1,puntero);
	fclose(puntero);
}

void registroT()
{
	FILE *puntero;
	puntero=fopen("Turnos.dat","ab+");
	
	turno ingreso;
	
	printf("====================================");
	printf("\n         REGISTRO DE TURNOS");
	printf("\n====================================");	
	
	printf("\n\nINGRESO DE LA INFORMACION DE LOS TURNOS");
	printf("\nIngrese la matricula del veterinario: ");
	scanf("%d",&ingreso.matricula);
	
	printf("\nIngrese la fecha del turno: ");
	printf("\n\t Dia: ");
	scanf("%d",&ingreso.cita.dia);
	while(ingreso.cita.dia<1 or ingreso.cita.dia>31)
	{
		printf("\n\n------------------------------ERROR!--------------------------------------------");
		printf("\nIngrese un dia que sea valido.");
		scanf("%d",&ingreso.cita.dia);
	}
	
	printf("\t Mes: ");
	scanf("%d",&ingreso.cita.mes);
	while(ingreso.cita.mes<1 or ingreso.cita.mes>12)
	{
		printf("\n\n------------------------------ERROR!--------------------------------------------");
		printf("\nIngrese un mes que sea valido.");
		scanf("%d",&ingreso.cita.mes);
	}
	
	printf("\t Ano: ");
	scanf("%d",&ingreso.cita.ano);
	
	printf("\nIngrese el DNI del dueño: ");
	scanf("%d",&ingreso.dni);
	
	printf("\nIngrese los detalles de la atencion: ");
	_flushall();
	gets(ingreso.evolucion);
	
	fwrite(&ingreso,sizeof(ingreso),1,puntero);
	
	fclose(puntero);
	
	puntero=fopen("Turnos.dat","ab+");
	fread(&ingreso,sizeof(ingreso),1,puntero);
	printf("\nMatricula del veterinario: %d",ingreso.matricula);
	
	fclose(puntero);

}

void listado()
{
	printf("==========================================");
	printf("\n           LISTADO DE ATENCIONES");
	printf("\n==========================================");		
	
	turno auxiliar,a[100],aux;
	int matriculaZ[100],vet[100];
	int j=0,i=0,c=0,k=0,m=0,b,b2,b3,b4=0;
	
	FILE *puntero;

	puntero=fopen("Turnos.dat","ab+");	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	printf("\n------------------------------------------");
	while(!feof(puntero))
	{
		
		//printf("\nINGRESA por %d vez",i+1);
		//printf("\nMatricula: %d",auxiliar.matricula);
		
		if(i==0)
		{
			matriculaZ[c]=auxiliar.matricula;
			c++;
			b3=1;
		}
		else
		{
			for(j=0;j<c;j++)
			{
				//printf("\n***FOR*****");
				//printf("\nIngresada: %d -- Comparar: %d",auxiliar.matricula,matriculaZ[j]);
				if(auxiliar.matricula==matriculaZ[j]) b3=1;
			}
		}
		
		if(b3==0)
		{
			matriculaZ[c]=auxiliar.matricula;
			c++;
		}
		
		i++;
		b3=0;
		fread(&auxiliar,sizeof(auxiliar),1,puntero);
		
		/*printf("\n\nLISTADO DE MATRICULAS: ");		
		for(j=0;j<c;j++)
		{

			printf("\nMatricula #%d: %d",j+1,matriculaZ[j]);
		}		
		printf("\n------------------------------------------");*/
	}
		
	i=0;
	
	rewind(puntero);
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	
	//HASTA AHORA C ES IGUAL A LA CANTIDAD DE VETERINARIOS UNICOS
	
	//
	
	k=0;
	j=0;
	for(i=0;i<c;i++) //mientras que i sea menor a la cantidad de veterinarios unicos
	{
//		printf("\n------------------------------------------------------");
//		printf("\nSegundo while #%d",i+1);
		while(!feof(puntero))
		{
//			printf("\nIngresa %d\n",auxiliar.matricula);
			for(j=0;j<c;j++)
			{
//				printf("\nIngresa: %d --- Compara: %d",auxiliar.matricula,matriculaZ[i]);

				if(matriculaZ[i]==auxiliar.matricula && b4==0) //compara la matricula del primer veterinario del vector con la matricula del veterinario del archivo
				{
					a[k]=auxiliar; //si corresponde, lo guarda a la vez que lo rodena en el vector, unicamente por veterinario
//					printf("\nLa matricula ingresada se guardo en %d",k);
					k++;
					b4=1;
				}
			}
			fread(&auxiliar,sizeof(auxiliar),1,puntero);
			b4=0;
		}
		
		vet[m]=i;
		m++;
		rewind(puntero);
	}
//	printf("\n------------------------------------------------------");
	
	for(i=0;i<m;i++)
	{
//		printf("\nMatricula %d: %d",i+1,matriculaZ[i]);
	}

//	printf("\n------------------------------------------------------");
/*	for(i=0;i<k;i++)
	{
		printf("\nTurno #%d",i+1);
		printf("\nMatricula: %d",a[i].matricula);
		printf("\nCita: %d/%d/%d",a[i].cita.dia,a[i].cita.mes,a[i].cita.ano);
		printf("\nDNI: %d",a[i].dni);
		printf("\n**********************");
	}	
	printf("\n------------------------------------------------------");	
		
	
	printf("\n\nHASTA ACA ESTAN ORDENADOS POR VETERINARIO\n\n");
*/	
	/*
	for(i=0;i<m;i++)
	{
		printf("El valor de vet es %d",vet[i]);
	}
	*/	
	//HASTA ACA ESTAN ORDENADOS POR VETERINARIO	
		
	int x=0;	
	for(x=0;x<c;x++)
	{
		for(j=0;a[j].matricula==matriculaZ[x];j++)
		{
//			printf("\nIngresa al for por #%d vez",j+1);
			do
			{
				b=0;
				for(i=0;i<c-1;i++)
				{
					if(a[i].matricula==a[i+1].matricula)
//					printf("Compara %d/%d/%d -- Con %d/%d/%d",a[i].cita.dia,a[i].cita.mes,a[i].cita.ano,a[i+1].cita.dia,a[i+1].cita.mes,a[i+1].cita.ano);
					if(a[i].cita.ano>a[i+1].cita.ano)
					{
//						printf("\n por el año, era mas antes este");
						aux=a[i];
						a[i]=a[i+1];
						a[i+1]=aux;	
						b=1;
					}
					else
					{
						if(a[i].cita.ano==a[i+1].cita.ano)
						{
							if(a[i].cita.mes>a[i+1].cita.mes)
							{
//								printf("\n por el mes, era mas antes este");
								aux=a[i];
								a[i]=a[i+1];
								a[i+1]=aux;	
								b=1;							
							}
							else
							{
								if(a[i].cita.mes==a[i+1].cita.mes)
								{
									if(a[i].cita.dia==a[i+1].cita.dia)
									{
//										printf("\n por el dia, era mas antes este");
										aux=a[i];
										a[i]=a[i+1];
										a[i+1]=aux;	
										b=1;									
									}
								}
							}
						}
					}
				}
			}while(b==1);
		}
	}	

	printf("\n\nLISTADO ORDENADO POR VETERINARIO Y POR FECHA:");
	for(i=0;i<k;i++)
	{
		if(a[i].matricula!=a[i-1].matricula) printf("\n\nMatricula %d: ",a[i].matricula);	
		printf("\n\tTurno #%d",i+1);
		printf("\n\tCita: %d/%d/%d",a[i].cita.dia,a[i].cita.mes,a[i].cita.ano);
		printf("\n\tDNI: %d",a[i].dni);
		printf("\n");
	}
		
}
