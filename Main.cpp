#include <graphics.h>
#include<iostream>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
#define PI 3.141592654
using namespace std;

void clearscreen(){
    setcolor(BLACK);
    setfillstyle(1,BLACK);
    bar(0,0,640,480);
}

void intro(){
    int test;
    for(int i=1;i<=720;++i){
        if((i/40)%2==0) setcolor(LIGHTRED);
        else setcolor(WHITE);
        circle(0,240,i);
        circle(640,240,i);
        delay(1);
        if(i>20){
        setcolor(BLACK);
        circle(0,240,i-20);
        circle(640,240,i-20);
        }
    }
    setcolor(LIGHTCYAN);
    settextstyle(6,0,7);
    setlinestyle(2,0,2);
    outtextxy(40,30,"A");
    delay(200);
    outtextxy(105,30,"R");
    delay(200);
    outtextxy(170,30,"C");
    setcolor(YELLOW);
    line(20,20,520,20);
    setcolor(LIGHTCYAN);
    delay(200);
    outtextxy(235,30,"H");
    delay(200);
    outtextxy(305,30,"E");
    delay(200);
    outtextxy(365,30,"R");
    setcolor(YELLOW);
    line(520,20,520,160);
    setcolor(LIGHTCYAN);
    delay(200);
    outtextxy(430,30,"Y");
    delay(200);
    outtextxy(40,90,"G");
    delay(200);
    outtextxy(105,90,"A");
    setcolor(YELLOW);
    line(520,160,20,160);
    setcolor(LIGHTCYAN);
    delay(200);
    outtextxy(170,90,"M");
    delay(200);
    outtextxy(250,90,"E");
    setcolor(YELLOW);
    line(20,20,20,160);
    setcolor(LIGHTCYAN);
    delay(200);
    settextstyle(4,0,2);
    setcolor(WHITE);
    outtextxy(40,300,"Developed By:");
    outtextxy(40,325,"2K18/CO/097 Aryan Rana");
    outtextxy(40,350,"2K18/CO/317 Sanchit Singh");
    delay(1000);
    setcolor(LIGHTGREEN);
    outtextxy(40,400,"Press any key to start");
    cin>>test;
    setlinestyle(0,0,1);
}

void target(int x_target,int y_target){
    setcolor(WHITE);
    ellipse(x_target,y_target,0,360,20,80);
    ellipse(x_target,y_target,0,360,15,60);
    ellipse(x_target,y_target,0,360,10,40);
    ellipse(x_target,y_target,0,360,5,20);
    line(x_target,y_target+80,x_target+15,y_target+80);
    line(x_target,y_target-80,x_target+15,y_target-80);
    ellipse(x_target+15,y_target,-90,90,20,80);
    setfillstyle(1,BLACK);
    floodfill(x_target-17,y_target,WHITE);
    setfillstyle(1,BLUE);
    floodfill(x_target-13,y_target,WHITE);
    setfillstyle(1,RED);
    floodfill(x_target-8,y_target,WHITE);
    setfillstyle(1,YELLOW);
    floodfill(x_target-3,y_target,WHITE);
    setfillstyle(1,LIGHTGRAY);
    floodfill(x_target+25,y_target,WHITE);
}


int calcscore(float y_save,int y_target){
  if(abs(int(y_target)-int(y_save))>80) return -1;
  else return (80-(abs(int(y_target)-int(y_save))));
}

void bow(int x_i, int y_i){
    setcolor(WHITE);
    line(x_i-7,y_i,x_i-43,y_i);
    line(x_i,y_i,x_i-7,y_i+7);
    line(x_i,y_i,x_i-7,y_i-7);
    line(x_i-50,y_i-7,x_i-43,y_i);
    line(x_i-50,y_i+7,x_i-43,y_i);
    ellipse(x_i-30,y_i,-90,90,15,50);
    line(x_i-30,y_i+50,x_i-30,y_i-50);
    line(x_i-7,y_i+7,x_i-7,y_i-7);
    line(x_i-38,y_i,x_i-45,y_i+7);
    line(x_i-38,y_i,x_i-45,y_i-7);
}

