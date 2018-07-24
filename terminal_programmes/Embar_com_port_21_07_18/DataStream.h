//---------------------------------------------------------------------------


//*********************************************************

#define   AllPocketMax_def 10000000       // �������� ������ ��� �������� ��������

/// ����� ��������� ������������ ������ � �������...
class TDataStream
{
public:
	//// ��������� ������ ��� ������ � �������
		struct My_struct    // ��������� ����������� ����������
		{
			unsigned __int8 ZeroByte;                                      // 1 ����     // ����� ��� ������������ ������ � ���������
			unsigned __int8 Digital_input;   // 8 ���  �������������      // 1 ����
			unsigned __int16  Digital_output;   // 12 ���  �������������    // 2 ����
			unsigned __int16  ADC_massive[12];  // 12 �������               // 24 ����
			unsigned __int16  DAC_massive[8];   // 8 �������                 // 16 ����

			unsigned __int64  Servise;                                        // 8 �����
			
			
			
		};  // ����� 44 �����

   //		My_struct *P_MainStruct;
		
		My_struct *P_MainStructMass[AllPocketMax_def];
		My_struct *P_StructTemp;

		unsigned __int64   AllPocketCount;         // ������� ���������� ����� ������

			unsigned __int8 DoutMass[12];    // ������ �������� ������� � ������
			unsigned __int8 DinMass[8];    // ������ �������� ������� � ������

            // ������ ����� ���� � ���������
			 unsigned __int16 StructSize;

/////// �������

//// �����������
  TDataStream(void);

/// ������� ��� ������ �������� �������
 void DoutToSeries(My_struct * Str);
 

  /// ������� ��� ������ �������� ������
 void DinToSeries(My_struct * Str);
		
	 


};

#ifndef DataStreamH
#define DataStreamH
//---------------------------------------------------------------------------
#endif
