#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <MMSystem.h>
#define INI 6//escolhe quantos inimigos tu quer ai
// boa sorte!!!

void hidecursor()
{

   system("color 3f");
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

char mapa[20][40] =
                     {{"piiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiip"},
                      {"p                                      p"},
                      {"p       ooooo             ooooo        p"},
                      {"p  o o           opopo            o o  p"},
                      {"p  o o           opopo            o o  p"},
                      {"p       ooooo    opopo    ooooo        p"},
                      {"p  o o           opopo            o o  p"},
                      {"p  o o           opopo            o o  p"},
                      {"p                o   o                 p"},
                      {"p     ooooooooo         ooooooooo      p"},
                      {"p     iiiiiiiii         iiiiiiiii      p"},
                      {"p                                      p"},
                      {"p            iiiiiiiiiiiiii            p"},
                      {"p  o o                            o o  p"},
                      {"p  o o    iooo            iooo    o o  p"},
                      {"p  o o    iooo            iooo    o o  p"},
                      {"p  o o    iooo     *      iooo    o o  p"},
                      {"p  o o            ooo             o o  p"},
                      {"p                 olo                  p"},
                      {"iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"}};
char game[15][25]={{"ppppppppppppppppppppppppp"},
                   {"pp    pp   pp ppp p    pp"},
                   {"p ppppp ppp p  p  p ppppp"},
                   {"p pp  p ppp p p p p   ppp"},
                   {"p ppp p     p ppp p ppppp"},
                   {"p ppp p ppp p ppp p ppppp"},
                   {"pp   pp ppp p ppp p    pp"},
                   {"ppppppppppppppppppppppppp"},
                   {"pp   pp ppp p    pp   ppp"},
                   {"p ppp p ppp p ppppp pp pp"},
                   {"p ppp p ppp p   ppp pp pp"},
                   {"p ppp p ppp p ppppp   ppp"},
                   {"p ppp pp p pp ppppp pp pp"},
                   {"pp   pppp ppp    pp ppp p"},
                   {"ppppppppppppppppppppppppp"}};
char tank[4][18]={{"..../yyyyyy|===[] "},
                  {".../yyyyyyyyyy|   "},
                  {"/yyyyyyyyyyyyyyyy|"},
                  {"(@) (@) (@) (@) / "}};

char menu[13][98]={{"  pppppo pppppppo     pppppo ppo   ppopppppppopppo   ppoppppppppoppo   ppoppppppo  pppppo pppppppo"},
                 {" ppirrppoppirrrry    ppirrppoppu   ppuppirrrryppppo  pputrrppirryppu   ppuppirrppoppirrppoppirrrry"},
                 {" pppppppupppppppo    pppppppuppu   ppupppppo  ppippo ppu   ppu   ppu   ppuppppppiypppppppupppppppo"},
                 {" ppirrpputrrrrppu    ppirrpputppo ppiyppirry  pputppoppu   ppu   ppu   ppuppirrppoppirrpputrrrrppu"},
                 {" ppu  ppupppppppu    ppu  ppu tppppiy pppppppoppu tppppu   ppu   tppppppiyppu  ppuppu  ppupppppppu"},
                 {" try  trytrrrrrry    try  try  trrry  trrrrrrytry  trrry   try    trrrrry try  trytry  trytrrrrrry"},
                 {"                                                                                                  "},
                 {"                ppppppo pppppppo         ppo ppppppo ppppppo  ppppppo pppppppo                    "},
                 {"                ppirrppoppirrrry         ppuppirrrppoppirrppoppirrrry ppirrrry                    "},
                 {"                ppu  ppupppppo           ppuppu   ppuppppppiyppu  pppopppppo                      "},
                 {"                ppu  ppuppirry      pp   ppuppu   ppuppirrppoppu   ppuppirry                      "},
                 {"                ppppppiypppppppo    tpppppiytppppppiyppu  pputppppppiypppppppo                    "},
                 {"                trrrrry trrrrrry     trrrry  trrrrry try  try trrrrry trrrrrry                    "}};


struct tposicao{
    int x, y;
    int sentido;
    int ini_morto, ini_tiro;
};
int posx, posy;
struct tposicao inimigos[INI];
struct tposicao tiro_inimigo[INI];
struct tposicao tiro;
int tem_tiro = 0;
int morto = 0;
int ponto=0, matoutudo;



void gotoxy(int x, int y){
    COORD c;
    c.X = x -1;
    c.Y = y -1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void moldura(int ci, int cf, int li, int lf){
    int l,c;
    for (c = ci + 1; c <= cf - 1; c++){
            gotoxy(c,li);printf("%c",223);
            gotoxy(c,lf);printf("%c",223);
    }

    for (l = li + 1; l <= lf - 1; l++){
        gotoxy(ci,l);printf("%c",219);
        gotoxy(cf,l);printf("%c",219);

    }

    gotoxy(ci,li);printf("%c",220);
    gotoxy(ci,lf);printf("%c",223);
    gotoxy(cf,li);printf("%c",219);
    gotoxy(cf,lf);printf("%c",223);
}
void scorebar (int ponto){
int l,c;
for (l=0;l<4;l++){
    for(c=0;c<18;c++){
        gotoxy(50+c,20+l);
//        printf ("%d", ponto);
        switch(tank[l][c]){
        case'y' : printf("%c",178  );break;
        default:printf("%c",tank[l][c]);

        };



}}
//char scorebar [1][5]={{"score"}};
//char barra [1][5]={{"00000"}};
  //  for(c=ci;c<=cf;c++){
//gotoxy(100,16);printf("%c",game);
               // gotoxy(105,18);printf("%06d",c);
//textcolor(BLUE+BLINK);
                gotoxy(56,12);printf("SCORE!");
                gotoxy(56,14);printf("%06d",ponto);

  }
void desenhamapa(){
int l,c;

moldura(49,68, 10, 29);

scorebar (ponto);
for (l=0;l<20;l++){
    for(c=0;c<40;c++){
        gotoxy(10+c,10+l);
        switch(mapa[l][c]){
        case'*' : printf("%c",190  );break;
        case'p' : printf("%c",219  );break;
        case'I' : printf("%c",184  );break;
        case'-' : printf("%c",207  );break;
        case'i' : printf("%c",223  );break;
        case'o' : printf("%c",177  );break;
        case'l' :printf("%c",245  );break;
        default:printf("%c",mapa[l][c]);

        };



}}}
void gameover(){
int l,c;
//moldura(91,110, 15, 34);
//scorebar (c);
for (l=0;l<15;l++){
    for(c=0;c<25;c++){
        gotoxy(40+c,10+l);
        switch(game[l][c]){
            case'p' : printf("%c",219);break;
            default:printf("%c",game[l][c]);
        };
    }
}}
void menu1(){
int l,c;
//moldura(91,110, 15, 34);
//scorebar (c);
for (l=0;l<13;l++){
    for(c=0;c<98;c++){
        gotoxy(10+c,10+l);
        switch(menu[l][c]){
            case'p' : printf("%c",219);break;
            case'o' : printf("%c",187);break;
            case'i' : printf("%c",201);break;
            case'u' : printf("%c",186);break;
            case'y' : printf("%c",188);break;
            case't' : printf("%c",200);break;
            case'r' : printf("%c",205);break;
            default:printf("%c",menu[l][c]);
        };
    }
     gotoxy(55,25);printf("Aperte Espaco");
}}

void movimentaperso(int tecla){
    mapa[posx][posy] = ' ';
    if(tecla == 126){
        morto=1;
    }
    if(tecla == 80){
        if(mapa[posx+1][posy] == ' '){
            posx++;
        }
    }else if(tecla == 72){
        if(mapa[posx-1][posy] == ' '){
            posx--;
        }
    }else if(tecla == 77){
        if(mapa[posx][posy+1] == ' '){
            posy++;
        }
    }else if(tecla == 75){
        if(mapa[posx][posy-1] == ' '){
            posy--;
        }
    }
    if(tem_tiro == 0){
        if(tecla == 115){
            tiro.x = posx + 1;
            Beep(1000,5);
            tiro.y = posy;
           if(mapa[tiro.x][tiro.y]==' '){
                tem_tiro = 1;
                tiro.sentido = 0;
                mapa[tiro.x][tiro.y] = '-';}
        }else if(tecla == 119){
            tiro.x = posx - 1;
            Beep(1000,5);
            tiro.y = posy;
           if(mapa[tiro.x][tiro.y]==' '){
                tem_tiro = 1;
                tiro.sentido = 1;
                mapa[tiro.x][tiro.y] = '-';}
        }else if(tecla == 100){
            tiro.x = posx;
            Beep(1000,5);
            tiro.y = posy+1;
           if(mapa[tiro.x][tiro.y]==' '){
                tem_tiro = 1;
                tiro.sentido = 2;
                mapa[tiro.x][tiro.y] = '-';}
        }else if(tecla == 97){
            tiro.x = posx ;
            Beep(1000,5);
            tiro.y = posy-1;
           if(mapa[tiro.x][tiro.y]==' '){
                tem_tiro = 1;
                tiro.sentido = 3;
                mapa[tiro.x][tiro.y] = '-';}
        }
    }

    mapa[posx][posy] = '*';
}

void funcao_tiro_ini(int i){
    if(inimigos[i].x == posx && inimigos[i].y < posy && inimigos[i].ini_morto == 0){ // ini a esquerda
        tiro_inimigo[i].sentido = 0; // tiro a direita
        inimigos[i].ini_tiro = 1;
        Beep(1000,5);
        tiro_inimigo[i].x = inimigos[i].x;
        tiro_inimigo[i].y = inimigos[i].y + 1;
        if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'o'){
                inimigos[i].ini_tiro = 0;
                mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
        }else if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'B' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == '*'){
            morto = 1;
        }else{
            mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = '-';
        }

    }else if(inimigos[i].x == posx && inimigos[i].y > posy && inimigos[i].ini_morto == 0){ // ini a direita
        tiro_inimigo[i].sentido = 1; // tiro a esquerda
        inimigos[i].ini_tiro = 1;
        //Beep(1000,5);
        tiro_inimigo[i].x = inimigos[i].x;
        tiro_inimigo[i].y = inimigos[i].y - 1;
        if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'o'){
                inimigos[i].ini_tiro = 0;
                mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
        }else if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'B' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == '*'){
            morto = 1;
        }else{
            mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = '-';
        }

    }else if(inimigos[i].x > posx && inimigos[i].y == posy && inimigos[i].ini_morto == 0){ // ini em cima
        tiro_inimigo[i].sentido = 2; // tiro pra baixo
        inimigos[i].ini_tiro = 1;
        //Beep(1000,5);
        tiro_inimigo[i].x = inimigos[i].x -1;
        tiro_inimigo[i].y = inimigos[i].y;
        if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'o'){
                inimigos[i].ini_tiro = 0;
                mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
        }else if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'B' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == '*'){
            morto = 1;
        }else{
            mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = '-';
        }

    }else if(inimigos[i].x < posx && inimigos[i].y == posy && inimigos[i].ini_morto == 0){ // ini em baixo
        tiro_inimigo[i].sentido = 3; // tiro pra cima
        inimigos[i].ini_tiro = 1;
        //Beep(1000,5);
        tiro_inimigo[i].x = inimigos[i].x +1;
        tiro_inimigo[i].y = inimigos[i].y;
        if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'o'){
                inimigos[i].ini_tiro = 0;
                mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
        }else if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'B' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == '*'){
            morto = 1;
        }else{
            mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = '-';
        }
    }
}

