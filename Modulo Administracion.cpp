#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include <locale.h>

struct user{
	char usuario[10];
	char contrasena[32];
	int matricula;
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
	setlocale(LC_ALL, "spanish");
	
	do
	{
	printf("\n\t============================================");
	printf("\n\t   M O D U L O  A D M I N I S T R A C I O N ");
	printf("\n\t============================================");
	printf("\n\t 1-REGISTRAR VETERINARIO                    ");
	printf("\n\t--------------------------------------------");
	printf("\n\t 2-REGISTRAR USUARIO ASISTENTE              ");
	printf("\n\t--------------------------------------------");
	printf("\n\t 3-ATENCIONES POR VETERINARIO               ");
	printf("\n\t--------------------------------------------");
	printf("\n\t 4-RANKING DE VETERINARIOS POR ATENCIONES   ");
	printf("\n\t--------------------------------------------");
	printf("\n\t 5-SALIR DE LA APLICACION                   ");
    printf("\n\t--------------------------------------------");
	printf("\n\t  INGRESE UNA OPCION:  ");
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
		    printf("\n\t--------------------------------------------");
        	printf("\n\t SALIENDO DE LA APLICACION...               ");
            printf("\n\t--------------------------------------------");
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
	
	while(!feof(puntero))
	{	
		if(strcmp(auxiliar.puesto,"Veterinario")==0)
		{
		    printf("\n\t---------------------");
			printf("\n\tVETERINARIO: %d",i+1);
			printf("\n\t---------------------");
			printf("\n\t NOMBRE: "); puts(auxiliar.apeNom);
			printf("\n\t USUARIOS: %d: ",i+1);
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
	FILE *puntero2;
	puntero=fopen("Usuarios.dat","ab+");

	user auxiliar,nuevo;
	
	int b=1,i=0,a,c,d;
	int caracteres=0,mayusculas=0,digitos=0,alfa=0,diferencia=0;

	if(opcion==1)
	{
		printf("\n\t===================================");	
		printf("\n\tREGISTRO DE NUEVO VETERINARIO      ");
		printf("\n\t===================================");	
	}
	
	if(opcion==2)
	{
		printf("\n\t=====================================");	
		printf("\n\tREGISTRO DE NUEVO ASISTENTE          ");
		printf("\n\t=====================================");
		
	}

	_flushall();
	if(opcion==1) printf("\n\n\t INGRESE NOMBRE Y APELLIDO DEL VETERINARIO:  ");
	if(opcion==2) printf("\n\n\t INGRESE EL NOMBRE Y APELLIDO DEL ASISTENTE: ");
	gets(nuevo.apeNom);
	
	_flushall();
	printf("\n\t INGRESE NOMBRE DE USUARIO: ");
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
				printf("\n\n\t------------------------------ERROR!------------------------------------------");
				printf("\n\tEL NOMBRE YA SE ECUENTRA REGISTRADO\n\t INTENTE NUEVAMENTE.");
				printf("\n\t--------------------------------------------------------------------------------");
				printf("\nIngrese el nombre de usuario: ");

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
				printf("\n\n\t--------------------------ERROR!---------------------------------------");
				printf("\n X - EL NOMBRE DE USUARIO DEBE CONTENER ENTRE 6 Y 10 CARACTERES\n\t INTENTE NUEVAMENTE.");
				printf("\n\t----------------------------------------------------------------------");
				printf("\nIngrese el nombre de usuario: ");
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
				printf("\n\n\t----------------------------ERROR!--------------------------------------");
				printf("\n\tX -EL NOMBRE DE USUARIO DEBE COMENZAR CON LETRA MINUSCULA\n\tINTENTE NUEVAMENTE");
				printf("\n\t------------------------------------------------------------------------");
				printf("\nIngrese el nombre de usuario: ");
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
				printf("\n\n\t-------------------------ERROR!---------------------------------------");
				printf("\n\tX -EL NOMBRE DE USUARIO DEBE TENER AL MENOS DOS LETRAS MAYUSCULAS\n\t INTENTE NUEVAMENTE ");
			    printf("\n\t------------------------------------------------------------------------");
			    printf("\nIngrese el nombre de usuario: ");
				
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
				printf("\n\n\t---------------------------ERROR!--------------------------------------");
				printf("\n\tX -EL NOMBRE DE USUARIO DEBE TENER TRES DIGITOS COMO MAXIMO\n\t INTENTE NUEVAMENTE ");
				printf("\n\t---------------------------------------------------------------------");
				printf("\nIngrese el nombre de usuario: ");
		
				_flushall();
				gets(nuevo.usuario);
			}
		}

		if(nuevo.usuario[0]=='x' or nuevo.usuario[0]=='X') exit(1);		
		
	}
	
	if(b==0) 
	{
	    printf("\n\n\t------------------------------------------------------------------------");
	    printf("\n\tX -EL NOMBRE DE USUARIO HA SIDO REGISTRADO Y ES: ");
	    puts(nuevo.usuario);
	    printf("\n\t------------------------------------------------------------------------");
	
		
	}

