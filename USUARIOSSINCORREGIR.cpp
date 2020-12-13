#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct user{
	char usuario[50];
	char contrasena[50];
};

void registrarVet();

main()
{
	int opcion;
	printf("Modulo Administracion");
	printf("\n=================================");
	printf("\n1.- Registrar Veterinario");
	printf("\n2.- Registrar Usuario Asistente");
	printf("\n3.- Atenciones por Veterinario");
	printf("\n4.- Ranking de Veterinarios por Atenciones");
	printf("\n5.- Cerrar la aplicacion");
	
	printf("\n\nIngrese	una opcion: ");
	scanf("%d",&opcion);
	
	switch(opcion){
		case 1:
			system("cls");
			registrarVet();
			system("cls");
			break;
	}
}

void registrarVet()
{
	FILE *puntero;
	puntero=fopen("GestionUsuarios.txt.dat","ab+");

	user auxiliar,nuevo;
	
	int b=1,i=0,n=0;
	int caracteres=0,mayusculas=0,digitos=0,diferencia;

		
	printf("REGISTRO DE NUEVO VETERINARIO");
	printf("\n=============================");

	_flushall();
	printf("\n\nIngrese el nombre de usuario: ");
	gets(nuevo.usuario);
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);


	while(b==1)
	{
		while(!feof(puntero))
		{
			if(strcmp(nuevo.usuario,auxiliar.usuario)==0) 
			{
				
				printf("\nEl nombre ingresado ya esta regisrtado, intente nuevamente.\nSi no desea registrar un usuario, ingrese la letra 'x'");
				gets(nuevo.usuario);
				
			}
			else b=0;

		}
		
		printf("SALE DEL WHILE DEL PUNTERO");
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);		
		
		printf("COMPRUEBA LO DE LA X");

		caracteres=strlen(nuevo.usuario);

		if(b==0)
		{
			printf("BANDERA DICE CORRECTO");
			if(caracteres<6 || caracteres>10)
			{
				b=1;
				printf("\nEl nombre de usuario debe tener entre 6 y 10 caracteres, intente nuevamente. \nSi no desea regisrar un usuario,ingrese la letra 'x'");
			}
		}
		
		printf("COMPRUEBA LO DE LA X");
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);

		if(b==0)
		{
			printf("BANDERADICECORRECTO");
			if(islower(nuevo.usuario[0])==0)
			{
				b=1;
				printf("\nEl nombre de usuario debe comenzar con letra minuscula, intente nuevamente \nSi no desea registrar un usuario, ingrese la letra 'x'");
			}
		}
		
		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);
		
		printf("COMPRUEBA LO DE LA X");

		while(nuevo.usuario[i]!='\0')
		{
			printf("COMPRUEBA QUE SEA FIN DE CARACTER");
			if(isupper(nuevo.usuario[i])>0) mayusculas++;
			i++;
		}
		
		if(b==0)
		{
			printf("BANDERADICECORRECTO");
			if(mayusculas<2)
			{
				b=1;
				printf("\nEl nombre de usuario debe tener al menos dos letras mayusculas, intente nuevamente. \nSi no desea registrar un usuario, ingrese la letra 'x'");
			}
		}

		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);
		
		printf("\nCOMPRUEBA LO DE LA X");
		
		i=0;
		while(nuevo.usuario[i]!='\0')
		{
			printf("\nCUENTADIGITOS");
			if(isdigit(nuevo.usuario[i])!=0) digitos++;
			i++;
		}		
		
		if(b=0)
		{
			printf("\nBANDERA DICE CORRECTO");
			if(digitos>3)
			{
				b=1;
				printf("\nEl nombre de usuario debe tener tres digitos como maximo, intente nuevamente. \nSi no desea registrar un usuario, ingrese la letra 'x'");
			}
		}

		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);
		
		printf("\nCOMPRUEBA LO DE LA X");
		
		fread(&auxiliar,sizeof(auxiliar),1,puntero);
	}
	
	while(b==0)
	{
		printf("\nCONTRASEÑA, BANDERA DICE CORRECTA");
		printf("\n\nEl nombre de usuario ha sido registrado y es: ");
		puts(nuevo.usuario);


		printf("\nIngrese la contraseña: ");
		_flushall();
		gets(nuevo.contrasena);
		
		caracteres=strlen(nuevo.contrasena);
		
		if(caracteres>=6 && caracteres<=32) b=1;
		else
		{
			printf("\nLa contraseña debe tener entre 6 y 32 caracteres, intente de nuevo");
		}
		
		i=0;
		
		while(nuevo.contrasena[i]!='\0')
		{
			printf("\nCUENTA 3 DIGITOS");
			n=0;
			if(isupper(nuevo.contrasena[i])>0) 
			{
				n++;
				if(islower(nuevo.contrasena[i])>0) 
				{
					n++;
					if(isdigit(nuevo.contrasena[i])>0) n++;
				}
			}
			
			i++;
		}
		
		if(b==1)
		{
			printf("\nBANDERA DICE CORRECTO");
			if(n!=3)
			{
				printf("\nLa contraseña debe tener al menos una letra mayuscula, una letra minuscula y un digito. Intentelo de nuevo.");
				b=0;
			}
		}
		
		if(b==1)
		{
			printf("\nBANDERA DICE CORRECTO");
			if(isalpha(nuevo.contrasena[i])==0) 
			{
				printf("\nLa contraseña solo debe tener caracteres alfanumericos. Intentelo de nuevo.");
				b=0;
			}
		}
		
		i=0;
		while(nuevo.usuario[i+3]!='\0')
		{
			printf("\nCOMPRUEBA DIGITOS CONSECUTIVOS");
			if(isdigit(nuevo.contrasena[i])>0 && isdigit(nuevo.contrasena[i+1])>0 && isdigit(nuevo.contrasena[i+2])>0 && isdigit(nuevo.contrasena[i+3])>0)
			{
				printf("\nLa contrasena no debe tener mas de 3 digitos seguidos. Intente de nuevo.");
				b=0;
			}
			i++;
		}
		
		i=0;
		
		if(b==1)
		{
			printf("\nCOMPRUEBA LETRAS CONSECUTIVAS");
			while(nuevo.contrasena[i+1]!='\0')
			{
			
				diferencia=nuevo.usuario[i+1]-nuevo.usuario[i];
				if(diferencia==1)
				{
					printf("\nLa contrasena no debe tener 2 caracteres consecutivos alfabeticamente. Intente de nuevo.");
					b=0;
				}
				i++;
			}
		}
		
		
	}
	
	if(b==0)
	{
		printf("\nEl usuario ha sido registrado correctamente.");
	}
	
	fwrite(&nuevo,sizeof(nuevo),1,puntero);
	
	fclose(puntero);

}
