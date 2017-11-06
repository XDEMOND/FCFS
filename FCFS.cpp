//@XDEMOND
#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#define numProcesos 10
#define N 5
#define LinpPag 100

struct MMT
{
	int numMarco,locIni, estadoTMM;
   MMT *sig;
}*iM=NULL, *fM=NULL, *nuevoM=NULL, *auxM=NULL;

struct PCB
{
	int idProceso;
   int nPag;
   int tLlegada;
   int ciclos;
   int memoria;
   char cpuES[10];
   int archivos;
   int nDisp;
   char tipo[10];
   int estado;
   int trp;
   PCB *sig;
} *piPCB=NULL, *pfPCB=NULL, *paPCB=NULL,*pnPCB=NULL;

struct JT
{
	int tarea,seleccion;
   JT *sig;
}*iJ=NULL, *fJ=NULL, *nuevoJ=NULL, *auxJ=NULL;

struct PMT
{
	int numPagina,estado;
   PMT *sig;
}*iP[N], *fP[N], *nuevoP[N], *auxP[N];

void crearMMT(int valor1);
void imprimeMMT();
void cambiarEstadoA2();

void cambiarEstadoA2()
{
  	paPCB=piPCB;
   while(paPCB!=NULL)
   {
   	paPCB->estado=2;
      paPCB=paPCB->sig;
   }
}

void crearJT()
{
	int i=1;
   do
   {
   	if(iJ==NULL)
      {
      	iJ = (JT *)malloc(sizeof(JT));
         iJ->tarea = i;
         iJ->sig = NULL;
         fJ = iJ;
      }
      else
      {
      	nuevoJ = (JT *)malloc(sizeof(JT));
         nuevoJ->tarea = i;
         fJ->sig = nuevoJ;
         fJ = nuevoJ;
         fJ->sig = NULL;
      }
      i++;
   }while(i<=N);
}

void crearPCB()
{
		int i =1;
      int x=0;
      int cont=1;
      int cont2=0;
      int marcos=0;
      auxJ=iJ;
	  do
   	{
   		auxP[i] = iP[i];
      	while(auxP[i]!=NULL)
      	{
      		if(auxP[i]->estado==1)
            {
            	if(piPCB==NULL)
               {
              		paPCB = (PCB *)malloc(sizeof(PCB));
               	paPCB->idProceso=cont++;
               	paPCB->tLlegada = cont2++;
               	paPCB->ciclos = 1+rand()%(10);
               	paPCB->estado = 1;
               	paPCB->memoria =rand()%(101-1);
                  x=rand()%(501-1);
                  if((x%2)==0)
                  {
                  	strcpy(paPCB->cpuES,"CPU");
                     paPCB->nDisp =0;
                  }
                  else
                  {
                  	strcpy(paPCB->cpuES,"ES");
                     paPCB->nDisp =rand()%(7-1);
                  }
                  paPCB->archivos =rand()%(11-1);
                  if((x%2)==0)
                  	strcpy(paPCB->tipo,"SISTEMA");
                  else
                  	strcpy(paPCB->tipo,"USUARIO");
                     marcos++;

                  paPCB->sig = NULL;
                  piPCB = paPCB;
                  pfPCB=piPCB;
               }
            	else
            	{
            		paPCB = (PCB *)malloc(sizeof(PCB));
               	paPCB->idProceso=cont++;
               	paPCB->tLlegada = cont2++;
               	paPCB->ciclos = 1+rand()%(10);
               	paPCB->estado = 1;
               	paPCB->memoria =rand()%(101-1);
                  x=rand()%(501-1);
                  if((x%2)==0)
                  {
                  	strcpy(paPCB->cpuES,"CPU");
                     paPCB->nDisp =0;
                  }
                  else
                  {
                  	strcpy(paPCB->cpuES,"ES");
                     paPCB->nDisp =rand()%(7-1);
                  }
                  paPCB->archivos = rand()%(11-1) ;
                  if((x%2)==0)
                  	strcpy(paPCB->tipo,"SISTEMA");
                  else
                  	strcpy(paPCB->tipo,"USUARIO");

                     paPCB->sig = NULL;
                     pfPCB->sig=paPCB;
                     pfPCB=paPCB;
                     marcos++;
            	}
         	}
            auxP[i] = auxP[i]->sig;


      	}
         i++;
      //getch();
   }while(i<=5);

crearMMT(marcos);

}

void imprimeMMT()
{
   nuevoM = iM;

	cout<<" \t\t\t\t*****Tabla de Mapa de Memoria*****"<<endl;
   cout<<"\nNum.Marco\tLoc Ini\t\tEstado\n";
   while(nuevoM!=NULL)
   {
   	cout<<nuevoM->numMarco<<"\t\t"<<nuevoM->locIni<<"\t\t"<<nuevoM->estadoTMM<<endl;
      nuevoM = nuevoM->sig;
   }
}

