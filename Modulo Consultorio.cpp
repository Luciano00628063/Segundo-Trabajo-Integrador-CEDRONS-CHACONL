#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

const char nombreUsuarios[20]="Usuarios.dat";
const char nombreTurnos[20]="Turnos.dat";
const char nombreVeterinarios[20]="Veterinarios.dat";
const char nombreMascotas[25]="Mascotas.dat";
struct fecha
{
    int dia,mes,anio;
};
struct registroTurnos
{
    int matricula;
    fecha FechaAtencion;
    int dniDueno;
    int atenciones;
    char detalle[360];
    bool estado=false;
};

struct registro
{
    
    char usuario[20];
    char contrasena[20];
    char apellidoNombre[20];
    
};
struct registroVeterinario
{
    char ApeNom[60];
    int matricula;
    int dni;
    char telefono[25];
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
    
};
void registrarEvolucion(registroTurnos turnos[50],registroMascota mascotas[50],int numTurnos, int numMascotas, int buscarMatricula);
int menu();
void guardarArchivo(registroTurnos turnos[50], int numTurnos);
void ListarTurnos(registroMascota mascotas[50], registroTurnos turnos[50],int numMascotas, int numTurnos, int buscarMatricula);
void leerPasw(char frase[]);
bool IniciarSesion(registro usuarios[50],registroVeterinario veterinario[50],int numusuarios, int numVeterinarios, int &buscarMatricula);
void cargarRegistros(registro usuarios[50],registroVeterinario veterinario[50],registroMascota mascotas[50],registroTurnos turnos[50],int &numusuarios, int &numVeterinarios, int &numMascotas, int &numTurnos);
main()
{
    setlocale(LC_ALL, "spanish");
    system("color 0B");
    registro usuarios[50];
    registroVeterinario veterinario[50];
    registroMascota mascotas[50];
    registroTurnos turnos[50];
    int numusuarios=0, numVeterinarios=0, numMascotas=0, numTurnos=0, buscarMatricula;
    int opcion;
    bool ingresa=false;
    
    cargarRegistros(usuarios,veterinario,mascotas,turnos,numusuarios,numVeterinarios,numMascotas,numTurnos);
      do{
          opcion=menu();
          switch(opcion)
          {
              case 1: system("cls");
                      ingresa=IniciarSesion(usuarios,veterinario,numusuarios,numVeterinarios,buscarMatricula);
                      printf("\n\n");
                      system("pause");
                      
              break;
              case 2: if(ingresa==true)
                       {
                        system("cls");
                      ListarTurnos(mascotas,turnos,numMascotas,numTurnos,buscarMatricula);
                      
                      
                       }
                      else {
                      printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t PARA VISUALIZAR TURNOS, INICIE SESION...             ");
                      printf("\n\t\t\t------------------------------------------------------");
                      
                      }
                      printf("\n\n");
                      system("pause");
                      
                      
              break;
              case 3: if(ingresa==true)
                     {
                         registrarEvolucion(turnos,mascotas,numTurnos,numMascotas,buscarMatricula);
                     }
                      else {
                      printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t PARA REGISTRAR EVOLUCION DE LA MASCOTA, INICIE SESION... ");
                      printf("\n\t\t\t------------------------------------------------------");
                      
                      }
                      printf("\n\n");
                      system("pause");
                      
              break;
              case 4: guardarArchivo(turnos,numTurnos);
                      printf("\n\t\t\t------------------------------------------------------");
                      printf("\n\t\t\t  SALIENDO DEL PROGRAMA...                            ");
                      printf("\n\t\t\t------------------------------------------------------");
              break;
              default:    printf("\n\t\t\t------------------------------------------------------");
                          printf("\n\t\t\t  ERROR!!, INGRESE UNA DE LAS OPCIONES                ");
                          printf("\n\t\t\t------------------------------------------------------");
              break;
          }
      }while(opcion!=4);



system("pause");
}

