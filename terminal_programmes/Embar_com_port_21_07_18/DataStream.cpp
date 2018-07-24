//---------------------------------------------------------------------------

#pragma hdrstop

#include "DataStream.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

TDataStream::TDataStream(void)
{
     /////////////////////////////////////////////  ����������� ���������� �� ��������� � ������ ����������

			 //	   P_MainStruct=new My_struct;

				   for (int i = 0; i < AllPocketMax_def; i++) 
				   {
					  P_MainStructMass[i]=new My_struct;
				   }
				   P_StructTemp=new  My_struct;        // �������� ������

				   StructSize=sizeof(My_struct);

                  
}

/// ������� ��� ������ �������� �������
void TDataStream::DoutToSeries(My_struct * Str)
 {
	 int Temp=Str->Digital_output;
 
	for (int i = 0; i < 12; i++) 

	{
		
		  if ( Temp & 1 ) 
			{
					DoutMass[i]=1;
		 
			}
			 if ( !(Temp & 1) )
			{
					DoutMass[i]=0;
			}

		   Temp=Temp>>1;	
		
	} 
	 
	   
 }

 /// ������� ��� ������ �������� ������
 void TDataStream::DinToSeries(My_struct * Str)
 {
	 int Temp=Str->Digital_input;
 
	for (int i = 0; i < 8; i++) 

	{
		
		  if ( Temp & 1 ) 
			{
					DinMass[i]=1;
		 
			}
			 if ( !(Temp & 1) )
			{
					DinMass[i]=0;
			}

		   Temp=Temp>>1;	
		
	} 
	 
	   
 }	
