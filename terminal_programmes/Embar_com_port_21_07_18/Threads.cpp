//---------------------------------------------------------------------------

#pragma hdrstop

#include "Controller.h"
#include "DataStream.h"
#include "Form.h"

#include "Threads.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------

__fastcall TPotokGraf::TPotokGraf(bool CreateSuspended)
	: TThread(CreateSuspended)
{
		 Priority = tpLowest;

          if ((F = fopen("Test.txt", "a+b")) == NULL)     //  "ab+"
		{
			ShowMessage("Файл не удается открыть");
			return;
		}
	
}
//---------------------------------------------------------------------------
void __fastcall TPotokGraf::Execute()
{
  //	NameThreadForDebugging(System::String(L"Potok_Uart"));
	//---- Place thread code here ----

	while (1)
		{
		   if (Int_)
		   {

			   Synchronize(Work);
			   Int_=false;
			  Suspend();
		   }


		}



   
}
//---------------------------------------------------------------------------
void __fastcall TPotokGraf::Work()
{
   // тут делаем дела

   unsigned int i;
   extern TDataStream* DataStream;       // объект уже создан...
   
		 //	Form1->Otvetka();
			Form1->MemoPotoki->Lines->Add("Залетело :"+ IntToStr( (__int64)DataStream->AllPocketCount ) );
			DataToGraficMemo ();
		 

   
}

void TPotokGraf::DataToGraficMemo (void)
{
	 extern TDataStream* DataStream;       // объект уже создан...
	 extern	TPotokControl *PotokControl;

	 unsigned __int64  Temp;
		AnsiString Str;
	 


	 /// Выводим данные...
	  Form1->MemoDout->Clear();
								 Str="";

								 for (int i = 0; i < 12; i++)
								 {
									 if (PotokControl->DigitalOutRead(i))
									 {
										 Form1->MemoDout->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrDOut[i]+"= 1");
									 }
									 else
									 {
										  Form1->MemoDout->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrDOut[i]+"= 0");
									 }



								 }

		 Form1->MemoDIn->Clear();

                                Temp=DataStream->P_MainStructMass[DataStream->AllPocketCount-1]->Digital_input;
										Str="";

										   for (int i = 0; i < 8; i++)
										   {
												 if ( (Temp & 1) )
												 {
													  // Ставим единичку
												   //	  Str+="D_in_"+IntToStr((__int64)(i+1))+"= 1 ; ";
													  Form1->MemoDIn->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrDIn[i]+"= 1");
												 }
												 else
												 {
														// Ставим ноль
													//  Str+="D_in_"+IntToStr((__int64)(i+1))+"= 0 ; ";
													  Form1->MemoDIn->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrDIn[i]+"= 0");
												 }

												Temp=Temp>>1;
										   }

			 Form1->MemoAIn->Clear();

                                       for (int i = 0; i < 12; i++)
								 {


										 Form1->MemoAIn->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrAIn[i]+"="+ IntToStr( (__int64) DataStream->P_MainStructMass[DataStream->AllPocketCount-1]->ADC_massive[i]  )   );


								 }


              Form1->MemoAOut->Clear();

								  for (int i = 0; i < 8; i++)
								 {


										 Form1->MemoAOut->Lines->Add("_"+IntToStr( (__int64) i ) +"->"+ PotokControl->MassStrAOut[i]+"="+ IntToStr( (__int64) DataStream->P_MainStructMass[DataStream->AllPocketCount-1]->DAC_massive[i]  )   );


								 }





										   Form1->MemoData->Lines->Add(Str);

										  Form1->Edit3->Text= IntToStr((__int64)DataStream->AllPocketCount);




	 // Выводим графики и пишем в файл
	 for (int ii = AllPocketCountOld; ii < AllPocketCountNew; ii++)
	 {
													DataStream->DoutToSeries(DataStream->P_MainStructMass[ii]);
													DataStream->DinToSeries(DataStream->P_MainStructMass[ii]);

												/// Выводим на график значение каналов АЦП
													for (int i = 0; i < 12; i++) 
													{
													   Form1->SeriesADC[i]->AddXY(ii,(DataStream->P_MainStructMass[ii])->ADC_massive[i]);

																 /// ФОН1
																 if (i==8)
																 {
																	 Form1->SeriesФОН1->AddXY ( ii, Form1->CodeToVoltag( (DataStream->P_MainStructMass[ii])->ADC_massive[i]) );
																 }
																 /// ДельтаЦУ
																 if (i==6)
																 {
																	 Form1->SeriesДельтаЦУ->AddXY ( ii, Form1->CodeToVoltag( (DataStream->P_MainStructMass[ii])->ADC_massive[i]) );
																 }
																 /// Ф1
																 if (i==5)
																 {
																	 Form1->SeriesФ1->AddXY ( ii, Form1->CodeToVoltag( (DataStream->P_MainStructMass[ii])->ADC_massive[i]) );
																 }


													   // Выводим на график значения каналов цифровых ВЫХОДОВ
													   Form1->SeriesDOUT[i]->AddXY(ii, i*2+1.7*DataStream->DoutMass[i] );

													 
													}
													/// Выводим на график значение каналов ЦАП
													for (int i = 0; i < 8; i++) 
													{
													   Form1->SeriesDAC[i]->AddXY(ii,(DataStream->P_MainStructMass[ii])->DAC_massive[i]);
															  // Выводим на график значения каналов цифровых ВХОДОВ
													   Form1->SeriesDIN[i]->AddXY(ii, i*2+1.7*DataStream->DinMass[i] );

															// Захват Головки
															if (i==1)
																 {
																	 Form1->SeriesЗГ->AddXY ( ii, DataStream->DinMass[i] );
																 }
														
													}

													 #define   Dlina 10000  
										   
											  if (Form1->SeriesADC[0]->Count()>Dlina) 
											   {
												 
												  // Удаляем точки графиков каналов АЦП
																for (int i = 0; i < 12; i++) 
													{
															 Form1->SeriesADC[i]->XValues->Delete(Form1->SeriesADC[i]->XValues->Count -( Dlina+1) );
															 Form1->SeriesADC[i]->YValues->Delete(Form1->SeriesADC[i]->YValues->Count -( Dlina+1) );

												
													}
													// Удаляем точки графиков каналов ЦАП
																for (int i = 0; i < 8; i++) 
													{
															 Form1->SeriesDAC[i]->XValues->Delete(Form1->SeriesDAC[i]->XValues->Count -( Dlina+1) );
															 Form1->SeriesDAC[i]->YValues->Delete(Form1->SeriesDAC[i]->YValues->Count -( Dlina+1) );

												
													}
																 
													   
											   }


                                               // Делаем запись в файл...

												fwrite(DataStream->P_MainStructMass[ii], DataStream->StructSize, 1, F) ;

	 }

	 AllPocketCountOld= AllPocketCountNew;
}