int menu()
{
    
    int opcion;
    system("cls");
    printf("\n\t\t\t==============================================================");
    printf("\n\t\t\t      M O D U L O  C O N S U L T O R I O                      ");
    printf("\n\t\t\t==============================================================");
    printf("\n\t\t\t  1-INICIAR SESION                                            ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  2-VISUALIZAR LISTA DE ESPERA DE TURNOS (INFORME)            ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  3-REGISTRAR LA EVOLUCION DE LA MASCOTA                      ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  4-SALIR DE LA APLICACION                                    ");
    printf("\n\t\t\t--------------------------------------------------------------");
    printf("\n\t\t\t  INGRESE SU OPCION --> ");
    scanf("%d",&opcion);
    
    return opcion;
}

void cargarRegistros(registro usuarios[50],registroVeterinario veterinario[50],registroMascota mascotas[50],registroTurnos turnos[50],int &numusuarios, int &numVeterinarios, int &numMascotas, int &numTurnos)
{
  FILE *archivo;
  int i=0;
  archivo=fopen(nombreVeterinarios,"rb");
  if(archivo==NULL)
  {
      printf("\n\t\t\t-------------------------------------------------------------");
      printf("\n\t\t\t ESTE ARCHIVO NO FUE CREADO, COMUNÍQUESE CON ADMINISTRACIÓN. ");
      printf("\n\t\t\t------------------------------------------------------------");
  }  
  else
  {
      fread(&veterinario[i],sizeof(registroVeterinario),1,archivo);
      while(!feof(archivo))
      {
          i++;
          fread(&veterinario[i],sizeof(registroVeterinario),1,archivo);
      }
      numVeterinarios=i;
      i=0;
      fclose(archivo);
   } 
   
   archivo=fopen(nombreUsuarios,"rb");
   if(archivo==NULL)
  {
      printf("\n\t\t\t-------------------------------------------------------------");
      printf("\n\t\t\t ESTE ARCHIVO NO FUE CREADO, COMINUQUESE CON ADMINISTRACION. ");
      printf("\n\t\t\t------------------------------------------------------------");
  }  
  else
  {
      fread(&usuarios[i],sizeof(registro),1,archivo);
      while(!feof(archivo))
      {
          i++;
          fread(&usuarios[i],sizeof(registro),1,archivo);
      }
      numusuarios=i;
      i=0;
      fclose(archivo);
  }
  archivo=fopen(nombreMascotas,"rb");
   if(archivo==NULL)
  {
      printf("\n\t\t\t-------------------------------------------------------------");
      printf("\n\t\t\t ESTE ARCHIVO NO FUE CREADO, COMINUQUESE CON ADMINISTRACION. ");
      printf("\n\t\t\t------------------------------------------------------------");
  }  
  else
  {
      fread(&mascotas[i],sizeof(registroMascota),1,archivo);
      while(!feof(archivo))
      {
          i++;
          fread(&mascotas[i],sizeof(registroMascota),1,archivo);
      }
      numMascotas=i;
      i=0;
      fclose(archivo);
  }
  
  archivo=fopen(nombreTurnos,"rb");
   if(archivo==NULL)
  {
      printf("\n\t\t\t-------------------------------------------------------------");
      printf("\n\t\t\t ESTE ARCHIVO NO FUE CREADO, COMINUQUESE CON ADMINISTRACION. ");
      printf("\n\t\t\t------------------------------------------------------------");
  }  
  else
  {
      fread(&turnos[i],sizeof(registroTurnos),1,archivo);
      while(!feof(archivo))
      {
          i++;
          fread(&turnos[i],sizeof(registroTurnos),1,archivo);
      }
      numTurnos=i;
      i=0;
      fclose(archivo);
  }
  
  
   
}
bool IniciarSesion(registro usuarios[50],registroVeterinario veterinario[50],int numusuarios, int numVeterinarios, int &buscarMatricula)
{
    char Contra[10], buscarApenom[60];
    bool encontrado= false;
    system("cls");
           printf("\n\t\t----------------------------");
           printf("\n\t\t   INICIO DE SESION           ");
           printf("\n\t\t----------------------------");
           printf("\n\t\t MATRICULA-> ");
           scanf("%d",&buscarMatricula);
           printf("\n\t\t CONTRASEÑA -> ");
           leerPasw(Contra);
           
           for(int i=0; i<numVeterinarios;i++)
           {
               if(buscarMatricula==veterinario[i].matricula);
               {
                   strcpy(buscarApenom,veterinario[i].ApeNom);
                   encontrado=true;
                   i=numVeterinarios+1;
               }
           }
           
           if(encontrado==true)
           {
               encontrado=false;
               for(int i=0; i<numusuarios;i++)
               {
                   if(strcmp(buscarApenom,usuarios[i].apellidoNombre)==0)
                   {
                       if(strcmp(Contra,usuarios[i].contrasena)==0)
                       {
                           encontrado=true;
                           i=numusuarios+1;
                       }
                   }
               }
               if(encontrado==true)
               {
                   printf("\n\t\t----------------------------");
                   printf("\n\t\t INICIO DE SESION CON EXITO           ");
                   printf("\n\t\t----------------------------");
                   return true;
               }
               else
               {
                   printf("\n\t\t----------------------------");
                   printf("\n\t\t   DATOS INCORRECTOS        ");
                   printf("\n\t\t----------------------------");
                   return false;
               }
           }
           else
           {
                   printf("\n\t\t----------------------------");
                   printf("\n\t\t   DATOS INCORRECTOS        ");
                   printf("\n\t\t----------------------------");
                   return false;
           }
    
}
void leerPasw(char frase[])
{
    int i=0;
    _flushall();

    do
    {
        frase[i] = (unsigned char)getch();

        if(frase[i]!=8)  // no es retroceso
        {
            printf("*");  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            printf("\b \b");
            i--;  //el caracter a borrar e el backspace
        }
    
        _flushall();

    }while(frase[i-1]!=13);  // si presiona ENTER

    frase[i-1] = NULL;
    
}

