//---------------------------------------------------------------------------


//*********************************************************

#define   AllPocketMax_def 10000000       // Выделяем память для хранения структур

/// Класс управляем круговоротом данных в природе...
class TDataStream
{
public:
	//// Структура данных для приема и отсылки
		struct My_struct    // Обьявляем структурную переменную
		{
			unsigned __int8 ZeroByte;                                      // 1 байт     // нужен для выравнивания данных в структуре
			unsigned __int8 Digital_input;   // 8 бит  задействовано      // 1 байт
			unsigned __int16  Digital_output;   // 12 бит  задействовано    // 2 байт
			unsigned __int16  ADC_massive[12];  // 12 каналов               // 24 байт
			unsigned __int16  DAC_massive[8];   // 8 каналов                 // 16 байт

			unsigned __int64  Servise;                                        // 8 байта
			
			
			
		};  // ИТОГО 44 байта

   //		My_struct *P_MainStruct;
		
		My_struct *P_MainStructMass[AllPocketMax_def];
		My_struct *P_StructTemp;

		unsigned __int64   AllPocketCount;         // Текущий порядковый номер пакета

			unsigned __int8 DoutMass[12];    // Массив цифровых ВЫХОДОВ и ВХОДОВ
			unsigned __int8 DinMass[8];    // Массив цифровых ВЫХОДОВ и ВХОДОВ

            // Хранит число байт в структуре
			 unsigned __int16 StructSize;

/////// ФУНКЦИИ

//// Конструктор
  TDataStream(void);

/// Функция для выдачи цифровых ВЫХОДОВ
 void DoutToSeries(My_struct * Str);
 

  /// Функция для выдачи цифровых ВХОДОВ
 void DinToSeries(My_struct * Str);
		
	 


};

#ifndef DataStreamH
#define DataStreamH
//---------------------------------------------------------------------------
#endif
