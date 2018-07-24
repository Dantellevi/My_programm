//---------------------------------------------------------------------------

#ifndef ThreadsH
#define ThreadsH

//------------------------------------------------------
#define Low_ tpLower          // Низкний приоритет потока
#define High_  tpTimeCritical         // Высокий приоритет потока



class TPotokGraf : public TThread
{
protected:
	void __fastcall Execute();
	void __fastcall Work();


public:
		bool Int_;

        // указатель на переменную фала
			FILE *F;

	  unsigned __int64	AllPocketCountOld;
	  unsigned __int64	AllPocketCountNew;
	  unsigned __int64  Count; // число прилетевший байт	
		
	__fastcall TPotokGraf(bool CreateSuspended);

	void DataToGraficMemo (void);
};
//---------------------------------------------------------------------------
#endif
