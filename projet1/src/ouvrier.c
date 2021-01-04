



#include<stdio.h>
#include<string.h>
#include "ouvrier.h"
#include <gtk/gtk.h>


enum
{

     NOM,
     PRENOM,
     CIN,
     NUM_TEL,
     MAIL,
     ADRESSE,
     COLUMNS,
};
//ajouter ouvrier

void ajouter_ouvrier(ouvrier o)
{

FILE *f,*f1;
f=fopen("ouvrier.txt","a+");
if((f!=NULL))
{
fprintf(f,"%s %s %s %s %s %s\n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse);
}

fclose(f);
}

// supprimer ouvrier

void supprimer_ouvrier(char refer[])
{
FILE *f,*f1;
ouvrier o;

f=fopen("ouvrier.txt","r");
f1=fopen("ouvrier_tmp.txt","w");
 if ((f!=NULL))
{
while(fscanf(f,"%s %s %s %s %s %s\n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse)!=EOF)
{
if(strcmp(refer,o.cin)!=0)
{
fprintf(f1,"%s %s %s %s %s %s\n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse);
}
}
fclose(f) ;
fclose(f1);


remove("ouvrier.txt");
rename("ouvrier_tmp.txt","ouvrier.txt");
}
}

//modifier ouvrier
void modifier_ouvrier(ouvrier o)
{

ouvrier m;

FILE *f;
FILE *f2;
f=fopen("ouvrier.txt","r");
f2=fopen("ouvrier_tmp.txt","a+");
if (f!=NULL)
{
if (f2!=NULL)

{
     while (fscanf(f,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.cin,m.num_tel,m.mail,m.adresse)!=EOF)
    {
if (strcmp(o.cin,m.cin)==0){
   fprintf(f2,"%s %s %s %s %s %s\n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse);
}
else
{    fprintf(f2,"%s %s %s %s %s %s\n",m.nom,m.prenom,m.cin,m.num_tel,m.mail,m.adresse);
     }

}}
fclose(f2);
fclose(f);
remove("ouvrier.txt");
rename("ouvrier_tmp.txt","ouvrier.txt");

}


}

//verifier ouvrier
int verifier_cin(char CIN[])
{ouvrier o;
FILE *f;
int test = 0 ;
f=fopen("ouvrier.txt","r+");
if (f!=NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s\n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse)!=EOF)
       {
         if(strcmp(o.cin,CIN)==0)
         {
             test=1 ;
             return test;
         }
       }
    }
fclose(f);

return test;
}
//afficher ouvrier

void afficher_ouvrier(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;

char nom[25];
char prenom[35];
char cin[20];
char num_tel[20];
char mail[35];
char adresse[60];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num_tel",renderer, "text",NUM_TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADRESSE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("ouvrier.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("ouvrier.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,cin,num_tel,mail,adresse)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,NUM_TEL,num_tel,MAIL,mail,ADRESSE,adresse
);
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	
}

//afficher absence


void afficher_absence(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;
char annee[7];
char mois[5];
char jour[5];
char cin[20];
store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",NUM_TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	


}
	store=gtk_list_store_new(4,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("absence.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("absence.txt","a+");
	while(fscanf(f,"%s %s %s %s\n",jour,mois,annee,cin)!=EOF)
	{
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,NOM,jour,PRENOM,mois,CIN,annee,NUM_TEL,cin,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}
	
}




void enregristrer_absence(ouvrier o)
{
  FILE *f;
  
f=fopen("absence.txt","a+");
if(f!=NULL)
{
      fprintf(f,"%s %s %s %s\n",o.Absence.jour,o.Absence.mois,o.Absence.annee,o.cin);
}
fclose(f);
}

int meilleur(char cin5[],char mois5[],char anne5[])
{
   FILE *f=NULL;



   int t[9000],t1[9000],t2[9000];
     int i=0,x=0,j=0,n=0,l=0;
    int min=0;
    int cin=atol(cin5);
    int mois=atol(mois5);
    int anne=atol(anne5);
    int cin1,mois1,an1,jour1;
     
     f=fopen("absence.txt","a+");


         while(fscanf(f,"%d %d %d %d\n",&jour1,&mois1,&an1,&cin1)!=EOF)
            {//printf("%d\n",cin1);
                if((mois==mois1)&&(anne==an1))
                {
                    t[x]=cin1;x++;
                }

            }
   rewind(f);
                 for(j=0;j<=x;j++)
                 {
                    if (t[j]!=0)
                    {
                       t1[l]=t[j];l++;
                       for(n=0;n<=x;n++)
                        {
                          if(t[n]==t1[l-1])
                           {
                             t[n]=0;
                           }
                        }

                     }
                  }


              for(j=0;j<l;j++)
                 {   rewind(f);i=0;
                      while(fscanf(f,"%d %d %d %d\n",&jour1,&mois1,&an1,&cin1)!=EOF)
                        {
                            if((mois==mois1)&&(anne==an1))
                              {
                               if(cin1==t1[j])
                                 {
                                   t2[j]=i++;
                                 }
                              }
                         }
                 }
fclose(f);
for (i=0;i<l;i++)
  {
         if(t2[i]<t2[min])
          {
            min=i;
          }
  }
             
   

return t1[min];
}



void afficherm(GtkWidget *liste,char cinm[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;

char nom[25];
char prenom[35];
char cin[20];
char num_tel[20];
char mail[35];
char adresse[60];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" nom",renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" prenom",renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" cin",renderer, "text",CIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" num_tel",renderer, "text",NUM_TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" mail",renderer,"text",MAIL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" adresse",renderer, "text",ADRESSE,NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("ouvrier.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("ouvrier.txt","a+");
	while(fscanf(f,"%s %s %s %s %s %s\n",nom,prenom,cin,num_tel,mail,adresse)!=EOF)
	{if(strcmp(cin,cinm)==0)
          {
	gtk_list_store_append (store,&iter);
	gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,CIN,cin,NUM_TEL,num_tel,MAIL,mail,ADRESSE,adresse
);
          }
	}
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	
}





