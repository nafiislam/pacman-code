# include "iGraphics.h"
# include "gl.h"
#include "newheader.h"
#include<string.h>
int width=900,height=750,tempcx,tempcy,lifeline=3,i,j,k,m,font,dx=20,bx,by,px=80,py=150,point=0,playicon=0,temp=0,stand=1,t,c=0,sound=1,ti=0,pagen=0,win=0,pagen3count=0;
int temppoint,tempti,hour,minute,second,block[30][40],dot[30][40],pause=0,timer=0,len=0,mode=0,direction=1,resume=1,previousx=0,previousy=0,previousx1=0,previousy1=0,previousx2=0,previousy2=0,previousx3=0,previousy3=0;
char score[100],timetable[100],lifelinestr[50],playername[100],tempplayername[100]={'\0'};
double cx=20,cy=2,gx=0,gy=0,zxr=2,zyr=30,zxv=38,zyv,zxg,zyg,zxo,zyo,extra=0;
int newgameselect=0,resumeselect=0,reloadselect=0,highscoreselect=0,helpselect=0,exitselect=0;
long long int text=0,playerloop=0,ghostgxlength=0,ghostgx1length=0,ghostgx2length=0,ghostgx3length=0,ghosttimecontrol=0,mukh=0,ghostrmukh=0,ghostomukh=0,ghostgmukh=0,ghostvmukh=0,ghostomukh2=0;
int ghostgx[200]={2,3,4,5,6,7,8,9,10,11,12,13,14,14,14,14,14,14,14,14,14,14,14,15,15,15,15,15,16,17,18,19,20,21,22,23,24,25,26,26,26,26,26,26,26,26,26,26,25,24,23,22,21,20,19,18,17,16,15,14,14,14,14,14,14,13,12,11,10,9,8,7,6,5,4,3,2};
int ghostgy[200]={10,10,10,10,10,10,10,10,10,10,10,10,10,11,12,13,14,15,16,17,18,19,20,20,21,22,23,24,24,24,24,24,24,24,24,24,24,24,24,23,22,21,20,19,18,17,16,15,15,15,15,15,15,15,15,15,15,15,15,15,14,13,12,11,10,10,10,10,10,10,10,10,10,10,10,10,10};
int ghostgx1[200]={39,39,39,39,39,39,38,37,37,37,38,38,38,37,36,35,34,33,32,31,30,29,28,27,26,26,26,25,24,24,23,22,21,20,19,18,17,16,16,16,16,16,16,16,17,18,19,19,19,19,19,20,21,22,23,23,23,23,23,24,25,26,27,28,29,30,31,32,32,32,33,34,35,36,37,38,39,40,40,39,38,37,36,35,35,35,35,34,33,32,31,30,29,28,27,27,27,26,25,25,25,25,25,25,25,25,26,26,26,26,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
int ghostgy1[200]={3,4,5,6,7,8,8,8,7,6,6,5,4,4,4,4,4,4,4,4,4,4,4,4,4,5,6,6,6,7,7,7,7,7,7,7,7,7,8,9,10,11,12,13,13,13,13,12,11,10,9,9,9,9,9,10,11,12,13,13,13,13,13,13,13,13,13,13,14,15,15,15,15,15,15,15,15,15,14,14,14,14,14,14,13,12,11,11,11,11,11,11,11,11,11,12,13,13,13,12,11,10,9,8,7,6,6,5,4,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
int ghostgx2[200]={1,1,2,3,4,5,6,7,8,9,10,10,10,10,10,10,10,10,10,10,10,10,9,8,7,6,5,4,4,3,2,2,2,2,3,4,5,6,6,6,5,4,3,2,1,1,1,1,2,3,4,5,6,6,6,6,6,7,8,8,8,8,8,8,8,9,9,9,10,11,12,13,14,14,14,13,12,11,10,9,8,7,7,7,6,6,5,4,3,2,1};
int ghostgy2[200]={14,15,15,15,15,15,15,15,15,15,15,16,17,18,19,20,21,22,23,24,25,26,26,26,26,26,26,26,25,25,25,24,23,22,22,22,22,22,21,20,20,20,20,20,20,19,18,17,17,17,17,17,17,18,19,20,21,21,21,20,19,18,17,16,15,15,14,13,13,13,13,13,13,12,11,11,11,11,11,11,11,11,12,13,13,14,14,14,14,14,14};
int ghostgx3[200]={39,38,37,36,35,34,33,32,31,31,31,31,31,31,31,31,30,29,29,29,29,29,29,29,29,28,27,26,26,26,26,26,26,26,26,25,24,23,22,21,20,19,18,17,16,15,14,14,14,14,14,13,12,12,12,12,12,11,10,10,10,10,10,10,10,10,10,10,10,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,37,38,39,39,39,39};
int ghostgy3[200]={22,22,22,22,22,22,22,22,22,21,20,19,18,17,16,15,15,15,16,17,18,19,20,21,22,22,22,22,21,20,19,18,17,16,15,15,15,15,15,15,15,15,15,15,15,15,15,16,17,18,19,19,19,18,17,16,15,15,15,16,17,18,19,20,21,22,23,24,25,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,25,25,25,24,23,22};
char page0[5][50]={"page\\pacman.bmp","page\\ghostr.bmp","page\\ghostp.bmp","page\\ghostg.bmp","page\\ghosto.bmp"};
char page[10][100]={"page\\page0.bmp"};
double box=20;
int eatenr=0,eateng=0,eateno=0,eatenv=0,frightenedcount=0,hundredx,hundredy,hundredcount=0,thundredcount=0,thundredx,thundredy;
char playlist[10][50]={"intro.wav","game.wav","click.wav","fate.wav","victory.wav"};
char scorestring[150];
FILE *fp=NULL;
char buf;
int fireball=0,fireballleft=0;
double fireballx=0,firebally=0;
int ghosto=0,ghostoleft=0;
double ghostox=0,ghostoy=0;
int ghostoalive=0,ghostgalive=0,ghostvalive=0,ghostralive=0;
long long ghostallmukh=0;
int invisiblemode=0,pauseghost=0,increasemode=0,invisiblemodecount=0,pauseghostcount=0,increasemodecount=0;
int directchase=0,cornerchase=0;
int level1pic,level2pic;
int level1=0,level2=0;
int exiton=0;
int yeson=0,noon=0;
int tempsound=0;
int intro=1,introcount=0;
int pc=0;
char pic[11][50]={"pic1.bmp","pic2.bmp","pic3.bmp","pic4.bmp","pic5.bmp","pic6.bmp","pic8.bmp","pic9.bmp","pic10.bmp","pic11.bmp","pic7.bmp"};
struct
{
    char x[100];
    char y[100];
    char z[100];
    char a[100];
    char b[100];
}left,right,up,down;
struct high_score
{
    char name[100];
    int p;
    int t;
}scorelist[11],tempscorelist,scorelist2[10];
enum direct
{
    l,
    r,
    u,
    d
};
enum _ghostmode
{
    chase,
    scatter,
    frightened,
    eaten
}ghostmode;
enum direct godirection,grdirection,gvdirection,ggdirection,odirection;
void ghostrmove();
void newgame();
void pfs(double*,double*, double, double ,enum direct*);
void pafs(double*,double*, double, double ,enum direct*);
void playerchange();
void save();
void reload();
void save2();
void reload2();
void fireballmove();
//char player[8][20]={"pacman\\left1.bmp","pacman\\left2.bmp","pacman\\right1.bmp","pacman\\right2.bmp","pacman\\up1.bmp","pacman\\up2.bmp","pacman\\down1.bmp","pacman\\down2.bmp"};
int tempdot[30][40]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1},
    {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}


};