void ListarTurnos(registroMascota mascotas[50], registroTurnos turnos[50],int numMascotas, int numTurnos, int buscarMatricula)
{
    fecha buscarFecha;
    bool encontrado=false;
    int dniAbuscar;
    printf("\n\t\t INGRESE LA FECHA PARA BUSCAR SUS RESPECTIVOS TURNOS...");
    printf("\n\t DIA: ");
    scanf("%d",&buscarFecha.dia);
    printf("\n\t MES: ");
    scanf("%d",&buscarFecha.mes);
    printf("\n\t AÑO: ");
    scanf("%d",&buscarFecha.anio);
    
    printf("\n\t===================================================================");
    printf("\n\t\t  LISTADO DE MASCOTAS CON TURNO PARA LA FECHA INGRESADA  ");
    printf("\n\t===================================================================");
    for(int i=0; i<numTurnos; i++)
    {
        if((buscarMatricula==turnos[i].matricula) and (turnos[i].estado==false))
        {
            if((buscarFecha.dia==turnos[i].FechaAtencion.dia) and (buscarFecha.mes==turnos[i].FechaAtencion.mes) and (buscarFecha.anio==turnos[i].FechaAtencion.anio))
            {
                encontrado=true;
                
                printf("\n------------------------------------------");
                printf("\n\t NUMERO DE TURNO  #%d",i+1);
                printf("\n------------------------------------------");
                printf("\n MATRICULA DEL VETERINARIO: %d",turnos[i].matricula);
                printf("\n FECHA ->   %d / %d / %d ",turnos[i].FechaAtencion.dia,turnos[i].FechaAtencion.mes,turnos[i].FechaAtencion.anio);
                printf("\n DNI DUEÑO: %d",turnos[i].dniDueno);
                
            }
        }
    }
    
    if(encontrado==false) 
    {
    printf("\n=============================================================");
    printf("\n\t\t  NO HAY TURNOS PARA EL DIA INGRESADO!!                                     ");
    printf("\n=============================================================");
    }
}

