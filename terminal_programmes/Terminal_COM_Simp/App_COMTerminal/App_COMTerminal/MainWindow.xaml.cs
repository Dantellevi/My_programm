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
using System.IO.Ports;
using System.Threading;

namespace App_COMTerminal
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private int cntBtn_setting=1;
        SerialPort _dataport;
        Convert_dataList _Listdata;

        private delegate void ReadStringCOM(string data);// делегат для работы на прием данных в отдельном потоке


        public MainWindow()
        {
            InitializeComponent();
            _Listdata = new Convert_dataList();
            _Listdata.FillList();
            GetDataList();
            _dataport = new SerialPort();

        }

        /// <summary>
        /// Функция заполнения Combobox-ов
        /// </summary>
        void GetDataList()
        {
            ListNamePORT.ItemsSource = _Listdata.PortComName;
            SpeedBuad.ItemsSource = _Listdata.Baud;
            Format_Data.ItemsSource = _Listdata.Format;
            Parity_BitStatus.ItemsSource = _Listdata.bitParity;
            Stop_BitStatus.ItemsSource = _Listdata.StopBit;
        }




        /// <summary>
        /// Обработчик прерывания настройки соединения 
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btn_Setting_Click(object sender, RoutedEventArgs e)
        {
            
            try
            {
                

                if (ListNamePORT.SelectedIndex!=-1 && SpeedBuad.SelectedIndex!=-1 &&
                    Format_Data.SelectedIndex!=-1 && Parity_BitStatus.SelectedIndex!=-1 && Stop_BitStatus.SelectedIndex!=-1)
                {
                    cntBtn_setting++;
                    if (cntBtn_setting % 2 == 0)
                    {
                        _Listdata._NamePort_ = ListNamePORT.Text;
                        _Listdata._speed_ =long.Parse(SpeedBuad.Text);
                        _Listdata._format_ = int.Parse(Format_Data.Text);
                        _Listdata._bitP_ = Parity_BitStatus.Text;
                        _Listdata._stopBit_ = Stop_BitStatus.Text;
                        _Listdata.Connect(ref _dataport);//Функция инициализации порта и подключения  к порту
                        btn_Setting.Content = "Соединение установлено";
                        btnTransmitData.IsEnabled = true;
                        _dataport.DataReceived += _dataport_DataReceived;
                    }
                    else
                    {
                        btn_Setting.Content = "Подключиться";
                        btnTransmitData.IsEnabled = false;
                        Disconnect();
                    }

                }
                
            }
            catch(Exception exs)
            {
                Disconnect();
                MessageBox.Show("Ошибка!!!" + exs.Message);
            }
            

        }

        /// <summary>
        /// Обработчик принятия данных из порта
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void _dataport_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Thread.Sleep(50);
            string dataRes = _dataport.ReadLine();
            Dispatcher.BeginInvoke(new ReadStringCOM(VisibleTexbox_String), new object[] { dataRes });
            //логирование

        }

        /// <summary>
        /// Метод отображения в поле текстбокса  данных принимаемых ввид строки и HEX
        /// </summary>
        /// <param name="data"></param>
        private void VisibleTexbox_String(string data)
        {
            DataRessieveTransmit_Box.Text += String.Format("Прием данных[{0}]:{1}"+Environment.NewLine, DateTime.Now, data);
            //Hex
            DataRessieveTransmit_BoxHEX.Text+= String.Format("Прием данных[{0}]:0x{1:X}"+Environment.NewLine, DateTime.Now, data);//не работает
            //bin
            byte[] StrBytes = System.Text.Encoding.ASCII.GetBytes(data);
            DataRessieveTransmit_BoxBIN.Text += String.Format("Прием данных[{0}]:{1}"+Environment.NewLine, DateTime.Now, StrBytes.ToString());//не работает




        }

        private void Disconnect()
        {
            _dataport.Close();
        }

        /// <summary>
        /// Функция передачи данных из текстбокса
        /// </summary>
        /// <param name="DataString"></param>
        private void Transmit_String(string DataString)
        {
            try
            {
                _dataport.WriteLine(String.Format("{0}", DataString));
                Fill_DataTransmit.Clear();
                DataRessieveTransmit_Box.Text += String.Format("Передача[{0}]:{1}" + Environment.NewLine, DateTime.Now, DataString);
                //отображение в поле 16-битного значения
                DataRessieveTransmit_BoxHEX.Text += String.Format("Передача данных[{0}]:0x{1:X}"+Environment.NewLine, DateTime.Now, DataString);//не работает

                //отображения в поле 2-раз. значения
                byte[] StrBytes = System.Text.Encoding.ASCII.GetBytes(DataString);
                DataRessieveTransmit_BoxBIN.Text += String.Format("Передача данных[{0}]:{1}" + Environment.NewLine, DateTime.Now, StrBytes.ToString());//не работает
                //логирования

            }
            catch(Exception exs)
            {
                MessageBox.Show("Ошибка передачи: " + exs.Message);
            }
        }

        /// <summary>
        /// Обработчик события кнопки передачи данных
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnTransmitData_Click(object sender, RoutedEventArgs e)
        {
            Transmit_String(Fill_DataTransmit.Text);

        }


        /// <summary>
        /// Обработчик нажатия кнопки ENTER
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Fill_DataTransmit_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.Key==Key.Enter)
            {
                Transmit_String(Fill_DataTransmit.Text);
            }
        }
    }
}
