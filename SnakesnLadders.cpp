#include <graphics.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
using namespace std;

int x_marker1, y_marker1; //coordinates of marker1
int x_marker2, y_marker2; //coordinates of marker2

int c1, c2;               // for direction of marker

boolean just_moved_up1, just_moved_up2;
boolean game_over;

int player_won;
int num1, num2;  //number on dice

void keep_marker1();
void keep_marker2();
void display();
void snakes();
void ladders();

void board()
{
    int x = 0, y = 0, count = 0;

    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 16);
    setfillstyle(10, BLUE);
    //arc(275, 500, 270, 80, 100);
    //arc(275, 515, 270, 90, 85);
    setcolor(CYAN);
    setlinestyle(SOLID_FILL, 0, 4);

    rectangle(50, 50, 750, 750);
    floodfill(200, 200, CYAN);

    int x1 = 50, x2 = 750;
    y = 120;

    setcolor(LIGHTGRAY);

    while(count < 10)
    {
        line(x1, y, x2, y);
        line(y, x1, y, x2);
        y += 70;
        count++;
    }

    outtextxy(78,710," 1              2               3                 4                5               6                 7                8                9               10");
    outtextxy(78,640,"20            19             18               17              16             15               14              13              12              11");
    outtextxy(78,570,"21            22             23               24              25             26               27              28              29              30");
    outtextxy(78,500,"40            39             38               37              36             35               34              33              32              31");
    outtextxy(78,430,"41            42             43               44              45             46               47              48              49              50");
    outtextxy(78,360,"60            59             58               57              56             55               54              53              52              51");
    outtextxy(78,290,"61            62             63               64              65             66               67              68              69              70");
    outtextxy(78,220,"80            79             78               77              76             75               74              73              72              71");
    outtextxy(78,150,"81            82             83               84              85             86               87              88              89              90");
    outtextxy(78,80,"100           99              98              97              96              95              94              93              92              91");


}


int check_snake1()
{
    setcolor(GREEN);

    if(x_marker1 == 223 && y_marker1 == 70) // 98 - 85
    {
        x_marker1 = 363;
        y_marker1 = 140;
        c1 = 1;


        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 1 falls to 85");
    }

    else if(x_marker1 == 433 && y_marker1 == 70) // 95 - 76
    {
        x_marker1 = 363;
        y_marker1 = 210;
        c1 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 1 falls to 76");
    }

    else if(x_marker1 == 293 && y_marker1 == 140) // 84 - 18
    {
        x_marker1 = 223;
        y_marker1 = 630;
        c1 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 1 falls to 18");
    }

    else if(x_marker1 == 363 && y_marker1 == 280) // 65 - 47
    {
        x_marker1 = 503;
        y_marker1 = 420;
        c1 = 1;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 1 falls to 47");
    }

    else if(x_marker1 == 573 && y_marker1 == 420) // 53 - 13
    {
        x_marker1 = 573;
        y_marker1 = 630;
        c1 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 1 falls to 13");
    }

    else
        return 0;

}