void registrarEvolucion(registroTurnos turnos[50],registroMascota mascotas[50],int numTurnos, int numMascotas, int buscarMatricula)
{
    system("cls");
    
    fecha buscarFecha;
    int dniDueno;
    bool encontrado=false;
    printf("\n\n\t INGRESE LA FECHA DEL TURNO A REGISTRAR.");
    printf("\n\t DIA: ");
    scanf("%d",&buscarFecha.dia);
    printf("\n\t MES: ");
    scanf("%d",&buscarFecha.mes);
    printf("\n\t AÑO: ");
    scanf("%d",&buscarFecha.anio);
    
    printf("\n\t\t INGRESE EL DNI DEL DUEÑO: ");
    scanf("%d",&dniDueno);
    
    printf("\n\t------------------------------------");
    printf("\n\t HISTORIA CLINICA DE LA MASCOTA     ");
    printf("\n\t------------------------------------");
    int verifica;
    for(int k=0; k<numMascotas; k++)
    {
        if(dniDueno==mascotas[k].dniDueno)
        {
         printf("\n NOMBRE Y APELLIDO: %s",mascotas[k].apellidoNombre);
	     printf("\n DOMICILIO: %s",mascotas[k].domicilio);
	     printf("\n DNI DEL DUEÑO: %d",mascotas[k].dniDueno);
	     printf("\n LOCALIDAD: %s",mascotas[k].localidad);
	     printf("\n FECHA NACIMIENTO: %d/ %d /%d ",mascotas[k].fechaNacimiento.dia,mascotas[k].fechaNacimiento.mes,mascotas[k].fechaNacimiento.anio);
	     printf("\n PESO MASCOTA: %.2f KG",mascotas[k].peso);
	     printf("\n EDAD DE LA MASCOTA: %d  AÑOS",buscarFecha.anio-mascotas[k].fechaNacimiento.anio);
	     printf("\n TELEFONO DE CONTACTO: %d",mascotas[k].telefono);
	     
	     printf("\n\n");
	     verifica=0;
        }
        else verifica=1;
        
            
        
    }
    if(verifica==1)
    {
        printf("\n\n----------------------------------------------------");
             printf("\n\t  LA MASCOTA NO POSEE HISTORIA CLINICA             ");
             printf("\n------------------------------------------------------");
    }
    
    printf("\n\n------------------------------------");
     printf("\n\t     REGISTRAR EVOLUCIÓN           ");
     printf("\n------------------------------------");
     verifica=0;
    for(int i=0; i<numTurnos; i++)
    {
        if((buscarMatricula==turnos[i].matricula) and (turnos[i].estado==false))
        {
            
            if((buscarFecha.dia==turnos[i].FechaAtencion.dia) and (buscarFecha.mes==turnos[i].FechaAtencion.mes) and (buscarFecha.anio==turnos[i].FechaAtencion.anio))
            {
                if(dniDueno==turnos[i].dniDueno)
                {
                    encontrado=true;
                    turnos[i].estado=true;
                    printf("\n\t INGRESA LOS DETALLES DE LA ATENCION: ");
                    _flushall();
                    gets(turnos[i].detalle);
                    turnos[i].atenciones++;
                    
                    i=numTurnos+1;
                    printf("\n\n----------------------------------------------------");
                     printf("\n\t  EVOLUCION GUARDADA                               ");
                     printf("\n------------------------------------------------------");
                     
                     
                }
                else verifica=1;
                
            }
        }
    }
    
    if(verifica==1)
    {
        printf("\n\n----------------------------------------------------");
                 printf("\n\t     NO SE HA PODIDO REGISTRAR                     ");
                 printf("\n------------------------------------------------------");
    }
    
    if(encontrado==false)
    {
     printf("\n\n------------------------------------");
     printf("\n\t NO SE HA ENCONTRADO EL TURNO       ");
     printf("\n------------------------------------");
    }
}

void guardarArchivo(registroTurnos turnos[50], int numTurnos)
{
    FILE *archivo;
    archivo=fopen(nombreTurnos,"w+b");
    for(int i=0; i<numTurnos; i++)
    {
        fwrite(&turnos[i],sizeof(registroTurnos),1,archivo);
    }
}