void movimentainimigo(){
    int chute, contaMorto=0;
    for(int i=0; i<INI; i++){
            if(inimigos[i].ini_tiro == 0){
            funcao_tiro_ini(i);
        }
        if(inimigos[i].ini_morto == 0){
//            gotoxy (01,01); printf ("[%d - %d, %d]", i, inimigos[i].x, inimigos[i].y);
            mapa[inimigos[i].x][inimigos[i].y] = ' ';
            chute = rand()%4;
            switch(chute){
                case 0:
                    if(mapa[inimigos[i].x-1][inimigos[i].y] == ' '){
                        inimigos[i].x--;
                    }else if(mapa[inimigos[i].x-1][inimigos[i].y] == '*'){
                        morto=1;
                    }
                break;
                case 1:
                    if(mapa[inimigos[i].x][inimigos[i].y+1] == ' '){
                        inimigos[i].y++;
                    }else if(mapa[inimigos[i].x][inimigos[i].y+1] == '*'){
                        morto=1;
                    }
                break;
                case 2:
                    if(mapa[inimigos[i].x+1][inimigos[i].y] == ' '){
                        inimigos[i].x++;
                    }else if(mapa[inimigos[i].x+1][inimigos[i].y] == '*'){
                        morto=1;
                    }
                break;
                case 3:
                    if(mapa[inimigos[i].x][inimigos[i].y-1] == ' '){
                        inimigos[i].y--;
                    }else if(mapa[inimigos[i].x][inimigos[i].y-1] == '*'){
                        morto=1;
                    }
                break;
            }
//            gotoxy (01,02); printf ("[%d - %d, %d]", i, inimigos[i].x, inimigos[i].y);
//            getch();
            mapa[inimigos[i].x][inimigos[i].y] = 'I';
        }else{
            contaMorto++;
        }
        if(contaMorto == INI){
           // printf("¯\_(ツ)_/¯");
            matoutudo = 1;
        }
    }
}

