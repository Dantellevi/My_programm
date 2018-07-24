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

 


// Глобальные переменные
/// Выделям память и создаем указатели на КЛАССЫ

TDataStream* DataStream=new TDataStream();

TPotokControl *PotokControl = new TPotokControl(true);      // Породжаем остановленный поток Для КОНТРОЛЛЕРА
TPotokGraf *PotokGraf = new TPotokGraf(true);      // Породжаем остановленный поток



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

			//// Вызываем конструктор класса DataStream
		//	DataStream();
		//	DataStream->	   

				   //      Динамическое создание кривых графика

	   for (int i = 0; i < 12; i++)
	   {
		 // АЦП
		 SeriesADC[i]=new TLineSeries(Form1);
		 SeriesADC[i]->ParentChart=ChartADC;
		 SeriesADC[i]->SeriesColor=clLime;
		 /// Цифровые ВЫХОДЫ
		 SeriesDOUT[i]=new TLineSeries(Form1);
		 SeriesDOUT[i]->ParentChart=ChartDOUT;
		 SeriesDOUT[i]->SeriesColor=clLime;

		
	   }
	   ///  Кривые графика ЦАП
	   for (int i = 0; i < 8; i++)
	   {
		 // АЦП
		 SeriesDAC[i]=new TLineSeries(Form1);
		 SeriesDAC[i]->ParentChart=ChartDAC;
		 SeriesDAC[i]->SeriesColor=clLime;

		   /// Цифровые ВХОДЫ
					SeriesDIN[i]=new TLineSeries(Form1);
					SeriesDIN[i]->ParentChart=ChartDIN;
					SeriesDIN[i]->SeriesColor=clLime;

		
	   }
	   
	   PotokGraf->Resume();          // Запускаем поток...	 
	   PotokControl->Resume();          // Запускаем поток КОНТРОЛЛЕРА

	   PotokControl->ApdComPortPotok=ApdComPort1;

	  // Присваиваем адреса кнопок для установки цифровых сигналов

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

	  // Устанавливаем имена на кнопках
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
	  Button1->Caption="COM-порт открыт!";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::ApdComPort1TriggerAvail(TObject *CP, WORD Count)
{
#define   KvantOfPocket 20            // число пакетов в одном кванте обработки информации
#define   KvantForGraf 69                // Число циклов для вывода графики


 static __int64   error, count_data_byte;
 unsigned char data_byte;
 static unsigned char *P_data_byte;
 static int sostoyanie=0, GrafTic=0;



			   PotokGraf->Count=Count;

				Edit1->Text= IntToStr(Count);          //  число байт
		  		Edit2->Text= IntToStr(error);          // число ошибок
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
					count_data_byte=0;     // обнуляем счетчик байт данных
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
				// Сдесь начинаме крутить данные...  и считать CRC
						// сохраняем в массив байтов
					  *(P_data_byte +	count_data_byte)=data_byte;

							 //	  DataByteMass[count_data_byte]=data_byte;
								  
						crc_+= data_byte;
						
						count_data_byte++;      // увеличиваем число байт...
							// Проверка байтности
							if (count_data_byte==43)      // по условию уходим из наполнения текущей структуры
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

				if (data_byte==255)  //  переходим к обработке полученных данных
				{        

				///  Пакте получен успешно!
				
						// В текущей успешно заполненной структуре сохраняем ее порядковый номер...
						DataStream->P_MainStructMass[DataStream->AllPocketCount]->Servise=DataStream->AllPocketCount;


											/// И сообщаем актуальный последний номер структуры
											PotokControl->AllPocketCountForControl=DataStream->AllPocketCount;	   
											 ///// Сообщаем контроллеру о готовности очередной структуры данных
											PotokControl->IntControl=true;



								  
						// Увеличиваем порядковый номер для следующей структуры
				  DataStream->AllPocketCount++; 	

					paket++;               // число пакетов для формирования пачки....
					paketGraf++;           // число пакетов для вывода графики...

					if (paket==KvantOfPocket) 
					{
								
									   PotokControl->IntControlOtvetka=true;

											   
									   paket=0;
				
					}
					if (paketGraf==KvantForGraf) 
					{
								
									   	 // Сохраняем текущий номер структуры  для корректной записи в файл
											PotokGraf->AllPocketCountNew=DataStream->AllPocketCount;

									   if (PotokGraf->Int_)   // если поток перегружен
									   {
											 ShowMessage("Поток перегружен");
									   }
									   else
									   {
											/// Поток на обработку графики

												PotokGraf->Int_=true;
												PotokGraf->Resume();          // Запускаем поток...
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

	 // очищаем МЕМО
	 MemoAdcCalibr->Lines->Clear();
	 MemoDacCalibr->Lines->Clear();
	 
	 for (int i = 0; i < 12; i++)   // Аналоговые входы
	 {
		   MemoAdcCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i] )+" ;"+ 
		   FloatToStr( CodeToVoltag (DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i]) )	);

		 //	  MemoAdcCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->ADC_massive[i] ));
	 } 
	  for (int i = 0; i < 8; i++)   // Аналоговые вЫХОДЫ
	 {
		  MemoDacCalibr->Lines->Add(IntToStr((__int64)DataStream->P_MainStructMass[AllPocketCount-1]->DAC_massive[i] ) );
	 } 
}
//---------------------------------------------------------------------------
/// Преобразование КОДА АЦП в НАПРЯЖЕНИЕ
float TForm1::CodeToVoltag ( int Code)
{
  float result;		
   if (Code>=2124)    // Выше нуля
   {
		result= Code*0.0059-11.850;
		return result;
   }
   else            // Ниже нуля
   {     
		result= Code*0.0059-11.913;
		return result;
   }
   
}
//  Для преобразования напряжения в код ЦАП
 int  TForm1::VoltagToCode ( float Voltage)
 {
	int result;		
   if (Voltage>=0.04025)    // Выше нуля
   {
		result= (int)(Voltage*154.83+2053.8);
		return result;
   }
   else            // Ниже нуля
   {     
		result= (int)(Voltage*154.82+2053.8);
		return result;
   }


 }






