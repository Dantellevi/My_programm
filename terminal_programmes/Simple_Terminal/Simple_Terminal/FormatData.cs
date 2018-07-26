﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Simple_Terminal
{
   
    public struct IHH_Formata_Data
    {
        public  byte ZeroByte;           // 1 байт     // нужен для выравнивания данных в структуре
        public byte Digital_input;      // 8 бит  задействовано      // 1 байт
        public UInt16 Digital_Output;  // 12 бит  задействовано    // 2 байт
        public UInt16[] ADC_massive;  // 12 каналов               // 24 байт
        public UInt16[] DAC_massive;  // 8 каналов                 // 16 байт


        /// <summary>
        /// Функция инициализации массивов
        /// </summary>
       public void Initilice_Massive()
        {
            ADC_massive = new UInt16[12];
            DAC_massive = new UInt16[8];
        }


        


    }

}