	if(b==0)
	{
		
		printf("\n\t INGRESE CONTRASEÑA:  ");
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
            printf("\n\n\t-------------------------ERROR!---------------------------------");
		    printf("\n\tX -LA CONTRASEÑA DEBE TENER ENTRE 6 Y 32 CARACTERES\n\tINTENTE NUEVAMENTE: ");
		    printf("\n\t---------------------------------------------------------------");
		    printf("\nIngrese el nombre de usuario: ");
		
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
			    printf("\n\n\t------------------------------ERROR!--------------------------------------");
		        printf("\n\tX -LA CONTRASEÑA DEBE TENER AL MENOS UNA LETRA MAYUSCULA, UNA LETRA MINUSCULA Y UN DIGITO\n\tINTENTE NUEVAMENTE: ");
		        printf("\n\t-------------------------------------------------------------------------");
		        printf("\nIngrese el nombre de usuario: ");
				
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
			    printf("\n\n\t-------------------------ERROR!-----------------------------------");
		        printf("\n\tX -LA CONTRASEÑA SOLO DEBE TENER CARACTERES ALFANUMERICO\n\tINTENTE NUEVAMENTE: ");
		        printf("\n\t--------------------------------------------------------------");
		        printf("\nIngrese el nombre de usuario: ");
				
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
			    printf("\n\n\t---------------------------ERROR!----------------------------------");
		        printf("\n\tX -LA CONTRASEÑA NO DEBE TENER MAS DE 3 DIGITOS SEGUIDOS\n\tINTENTE NUEVAMENTE: ");
		        printf("\n\t---------------------------------------------------------------------");
		        printf("\nIngrese el nombre de usuario: ");
			
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
					    printf("\n\n\t-------------------------------ERROR!------------------------------");
                        printf("\n\tX -LA CONTRASEÑA NO DEBE TENER 2 CARACTERES CONSECUTIVOS ALFABETICAMENTE, INTENTE NUEVAMENTE: ");
		                printf("\n\t--------------------------------------------------------------");
		                printf("\nIngrese el nombre de usuario: ");
					
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
	
	if(opcion==1) strcpy(nuevo.puesto,"Veterinario");
	if(opcion==2) strcpy(nuevo.puesto,"Asistente");	

	
	printf("\nINGRESE EL NUMERO DE MATRICULA CORRESPONDIENTE AL USUARIO INRGESADO: ");
	scanf("%d",&nuevo.matricula);
	
	puntero2=fopen("Usuarios.dat","ab+");
	fread(&auxiliar,sizeof(auxiliar),1,puntero2);
	while(b==1)
	{
		b=0;
		while(!feof(puntero2))
		{
			if(auxiliar.matricula==nuevo.matricula) b=1;
			fread(&auxiliar,sizeof(auxiliar),1,puntero2);
		}
		if(b==1)
		{
			printf("LA MATRICULA INGRESADA CORRESPONDE A OTRO USUARIO INGRESADO.\nINGRESE UNA DISTINTA");
			scanf("%d",&nuevo.matricula);
		}
	}

	printf("\n\n\t------------------------------------------------------------------------");
    printf("\n\t  EL REGISTRO HA SIDO INGRESADO CORRECTAMENTE                               ");
    printf("\n\t-------------------------------------------------------------------------");
	
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
	printf("\n\t==============================================");
	printf("\n\t    BUSQUEDA DE ATENCIONES POR VETERINARIO    ");
	printf("\n\t==============================================");
	
	printf("\n\n\tLISTA DE USUARIOS");
	printf("\n\t-----------------");
	listar();
	
	printf("\n\tINGRESE EL USUARIO DEL VETERINARIO CUYA CANTIDAD \n\tDE ATENCIONES DESEA CONOCER: ");
	printf("\n\t NOMBRE DE USUARIO: ");
	_flushall();
	gets(buscar);
	
	
	
	fread(&auxiliar,sizeof(auxiliar),1,puntero);
	
	if(feof(puntero)) printf("\n\t***EL ARCHIVO NO TIENE CONTENIDO***");
	
	while(!feof(puntero))
	{
		//if(strcmp(auxiliar.puesto,cargo)==0)
		//{
			if(strcmp(buscar,auxiliar.usuario)==0)
			{
			    printf("\n\t--------------------------------------------------");
				printf("\n\t LA CANTIDAD DE ATENCIONES DEL USUARIO %s",buscar);
				printf(" \n\tES IGUAL A: %d ATENCION/ES.",auxiliar.atenciones);
				printf("\n\t--------------------------------------------------");
				b=1;
			}
			fread(&auxiliar,sizeof(auxiliar),1,puntero);
		//}
	}
	if(b==0) printf("\n\t EL USUARIO REGISTRADO NO COINCIDE CON NINGUN VETERINARIO REGISTRADO.\n\n");
	
	printf("\n\n");
	fclose(puntero);
}

void rankingVet()
{
	FILE *puntero;
	puntero=fopen("Usuarios.dat","ab+");
	user auxiliar[100],a;
	int i=0,n=0,b=0,j=0,aux;
	
	printf("\n\t===================================");
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
	i=0;
	for(j=0;j<n;j++)
	{
		if(strcmp(auxiliar[j].puesto,"Veterinario")==0)
		{
			printf(".-#%d: %d ATENCIONES: ",i+1,auxiliar[j].atenciones);
			puts(auxiliar[j].apeNom);
			printf("\t\t   -USUARIOS: "); puts(auxiliar[j].usuario); 
			printf("---------------------------------------\n");
			i++;
		}
	}
	
//	listar();
	
	
	printf("\n\n");
}