char finale(int y_target,float y_save, int score){
    char res[10];
    char ret;
    setcolor(WHITE);
    circle(240,240,50);
    circle(240,240,100);
    circle(240,240,150);
    circle(240,240,200);
    setfillstyle(1,BLACK);
    floodfill(240-175,240,WHITE);
    setfillstyle(1,BLUE);
    floodfill(240-125,240,WHITE);
    setfillstyle(1,RED);
    floodfill(240-75,240,WHITE);
    setfillstyle(1,YELLOW);
    floodfill(240-25,240,WHITE);
    setcolor(GREEN);
    if(score!=-1){
    circle(240,240-int(2.5*(y_save-float(y_target))),10);
    setfillstyle(1,LIGHTGREEN);
    floodfill(240,240-int(2.5*(y_save-float(y_target))),GREEN);
    }
    settextstyle(6,0,4);
    setcolor(WHITE);
    delay(500);
    outtextxy(470,50,"YOUR");
    delay(1000);
    outtextxy(460,100,"SCORE:");
    delay(1000);
    if(score==-1) setcolor(RED);
    else if(score<20) setcolor(LIGHTGRAY);
    else if(score<40) setcolor(LIGHTRED);
    else if(score<60) setcolor(YELLOW);
    else setcolor(LIGHTGREEN);
    if(score==-1) outtextxy(480,180,"MISS");
    else{
        itoa((score*5)/4,res,10);
        outtextxy(510,180,res);
    }
    delay(1000);
    settextstyle(6,0,2);
    setcolor(LIGHTCYAN);
    outtextxy(470,300,"1 to Reset");
    setcolor(LIGHTGREEN);
    outtextxy(505,340,"2 to");
    outtextxy(470,360,"Play Again");
    setcolor(LIGHTRED);
    outtextxy(480,410,"X to Exit");
    cin>>ret;
    return ret;
}
int main()
{
    srand(time(0));
    int gd = DETECT, gm;
    float angle1;
    char choice;
    float power,xi,yi,g=10,y_target,x_target,y_save=-1,intro_flag=0;
    reset:
    xi=rand()%150+70;
    yi=rand()%350+50;
    x_target=rand()%200+400;
    y_target=rand()%300+80;
    reset1:
    initgraph(&gd, &gm, "");
    if(intro_flag==0){
        intro();
        intro_flag=1;
    }
    int score;
    clearscreen();
    bow(xi-3,yi);
    target(x_target,y_target);
    cout<<"Enter power:";
    cin>>power;
    cout<<"Enter angle:";
    cin>>angle1;
    double angle=(PI*angle1)/180;
    float x=xi;
    float y=yi;
    putpixel(xi,yi,WHITE);
    for(float i=0;i<20;i+=0.025){
        if(y>480||x>640) break;
        if(x>=x_target){
            y_save=y;
            break;
        }
        else y_save=y;
        x=power*cos(angle)*i+xi;
        y=yi-(power*sin(angle)*i-0.5*g*i*i);
        setcolor(WHITE);
        circle(x,y,1);
        circle(x,y,2);
        circle(x,y,3);
        circle(x,y,4);
        delay(15);
        setcolor(BLACK);
        circle(x,y,1);
        circle(x,y,2);
        circle(x,y,3);
        circle(x,y,4);
    }
    score=calcscore(y_save,y_target);
    clearscreen();
    choice=finale(y_save,y_target,score);
    if(choice=='1'){
        closegraph();
        cout<<endl;
        goto reset;
    }
    else if(choice=='2'){
        closegraph();
        cout<<endl;
        goto reset1;
    }
    else exit(0);
    getch();
    closegraph();
    return 0;
}
