﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Simple_Terminal.ConvertData
{
    /// <summary>
    /// Класс отвечающий за конвертирование пакета в hex  и bin формат и логирования
    /// </summary>
   public class ConvertPackage
    {
        /// <summary>
        /// Метод конвертации структуры в массив байт
        /// </summary>
        /// <param name="dd">Структура для преобразования в байты</param>
        /// <returns>Массив байт полученный из структуры</returns>
        public byte[] ConvertInMassByte(IHH_Formata_Data dd)
        {
            int size = Marshal.SizeOf(dd);//получаем неуправляемый размер объекта
            byte[] arr = new byte[size];

            IntPtr ptr = Marshal.AllocHGlobal(size);//выделяем память из неуправляемого процесса , заданное количество байт
            Marshal.StructureToPtr(dd, ptr, true);//преобразуем данные из управляемых в неуправляемый процесс
            Marshal.Copy(ptr, arr, 0, size);//копируем данные из неуправляемого процесса в массив байт
            Marshal.FreeHGlobal(ptr);//освобождение памяти
            return arr;

        }


        /// <summary>
        /// Метод конвертации из массива байт в структуру
        /// </summary>
        /// <param name="data">Принятый массив байт из виртуального COM порта</param>
        /// <returns>Полученная структура из принятых байт</returns>
        public IHH_Formata_Data ConvertStructData(ref byte[] data)
        {
            var handle = GCHandle.Alloc(data, GCHandleType.Pinned);//дескриптор для объекта
            IHH_Formata_Data datastruct = Marshal.PtrToStructure<IHH_Formata_Data>(handle.AddrOfPinnedObject());//преобразует принятые байты в новый объект
            return datastruct;

        }

        /// <summary>
        /// Логирование данных запись/перезапись в текстовый файл
        /// </summary>
        /// <param name="data">Принимаемые/отправляемые данные</param>
        /// <param name="flagSR">Флаг отвечающий за  отправку/прием байт</param>
        public void LogSystem(byte[] data,bool flagSR)
        {
            if(flagSR)  //принимаем массив байт(Пример в логе: 12.01.2018 12:15-Принятые байты из COM порта:\n.......байты\n)
            {

            }
            else //отправляем массив байт(13.03.2018 12:20 - Отправленные байты в COM-порт:\n..............байты\n)
            {

            }
        }



    }
}
