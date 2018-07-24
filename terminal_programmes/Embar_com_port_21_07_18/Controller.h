//---------------------------------------------------------------------------

#ifndef ControllerH
#define ControllerH

#include <AdPort.hpp>

//------------------------------------------------------
// #define Low_ tpLower          // Низкний приоритет потока
// #define High_  tpTimeCritical         // Высокий приоритет потока

// дефайны названий выходов
			#define ОК 7
			#define КЦУ 9

		 /// аналоговые выходы
			#define ФI   4
			#define ФII  3

class TPotokControl : public TThread
{

protected:
	void __fastcall Execute();
	void __fastcall Work();


public:
		bool IntControl, IntControlOtvetka;

		unsigned __int64	AllPocketCountForControl;
		
		
	__fastcall TPotokControl(bool CreateSuspended);

	void Process(void);

	 void  Otvetka(void);

	 TApdComPort *ApdComPortPotok;



	 ///// Функции для вывода данных на голову / принимает порядковый номер бита и его устанавливаемое значение
	  void DigitalOutSet (int NumberBit, bool Uroven);
	  bool DigitalOutRead  (int NumberBit);

	  //// Массивы строк для названия входов и выходов
	  AnsiString MassStrDOut[12];    // Цифровые ВЫХОДЫ
	  AnsiString MassStrDIn[8];      // Цифровые ВХОДЫ

	   AnsiString MassStrAIn[12];    // Аналоговые ВХОДЫ
       AnsiString MassStrAOut[8];    // Аналоговые ВЫХОДЫ


};
//---------------------------------------------------------------------------
#endif
