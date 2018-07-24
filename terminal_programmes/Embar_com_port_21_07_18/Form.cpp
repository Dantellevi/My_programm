//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Threads.h"
#include "Controller.h"
#include "DataStream.h"
#include "Form.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdPort"
#pragma link "OoMisc"
#pragma resource "*.dfm"


////////////////////////////////////
 #define nachalo      0
 #define adres      1
 #define data      2
 #define data_dac      3
 #define data_d_input      4
 #define data_d_output      5
 #define crc      6
 #define vihod1      7
 #define vihod2      8

 #define H      0
 #define L      1

 #define address      1

 


// ���������� ����������
/// ������� ������ � ������� ��������� �� ������

TDataStream* DataStream=new TDataStream();

TPotokControl *PotokControl = new TPotokControl(true);      // ��������� ������������� ����� ��� �����������
TPotokGraf *PotokGraf = new TPotokGraf(true);      // ��������� ������������� �����



AnsiString str;
unsigned char   crc_, adc_chanel=0, temp_d_outputH=0, temp_d_outputL=0, temp_d_input=0,  temp_adc_massiveH[20], temp_adc_massiveL[20], temp_dac_massiveH[20], temp_dac_massiveL[20];
int bytiki=0,  paket=0, paketGraf=0,  temp, data_massiv1[1000], data_massiv2[1000],   paket_count=0, adc_data_chanel[12];
bool H_or_L=0;
int  temp_int;



unsigned int i,ii, poz;



TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

			//// �������� ����������� ������ DataStream
		//	DataStream();
		//	DataStream->	   

				   //      ������������ �������� ������ �������

	   for (int i = 0; i < 12; i++)
	   {
		 // ���
		 SeriesADC[i]=new TLineSeries(Form1);
		 SeriesADC[i]->ParentChart=ChartADC;
		 SeriesADC[i]->SeriesColor=clLime;
		 /// �������� ������
		 SeriesDOUT[i]=new TLineSeries(Form1);
		 SeriesDOUT[i]->ParentChart=ChartDOUT;
		 SeriesDOUT[i]->SeriesColor=clLime;

		
	   }
	   ///  ������ ������� ���
	   for (int i = 0; i < 8; i++)
	   {
		 // ���
		 SeriesDAC[i]=new TLineSeries(Form1);
		 SeriesDAC[i]->ParentChart=ChartDAC;
		 SeriesDAC[i]->SeriesColor=clLime;

		   /// �������� �����
					SeriesDIN[i]=new TLineSeries(Form1);
					SeriesDIN[i]->ParentChart=ChartDIN;
					SeriesDIN[i]->SeriesColor=clLime;

		
	   }
	   
	   PotokGraf->Resume();          // ��������� �����...	 
	   PotokControl->Resume();          // ��������� ����� �����������

	   PotokControl->ApdComPortPotok=ApdComPort1;

	  // ����������� ������ ������ ��� ��������� �������� ��������

	  MassButtonDOut[0]=ButtonDOut0;
	  MassButtonDOut[1]=ButtonDOut1;
	  MassButtonDOut[2]=ButtonDOut2;
	  MassButtonDOut[3]=ButtonDOut3;
	  MassButtonDOut[4]=ButtonDOut4;
	  MassButtonDOut[5]=ButtonDOut5;
	  MassButtonDOut[6]=ButtonDOut6;
	  MassButtonDOut[7]=ButtonDOut7;
	  MassButtonDOut[8]=ButtonDOut8;
	  MassButtonDOut[9]=ButtonDOut9;
	  MassButtonDOut[10]=ButtonDOut10;
	  MassButtonDOut[11]=ButtonDOut11;

	  // ������������� ����� �� �������
	  for (int i = 0; i < 12; i++)
	  {
		  MassButtonDOut[i]->Caption=PotokControl->MassStrDOut[i];
	  }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 	 ApdComPort1->Open=True;


}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::ApdComPort1PortOpen(TObject *Sender)
{
	  Button1->Caption="COM-���� ������!";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::ApdComPort1TriggerAvail(TObject *CP, WORD Count)
{
#define   KvantOfPocket 20            // ����� ������� � ����� ������ ��������� ����������
#define   KvantForGraf 69                // ����� ������ ��� ������ �������


 static __int64   error, count_data_byte;
 unsigned char data_byte;
 static unsigned char *P_data_byte;
 static int sostoyanie=0, GrafTic=0;



			   PotokGraf->Count=Count;

				Edit1->Text= IntToStr(Count);          //  ����� ����
		  		Edit2->Text= IntToStr(error);          // ����� ������
		  //	 MemoCount->Lines->Add(IntToStr(Count));



   for (i = 0; i < Count; i++)
   {

						   //		data_byte=(unsigned char)ApdComPort1->GetChar();
						            data_byte=ApdComPort1->GetChar();


			switch (sostoyanie)
			{
	 // 0
	case nachalo:
					if (data_byte==255) 
					{
					sostoyanie=adres;
					}
					break;
	// 1
	case adres:
					if (data_byte==address) 	
					{
					sostoyanie=data;
					count_data_byte=0;     // �������� ������� ���� ������
					crc_=0;

						 P_data_byte=&( DataStream->P_MainStructMass[DataStream->AllPocketCount]->Digital_input );
					
					}
					
					else
					{
					sostoyanie=nachalo;
					}
					break;

	// 2
	case data:
				// ����� �������� ������� ������...  � ������� CRC
						// ��������� � ������ ������
					  *(P_data_byte +	count_data_byte)=data_byte;

							 //	  DataByteMass[count_data_byte]=data_byte;
								  
						crc_+= data_byte;
						
						count_data_byte++;      // ����������� ����� ����...
							// �������� ���������
							if (count_data_byte==43)      // �� ������� ������ �� ���������� ������� ���������
							{
								 sostoyanie=crc;
							}
							break;

				  
	// 6
	case crc:

			 

			if (crc_==data_byte)	
					{             

					sostoyanie=vihod1;
					crc_=0;
					}
					else 
					{

					sostoyanie=nachalo;
					error++;
					crc_=0;

					}
			break;

	// 7
	case vihod1:

				if (data_byte==255) 
				{

				sostoyanie=vihod2;

				}
				else	
				{

				sostoyanie=nachalo;

				error++;

				}
				break;
				

	// 8
	case vihod2:

				if (data_byte==255)  //  ��������� � ��������� ���������� ������
				{        

				///  ����� ������� �������!
				
						// � ������� ������� ����������� ��������� ��������� �� ���������� �����...
						DataStream->P_MainStructMass[DataStream->AllPocketCount]->Servise=DataStream->AllPocketCount;


											/// � �������� ���������� ��������� ����� ���������
											PotokControl->AllPocketCountForControl=DataStream->AllPocketCount;	   
											 ///// �������� ����������� � ���������� ��������� ��������� ������
											PotokControl->IntControl=true;



								  
						// ����������� ���������� ����� ��� ��������� ���������
				  DataStream->AllPocketCount++; 	

					paket++;               // ����� ������� ��� ������������ �����....
					paketGraf++;           // ����� ������� ��� ������ �������...

					if (paket==KvantOfPocket) 
					{
								
									   PotokControl->IntControlOtvetka=true;

											   
									   paket=0;
				
					}
					if (paketGraf==KvantForGraf) 
					{
								
									   	 // ��������� ������� ����� ���������  ��� ���������� ������ � ����
											PotokGraf->AllPocketCountNew=DataStream->AllPocketCount;

									   if (PotokGraf->Int_)   // ���� ����� ����������
									   {
											 ShowMessage("����� ����������");
									   }
									   else
									   {
											/// ����� �� ��������� �������

												PotokGraf->Int_=true;
												PotokGraf->Resume();          // ��������� �����...
									   }

											   
									   paketGraf=0;
				
					}
					



				   sostoyanie=nachalo;

				}
				else
				{

				 sostoyanie=nachalo;

				  error++;

				}
				break;


			};




	}


}
//---------------------------------------------------------------------------




void __fastcall TForm1::ButtonCalibrClick(TObject *Sender)
{
	 unsigned __int64   AllPocketCount= DataStream->AllPocketCount;

	 // ������� ����
	 MemoAdcCalibr->Lines->Clear();
	 MemoDacCalibr->Lines->Clear();
	 
	 for (int i = 0; i < 12; i++)   // ���������� �����
	 {
		   MemoAdcCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i] )+" ;"+ 
		   FloatToStr( CodeToVoltag (DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i]) )	);

		 //	  MemoAdcCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i] ));
	 } 
	  for (int i = 0; i < 8; i++)   // ���������� ������
	 {
		  MemoDacCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->DAC_massive[i] ) );
	 } 
}
//---------------------------------------------------------------------------
/// �������������� ���� ��� � ����������
float TForm1::CodeToVoltag ( int Code)
{
  float result;		
   if (Code>=2124)    // ���� ����
   {
		result= Code*0.0059-11.850;
		return result;
   }
   else            // ���� ����
   {     
		result= Code*0.0059-11.913;
		return result;
   }
   
}
//  ��� �������������� ���������� � ��� ���
 int  TForm1::VoltagToCode ( float Voltage)
 {
	int result;		
   if (Voltage>=0.04025)    // ���� ����
   {
		result= (int)(Voltage*154.83+2053.8);
		return result;
   }
   else            // ���� ����
   {     
		result= (int)(Voltage*154.82+2053.8);
		return result;
   }


 }