void movimentatiro_inimigo(int i){

    mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
    switch(tiro_inimigo[i].sentido){
        case 0:
            if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y+1] == ' ' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y+1] == '*' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y+1] == 'o' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y+1] == 'l'){
                tiro_inimigo[i].y++; break; //vai atirar para direita
            }else{
                inimigos[i].ini_tiro = 0;
            }
        case 1:
            if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y-1] == ' ' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y-1] == '*' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y-1] == 'o' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y-1] == 'l'){
                tiro_inimigo[i].y--; break; //vai tirar para esquerda
            }else{
                inimigos[i].ini_tiro = 0;
            }
        case 2:
            if(mapa[tiro_inimigo[i].x-1][tiro_inimigo[i].y] == ' ' || mapa[tiro_inimigo[i].x-1][tiro_inimigo[i].y] == '*' || mapa[tiro_inimigo[i].x-1][tiro_inimigo[i].y] == 'o' || mapa[tiro_inimigo[i].x-1][tiro_inimigo[i].y] == 'l'){
                tiro_inimigo[i].x--; break; //vai tirar para baixo
            }else{
                inimigos[i].ini_tiro = 0;
            }
        case 3:
            if(mapa[tiro_inimigo[i].x+1][tiro_inimigo[i].y] == ' ' || mapa[tiro_inimigo[i].x+1][tiro_inimigo[i].y] == '*' || mapa[tiro_inimigo[i].x+1][tiro_inimigo[i].y] == 'o' || mapa[tiro_inimigo[i].x+1][tiro_inimigo[i].y] == 'l'){
                tiro_inimigo[i].x++; break; //atira para cima
            }else{
                inimigos[i].ini_tiro = 0;
            }
    }
    if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == '*' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'l'){
        printf("mato o totem mo burro tu");
        morto=1;
    }else if(mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'o' || mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] == 'I'){
        inimigos[i].ini_tiro = 0;
    }
    if(inimigos[i].ini_tiro == 0){
        mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = ' ';
    }else{
        mapa[tiro_inimigo[i].x][tiro_inimigo[i].y] = '-';
    }

}


