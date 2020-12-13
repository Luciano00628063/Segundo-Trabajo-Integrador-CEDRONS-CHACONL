#include <stdio.h>
#include <stdlib.h>

struct fecha
{
    int dia, mes, anio;
};
struct registroMascota
{
    char apellidoNombre[50];
    char domicilio[30];
    int dniDueno;
    char localidad[30];
    fecha fechaNacimiento;
    float peso;
    int telefono;
    char detalleUltimaAtencion[360];
    char fechaUltimaAtencion[100];
};

main()
{
  FILE *archivo;
  registroMascota mascota;
  archivo=fopen("Mascotas.dat","r+b");
  if (archivo == NULL)
	{
		printf("Archivo no existente. Se procedera a su creacion");
		
		archivo = fopen("usuarios.dat", "a+b");
		
		if (archivo == NULL)
		{
			printf("Error al crear el archivo.");
			printf("\nFin del programa....");
			exit(1);
		}
		
		printf("\nArchivo creado exitosamente...\n\n");
		system("cls");
		system("pause");
	}
	fclose(archivo);
	 rewind(archivo);
	 archivo=fopen("Mascotas.dat","ab");
	 printf("\n nombre y apellido: ");
	 _flushall();
	 gets(mascota.apellidoNombre);
	 printf("\n domicilio: ");
	 gets(mascota.domicilio);
	 printf("\n DNI dueño: ");
	 scanf("%d",&mascota.dniDueno);
	 _flushall();
	 printf("\n localidad: ");
	 gets(mascota.localidad);
	 printf("\n fecha de nacimiento: ");
	 printf("\n dia: "); scanf("%d",&mascota.fechaNacimiento.dia);
	 printf("\n mes: "); scanf("%d",&mascota.fechaNacimiento.mes);
	 printf("\n anio: "); scanf("%d",&mascota.fechaNacimiento.anio);
	 printf("\n peso: ");
	 scanf("%f",&mascota.peso);
	 printf("\n telefono: ");
	 scanf("%d",&mascota.telefono);
	 
	 fwrite(&mascota,sizeof(registroMascota),1,archivo);
	 fclose(archivo);
	 rewind(archivo);
	 archivo=fopen("Mascotas.dat","rb");
	 fread(&mascota,sizeof(registroMascota),1,archivo);
	 while(!feof(archivo))
	 {
	     printf("\n nombre y apellido: %s",mascota.apellidoNombre);
	     printf("\n domicilio: %s",mascota.domicilio);
	     printf("\n dni dueño: %d",mascota.dniDueno);
	     printf("\n localidad: %s",mascota.localidad);
	     printf("\n fecha: %d/ %d /%d ",mascota.fechaNacimiento.dia,mascota.fechaNacimiento.mes,mascota.fechaNacimiento.anio);
	     printf("\n peso: %.2f",mascota.peso);
	     printf("\n telefono: %d",mascota.telefono);
	     
	     printf("\n\n");
	     fread(&mascota,sizeof(registroMascota),1,archivo);
     }
  



system("pause");
}

