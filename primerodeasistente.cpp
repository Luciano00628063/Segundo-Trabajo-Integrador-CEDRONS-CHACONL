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
		printf("\t\n------------------------------------------");
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
					printf("\nNo puede hacer uso del programa si no ha iniciado sesion antes.");
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
					printf("\nNo puede hacer uso del programa si no ha iniciado sesion antes.");
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
					printf("\nNo puede hacer uso del programa si no ha iniciado sesion antes.");
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
	puntero=fopen("GestionUsuarios.dat","rb");

	
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
				strcpy(password,auxiliar.contrasena);
			}
			
			fread(&auxiliar,sizeof(auxiliar),1,puntero);
		}
		
		if(b=0)
		{
			printf("\n\n------------------------------ERROR!--------------------------------------------");
			printf("\nEl nombre de usuario ingresado no coincide con ningun usuario registrado.");
			printf("\nNombre de usuario: ");
			_flushall();
			gets(ingreso.usuario);
		}
	}
	
	b=0;
	
	printf("\nIngrese la contrasena: ");
	gets(ingreso.contrasena);
	while(b==0)
	{
		if(strcmp(ingreso.contrasena,password)!=0)
		{
			printf("\n\n------------------------------ERROR!--------------------------------------------");
			printf("\nLa contraseña ingresada no coincide con el usuario.");
			printf("\nIngrese la contraseña: ");
			gets(ingreso.contrasena);
		}
		else b=1;
	}
	
	if(b==1)
	{
		printf("\nSe ha iniciado sesion con exito!");
		bandera=1;
	}
	
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
	printf("\t Dia: ");
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
	
	
}

void listado()
{
	printf("==========================================");
	printf("\n           LISTADO DE ATENCIONES");
	printf("\n==========================================");		
	
	turno auxiliar,a[100];
	int matriculaZ[100];
	int j=0,i=0,c=0;
	
	FILE *puntero1;
	FILE *puntero2;
	
	puntero1=fopen("Mascotas.dat","b+");
	puntero2=fopen("Turno.dat","b+");
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero2);
	while(!feof(puntero2))
	{
		j=0;
		if(i==0)
		{
			matriculaZ[i]=auxiliar.matricula;
			c++;
		}
		else
		{
			while(j<c)
			{
				if(matriculaZ[j]!=auxiliar.matricula)
				{
					matriculaZ[i]=auxiliar.matricula;
					c++;
				}
			}	
		}
		i++;
		
	}
	
	i=0;
	
	rewind(puntero2);
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero2);
	
	while(i<c)
	{
		while(!feof(puntero2))
		{
			while(j<c)
			{
				if(matriculaZ[i]==auxiliar.matricula)
				{
					a[j]=auxiliar;
					j++;
				}
			}
		}
		i++;
		rewind(puntero2);
	}
	
	for(i=0;i<j;i++)
	{
		printf("\nMatricula del veterinario: %d",a[i].matricula);
	}
}
