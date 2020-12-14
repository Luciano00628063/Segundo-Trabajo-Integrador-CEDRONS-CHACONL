#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct user{
	char usuario[10];
	char contrasena[32];
	char puesto[20];
	int atenciones;
	char apeNom[60];
};


void registrar(int opcion);
void atencionesVet();
void rankingVet();
void listar();

main()
{
	int opcion,cargo;
	
	system("color 0b");	
	
	do
	{
	printf("==========================================");
	printf("\n\t   Modulo Administracion");
	printf("\t\n==========================================");
	printf("\t\n1.- Registrar Veterinario");
	printf("\t\n2.- Registrar Usuario Asistente");
	printf("\t\n3.- Atenciones por Veterinario");
	printf("\t\n4.- Ranking de Veterinarios por Atenciones");
	printf("\t\n5.- Cerrar la aplicacion");
	printf("\t\n------------------------------------------");
	printf("\t\nIngrese	una opcion: ");
	scanf("%d",&opcion);
	
	switch(opcion){
		case 1:
			system("cls");
			cargo=1;
			registrar(opcion);
			system("pause");
			system("cls");
			break;
		
		case 2:
			system("cls");
			cargo=2;
			registrar(opcion);
			system("pause");
			system("cls");
			break;
			
		case 3:
			system("cls");
			atencionesVet();
			system("pause");
			system("cls");
			break;
			
		case 4:
			system("cls");
			rankingVet();
			system("pause");
			system("cls");
			break;
			
		case 5:
			system("cls");
			printf("\nSe cerrará la aplicacion.");
			exit(1);
			break;
		
	}
	}while(opcion!=5);
}


void listar()
{
	FILE *puntero;
	puntero=fopen("Usuarios.dat","ab+");
	
	int i=0;
	user auxiliar;
	printf("\n");
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	//AGREGAR EL IF DEL CARGO
	
	while(!feof(puntero))
	{
		if(strcmp(auxiliar.puesto,"Veterinario")==0)
		{
			printf("\nVeterinario: %d",i+1);
			printf("\n---------------------");
			printf("\nNombre: "); puts(auxiliar.apeNom);
			printf("Usuario: %d: ",i+1);
			puts(auxiliar.usuario);
//			printf("\tContrasena: ");
//			puts(auxiliar.contrasena);
//			printf("Cargo: ");
//			puts(auxiliar.puesto);
//			printf("Cantidad de atenciones: %d",auxiliar.atenciones);
//			printf("\n\n");
			i++;
		}
		fread(&auxiliar,sizeof(auxiliar),1,puntero);
	}
	
	printf("\n\n");
}



