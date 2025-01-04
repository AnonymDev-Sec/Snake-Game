#include "fonction_snake.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    TTF_Font *police = TTF_OpenFont("fonts/FreeSerif.ttf",64);

    SDL_Window *fenetre = SDL_CreateWindow("Serpent",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGEUR_FENETRE,HAUTEUR_FENETRE,0);
    SDL_Renderer *rendu = SDL_CreateRenderer(fenetre,-1,SDL_RENDERER_ACCELERATED);
    SDL_Surface *surfaceTexte=TTF_RenderText_Solid(police,"GAME OVER", (SDL_Color){255,0,0});
    // SDL_Surface *surfaceTexteScore=TTF_RenderText_Solid(police,"SCORE: ", (SDL_Color){0,0,0});
    SDL_Texture *textureTexte = SDL_CreateTextureFromSurface(rendu,surfaceTexte);
    // SDL_Texture *textureTexteScore = SDL_CreateTextureFromSurface(rendu,surfaceTexteScore);

    SDL_Event event;
    SDL_bool Quit=0;
    Serpent serpent[LONGUEUR_SERPENT_MAX];
    Pomme pomme;
    pomme.x=(rand()%(LARGEUR_FENETRE/15))*15;
    pomme.y=(rand()%(HAUTEUR_FENETRE/15))*15;
    serpent[0].x=TAILLE_SERPENT;
    serpent[0].y=TAILLE_SERPENT;
    serpent[0].direction_x=TAILLE_SERPENT;
    serpent[0].direction_y=0;
    int tailleSerpent=4;
    int score=0;
    int tempsR=100;

    while (!Quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                Quit=1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_UP:
                        deplacerSerpent(serpent,tailleSerpent,SDLK_UP);
                        // essai=0;
                        break;
                    case SDLK_DOWN:
                        deplacerSerpent(serpent,tailleSerpent,SDLK_DOWN);
                        // essai=0;
                        break;
                    case SDLK_LEFT:
                        deplacerSerpent(serpent,tailleSerpent,SDLK_LEFT);
                        // essai=0;
                        break;
                    case SDLK_RIGHT:
                        deplacerSerpent(serpent,tailleSerpent,SDLK_RIGHT);
                        // essai=0;
                        break;
                    case SDLK_SPACE:
                        // essai=1;
                        break;
                    default:
                        break;
                }            
            default:
                break;
            }
        }
        dessinerPlateau(rendu);
        SDL_SetRenderDrawColor(rendu,255,255,0,255);

        if(!collision(serpent,tailleSerpent)){
            dessinerSerpent(rendu,serpent,tailleSerpent);
            for (int i = tailleSerpent-1; i > 0; i--)
            {
                serpent[i]=serpent[i-1];
            }
            serpent[0].x+=serpent[0].direction_x;
            serpent[0].y+=serpent[0].direction_y;
        }else{
	        Quit=1;    
        }

        if(serpent[0].x==pomme.x && serpent[0].y==pomme.y){
            tailleSerpent++;
            score++;
            pomme.x=(rand()%(LARGEUR_FENETRE/15))*15;
            pomme.y=(rand()%(HAUTEUR_FENETRE/15))*15;
            printf("C'est mangé\n");
            printf("Score:%d\n",score);

        }
        dessinerPomme(rendu,&pomme);
        if(tailleSerpent>=14 && tailleSerpent<=34)
            tempsR=50;
        else if(tailleSerpent<14)
            tempsR=100;
        else
            tempsR=25;    
        SDL_RenderPresent(rendu);
        SDL_Delay(tempsR);
    }
    // printf("X:%d\nY:%d\n",serpent[0].x,serpent[0].y);
    // printf("X:%d\nY:%d\n",serpent[1].x,serpent[1].y);
    // printf("X:%d\nY:%d\n",serpent[2].x,serpent[2].y);
    // printf("X:%d\nY:%d\n",serpent[3].x,serpent[3].y);
    if(Quit==1){
        dessinerPlateau(rendu);
        dessinerSerpent(rendu,serpent,tailleSerpent);
        SDL_Rect texte={LARGEUR_FENETRE/2-surfaceTexte->w/2,HAUTEUR_FENETRE/2-surfaceTexte->h/2,surfaceTexte->w,surfaceTexte->h};
	    // SDL_Rect texteScore={LARGEUR_FENETRE/2-surfaceTexteScore->w/2,(HAUTEUR_FENETRE/2-surfaceTexteScore->h/2)+50,surfaceTexteScore->w,surfaceTexteScore->h};
        SDL_RenderCopy(rendu,textureTexte,NULL,&texte);
	    // SDL_RenderCopy(rendu,textureTexteScore,NULL,&texteScore);
        SDL_RenderPresent(rendu);
        SDL_Delay(3000);
    }
    TTF_CloseFont(police);
    SDL_DestroyTexture(textureTexte);
    // SDL_DestroyTexture(textureTexteScore);
    SDL_FreeSurface(surfaceTexte);
    // SDL_FreeSurface(surfaceTexteScore);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
