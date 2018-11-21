#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define p printf
#define s scanf
#define fp fprintf
void Solicitar();
void Consultar();
void Imprimir();
void Borrar ();

int i,x,opc,n,c;
 char contenido [100];
	struct datos
	{
		char nombre[10];
		char apellidoP[10];
		char apellidoM[10];
		char telefono[15];
		char direccion[20];
	};
struct datos contacto [50];
FILE *Directorio;

int main()
{
	//p("\t\t\tA G E N D A\n\n\n");
	if((Directorio=fopen("Contactos.txt","w+"))==NULL)
	{
		p("No se puede abrir .\n");
	}
	else
	{
				do
		{
			p("\tMENU\n");
			p("1)Altas \n");
			p("2)Bajas\n");
			p("3)Consultas\n");
			p("4)Salir\n");
			p("Elige una opcion: ");
			s("%d",&opc);
			
			switch(opc)
			{
				case 1:
					p("Cuantos contactos desea agregar?  ");
					s("%d",&n);
					for(i=1;i<=n;i++)
					{
						Solicitar();
					}
					Imprimir();
					fclose(Directorio);
					p("Contactos Guardados .\n");
					
					
				break;
				
				case 2:
					Borrar();
					getch();
				break;
				
				case 3:
					Consultar();	
				break;
				
				case 4:
						p("Programa terminado\n");
				break;
				
				default:
						p("Opcion no valida\n");
				break;

			}
			system("pause");
			system("cls");
		}while (opc!=4);
		p("Vuelva pronto");	
	}
	
	
	return 0;
}

void Solicitar ()
{
	p("Nombre %d: ",i);
	s("%s",&contacto[i].nombre);
	strupr(contacto[i].nombre);	
	
	p("Apellido paterno %d: ",i);
	scanf("%s",&contacto[i].apellidoP);
	strupr(contacto[i].apellidoP);
	
	p("Apellido materno %d: ",i);
	s("%s",&contacto[i].apellidoM);
	strupr(contacto[i].apellidoM);
	
	p("Telefono %d: ",i);
	s("%s",&contacto[i].telefono);
	strupr(contacto[i].telefono);
	
	p("Direccion %d (sin espacios, separandola por un punto o guion bajo): ",i);
	s("%s",&contacto[i].direccion);
	strupr(contacto[i].direccion);
	p("\n");
}
void Borrar()
{
	int j=1;
	p("\nEsribe el numero de contacto que quieres borrar: ");
	s("%d", &x);
	if((Directorio=fopen("Contactos.txt","w+"))==NULL)
	{
		p("ERROR\n");
	}
	else 
	{
		for(int t=0; t<=10;t++)
		{
		contacto[x].nombre[t]=' ';
		contacto[x].apellidoP[t]=' ';
		contacto[x].apellidoM[t]=' ';
		contacto[x].direccion[t]=' ';
		contacto[x].telefono[t]=' ';			
		}

		for(int j=1;j<=i;j++)
		  {
		  	fprintf(Directorio,"Nombre %d: %s %s %s \n", j,contacto[j].nombre, contacto[j].apellidoP,contacto[j].apellidoM);
		  	fprintf(Directorio,"Direccion %d: %s\n", j, contacto[j].direccion);
		  	fprintf(Directorio,"Telefono %d: %s\n", j, contacto[j].telefono);
		  	fprintf(Directorio,"\n");
		  }
	   p("Se ha borrado su contacto\n");	
	  fclose(Directorio);
	}
}

void Consultar()
{
		if ((Directorio=fopen("Contactos.txt","r"))==NULL)
   {
   	p("El archivo no se pudo abrir para la consulta");
   }	
   else
   {
   	 while (feof(Directorio) == 0)
   	 {
   	 	    fgets (contenido, 100, Directorio);
            p("%s", contenido);
   	 }
            fclose(Directorio);
   } 
				
}

void Imprimir()
{
	fp(Directorio,"\t\tA G E N D A\n\n");
	for(i=1;i<=n;i++)
	{
		fp(Directorio,"Contacto %d\n",i);
		fp(Directorio,"Nombre:  %s %s %s\n",contacto[i].nombre,contacto[i].apellidoP,contacto[i].apellidoM);
		fp(Directorio,"Direccion:  %s\n",contacto[i].direccion);
		fp(Directorio,"Telefono:  %s\n",contacto[i].telefono);
		fp(Directorio,"\n");
	}
}