void movimentatiro(){
    mapa[tiro.x][tiro.y] = ' ';
    switch(tiro.sentido){
        case 0:
             if(mapa[tiro.x+1][tiro.y] == ' ' || mapa[tiro.x+1][tiro.y] == '*' || mapa[tiro.x+1][tiro.y] == 'o' || mapa[tiro.x+1][tiro.y] == 'I'|| mapa[tiro.x+1][tiro.y] == 'l'){
                tiro.x++; break; //tira para baixo
            }else{
                tem_tiro = 0;
            }
        case 1:
            if(mapa[tiro.x-1][tiro.y] == ' ' || mapa[tiro.x-1][tiro.y] == '*' || mapa[tiro.x-1][tiro.y] == 'o' || mapa[tiro.x-1][tiro.y] == 'I'|| mapa[tiro.x-1][tiro.y] == 'l'){
                tiro.x--; break; //tira para cima
            }else{
                tem_tiro = 0;
            }
        case 2:
            if(mapa[tiro.x][tiro.y+1] == ' ' || mapa[tiro.x][tiro.y+1] == '*' || mapa[tiro.x][tiro.y+1] == 'o' || mapa[tiro.x][tiro.y+1] == 'I'|| mapa[tiro.x][tiro.y+1] == 'l'){
                tiro.y++; break; //tira para direita
            }else{
                tem_tiro = 0;
            }
        case 3:
            if(mapa[tiro.x][tiro.y-1] == ' ' || mapa[tiro.x][tiro.y-1] == '*' || mapa[tiro.x][tiro.y-1] == 'o' || mapa[tiro.x][tiro.y-1] == 'I'|| mapa[tiro.x][tiro.y-1] == 'l'){
                tiro.y--; break; //tira para esquerda
            }else{
                tem_tiro = 0;
            }
    }
    if(mapa[tiro.x][tiro.y] == 'I'){
        for(int i=0; i<INI; i++){
            if(inimigos[i].x == tiro.x && inimigos[i].y == tiro.y){
                printf("   Matou um!!!");
                inimigos[i].ini_morto = 1;
                ponto=ponto+50;
                //scorebar(ponto);

            }
        }
        tem_tiro = 0;
    }else if(mapa[tiro.x][tiro.y] == '*'){
        printf("    vc se sauto suicidou-se a si mesmo");
        morto=1;
    }else if(mapa[tiro.x][tiro.y] == 'o'){
        tem_tiro = 0;
    }else if(mapa[tiro.x][tiro.y] == 'p'){
        tem_tiro = 0;
    }else if(mapa[tiro.x][tiro.y] == 'i'){
        tem_tiro = 0;
    }else if(mapa[tiro.x][tiro.y] == 'l'){
        tem_tiro = 0;
        morto =1;
        }
    if(tem_tiro == 0){
        mapa[tiro.x][tiro.y] = ' ';
    }else{
        mapa[tiro.x][tiro.y] = '-';
    }

}

