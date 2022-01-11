#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#define WAIT sleep(2)
#define N 1000
#define FFLUSH fflush(stdin)


static int i=0,nb_art,nb_cat; int Nb_vente,total_A;
static int choice;
FILE *USER,*ADMINS,*PRODUIT,*CATEGORIE;


//Structure de l'admin
typedef struct
{
    char nom[25];
    char prenom[25];
    int id_admin;
    char mdp_admin[30];
    char login_admin[50];
    int tel;
}ADMIN;

// Structure de l'admin
typedef struct 
{
    char nom[25];
    char prenom[25];
    char login[100];
    int tel;
    int id;
}users;


// structure des catégorie
 typedef struct 
{
    char Cat_name[25];
    int id;
    char libelle[100];
}categorie;


//structure des articles
typedef struct 
{
    char designation[100];
    int prix;
    int qte;
    char code[7];
    categorie Cat;
}article;

void ajout_admin(ADMIN *tab, int n);
void ajout_user(users *tab,int n);
void Menu();
void Menu2();
void Affichage_user(users *tab,int n);
void ajout_cat(categorie *tab2, int n);
void ajout_produit(article *tab3, int n);
void list_produit(article *tab3,int n);
void list_cat(categorie *tab2,int n);
void vente(article *ART,int n);




int main(int argc, char const *argv[])
{
    ADMIN admin[N]; users user[N];
    int choix;
    USER=fopen("user.bin","wb+rb");
    ADMINS =fopen("admin.bin","wb+rb");
    PRODUIT =fopen("prouits.bin","wb+rb");
    CATEGORIE =fopen("categorie.bin","wb+rb");

    printf("\n********** Bienvenu sur GOOR FALL SHOP *********\n\n");
    printf("********** Connexion *********\n\n");
    printf("1. Se connecter en tant qu'admin\n2. Se connecter en tant qu'utilisateur\n\n");
    printf("Votre choix : "); scanf("%d",&choix);
    printf("\n");
    switch (choix)
    {
    case 1:
        WAIT;
        ajout_admin(admin, N);
        break;
    
    default:
        break;
    }
    return 0;
}



void Menu(){
        printf ("||--------------------------------------||\n") ;
        printf ("||--------------------------------------||\n") ;
        printf ("||---     WELCOME TO THE MAI MENU    ---||\n") ;  
        printf ("||--------------------------------------||\n") ;     
        printf ("||--------------------------------------||\n") ;
        printf ("||------     Choose an  action     -----||\n") ;
        printf ("||--------------------------------------||\n") ;
        printf ("||   1. Display the list of users       ||\n") ;
        printf ("||   2. Add Users                       ||\n") ;
        printf ("||   3. Add categories                  ||\n") ;
        printf ("||   4. Add products                    ||\n") ;
        printf ("||   5. Make a sale                     ||\n") ;
        printf ("||   6. Print the sales report          ||\n") ;
        printf ("||   7. List the products               ||\n") ;
        printf ("||   8. List the categories             ||\n") ;
        printf ("||   9. Supprimer un produit            ||\n") ;
        printf ("||   10. Modifer un  produit            ||\n") ;
        printf ("||   10. Exit the application           ||\n") ;
        printf ("||--------------------------------------||\n") ;
        printf ("||--------------------------------------||\n\n");            
}