void __fastcall TForm1::ButtonCodeToDacClick(TObject *Sender)
{
	for (int i = 0; i < 8; i++)   // ���������� �����
	 {
		  DataStream->P_StructTemp->DAC_massive[i]=VoltagToCode (-5.0);
		  
	 } 
	
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ButtonOKClick(TObject *Sender)
{

	   if (Form1->Button��->Caption=="��=OFF")  // ���� ���������
	   {
		   PotokControl->DigitalOutSet(�� , true);   // ��������...
	   }

	   if (Form1->Button��->Caption=="��=ON")  // ���� ��������
	   {
		   PotokControl->DigitalOutSet(�� , false);   // ���������...
	   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button���Click(TObject *Sender)
{

		if (Form1->Button���->Caption=="���=OFF")  // ���� ���������
	   {
		   PotokControl->DigitalOutSet(��� , true);   // ��������...
	   }

		if (Form1->Button���->Caption=="���=ON")  // ���� ��������
	   {
		   PotokControl->DigitalOutSet(��� , false);   // ���������...
	   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDOutClick(TObject *Sender)
{

	  for (int i = 0; i < 10; i++)
	  {

			  if (MassButtonDOut[i]== Sender)
			  {
					if ( MassButtonDOut[i]->Caption == PotokControl->MassStrDOut[i]+"=OFF" )  // ���� ���������
					{
						PotokControl->DigitalOutSet(i , true);   // ��������...
					}

					if ( MassButtonDOut[i]->Caption == PotokControl->MassStrDOut[i]+"=ON" )  // ���� ��������
					{
						PotokControl->DigitalOutSet(i , false);   // ���������...
					}



			  }


	  }




}
//---------------------------------------------------------------------------