main(){
    hidecursor();
    PlaySound(TEXT("jorge.wav"), NULL, SND_LOOP | SND_ASYNC);
    int retarda=0;
    int retardatiro=0, retarda_tiro_ini = 0;
    int ini;
    posx = 16;
    posy = 19;
    int menu=0;
    char tecla;
    int chutex, chutey;
    srand(time(NULL));
    ponto = 0;
    do{
        menu1();
        tecla = getch();
    }while(tecla!=32);

    system("cls");
    do{

    for(ini=0;ini<7; ini++){
      do{
    chutex = rand()%10;
    chutey = rand()%40;

    if (mapa[chutex][chutey] == ' '){
       inimigos[ini].x=chutex;
       inimigos[ini].y=chutey;
       inimigos[ini].ini_morto = 0;
    }

      }while(mapa[chutex][chutey] != ' ');
     mapa[chutex][chutey] = 'I';
    // printf("%d,%d - ",chutex,chutey);
    }
    //inimigos[0].x=2;
    //inimigos[0].y=3;
    //inimigos[0].ini_morto = 0;
    //inimigos[1].x=2;
   // inimigos[1].y=36;
  //  inimigos[1].ini_morto = 0;
  //  inimigos[2].x=8;
   // inimigos[2].y=10;
   // inimigos[2].ini_morto = 0;
  //  inimigos[3].x=8;
  //  inimigos[3].y=28;
   // inimigos[3].ini_morto = 0;

    do{
        hidecursor();
        desenhamapa();
       // getch();
        if(kbhit()){
            tecla = getch();
            movimentaperso(tecla);
        }
        if(retarda %10 ==0){
            movimentainimigo();
            retarda=0;
        }
        retarda++;
        if(tem_tiro == 1){
            if(retardatiro % 1 == 0){
                movimentatiro();
                retardatiro = 0;
            }
            retardatiro++;
        }
        for(int i = 0; i<INI; i++){
            if(inimigos[i].ini_tiro == 1){
                if(retarda_tiro_ini % 3 == 0){
                    movimentatiro_inimigo(i);
                    retarda_tiro_ini = 0;
                }
                retarda_tiro_ini++;
            }
        }
        if(morto != 0){
            system("cls");
            gameover();
        }
    }while(tecla != 27 && morto == 0 && matoutudo == 0);

    if (matoutudo == 1){

        matoutudo = 0;
//        contaMorto = 0;
    }
    getch();
    }while(tecla != 27  && morto == 0);

}