int tempblock[30][40]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1},
    {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
    {1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,1},
    {0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    {1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,1,1,0,1,1,0,0,0,1,1,1,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,1,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0,0,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,0,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

};


int tempdot2[30][40]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1},
    {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1},
    {1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

};

int tempblock2[30][40]={
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,0,1,1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,1,0,1},
    {0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,0,0,0,0,0,0,0},
    {1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1},
    {1,0,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

};


/*
	function iDraw() is called again and again by the system.
*/
int sorti2(struct high_score a,struct high_score b)
{
    if(a.t<b.t)
        return 1;
    else
        return 0;
}
int sorti(struct high_score a,struct high_score b)
{
    if(a.p>b.p)
        return 1;
    else if(a.p<b.p)
        return 0;
    else
        return sorti2(a,b);
}
double dist(double a,double b,double c,double d)
{
    double r;
    r=sqrt((a-c)*(a-c)*1.0+(b-d)*(b-d)*1.0);
    return r;
}
double mini(double x,double y)
{
    if(x<=y)
        return x;
    else
        return y;
}
double maxi(double x,double y)
{
    if(x>=y)
        return x;
    else
        return y;
}
void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(150, 590,400, 60);
}
void iDraw()
{
	iClear();

    if(pc==11)
        intro=0;
    if(intro&&pagen==0)
    {
            iShowBMP(0,0,pic[pc]);
            if(pc>=6)
            {
                if(text%2==0)
                {
                    iShowBMP(600,20,"loading.bmp");
                    iShowBMP(670,20,"loading2.bmp");
                }
            }
    }

	if((ti%30==0)&&!fireball&&ti&&ghostmode!=frightened)
	{
	    fireball=1;
	    fireballx=ceil(zxr);
	    firebally=ceil(zyr);
	    if(zxr-cx>0)
            fireballleft=1;
        else
            fireballleft=0;

	}

    if((ti%30==0)&&!ghosto&&ti&&ghostmode!=frightened)
    {
        ghosto=1;
	    ghostox=ceil(zxo);
	    ghostoy=ceil(zyo);
	    if(zyo-cy>0)
            ghostoleft=1;
        else
            ghostoleft=0;
    }

	if(ghostmode==frightened&&frightenedcount>20)
    {
        ghostmode=chase,eateng=0,eatenv=0,eatenr=0,eateno=0;
        ghostoalive=0,ghostvalive=0,ghostgalive=0,ghostralive=0;
        if(sound)
            PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
    }
	if(playerloop!=0&&lifeline!=0)
    {
        i=playerloop;
        if(i==1)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd1.bmp",0),Sleep(50);
        if(i==2)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd2.bmp",0),Sleep(50);
        if(i==3)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd3.bmp",0),Sleep(50);
        if(i==4)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd4.bmp",0),Sleep(50);
        if(i==5)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd5.bmp",0),Sleep(50);
        if(i==6)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd6.bmp",0),Sleep(50);
        if(i==7)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd7.bmp",0),Sleep(50);
        if(i==8)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd8.bmp",0),Sleep(50);
        if(i==9)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd9.bmp",0),Sleep(50);
        if(i==10)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd10.bmp",0),Sleep(50);
        if(i==11)
            iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,"ghost\\pd11.bmp",0),Sleep(50);
        playerloop++;
        if(playerloop==12){
            playerloop=0,cx=20,cy=2;
            iResumeTimer(0);
            iResumeTimer(1);
            iResumeTimer(2);
            if(sound)
                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);

        }
    }

	if(!pause&&resume)
    {
        //printf("%d\n",ghosttimecontrol);
        if(ghosttimecontrol<150)
            dx=3;
        else if(ghosttimecontrol<1000)
            dx=2;
        else if(ghosttimecontrol<1300)
            dx=1;
        else
            ghosttimecontrol=1;
        if(ti%80<70&&ghostmode!=frightened)
            ghostmode=chase;
        else if(ti%80>=71&&ti%80<80&&ghostmode!=frightened)
            ghostmode=scatter;

        if(ti%80>=40&&ti%80<44&&!cornerchase&&!directchase)
            directchase=1,cornerchase=1;

        if(ghosttimecontrol%dx==0&&!playerloop&&!pauseghost)
        {
            fireballmove();
            if(ghostmode==chase)
            {
                pfs(&zxr,&zyr,cx,cy,&grdirection);
                if(!directchase)
                {
                    if(direction==0)
                        pfs(&zxg,&zyg,cx-4,cy,&ggdirection);
                    else if(direction==1)
                        pfs(&zxg,&zyg,cx+4,cy,&ggdirection);
                    else if(direction==2)
                        pfs(&zxg,&zyg,cx-4,cy+4,&ggdirection);
                    else if(direction==3)
                        pfs(&zxg,&zyg,cx,cy-4,&ggdirection);
                }
                else
                {
                    pfs(&zxg,&zyg,cx,cy,&ggdirection);
                    directchase++;
                    //printf("%d\n",ti);
                    if(directchase>=80)
                        directchase=0;
                }
                if(!cornerchase)
                {
                    if(direction==0)
                        bx=2*(cx-2)-zxr,by=2*cy-zyr;
                    else if(direction==1)
                        bx=2*(cx+2)-zxr,by=2*cy-zyr;
                    else if(direction==2)
                        bx=2*(cx-2)-zxr,by=2*(cy+2)-zyr;
                    else if(direction==3)
                        bx=2*cx-zxr,by=2*(cy-2)-zyr;

                    pfs(&zxv,&zyv,bx,by,&gvdirection);
                }
                else
                {
                    if(direction==0)
                        pfs(&zxv,&zyv,cx-2,cy,&gvdirection);
                    else if(direction==1)
                        pfs(&zxv,&zyv,cx+2,cy,&gvdirection);
                    else if(direction==2)
                        pfs(&zxv,&zyv,cx,cy+2,&gvdirection);
                    else if(direction==3)
                        pfs(&zxv,&zyv,cx,cy-2,&gvdirection);
                    cornerchase++;
                    if(cornerchase>=80)
                        cornerchase=0;
                }
                bx=rand()%40;
                by=rand()%30;
                pfs(&zxo,&zyo,bx,by,&godirection);
            }
            else if(ghostmode==scatter||ghostmode==frightened)
            {
                bx=rand()%40;
                by=rand()%30;
                if(ghostmode==frightened&&eatenr==1&&!ghostralive)
                {
                     if(level1pic)
                     {
                        if(fabs(zxr-25)>0.5||fabs(zyr-23)>0.5)
                        {
                            pfs(&zxr,&zyr,25,23,&grdirection);
                            pfs(&zxr,&zyr,25,23,&grdirection);

                        }
                        else if(fabs(zxr-25)<=0.5&&fabs(zyr-23)<=0.5)
                        {
                            ghostralive=1;
                        }
                     }
                     else if(level2pic)
                     {
                         if(fabs(zxr-21)>0.5||fabs(zyr-21)>0.5)
                        {
                            pfs(&zxr,&zyr,21,21,&grdirection);
                            pfs(&zxr,&zyr,21,21,&grdirection);

                        }
                        else if(fabs(zxr-21)<=0.5&&fabs(zyr-21)<=0.5)
                        {
                            ghostralive=1;
                        }
                     }
                }
                else if(!ghostralive)
                    pfs(&zxr,&zyr,bx,by,&grdirection);
                bx=rand()%40;
                by=rand()%30;
                if(ghostmode==frightened&&eateng==1&&!ghostgalive)
                {
                    if(level1pic)
                    {
                        if(fabs(zxg-16)>0.5||fabs(zyg-18)>0.5)
                        {
                            pfs(&zxg,&zyg,16,18,&ggdirection);
                            pfs(&zxg,&zyg,16,18,&ggdirection);
                        }
                        else if(fabs(zxg-16)<=0.5&&fabs(zyg-18)<=0.5)
                        {
                            ghostgalive=1;
                        }
                    }
                    else if(level2pic)
                    {
                        if(fabs(zxg-22)>0.5||fabs(zyg-21)>0.5)
                        {
                            pfs(&zxg,&zyg,22,21,&ggdirection);
                            pfs(&zxg,&zyg,22,21,&ggdirection);
                        }
                        else if(fabs(zxg-22)<=0.5&&fabs(zyg-21)<=0.5)
                        {
                            ghostgalive=1;
                        }
                    }

                }
                else if(!ghostgalive)
                    pfs(&zxg,&zyg,bx,by,&ggdirection);
                bx=rand()%40;
                by=rand()%30;
                if(ghostmode==frightened&&eatenv==1&&!ghostvalive)
                {
                    if(level1pic)
                    {
                        if(fabs(zxv-25)>0.5||fabs(zyv-18)>0.5)
                        {
                            pfs(&zxv,&zyv,25,18,&gvdirection);
                            pfs(&zxv,&zyv,25,18,&gvdirection);
                        }
                        else if(fabs(zxv-25)<=0.5&&fabs(zyv-18)<=0.5)
                        {
                            ghostvalive=1;
                        }
                    }
                    else if(level2pic)
                    {
                        if(fabs(zxv-22)>0.5||fabs(zyv-22)>0.5)
                        {
                            pfs(&zxv,&zyv,22,22,&gvdirection);
                            pfs(&zxv,&zyv,22,22,&gvdirection);
                        }
                        else if(fabs(zxv-22)<=0.5&&fabs(zyv-22)<=0.5)
                        {
                            ghostvalive=1;
                        }
                    }
                }
                else if(!ghostvalive)
                    pfs(&zxv,&zyv,bx,by,&gvdirection);
                bx=rand()%40;
                by=rand()%30;
                if(ghostmode==frightened&&eateno==1&&!ghostoalive)
                {
                    if(level1pic)
                    {
                        if(fabs(zxo-16)>0.5||fabs(zyo-23)>0.5)
                        {
                            pfs(&zxo,&zyo,16,23,&godirection);
                            pfs(&zxo,&zyo,16,23,&godirection);
                        }
                        else if(fabs(zxo-16)<=0.5&&fabs(zyo-23)<=0.5)
                        {
                            ghostoalive=1;
                        }
                    }
                    else if(level2pic)
                    {
                        if(fabs(zxo-23)>0.5||fabs(zyo-21)>0.5)
                        {
                            pfs(&zxo,&zyo,23,21,&godirection);
                            pfs(&zxo,&zyo,23,21,&godirection);
                        }
                        else if(fabs(zxo-23)<=0.5&&fabs(zyo-21)<=0.5)
                        {
                            ghostoalive=1;
                        }
                    }
                }
                else if(!ghostoalive)
                    pfs(&zxo,&zyo,bx,by,&godirection);
            }

        }
        else if(ghosttimecontrol%dx==0&&!playerloop)
        {
            fireballmove();
        }
        if(ghosttimecontrol%4<2&&!playerloop)
        {
            playerchange();
            if(increasemode)
                playerchange();
        }

    }
    if(!invisiblemode&&ghostmode!=frightened&&playerloop==0&&pagen!=4&&(((fabs(zxg-cx)<0.5)&&(fabs(zyg-cy)<0.5))||((fabs(zxv-cx)<0.5)&&(fabs(zyv-cy)<0.5))||((fabs(zxr-cx)<.5)&&(fabs(zyr-cy)<0.5))||((fabs(zxo-cx)<0.5)&&(fabs(zyo-cy)<0.5)))&&pagen==2)
    {
        fireball=0;
        ghosto=0;
        pauseghost=0;
        invisiblemode=0;
        increasemode=0;
        pauseghostcount=0;
        invisiblemodecount=0;
        increasemodecount=0;
        lifeline--;
        playerloop=1;
        PlaySound("collision.wav",NULL,SND_ASYNC);
        if(level1pic)
        {
            zxg=16;
            zyg=18;
            zxr=25;
            zyr=23;
            zxv=25;
            zyv=18;
            zxo=16;
            zyo=23;
        }
        if(level2pic)
        {
            zxv=22;
            zyv=22;
            zxg=22;
            zyg=21;
            zxr=21;
            zyr=21;
            zxo=23;
            zyo=21;
        }
        playicon=0;
        direction=1;
        if(lifeline!=0)
        {
            iPauseTimer(0);
            iPauseTimer(1);
        }
        if(lifeline==0)
        {
            temppoint=point;
            tempti=ti;
            PlaySound(playlist[2],NULL,SND_ASYNC);
            Sleep(100);
            pagen=4;
            PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
            lifeline=3;
            newgame();
            dx=20,cx=20,cy=2,px=80,py=150;
            playerloop=0;
        }
    }
    else if(ghostmode==frightened&&playerloop==0&&pagen!=4&&(((fabs(zxg-cx)<0.5)&&(fabs(zyg-cy)<0.5))||((fabs(zxv-cx)<0.5)&&(fabs(zyv-cy)<0.5))||((fabs(zxr-cx)<.5)&&(fabs(zyr-cy)<0.5))||((fabs(zxo-cx)<0.5)&&(fabs(zyo-cy)<0.5)))&&pagen==2)
    {
        if(((fabs(zxg-cx)<0.5)&&(fabs(zyg-cy)<0.5))&&!eateng)
        {
            eateng=1;
            point+=100;
            win+=100;
            hundredx=zxg;
            hundredy=zyg;
            hundredcount=1;
            PlaySound("eatghost.wav",NULL,SND_ASYNC);
            Sleep(200);
            if(sound)
                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
        }
        if(((fabs(zxv-cx)<0.5)&&(fabs(zyv-cy)<0.5))&&!eatenv)
        {
            eatenv=1;
            point+=100;
            win+=100;
            hundredx=zxv;
            hundredy=zyv;
            hundredcount=1;
            PlaySound("eatghost.wav",NULL,SND_ASYNC);
            Sleep(200);
            if(sound)
                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
        }
        if(((fabs(zxr-cx)<.5)&&(fabs(zyr-cy)<0.5))&&!eatenr)
        {
            eatenr=1;
            point+=100;
            win+=100;
            hundredx=zxr;
            hundredy=zyr;
            hundredcount=1;
            PlaySound("eatghost.wav",NULL,SND_ASYNC);
            Sleep(200);
            if(sound)
                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
        }
        if(((fabs(zxo-cx)<.5)&&(fabs(zyo-cy)<0.5))&&!eateno)
        {
            eateno=1;
            point+=100;
            win+=100;
            hundredx=zxo;
            hundredy=zyo;
            hundredcount=1;
            PlaySound("eatghost.wav",NULL,SND_ASYNC);
            Sleep(200);
            if(sound)
                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
        }
    }

    //printf("%d\n",dx);

	if(pagen==3&&pagen3count>=500)
    {
        newgame();
        ti=0;
        point=0;
        cx=20;
        cy=2;
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                block[i-1][j-1]=tempblock[i-1][j-1];
            }
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                dot[i-1][j-1]=tempdot[i-1][j-1];
            }
        PlaySound(playlist[2],NULL,SND_ASYNC);
        Sleep(100);
        pagen=4;
        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
    }
    if(pause)
    {
        iShowBMP(0,150,"pause.bmp");
        iShowBMP2(375,150,"resume.bmp",0);
        iSetColor(255,0,0);
        if(timer%2==0)
            iText(300,100,"PRESS R / r TO CONTINUE",(void*)font);
    }
	else if(pagen==2)
    {
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                if(block[i-1][j-1]==1)
                {
                    //iSetColor(217, 180, 105);
                    //iFilledRectangle(40+(j-1)*box,70+(i-1)*box,box,box);
                    if(level1pic)
                        iShowBMP(40+(j-1)*box,70+(i-1)*box,"block.bmp");
                    else if(level2pic)
                        iShowBMP(40+(j-1)*box,70+(i-1)*box,"block2.bmp");
                }
                else
                {
                    if(((i==2&&j==2)||(i==2&&j==39)||(i==29&&j==39)||(i==29&&j==2))&&(dot[i-1][j-1]==0))
                    {
                        iSetColor(189,11,173);
                        iFilledCircle(40+(j-1)*box+box/2,70+(i-1)*box+box/2, 8,100);
                    }
                    else if(((i==13&j==2))&&(dot[i-1][j-1]==0)&&extra!=2)
                    {
                        iShowBMP2(40+(j-1)*box,70+(i-1)*box,"ghost\\cherry.bmp",0);

                    }
                    else if((i==13&&j==39)&&(dot[i-1][j-1]==0)&&extra!=2)
                        iShowBMP2(40+(j-1)*box,70+(i-1)*box,"apple.bmp",0);
                    else if(((i==18&j==2)||(i==18&&j==39))&&(dot[i-1][j-1]==0))
                    {
                        iSetColor(144,79,15);
                        iFilledCircle(40+(j-1)*box+box/2,70+(i-1)*box+box/2, 8,100);

                    }
                    else if(((i==9&j==10)||(i==9&&j==31))&&(dot[i-1][j-1]==0))
                    {
                        iSetColor(242,186,184);
                        iFilledCircle(40+(j-1)*box+box/2,70+(i-1)*box+box/2, 8,100);

                    }
                    else if(((i==22&j==10)||(i==22&&j==31))&&(dot[i-1][j-1]==0))
                    {
                        iSetColor(241,20,33);
                        iFilledCircle(40+(j-1)*box+box/2,70+(i-1)*box+box/2, 8,100);

                    }
                    else if(dot[i-1][j-1]==0)
                    {
                        iSetColor(102,255,153);
                        iFilledCircle(40+(j-1)*box+box/2,70+(i-1)*box+box/2, 3,100);
                    }

                }

            }
        sprintf(score,"Score :%d",point);
        hour=ti/(60*60);
        minute=(ti-hour*60*60)/(60);
        second=ti-hour*60*60-minute*60;
        sprintf(timetable,"Time %d: %d: %d",hour,minute,second);
        strcpy(lifelinestr,"Lifeline :  ");
        iSetColor(255,0,0);
        iText(50, 700,score,(void*)font);
        if(level1pic)
        {
            iSetColor(255,255,255);
            iText(200, 700,"LEVEL 1",(void*)font);
        }
        else if(level2pic)
        {
            iSetColor(255,255,255);
            iText(200, 700,"LEVEL 2",(void*)font);
        }
        iSetColor(0,255,0);
        iText(330, 700,timetable,(void*)font);
        iSetColor(20,241,228);
        iText(500, 700,lifelinestr,(void*)font);
        for(i=0;i<lifeline;i++)
        {
            iShowBMP2(590+i*20,700,"pacman\\right3.bmp",0);
        }
        if(!stand&&!playerloop)
        {
            if(playicon==0)
            {
                if(invisiblemode)
                    iShowBMP(40+(cx-1)*box,70+(cy-1)*box,"square.bmp");
                if(mukh%4<2)
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,left.x,0),mukh++;
                else
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,left.z,0),mukh++;

            }
            else if(playicon==1)
            {
                if(invisiblemode)
                    iShowBMP(40+(cx-1)*box,70+(cy-1)*box,"square.bmp");
                if(mukh%4<2)
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,right.x,0),mukh++;
                else
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,right.z,0),mukh++;
            }
            else if(playicon==2)
            {
                if(invisiblemode)
                    iShowBMP(40+(cx-1)*box,70+(cy-1)*box,"square.bmp");
                if(mukh%4<2)
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,up.x,0),mukh++;
                else
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,up.z,0),mukh++;
            }
            else if(playicon==3)
            {
                if(invisiblemode)
                    iShowBMP(40+(cx-1)*box,70+(cy-1)*box,"square.bmp");
                if(mukh%4<2)
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,down.x,0),mukh++;
                else
                    iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,down.z,0),mukh++;
            }
        }
        else if(!playerloop)
        {
            if(playicon==0)
            {
                iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,left.y,0);
            }
            else if(playicon==1)
            {
                iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,right.y,0);
            }
            else if(playicon==2)
            {
                iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,up.y,0);
            }
            else if(playicon==3)
            {
                iShowBMP2(40+(cx-1)*box,70+(cy-1)*box,up.y,0);
            }
        }
        if(ghostmode==frightened&&!playerloop)
        {
            if(ghostallmukh%2==0)
            {
                if(eatenr!=1)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\fright.bmp",0);
                if(eateng!=1)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\fright.bmp",0);
                if(eateno!=1)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\fright.bmp",0);
                if(eatenv!=1)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\fright.bmp",0);
                ghostallmukh++;
            }
            else
            {
                if(eatenr!=1)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\fright2.bmp",0);
                if(eateng!=1)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\fright2.bmp",0);
                if(eateno!=1)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\fright2.bmp",0);
                if(eatenv!=1)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\fright2.bmp",0);
                ghostallmukh++;
            }
        }
        if(!playerloop)
        {
            if(godirection==r)
            {
                if(eateno==1&&!ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\eatenright.bmp",0);
                else if(ghostomukh%2==0&&(ghostmode!=frightened||ghostoalive))
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoright.bmp",0),ghostomukh++;
                else if(ghostmode!=frightened||ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoright2.bmp",0),ghostomukh++;
            }
            else if(godirection==l)
            {
                if(eateno==1&&!ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\eatenleft.bmp",0);
                else if(ghostomukh%2==0&&(ghostmode!=frightened||ghostoalive))
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoleft.bmp",0),ghostomukh++;
                else if(ghostmode!=frightened||ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoleft2.bmp",0),ghostomukh++;
            }
            else if(godirection==u)
            {
                if(eateno==1&&!ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\eatenup.bmp",0);
                else if(ghostomukh%2==0&&(ghostmode!=frightened||ghostoalive))
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoup.bmp",0),ghostomukh++;
                else if(ghostmode!=frightened||ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostoup2.bmp",0),ghostomukh++;
            }
            else if(godirection==d)
            {
                if(eateno==1&&!ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\eatendown.bmp",0);
                else if(ghostomukh%2==0&&(ghostmode!=frightened||ghostoalive))
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostodown.bmp",0),ghostomukh++;
                else if(ghostmode!=frightened||ghostoalive)
                    iShowBMP2(40+(zxo-1)*box,70+(zyo-1)*box,"ghost\\ghostodown2.bmp",0),ghostomukh++;
            }


            if(ggdirection==r)
            {
                if(eateng==1&&!ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\eatenright.bmp",0);
                else if(ghostgmukh%2==0&&(ghostmode!=frightened||ghostgalive))
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgright.bmp",0),ghostgmukh++;
                else if(ghostmode!=frightened||ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgright2.bmp",0),ghostgmukh++;
            }
            else if(ggdirection==l)
            {
                if(eateng==1&&!ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\eatenleft.bmp",0);
                else if(ghostgmukh%2==0&&(ghostmode!=frightened||ghostgalive))
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgleft.bmp",0),ghostgmukh++;
                else if(ghostmode!=frightened||ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgleft2.bmp",0),ghostgmukh++;

            }

            else if(ggdirection==u)
            {
                if(eateng==1&&!ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\eatenup.bmp",0);
                else if(ghostgmukh%2==0&&(ghostmode!=frightened||ghostgalive))

                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgup.bmp",0),ghostgmukh++;
                else if(ghostmode!=frightened||ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgup2.bmp",0),ghostgmukh++;

            }

            else if(ggdirection==d)
            {
                if(eateng==1&&!ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\eatendown.bmp",0);
                else if(ghostgmukh%2==0&&(ghostmode!=frightened||ghostgalive))
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgdown.bmp",0),ghostgmukh++;
                else if(ghostmode!=frightened||ghostgalive)
                    iShowBMP2(40+(zxg-1)*box,70+(zyg-1)*box,"ghost\\ghostgdown2.bmp",0),ghostgmukh++;

            }

            if(grdirection==r)
            {
                if(eatenr==1&&!ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\eatenright.bmp",0);
                else if(ghostrmukh%2==0&&(ghostmode!=frightened||ghostralive))
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrright.bmp",0),ghostrmukh++;
                else if(ghostmode!=frightened||ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrright2.bmp",0),ghostrmukh++;
            }
            else if(grdirection==l)
            {
                if(eatenr==1&&!ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\eatenleft.bmp",0);
                else if(ghostrmukh%2==0&&(ghostmode!=frightened||ghostralive))
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrleft.bmp",0),ghostrmukh++;
                else if(ghostmode!=frightened||ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrleft2.bmp",0),ghostrmukh++;
            }
            else if(grdirection==u)
            {
                if(eatenr==1&&!ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\eatenup.bmp",0);
                else if(ghostrmukh%2==0&&(ghostmode!=frightened||ghostralive))
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrup.bmp",0),ghostrmukh++;
                else if(ghostmode!=frightened||ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrup2.bmp",0),ghostrmukh++;
            }
            else if(grdirection==d)
            {
                if(eatenr==1&&!ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\eatendown.bmp",0);
                else if(ghostrmukh%2==0&&(ghostmode!=frightened||ghostralive))
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrdown.bmp",0),ghostrmukh++;
                else if(ghostmode!=frightened||ghostralive)
                    iShowBMP2(40+(zxr-1)*box,70+(zyr-1)*box,"ghost\\ghostrdown2.bmp",0),ghostrmukh++;
            }

            if(gvdirection==r)
            {
                if(eatenv==1&&!ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\eatenright.bmp",0);
                else if(ghostvmukh%2==0&&(ghostmode!=frightened||ghostvalive))
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvright.bmp",0),ghostvmukh++;
                else if(ghostmode!=frightened||ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvright2.bmp",0),ghostvmukh++;
            }
            else if(gvdirection==l)
            {
                if(eatenv==1&&!ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\eatenleft.bmp",0);
                else if(ghostvmukh%2==0&&(ghostmode!=frightened||ghostvalive))
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvright.bmp",0),ghostvmukh++;
                else if(ghostmode!=frightened||ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvright2.bmp",0),ghostvmukh++;
            }
            else if(gvdirection==u)
            {
                if(eatenv==1&&!ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\eatenup.bmp",0);
                else if(ghostvmukh%2==0&&(ghostmode!=frightened||ghostvalive))
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvup.bmp",0),ghostvmukh++;
                else if(ghostmode!=frightened||ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvup2.bmp",0),ghostvmukh++;
            }
            else if(gvdirection==d)
            {
                if(eatenv==1&&!ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\eatendown.bmp",0);
                else if(ghostvmukh%2==0&&(ghostmode!=frightened||ghostvalive))
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvdown.bmp",0),ghostvmukh++;
                else if(ghostmode!=frightened||ghostvalive)
                    iShowBMP2(40+(zxv-1)*box,70+(zyv-1)*box,"ghost\\ghostvdown2.bmp",0),ghostvmukh++;
            }
        }
        if(sound)
            iShowBMP(700,680,"soundon.bmp");
        else
            iShowBMP(700,680,"soundoff.bmp");
        iShowBMP(780,680,"homebutton.bmp");
        iShowBMP2(840,680,"pauseicon.bmp",0);

        if(ghostralive)
        {
            if(!pauseghost&&ghosttimecontrol%dx==0&&!playerloop)
            {
                bx=rand()%40;
                by=rand()%30;
                pfs(&zxr,&zyr,bx,by,&grdirection);
            }


            if(!invisiblemode&&playerloop==0&&pagen!=4&&(fabs(zxr-cx)<.5)&&(fabs(zyr-cy)<0.5)&&pagen==2)
            {
                fireball=0;
                ghosto=0;
                pauseghost=0;
                invisiblemode=0;
                increasemode=0;
                pauseghostcount=0;
                invisiblemodecount=0;
                increasemodecount=0;
                lifeline--;
                playerloop=1;
                PlaySound("collision.wav",NULL,SND_ASYNC);
                if(level1pic)
                {
                    zxg=16;
                    zyg=18;
                    zxr=25;
                    zyr=23;
                    zxv=25;
                    zyv=18;
                    zxo=16;
                    zyo=23;
                }
                if(level2pic)
                {
                    zxv=22;
                    zyv=22;
                    zxg=22;
                    zyg=21;
                    zxr=21;
                    zyr=21;
                    zxo=23;
                    zyo=21;
                }
                playicon=0;
                direction=1;
                if(lifeline!=0)
                {
                    iPauseTimer(0);
                    iPauseTimer(1);
                }
                if(lifeline==0)
                {
                    temppoint=point;
                    tempti=ti;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    pagen=4;
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    lifeline=3;
                    newgame();
                    dx=20,cx=20,cy=2,px=80,py=150;
                    playerloop=0;
                }
            }

        }
        if(ghostoalive)
        {
            if(!pauseghost&&ghosttimecontrol%dx==0&&!playerloop)
            {
                bx=rand()%40;
                by=rand()%30;
                pfs(&zxo,&zyo,bx,by,&godirection);
            }


            if(!invisiblemode&&playerloop==0&&pagen!=4&&(fabs(zxo-cx)<.5)&&(fabs(zyo-cy)<0.5)&&pagen==2)
            {
                fireball=0;
                ghosto=0;
                pauseghost=0;
                invisiblemode=0;
                increasemode=0;
                pauseghostcount=0;
                invisiblemodecount=0;
                increasemodecount=0;
                lifeline--;
                playerloop=1;
                PlaySound("collision.wav",NULL,SND_ASYNC);
                if(level1pic)
                {
                    zxg=16;
                    zyg=18;
                    zxr=25;
                    zyr=23;
                    zxv=25;
                    zyv=18;
                    zxo=16;
                    zyo=23;
                }
                if(level2pic)
                {
                    zxv=22;
                    zyv=22;
                    zxg=22;
                    zyg=21;
                    zxr=21;
                    zyr=21;
                    zxo=23;
                    zyo=21;
                }
                playicon=0;
                direction=1;
                if(lifeline!=0)
                {
                    iPauseTimer(0);
                    iPauseTimer(1);
                }
                if(lifeline==0)
                {
                    temppoint=point;
                    tempti=ti;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    pagen=4;
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    lifeline=3;
                    newgame();
                    dx=20,cx=20,cy=2,px=80,py=150;
                    playerloop=0;
                }
            }

        }
        if(ghostgalive)
        {
            if(!pauseghost&&ghosttimecontrol%dx==0&&!playerloop)
            {
                bx=rand()%40;
                by=rand()%30;
                pfs(&zxg,&zyg,bx,by,&ggdirection);
            }


            if(!invisiblemode&&playerloop==0&&pagen!=4&&(fabs(zxg-cx)<.5)&&(fabs(zyg-cy)<0.5)&&pagen==2)
            {
                fireball=0;
                ghosto=0;
                pauseghost=0;
                invisiblemode=0;
                increasemode=0;
                pauseghostcount=0;
                invisiblemodecount=0;
                increasemodecount=0;
                lifeline--;
                playerloop=1;
                PlaySound("collision.wav",NULL,SND_ASYNC);
                if(level1pic)
                {
                    zxg=16;
                    zyg=18;
                    zxr=25;
                    zyr=23;
                    zxv=25;
                    zyv=18;
                    zxo=16;
                    zyo=23;
                }
                if(level2pic)
                {
                    zxv=22;
                    zyv=22;
                    zxg=22;
                    zyg=21;
                    zxr=21;
                    zyr=21;
                    zxo=23;
                    zyo=21;
                }
                playicon=0;
                direction=1;
                if(lifeline!=0)
                {
                    iPauseTimer(0);
                    iPauseTimer(1);
                }
                if(lifeline==0)
                {
                    temppoint=point;
                    tempti=ti;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    pagen=4;
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    lifeline=3;
                    newgame();
                    dx=20,cx=20,cy=2,px=80,py=150;
                    playerloop=0;
                }
            }

        }
        if(ghostvalive)
        {
            if(!pauseghost&&ghosttimecontrol%dx==0&&!playerloop)
            {
                bx=rand()%40;
                by=rand()%30;
                pfs(&zxv,&zyv,bx,by,&gvdirection);
            }


            if(!invisiblemode&&playerloop==0&&pagen!=4&&(fabs(zxv-cx)<.5)&&(fabs(zyv-cy)<0.5)&&pagen==2)
            {
                fireball=0;
                ghosto=0;
                pauseghost=0;
                invisiblemode=0;
                increasemode=0;
                pauseghostcount=0;
                invisiblemodecount=0;
                increasemodecount=0;
                lifeline--;
                playerloop=1;
                PlaySound("collision.wav",NULL,SND_ASYNC);
                if(level1pic)
                {
                    zxg=16;
                    zyg=18;
                    zxr=25;
                    zyr=23;
                    zxv=25;
                    zyv=18;
                    zxo=16;
                    zyo=23;
                }
                if(level2pic)
                {
                    zxv=22;
                    zyv=22;
                    zxg=22;
                    zyg=21;
                    zxr=21;
                    zyr=21;
                    zxo=23;
                    zyo=21;
                }
                playicon=0;
                direction=1;
                if(lifeline!=0)
                {
                    iPauseTimer(0);
                    iPauseTimer(1);
                }
                if(lifeline==0)
                {
                    temppoint=point;
                    tempti=ti;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    pagen=4;
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    lifeline=3;
                    newgame();
                    dx=20,cx=20,cy=2,px=80,py=150;
                    playerloop=0;
                }
            }

        }
        if(hundredcount!=0)
        {
            hundredcount++;
            if(hundredcount>15)
                hundredcount=0;
            iShowBMP2(40+(hundredx-1)*box,70+(hundredy-1)*box,"ghost\\100.bmp",0);

        }
        if(thundredcount!=0)
        {
            thundredcount++;
            if(thundredcount>15)
                thundredcount=0;
            iShowBMP2(40+(thundredx-1)*box,70+(thundredy-1)*box,"ghost\\200.bmp",0);

        }
        if(increasemode)
        {
            increasemodecount++;
            if(increasemodecount>=150)
                increasemode=0,invisiblemodecount=0;
        }
        if(invisiblemode)
        {
            //printf("%d    %d\n",invisiblemodecount,ti);
            invisiblemodecount++;
            if(invisiblemodecount>=200)
                invisiblemode=0,invisiblemodecount=0;

        }
        if(pauseghost)
        {
            //printf("%d    %d\n",pauseghostcount,ti);
            pauseghostcount++;
            if(pauseghostcount>=150)
                pauseghost=0,pauseghostcount=0;
        }


        if(fireball)
        {
            iShowBMP2(40+(fireballx-1)*box,70+(firebally-1)*box,"ghost\\fireball.bmp",0);
        }

        if(ghosto)
        {
            if(odirection==r)
            {
                if(ghostomukh2%2==0)
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoright.bmp",0),ghostomukh2++;
                else
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoright2.bmp",0),ghostomukh2++;
            }
            else if(odirection==l)
            {
                if(ghostomukh2%2==0)
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoleft.bmp",0),ghostomukh2++;
                else
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoleft2.bmp",0),ghostomukh2++;
            }
            else if(odirection==u)
            {
                if(ghostomukh2%2==0)
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoup.bmp",0),ghostomukh2++;
                else
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostoup2.bmp",0),ghostomukh2++;
            }
            else if(odirection==d)
            {
                if(ghostomukh%2==0)
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostodown.bmp",0),ghostomukh2++;
                else
                    iShowBMP2(40+(ghostox-1)*box,70+(ghostoy-1)*box,"ghost\\ghostodown2.bmp",0),ghostomukh2++;
            }


        }


    }
    else if(pagen==0&&!intro)
    {
        iShowBMP(0,150,"page0.bmp");
        if(px%10<5)
            iShowBMP2(px,py,page0[0],0);
        else
            iShowBMP2(px,py,right.z,0);
        iShowBMP2(px-20,py,page0[1],0);
        iShowBMP2(px-40,py,page0[2],0);
        iShowBMP2(px-60,py,page0[3],0);
        iShowBMP2(px-80,py,page0[4],0);
        for(i=1;i<=(width-px-20)/20;i++)
        {
            iSetColor(255,255,255);
            iFilledCircle(80+(40-i)*20+10,py+10, 5,100);
        }
        font=5;
        if(text%2==0)
        {
            iSetColor(255,255,255);
            iText(width/2-60,100, "Press ENTER",(void*)font);
        }
        else
        {

        }
        if(px==width)
            px=80;
        else
            px=px+1;

    }
    else if(pagen==1)
    {
        iShowBMP(0,50,"page1.bmp");
        iShowBMP2(460,600,"pacman.bmp",0xFFFFFF);

        font=2;
        if(!newgameselect)
            iShowBMP2(650,540,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,540,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(690,575,"NEW GAME",(void*)font);
        if(!resumeselect)
            iShowBMP2(650,460,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,460,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(680,495,"RESUME GAME",(void*)font);
        if(!reloadselect)
            iShowBMP2(650,380,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,380,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(680,415,"RELOAD GAME",(void*)font);
        if(!highscoreselect)
            iShowBMP2(650,300,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,300,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(685,335,"HIGHSCORES",(void*)font);
        if(!helpselect)
            iShowBMP2(650,220,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,220,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(710,255,"HELP",(void*)font);
        if(!exitselect)
            iShowBMP2(650,140,"button.bmp",0xFFFFFF);
        else
            iShowBMP2(650,140,"button2.bmp",0xFFFFFF);
        iSetColor(0,0,0);
        iText(710,175,"EXIT",(void*)font);
        pagen=1;
        font=5;
        if(sound)
            iShowBMP2(10,620,"soundon2.bmp",0);
        else
            iShowBMP2(10,620,"soundoff2.bmp",0);

    }
    else if(pagen==3)
    {
        iShowBMP(0,50,"victory.bmp");
        pagen3count++;
        sprintf(score,"YOUR SCORE TIME IS  %d: %d: %d",hour,minute,second);
        iSetColor(149,12,111);
        iText(300,650,score,(void*)font);
        sprintf(score,"YOUR SCORE :  %d",temppoint);
        iText(300, 700,score,(void*)font);
    }
    else if(pagen==4)
    {
        iShowBMP(0,50,"namesave.bmp");
        iShowBMP2(600,445,"gameover.bmp",0);
        drawTextBox();

        font=5;
        iSetColor(255, 255, 255);
        iText(155, 600, playername,(void*)font);
        iText(280, 670, "Enter Your Name",(void*)font);
        sprintf(score,"Your Score :  %d",temppoint);
        iText(280, 540,score,(void*)font);
        hour=tempti/(60*60);
        minute=(tempti-hour*60*60)/(60);
        second=tempti-hour*60*60-minute*60;
        sprintf(timetable,"Time %d: %d: %d",hour,minute,second);
        iText(280, 490,timetable,(void*)font);

        //iText(100, 250, "Click to activate the box, enter to finish.",(void*)font);
        if(mode==0&&strlen(tempplayername)!=0)
        {
            i=0,j=0,k=0,m=0;
            fp=fopen("highscore.txt","r");
            while(1)
            {
                fscanf(fp,"%d",&scorelist[i].p);
                fscanf(fp,"%d",&scorelist[i].t);
                fscanf(fp,"%c%[^\n]",&buf,scorelist[i].name);
                i++;
                if(feof(fp))
                    break;
                if(ferror(fp))
                    break;
            }
            fclose(fp);
            scorelist[i].p=temppoint;
            scorelist[i].t=tempti;
            strcpy(scorelist[i].name,tempplayername);
            for(j=0;j<i+1;j++)
            {
                m=j;
                for(k=j+1;k<i+1;k++)
                {
                    if(sorti(scorelist[k],scorelist[m]))
                        m=k;
                }
                tempscorelist.p=scorelist[j].p;
                tempscorelist.t=scorelist[j].t;
                strcpy(tempscorelist.name,scorelist[j].name);
                scorelist[j].p=scorelist[m].p;
                scorelist[j].t=scorelist[m].t;
                strcpy(scorelist[j].name,scorelist[m].name);
                scorelist[m].p=tempscorelist.p;
                scorelist[m].t=tempscorelist.t;
                strcpy(scorelist[m].name,tempscorelist.name);
            }
            fp=fopen("highscore.txt","w");
            for(j=0;j<(i)&&j<10;j++)
            {
                fprintf(fp,"%d\n",scorelist[j].p);
                fprintf(fp,"%d\n",scorelist[j].t);
                fprintf(fp,"%s\n",scorelist[j].name);
            }
            fclose(fp);

            PlaySound(playlist[2],NULL,SND_ASYNC);
            Sleep(100);
            PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
            pagen=1;
            tempplayername[0]='\0';
            newgame();
        }

    }
    else if(pagen==5)
    {

        iSetColor(238,129,105);
        iText(360,700,"HIGHSCORES",(void*)font);
        fp=fopen("highscore.txt","r");
        for(j=0;j<10;j++)
        {
            fscanf(fp,"%d",&scorelist2[j].p);
            fscanf(fp,"%d",&scorelist2[j].t);
            fscanf(fp,"%c%[^\n]",&buf,scorelist2[j].name);
            if(feof(fp))
                break;
        }
        fclose(fp);
        iSetColor(255,207,64);
        iText(110,630,"POINTS",(void*)font);
        iText(350,630,"TIME",(void*)font);
        iText(600,630,"NAME",(void*)font);
        for(i=0;i<=j&&i<10;i++)
        {
            hour=scorelist2[i].t/(60*60);
            minute=(scorelist2[i].t-hour*60*60)/(60);
            second=scorelist2[i].t-hour*60*60-minute*60;
            sprintf(timetable,"%2d: %2d: %2d",hour,minute,second);
            sprintf(scorestring,"%7d                            %s                          %s",scorelist2[i].p,timetable,scorelist2[i].name);
            iSetColor(255,255,255);
            iText(100,560-i*40,scorestring,(void*)font);
        }

        iShowBMP(0,650,"homebutton2.bmp");

    }
    else if(pagen==6)
    {
        iShowBMP(0,0,"level.bmp");
        if(level1pic)
            iShowBMP(350,250,"levelred.bmp");
        if(level2pic)
            iShowBMP(350,120,"levelred.bmp");

        iShowBMP2(350,250,"level1.bmp",0xFFFFFF);
        iShowBMP2(350,120,"level2.bmp",0xFFFFFF);
        iShowBMP(0,100,"homebutton2.bmp");
        //iSetColor(0,0,0);

    }
    else if(pagen==7)
    {
        iShowBMP(0,0,"black screen.bmp");
        iShowBMP(0,650,"homebutton2.bmp");
    }
    if(exiton==1)
    {
        iShowBMP(0,0,"blackscreen.bmp");
        if(yeson)
        {
            iSetColor(255,0,0);
            iFilledRectangle(210,195,210,103);
        }
        else if(noon)
        {
            iSetColor(255,0,0);
            iFilledRectangle(510,195,210,103);
        }

        iShowBMP2(215,200,"yes.bmp",0);
        iShowBMP2(515,200,"no.bmp",0);

    }

    /*if(intro&&pagen==0)
    {
        if(intro<8)
        {
            iShowBMP(0,0,"pic1.bmp");
        }
        else
            intro=0;

        intro++;
    }
    */
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/

void iPassiveMouseMove(int mx, int my)
{
    if(pagen==1)
    {
        if(mx>=650&&mx<=800&&my>=540&&my<=610)
        {
            newgameselect=1;
            resumeselect=0;
            reloadselect=0;
            highscoreselect=0;
            helpselect=0;
            exitselect=0;
        }
        else if(mx>=650&&mx<=800&&my>=460&&my<=530)
        {
            newgameselect=0;
            resumeselect=1;
            reloadselect=0;
            highscoreselect=0;
            helpselect=0;
            exitselect=0;
        }
        else if(mx>=650&&mx<=800&&my>=380&&my<=450)
        {
            newgameselect=0;
            resumeselect=0;
            reloadselect=1;
            highscoreselect=0;
            helpselect=0;
            exitselect=0;
        }
        else if(mx>=650&&mx<=800&&my>=300&&my<=370)
        {
            newgameselect=0;
            resumeselect=0;
            reloadselect=0;
            highscoreselect=1;
            helpselect=0;
            exitselect=0;
        }
        else if(mx>=650&&mx<=800&&my>=220&&my<=290)
        {
            newgameselect=0;
            resumeselect=0;
            reloadselect=0;
            highscoreselect=0;
            helpselect=1;
            exitselect=0;
        }
        else if(mx>=650&&mx<=800&&my>=140&&my<=210)
        {
            newgameselect=0;
            resumeselect=0;
            reloadselect=0;
            highscoreselect=0;
            helpselect=0;
            exitselect=1;
        }
        else
        {
            newgameselect=0;
            resumeselect=0;
            reloadselect=0;
            highscoreselect=0;
            helpselect=0;
            exitselect=0;
        }
    }
    if(pagen==6)
    {
        if(mx>=350&&mx<=550&&my>=250&&my<=350)
        {
            level1pic=1;
            level2pic=0;
        }
        else if(mx>=350&&mx<=550&&my>=120&&my<=220)
        {
            level1pic=0;
            level2pic=1;
        }
        else
        {
            level1pic=0;
            level2pic=0;
        }
    }
    if(exiton)
    {
        if(mx>=215&&mx<=415&&my>=200&&my<=300)
        {
            yeson=1;
            noon=0;
        }
        else if(mx>=515&&mx<=715&&my>=200&&my<=300)
        {
            yeson=0;
            noon=1;
        }
        else
        {
            yeson=0;
            noon=0;
        }


    }
}

void iMouseMove(int mx, int my)
{

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//printf("%d %d\n",mx,my);
        if(pause)
        {
            if(mx>=375&&mx<=525&&my>=150&&my<=300)
            {
                iResumeTimer(0);
                iResumeTimer(1);iResumeTimer(2);
                pause=0;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                {
                    if(pagen==0)
                        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    if(pagen==1)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                    if(pagen==2)
                        PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    if(pagen==3)
                        PlaySound(playlist[4],NULL,SND_ASYNC);
                }
            }
        }
        if(pagen==1)
        {
            if(mx>=650&&mx<=800&&my>=540&&my<=610)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                pagen=6;
            }
            else if(mx>=650&&mx<=800&&my>=460&&my<=530)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                pagen=2;
                iResumeTimer(0);
                iResumeTimer(1);iResumeTimer(2);
                resume=1;
                if(level1)
                    level1pic=1;
                if(level2)
                    level2pic=1;
            }
            else if(mx>=650&&mx<=800&&my>=380&&my<=450)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                pagen=2;
                reload();
                if(sound)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                iResumeTimer(0);
                iResumeTimer(1);iResumeTimer(2);
                resume=1;
                //level1pic=1;


            }
            else if(mx>=650&&mx<=800&&my>=300&&my<=370)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                //PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                pagen=5;
            }
            else if(mx>=650&&mx<=800&&my>=220&&my<=290)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                //PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                pagen=7;
            }
            else if(mx>=650&&mx<=800&&my>=140&&my<=210)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                pagen=0;
            }
            else if(mx >= 10 && mx <= 90 && my >= 620 && my <= 700)
            {
                if(sound)
                {
                    sound=0;
                    PlaySound(0,0,0);
                }
                else
                {
                    sound=1;
                    if(pagen==0)
                        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    else if(pagen==1)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                    else if(pagen==2)
                    {
                        if(ghostmode!=frightened)
                             PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                        else
                             PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);

                    }
                }
            }



        }
        else if(pagen==4)
        {
            if(mx >= 150 && mx <= 600 && my >= 400 && my <= 460 && mode == 0)
            {
                mode = 1;
            }
        }

        if(pagen==2)
        {
            if(mx >= 650 && mx <= 780 && my >= 650 && my <= 780)
            {
                if(sound)
                {
                    sound=0;
                    PlaySound(0,0,0);
                }
                else
                {
                    sound=1;
                    if(pagen==0)
                        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                    else if(pagen==1)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                    else if(pagen==2)
                    {
                        if(ghostmode!=frightened)
                             PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                        else
                             PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);

                    }
                }
            }
            else if(mx >= 780 && mx <= 830 && my >= 680 && my <= 730)
            {
                exiton=1;
                if(pagen==2)
                {
                    iPauseTimer(0);
                    iPauseTimer(1);iPauseTimer(2);
                    resume=0;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                }
            }
            else if(mx >= 840 && mx <= 890 && my >= 680 && my <= 730)
            {
                pause=1;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                iPauseTimer(0);
                iPauseTimer(1);
                iPauseTimer(2);
            }
        }
        if(pagen==6)
        {
            if(mx>=350&&mx<=550&&my>=250&&my<=350)
            {
                tempsound=sound;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                level1=1;
                level2=0;
                if(sound)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                pagen=2;
                iResumeTimer(0);
                iResumeTimer(1);iResumeTimer(2);
                resume=1;
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        block[i-1][j-1]=tempblock[i-1][j-1];
                    }
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        dot[i-1][j-1]=tempdot[i-1][j-1];

                    }
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        if(dot[i-1][j-1]==0)
                            win++;
                    }
                newgame();
                sound=tempsound;
            }
            else if(mx>=350&&mx<=550&&my>=120&&my<=220)
            {
                tempsound=sound;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                level1=0;
                level2=1;
                if(sound)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                pagen=2;
                iResumeTimer(0);
                iResumeTimer(1);iResumeTimer(2);
                resume=1;
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        block[i-1][j-1]=tempblock2[i-1][j-1];
                    }
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        dot[i-1][j-1]=tempdot2[i-1][j-1];

                    }
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        if(dot[i-1][j-1]==0)
                            win++;
                    }
                win--;
                win=win*10;
                newgame();
                sound=tempsound;
            }
            else if(mx >= 0 && mx <=100 && my >= 100 && my <= 200)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                exiton=1;
            }
        }
        if(pagen==5)
        {
            if(mx >= 0 && mx <=100 && my >= 650 && my <= 750)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                exiton=1;
            }
        }
        if(pagen==7)
        {
            if(mx >= 0 && mx <=100 && my >= 650 && my <= 750)
            {
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                exiton=1;
            }
        }
        if(exiton)
        {
            if(mx>=215&&mx<=415&&my>=200&&my<=300)
            {
                if(pagen==2)
                {
                    save();
                    pagen=1;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    if(sound)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                }
                else if(pagen==1)
                {
                    pagen=0;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    if(sound)
                        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                }
                else if(pagen==5)
                {
                    pagen=1;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    if(sound)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                }
                else if(pagen==7)
                {
                    pagen=1;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    if(sound)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                }
                else if(pagen==6)
                {
                    pagen=1;
                    PlaySound(playlist[2],NULL,SND_ASYNC);
                    Sleep(100);
                    if(sound)
                        PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                }
                exiton=0;
            }
            else if(mx>=515&&mx<=715&&my>=200&&my<=300)
            {
                exiton=0;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(pagen==2)
                {

                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    pagen=2;
                    iResumeTimer(0);
                    iResumeTimer(1);iResumeTimer(2);
                    resume=1;
                    if(level1)
                        level1pic=1;
                    if(level2)
                        level2pic=1;
                }

            }
        }

    }
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    int i;
	if(pagen == 4)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(tempplayername,playername);
			//printf("%s\n", tempplayername);
			for(i = 0; i < len; i++)
				playername[i] = 0;
			len = 0;
		}
		else
		{
		    if(key != 8)
            {
                playername[len] = key;
                len++;
            }
            else
            {
                len--;
                playername[len] = '\0';
            }
		}
	}
    else
    {
        if(key == 'p'||key == 'P')
        {
            //do something with 'q'
            pause=1;
            PlaySound(playlist[2],NULL,SND_ASYNC);
            iPauseTimer(0);
            iPauseTimer(1);
            iPauseTimer(2);
        }
        if(key == 'r'||key == 'R')
        {
            iResumeTimer(0);
            iResumeTimer(1);iResumeTimer(2);
            pause=0;
            PlaySound(playlist[2],NULL,SND_ASYNC);
            Sleep(100);
            if(sound)
            {
                if(pagen==0)
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                if(pagen==1)
                    PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                if(pagen==2)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                if(pagen==3)
                    PlaySound(playlist[4],NULL,SND_ASYNC);
            }


        }
        if(key == 'a'||key == 'A')
        {
            if(sound)
            {
                sound=0;
                PlaySound(0,0,0);
            }
            else
            {
                sound=1;
                if(pagen==0)
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                else if(pagen==1)
                    PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                else if(pagen==2)
                {
                    if(ghostmode!=frightened)
                         PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    else
                         PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);

                }

            }
        }
        if(key== '\r')
        {
            pagen=1;
            PlaySound(playlist[2],NULL,SND_ASYNC);
            Sleep(100);
            if(sound)
                PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
        }
        if(key==27)
        {
            if(pagen==2)
            {
                save();
                pagen=1;
                iPauseTimer(0);
                iPauseTimer(1);iPauseTimer(2);
                resume=0;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
                //printf("save %d %d\n",level1pic,level2pic);
            }
            else if(pagen==1)
            {
                pagen=0;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
            }
            else if(pagen==5)
            {
                pagen=1;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
            }
            else if(pagen==7)
            {
                pagen=1;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[3],NULL,SND_LOOP|SND_ASYNC);
            }

        }

    }

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
	    save();
		exit(0);

	}
	if(key == GLUT_KEY_LEFT)
    {
        if(((int)cy-cy==0)&&block[(int)(cy)-1][(int)(cx-0.5)-1]==0)
            direction=0;
        else if(fabs((int)cy-cy)==0.5)
        {
            if(direction==2&&block[(int)ceil(cy)-1][(int)(cx-0.5)-1]==0)
                direction=0,cy+=0.5;
            else if(direction==3&&block[(int)(cy)-1][(int)(cx-0.5)-1]==0)
                direction=0,cy-=0.5;
        }
    }
    if(key == GLUT_KEY_RIGHT)
    {

        if(((int)cy-cy==0)&&block[(int)ceil(cy)-1][(int)ceil(cx+0.5)-1]==0)
            direction=1;
        else if(fabs((int)cy-cy)==0.5)
        {
            if(direction==2&&block[(int)ceil(cy)-1][(int)ceil(cx+0.5)-1]==0)
                direction=1,cy+=0.5;
            else if(direction==3&&block[(int)(cy)-1][(int)ceil(cx+0.5)-1]==0)
                direction=1,cy-=0.5;
        }
    }
    if(key == GLUT_KEY_UP)
    {
        if(((int)cx-cx==0)&&block[(int)ceil(cy+0.5)-1][(int)ceil(cx)-1]==0)
            direction=2;
        else if(fabs((int)cx-cx)==0.5)
        {
            if(direction==0&&block[(int)ceil(cy+0.5)-1][(int)(cx)-1]==0)
                direction=2,cx-=0.5;
            else if(direction==1&&block[(int)ceil(cy+0.5)-1][(int)ceil(cx)-1]==0)
                direction=2,cx+=0.5;

        }

    }
    if(key == GLUT_KEY_DOWN)
    {
        if(((int)cx-cx==0)&&block[(int)(cy-0.5)-1][(int)ceil(cx)-1]==0)
            direction=3;
        else if(fabs((int)cx-cx)==0.5)
        {
            if(direction==0&&block[(int)(cy-0.5)-1][(int)(cx)-1]==0)
                direction=3,cx-=0.5;
            else if(direction==1&&block[(int)(cy-0.5)-1][(int)ceil(cx)-1]==0)
                direction=3,cx+=0.5;

        }
    }

	//place your codes for other keys here
}

void change()
{


    pc++;
    if(pc==12)
        intro=0;
    if(pagen==2&&!pause)
    {
        int d=0,h=0,l=0,o=0;
        ti++;
        for(i=1;i<=30;i++){
            for(j=1;j<=40;j++)
            {
                //printf("%d ",dot[i-1][j-1]);
               if(dot[i-1][j-1]==0)
                {
                    d=1;
                    break;
                }
            }
            //printf("\n");
        }
        //printf("\n\n");
        if(d==0)
        {
            if(level2pic)
            {
                temppoint=point,tempti=ti,pagen=3,point=0,PlaySound(playlist[4],NULL,SND_ASYNC);
            }
            else if(level1pic)
            {
                level2pic=1;
                level1pic=0;
                tempsound=sound;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                if(sound)
                    PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        block[i-1][j-1]=tempblock2[i-1][j-1];
                    }
                for(i=1;i<=30;i++)
                    for(j=1;j<=40;j++)
                    {
                        dot[i-1][j-1]=tempdot2[i-1][j-1];

                    }
                h=point;
                l=lifeline;
                o=ti;
                newgame();
                sound=tempsound;
                point=h;
                lifeline=l;
                ti=o;;
            }
        }



        /*if(d==0)
            printf("d=0\n");
        else if(d==1)
            printf("d=1\n");
            */
    }
    if(pagen==0)
        text++;

    if(pause)
        timer++;
}

void playerchange()
{

    if(direction==1&&pagen==2&&!pause)
    {
        t=temp;
        if(cx==40)
            cx=0;
        else if(cx<40)
        {
            if(block[(int)ceil(cy)-1][(int)ceil(cx+0.5)-1]==0&&((int)cy-cy)==0)
            {
                cx+=.5;
                if(dot[(int)ceil(cy)-1][(int)ceil(cx)-1]==0){
                    point+=10;
                    Beep(400,100);
                    i=(int)ceil(cy);
                    j=(int)ceil(cx);
                    if(((i==2&&j==2)||(i==2&&j==39)||(i==29&&j==39)||(i==29&&j==2)))
                    {
                        ghostmode=frightened,frightenedcount=0,eatenr=0,eatenv=0,eateno=0,eateng=0,ghosto=0,fireball=0;
                        if(sound)
                            PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==13&&j==2)||(i==13&&j==39))
                    {
                        thundredcount=1;
                        thundredx=j;
                        thundredy=i;
                        extra++;
                        point+=190;
                        win+=190;
                        PlaySound("eatfruit.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==18&&j==2)||(i==18&&j==39))
                    {
                        invisiblemode=1,invisiblemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==9&&j==10)||(i==9&&j==31))
                    {
                        pauseghost=1,pauseghostcount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==22&&j==10)||(i==22&&j==31))
                    {
                        increasemode=1,increasemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                }
                dot[(int)ceil(cy)-1][(int)ceil(cx)-1]=1;
                playicon=1;
            }
            temp++;
        }
    }
    else if(direction==0&&pagen==2&&!pause)
    {
        t=temp;
        if(cx==1)
            cx=40;
        else if(cx>0)
        {
            //printf("%lf %lf\n",cx,cy);

            if(block[(int)ceil(cy)-1][(int)(cx-0.5)-1]==0&&((int)cy-cy)==0)
            {
                cx-=.5;
                if(dot[(int)ceil(cy)-1][(int)ceil(cx)-1]==0){
                    point+=10;
                    Beep(400,100);
                    i=(int)ceil(cy);
                    j=(int)ceil(cx);
                    if(((i==2&&j==2)||(i==2&&j==39)||(i==29&&j==39)||(i==29&&j==2)))
                    {
                        ghostmode=frightened,frightenedcount=0,eatenr=0,eatenv=0,eateno=0,eateng=0,ghosto=0,fireball=0;
                        if(sound)
                            PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==13&&j==2)||(i==13&&j==39))
                    {
                        thundredcount=1;
                        thundredx=j;
                        thundredy=i;
                        extra++;
                        point+=190;
                        win+=190;
                        PlaySound("eatfruit.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==18&&j==2)||(i==18&&j==39))
                    {
                        invisiblemode=1,invisiblemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==9&&j==10)||(i==9&&j==31))
                    {
                        pauseghost=1,pauseghostcount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==22&&j==10)||(i==22&&j==31))
                    {
                        increasemode=1,increasemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }

                }
                dot[(int)ceil(cy)-1][(int)ceil(cx)-1]=1;
                playicon=0;

            }
            temp++;
        }
    }
    else if(direction==2&&pagen==2&&!pause)
    {
        t=temp;
        if(cy<30)
        {
            if(block[(int)ceil(cy+0.5)-1][(int)ceil(cx)-1]==0&&((int)cx-cx)==0)
            {
                cy+=0.5;
                if(dot[(int)ceil(cy)-1][(int)ceil(cx)-1]==0){
                    point+=10;
                    Beep(400,100);
                    i=(int)ceil(cy);
                    j=(int)ceil(cx);
                    if(((i==2&&j==2)||(i==2&&j==39)||(i==29&&j==39)||(i==29&&j==2)))
                    {
                        ghostmode=frightened,frightenedcount=0,eatenr=0,eatenv=0,eateno=0,eateng=0,ghosto=0,fireball=0;
                        if(sound)
                            PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==13&&j==2)||(i==13&&j==39))
                    {
                        thundredcount=1;
                        thundredx=j;
                        thundredy=i;
                        extra++;
                        point+=190;
                        win+=190;
                        PlaySound("eatfruit.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==18&&j==2)||(i==18&&j==39))
                    {
                        invisiblemode=1,invisiblemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==9&&j==10)||(i==9&&j==31))
                    {
                        pauseghost=1,pauseghostcount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==22&&j==10)||(i==22&&j==31))
                    {
                        increasemode=1,increasemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                }
                dot[(int)ceil(cy)-1][(int)ceil(cx)-1]=1;
                playicon=2;
            }
            temp++;
        }
    }
    else if(direction==3&&pagen==2&&!pause)
    {
        t=temp;
        if(cy>0)
        {
            if(block[(int)(cy-0.5)-1][(int)(cx)-1]==0&&((int)cx-cx)==0)
            {
                cy-=.5;
                if(dot[(int)ceil(cy)-1][(int)ceil(cx)-1]==0){
                    point+=10;
                    Beep(400,100);
                    i=(int)ceil(cy);
                    j=(int)ceil(cx);
                    if(((i==2&&j==2)||(i==2&&j==39)||(i==29&&j==39)||(i==29&&j==2)))
                    {
                        ghostmode=frightened,frightenedcount=0,eatenr=0,eatenv=0,eateno=0,eateng=0,ghosto=0,fireball=0;
                        if(sound)
                            PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==13&&j==2)||(i==13&&j==39))
                    {
                        thundredcount=1;
                        thundredx=j;
                        thundredy=i;
                        extra++;
                        point+=190;
                        win+=190;
                        PlaySound("eatfruit.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==18&&j==2)||(i==18&&j==39))
                    {
                        invisiblemode=1,invisiblemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==9&&j==10)||(i==9&&j==31))
                    {
                        pauseghost=1,pauseghostcount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                    if((i==22&&j==10)||(i==22&&j==31))
                    {
                        increasemode=1,increasemodecount=0;
                        PlaySound("eat.wav",NULL,SND_ASYNC);
                        Sleep(200);
                        if(sound)
                            if(ghostmode==frightened)
                                PlaySound("fright.wav",NULL,SND_LOOP|SND_ASYNC);
                            else
                                PlaySound(playlist[1],NULL,SND_LOOP|SND_ASYNC);
                    }
                }
                dot[(int)ceil(cy)-1][(int)ceil(cx)-1]=1;
                playicon=3;

            }
            temp++;
        }

    }
}
void fireballmove()
{
    if(fireball)
    {
        if(fireballx==40.5)
            fireball=0;
        if(fireballx==0.5)
            fireball=0;
        if(!fireballleft)
            fireballx+=0.5;
        else
            fireballx-=0.5;
        if(!invisiblemode&&playerloop==0&&pagen!=4&&((fabs(fireballx-cx)<0.5)&&(fabs(firebally-cy)<0.5))&&pagen==2)
        {
            fireball=0;
            ghosto=0;
            pauseghost=0;
            invisiblemode=0;
            increasemode=0;
            pauseghostcount=0;
            invisiblemodecount=0;
            increasemodecount=0;
            lifeline--;
            playerloop=1;
            PlaySound("collision.wav",NULL,SND_ASYNC);
            if(level1pic)
            {
                zxg=16;
                zyg=18;
                zxr=25;
                zyr=23;
                zxv=25;
                zyv=18;
                zxo=16;
                zyo=23;
            }
            if(level2pic)
            {
                zxv=22;
                zyv=22;
                zxg=22;
                zyg=21;
                zxr=21;
                zyr=21;
                zxo=23;
                zyo=21;
            }
            playicon=0;
            direction=1;
            if(lifeline!=0)
            {
                iPauseTimer(0);
                iPauseTimer(1);
            }
            if(lifeline==0)
            {
                temppoint=point;
                tempti=ti;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                pagen=4;
                PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                lifeline=3;
                newgame();
                dx=20,cx=20,cy=2,px=80,py=150;
                playerloop=0;
            }
        }
    }
    if(ghosto)
    {
        if(ghostox==39&&ghostoy==2)
            ghosto=0;
        if(ghostox==39&&ghostoy==29)
            ghosto=0;
        if(ghostoleft)
            pfs(&ghostox,&ghostoy,39,29,&odirection);
        else
            pfs(&ghostox,&ghostoy,39,2,&odirection);
        if(!invisiblemode&&playerloop==0&&pagen!=4&&((fabs(ghostox-cx)<0.5)&&(fabs(ghostoy-cy)<0.5))&&pagen==2)
        {

            fireball=0;
            ghosto=0;
            pauseghost=0;
            invisiblemode=0;
            increasemode=0;
            pauseghostcount=0;
            invisiblemodecount=0;
            increasemodecount=0;
            lifeline--;
            playerloop=1;
            PlaySound("collision.wav",NULL,SND_ASYNC);
            if(level1pic)
            {
                zxg=16;
                zyg=18;
                zxr=25;
                zyr=23;
                zxv=25;
                zyv=18;
                zxo=16;
                zyo=23;
            }
            if(level2pic)
            {
                zxv=22;
                zyv=22;
                zxg=22;
                zyg=21;
                zxr=21;
                zyr=21;
                zxo=23;
                zyo=21;
            }

            playicon=0;
            direction=1;
            if(lifeline!=0)
            {
                iPauseTimer(0);
                iPauseTimer(1);
            }
            if(lifeline==0)
            {
                temppoint=point;
                tempti=ti;
                PlaySound(playlist[2],NULL,SND_ASYNC);
                Sleep(100);
                pagen=4;
                PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
                lifeline=3;
                newgame();
                dx=20,cx=20,cy=2,px=80,py=150;
                playerloop=0;
            }
        }
    }
}
void ghostmove()
{
    ghosttimecontrol++;
    //printf("%d   %d\n",ghosttimecontrol,ti);
}
void frighttimer()
{
    frightenedcount++;
}
int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	iSetTimer(1000,change);
	iSetTimer(1,ghostmove);
	iSetTimer(1000,frighttimer);
	//iSetTimer(350,playerchange);
	//iSetTimer(dx,ghostrmove);
	len = 0;
	mode = 0;
	grdirection=r;
	ggdirection=l;
	gvdirection=u;
	godirection=d;
	odirection=r;
	playername[0]= 0;
	strcpy(left.x,"pacman\\left1.bmp");
    strcpy(left.y,"pacman\\left2.bmp");
    strcpy(left.z,"pacman\\left3.bmp");
    strcpy(left.a,"pacman\\left4.bmp");
    strcpy(left.b,"pacman\\left5.bmp");
    strcpy(right.x,"pacman\\right1.bmp");
    strcpy(right.y,"pacman\\right2.bmp");
    strcpy(right.z,"pacman\\right3.bmp");
    strcpy(right.a,"pacman\\right4.bmp");
    strcpy(right.b,"pacman\\right5.bmp");
    strcpy(up.x,"pacman\\up1.bmp");
    strcpy(up.y,"pacman\\up2.bmp");
    strcpy(up.z,"pacman\\up3.bmp");
    strcpy(up.a,"pacman\\up4.bmp");
    strcpy(up.b,"pacman\\up5.bmp");
    strcpy(down.x,"pacman\\down1.bmp");
    strcpy(down.y,"pacman\\down2.bmp");
    strcpy(down.z,"pacman\\down3.bmp");
    strcpy(down.a,"pacman\\down4.bmp");
    strcpy(down.b,"pacman\\down5.bmp");
	if(sound)
    {
        PlaySound(playlist[0],NULL,SND_LOOP|SND_ASYNC);
    }
    /*for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            tempblock[i-1][j-1]=block[i-1][j-1];
        }
    for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            tempdot[i-1][j-1]=dot[i-1][j-1];
        }
    win--;
    win=win*10;
    */
    for(i=1;ghostgx[i-1]!=0;i++)
    {
        ghostgxlength++;
    }
    for(i=1;ghostgx1[i-1]!=0;i++)
    {
        ghostgx1length++;
    }
    for(i=1;ghostgx2[i-1]!=0;i++)
    {
        ghostgx2length++;
    }
    for(i=1;ghostgx3[i-1]!=0;i++)
    {
        ghostgx3length++;
    }
    //printf("%d",win);
	iInitializeNew(width, height, "Pacman");
	return 0;
}
void save()
{
    fp=fopen("save.txt","w");
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n",newgameselect,resumeselect,reloadselect,highscoreselect,helpselect,exitselect);
    fprintf(fp,"%d\n%d\n",tempcx,tempcy);
    fprintf(fp,"%d\n",dx);
    fprintf(fp,"%lf\n%lf\n",cx,cy);
    fprintf(fp,"%d\n%d\n",px,py);
    fprintf(fp,"%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n",zxg,zyg,zxr,zyr,zxv,zyv,zxo,zyo);
    fprintf(fp,"%d\n",ti);
    fprintf(fp,"%lf\n",extra);
    fprintf(fp,"%d\n",point);
    fprintf(fp,"%d\n%d\n%d\n%d\n",eatenr,eateng,eateno,eatenv);
    fprintf(fp,"%d\n",frightenedcount);
	fprintf(fp,"%d\n%d\n",hundredcount,thundredcount);
    fprintf(fp,"%d\n",ghostmode);
    for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            fprintf(fp,"%d\n",block[i-1][j-1]);
        }
    for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            fprintf(fp,"%d\n",dot[i-1][j-1]);
        }
    fprintf(fp,"%lld\n",text);
    fprintf(fp,"%lld\n",ghosttimecontrol);
    fprintf(fp,"%d\n",grdirection);
	fprintf(fp,"%d\n",ggdirection);
	fprintf(fp,"%d\n",gvdirection);
	fprintf(fp,"%d\n",godirection);
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",lifeline,point,direction,playicon,temp,stand,c,sound,ti,pagen3count);
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n",pause,timer,len,mode,previousx,previousy);
    fprintf(fp,"%lld\n",mukh);
    fprintf(fp,"%lld\n%lld\n%lld\n%lld\n",ghostrmukh,ghostvmukh,ghostomukh,ghostgmukh);
    fprintf(fp,"%d\n",stand);
    fprintf(fp,"%d\n",fireball);
    fprintf(fp,"%lf\n%lf\n",fireballx,firebally);
    fprintf(fp,"%d\n",fireballleft);
    fprintf(fp,"%d\n",ghosto);
    fprintf(fp,"%lf\n%lf\n",ghostox,ghostoy);
    fprintf(fp,"%d\n",ghostoleft);
    fprintf(fp,"%d\n",odirection);
    fprintf(fp,"%lld\n",ghostomukh2);
    fprintf(fp,"%d\n%d\n%d\n%d\n",ghostoalive,ghostgalive,ghostvalive,ghostralive);

    fprintf(fp,"%lld\n",ghostallmukh);
    fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n",invisiblemode,pauseghost,increasemode,invisiblemodecount,pauseghostcount,increasemodecount);

    fprintf(fp,"%d\n%d\n",level1pic,level2pic);
    fprintf(fp,"%lld\n",playerloop);
    fprintf(fp,"%d\n",win);
    //fprintf(fp,"%d\n%d\n%d\n",exiton,yeson,noon);
    //printf("%d   %d\n",level1pic,level2pic);

    fclose(fp);
}

void reload()
{
    fp=fopen("save.txt","r");
    fscanf(fp,"%d%d%d%d%d%d",&newgameselect,&resumeselect,&reloadselect,&highscoreselect,&helpselect,&exitselect);
    fscanf(fp,"%d%d",&tempcx,&tempcy);
    fscanf(fp,"%d",&dx);
    fscanf(fp,"%lf%lf",&cx,&cy);
    fscanf(fp,"%d%d",&px,&py);
    fscanf(fp,"%lf%lf%lf%lf%lf%lf%lf%lf",&zxg,&zyg,&zxr,&zyr,&zxv,&zyv,&zxo,&zyo);
    fscanf(fp,"%d",&ti);
    fscanf(fp,"%lf",&extra);
    fscanf(fp,"%d",&point);
    fscanf(fp,"%d%d%d%d",&eatenr,&eateng,&eateno,&eatenv);
    fscanf(fp,"%d",&frightenedcount);
	fscanf(fp,"%d%d",&hundredcount,&thundredcount);
    fscanf(fp,"%d",&ghostmode);
    for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            fscanf(fp,"%d",&block[i-1][j-1]);
        }
    for(i=1;i<=30;i++)
        for(j=1;j<=40;j++)
        {
            fscanf(fp,"%d",&dot[i-1][j-1]);
        }
    fscanf(fp,"%lld",&text);
    fscanf(fp,"%lld",&ghosttimecontrol);
    fscanf(fp,"%d",&grdirection);
	fscanf(fp,"%d",&ggdirection);
	fscanf(fp,"%d",&gvdirection);
	fscanf(fp,"%d",&godirection);
    fscanf(fp,"%d%d%d%d%d%d%d%d%d%d",&lifeline,&point,&direction,&playicon,&temp,&stand,&c,&sound,&ti,&pagen3count);
    fscanf(fp,"%d%d%d%d%d%d",&pause,&timer,&len,&mode,&previousx,&previousy);
    fscanf(fp,"%lld",&mukh);
    fscanf(fp,"%lld%lld%lld%lld",&ghostrmukh,&ghostvmukh,&ghostomukh,&ghostgmukh);
    fscanf(fp,"%d",&stand);
    fscanf(fp,"%d",&fireball);
    fscanf(fp,"%lf%lf",&fireballx,&firebally);
    fscanf(fp,"%d",&fireballleft);
    fscanf(fp,"%d",&ghosto);
    fscanf(fp,"%lf%lf",&ghostox,&ghostoy);
    fscanf(fp,"%d",&ghostoleft);
    fscanf(fp,"%d",&odirection);
    fscanf(fp,"%lld\n",&ghostomukh2);
    fscanf(fp,"%d\n%d\n%d\n%d\n",&ghostoalive,&ghostgalive,&ghostvalive,&ghostralive);
    fscanf(fp,"%lld\n",&ghostallmukh);
    fscanf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n",&invisiblemode,&pauseghost,&increasemode,&invisiblemodecount,&pauseghostcount,&increasemodecount);
    fscanf(fp,"%d%d",&level1pic,&level2pic);
    fscanf(fp,"%lld",&playerloop);
    fscanf(fp,"%d",&win);
    printf("%d\n%d\n",point,win);
    //fscanf(fp,"%d%d%d",&exiton,&yeson,&noon);
    //printf("%d   %d\n",level1pic,level2pic);

    fclose(fp);
    if(lifeline==0)
    {
        newgame();
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                block[i-1][j-1]=tempblock[i-1][j-1];
            }
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                dot[i-1][j-1]=tempdot[i-1][j-1];

            }
    }
    int d=0;
    for(j=1;j<=40;j++)
    {
        if(dot[i-1][j-1]==0)
        {
            d=1;
            break;
        }

    }
    if(d==0)
    {
        newgame();
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                block[i-1][j-1]=tempblock[i-1][j-1];
            }
        for(i=1;i<=30;i++)
            for(j=1;j<=40;j++)
            {
                dot[i-1][j-1]=tempdot[i-1][j-1];

            }
    }
}

void newgame()
{
    tempcx=0,tempcy=0;
    newgameselect=0,resumeselect=0,reloadselect=0,highscoreselect=0,helpselect=0,exitselect=0;
    dx=20,cx=20,cy=2,px=80,py=150;
    if(level1pic)
    {
        zxg=16;
        zyg=18;
        zxr=25;
        zyr=23;
        zxv=25;
        zyv=18;
        zxo=16;
        zyo=23;
    }
    if(level2pic)
    {
        zxv=22;
        zyv=22;
        zxg=22;
        zyg=21;
        zxr=21;
        zyr=21;
        zxo=23;
        zyo=21;
    }

    ti=0;
    extra=0;
    point=0;
    eatenr=0,eateng=0,eateno=0,eatenv=0;
    frightenedcount=0;
	hundredcount=0,thundredcount=0;
    ghostmode=chase;


    text=0;
    ghosttimecontrol=0;
    grdirection=r;
	ggdirection=l;
	gvdirection=u;
	godirection=d;
    lifeline=3,point=0,direction=1,playicon=0,temp=0,stand=1,t,c=0,sound=1,ti=0,pagen3count=0;
    pause=0,timer=0,len=0,mode=0,previousx=0,previousy=0,previousx1=0,previousy1=0,previousx2=0,previousy2=0,previousx3=0,previousy3=0;
    mukh=0;
    ghostrmukh=0,ghostvmukh=0,ghostomukh=0,ghostgmukh=0;
    stand=0;
    fireball=0;
    fireballx=0,firebally=0;
    fireballleft=0;
    ghosto=0;
    ghostox=0,ghostoy=0;
    ghostoleft=0;
    odirection=r;
    ghostomukh2=0;
    ghostoalive=0,ghostgalive=0,ghostvalive=0,ghostralive=0;
    ghostallmukh=0;
    invisiblemode=0,pauseghost=0,increasemode=0,invisiblemodecount=0,pauseghostcount=0,increasemodecount=0;
    playerloop=0;
    exiton=0,yeson=0,noon=0;
}
void pfs(double *ghostx,double *ghosty, double destinationx, double destinationy,enum direct *gdir)
{
    double dr,dl,du,dd;
    double dx=0.25;
    double zx,zy,cx,cy;
    enum direct gdirection;
    zx=*(ghostx);
    zy=*(ghosty);
    cx=destinationx;
    cy=destinationy;
    gdirection=*(gdir);
    dl=dist(zx-dx,zy,cx,cy);
    dr=dist(zx+dx,zy,cx,cy);
    du=dist(zx,zy+dx,cx,cy);
    dd=dist(zx,zy-dx,cx,cy);
    if(gdirection==r)
    {
        if(((int)zx-zx)!=0)
        {
            if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0)
                zx+=dx,gdirection=r;
            else
                gdirection=l;

        }
        else
        {
            if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                if(mini(mini(dr,du),dd)==dr)
                    zx+=dx,gdirection=r;
                else if(mini(mini(dr,du),dd)==du)
                    zy+=dx,gdirection=u;
                else if(mini(mini(dr,du),dd)==dd)
                    zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                if(mini(dr,du)==dr)
                    zx+=dx,gdirection=r;
                else
                    zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                if(mini(dr,dd)==dr)
                    zx+=dx,gdirection=r;
                else
                    zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                zx+=dx,gdirection=r;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                if(mini(dd,du)==dd)
                    zy-=dx,gdirection=d;
                else
                    zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)
            {
                zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                gdirection=l;
            }
            else
            {
                gdirection=l;

            }
        }
    }
    else if(gdirection==l)
    {
        if(((int)zx-zx)!=0)
        {
            if(block[(int)zy-1][(int)(zx-dx)-1]==0)
                zx-=dx,gdirection=l;
            else
                gdirection=r;
        }
        else
        {
            if(block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                if(mini(mini(dl,du),dd)==dl)
                    zx-=dx,gdirection=l;
                else if(mini(mini(dl,du),dd)==du)
                    zy+=dx,gdirection=u;
                else if(mini(mini(dl,du),dd)==dd)
                    zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                if(mini(dl,du)==dl)
                    zx-=dx,gdirection=l;
                else
                    zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                if(mini(dl,dd)==dl)
                    zx-=dx,gdirection=l;
                else
                    zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                if(mini(dd,du)==dd)
                    zy-=dx,gdirection=d;
                else
                    zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)

            {
                zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)

            {
                gdirection=r;
            }
            else
            {
                gdirection=r;

            }
        }

    }
    else if(gdirection==d)
    {
        if(((int)zy-zy)!=0)
        {
            if(block[(int)(zy-dx)-1][(int)(zx)-1]==0)
                zy-=dx,gdirection=d;
            else
                gdirection=u;

        }
        else
        {
            if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                if(mini(mini(dr,dl),dd)==dd)
                    zy-=dx,gdirection=d;
                else if(mini(mini(dr,dl),dd)==dl)
                    zx-=dx,gdirection=l;
                else if(mini(mini(dr,dl),dd)==dr)
                    zx+=dx,gdirection=r;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)
            {
                if(mini(dr,dl)==dr)
                    zx+=dx,gdirection=r;
                else
                    zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                if(mini(dd,dr)==dd)
                    zy-=dx,gdirection=d;
                else
                    zx+=dx,gdirection=r;

            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)
            {
                zx+=dx,gdirection=r;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                if(mini(dd,dl)==dd)
                    zy-=dx,gdirection=d;
                else
                    zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==0&&block[(int)(zy-dx)-1][(int)zx-1]==1)
            {
                zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==0)
            {
                zy-=dx,gdirection=d;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==1&&block[(int)(zy-dx)-1][(int)zx-1]==1)
            {
                gdirection=u;
            }
            else
            {
                gdirection=u;

            }
        }
    }
    else if(gdirection==u)
    {
        if(((int)zy-zy)!=0)
        {
            if(block[(int)ceil(zy+dx)-1][(int)(zx)-1]==0)
                zy+=dx,gdirection=u;
            else
                gdirection=d;

        }
        else
        {
            if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==0)
            {
                if(mini(mini(dr,du),dl)==du)
                    zy+=dx,gdirection=u;
                else if(mini(mini(dr,du),dl)==dr)
                    zx+=dx,gdirection=r;
                else if(mini(mini(dr,du),dl)==dl)
                    zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==1)
            {
                if(mini(dr,du)==du)
                    zy+=dx,gdirection=u;
                else
                    zx+=dx,gdirection=r;

            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==0)
            {
                if(mini(dr,dl)==dr)
                    zx+=dx,gdirection=r;
                else
                    zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==0&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==1)
            {
                zx+=dx,gdirection=r;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==0)
            {
                if(mini(du,dl)==du)
                    zy+=dx,gdirection=u;
                else
                    zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==0&&block[(int)zy-1][(int)(zx-dx)-1]==1)
            {
                zy+=dx,gdirection=u;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==0)
            {
                zx-=dx,gdirection=l;
            }
            else if(block[(int)zy-1][(int)ceil(zx+dx)-1]==1&&block[(int)ceil(zy+dx)-1][(int)zx-1]==1&&block[(int)zy-1][(int)(zx-dx)-1]==1)
            {
                gdirection=d;
            }
            else
            {
                gdirection=d;

            }
        }
    }
    *(ghostx)=zx;
    *(ghosty)=zy;
    *(gdir)=gdirection;
}