void ajout_admin(ADMIN *tab, int n)
{

     FILE *fichier; char login[25]; char pass[20];
      int i;
    int max = 999;  int min = 600;
    
    ADMIN admin; users user[N]; categorie cat[100]; article a[100];
    //id Auto de façon aleatoire
    srand(time(NULL));
    admin.id_admin = (rand() % (max - min + 1)) + min;
    

    printf("********** Creation compte Admin **********\n\n");
    
    // information conçernant l'admin
    printf("id : GFS%d\n",admin.id_admin); 
    fflush(stdin);
    printf("Nom(s) : ");
    gets(admin.nom);
    printf("Prénom(s) : ");
    gets(admin.prenom);
    printf("Tel : ");
    scanf("%d",&admin.tel);
    fflush(stdin);
    printf("Login : ");
    gets(admin.login_admin);
    //char *pointeur_login = admin.login_admin;
    printf("Mot de passe : ");
    gets(admin.mdp_admin);
    fwrite(&admin,sizeof(ADMIN),1,ADMINS);
    printf("\n\n\n");

    WAIT;

    //insertion des infos de l'admin dans le fichier USERS
    
    
    
    printf("********** CREATION DE COMPTE VALIDEE **********\n\n");


    // CONNEXION DE L'ADMIN
    printf("********** CONNEXION **********\n\n");

    printf("Login : "); scanf("%s",login);

        // Verification si le login est identique au login engeritré
        while (strcmp(login,admin.login_admin)!=0)
        {
            printf("\nLogin Incorrect Reesaayer!!!! \n");
            printf("Login : "); scanf("%s",login);
        }

    printf("Mot de passe : ");  scanf("%s",pass);

        // Verification si le mdp est identique au login engeritré
        while (strcmp(pass,admin.mdp_admin)!=0)
        {
            printf("Mot de passe incorrect !!!!\n");
            printf("mot de passe : ");  scanf("%s",pass);
        }
        WAIT;

    printf("\n\n*********** CONNEXION REUSSITE ***********\n\n");
  
    
    while (choice != 9)
    {
        Menu();
        printf("Votre Choix : ");   scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            WAIT;
            Affichage_user(user, N);
            break; 

        case 2:
            WAIT;
            ajout_user(user, N);
            break; 
        case 3:
            WAIT;
            ajout_cat(cat, N);
            break;
        case 4:
            WAIT;
            ajout_produit(a , N);
            break;  
        case 5:
            printf("Effectuer une vente\n");
            break;
        case 6:
            printf("Imprimer l'état de vente\n");
            break;
        case 7:
            break;
            WAIT;
            list_produit(a, N);
        case 8:
            WAIT;
            list_cat(cat,N);
            break;    
        default:
            
            break;
        }
    }
}



void ajout_user(users *tab,int n)
{
    users T;
    int taille,i,j,choix,nb,nb_cat;
    int max = 500;  int min = 100;  char LL[25]; char pass[25];
    char mdp[]="passer123";
    srand(time(NULL));

    
    T.id = (rand() % (max - min + 1)) + min;

    printf("\n********** Ajout d'Utilisateur **********\n");

    printf("\nUtilisateur N°%d\n",i);
        //gere l'id de façon auto
    printf("Id : GFS%d \n",T.id);
    
    fflush(stdin); 
    printf("Login : ");
    scanf("%s",T.login);
    taille = strlen(T.login);

    //controle de la taille du login à 5 caractère alphabétiques 
    while (taille !=5 )
    {       
        // && !(isalpha(T.login[i]) || T.login[i] == '-' || T.login == ' ')

        printf("\nLogin Error !!!\n");
        printf("Assurez-vous que votre login comporte cinq (5) caractères alphabétiques !!!!\n\n");
        printf("Login : ");
        scanf("%s",T.login);
        taille = strlen(T.login);
        //Mettre le login en majuscule
        for (i = 0; i <= nb; i++)
        {
            for (j = 0; T.login[j]; j++) 
            {
                if((T.login[j] >= 'a') && (T.login[j] <= 'z')) 
                {
                    T.login[j] = T.login[j] - 'a' + 'A';
                }
            }
        }           
    }   
    
    printf("Nom :");    scanf("%s",T.nom);
    
    fflush(stdin);
    printf("Prénom : ");    scanf("%s",T.prenom);
    
    fflush(stdin);
    printf("Tel :");    scanf("%d",&T.tel);
    
    fflush(stdin);
    printf("Mot de passe attribué pae défaut : %s\n\n",mdp);
    fwrite(&T,sizeof(users),1,USER);
    WAIT;
    
    printf("\n********** Inscription Terminée **********\n\n");
    printf("********** Connexion en tant que User **********\n");

    printf("Login : ");     scanf("%s",LL);

    while (strcmp(LL,T.login)!=0)
    {
        printf("\nLogin Incorrect Reesaayer!!!! \n");
        printf("Login : "); scanf("%s",LL);
    }

    printf("Mot de passe : ");  scanf("%s",pass);

    while (strcmp(pass,mdp)!=0)
    {
        printf("\nMot de passe Incorrect Reesaayer!!!! \n");
        printf("Mot de passe : "); scanf("%s",pass);
    }
    

    printf("Creation du nouveau mot de passe\n\n");
    printf("Nouveau mot de passe : ");  scanf("%s",pass);
    
    printf("Confirmer mot de passe : ");    scanf("%s",mdp);

    while (strcmp(mdp,pass)!=0)
    {
        printf("\nMot de passe Incorrect Reesaayer!!!! \n");
        printf("Confirmer mot de passe : "); scanf("%s",pass);
    }


    while (choice !=3)
    {
        Menu2();
        printf("Votre choix : ");      scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                if (nb_art==0)
                {
                    printf("Stockage Vide\n");
                }
                
            break;
        case 2:
            
            break;
        default:

            break;
        }
    }
    
    
    tab[i]=T;
    i++;
    WAIT;       
}


