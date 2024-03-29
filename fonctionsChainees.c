/* petit script personel pour stocker avec des list chainees
source: https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/19733-stockez-les-donnees-avec-les-listes-chainees
date : lun 12 fevr 2024 || update 28 fev 2024 */

#include<stdio.h>
#include<stdlib.h>


/*cration d'une struct de la liste d'Elements*/
typedef struct Element Element;
struct Element/*creation d'une structure Element contenant une donnée(s) et un pouetur vers l'adresse de l'element suivant*/
{
    int nombre;/* Donée */
    Element *suivant;/* pointeur de l'ement suivant */
};


/*creation de la struct de controle */
typedef struct Liste Liste;
struct Liste
{
    Element *premier;/*cette struc contien le pointeur du premier element pour savoir ou commence la liste */
};


/* ici on retrouve les fonctions qui permete de manipuler nos structure Element*/

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));/* on alloue dynamiquement la taille des donne de la structure Liste */
    Element *element = malloc(sizeof(*element));/* on alloue dynamiquement la taille des donne de la structure Element */
    
    if(liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);/* on verifie si les allocution dynamique on fonctionner en cas d'ERREUR on execute exit()*/
    }
    /* on definni les valeur de notre premier element */
    element->nombre = 0; /* la donée nombre est mise a 0 pars defaut*/
    element->suivant = NULL;/* le ptr suivant pointe vers NULL car il y un seul element de la chaine donc aussi le dernier qui indique la fin avec la valeur NULL*/
    liste->premier = element;
    
    return liste;
}

/* ici on ajout un elemnt au DEBUT de la liste chainee en adaptant le pointeur premier & suivant du nouveaux element*/

void insertion(Liste *liste, int nvNombre)
{
    /* creation d'un nouveaux element */
    Element *nouveau = malloc(sizeof(*nouveau)); /* on alloue la memoire pour le nouveau element de la structure*/
    
    if(liste == NULL || nouveau == NULL )
    {
        exit(EXIT_FAILURE);/* on regarde si l'allocution a reussi */
    }
    nouveau->nombre = nvNombre;
   
    /* Insertion de l'element au debut de la liste */
    nouveau->suivant = liste->premier;
    /* on place le nouveaux element en premier dans la liste || OC source : aire pointer notre nouvel élément vers son futur successeur, qui est l'actuel premier élément de la liste.*/
    liste->premier = nouveau;/* !!! on ajoute l'adresse de l'element ??? a verifier || OC cource : Faire pointer le pointeur premier vers notre nouvel élément.*/
}

/* fonction pour suprimer un Element de la chaine */
void suppression(Liste *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);/* on teste si la liste est vide on arrete la fonction */
    }
    
    if(liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;/* on sauvegarde l'adresse de element a supprimer dans le pointeur aSupprimer*/
        liste->premier = liste->premier->suivant;/* on adapte ensuite le pointeur premier vers le nouveau premier element, actelment en seconde position de la liste chainee */
        free(aSupprimer);/* on libere la memoire allouer */
    }
}

/* pour afficher les liste il sufi d'afficher un element pui de soter d'un element apres l'autre */
void afficherListe(Liste *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);/* si la liste est vide on arrete la fonction */
    }
    
    Element *actuel = liste->premier;/* cration d'un ptr de type Element qui prend l'adresse du premier element dans la liste */
    
    while(actuel != NULL)
    {
        printf("%d-> ", actuel->nombre);
        actuel = actuel->suivant;/* On se sert du pointeur suivant pour passer à l'élément qui suit à chaque fois.On se sert du pointeur suivant pour passer à l'élément qui suit à chaque fois.*/
    }
    printf("NULL \n");
}
int main()
{
    Liste *maListe = initialisation();

        insertion(maListe, 4);
        insertion(maListe, 8);
        insertion(maListe, 15);
        suppression(maListe);

        afficherListe(maListe);

        return 0;
}