int check_ladder1()
{
    if(x_marker1 == 223 && y_marker1 == 700) // 3 - 35
    {
        for(int i = 1; i <= 3; i++)
        {
            x_marker1 += 70;
            y_marker1 -= 70;

            setcolor(GREEN);
            circle(x_marker1, y_marker1, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker2();
        }

        setcolor(GREEN);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 1 moves up to 35");
        c1 = 2;
    }

    else if(x_marker1 == 643 && y_marker1 == 630) // 12 - 47
    {
        for(int i = 1; i <= 3; i++)
        {
            x_marker1 -= 70;
            y_marker1 -= 70;

            if(i == 3)
                x_marker1 += 70;

            setcolor(GREEN);
            circle(x_marker1, y_marker1, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker2();
        }


        c1 = 1;
        setcolor(GREEN);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 1 moves up to 47");
    }

    else if(x_marker1 == 153 && y_marker1 == 560) // 22 - 64
    {
        for(int i = 1; i <= 4; i++)
        {
            x_marker1 += 70;
            y_marker1 -= 70;

            if(i == 2 || i == 4)
                x_marker1 -= 70;

            setcolor(GREEN);
            circle(x_marker1, y_marker1, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker2();
        }

        c1 = 1;
        setcolor(GREEN);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 1 moves up to 64");
    }

    else if(x_marker1 == 363 && y_marker1 == 490) // 36 - 91
    {
        for(int i = 1; i <= 6; i++)
        {
            x_marker1 += 70;
            y_marker1 -= 70;

            if(i == 6)
                x_marker1 -= 70;

            setcolor(GREEN);
            circle(x_marker1, y_marker1, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker2();
        }

        c1 = 2;
        setcolor(GREEN);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 1 moves up to 91");
    }

    else if(x_marker1 == 363 && y_marker1 == 280) // 67 - 86
    {
        for(int i = 1; i <= 2; i++)
        {
            x_marker1 -= 70;
            y_marker1 -= 70;

            if(i == 2)
                x_marker1 += 70;

            setcolor(GREEN);
            circle(x_marker1, y_marker1, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker2();
        }

        c1 = 1;
        setcolor(GREEN);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 1 moves up to 86");
    }

    else
        return 0;

}



int check_snake2()
{
    setcolor(MAGENTA);

    if(x_marker2 == 223 && y_marker2 == 70) // 98 - 85
    {
        x_marker2 = 363;
        y_marker2 = 140;
        c2 = 1;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 2 falls to 85");
    }

    else if(x_marker2 == 433 && y_marker2 == 70) // 95 - 76
    {
        x_marker2 = 363;
        y_marker2 = 210;
        c2 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 2 falls to 76");
    }

    else if(x_marker2 == 293 && y_marker2 == 140) // 84 - 18
    {
        x_marker2 = 223;
        y_marker2 = 630;
        c2 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 2 falls to 18");
    }

    else if(x_marker2 == 363 && y_marker2 == 280) // 65 - 47
    {
        x_marker2 = 503;
        y_marker2 = 420;
        c2 = 1;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 2 falls to 47");
    }

    else if(x_marker2 == 573 && y_marker2 == 420) // 53 - 13
    {
        x_marker2 = 573;
        y_marker2 = 630;
        c2 = 2;

        outtextxy(900, 450, "Oops!");
        outtextxy(900, 485, "Player 2 falls to 13");
    }

    else
        return 0;
}

int check_ladder2()
{
    if(x_marker2 == 223 && y_marker2 == 700) // 3 - 35
    {
        for(int i = 1; i <= 3; i++)
        {
            x_marker2 += 70;
            y_marker2 -= 70;

            setcolor(MAGENTA);
            circle(x_marker2, y_marker2, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker1();
        }

        c2 = 2;
        setcolor(MAGENTA);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 2 moves up to 35");
    }

    else if(x_marker2 == 643 && y_marker2 == 630) // 12 - 47
    {
        for(int i = 1; i <= 3; i++)
        {
            x_marker2 -= 70;
            y_marker2 -= 70;

            if(i == 3)
                x_marker2 += 70;

            setcolor(MAGENTA);
            circle(x_marker2, y_marker2, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker1();
        }

        c2 = 1;
        setcolor(MAGENTA);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 2 moves up to 47");
    }

    else if(x_marker2 == 153 && y_marker2 == 560) // 22 - 64
    {
        for(int i = 1; i <= 4; i++)
        {
            x_marker2 += 70;
            y_marker2 -= 70;

            if(i == 2 || i == 4)
                x_marker2 -= 70;


            setcolor(MAGENTA);
            circle(x_marker2, y_marker2, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker1();
        }

        c2 = 1;
        setcolor(MAGENTA);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 2 moves up to 64");
    }

    else if(x_marker2 == 363 && y_marker2 == 490) // 36 - 91
    {
        for(int i = 1; i <= 6; i++)
        {
            x_marker2 += 70;
            y_marker2 -= 70;

            if(i == 6)
                x_marker2 -= 70;

            setcolor(MAGENTA);
            circle(x_marker2, y_marker2, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker1();
        }

        c2 = 2;
        setcolor(MAGENTA);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 2 moves up to 91");
    }

    else if(x_marker2 == 363 && y_marker2 == 280) // 67 - 86
    {
        for(int i = 1; i <= 2; i++)
        {
            x_marker2 -= 70;
            y_marker2 -= 70;

            if(i == 2)
                x_marker2 += 70;

            setcolor(MAGENTA);
            circle(x_marker2, y_marker2, 10);
            delay(300);
            cleardevice();
            display();
            keep_marker1();
        }

        c2 = 1;
        setcolor(MAGENTA);
        outtextxy(900, 450, "Yay!");
        outtextxy(900, 485, "Player 2 moves up to 86");
    }

    else
        return 0;

}



void marker1()
{
    for(int i = 1; i <= num1; i++)
    {
        //for checking if the marker is in the first or last tiles
        if((c1 >= 1) && ((x_marker1 == 83) || (x_marker1 == 713)) && (just_moved_up1 == false) && (y_marker1 > 70) && !(x_marker1 == 83 && y_marker1 == 140))
        {
                y_marker1 -= 70;
                c1++;
                just_moved_up1 = true;
                continue;
        }
        else if(c1 % 2 != 0 || c1 == 0)
        {
            x_marker1 += 70;     //then marker moves towards right
            just_moved_up1 = false;
        }
        else if(c1 % 2 == 0 && c1 != 0)
        {
            x_marker1 -= 70;     //marker moves towards left
            just_moved_up1 = false;
        }
        else
            exit(1);

    }

    check_snake1();
    check_ladder1();

    if(x_marker1 == 83 && y_marker1 == 70)  // if marker is at 100 then player 1 wins
    {
        game_over = true;
        player_won = 1;
    }

    if(x_marker1 < 83)
        x_marker1 = 83 + (83 - x_marker1);

    setcolor(GREEN);
    circle(x_marker1, y_marker1, 10); //new position of marker
}


void marker2()
{
    for(int i = 1; i <= num2; i++)
    {
        //for checking if the marker is in the first or last tiles
        if((c2 >= 1) && ((x_marker2 == 83) || (x_marker2 == 713)) && (just_moved_up2 == false) && (y_marker2 > 70) && !(x_marker2 == 83 && y_marker2 == 140))
        {
                y_marker2 -= 70;
                c2++;
                just_moved_up2 = true;
                continue;
        }
        else if(c2 % 2 != 0 || c2 == 0)
        {
            x_marker2 += 70;     //then marker moves towards right
            just_moved_up2 = false;
        }
        else if(c2 % 2 == 0 && c2 != 0)
        {
            x_marker2 -= 70;     //marker moves towards left
            just_moved_up2 = false;
        }
        else
            exit(1);


    }

    check_snake2();
    check_ladder2();

    if(x_marker2 == 83 && y_marker2 == 70)  // if marker is at 100 then player 2 wins
    {
        game_over = true;
        player_won = 2;
    }

    if(x_marker2 < 83)
        x_marker2 = 83 + (83 - x_marker2);

    setcolor(MAGENTA);
    circle(x_marker2, y_marker2, 10); //new position of marker
}

void keep_marker1()
{
    setcolor(GREEN);
    setlinestyle(0, 0, 8);
    circle(x_marker1, y_marker1, 10);
}

void keep_marker2()
{
    setcolor(MAGENTA);
    setlinestyle(0, 0, 8);
    circle(x_marker2, y_marker2, 10);
}


void snakes()
{
    //snake 1
    ellipse(243, 510, 270, 70, 60, 115);
    ellipse(274, 516, 244, 70, 60, 120);
    arc(535, 317, 150, 200, 260);
    arc(542, 330, 150, 190, 290);
    int points[8] = { 293, 183, 314, 143, 310, 187};
    drawpoly(3, points);
    circle(308, 170 , 2);

    //snake 2
    arc(255,118,320,0,170);
    arc(265,118,305,0,170);
    line(384,229,361,260);
    line(425,120,429,105);
    line(428,105,435,120);
    line(428,105,429,100);
    circle(430,115,1);

    //snake 3 and 4
    int x,y=10,h=2;
    for(x=100;x<=300;x+=125)
    {
        arc(120+x,110+y,10,85,60);
        arc(258+x,85+y,190,240,80);
        arc(112+x,118+y,10,80,60);
        arc(250+x,93+y,190,290,80);
        arc(275+x,100+y,250,270,70);
        line(250+x,170+y,250+x,165+y);
        line(250+x,165+y,230+x,160+y);
        line(230+x,160+y,218+x,155+y);
        line(130+x,50+y,115+x,47+y);
        line(121+x,59+y,106+x,52+y);
        line(106+x,52+y,114+x,48+y);
        circle(114+x,52+y,1);
        setfillstyle(1,h);
        //floodfill(116+x,52+y,8);
        y+=230; h+=8;
    }


    //snake 5
    ellipse(550, 500, 270, 65, 90, 120);
    ellipse(560, 510, 270, 70, 65, 110);
    int points2[8] = { 580, 405, 570, 380, 605, 400};
    drawpoly(3, points2);
    circle(585, 395, 2);
}


int dice1()
{
    srand(time(NULL));
    int num = (rand() % 6) + 1;

    setcolor(15);
    char arr[3];
    sprintf(arr, "%d",num);
    outtextxy(837, 307, arr);

    return num;

}


int dice2()
{
    srand(time(NULL));
    int num = (rand() % 6) + 1;

    setcolor(15);
    char arr[3];
    sprintf(arr, "%d",num);
    outtextxy(1337, 307, arr);

    return num;
}

void sideboard()
{
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 7);
    outtextxy(800, 40, "SNAKES");
    outtextxy(1100, 90, "n");
    outtextxy(1100, 150, "LADDERS");


    settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
    setlinestyle(0, 0, 3);

    rectangle(800,270,900,370); //dice green
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(811,280, WHITE);
    outtextxy(790, 380, "Player 1");


    rectangle(1300, 270, 1400, 370); //dice magenta
    setfillstyle(SOLID_FILL, MAGENTA);
    floodfill(1333,333, WHITE);
    outtextxy(1290, 380, "Player 2");

    outtextxy(850, 700,"Press space to roll the dice");


}


void ladders()

{
     //ladder 1
     line(200,700,420,530);
     line(230,700,450,530);
     //ladder 2
     line(630,630,490,460);
     line(660,630,520,460);
     //ladder 3
     line(350,490,700,100);
     line(380,490,730,100);
     //ladder 4
     line(490,280,420,170);
     line(520,280,460,170);
     //ladder 5
     line(150,560,280,280);
     line(190,560,320,280);
}

void display()
{

    board();
    sideboard();

    setcolor(RED);          //for the snakes
    setlinestyle(0, 0, 3);
    snakes();


    setcolor(CYAN);         //for the ladders
    setlinestyle(1, 0, 3);
    ladders();

    setcolor(GREEN);        //for the marker
    setlinestyle(0, 0, 8);
}

int main()
{
    int player = 1;
    game_over = false;
    player_won = 0;

    initwindow(1600, 900);
    display();  //drawing the board and everything else

    setcolor(GREEN);
    setlinestyle(0, 0, 8);
    circle(83, 700, 10); //initial position of marker at 1

    x_marker1 = 83, y_marker1 = 700; //starting position of marker1 i.e. 1
    c1 = 0, just_moved_up1 = false;

    setcolor(MAGENTA);
    setlinestyle(0, 0, 8);
    circle(83, 735, 10); //initial position of marker at 1

    x_marker2 = 83, y_marker2 = 700; //starting position of marker2 i.e. 1
    c2 = 0, just_moved_up2 = false;


    num1 = 0, num2 = 0;

    while(num1 != 1 && num2 != 1)    //game starts when a player gets 1
    {
        if(player == 1)
        {
            getch();

            if(GetAsyncKeyState(VK_SPACE))
            {
                cleardevice();
                display();

                setcolor(GREEN);
                setlinestyle(0, 0, 8);
                circle(83, 700, 10);

                num1 = dice1();

            }

            else
                outtextxy(800, 670,"Wrong input. Please try again.");

            player = 2;
        }

        else
        {
           getch();

            if(GetAsyncKeyState(VK_SPACE))
            {
                cleardevice();
                display();

                setcolor(MAGENTA);
                setlinestyle(0, 0, 8);
                circle(83, 700, 10);

                num2 = dice2();
            }


            else
                outtextxy(800, 670,"Wrong input. Please try again.");

            player = 1;
        }


    }

    if(num1 == 1)                           //moving the marker1 for the first time
    {
        x_marker1 += 70;
        cleardevice();
        display();

        setcolor(MAGENTA);
        setlinestyle(0, 0, 8);
        circle(83, 700, 10);

        setcolor(GREEN);
        setlinestyle(0, 0, 8);
        circle(x_marker1, y_marker1, 10);

        ++c1;

        player = 2;

    }

    else                                //moving the marker2 for the first time
    {
        x_marker2 += 70;
        cleardevice();
        display();

        setcolor(GREEN);
        setlinestyle(0, 0, 8);
        circle(83, 700, 10);

        setcolor(MAGENTA);
        setlinestyle(0, 0, 8);
        circle(x_marker2, y_marker2, 10);

        ++c2;

        player = 1;
    }


    int i = 1;

    while(i < 5)
    {

        if(player == 1)   // Turn of 1st player
        {
            getch();

            if(GetAsyncKeyState(VK_SPACE))  //when player presses the space bar
            {
                cleardevice();
                display();

                keep_marker2();

                num1 = dice1();      //roll the dice
                marker1();      //move the marker

                if(num1 == 6)      //if 6 appears then roll the dice again
                    continue;

            }

            else
            {
                outtextxy(800, 670,"Wrong input. Please try again.");
            }

            player = 2;

            if(i == 1)
            {
                c1++;
                i += 2;
            }
        }

        else if(player == 2)  //Turn of 2nd player
        {
            getch();

            if(GetAsyncKeyState(VK_SPACE))  //when player presses the space bar
            {
                cleardevice();
                display();

                keep_marker1();

                num2 = dice2();      //roll the dice
                marker2();           //move the marker

                if(num2 == 6)      //if 6 appears then roll the dice again
                    continue;

            }

            else
            {
                outtextxy(800, 670,"Wrong input. Please try again.");
            }

            player = 1;

            if(i == 1)
            {
                c2++;
                i += 2;
            }
        }

        if(game_over)
            break;

    }

    if(player_won == 1)
        outtextxy(800, 505, " Congratulations! Player 1 wins! ");

    else
        outtextxy(800, 505, "Congratulations! Player 2 wins! ");



    getch();
}