void Affichage_user(users *tab,int n)
{
    printf("\n********** Ajout d'Utilisateur **********\n\n");
    WAIT;
    int j = 0;

    while (j<i)
    {
        printf("Id : GFS%d\n",tab[i].id);
        printf("Nom : %s",tab[j].nom);
        printf("Prenom : %s",tab[j].prenom);
        printf("Telephone : %d",tab[j].tel);
        printf("Login : %s",tab[j].login);

        printf("------------------------------------\n\n");
        j++;
    }
    
    WAIT;
}

void ajout_cat(categorie *tab2, int n)
{
    int i;
    categorie cat[100];

    printf("\n********** Ajout de Catégorie(s) **********\n\n");
    printf("Combien de catégorie voulez vous ajouté ?\n");
    printf("Nombre : ");    scanf("%d",&n);
    for ( i = 1; i <= nb_cat; i++)
    {
        printf("Id : %d",cat[i].id+1);
        printf("Designation : ");   scanf("%s",cat[i].Cat_name);
        printf("Libelle : ");   scanf("%s",cat[i].libelle);
        // fwrite(cat,sizeof(categorie),n,CATEGORIE);
    }
    
    WAIT;

    tab2[i]=cat[i];
}


void ajout_produit(article *tab3, int n)
{
    article a[100]; int i,taille; 
    printf("\n********** Ajout de produit(s) **********\n\n");
    printf("Combien de Catégorie ?\n");
    printf("Nombre : ");    scanf("%d",&nb_art);
    for ( i = 1; i <=nb_art; i++)
    {
        printf("Désignation : "); scanf("%s",a[i].designation);
        do
        {
            printf("Prix : ");  scanf("%d",&a[i].prix);
        } while (a[i].prix<=0); 
        printf("Quantité : ");  scanf("%d",&a[i].qte);
        printf("Code : "); scanf("%s",a[i].code);
        taille = strlen(a[i].code);
        while (taille!=7)
        {
            printf("Code Incorrect Reesayer Svp !\n");
            printf("Code : "); scanf("%s",a[i].code);
        }   
        total_A++;       
    }
    
    tab3[i]=a[i];
    WAIT;
}

void list_produit(article *tab3,int n)
{
    for ( i = 1; i <= nb_art; i++)
    {
        printf("Desingnation : %s",tab3[i].designation);
        printf("Prix : %d",tab3[i].prix);
        printf("Quantité : %d",tab3[i].qte);
        printf("Code :  %s",tab3[i].code);
        printf("_________________________\n\n");
    } 
    WAIT;  
}


void list_cat(categorie *tab2,int n)
{
    for ( i = 1; i <= nb_cat; i++)
    {
        printf("Nom : %s",tab2[i].Cat_name);
        printf("Id : %d ",tab2[i].id);
        printf("LIibelle : %s",tab2[i].libelle);
        printf("---------------------------\n\n");
    }
    WAIT;
}

void Menu2(){
    WAIT;
        printf ("||--------------------------------------||\n") ;
        printf ("||--------------------------------------||\n") ;
        printf ("||---     WELCOME TO THE  MENU       ---||\n") ;  
        printf ("||--------------------------------------||\n") ;     
        printf ("||--------------------------------------||\n") ;
        printf ("||------     Choose an  action     -----||\n") ;
        printf ("||--------------------------------------||\n") ;
        printf ("||   1. Imprimer l'etat de vente        ||\n") ;
        printf ("||   2. Acheter une article             ||\n") ;
        printf ("||   3. Menu Principal                  ||\n") ;
        printf ("||--------------------------------------||\n\n"); 

}


// void vente(article *ART,int n)
// {
//     int NC;
//     int j,k;char name_A[25]; char recherche[25]; char found[25];
//     article a[100];

//     printf("Combien d'achat voulez-vous effectué ?\n\n");
//     printf("Nombre : " );   scanf("%d",&NC);

//     for ( i = 1; i <= NC; i++)
//     {
//        j=i;
//        printf("Achat n°%d",++j);
//        printf("Que cherhcez vous ?\n\n");
//        scanf("%s",name_A);
//        for ( k = 0; k < total_A; k++)
//        {
//            fread(a[k].code,sizeof(struct articles),total_A,PRODUIT);
//            strcpy(recherche,a[k].code);
//            found=strcmp(name_A,recherche);
//            if (found!=0)
//            {
//                printf("En rupture de stock\n\n");
//            }
           
//        }
       
//     }
    
// }