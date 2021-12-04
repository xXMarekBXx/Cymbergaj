//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *b;
        TTimer *TimerBall;
        TImage *p1;
        TTimer *Up1;
        TTimer *Down1;
        TImage *p2;
        TTimer *Up2;
        TTimer *Down2;
        TLabel *points1;
        TLabel *points2;
        TLabel *bounce1;
        TLabel *bounce2;
        TLabel *stopwatch;
        TTimer *TimerStopwatch;
        TLabel *yes;
        TLabel *no;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall Up1Timer(TObject *Sender);
        void __fastcall Down1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Up2Timer(TObject *Sender);
        void __fastcall Down2Timer(TObject *Sender);
        void __fastcall TimerStopwatchTimer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall noClick(TObject *Sender);
        void __fastcall yesClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 