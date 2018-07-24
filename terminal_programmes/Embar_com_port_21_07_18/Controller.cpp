//---------------------------------------------------------------------------



#pragma hdrstop


#include "DataStream.h"
#include "Form.h"
#include "Controller.h"
#include "Threads.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

__fastcall TPotokControl::TPotokControl(bool CreateSuspended)
	: TThread(CreateSuspended)
{
		 extern TDataStream* DataStream;       // объект уже создан...
		 Priority = tpNormal;

					  // Инициализация массивов   // Цифровые ВЫХОДЫ
						 MassStrDOut[0]="K1";
						 MassStrDOut[1]="K3";
						 MassStrDOut[2]="K4";
						 MassStrDOut[3]="Tупр";
						 MassStrDOut[4]="ПК";
						 MassStrDOut[5]="НП";
						 MassStrDOut[6]="БПГ";
						 MassStrDOut[7]="ОК";
						 MassStrDOut[8]="ОТКЛ.ПЦ";
						 MassStrDOut[9]="КЦУ";
						 MassStrDOut[10]="Оцу.Фпол";
						 MassStrDOut[11]="<-->";
		 

                         // Цифровые ВХОДЫ
						 MassStrDIn[0]="В2";
						 MassStrDIn[1]="ЗГ";
						   MassStrDIn[2]="<-->";
						   MassStrDIn[3]="<-->";
						   MassStrDIn[4]="<-->";
						   MassStrDIn[5]="<-->";
						   MassStrDIn[6]="<-->";
						   MassStrDIn[7]="<-->";

							// Аналоговые ВХОДЫ
							MassStrAIn[0]="Омега_1";
							MassStrAIn[1]="Омега_2";
							MassStrAIn[2]="Пси_1г";
							MassStrAIn[3]="Пси_2г";
							MassStrAIn[4]="lФпол.l";
							MassStrAIn[5]="Ф1";
							MassStrAIn[6]="ДельтаЦУ";
							MassStrAIn[7]="<-->";
							MassStrAIn[8]="ФОН1";
							MassStrAIn[9]="Фпол.";
							MassStrAIn[10]="АЭ1";
							MassStrAIn[11]="АЭ2";


						   // Аналоговые ВЫХОДЫ
							MassStrAOut[0]="Омега_x";
							MassStrAOut[1]="Альфа*1";
							MassStrAOut[2]="Альфа*2";
							MassStrAOut[3]="Ф II";
							MassStrAOut[4]="Ф I";
							MassStrAOut[5]="<-->";
							MassStrAOut[6]="<-->";
							MassStrAOut[7]="<-->";

							  /// сброс выходов ЦАП в ноль...
                            	//// Выставняем все выхода ЦАПа в 0-е напряжение, анулирование заблаговременно
				for (int i = 0; i < 8; i++)
				{

					   DataStream->P_StructTemp->DAC_massive[i]=Form1->VoltagToCode(0.0);
				}

}
//---------------------------------------------------------------------------
void __fastcall TPotokControl::Execute()
{
  //	NameThreadForDebugging(System::String(L"Potok_Uart"));
	//---- Place thread code here ----
   extern TDataStream* DataStream;

	while (1)
		{
		   if (IntControl && DataStream->AllPocketCount>0)
		   {
			   IntControl=false;
					Synchronize(Work);
						///// Тут решаем все свои задачи....
			  
		   }


		}



   
}
//---------------------------------------------------------------------------
void __fastcall TPotokControl::Work()
{
	extern TDataStream* DataStream;       // объект уже создан...
   // тут делаем дела
				/// Получаем данные и обрабатываем их...

				// актуализируем ПОДСВЕТКУ кнопок управления
				if (DigitalOutRead(ОК))
				{
					 Form1->ButtonОК->Caption="ОК=ON";
				}
				else
				{
					  Form1->ButtonОК->Caption="ОК=OFF";
				}

                if (DigitalOutRead(КЦУ))
				{
					  Form1->ButtonКЦУ->Caption="КЦУ=ON";
				}
				else
				{
					   Form1->ButtonКЦУ->Caption="КЦУ=OFF";
				}

		 // актуализируем ПОДСВЕТКУ кнопок управления цифровыми выходами в цикле для Алексея...

		 for (int i = 0; i < 12; i++)
		 {
					if ( DigitalOutRead(i) )
				{
					 Form1->MassButtonDOut[i]->Caption=MassStrDOut[i]+"=ON";
				}
				else
				{
					Form1->MassButtonDOut[i]->Caption=MassStrDOut[i]+"=OFF";
				}


		 }










   ////////				//// Загружаем на выходы ЦАПа нужные сигналы.


						 DataStream->P_StructTemp->DAC_massive[ФI]=Form1->VoltagToCode ( StrToFloat(Form1->EditФI->Text) );
						 DataStream->P_StructTemp->DAC_massive[ФII]=Form1->VoltagToCode(StrToFloat(Form1->EditФII->Text) );




				
					if (IntControlOtvetka)   //  	if (IntControlOtvetka)
					{
						  IntControlOtvetka=false;
						  
						  Process();
						 /// Отсылаем данные...
						 Otvetka();
					}
					
				
				
   
		 

   
}

