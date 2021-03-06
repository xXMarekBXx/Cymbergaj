//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = 8;
int y = 8;

int player1Points = 0;
int player2Points = 0;

int player1Bounce = 0;
int player2Bounce = 0;
   
int second = 30;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   second = 30;

   ShowMessage("Welcome in the Cymbergaj game.\n\nPlayer on the left side(red) controls \nusing the up and down arrows.\n\nPlayer on the right side(orange)\ncontrols using the numeric keypad:\n8 - up, 2 - down.\n\nOne round lasts 30 seconds.\n\nHave fun :)");
   
   TimerStopwatch->Enabled = true;
   Form1->TimerBall->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   stopwatch->Caption ="Timer start!";
   second = 30;
   Form1->yes->Visible = false;
   Form1->no->Visible = false;
}
//---------------------------------------------------------------------------

void colissionsTopAndBottom()
{
  //Collision Top
  if(Form1->b->Top-5 <= Form1->background->Top) y = -y;
  //Collision Bottom
  if(Form1->b->Top + Form1->b->Height + 5 >= Form1->background->Height) y = -y;
}
//---------------------------------------------------------------------------

void lostOfPointPlayer1()
{
  if(Form1->b->Width >= Form1->p1->Width + Form1->p1->Width+15)
  {
   Form1->TimerBall->Enabled = false;
   Form1->b->Visible=false;
  }

 if(Form1->b->Left == Form1->background->Left)
 {
   player2Points++;

   Form1->TimerBall->Enabled = false;
   Form1->b->Left = 600;
   Form1->b->Top = 250;
   Form1->TimerBall->Enabled = true;
   x = -x;
 }
 Form1->points2->Caption = "Player 2 points: " + IntToStr(player2Points);
}

void lostOfPointPlayer2()
{
if(Form1->b->Width >= Form1->p2->Width + Form1->p2->Width+15)
  {
   Form1->TimerBall->Enabled = false;
   Form1->b->Visible=false;
  }
  
 if(Form1->b->Left == Form1->p2->Left)
 {
  player1Points++;

  Form1->TimerBall->Enabled = false;
  Form1->b->Left = 600;
  Form1->b->Top = 250;
  Form1->TimerBall->Enabled = true;
  x = -x;
 }
 Form1->points1->Caption = "Player 1 points: " + IntToStr(player1Points);
}
//---------------------------------------------------------------------------

void blockPlayer1()
{
  if((Form1->b->Left <= Form1->p1->Width) && (Form1->b->Top + Form1->b->Height > Form1->p1->Top) && (Form1->b->Top + Form1->b->Height < Form1->p1->Top + Form1->p1->Height))
  {
       x = -x;
       player1Bounce++;
  }
  Form1->bounce1->Caption = "Player 1 bounce: " + IntToStr(player1Bounce);
}

void blockPlayer2()
{
    if((Form1->b->Left + (Form1->b->Width)/2  >= Form1->p2->Left) && (Form1->b->Top + Form1->b->Height > Form1->p2->Top) && (Form1->b->Top + Form1->b->Height < Form1->p2->Top + Form1->p2->Height))
    {
       x = -x;
       player2Bounce++;
  }
  Form1->bounce2->Caption = "Player 2 bounce: " + IntToStr(player2Bounce);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
  b->Left += x;
  b->Top +=y;

  colissionsTopAndBottom();
  lostOfPointPlayer1();
  lostOfPointPlayer2();
  blockPlayer1();
  blockPlayer2();   
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Up1Timer(TObject *Sender)
{
   if(p1->Top > 10) p1->Top -=10;
}

void __fastcall TForm1::Down1Timer(TObject *Sender)
{
   if(p1->Top + p1->Height < background->Height - 10) p1->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  //Player 1
  if(Key == VK_UP) Up1->Enabled = true;
  if(Key == VK_DOWN) Down1->Enabled = true;

  //Player 2
  if(Key == VK_NUMPAD8) Up2->Enabled = true;
  if(Key == VK_NUMPAD2) Down2->Enabled = true;
}

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  //Player 1
  if(Key == VK_UP) Up1->Enabled = false;
  if(Key == VK_DOWN) Down1->Enabled = false;
  //Player 2
  if(Key == VK_NUMPAD8) Up2->Enabled = false;
  if(Key == VK_NUMPAD2) Down2->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Up2Timer(TObject *Sender)
{
  if(p2->Top>9) p2->Top -=10;
}

void __fastcall TForm1::Down2Timer(TObject *Sender)
{
  if(p2->Top + p2->Height < background->Height - 10) p2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerStopwatchTimer(TObject *Sender)
{  
 second--;
 AnsiString s;
 s = IntToStr(second);
 stopwatch->Caption ="remaining time: " + s;

 if(second==0)
 {
   TimerStopwatch->Enabled = false;

   Form1->TimerBall->Enabled = false;
   Form1->b->Left = 600;
   Form1->b->Top = 250;

   stopwatch->Caption ="Do you want to play again?";

   Form1->yes->Visible = true;
   Form1->no->Visible = true;
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::noClick(TObject *Sender)
{
   Form1->Close();   
}
     
void __fastcall TForm1::yesClick(TObject *Sender)
{
   stopwatch->Caption ="Timer start!";
   TimerStopwatch->Enabled = true;
   Form1->TimerBall->Enabled = true;
   Form1->b->Left = 600;
   Form1->b->Top = 250;

   second = 30;

   player1Points = 0;
   player2Points = 0;

   player1Bounce = 0;
   player2Bounce = 0;

   Form1->yes->Visible = false;
   Form1->no->Visible = false;
}
//---------------------------------------------------------------------------

