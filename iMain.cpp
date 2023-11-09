# include "iGraphics.h"

#define screenwidth 1400
#define screenheight 700
#define MarginY 50
#define MarginX 1200
#define totalbricks 50
#define HighScoresLimit 10
#define PerksLimit 12
double BallX = (screenwidth-200)/2.0;
double BallY = MarginY;
int red = 255;
int green = 0;
int blue = 0;
int BallRadius = 10;
double Balldx = 12;
double Balldy = 12;
double Boarddx = 100;
double Boarddy = 20;
double BoardX = BallX - (Boarddx/2.0);
double BoardY = BallY - Boarddy - BallRadius;
bool BallMove = false;
int TimeSecond = 0;
int TimeMinute = 0;
int TimeHour = 0;
char Time[100] = "00 : 00 : 00";
char Score[20] = "0000";
int CurrentScore = 0;
int LifeNumber = 3;
char Life[20] = "Life : 3";
int State = 1;
bool PauseTime = false;
bool GameWin = false;
char EnterName[60] = "";
int EnterNameIndex = 0;
bool GamePlayed = false;
bool GameSaved = false;
bool ShowDialogBox = false;
int DialogBox = 1;
bool NewGamePlayed = false;
bool PlayMusic = true;

typedef struct
{
    int BrickX;
    int BrickY;
    int Brickdx;
    int Brickdy;
    bool showBrick;
    int BrickRed;
    int BrickGreen;
    int BrickBlue;
}BrickStructure;

typedef struct
{
    int ButtonX;
    int ButtonY;
    int Buttondx;
    int Buttondy;
}ButtonStructure;

typedef struct
{
    int GameScore;
    char GameTime[20];
    char GameName[60];
}ScoreTimeName;

typedef struct
{
    int PerkX;
    int PerkY;
    bool ShowPerk;
    int BrickNumber;
}PerkStructure;

typedef struct
{
    int RBallRadius;
    double RBallX;
    double RBallY;
    double RBalldx;
    double RBalldy;
    double RBoarddx;
    double RBoarddy;
    double RBoardX;
    double RBoardY;
    int RBallMove;
    int RCurrentScore;
    int RTimeSecond;
    int RTimeMinute;
    int RTimeHour;
    int RLifeNumber;
    int RPauseTime;
    int RShowBrick[totalbricks];
    int RBrickRed[totalbricks];
    int RBrickGreen[totalbricks];
    int RBrickBlue[totalbricks];
    int RPerk1ShowPerk;
    int RPerk2ShowPerk;
    int RPerk3ShowPerk;
    int RPerk4ShowPerk;
    int RPerk5ShowPerk;
    int RPerk6ShowPerk;
    int RPerk7ShowPerk;
    int RPerk8ShowPerk;
    int RPerk9ShowPerk;
    int RPerk10ShowPerk;
    int RPerk11ShowPerk;
    int RPerk12ShowPerk;
    int RPerk1PerkY;
    int RPerk2PerkY;
    int RPerk3PerkY;
    int RPerk4PerkY;
    int RPerk5PerkY;
    int RPerk6PerkY;
    int RPerk7PerkY;
    int RPerk8PerkY;
    int RPerk9PerkY;
    int RPerk10PerkY;
    int RPerk11PerkY;
    int RPerk12PerkY;
}ResumeGameInfo;

PerkStructure Perk1 , Perk2 , Perk3 , Perk4 , Perk5 , Perk6 , Perk7 , Perk8 , Perk9 , Perk10 , Perk11 ,Perk12;

ScoreTimeName GameHighScores[HighScoresLimit + 2];

BrickStructure bricks[totalbricks];

ButtonStructure NewGame1 , Pause2 , Resume1 , Resume2 , Exit1 , Exit2 , Menu2 , Help1 , HighScores1 , Save3 , DontSave3 , Menu3 , NewGame3 , Exit3 , DBYes1 , DBNo1;

ButtonStructure DBSaveExit2 , DBDontSaveExit2 , DBCancelExit2 , Back4 , Back5;

ResumeGameInfo ResumeGame;

void defineButtons()
{
    NewGame1.ButtonX = 625;
    Resume1.ButtonX = 625;
    HighScores1.ButtonX = 625;
    Help1.ButtonX = 625;
    Exit1.ButtonX = 625;
    NewGame1.ButtonY = 375;
    Resume1.ButtonY = 300;
    HighScores1.ButtonY = 225;
    Help1.ButtonY = 155;
    Exit1.ButtonY = 80;
    NewGame1.Buttondx = 150;
    Resume1.Buttondx = 150;
    HighScores1.Buttondx = 150;
    Help1.Buttondx = 150;
    Exit1.Buttondx = 150;
    NewGame1.Buttondy = 55;
    Resume1.Buttondy = 55;
    HighScores1.Buttondy = 55;
    Help1.Buttondy = 50;
    Exit1.Buttondy = 50;
    Menu2.ButtonX = 1255;
    Pause2.ButtonX = 1255;
    Resume2.ButtonX = 1255;
    Exit2.ButtonX = 1255;
    Menu2.ButtonY = 275;
    Pause2.ButtonY = 175;
    Resume2.ButtonY = 175;
    Exit2.ButtonY = 75;
    Menu2.Buttondx = 100;
    Pause2.Buttondx = 100;
    Resume2.Buttondx = 100;
    Exit2.Buttondx = 100;
    Menu2.Buttondy = 65;
    Pause2.Buttondy = 65;
    Resume2.Buttondy = 65;
    Exit2.Buttondy = 65;
    Save3.ButtonX = 615;
    Save3.ButtonY = 260;
    Save3.Buttondx = 60;
    Save3.Buttondy = 30;
    DontSave3.ButtonX = 730;
    DontSave3.ButtonY = 260;
    DontSave3.Buttondx = 110;
    DontSave3.Buttondy = 30;
    Menu3.ButtonX = 280;
    Menu3.ButtonY = 70;
    Menu3.Buttondx = 100;
    Menu3.Buttondy = 75;
    NewGame3.ButtonX = 645;
    NewGame3.ButtonY = 70;
    NewGame3.Buttondx = 160;
    NewGame3.Buttondy = 75;
    Exit3.ButtonX = 1075;
    Exit3.ButtonY = 70;
    Exit3.Buttondx = 95;
    Exit3.Buttondy = 75;
    DBYes1.ButtonX = 605;
    DBYes1.ButtonY = 325;
    DBYes1.Buttondx = 45;
    DBYes1.Buttondy = 25;
    DBNo1.ButtonX = 725;
    DBNo1.ButtonY = 325;
    DBNo1.Buttondx = 35;
    DBNo1.Buttondy = 25;
    DBSaveExit2.ButtonX = 515;
    DBSaveExit2.ButtonY = 315;
    DBSaveExit2.Buttondx = 110;
    DBSaveExit2.Buttondy = 25;
    DBDontSaveExit2.ButtonX = 645;
    DBDontSaveExit2.ButtonY = 315;
    DBDontSaveExit2.Buttondx = 160;
    DBDontSaveExit2.Buttondy = 25;
    DBCancelExit2.ButtonX = 825;
    DBCancelExit2.ButtonY = 315;
    DBCancelExit2.Buttondx = 105;
    DBCancelExit2.Buttondy = 25;
    Back4.ButtonX = 1250;
    Back4.ButtonY = 50;
    Back4.Buttondx = 100;
    Back4.Buttondy = 50;
    Back5.ButtonX = 1275;
    Back5.ButtonY = 25;
    Back5.Buttondx = 100;
    Back5.Buttondy = 50;
}
void definebricks()
{
    for(int i = 0;i < totalbricks; i++)
    {
        if((i*100+100)%1000 == 0)
        {
            bricks[i].BrickX = 1000;
        }
        else
        {
            bricks[i].BrickX = (i*100+100)%1000;
        }
        bricks[i].BrickY = 600 - 50*(i/10);
        bricks[i].Brickdx = 50;
        bricks[i].Brickdy = 25;
        bricks[i].showBrick = true;
        bricks[i].BrickRed = rand()%255;
        bricks[i].BrickGreen = rand()%255;
        bricks[i].BrickBlue = rand()%255;
    }
}

