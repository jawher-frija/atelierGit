#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ouvrier.h"
#include <string.h>
#include "fonction.h"
void
on_buttonb3_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj1 ;
 GtkWidget *windowj2;


windowj2 = create_windowj2();
gtk_widget_show (windowj2);

windowj1=lookup_widget(button,"windowj1");
gtk_widget_hide(windowj1);

}


void
on_buttonb4_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj7, *windowj1;
windowj7 = create_windowj7();
gtk_widget_show (windowj7);


windowj1=lookup_widget(button,"windowj1");
gtk_widget_destroy(windowj1);
/*windowj3 = create_windowj3();
gtk_widget_show (windowj3);*/

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj1 ;
 GtkWidget *windowj0;


windowj0 = create_windowj0();
gtk_widget_show (windowj0);

windowj1=lookup_widget(button,"windowj1");
gtk_widget_hide(windowj1);


}


void
on_buttonb5_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj1, *windowj5;
windowj1=lookup_widget(button,"windowj1");
gtk_widget_hide(windowj1);
windowj5 = create_windowj5();
gtk_widget_show (windowj5);

}


void
on_buttonb7_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{ouvrier o;

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6;


input1=lookup_widget(button,"entryb3");
input2=lookup_widget(button,"entryb4");
input3=lookup_widget(button,"entryb5");
input4=lookup_widget(button,"entryb6");
input5=lookup_widget(button,"entryb7");
input6=lookup_widget(button,"entryb8");




strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(o.num_tel,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(o.mail,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(o.adresse,gtk_entry_get_text(GTK_ENTRY(input6)));



       
ajouter_ouvrier(o);


}


void
on_buttonbackb2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj2, *windowj1;
windowj2=lookup_widget(button,"windowj2");
gtk_widget_hide(windowj2);
windowj1 = create_windowj1();
gtk_widget_show (windowj1);

}


void
on_buttonbackb3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj2, *windowj1;
windowj2=lookup_widget(button,"windowj2");
gtk_widget_hide(windowj2);
windowj1 = create_windowj1();
gtk_widget_show (windowj1);

}


void
on_buttonb13_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj2;
ouvrier o;
GtkWidget *treeview;
windowj2=lookup_widget(button,"windowj2");
treeview=lookup_widget(windowj2,"treeviewb1");
afficher_ouvrier(treeview);
}


void
on_buttonb9_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{char CIN[20];
int test;
ouvrier o;
GtkWidget *entryb13, *entryb14,*entryb15,*entryb16,*entryb17,*entryb18,*entryb11;
GtkWidget *windowj2,*windowj4;
GtkWidget *output;

windowj4=create_windowj4();

entryb13=lookup_widget(windowj4,"entryb13");
entryb14=lookup_widget(windowj4,"entryb14");
entryb15=lookup_widget(windowj4,"entryb15");
entryb16=lookup_widget(windowj4,"entryb16");
entryb17=lookup_widget(windowj4,"entryb17");
entryb18=lookup_widget(windowj4,"entryb18");

output= lookup_widget(button,"label1");
entryb11=lookup_widget(button,"entryb11");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(entryb11)));
g_print("%s\n",CIN);
if (verifier_cin(CIN)==0)
{
gtk_label_set_text(GTK_LABEL(output),"ouvrier n'existe pas");
}
/*if (verifier_cin(CIN)==1)
{
  gtk_label_set_text(GTK_LABEL(output),"bbbb");
}*/
else
{
FILE *f2;
f2=fopen("ouvrier.txt","r"); 
if (f2!=NULL)
{while (fscanf(f2,"%s %s %s %s %s %s \n",o.nom,o.prenom,o.cin,o.num_tel,o.mail,o.adresse)!=EOF)
{if (strcmp(o.cin,CIN)==0) 
{ gtk_widget_show(windowj4);
gtk_entry_set_text(GTK_ENTRY(entryb13),o.nom) ;
gtk_entry_set_text(GTK_ENTRY(entryb14),o.prenom) ;
gtk_entry_set_text(GTK_ENTRY(entryb15),o.cin) ;
gtk_entry_set_text(GTK_ENTRY(entryb16),o.num_tel) ;
gtk_entry_set_text(GTK_ENTRY(entryb17),o.mail) ;
gtk_entry_set_text(GTK_ENTRY(entryb18),o.adresse) ;


break ;}}
}
fclose(f2);
}	
}



void
on_buttonb10_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *output;
ouvrier o;
char ref[20];
input=lookup_widget(button,"entryb12");
output=lookup_widget(button,"labelb29");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(ref,o.cin)==0)
gtk_label_set_text(GTK_LABEL(output),"ouvrier n'existe pas");
else
{
supprimer_ouvrier(ref);
gtk_label_set_text(GTK_LABEL(output),"suppression avec succée");
}

}


void
on_buttonb11_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj3;

