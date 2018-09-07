using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace App_COMTerminal
{

   public struct SettingUsart
    {
        public  int speed;
        public string NamePort;
        public string Parity;
        public string Format;
        public string StopBits;
    }

   public class LogSystem
    {

        StreamWriter sw;
        private string NameLogFile;
        string path;
        FileInfo fi1;

        public LogSystem()
        {
            NameLogFile = "LogFile_" + DateTime.Now.ToString() + ".txt";
            path = Path.GetFullPath(@"" + NameLogFile);
            fi1 = new FileInfo(path);
        }


        /// <summary>
        /// Метод старта системы логирования
        /// </summary>
        public void LogirateStart ()
        {
            if(!fi1.Exists)
            {
                sw = new StreamWriter(path);
            }
        }

        /// <summary>
        /// Метод записи в файл
        /// </summary>
        /// <param name="data"></param>
        public void LogRecord(string data,bool Mode_T_R, SettingUsart dat)
        {
            string Data_s;
            if(Mode_T_R)
            {
                Data_s = String.Format("Передача[{0}]:[Скорость:{1},Формат:{2},СтопБит:{3},Бит четности:{4},Имя порта:{5}]:{6}", DateTime.Now, dat.speed, dat.Format, dat.StopBits, dat.Parity, dat.NamePort, data);
                sw.WriteLine(Data_s);
                //записать в бинарном виде

                sw.WriteLine("--------------------------------------------");
            }
            else if(!Mode_T_R)
            {
                Data_s = String.Format("Прием[{0}]:[Скорость:{1},Формат:{2},СтопБит:{3},Бит четности:{4},Имя порта:{5}]:{6}", DateTime.Now, dat.speed, dat.Format, dat.StopBits, dat.Parity, dat.NamePort, data);
                sw.WriteLine(Data_s);
                //записать в бинарном виде

                sw.WriteLine("--------------------------------------------");
            }
           
        }


        /// <summary>
        /// Остановка записи в лог файл
        /// </summary>
        public void StopRecord()
        {
            sw.Close();
        }



        
    }
}
