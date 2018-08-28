using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.IO.Ports;
namespace App_COMTerminal
{
    /// <summary>
    /// Класс отвечает за заполнение списков для настроек
    /// </summary>
   public class Convert_dataList
    {
        private List<long> SpeedBaudL;//список скоростей порта
        private List<string> NamePortL;//имя порта
        private List<int> formatDataL;//формат данных
        private List<string> bitParityL;//бит четности
        private List<string> stopBitsL;//стоп бит


        private string _NamePort;//переменная для хранения выбранного имени порта
        private long _speed;//переменная для хранения выбранной скорости
        private int _format;//выбранный формат данных
        private string _bitP;//выбранный режим бита четности
        private string _stopBits;//выбранное количество стоп битов


        public string _NamePort_
        {
            
            set
            {
                _NamePort = value;
            }
        }

        public long _speed_
        {
            set
            {
                _speed = value;
            }
        }

        public int _format_
        {
            set
            {
                _format = value;
            }
        }

        public string _bitP_
        {
            set
            {
                _bitP = value;

            }
        }

        public string _stopBit_
        {
            set
            {
                _stopBits = value;
            }
        }





        #region Свойства для возврата

        /// <summary>
        /// Свойство возращающее значения из списка скоростей
        /// </summary>
        public List<long> Baud
        {
            get
            {
                return SpeedBaudL;
            }
        }

        /// <summary>
        /// Свойство возращающее значения из списка имен портов
        /// </summary>
        public List<string> PortComName
        {
            get
            {
                return NamePortL;
            }
        }


        /// <summary>
        /// Свойство возращающее значения из списка формата данных
        /// </summary>
        public List<int> Format
        {
            get
            {
                return formatDataL;
            }
        }


        /// <summary>
        /// Свойство возращающее значения из списка битов четности
        /// </summary>
        public List<string> bitParity
        {
            get
            {
                return bitParityL;
            }
        }


        /// <summary>
        /// Свойство возращающее значения из списка стоп битов
        /// </summary>
        public List<string> StopBit
        {
            get
            {
                return stopBitsL;
            }
        }


        #endregion


        /// <summary>
        /// Функция заполнения списков
        /// </summary>
       public void FillList()
        {
            SpeedBaudL = new List<long>()
            {
                300,600,1200,2400,4800,9600,19200,38400,57600,115200,230400,460800,921600
            };

            NamePortL = SerialPort.GetPortNames().ToList();

            formatDataL = new List<int>()
            {
                7,8,9
            };

            bitParityL = new List<string>()
            {
                "1 бит четности",
                "нет битов четности"
            };

            stopBitsL = new List<string>()
            {
                "1 стоп бит",
                "2 стоп бита",
                "None"
            };



        } 

       

        public void Connect(ref SerialPort data)
        {
            data.PortName = _NamePort;
            data.DataBits = _format;
            data.BaudRate = (int)_speed;


            switch(_bitP)
            {
                case "1 бит четности":
                    {
                        data.Parity = Parity.Mark;
                        break;
                    }
                case "нет битов четности":
                    {
                        data.Parity = Parity.None;
                        break;
                    }
            }

            switch(_stopBits)
            {
                case "1 стоп бит":
                    {
                        data.StopBits = StopBits.One;
                        break;
                    }
                case "2 стоп бита":
                    {
                        data.StopBits = StopBits.Two;
                        break;
                    }

            }

            data.Open();





        }


    }
}