GtkWidget *treeview;
windowj3=lookup_widget(button,"windowj3");
treeview=lookup_widget(windowj3,"treeviewb2");
afficher_ouvrier(treeview);

}


void
on_buttonback5_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj1, *windowj5;
windowj1=lookup_widget(button,"windowj1");
gtk_widget_hide(windowj1);
windowj5 = create_windowj5();
gtk_widget_show (windowj5);

}


void
on_buttonb14_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{ouvrier o;
GtkWidget *entryb13,*entryb14,*entryb15,*entryb16,*entryb17,*entryb18;
GtkWidget *output;
entryb13=lookup_widget(button,"entryb13");
entryb14=lookup_widget(button,"entryb14");
entryb15=lookup_widget(button,"entryb15");
entryb16=lookup_widget(button,"entryb16");
entryb17=lookup_widget(button,"entryb17");
entryb18=lookup_widget(button,"entryb18");

output=lookup_widget(button,"label2");
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(entryb13)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(entryb14)));
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(entryb15)));
strcpy(o.num_tel,gtk_entry_get_text(GTK_ENTRY(entryb16)));
strcpy(o.mail,gtk_entry_get_text(GTK_ENTRY(entryb17)));
strcpy(o.adresse,gtk_entry_get_text(GTK_ENTRY(entryb18)));

modifier_ouvrier(o);
gtk_label_set_text(GTK_LABEL(output),"modifié avec succés") ;

}


void
on_buttonb963_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowj2, *windowj4;
windowj4=lookup_widget(button,"windowj4");
gtk_widget_hide(windowj4);
windowj2 = create_windowj2();
gtk_widget_show (windowj2);
}


void
on_buttonb555_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj5;

GtkWidget *treeview;
windowj5=lookup_widget(button,"windowj5");
treeview=lookup_widget(windowj5,"treeviewb3");
afficher_absence(treeview);

}


void
on_buttonback4_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj1, *windowj5;
windowj5=lookup_widget(button,"windowj5");
gtk_widget_hide(windowj5);
windowj1 = create_windowj1();
gtk_widget_show (windowj1);

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj5, *windowj6,*cin1,*jour1,*mois1,*annee1;

ouvrier o;

cin1=lookup_widget(button,"entry20");
jour1=lookup_widget(button,"comboboxentry1");
mois1=lookup_widget(button,"comboboxentry2");
annee1=lookup_widget(button,"comboboxentry3");
strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));
gchar *anne=gtk_combo_box_get_active_text(annee1);
gchar *mois=gtk_combo_box_get_active_text(mois1);
gchar *jour=gtk_combo_box_get_active_text(jour1);
strcpy(o.Absence.jour,jour);
strcpy(o.Absence.mois,mois);
strcpy(o.Absence.annee,anne);

/*
    anne1 = lookup_widget(button, "comboboxentryAnne") ;
    gchar *anne=gtk_combo_box_get_active_text(anne1);
    strcpy(c.d.anne,anne);
*/






enregristrer_absence (o);



windowj6=lookup_widget(button,"windowj6");
gtk_widget_hide(windowj6);
windowj5 = create_windowj5();
gtk_widget_show (windowj5);

}


void
on_buttonb33_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj5, *windowj6,*cin1,*mois1,*annee1;
char cinm[40];
char meilleur5[50];
ouvrier o;
  // cin1=lookup_widget(button,"entry21");
mois1=lookup_widget(button,"comboboxentry5");
annee1=lookup_widget(button,"comboboxentry4");

//strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(cin1)));

gchar *mois=gtk_combo_box_get_active_text(mois1);
gchar *annee=gtk_combo_box_get_active_text(annee1);
strcpy(o.Absence.mois,mois);
strcpy(o.Absence.annee,annee);

snprintf(meilleur5, sizeof(meilleur5), "%d", meilleur(o.cin,o.Absence.mois,o.Absence.annee));
strcpy(cinm,meilleur5);

GtkWidget *treeview;

treeview=lookup_widget(button,"treeviewb4");
afficherm(treeview,cinm);


}


void
on_Gestion_des_ouvriersj2_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj0 ;
 GtkWidget *windowj1;
windowj0=lookup_widget(button,"windowj0");
gtk_widget_hide(windowj0);
windowj1 = create_windowj1();
gtk_widget_show (windowj1);

}


void
on_Gestion_de_calendrierj4_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Gestion_de_clientsj5_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Gestion_de_troupeauxj6_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Gestion_des_capteursj3_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Gestion_des_equipementj1_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_bouttonretourj5_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj0 ;
 GtkWidget *windowj11;


windowj11 = create_windowj11();
gtk_widget_show (windowj11);

windowj0=lookup_widget(button,"windowj0");
gtk_widget_hide(windowj0);


}


void
on_button10jinscr_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11ja_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowj11 ;
 GtkWidget *windowj0;


windowj0 = create_windowj0();
gtk_widget_show (windowj0);

windowj11=lookup_widget(button,"windowj11");
gtk_widget_hide(windowj11);


}

