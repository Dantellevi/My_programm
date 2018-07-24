//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <AdPort.hpp>
#include "OoMisc.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------




class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TApdComPort *ApdComPort1;
	TButton *Button1;

  //	TMemo *Memo1;

	TMemo *MemoData;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TTimer *Timer1;

	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *������_2D_�������;
	TChart *ChartADC;
	TTabSheet *������_2D_�������;
	TChart *ChartDAC;
	TTabSheet *TabSheet2;
	TChart *ChartDOUT;
	TTabSheet *TabSheet3;
	TChart *ChartDIN;
	TTabSheet *����������;
	TMemo *MemoAdcCalibr;
	TMemo *MemoDacCalibr;
	TButton *ButtonCalibr;
	TButton *ButtonCodeToDac;
	TTabSheet *������;
	TMemo *MemoPotoki;
	TMemo *MemoCount;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TTabSheet *TabSheet4;
	TPanel *PanelManeger;
	TButton *Button��;
	TButton *Button���;
	TPanel *PanelDout;
	TMemo *MemoDout;
	TPanel *PanelDIn;
	TMemo *MemoDIn;
	TPanel *PanelAOut;
	TMemo *MemoAOut;
	TPanel *PanelAin;
	TMemo *MemoAIn;
	TChart *Chart���1;
	TLineSeries *Series���1;
	TChart *Chart��������;
	TLineSeries *Series��������;
	TChart *Chart�1;
	TLineSeries *Series�1;
	TChart *Chart��;
	TLineSeries *Series��;
	TEdit *Edit�I;
	TEdit *Edit�II;
	TButton *ButtonDOut0;
	TButton *ButtonDOut1;
	TButton *ButtonDOut2;
	TButton *ButtonDOut3;
	TButton *ButtonDOut4;
	TButton *ButtonDOut5;
	TButton *ButtonDOut6;
	TButton *ButtonDOut7;
	TButton *ButtonDOut9;
	TButton *ButtonDOut10;
	TButton *ButtonDOut11;
	TButton *ButtonDOut8;



	void __fastcall Button1Click(TObject *Sender);

	void __fastcall ApdComPort1PortOpen(TObject *Sender);
 //	void __fastcall ApdComPort1TriggerData(TObject *CP, WORD TriggerHandle);
	void __fastcall ApdComPort1TriggerAvail(TObject *CP, WORD Count);
	void __fastcall ButtonCalibrClick(TObject *Sender);
	void __fastcall ButtonCodeToDacClick(TObject *Sender);
	void __fastcall ButtonOKClick(TObject *Sender);
	void __fastcall Button���Click(TObject *Sender);
	void __fastcall ButtonDOutClick(TObject *Sender);

		  

   
	
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	


   TLineSeries * SeriesADC[12];       // 12 ������ ������ ���
   TLineSeries * SeriesDAC[8];       // 12 ������ ������ ���
   TLineSeries * SeriesDOUT[12];       // 12 ������ ������ �������� �������
   TLineSeries * SeriesDIN[8];       // 8 ������ ������ �������� ������

	 
   float  CodeToVoltag ( int Code);	  // ��� ��������� ���� ��� � ����������
   int  VoltagToCode ( float Voltage);   //  ��� �������������� ���������� � ��� ���


   TButton * MassButtonDOut[12];

		
};

  


//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------



#endif