void crearMMT(int valor1)
{
	int Marcos=valor1;
	int i=0;
   do
   {
   	if(iM==NULL)
      {
      	iM = (MMT *)malloc(sizeof(MMT));
         iM->numMarco = i;
         iM->locIni = (i+100);
         iM->estadoTMM = 0;

         iM->sig=NULL;
         fM = iM;
      }
      else
      {
      	nuevoM = (MMT *)malloc(sizeof(MMT));
         nuevoM->numMarco = i;
         nuevoM->locIni = (i+100);
         nuevoM->estadoTMM = 0;
         fM->sig = nuevoM;
         fM = nuevoM;
      }
      i++;
   }while(i<Marcos);

   imprimeMMT();
}

void crearPMT()
{
	int cont;
	int i=1;
   int j,x;
   auxJ = iJ;
   do
   {
   	cont=0;
   	for(j=0;j<5;j++)
      {
      	if(iP[i]==NULL)
         {
         	iP[i]=(PMT *)malloc(sizeof(PMT));
            iP[i]->numPagina = j;
            iP[i]->estado = rand()%2;
            if(iP[i]->estado==1)
            	cont++;
            iP[i]->sig = NULL;
            fP[i] = iP[i];
         }
         else
         {
         	nuevoP[i] = (PMT *)malloc(sizeof(PMT));
            nuevoP[i]->numPagina = j;
            nuevoP[i]->estado = rand()%2;
            if(nuevoP[i]->estado==1)
            	cont++;
            nuevoP[i]->sig = NULL;
            fP[i]->sig = nuevoP[i];
            fP[i] = nuevoP[i];
         }
      }
      i++;
      auxJ->seleccion=cont;
      auxJ = auxJ->sig;
   }while(i<=N);
}


void imprimePMT()
{
	int i=1, j;
   cout<<"\n  \t\t\t\t*****Tabla PMT*****"<<endl;
   do
   {
   	auxP[i] = iP[i];
   	cout<<"\nTabla J"<<i<<endl;
      cout<<"Pagina\tEstado\n";
      while(auxP[i]!=NULL)
      {
      	cout<<"P"<<auxP[i]->numPagina<<"\t"<<auxP[i]->estado<<endl;
         auxP[i] = auxP[i]->sig;
      }
      i++;
      //getch();
   }while(i<=5);
}

void imprimeJT()
{
   auxJ = iJ;
	cout<<"\n \t\t\t\t*****Tabla de Tareas*****"<<endl;
   cout<<"\nTarea\n";
   while(auxJ!=NULL)
   {
   	cout<<"J"<<auxJ->tarea<<"\tSeleccion: "<<auxJ->seleccion<<endl;
      auxJ = auxJ->sig;
   }
}

void imprimePCB()
{
	paPCB=piPCB;
   cout<<"\n \t\t\t\t*****Tabla PCB*****"<<endl;
   cout<<"\nProceso\tT.lleg\tCiclos\tEstado\tMemoria\tCPU/ES\tNum_Dispvt Archivos\tTipo"<<endl;
   while(paPCB!=NULL)
   {
      cout<<paPCB->idProceso<<"\t"<<paPCB->tLlegada<<"\t"<<paPCB->ciclos<<"\t"<<paPCB->estado<<"\t"<<paPCB->memoria<<"\t"<<paPCB->cpuES<<"\t";
      cout<<paPCB->nDisp<<"\t\t"<<paPCB->archivos<<"\t"<<paPCB->tipo<<endl;
      paPCB=paPCB->sig;
   }
   system("pause");
}

void FCFS()
{
	auxM=iM;
    pnPCB=piPCB;
    float tps=0;
    imprimePCB();
    while((pnPCB!=NULL)&&(auxM!=NULL))
    {
        pnPCB->estado=3;
        auxM->estadoTMM=1;
        imprimeMMT();
        while(pnPCB->ciclos>0)
        {
            pnPCB->ciclos--;
            imprimePCB();
            tps=tps+1;
        }
        pnPCB->trp=tps;
        pnPCB->estado=5;
        auxM->estadoTMM=0;
        pnPCB=pnPCB->sig;
        auxM=auxM->sig;
    }
    pnPCB=piPCB;

    cout<<"\t\t\tTRP :";


    int no=0;
    tps=0;

    while(pnPCB!=NULL)
    {
        cout<<"P"<<pnPCB->idProceso<<": "<<pnPCB->trp<<"ms"<<endl;
        tps=tps+pnPCB->trp;
        pnPCB=pnPCB->sig;
        no++;
    }
    cout<<"\n\nTiempo Promedio del Sistema: "<<tps/no<<"ms"<<endl;
}

void main()
{
	crearJT();
   crearPMT();
   imprimePMT();
   imprimeJT();
	crearPCB();
   imprimePCB();
   cambiarEstadoA2();
   FCFS();
   system("pause");
}