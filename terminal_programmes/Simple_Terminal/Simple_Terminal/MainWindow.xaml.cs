using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Threading;
using System.IO.Ports;

namespace Simple_Terminal
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<string> ListnamePort;//список для хранения имен портов
        private List<int> ListBaud;//список для хранения скоростей
        private List<int> ListparityBit;//список для выбора бита четности
        private List<int> ListFormat;//список для выбора формата данных
        private List<string> ListStopBit;//список для выбора стоп битов
        private int clicker=1;// переменная для хранения кол-ва нажатий
            
        private delegate void ReadStructData(IHH_Formata_Data data);


        private SerialPort _serialCOM=new SerialPort();

        public MainWindow()
        {
            InitializeComponent();
            
            IHH_Formata_Data dataFormat = new IHH_Formata_Data();//создание экземпляра  структуры
            dataFormat.Initilice_Massive();// создание экземпляров массивов
            SetList_Data();//Установка данных в комбобоксы

        }



        #region Вспомогательные функции

        /// <summary>
        /// Функция инициализации списков с данными для выбора в COMBobox
        /// </summary>
        private void SetList_Data()
        {
            ListnamePort = SerialPort.GetPortNames().ToList();//список портов
            ListBaud = new List<int>()
            {
                300,
                600,
                1200,
                2400,
                4800,
                9600,19200,38400,
                57600,
                115200,230400,460800,
                921600
            };//список скоростей USART

            ListparityBit = new List<int>()
            {
                0,
                1
            };//бит четности


            ListFormat = new List<int>()
            {
                7,8,9
            };//Формат данных

            ListStopBit = new List<string>()
            {
                "1 стоп бит",
                "2 стоп бита",
                "None"
            };//стоп биты

            //Подгружаем данные в COMBoBox
            ComboPortName.ItemsSource = ListnamePort;
            ComboParityBit.ItemsSource = ListparityBit;
            ComboStopBit.ItemsSource = ListStopBit;
            ComboFormatData.ItemsSource = ListFormat;
            ComboBaudSpeed.ItemsSource = ListBaud;

        }


        /// <summary>
        /// Функция Настройки виртуального COM- порта
        /// </summary>
        private void Settings_COMPort()
        {
            if(ComboBaudSpeed.SelectedIndex!=-1 && ComboFormatData.SelectedIndex!=-1 &&
                ComboParityBit.SelectedIndex!=-1 && ComboStopBit.SelectedIndex!=-1 && ComboPortName.SelectedIndex!=-1)
            {
                _serialCOM.PortName = ComboPortName.Text;
                _serialCOM.DataBits = int.Parse(ComboFormatData.Text);
                
                switch(ComboStopBit.Text)
                {
                    case "1 стоп бит":
                        {
                            _serialCOM.StopBits = StopBits.One;
                            break;
                        }
                    case "2 стоп бита":
                        {
                            _serialCOM.StopBits = StopBits.Two;
                            break;
                        }
                    case "None":
                        {
                            _serialCOM.StopBits = StopBits.None;
                            break;
                        }

                }

                _serialCOM.BaudRate = int.Parse(ComboBaudSpeed.Text);


                switch (int.Parse(ComboParityBit.Text))
                {
                    case 0:
                        {
                            _serialCOM.Parity=Parity.None;
                            break;
                        }
                    case 1:
                        {
                            _serialCOM.Parity=Parity.Mark;
                            break;
                        }
                    

                }

            }
           
        }



        /// <summary>
        /// Метод закрытия порта
        /// </summary>
        private void Disconnect()
        {
            _serialCOM.Close();
        }


        #endregion



        /// <summary>
        /// Обработчик события нажатия кнопки соединение
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ConnectBtn_Click(object sender, RoutedEventArgs e)
        {
            clicker++;

            if(clicker%2!=0)//если кол-во нажатий не равно нулю значит разъединение
            {
                ConnectBtn.Content = "Открыть порт";
                //вызываем функция разъединения
                Disconnect();

            }
            else if(clicker%2==0)
            {
                ConnectBtn.Content = "Уст.соединение";
                //вызываем функцию установки соединения
                Settings_COMPort();
                try
                {
                    _serialCOM.Open();
                    _serialCOM.DataReceived += _serialCOM_DataReceived;
                }
                catch(Exception ex)
                {
                    MessageBox.Show("Ошибка установки соединения" + ex.Message);
                }


            }
        }




        /// <summary>
        /// Обработчик приема данных из порта
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void _serialCOM_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            
        }
        
        /// <summary>
        /// Прием данных по принятой структуре
        /// </summary>
        /// <param name="Data"></param>
        private void Receive_Data_struct(IHH_Formata_Data Data)
        {

        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            //вызываем функция разъединения
            Disconnect();
            //производим закрытия окна
            this.Close();
        }
    }
}