void registrar(int opcion)
{
	FILE *puntero;
	puntero=fopen("Usuarios.dat","ab+");

	user auxiliar,nuevo;
	
	int b=1,i=0,a,c,d;
	int caracteres=0,mayusculas=0,digitos=0,alfa=0,diferencia=0;

	if(opcion==1)
	{
		printf("\t=============================");	
		printf("\n\tREGISTRO DE NUEVO VETERINARIO");
		printf("\n\t=============================");	
	}
	
	if(opcion==2)
	{
		printf("\t===========================");	
		printf("\n\tREGISTRO DE NUEVO ASISTENTE");
		printf("\n\t===========================");
		
	}

	_flushall();
	if(opcion==1) printf("\n\nIngrese el nombre y apellido del veterinario: ");
	if(opcion==2) printf("\n\nIngrese el nombre y apellido del asistente: ");
	gets(nuevo.apeNom);
	
	_flushall();
	printf("Ingrese el nombre de usuario: ");
	gets(nuevo.usuario);
	
	
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);


	while(b==1)
	{
		caracteres=0,mayusculas=0,digitos=0,alfa=0,diferencia=0;
		
		b=0;
		while(!feof(puntero))
		{
			if(strcmp(nuevo.usuario,auxiliar.usuario)==0)
			{
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nEl nombre ingresado ya esta regisrtado, intente nuevamente.\nSi no desea registrar un usuario, ingrese la letra 'x': ");
				_flushall();
				gets(nuevo.usuario);
				b=1;
			}
			else 
			{
				b=0;
				fread(&auxiliar,sizeof(auxiliar),1,puntero);			
			}
		}
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);		

		caracteres=strlen(nuevo.usuario);

		if(b==0)
		{
			if(caracteres<6 || caracteres>10)
			{
				b=1;
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - El nombre de usuario debe tener entre 6 y 10 caracteres, intente nuevamente. \nSi no desea regisrar un usuario,ingrese la letra 'x': ");
				_flushall();
				gets(nuevo.usuario);
			}
		}
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);

		if(b==0)
		{
			if(islower(nuevo.usuario[0])==0)
			{
				b=1;
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - El nombre de usuario debe comenzar con letra minuscula, intente nuevamente \nSi no desea registrar un usuario, ingrese la letra 'x': ");
				_flushall();
				gets(nuevo.usuario);
			}
		}
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);
		
		i=0;

		while(nuevo.usuario[i]!='\0')
		{
			if(isupper(nuevo.usuario[i])>0) mayusculas++;
			i++;
		}
		
		if(b==0)
		{
			if(mayusculas<2)
			{
				b=1;
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - El nombre de usuario debe tener al menos dos letras mayusculas, intente nuevamente. \nSi no desea registrar un usuario, ingrese la letra 'x': ");
				_flushall();
				gets(nuevo.usuario);
			}
		}

		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);
		
		i=0;
		while(nuevo.usuario[i]!='\0')
		{
			if(isdigit(nuevo.usuario[i])!=0) digitos++;
			i++;
		}		
		
		if(b==0)
		{
			if(digitos>3)
			{
				b=1;
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - El nombre de usuario debe tener tres digitos como maximo, intente nuevamente\nSi no desea registrar un usuario, ingrese la letra 'x': ");
				_flushall();
				gets(nuevo.usuario);
			}
		}

		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);		
		
	}
	
	if(b==0) 
	{
		printf("\n\nO - El nombre de usuario ha sido registrado y es: ");
		puts(nuevo.usuario);
	}

	if(b==0)
	{
		
		printf("\nIngrese la contrasena: ");
		_flushall();
		gets(nuevo.contrasena);		
	}

	while(b==0)
	{
		caracteres=0,mayusculas=0,digitos=0,alfa=0,diferencia=0;
		
		caracteres=strlen(nuevo.contrasena);
		
		if(caracteres>=6 && caracteres<=32) b=1;
		else
		{
			printf("\n\n------------------------------ERROR!--------------------------------------------");
			printf("\nX - La contraseña debe tener entre 6 y 32 caracteres, intente de nuevo: ");
			_flushall();
			gets(nuevo.contrasena);	
		}
		
		i=0;
		
		while(nuevo.contrasena[i]!='\0')
		{
			if(isupper(nuevo.contrasena[i])>0) a++;
			if(islower(nuevo.contrasena[i])>0) c++;
			if(isdigit(nuevo.contrasena[i])>0) d++;
			i++;
		}
		

		if(b==1)
		{
			if(a==0 || c==0 || d==0)
			{
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - La contraseña debe tener al menos una letra mayuscula, una letra minuscula y un digito. Intentelo de nuevo: ");
				_flushall();
				gets(nuevo.contrasena);	
				b=0;
			}
		}
		
		a=0;c=0;d=0;i=0;
		
		while(nuevo.contrasena[i]!='\0')
		{
			if(isalnum(nuevo.contrasena[i])==0) alfa++;
			i++;
		}
		
		if(b==1)
		{
			if(alfa!=0) 
			{
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - La contraseña solo debe tener caracteres alfanumericos. Intentelo de nuevo: ");
				_flushall();
				gets(nuevo.contrasena);	
				b=0;
			}
		}
		
		
		i=0;
		while(nuevo.usuario[i+3]!='\0')
		{
			if(isdigit(nuevo.contrasena[i])>0 && isdigit(nuevo.contrasena[i+1])>0 && isdigit(nuevo.contrasena[i+2])>0 && isdigit(nuevo.contrasena[i+3])>0)
			{
				printf("\n\n------------------------------ERROR!--------------------------------------------");
				printf("\nX - La contrasena no debe tener mas de 3 digitos seguidos. Intente de nuevo: ");
				_flushall();
				gets(nuevo.contrasena);	
				b=0;
			}
			i++;
		}
		
		i=0;
		
		if(b==1)
		{
			while(nuevo.contrasena[i+1]!='\0')
			{
				if(isalpha(nuevo.contrasena[i])!=0)
				{
					diferencia=nuevo.contrasena[i+1]-nuevo.contrasena[i];
					if(diferencia==1)
					{
						printf("\n\n------------------------------ERROR!--------------------------------------------");
						printf("\nX - La contrasena no debe tener 2 caracteres consecutivos alfabeticamente. \nIntente de nuevo: ");
						_flushall();
						gets(nuevo.contrasena);	
						b=0;
					}
					
				}
				i++;
			}
		}
		
		
	}
	
	nuevo.atenciones=0;
	
	if(opcion==1) strcat(nuevo.puesto,"Veterinario");
	if(opcion==2) strcat(nuevo.puesto,"Asistente");	

	printf("\nO - El usuario ha sido registrado correctamente.");
	printf("\n------------------------------------------------\n\n");
	
	
	fwrite(&nuevo,sizeof(nuevo),1,puntero);
	
	fclose(puntero);

}