void DefinePerks()
{
    Perk1.BrickNumber = 4;
    Perk2.BrickNumber = 7;
    Perk3.BrickNumber = 14;
    Perk4.BrickNumber = 16;
    Perk5.BrickNumber = 22;
    Perk6.BrickNumber = 26;
    Perk7.BrickNumber = 32;
    Perk8.BrickNumber = 34;
    Perk9.BrickNumber = 40;
    Perk10.BrickNumber = 42;
    Perk11.BrickNumber = 46;
    Perk12.BrickNumber = 47;
    Perk1.ShowPerk = false;
    Perk2.ShowPerk = false;
    Perk3.ShowPerk = false;
    Perk4.ShowPerk = false;
    Perk5.ShowPerk = false;
    Perk6.ShowPerk = false;
    Perk7.ShowPerk = false;
    Perk8.ShowPerk = false;
    Perk9.ShowPerk = false;
    Perk10.ShowPerk = false;
    Perk11.ShowPerk = false;
    Perk12.ShowPerk = false;
    Perk1.PerkX = bricks[Perk1.BrickNumber].BrickX + 5;
    Perk2.PerkX = bricks[Perk2.BrickNumber].BrickX + 5;
    Perk3.PerkX = bricks[Perk3.BrickNumber].BrickX + 5;
    Perk4.PerkX = bricks[Perk4.BrickNumber].BrickX + 5;
    Perk5.PerkX = bricks[Perk5.BrickNumber].BrickX + 5;
    Perk6.PerkX = bricks[Perk6.BrickNumber].BrickX + 5;
    Perk7.PerkX = bricks[Perk7.BrickNumber].BrickX + 5;
    Perk8.PerkX = bricks[Perk8.BrickNumber].BrickX + 5;
    Perk9.PerkX = bricks[Perk9.BrickNumber].BrickX + 5;
    Perk10.PerkX = bricks[Perk10.BrickNumber].BrickX + 5;
    Perk11.PerkX = bricks[Perk11.BrickNumber].BrickX + 5;
    Perk12.PerkX = bricks[Perk12.BrickNumber].BrickX + 5;
    Perk1.PerkY = bricks[Perk1.BrickNumber].BrickY;
    Perk2.PerkY = bricks[Perk2.BrickNumber].BrickY;
    Perk3.PerkY = bricks[Perk3.BrickNumber].BrickY;
    Perk4.PerkY = bricks[Perk4.BrickNumber].BrickY;
    Perk5.PerkY = bricks[Perk5.BrickNumber].BrickY;
    Perk6.PerkY = bricks[Perk6.BrickNumber].BrickY;
    Perk7.PerkY = bricks[Perk7.BrickNumber].BrickY;
    Perk8.PerkY = bricks[Perk8.BrickNumber].BrickY;
    Perk9.PerkY = bricks[Perk9.BrickNumber].BrickY;
    Perk10.PerkY = bricks[Perk10.BrickNumber].BrickY;
    Perk11.PerkY = bricks[Perk11.BrickNumber].BrickY;
    Perk12.PerkY = bricks[Perk12.BrickNumber].BrickY;
}
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
    //place your drawing codes here
    iClear();
    if(State == 1)
       {
       iShowBMP(0 , 0, "Dx Ball Theme 18.bmp");
       iShowBMP2(500 , 550 , "Dx Ball Theme 20.bmp" , 0);
       red = 255;
       green = 100;
       blue = 0;
       iSetColor(red , green , blue);
       iFilledRectangle(NewGame1.ButtonX , NewGame1.ButtonY , NewGame1.Buttondx , NewGame1.Buttondy);
       iFilledRectangle(Resume1.ButtonX , Resume1.ButtonY , Resume1.Buttondx , Resume1.Buttondy);
       iFilledRectangle(HighScores1.ButtonX , HighScores1.ButtonY , HighScores1.Buttondx , HighScores1.Buttondy);
       iFilledRectangle(Help1.ButtonX , Help1.ButtonY , Help1.Buttondx , Help1.Buttondy);
       iFilledRectangle(Exit1.ButtonX , Exit1.ButtonY , Exit1.Buttondx , Exit1.Buttondy);
       red = 255;
       green = 255;
       blue = 255;
       iSetColor(red , green , blue);
       iText(650 , 400 , "New Game" , GLUT_BITMAP_TIMES_ROMAN_24);
       iText(660 , 325 , "Resume" , GLUT_BITMAP_TIMES_ROMAN_24);
       iText(640 , 250 , "High Scores" , GLUT_BITMAP_TIMES_ROMAN_24);
       iText(680 , 175 , "Help" , GLUT_BITMAP_TIMES_ROMAN_24);
       iText(680 , 100 , "Exit" , GLUT_BITMAP_TIMES_ROMAN_24);
       if(ShowDialogBox && DialogBox == 1)
       {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(540 , 300 , 300 , 120);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBYes1.ButtonX , DBYes1.ButtonY , DBYes1.Buttondx , DBYes1.Buttondy);
           iFilledRectangle(DBNo1.ButtonX , DBNo1.ButtonY , DBNo1.Buttondx , DBNo1.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(570 , 380 , "Are you sure you want to exit?" , GLUT_BITMAP_HELVETICA_18);
           iText(610 , 330 , "Yes" , GLUT_BITMAP_HELVETICA_18);
           iText(730 , 330 , "No" , GLUT_BITMAP_HELVETICA_18);
       }
       if(ShowDialogBox && DialogBox == 2)
       {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(480 , 300 , 500 , 125);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBSaveExit2.ButtonX , DBSaveExit2.ButtonY , DBSaveExit2.Buttondx , DBSaveExit2.Buttondy);
           iFilledRectangle(DBDontSaveExit2.ButtonX , DBDontSaveExit2.ButtonY , DBDontSaveExit2.Buttondx , DBDontSaveExit2.Buttondy);
           iFilledRectangle(DBCancelExit2.ButtonX , DBCancelExit2.ButtonY , DBCancelExit2.Buttondx , DBCancelExit2.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(500 , 400 , "If you want to save the game,please enter your name :" , GLUT_BITMAP_HELVETICA_18);
           iSetColor(255 , 255 , 255);
           iFilledRectangle(500 , 350 , 300 , 30);
           iSetColor(0 , 0 , 0);
           iText(505 , 360 , EnterName , GLUT_BITMAP_HELVETICA_18);
           iText(520 , 320 , "Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(650 , 320 , "Don't Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(830 , 320 , "Cancel Exit" , GLUT_BITMAP_HELVETICA_18);
       }
    }
    if(State == 2)
    {
    iShowBMP(0 , 0 , "Dx Ball Theme 17.bmp");
    iShowBMP(MarginX , 0 , "Dx Ball Theme 7.bmp");
    blue = 255;
    red = 255;
    green = 255;
    iSetColor(red ,green ,blue);
    iFilledCircle( BallX, BallY, BallRadius);
    red = 100;
    green = 26;
    blue = 13;
    iSetColor(red ,green ,blue);
    iFilledRectangle(BoardX , BoardY , Boarddx , Boarddy);
    red = 0;
    green = 100;
    blue = 255;
    iSetColor(red , green , blue);
    iFilledRectangle(1200 , 575 , 200 , 75);
    iFilledRectangle(1200 , 475 , 200 , 75);
    iFilledRectangle(1200 , 375 , 200 , 75);
    red = 255;
    green = 100;
    blue = 0;
    iSetColor(red , green , blue);
    iFilledRectangle(Menu2.ButtonX , Menu2.ButtonY , Menu2.Buttondx , Menu2.Buttondy);
    iFilledRectangle(Exit2.ButtonX , Exit2.ButtonY , Exit2.Buttondx , Exit2.Buttondy);
    if(!PauseTime)
    {
       iFilledRectangle(Pause2.ButtonX , Pause2.ButtonY , Pause2.Buttondx , Pause2.Buttondy);
    }
    if(PauseTime)
    {
        iFilledRectangle(Resume2.ButtonX , Resume2.ButtonY , Resume2.Buttondx , Resume2.Buttondy);
    }
    red = 255;
    green = 255;
    blue = 255;
    iSetColor(red , green , blue);
    iText(1280 , 525 , "Time" , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1250 , 500 , Time , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1275 , 625 , "Score" , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1280 , 600 , Score , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1275 , 410 , Life , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1275 , 300 , "Menu" , GLUT_BITMAP_TIMES_ROMAN_24);
    if(!PauseTime)
       iText(1275 , 200 , "Pause" , GLUT_BITMAP_TIMES_ROMAN_24);
    if(PauseTime)
       iText(1265 , 200 , "Resume" , GLUT_BITMAP_TIMES_ROMAN_24);
    iText(1280 , 100 , "Exit" , GLUT_BITMAP_TIMES_ROMAN_24);
    for(int i = 0;i < totalbricks ;i++)
    {
        if(bricks[i].showBrick)
        {
            iSetColor(bricks[i].BrickRed , bricks[i].BrickGreen , bricks[i].BrickBlue);
            iFilledRectangle(bricks[i].BrickX , bricks[i].BrickY , bricks[i].Brickdx , bricks[i].Brickdy);
        }
    }
    if(Perk1.ShowPerk)
    {
        iShowBMP(Perk1.PerkX , Perk1.PerkY , "Dx Ball Perks 1.bmp");
    }
    if(Perk2.ShowPerk)
    {
        iShowBMP(Perk2.PerkX , Perk2.PerkY , "Dx Ball Perks 2.bmp");
    }
    if(Perk3.ShowPerk)
    {
        iShowBMP(Perk3.PerkX , Perk3.PerkY , "Dx Ball Perks 3.bmp");
    }
    if(Perk4.ShowPerk)
    {
        iShowBMP(Perk4.PerkX , Perk4.PerkY , "Dx Ball Perks 4.bmp");
    }
    if(Perk5.ShowPerk)
    {
        iShowBMP(Perk5.PerkX , Perk5.PerkY , "Dx Ball Perks 5.bmp");
    }
    if(Perk6.ShowPerk)
    {
        iShowBMP(Perk6.PerkX , Perk6.PerkY , "Dx Ball Perks 6.bmp");
    }
    if(Perk7.ShowPerk)
    {
        iShowBMP(Perk7.PerkX , Perk7.PerkY , "Dx Ball Perks 1.bmp");
    }
    if(Perk8.ShowPerk)
    {
        iShowBMP(Perk8.PerkX , Perk8.PerkY , "Dx Ball Perks 2.bmp");
    }
    if(Perk9.ShowPerk)
    {
        iShowBMP(Perk9.PerkX , Perk9.PerkY , "Dx Ball Perks 3.bmp");
    }
    if(Perk10.ShowPerk)
    {
        iShowBMP(Perk10.PerkX , Perk10.PerkY , "Dx Ball Perks 4.bmp");
    }
    if(Perk11.ShowPerk)
    {
        iShowBMP(Perk11.PerkX , Perk11.PerkY , "Dx Ball Perks 5.bmp");
    }
    if(Perk12.ShowPerk)
    {
        iShowBMP(Perk12.PerkX , Perk12.PerkY , "Dx Ball Perks 6.bmp");
    }
    if(ShowDialogBox && DialogBox == 1)
       {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(540 , 300 , 300 , 120);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBYes1.ButtonX , DBYes1.ButtonY , DBYes1.Buttondx , DBYes1.Buttondy);
           iFilledRectangle(DBNo1.ButtonX , DBNo1.ButtonY , DBNo1.Buttondx , DBNo1.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(570 , 380 , "Are you sure you want to exit?" , GLUT_BITMAP_HELVETICA_18);
           iText(610 , 330 , "Yes" , GLUT_BITMAP_HELVETICA_18);
           iText(730 , 330 , "No" , GLUT_BITMAP_HELVETICA_18);
       }
       if(ShowDialogBox && DialogBox == 2)
       {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(480 , 300 , 500 , 125);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBSaveExit2.ButtonX , DBSaveExit2.ButtonY , DBSaveExit2.Buttondx , DBSaveExit2.Buttondy);
           iFilledRectangle(DBDontSaveExit2.ButtonX , DBDontSaveExit2.ButtonY , DBDontSaveExit2.Buttondx , DBDontSaveExit2.Buttondy);
           iFilledRectangle(DBCancelExit2.ButtonX , DBCancelExit2.ButtonY , DBCancelExit2.Buttondx , DBCancelExit2.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(500 , 400 , "If you want to save the game,please enter your name :" , GLUT_BITMAP_HELVETICA_18);
           iSetColor(255 , 255 , 255);
           iFilledRectangle(500 , 350 , 300 , 30);
           iSetColor(0 , 0 , 0);
           iText(505 , 360 , EnterName , GLUT_BITMAP_HELVETICA_18);
           iText(520 , 320 , "Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(650 , 320 , "Don't Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(830 , 320 , "Cancel Exit" , GLUT_BITMAP_HELVETICA_18);
       }
    }
    if(State == 3)
    {
        iShowBMP(0 , 0 , "Dx Ball Theme 15.bmp");
        red = 0;
        green = 0;
        blue = 0;
        iSetColor(red , green , blue);
        if(GameWin)
        {
            iText(540 , 625 , "Congratulations!!!!!You Win!!!!!" , GLUT_BITMAP_TIMES_ROMAN_24);
        }
        if(!GameWin)
        {
            iText(580 , 625 , "Better Luck Next Time!!!!!" , GLUT_BITMAP_TIMES_ROMAN_24);
        }
        iText(650 , 575 , "Your Score :" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(680 , 525 , Score , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(650 , 475 , "Your Time :" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(650 , 425 , Time , GLUT_BITMAP_TIMES_ROMAN_24);
        if(!GameSaved)
        {
        iText(615 , 375 , "Enter Your Name :" , GLUT_BITMAP_TIMES_ROMAN_24);
        red = 255;
        green = 255;
        blue = 255;
        iSetColor(red , green , blue);
        iFilledRectangle(595 , 300 , 300 , 50);
        iSetColor(0 , 0 , 0);
        iText(605 , 320 , EnterName , GLUT_BITMAP_TIMES_ROMAN_24);
        red = 128;
        green = 128;
        blue = 128;
        iSetColor(red , green , blue);
        iFilledRectangle(Save3.ButtonX , Save3.ButtonY , Save3.Buttondx , Save3.Buttondy);
        iFilledRectangle(DontSave3.ButtonX , DontSave3.ButtonY , DontSave3.Buttondx , DontSave3.Buttondy);
        iSetColor(0 , 0 , 0);
        iText(625 , 270 , "Save" , GLUT_BITMAP_HELVETICA_18);
        iText(740 , 270 , "Don't Save" , GLUT_BITMAP_HELVETICA_18);
        }
        if(GameSaved)
        {
            iText(680 , 375 , "Saved!" , GLUT_BITMAP_TIMES_ROMAN_24);
        }
        red = 0;
        green = 100;
        blue = 255;
        iSetColor(red , green , blue);
        iFilledRectangle(Menu3.ButtonX , Menu3.ButtonY , Menu3.Buttondx , Menu3.Buttondy);
        iFilledRectangle(NewGame3.ButtonX , NewGame3.ButtonY , NewGame3.Buttondx , NewGame3.Buttondy);
        iFilledRectangle(Exit3.ButtonX , Exit3.ButtonY , Exit3.Buttondx , Exit3.Buttondy);
        iSetColor(0 , 0 , 0);
        iText(300 , 100 , "Menu" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(670 , 100 , "New Game" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1100 , 100 , "Exit" , GLUT_BITMAP_TIMES_ROMAN_24);
        if(ShowDialogBox && DialogBox == 1)
        {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(540 , 300 , 300 , 120);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBYes1.ButtonX , DBYes1.ButtonY , DBYes1.Buttondx , DBYes1.Buttondy);
           iFilledRectangle(DBNo1.ButtonX , DBNo1.ButtonY , DBNo1.Buttondx , DBNo1.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(570 , 380 , "Are you sure you want to exit?" , GLUT_BITMAP_HELVETICA_18);
           iText(610 , 330 , "Yes" , GLUT_BITMAP_HELVETICA_18);
           iText(730 , 330 , "No" , GLUT_BITMAP_HELVETICA_18);
       }
       if(ShowDialogBox && DialogBox == 2)
       {
           red = 128;
           green = 128;
           blue = 128;
           iSetColor(red , green , blue);
           iFilledRectangle(480 , 300 , 500 , 125);
           red = 0;
           green = 0;
           blue = 255;
           iSetColor(red , green , blue);
           iFilledRectangle(DBSaveExit2.ButtonX , DBSaveExit2.ButtonY , DBSaveExit2.Buttondx , DBSaveExit2.Buttondy);
           iFilledRectangle(DBDontSaveExit2.ButtonX , DBDontSaveExit2.ButtonY , DBDontSaveExit2.Buttondx , DBDontSaveExit2.Buttondy);
           iFilledRectangle(DBCancelExit2.ButtonX , DBCancelExit2.ButtonY , DBCancelExit2.Buttondx , DBCancelExit2.Buttondy);
           iSetColor(0 , 0 , 0);
           iText(500 , 400 , "If you want to save the game,please enter your name :" , GLUT_BITMAP_HELVETICA_18);
           iSetColor(255 , 255 , 255);
           iFilledRectangle(500 , 350 , 300 , 30);
           iSetColor(0 , 0 , 0);
           iText(505 , 360 , EnterName , GLUT_BITMAP_HELVETICA_18);
           iText(520 , 320 , "Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(650 , 320 , "Don't Save & Exit" , GLUT_BITMAP_HELVETICA_18);
           iText(830 , 320 , "Cancel Exit" , GLUT_BITMAP_HELVETICA_18);
       }
    }
    if(State == 4)
    {
        iShowBMP(0 , 0 , "Dx Ball Theme 16.bmp");
        red = 0;
        green = 0;
        blue = 0;
        iSetColor(red , green , blue);
        iText(50 , 625 , "Number" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(250 , 625 , "Name" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(750 , 625 , "Score" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(1050 , 625 , "Time" , GLUT_BITMAP_TIMES_ROMAN_24);
        for(int i = 0;i < HighScoresLimit ;i++)
        {
            char SerialNumber[5] , ScoreNumber[8];
            sprintf(SerialNumber , "%02d" , i+1);
            sprintf(ScoreNumber , "%04d" , GameHighScores[i].GameScore);
            iText(75 , 575 - i*50 , SerialNumber , GLUT_BITMAP_TIMES_ROMAN_24);
            iText(250 , 575 - i*50 , GameHighScores[i].GameName , GLUT_BITMAP_TIMES_ROMAN_24);
            iText(755 , 575 - i*50 , ScoreNumber , GLUT_BITMAP_TIMES_ROMAN_24);
            iText(1050 , 575 - i*50 , GameHighScores[i].GameTime , GLUT_BITMAP_TIMES_ROMAN_24);
        }
        red = 255;
        green = 100;
        blue = 0;
        iSetColor(red , green , blue);
        iFilledRectangle(Back4.ButtonX , Back4.ButtonY , Back4.Buttondx , Back4.Buttondy);
        iSetColor(0 , 0 , 0);
        iText(1275 , 65 , "Back" , GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(State == 5)
    {
        iSetColor(0 , 0 , 0);
        iShowBMP(0 , 0 , "Dx Ball Theme 12.bmp");
        iText(25 , 650 , "Instructions : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 600 , "You  can  control  the  paddle  below  that  deflects  the  ball  and  helps  to  break  the  bricks  using  both  keyboard (Left  key  and  " , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 550 , "Right  key ) and  mouse . Initially  you  will  have  three  lives . If  the  ball  falls  below  the  screen , you  will  lose  a  life . Your " , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 500 , "task  is  to  clear  all  the  bricks  in  minimum  amount  of  time . You  can  see  your  score , time  and  life  while  playing . You  can  " , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 450 , "reload  the  game  from  where  you  left  the  previous  time  if  you  save  the  game . You  can  see  the  top  10  high  scores  from  " , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 400 , "the menu . " , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(25 , 325 , "Best of luck!!!!!! " , GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP(50 , 220 , "Dx Ball Perks 2.bmp");
        iShowBMP(50 , 140 , "Dx Ball Perks 3.bmp");
        iShowBMP(50 , 60 , "Dx Ball Perks 1.bmp");
        iText(140 , 230 , "->     Wider  Paddle" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(140 , 150 , "->     Smaller  Paddle" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(140 , 70 , "->     Losing  A  Life" , GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP(650 , 220 , "Dx Ball Perks 4.bmp");
        iShowBMP(650 , 140 , "Dx Ball Perks 5.bmp");
        iShowBMP(650 , 60 , "Dx Ball Perks 6.bmp");
        iText(740 , 230 , "->     Gaining  A  Life" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(740 , 150 , "->     Faster  Ball" , GLUT_BITMAP_TIMES_ROMAN_24);
        iText(740 , 70 , "->     Slower  Ball" , GLUT_BITMAP_TIMES_ROMAN_24);
        red = 255;
        green = 100;
        blue = 0;
        iSetColor(red , green , blue);
        iFilledRectangle(Back5.ButtonX , Back5.ButtonY , Back5.Buttondx , Back5.Buttondy);
        iSetColor(0 , 0 , 0);
        iText(1300 , 40 , "Back" , GLUT_BITMAP_TIMES_ROMAN_24);
    }
}

void TimeChange()
{
    if(BallMove && !PauseTime && State == 2 && !ShowDialogBox)
    {
    TimeSecond++;
    if(TimeSecond == 60){
       TimeMinute++;
       TimeSecond = 0;
    }
    if(TimeMinute == 60){
       TimeHour++;
       TimeMinute = 0;
       TimeSecond = 0;
    }
    sprintf(Time , "%02d : %02d : %02d", TimeHour , TimeMinute , TimeSecond);
    }
}

void ScoreChange()
{
    sprintf(Score , "%04d" , CurrentScore);
}

void LifeChange()
{
    sprintf(Life , "Life : %d" , LifeNumber);
}

void restart()
{
    BallX = MarginX/2.0;
    BallY = MarginY;
    Balldx = 12;
    Balldy = 12;
    Boarddx = 100;
    Boarddy = 20;
    BoardX = BallX - (Boarddx/2.0);
    BoardY = BallY - Boarddy - BallRadius;
    BallMove = false;
}

void NewGameStart()
{
    BallX = MarginX/2.0;
    BallY = MarginY;
    Balldx = 12;
    Balldy = 12;
    Boarddx = 100;
    Boarddy = 20;
    BoardX = BallX - (Boarddx/2.0);
    BoardY = BallY - Boarddy - BallRadius;
    BallMove = false;
    GamePlayed = true;
    State = 2;
    TimeSecond = 0;
    TimeMinute = 0;
    CurrentScore = 0;
    LifeNumber = 3;
    sprintf(Life , "Life : %d" , LifeNumber);
    sprintf(Time , "%02d : %02d : %02d" , TimeHour , TimeMinute , TimeSecond);
    sprintf(Score , "%04d" , CurrentScore);
    NewGamePlayed = true;
    PauseTime = false;
    GameSaved = false;
    FILE *filepointer = fopen("CurrentGameInfo.txt" , "wb");
    fclose(filepointer);
    definebricks();
    DefinePerks();
}
void ShowHighScores()
{
    FILE *filepointer = fopen("HighScores.txt" , "rb");
    fread(GameHighScores , sizeof(ScoreTimeName) , 10 , filepointer);
    fclose(filepointer);
}

void UpdateHighScores()
{
    FILE *filepointer = fopen ("HighScores.txt" , "rb");
    ScoreTimeName SortingArray[HighScoresLimit + 2];
    fread(SortingArray , sizeof(ScoreTimeName) , HighScoresLimit , filepointer);
    fclose(filepointer);
    SortingArray[HighScoresLimit].GameScore = CurrentScore;
    strcpy(SortingArray[HighScoresLimit].GameTime , Time);
    strcpy(SortingArray[HighScoresLimit].GameName , EnterName);
    for(int i = HighScoresLimit;i>0;i--){
        int k = 0;
        for(int j = 0;j <= i;j++){
            if(SortingArray[j].GameScore < SortingArray[k].GameScore)
            {
                k = j;
            }
        }
        int t = SortingArray[i].GameScore;
        SortingArray[i].GameScore = SortingArray[k].GameScore;
        SortingArray[k].GameScore = t;
        char Time1[20],Time2[20],Name1[60],Name2[60];
        strcpy(Time1 , SortingArray[i].GameTime);
        strcpy(Time2 , SortingArray[k].GameTime);
        strcpy(SortingArray[i].GameTime , Time2);
        strcpy(SortingArray[k].GameTime , Time1);
        strcpy(Name1 , SortingArray[i].GameName);
        strcpy(Name2 , SortingArray[k].GameName);
        strcpy(SortingArray[k].GameName , Name1);
        strcpy(SortingArray[i].GameName , Name2);
    }
    filepointer = fopen("HighScores.txt" , "wb");
    fwrite(SortingArray , sizeof(ScoreTimeName) , HighScoresLimit , filepointer);
    fclose(filepointer);
}

void BallChange()
{
    if(BallMove && !PauseTime && State == 2 && !ShowDialogBox)
    {
       BallX += Balldx;
       BallY += Balldy;
       if(BallX + BallRadius >= MarginX||BallX - BallRadius <=0)
       {
           if(PlayMusic)
           {
              PlaySound("Music4.wav" , NULL , SND_ASYNC);
           }
           Balldx *= (-1);
       }
       if(BallY + BallRadius >=screenheight)
       {
           if(PlayMusic)
           {
              PlaySound("Music4.wav" , NULL , SND_ASYNC);
           }
           Balldy *= (-1);
       }
       if(BallX >= BoardX && BallX <= BoardX + Boarddx && BallY - BallRadius >= BoardY && BallY - BallRadius <= BoardY + Boarddy)
       {
           if(PlayMusic)
           {
              PlaySound("Music4.wav" , NULL , SND_ASYNC);
           }
           Balldy*=(-1);
       }
       if(BallY < BoardY)
       {
           LifeNumber--;
           LifeChange();
           if(LifeNumber == 0)
           {
               State = 3;
           }
           restart();
       }
       for(int i = 0;i < totalbricks; i++)
       {
           if(bricks[i].showBrick)
           {
               if(BallX + BallRadius >= bricks[i].BrickX && BallX - BallRadius <= bricks[i].BrickX + bricks[i].Brickdx)
               {
                   if(BallY + BallRadius >= bricks[i].BrickY && BallY - BallRadius <= bricks[i].BrickY + bricks[i].Brickdy)
                   {
                       if(PlayMusic)
                       {
                          PlaySound("Music5.wav" , NULL , SND_ASYNC);
                       }
                       Balldy *= (-1);
                       bricks[i].showBrick = false;
                       CurrentScore += 100;
                       ScoreChange();
                       if(CurrentScore == 5000)
                       {
                           State = 3;
                           GameWin = true;
                       }
                       if(i == Perk1.BrickNumber)
                       {
                           Perk1.ShowPerk = true;
                       }
                       if(i == Perk2.BrickNumber)
                       {
                           Perk2.ShowPerk = true;
                       }
                       if(i == Perk3.BrickNumber)
                       {
                           Perk3.ShowPerk = true;
                       }
                       if(i == Perk4.BrickNumber)
                       {
                           Perk4.ShowPerk = true;
                       }
                       if(i == Perk5.BrickNumber)
                       {
                           Perk5.ShowPerk = true;
                       }
                       if(i == Perk6.BrickNumber)
                       {
                           Perk6.ShowPerk = true;
                       }
                       if(i == Perk7.BrickNumber)
                       {
                           Perk7.ShowPerk = true;
                       }
                       if(i == Perk8.BrickNumber)
                       {
                           Perk8.ShowPerk = true;
                       }
                       if(i == Perk9.BrickNumber)
                       {
                           Perk9.ShowPerk = true;
                       }
                       if(i == Perk10.BrickNumber)
                       {
                           Perk10.ShowPerk = true;
                       }
                       if(i == Perk11.BrickNumber)
                       {
                           Perk11.ShowPerk = true;
                       }
                       if(i == Perk12.BrickNumber)
                       {
                           Perk12.ShowPerk = true;
                       }
                   }
               }
               else if(BallY + BallRadius >= bricks[i].BrickY && BallY - BallRadius <= bricks[i].BrickY + bricks[i].Brickdy)
               {
                   if(BallX + BallRadius >= bricks[i].BrickX && BallX - BallRadius <= bricks[i].BrickX + bricks[i].Brickdx)
                   {
                       if(PlayMusic)
                       {
                          PlaySound("Music5.wav" , NULL , SND_ASYNC);
                       }
                       Balldx *= (-1);
                       bricks[i].showBrick = false;
                       CurrentScore += 100;
                       ScoreChange();
                       if(CurrentScore == 5000)
                       {
                           State = 3;
                           GameWin = true;
                       }
                       if(i == Perk1.BrickNumber)
                       {
                           Perk1.ShowPerk = true;
                       }
                       if(i == Perk2.BrickNumber)
                       {
                           Perk2.ShowPerk = true;
                       }
                       if(i == Perk3.BrickNumber)
                       {
                           Perk3.ShowPerk = true;
                       }
                       if(i == Perk4.BrickNumber)
                       {
                           Perk4.ShowPerk = true;
                       }
                       if(i == Perk5.BrickNumber)
                       {
                           Perk5.ShowPerk = true;
                       }
                       if(i == Perk6.BrickNumber)
                       {
                           Perk6.ShowPerk = true;
                       }
                       if(i == Perk7.BrickNumber)
                       {
                           Perk7.ShowPerk = true;
                       }
                       if(i == Perk8.BrickNumber)
                       {
                           Perk8.ShowPerk = true;
                       }
                       if(i == Perk9.BrickNumber)
                       {
                           Perk9.ShowPerk = true;
                       }
                       if(i == Perk10.BrickNumber)
                       {
                           Perk10.ShowPerk = true;
                       }
                       if(i == Perk11.BrickNumber)
                       {
                           Perk11.ShowPerk = true;
                       }
                       if(i == Perk12.BrickNumber)
                       {
                           Perk12.ShowPerk = true;
                       }
                   }
               }
           }
       }
    }
}

void BallSpeedChange()
{
    if(BallMove && !PauseTime && State == 2 && !ShowDialogBox)
    {
        Balldx*=1.01;
        Balldy*=1.01;
    }
}

void PerkSpeedChange()
{
    if(Perk1.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk1.PerkY -= 10;
        if(BoardX + Boarddx >= Perk1.PerkX && BoardX <= Perk1.PerkX + 40 && BoardY + Boarddy >= Perk1.PerkY)
        {
            LifeNumber--;
            LifeChange();
            Perk1.ShowPerk = false;
            if(LifeNumber == 0)
            {
                State = 3;
            }
        }
        if(Perk1.PerkY < 10)
        {
            Perk1.ShowPerk = false;
        }
    }
    if(Perk2.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk2.PerkY -= 10;
        if(BoardX + Boarddx >= Perk2.PerkX && BoardX <= Perk2.PerkX + 40 && BoardY + Boarddy >= Perk2.PerkY)
        {
            BoardX -= (Boarddx)/2.0;
            Boarddx *= 1.5;
            Perk2.ShowPerk = false;
        }
        if(Perk2.PerkY < 10)
        {
            Perk2.ShowPerk = false;
        }
    }
    if(Perk3.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk3.PerkY -= 10;
        if(BoardX + Boarddx >= Perk3.PerkX && BoardX <= Perk3.PerkX + 40 && BoardY + Boarddy >= Perk3.PerkY)
        {
            BoardX += (Boarddx)/2.0;
            Boarddx /= 1.5;
            Perk3.ShowPerk = false;
        }
        if(Perk3.PerkY < 10)
        {
            Perk3.ShowPerk = false;
        }
    }
    if(Perk4.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk4.PerkY -= 10;
        if(BoardX + Boarddx >= Perk4.PerkX && BoardX <= Perk4.PerkX + 40 && BoardY + Boarddy >= Perk4.PerkY)
        {
            LifeNumber++;
            LifeChange();
            Perk4.ShowPerk = false;
        }
        if(Perk4.PerkY < 10)
        {
            Perk4.ShowPerk = false;
        }
    }
    if(Perk5.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk5.PerkY -= 10;
        if(BoardX + Boarddx >= Perk5.PerkX && BoardX <= Perk5.PerkX + 40 && BoardY + Boarddy >= Perk5.PerkY)
        {
            Balldx *= 1.5;
            Balldy *= 1.5;
            Perk5.ShowPerk = false;
        }
        if(Perk5.PerkY < 10)
        {
            Perk5.ShowPerk = false;
        }
    }
    if(Perk6.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk6.PerkY -= 10;
        if(BoardX + Boarddx >= Perk6.PerkX && BoardX <= Perk6.PerkX + 40 && BoardY + Boarddy >= Perk6.PerkY)
        {
            Balldx /= 1.8;
            Balldy /= 1.8;
            Perk6.ShowPerk = false;
        }
        if(Perk6.PerkY < 10)
        {
            Perk6.ShowPerk = false;
        }
    }
    if(Perk7.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk7.PerkY -= 10;
        if(BoardX + Boarddx >= Perk7.PerkX && BoardX <= Perk7.PerkX + 40 && BoardY + Boarddy >= Perk7.PerkY)
        {
            LifeNumber--;
            LifeChange();
            Perk7.ShowPerk = false;
            if(LifeNumber == 0)
            {
                State = 3;
            }
        }
        if(Perk7.PerkY < 10)
        {
            Perk7.ShowPerk = false;
        }
    }
    if(Perk8.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk8.PerkY -= 10;
        if(BoardX + Boarddx >= Perk8.PerkX && BoardX <= Perk8.PerkX + 40 && BoardY + Boarddy >= Perk8.PerkY)
        {
            BoardX -= (Boarddx)/2.0;
            Boarddx *= 1.5;
            Perk8.ShowPerk = false;
        }
        if(Perk8.PerkY < 10)
        {
            Perk8.ShowPerk = false;
        }
    }
    if(Perk9.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk9.PerkY -= 10;
        if(BoardX + Boarddx >= Perk9.PerkX && BoardX <= Perk9.PerkX + 40 && BoardY + Boarddy >= Perk9.PerkY)
        {
            BoardX += (Boarddx)/2.0;
            Boarddx /= 1.5;
            Perk9.ShowPerk = false;
        }
        if(Perk9.PerkY < 10)
        {
            Perk9.ShowPerk = false;
        }
    }
    if(Perk10.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk10.PerkY -= 10;
         if(BoardX + Boarddx >= Perk10.PerkX && BoardX <= Perk10.PerkX + 40 && BoardY + Boarddy >= Perk10.PerkY)
        {
            LifeNumber++;
            LifeChange();
            Perk10.ShowPerk = false;
        }
        if(Perk10.PerkY < 10)
        {
            Perk10.ShowPerk = false;
        }
    }
    if(Perk11.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk11.PerkY -= 10;
        if(BoardX + Boarddx >= Perk11.PerkX && BoardX <= Perk11.PerkX + 40 && BoardY + Boarddy >= Perk11.PerkY)
        {
            Balldx *= 1.5;
            Balldy *= 1.5;
            Perk11.ShowPerk = false;
        }
        if(Perk11.PerkY < 10)
        {
            Perk11.ShowPerk = false;
        }
    }
    if(Perk12.ShowPerk && !ShowDialogBox && !PauseTime)
    {
        Perk12.PerkY -= 10;
        if(BoardX + Boarddx >= Perk12.PerkX && BoardX <= Perk12.PerkX + 40 && BoardY + Boarddy >= Perk12.PerkY)
        {
            Balldx /= 1.8;
            Balldy /= 1.8;
            Perk12.ShowPerk = false;
        }
        if(Perk12.PerkY < 10)
        {
            Perk12.ShowPerk = false;
        }
    }
}

void WriteInfoInFile()
{
    ResumeGame.RBallRadius = BallRadius;
    ResumeGame.RBallX = BallX;
    ResumeGame.RBallY = BallY;
    ResumeGame.RBalldx = Balldx;
    ResumeGame.RBalldy = Balldy;
    ResumeGame.RBoarddx = Boarddx;
    ResumeGame.RBoarddy = Boarddy;
    ResumeGame.RBoardX = BoardX;
    ResumeGame.RBoardY = BoardY;
    if(BallMove)
    {
        ResumeGame.RBallMove = 1;
    }
    else
    {
        ResumeGame.RBallMove = 0;
    }
    ResumeGame.RCurrentScore = CurrentScore;
    ResumeGame.RTimeSecond = TimeSecond;
    ResumeGame.RTimeMinute = TimeMinute;
    ResumeGame.RTimeHour = TimeHour;
    ResumeGame.RLifeNumber = LifeNumber;
    if(PauseTime)
    {
        ResumeGame.RPauseTime = 1;
    }
    else
    {
        ResumeGame.RPauseTime = 0;
    }
    for(int i = 0;i < totalbricks;i++)
    {
        if(bricks[i].showBrick)
        {
            ResumeGame.RShowBrick[i] = 1;
        }
        else
        {
            ResumeGame.RShowBrick[i] = 0;
        }
        ResumeGame.RBrickRed[i] = bricks[i].BrickRed;
        ResumeGame.RBrickGreen[i] = bricks[i].BrickGreen;
        ResumeGame.RBrickBlue[i] = bricks[i].BrickBlue;
    }
    if(Perk1.ShowPerk)
    {
        ResumeGame.RPerk1ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk1ShowPerk = 0;
    }
    if(Perk2.ShowPerk)
    {
        ResumeGame.RPerk2ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk2ShowPerk = 0;
    }
    if(Perk3.ShowPerk)
    {
        ResumeGame.RPerk3ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk3ShowPerk = 0;
    }
    if(Perk4.ShowPerk)
    {
        ResumeGame.RPerk4ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk4ShowPerk = 0;
    }
    if(Perk5.ShowPerk)
    {
        ResumeGame.RPerk5ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk5ShowPerk = 0;
    }
    if(Perk6.ShowPerk)
    {
        ResumeGame.RPerk6ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk6ShowPerk = 0;
    }
    if(Perk7.ShowPerk)
    {
        ResumeGame.RPerk7ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk7ShowPerk = 0;
    }
    if(Perk8.ShowPerk)
    {
        ResumeGame.RPerk8ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk8ShowPerk = 0;
    }
    if(Perk9.ShowPerk)
    {
        ResumeGame.RPerk9ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk9ShowPerk = 0;
    }
    if(Perk10.ShowPerk)
    {
        ResumeGame.RPerk10ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk10ShowPerk = 0;
    }
    if(Perk11.ShowPerk)
    {
        ResumeGame.RPerk11ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk11ShowPerk = 0;
    }
    if(Perk12.ShowPerk)
    {
        ResumeGame.RPerk12ShowPerk = 1;
    }
    else
    {
        ResumeGame.RPerk12ShowPerk = 0;
    }
    ResumeGame.RPerk1PerkY = Perk1.PerkY;
    ResumeGame.RPerk2PerkY = Perk2.PerkY;
    ResumeGame.RPerk3PerkY = Perk3.PerkY;
    ResumeGame.RPerk4PerkY = Perk4.PerkY;
    ResumeGame.RPerk5PerkY = Perk5.PerkY;
    ResumeGame.RPerk6PerkY = Perk6.PerkY;
    ResumeGame.RPerk7PerkY = Perk7.PerkY;
    ResumeGame.RPerk8PerkY = Perk8.PerkY;
    ResumeGame.RPerk9PerkY = Perk9.PerkY;
    ResumeGame.RPerk10PerkY = Perk10.PerkY;
    ResumeGame.RPerk11PerkY = Perk11.PerkY;
    ResumeGame.RPerk12PerkY = Perk12.PerkY;
    FILE *filepointer = fopen("CurrentGameInfo.txt" , "wb");
    fwrite(&ResumeGame , sizeof(ResumeGameInfo) , 1 , filepointer);
    fclose(filepointer);
}

void ReadInfoFromFile()
{
    FILE *filepointer = fopen("CurrentGameInfo.txt" , "rb");
    fread(&ResumeGame , sizeof(ResumeGameInfo) , 1 , filepointer);
    fclose(filepointer);
    BallRadius = ResumeGame.RBallRadius;
    BallX = ResumeGame.RBallX;
    BallY = ResumeGame.RBallY;
    Balldx = ResumeGame.RBalldx;
    Balldy = ResumeGame.RBalldy;
    Boarddx = ResumeGame.RBoarddx;
    Boarddy = ResumeGame.RBoarddy;
    BoardX = ResumeGame.RBoardX;
    BoardY = ResumeGame.RBoardY;
    if(ResumeGame.RBallMove)
    {
        BallMove = true;
    }
    else
    {
        BallMove = false;
    }
    CurrentScore = ResumeGame.RCurrentScore;
    TimeSecond = ResumeGame.RTimeSecond;
    TimeMinute = ResumeGame.RTimeMinute;
    TimeHour = ResumeGame.RTimeHour;
    LifeNumber = ResumeGame.RLifeNumber;
    sprintf(Score , "%04d" , CurrentScore);
    sprintf(Life , "Life : %d" , LifeNumber);
    sprintf(Time , "%02d : %02d : %02d", TimeHour , TimeMinute , TimeSecond);
    if(ResumeGame.RPauseTime)
    {
        PauseTime = true;
    }
    else
    {
        PauseTime = false;
    }
    for(int i = 0; i < totalbricks ; i++)
    {
        if(ResumeGame.RShowBrick[i])
        {
            bricks[i].showBrick = true;
        }
        else
        {
            bricks[i].showBrick = false;
        }
        bricks[i].BrickRed = ResumeGame.RBrickRed[i];
        bricks[i].BrickGreen = ResumeGame.RBrickGreen[i];
        bricks[i].BrickBlue = ResumeGame.RBrickBlue[i];
    }
    if(ResumeGame.RPerk1ShowPerk)
    {
        Perk1.ShowPerk = true;
    }
    else
    {
        Perk1.ShowPerk = false;
    }
    if(ResumeGame.RPerk2ShowPerk)
    {
        Perk2.ShowPerk = true;
    }
    else
    {
        Perk2.ShowPerk = false;
    }
    if(ResumeGame.RPerk3ShowPerk)
    {
        Perk3.ShowPerk = true;
    }
    else
    {
        Perk3.ShowPerk = false;
    }
    if(ResumeGame.RPerk4ShowPerk)
    {
        Perk4.ShowPerk = true;
    }
    else
    {
        Perk4.ShowPerk = false;
    }
    if(ResumeGame.RPerk5ShowPerk)
    {
        Perk5.ShowPerk = true;
    }
    else
    {
        Perk5.ShowPerk = false;
    }
    if(ResumeGame.RPerk6ShowPerk)
    {
        Perk6.ShowPerk = true;
    }
    else
    {
        Perk6.ShowPerk = false;
    }
    if(ResumeGame.RPerk7ShowPerk)
    {
        Perk7.ShowPerk = true;
    }
    else
    {
        Perk7.ShowPerk = false;
    }
    if(ResumeGame.RPerk8ShowPerk)
    {
        Perk8.ShowPerk = true;
    }
    else
    {
        Perk8.ShowPerk = false;
    }
    if(ResumeGame.RPerk9ShowPerk)
    {
        Perk9.ShowPerk = true;
    }
    else
    {
        Perk9.ShowPerk = false;
    }
    if(ResumeGame.RPerk10ShowPerk)
    {
        Perk10.ShowPerk = true;
    }
    else
    {
        Perk10.ShowPerk = false;
    }
    if(ResumeGame.RPerk11ShowPerk)
    {
        Perk11.ShowPerk = true;
    }
    else
    {
        Perk11.ShowPerk = false;
    }
    if(ResumeGame.RPerk12ShowPerk)
    {
        Perk12.ShowPerk = true;
    }
    else
    {
        Perk12.ShowPerk = false;
    }
    Perk1.PerkY = ResumeGame.RPerk1PerkY;
    Perk2.PerkY = ResumeGame.RPerk2PerkY;
    Perk3.PerkY = ResumeGame.RPerk3PerkY;
    Perk4.PerkY = ResumeGame.RPerk4PerkY;
    Perk5.PerkY = ResumeGame.RPerk5PerkY;
    Perk6.PerkY = ResumeGame.RPerk6PerkY;
    Perk7.PerkY = ResumeGame.RPerk7PerkY;
    Perk8.PerkY = ResumeGame.RPerk8PerkY;
    Perk9.PerkY = ResumeGame.RPerk9PerkY;
    Perk10.PerkY = ResumeGame.RPerk10PerkY;
    Perk11.PerkY = ResumeGame.RPerk11PerkY;
    Perk12.PerkY = ResumeGame.RPerk12PerkY;
    filepointer = fopen("CurrentGameInfo.txt" , "wb");
    fclose(filepointer);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    if(State == 2 && !ShowDialogBox)
    {
    if(!BallMove && mx <= (MarginX - Boarddx) && !PauseTime){
       BoardX = mx;
       BallX = BoardX + (Boarddx/2.0);
    }
    else if(!BallMove && mx >= (MarginX - Boarddx) && !PauseTime){
        BoardX = MarginX - Boarddx;
        BallX = BoardX + (Boarddx/2.0);
    }
    else if(mx <= (MarginX - Boarddx) && BallMove && !PauseTime){
        BoardX = mx;;
    }
    else if(mx >= (MarginX - Boarddx) && !PauseTime){
        BoardX = MarginX - Boarddx;
    }
    }
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(State == 1 && !ShowDialogBox)
        {
            if(mx >= NewGame1.ButtonX && mx <= NewGame1.ButtonX+NewGame1.Buttondx && my >= NewGame1.ButtonY && my <= NewGame1.ButtonY+NewGame1.Buttondy)
            {
                NewGameStart();
            }
            if(mx >= Resume1.ButtonX && mx <= Resume1.ButtonX+Resume1.Buttondx && my >= Resume1.ButtonY && my <= Resume1.ButtonY+Resume1.Buttondy)
            {
                if(GameSaved || LifeNumber == 0 || CurrentScore == 5000)
                {
                    NewGameStart();
                }
                else if(!GameSaved && NewGamePlayed)
                {
                    State = 2;
                    GamePlayed = true;
                    PauseTime = false;
                }
                else if(!NewGamePlayed)
                {
                    FILE *filepointer = fopen("CurrentGameInfo.txt" , "r");
                    fseek(filepointer , 0 , SEEK_END);
                    int SizeOfFile = ftell(filepointer);
                    fclose(filepointer);
                    if(SizeOfFile == 0)
                    {
                        NewGameStart();
                    }
                    else
                    {
                        ReadInfoFromFile();
                        GamePlayed = true;
                        State = 2;
                    }
                }
            }
            if(mx >= HighScores1.ButtonX && mx <= HighScores1.ButtonX+HighScores1.Buttondx && my >= HighScores1.ButtonY && my <= HighScores1.ButtonY+HighScores1.Buttondy)
            {
                ShowHighScores();
                State = 4;
            }
            if(mx >= Help1.ButtonX && mx <= Help1.ButtonX+Help1.Buttondx && my >= Help1.ButtonY && my <= Help1.ButtonY+Help1.Buttondy)
            {
                State = 5;
            }
            if(mx >= Exit1.ButtonX && mx <= Exit1.ButtonX+Exit1.Buttondx && my >= Exit1.ButtonY && my <= Exit1.ButtonY+Exit1.Buttondy)
            {
                ShowDialogBox = true;
                if(!GamePlayed)
                {
                    DialogBox = 1;
                }
                if(GamePlayed)
                {
                    DialogBox = 2;
                }
            }
        }
        if(ShowDialogBox && DialogBox == 1)
        {
            if(mx >= DBYes1.ButtonX && mx <= DBYes1.ButtonX+DBYes1.Buttondx && my >= DBYes1.ButtonY && my <= DBYes1.ButtonY+DBYes1.Buttondy)
            {
                exit(0);
            }
            if(mx >= DBNo1.ButtonX && mx <= DBNo1.ButtonX+DBNo1.Buttondx && my >= DBNo1.ButtonY && my <= DBNo1.ButtonY+DBNo1.Buttondy)
            {
                ShowDialogBox = false;
            }
        }
        if(ShowDialogBox && DialogBox == 2)
        {
            if(mx >= DBSaveExit2.ButtonX && mx <= DBSaveExit2.ButtonX+DBSaveExit2.Buttondx && my >= DBSaveExit2.ButtonY && my <= DBSaveExit2.ButtonY+DBSaveExit2.Buttondy)
            {
                WriteInfoInFile();
                UpdateHighScores();
                exit(0);
            }
            if(mx >= DBDontSaveExit2.ButtonX && mx <= DBDontSaveExit2.ButtonX+DBDontSaveExit2.Buttondx && my >= DBDontSaveExit2.ButtonY && my <= DBDontSaveExit2.ButtonY+DBDontSaveExit2.Buttondy)
            {
                exit(0);
            }
            if(mx >= DBCancelExit2.ButtonX && mx <= DBCancelExit2.ButtonX+DBCancelExit2.Buttondx && my >= DBCancelExit2.ButtonY && my <= DBCancelExit2.ButtonY+DBCancelExit2.Buttondy)
            {
                EnterName[0] = '\0';
                EnterNameIndex = 0;
                ShowDialogBox = false;
            }
        }
        if(State == 2 && !ShowDialogBox)
        {
            if(mx >= Exit2.ButtonX && mx <= Exit2.ButtonX+Exit2.Buttondx && my >= Exit2.ButtonY && my <= Exit2.ButtonY+Exit2.Buttondy)
            {
                ShowDialogBox = true;
                if(!GamePlayed)
                {
                    DialogBox = 1;
                }
                if(GamePlayed)
                {
                    DialogBox = 2;
                }
            }
            if(mx >= Menu2.ButtonX && mx <= Menu2.ButtonX+Menu2.Buttondx && my >= Menu2.ButtonY && my <= Menu2.ButtonY+Menu2.Buttondy)
            {
                State = 1;
            }
            if(mx >= Pause2.ButtonX && mx <= Pause2.ButtonX+Pause2.Buttondx && my >= Pause2.ButtonY && my <= Pause2.ButtonY+Pause2.Buttondy && !PauseTime)
            {
                PauseTime = true;
            }
            else if(mx >= Resume2.ButtonX && mx <= Resume2.ButtonX+Resume2.Buttondx && my >= Resume2.ButtonY && my <= Resume2.ButtonY+Resume2.Buttondy && PauseTime)
            {
                PauseTime = false;
            }
        }
        if(State == 3 && !ShowDialogBox)
        {
            if(mx >= Menu3.ButtonX && mx <= Menu3.ButtonX+Menu3.Buttondx && my >= Menu3.ButtonY && my <= Menu3.ButtonY+Menu3.Buttondy)
            {
                EnterName[0] = '\0';
                EnterNameIndex = 0;
                State = 1;
            }
            if(mx >= NewGame3.ButtonX && mx <= NewGame3.ButtonX+NewGame3.Buttondx && my >= NewGame3.ButtonY && my <= NewGame3.ButtonY+NewGame3.Buttondy)
            {
                EnterName[0] = '\0';
                EnterNameIndex = 0;
                NewGameStart();
            }
            if(mx >= Exit3.ButtonX && mx <= Exit3.ButtonX+Exit3.Buttondx && my >= Exit3.ButtonY && my <= Exit3.ButtonY+Exit3.Buttondy)
            {
                ShowDialogBox = true;
                if(!GamePlayed)
                {
                    DialogBox = 1;
                }
                if(GamePlayed)
                {
                    DialogBox = 2;
                }
            }
            if(mx >= Save3.ButtonX && mx <= Save3.ButtonX+Save3.Buttondx && my >= Save3.ButtonY && my <= Save3.ButtonY+Save3.Buttondy && !GameSaved)
            {
                UpdateHighScores();
                GamePlayed = false;
                EnterName[0] = '\0';
                EnterNameIndex = 0;
                GameSaved = true;
            }
            if(mx >= DontSave3.ButtonX && mx <= DontSave3.ButtonX+DontSave3.Buttondx && my >= DontSave3.ButtonY && my <= DontSave3.ButtonY+DontSave3.Buttondy && !GameSaved)
            {
                EnterName[0] = '\0';
                EnterNameIndex = 0;
            }
        }
        if(State == 4 && !ShowDialogBox)
        {
            if(mx >= Back4.ButtonX && mx <= Back4.ButtonX+Back4.Buttondx && my >= Back4.ButtonY && my <= Back4.ButtonY+Back4.Buttondy)
            {
                State = 1;
            }
        }
        if(State == 5 && !ShowDialogBox)
        {
            if(mx >= Back5.ButtonX && mx <= Back5.ButtonX+Back5.Buttondx && my >= Back5.ButtonY && my <= Back5.ButtonY+Back5.Buttondy)
            {
                State = 1;
            }
        }
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        //x += 10;
        //y += 5;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //x -= 5;
        //y -= 5;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
    if(State == 3 && !ShowDialogBox)
    {
        if(key != '\b')
        {
            EnterName[EnterNameIndex] = key;
            EnterName[EnterNameIndex + 1] = '\0';
            EnterNameIndex++;
        }
        else
        {
            EnterName[EnterNameIndex - 1] = '\0';
            EnterNameIndex--;
        }
    }
    if(ShowDialogBox && DialogBox == 2)
    {
        if(key != '\b')
        {
            EnterName[EnterNameIndex] = key;
            EnterName[EnterNameIndex + 1] = '\0';
            EnterNameIndex++;
        }
        else
        {
            EnterName[EnterNameIndex - 1] = '\0';
            EnterNameIndex--;
        }
    }
    if(key == ' ')
    {
        if(!BallMove && State == 2 && !ShowDialogBox)
          BallMove = true;
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

    }
    if(key==GLUT_KEY_UP)
    {

    }
    if(key==GLUT_KEY_DOWN)
    {

    }
    if(key==GLUT_KEY_LEFT)
    {
       if(State == 2 && !ShowDialogBox)
       {
       if(BoardX >= 0)
         BoardX -= 15;
       if(!BallMove && BoardX >= 0)
       {
           BallX -= 15;
       }
       }
    }
    if(key==GLUT_KEY_RIGHT)
    {
       if(State == 2 && !ShowDialogBox)
       {
       if(BoardX <= MarginX - Boarddx)
         BoardX += 15;
       if(!BallMove && BoardX <= MarginX - Boarddx)
       {
           BallX += 15;
       }
       }
    }
    //place your codes for other keys here
}


int main()
{
    //place your own initialization codes here.
    definebricks();
    defineButtons();
    DefinePerks();
    iSetTimer(20 , BallChange);
    iSetTimer(1000 , TimeChange);
    iSetTimer(1000 , BallSpeedChange);
    iSetTimer(20 , PerkSpeedChange);
    iInitialize( screenwidth , screenheight, "Dx Ball");
    return 0;
}