void __fastcall TForm1::ButtonCodeToDacClick(TObject *Sender)
{
	for (int i = 0; i < 8; i++)   // Аналоговые входы
	 {
		  DataStream->P_StructTemp->DAC_massive[i]=VoltagToCode (-5.0);
		  
	 } 
	
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ButtonOKClick(TObject *Sender)
{

	   if (Form1->ButtonОК->Caption=="ОК=OFF")  // Если выключено
	   {
		   PotokControl->DigitalOutSet(ОК , true);   // Включаем...
	   }

	   if (Form1->ButtonОК->Caption=="ОК=ON")  // Если ВКЛючено
	   {
		   PotokControl->DigitalOutSet(ОК , false);   // Выключаем...
	   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonКЦУClick(TObject *Sender)
{

		if (Form1->ButtonКЦУ->Caption=="КЦУ=OFF")  // Если выключено
	   {
		   PotokControl->DigitalOutSet(КЦУ , true);   // Включаем...
	   }

		if (Form1->ButtonКЦУ->Caption=="КЦУ=ON")  // Если ВКЛючено
	   {
		   PotokControl->DigitalOutSet(КЦУ , false);   // Выключаем...
	   }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDOutClick(TObject *Sender)
{

	  for (int i = 0; i < 10; i++)
	  {

			  if (MassButtonDOut[i]== Sender)
			  {
					if ( MassButtonDOut[i]->Caption == PotokControl->MassStrDOut[i]+"=OFF" )  // Если выключено
					{
						PotokControl->DigitalOutSet(i , true);   // Включаем...
					}

					if ( MassButtonDOut[i]->Caption == PotokControl->MassStrDOut[i]+"=ON" )  // Если ВКЛючено
					{
						PotokControl->DigitalOutSet(i , false);   // Выключаем...
					}



			  }


	  }




}
//---------------------------------------------------------------------------

