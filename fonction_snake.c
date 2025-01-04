#include "fonction_snake.h"



void dessinerPlateau(SDL_Renderer *rendu){
    // for (int i = 0; i < LARGEUR_FENETRE; i+=15)
    // {
    //     for (int j = 0; j < HAUTEUR_FENETRE; j+=15)
    //     {
    //         SDL_Rect carreau={i,j,TAILLE_SERPENT,TAILLE_SERPENT};
    //         SDL_SetRenderDrawColor(rendu,0,154,74,255);
    //         SDL_RenderFillRect(rendu, &carreau);
    //         SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255); // Contour noir
    //         SDL_RenderDrawRect(rendu, &carreau);
    //     }
        
    // }
    SDL_SetRenderDrawColor(rendu,0,154,74,255);
    SDL_RenderClear(rendu);
}

void dessinerPomme(SDL_Renderer *rendu,Pomme *pomme){
    // pomme.x=LARGEUR_FENETRE/2;
    // pomme.y=HAUTEUR_FENETRE/2;
    SDL_SetRenderDrawColor(rendu,255,0,0,255);
    SDL_RenderFillRect(rendu,&(SDL_Rect){pomme->x,pomme->y,TAILLE_SERPENT,TAILLE_SERPENT});

}

void dessinerSerpent(SDL_Renderer *rendu, Serpent *serpent,int tailleSerpent){
    // serpent[0].x=LARGEUR_FENETRE/2;
    // serpent[0].y=HAUTEUR_FENETRE/2;
    // int rayonYeux= RAYON_YEUX;
    // serpent[0].yeux[0].x=LARGEUR_FENETRE/2+10;
    // serpent[0].yeux[0].y=HAUTEUR_FENETRE/2+3;
    // serpent[0].yeux[1].x=LARGEUR_FENETRE/2+10;
    // serpent[0].yeux[1].y=HAUTEUR_FENETRE/2+11;
    for (int i = 0; i < tailleSerpent; i++)
    {
        SDL_SetRenderDrawColor(rendu,255,255,0,255);
        SDL_RenderFillRect(rendu,&(SDL_Rect){serpent[i].x,serpent[i].y,TAILLE_SERPENT,TAILLE_SERPENT});
        SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255); // Noir
        SDL_RenderDrawRect(rendu,&(SDL_Rect){serpent[i].x,serpent[i].y,TAILLE_SERPENT,TAILLE_SERPENT});
    }
    // for(int i=0;i<2;i++){
    //     filledCircleRGBA(rendu,serpent[0].yeux[i].x,serpent[0].yeux[i].y,rayonYeux,255,0,0,255);
    // }
}

void deplacerSerpent(Serpent *serpent,int tailleSerpent,int position){
     if(position==SDLK_UP){
        if(serpent[0].direction_y!=TAILLE_SERPENT){
            serpent[0].direction_x=0;
            serpent[0].direction_y=-TAILLE_SERPENT;
        }
    }
    else if(position==SDLK_DOWN){
        if(serpent[0].direction_y!=-TAILLE_SERPENT){
            serpent[0].direction_x=0;
            serpent[0].direction_y=TAILLE_SERPENT;
        }
    }
    else if(position==SDLK_RIGHT){
        if(serpent[0].direction_x!=-TAILLE_SERPENT){
            serpent[0].direction_x=TAILLE_SERPENT;
            serpent[0].direction_y=0;  
        }      
    }
    else if(position==SDLK_LEFT){
        if(serpent[0].direction_x!=TAILLE_SERPENT){
            serpent[0].direction_x=-TAILLE_SERPENT;
            serpent[0].direction_y=0;
        }
    }
    
}

int collision(Serpent *serpent,int tailleSerpent){
    if(serpent[0].x<0 || serpent[0].x>=LARGEUR_FENETRE || serpent[0].y<0 || serpent[0].y>=HAUTEUR_FENETRE)
        return 1;
    for (int i = 1; i < tailleSerpent; i++)
    {
        if(serpent[0].x==serpent[i].x && serpent[0].y==serpent[i].y)
            return 1;
    }
    return 0;
        
}