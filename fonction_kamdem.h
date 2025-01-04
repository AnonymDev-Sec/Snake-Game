#if !defined(FONCTION_KAMDEM)
#define FONCTION_KAMDEM


#define LARGEUR_FENETRE 900
#define HAUTEUR_FENETRE 750
#define TAILLE_SERPENT 15
#define LONGUEUR_SERPENT_MAX 100
#define RAYON_YEUX 1


#include<SDL2/SDL.h>
#include<SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int x;
    int y;
} Yeux;

typedef struct {
    int taille;
    int x;
    int y;
    int direction_x;
    int direction_y;
    Yeux yeux[2];
    SDL_Color couleur;
}Serpent;

typedef struct{
    int x;
    int y;
}Pomme;



void dessinerPlateau(SDL_Renderer *);
void dessinerSerpent(SDL_Renderer *,Serpent *serpent,int);
void deplacerSerpent(Serpent *serpent,int ,int );
void dessinerPomme(SDL_Renderer *rendu,Pomme *pomme);
int collision(Serpent *,int tailleSerpent);
//Fonction pour les niveaux 
//void niveauSup(); À vénir


#endif // FONCTION_KAMDEM
