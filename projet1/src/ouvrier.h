#include <gtk/gtk.h>
typedef struct{

char annee[7];
char mois[5];
char jour[5];
}Date;

typedef struct
{
char nom[25];
char prenom[35];
char cin[20];
char num_tel[20];
char mail[35];
char adresse[60];
Date Absence;

}ouvrier;
void ajouter_ouvrier(ouvrier o);
void afficher_ouvrier(GtkWidget *liste);
void afficher_absence(GtkWidget *liste);
void supprimer_ouvrier(char refer[]);
void modifier_ouvrier(ouvrier o);
int verifier_cin(char CIN[]);
void enregristrer_absence (ouvrier o);
int meilleur(char cin5[],char mois5[],char anne5[]);
void afficherm(GtkWidget *liste,char cinm[]);
