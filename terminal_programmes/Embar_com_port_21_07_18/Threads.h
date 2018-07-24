//---------------------------------------------------------------------------

#ifndef ThreadsH
#define ThreadsH

//------------------------------------------------------
#define Low_ tpLower          // ������� ��������� ������
#define High_  tpTimeCritical         // ������� ��������� ������



class TPotokGraf : public TThread
{
protected:
	void __fastcall Execute();
	void __fastcall Work();


public:
		bool Int_;

        // ��������� �� ���������� ����
			FILE *F;

	  unsigned __int64	AllPocketCountOld;
	  unsigned __int64	AllPocketCountNew;
	  unsigned __int64  Count; // ����� ����������� ����	
		
	__fastcall TPotokGraf(bool CreateSuspended);

	void DataToGraficMemo (void);
};
//---------------------------------------------------------------------------
#endif