void TPotokControl::Process()
{
	   extern TDataStream* DataStream;
			// Дефайны для сигналов....
			
	   #define Low_ tpLower 

			 

	   // объект уже создан...
 ////////////////////////////////////////////
 /*
	   
	   static unsigned __int8 Tic;
	   // Инкременируем
				static byte Minus;
				#define   Pribavka 100  
					  if ( (!Minus)&&(DataStream->P_StructTemp->DAC_massive[0]<4000) )
					  {
						  for (int i = 0; i < 8; i++)
						  {
							(DataStream->P_StructTemp->DAC_massive[i])=(DataStream->P_StructTemp->DAC_massive[i])+Pribavka;  // добавляем

						  }
					  }
					  if ((!Minus)&& (DataStream->P_StructTemp->DAC_massive[0]>=4000) ) 
					  {
						  Minus=1;
						 for (int i = 0; i < 8; i++)
						 {
						  (DataStream->P_StructTemp->DAC_massive[i])=(DataStream->P_StructTemp->DAC_massive[i])-Pribavka;  // отнимаем
						  
						 } 
						  
					  }
					  if ( (Minus) && (DataStream->P_StructTemp->DAC_massive[0]>=Pribavka) ) 
					  {
						
						  
						  for (int i = 0; i < 8; i++)
						  {
							(DataStream->P_StructTemp->DAC_massive[i])=(DataStream->P_StructTemp->DAC_massive[i])-Pribavka;  // продолжаем отнимать

						  }
						  // Но если уже на дне
									if (DataStream->P_StructTemp->DAC_massive[0]<=Pribavka ) Minus=0;
						 
					  }

					  
					  ////// Устанавлинваем цифровые выходы
					  
						 Tic++;
						 if (Tic==3)
						{
						   Tic=0;
						   (DataStream->P_StructTemp->Digital_output)++;
						} 
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////

						
						 

}

/// Ответка
void TPotokControl::Otvetka(void)
{
	extern TDataStream* DataStream;       // объект уже создан...
  //	TApdComPort *ApdComPort1;
	  
		  static bool  flag;
		 
			 
		  //		   *P_StructTemp= *(P_MainStructMass[AllPocketCount-1]);  // скорпировали во временную струкруру мгновенную структуру



				unsigned __int8 *P_Temp = & ( DataStream->P_StructTemp->Digital_input );
				unsigned __int8 CRC=0;
		#define   Delay 1

				ApdComPortPotok->PutChar( 255);  // Начало
				Sleep(Delay);
				ApdComPortPotok->PutChar(1 );  // Адрес
				Sleep(Delay);
		
				//// А дальше нужно засылать все байты структуры поочереди...
				/// Возвращаем последнюю полученную структуру...
						for (int i = 0; i < 43; i++) 
						{
												
							   ApdComPortPotok->PutChar( *(P_Temp+i) );
							   CRC+=*(P_Temp+i);
							   Sleep(Delay);
							
						}

					ApdComPortPotok->PutChar( CRC );
				Sleep(Delay);
					ApdComPortPotok->PutChar( 255);  // Конец 1
				Sleep(Delay);	
					ApdComPortPotok->PutChar( 255);  // Конец 2

						
	 
				

				
}

void TPotokControl::DigitalOutSet (int NumberBit, bool Uroven)
{
	 unsigned __int16 Maska;
	 extern TDataStream* DataStream;

		   Maska=1;
		  Maska=Maska<<(NumberBit);

	 if (Uroven) // Добавляем единицу... лог ИЛИ
	 {
		  DataStream->P_StructTemp->Digital_output= ( DataStream->P_StructTemp->Digital_output ) | Maska;

	 }
	 else       //  В ноль.... лог И
	 {
		  Maska=~Maska;

           DataStream->P_StructTemp->Digital_output= ( DataStream->P_StructTemp->Digital_output ) & Maska;
	 }


}

bool TPotokControl::DigitalOutRead  (int NumberBit)
{
		extern TDataStream* DataStream;
		unsigned __int16 Maska;

		Maska=1;
		Maska=Maska<<(NumberBit);


		if ( (DataStream->P_MainStructMass[DataStream->AllPocketCount-1]->Digital_output & Maska) )
		{
		 //	ShowMessage("rrrrr");
			return 1;

		}
		else
		{
			  return 0;
        }

}
