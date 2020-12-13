#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

struct fecha
{
    int dia,mes,anio;
};
struct registroTurnos
{
    int matricula;
    fecha FechaAtencion;
    int dniDueno;
    char detalle[360];
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
struct nodo
 {
     registroTurnos turnos;
     nodo *siguiente;
 };
void cargar(nodo *&frente, nodo *&fondo, registroTurnos auxiliar);
main()
{
    setlocale(LC_ALL, "spanish");
  nodo *frente, *fondo;
  registroTurnos aux;
  frente=NULL;
  fondo=NULL;
  FILE *archivo;
  int cantidad=1;
  archivo=fopen("Turnos.dat","r+b");
  fread(&aux,sizeof(registroTurnos),1,archivo);
  while(!feof(archivo))
  {
      cargar(frente,fondo,aux);
      fread(&aux,sizeof(registroTurnos),1,archivo);
      
      
  }
    fclose(archivo);
   system("pause");
/*rewind(archivo);
   fread(&aux,sizeof(registroTurnos),1,archivo);
   while(!feof(archivo))
  {
      printf("\n=============================");
      printf("\n| TURNO  #%d ", cantidad);
      printf("\n| matricula: %d",aux.matricula);
      printf("\n| fecha : %d/ %d/ %d",aux.FechaAtencion.dia,aux.FechaAtencion.mes,aux.FechaAtencion.anio);
      printf("\n| dni dueño: %d",aux.dniDueno);
	     fread(&aux,sizeof(registroTurnos),1,archivo);
	     cantidad++;
      
  }*/
  
  nodo *aux1;
  aux1=frente;
  while(aux1!=NULL)
  {
      printf("\n=============================");
      printf("\n| TURNO  #%d ", cantidad);
      printf("\n| matricula: %d",aux1->turnos.matricula);
      printf("\n| fecha : %d/ %d/ %d",aux1->turnos.FechaAtencion.dia,aux1->turnos.FechaAtencion.mes,aux1->turnos.FechaAtencion.anio);
      printf("\n| dni dueño: %d",aux1->turnos.dniDueno);
      aux1=aux1->siguiente;
      cantidad++;
  }
   
  
  system("pause");
  int opcion;
  
  printf("\n\n Desea mostrar el turno de hoy?");
  printf("\n 1-si        2=no");
  scanf("%d",&opcion);
  cantidad=1;
  if(opcion==1)
  {
     printf("1111");
      registroTurnos auxiliar;
      if(frente!=NULL)
      {
       nodo *p;
      p=frente;
      printf("entre al ifs");
      auxiliar.matricula=p->turnos.matricula;
      auxiliar.FechaAtencion.dia=p->turnos.FechaAtencion.dia;
      auxiliar.FechaAtencion.mes=p->turnos.FechaAtencion.mes;
      auxiliar.FechaAtencion.anio=p->turnos.FechaAtencion.anio;
      auxiliar.dniDueno=p->turnos.dniDueno;
      
      
      printf("\n\n TURNO  #%d ", cantidad);
      printf("\n matricula: %d",auxiliar.matricula);
      printf("\n fecha : %d/ %d/ %d",auxiliar.FechaAtencion.dia,auxiliar.FechaAtencion.mes,auxiliar.FechaAtencion.anio);
	     printf("\n dni dueño: %d",auxiliar.dniDueno);
	     cantidad++;
	 }
	 FILE *archi;
	 int verif=0;
	 registroMascota mascota;
	 archi=fopen("Mascotas.dat","r+b");
	 fread(&mascota,sizeof(registroMascota),1,archi);
	 printf("\n VERIFICAR SI EXISTE HISTORIA CLINICA...");
	 
	 while(!feof(archi))
	 {
	     if(auxiliar.dniDueno==mascota.dniDueno)
	     {
	         printf("\n nombre y apellido: %s",mascota.apellidoNombre);
	     printf("\n domicilio: %s",mascota.domicilio);
	     printf("\n dni dueño: %d",mascota.dniDueno);
	     printf("\n localidad: %s",mascota.localidad);
	     printf("\n fecha: %d/ %d /%d ",mascota.fechaNacimiento.dia,mascota.fechaNacimiento.mes,mascota.fechaNacimiento.anio);
	     printf("\n peso: %.2f",mascota.peso);
	     printf("\n telefono: %d",mascota.telefono);
	     
	     printf("\n\n");
         }
         else verif=1;
         fread(&mascota,sizeof(registroMascota),1,archi);
          
         
     }
    
     if(verif==1) 
     {
     int opc;
     printf("\n no se ha encontrado la historia clinica...");
     printf("\n desea crear historia clinica?: 1=si  2=no ");
     scanf("%d",&opc);
     if(opc==1)
     {
        rewind(archi);
	 
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
	 
	 
	 fwrite(&mascota,sizeof(registroMascota),1,archi);
	 
     }
     
	 fclose(archi);
  }
  

}

system("pause");
}
void cargar(nodo *&frente, nodo *&fondo, registroTurnos auxiliar)
{
    nodo *auxiliar1;
    auxiliar1=new nodo;
    if(auxiliar1!=NULL)
    {
        auxiliar1->turnos=auxiliar;
        auxiliar1->siguiente=NULL;
        if(frente==NULL)
        frente=auxiliar1;
        else 
        fondo->siguiente=auxiliar1;
        fondo=auxiliar1;
        printf("sdf");
    }
    else printf("\n COLA LLENA");
}