void atencionesVet()
{
	user auxiliar;
	int b=0;
	FILE *puntero;
	char buscar[50],cargo[50];
	strcat(cargo,"Veterinario");
	puntero=fopen("Usuarios.dat","ab+");
	printf("==============================================");
	printf("\n----BUSQUEDA DE ATENCIONES POR VETERINARIO----");
	printf("\n==============================================");
	
	printf("\n\n\tLISTA DE USUARIOS");
	printf("\n\t-----------------");
	listar();
	
	printf("Ingrese el usuario del veterinario cuya cantidad de atenciones se desea conocer.Nombre de usuario: ");
	_flushall();
	gets(buscar);
	
	
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	
	if(feof(puntero)) printf("\nEl archivo no tiene contenido.");
	
	while(!feof(puntero))
	{
		//if(strcmp(auxiliar.puesto,cargo)==0)
		//{
			if(strcmp(buscar,auxiliar.usuario)==0)
			{
				printf("\n-. La cantidad de atenciones del usuario %s",buscar);
				printf(" es igual a: %d atencion/es.",auxiliar.atenciones);
				printf("\n---------------------------------------------------------------------------");
				b=1;
			}
			fread(&auxiliar,sizeof(auxiliar),1,puntero);
		//}
	}
	if(b==0) printf("\nEl usuario ingresado no coincide con ningun veterinario registrado.\n\n");
	
	printf("\n\n");
	fclose(puntero);
}

void rankingVet()
{
	FILE *puntero;
	puntero=fopen("Usuarios.dat","ab+");
	user auxiliar[100],a;
	int i=0,n=0,b=0,j=0,aux;
	
	printf("\t\t===================================");
	printf("\n\t\t------RANKING DE VETERINARIOS------");
	printf("\n\t\t===================================");
	
	
	fread(&a,sizeof(a),1,puntero);
	i=0;
	while(!feof(puntero))
	{
		auxiliar[i]=a;
		fread(&a,sizeof(a),1,puntero);
		i++;
	}	
	
	
	
	n=i;
	
	do{
		b=0;
		
		for(j=0;j<n;j++)
		{
			if(auxiliar[j].atenciones<auxiliar[j+1].atenciones)
			{
				aux=auxiliar[j].atenciones;
				auxiliar[j].atenciones=auxiliar[j+1].atenciones;
				auxiliar[j+1].atenciones=aux;
			}
		}
	}while(b==1);
	
	printf("\n\n");
	for(j=0;j<n;j++)
	{
		if(strcmp(auxiliar[j].puesto,"Veterinario")==0)
		{
			printf(".-#%d: %d Atenciones: ",j+1,auxiliar[j].atenciones);
			puts(auxiliar[j].apeNom);
			printf("\t\t   -Usuario "); puts(auxiliar[j].usuario); 
			printf("---------------------------------------\n");
		}
	}
	
	printf("\n\n");
}
