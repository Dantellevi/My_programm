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
using Simple_Terminal.ConvertData;

using MindFusion.Charting.Wpf;
using MindFusion.RealTimeCharting.Wpf;
using MindFusion.Diagramming.Wpf;

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
        private int[] StateCommand = new int[11];//состояние команд управлением платой     
        private delegate void ReadStructDataCOM(IHH_Formata_Data DataCOM,bool flag);//делегат для работы на прием данных прием структуры
        private delegate void ReadStringCOM(string DataCOM,bool val);//делегат для работы на прием данных прием структуры в виде строки
        IHH_Formata_Data dataFormat = new IHH_Formata_Data();//создание экземпляра  структуры

        private SerialPort _serialCOM=new SerialPort();//экземпляр СОМ терминала
        ConvertPackage convData = new ConvertPackage();// экземпляр класса для конвертации структуры в массив и наоборот

        public MainWindow()
        {
            InitializeComponent();
            dataFormat.Initilice_Massive();// создание экземпляров массивов
            SetList_Data();//Установка данных в комбобоксы
            InitStateButton();//инициализация состояний нажатий кнопок команд
        }


        /// <summary>
        /// Метод инициализации состояний кнопок
        /// </summary>
        private void InitStateButton()
        {
            for(int i=0;i<StateCommand.Length;i++)
            {
                StateCommand[i] = 1;
                if(i==9)
                {
                    StateCommand[i] =2;
                }
            }

            if (StateCommand[0] % 2 == 0)
            {
                Command_K1.Background = new SolidColorBrush(Colors.Green);
                Command_K1.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_K1.Background = new SolidColorBrush(Colors.White);
                Command_K1.Foreground = new SolidColorBrush(Colors.Black);
            }
            if (StateCommand[1] % 2 == 0)
            {
                Command_K2.Background = new SolidColorBrush(Colors.Green);
                Command_K2.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_K2.Background = new SolidColorBrush(Colors.White);
                Command_K2.Foreground = new SolidColorBrush(Colors.Black);
            }
            if (StateCommand[2] % 2 == 0)
            {
                Command_K4.Background = new SolidColorBrush(Colors.Green);
                Command_K4.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_K4.Background = new SolidColorBrush(Colors.White);
                Command_K4.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[3] % 2 == 0)
            {
                Command_Typr.Background = new SolidColorBrush(Colors.Green);
                Command_Typr.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_Typr.Background = new SolidColorBrush(Colors.White);
                Command_Typr.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[4] % 2 == 0)
            {
                Command_PK.Background = new SolidColorBrush(Colors.Green);
                Command_PK.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_PK.Background = new SolidColorBrush(Colors.White);
                Command_PK.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[5] % 2 == 0)
            {
                Command_NP.Background = new SolidColorBrush(Colors.Green);
                Command_NP.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_NP.Background = new SolidColorBrush(Colors.White);
                Command_NP.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[6] % 2 == 0)
            {
                Command_BPG.Background = new SolidColorBrush(Colors.Green);
                Command_BPG.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_BPG.Background = new SolidColorBrush(Colors.White);
                Command_BPG.Foreground = new SolidColorBrush(Colors.Black);
            }


            if (StateCommand[7] % 2 == 0)
            {
                Command_OK.Background = new SolidColorBrush(Colors.Green);
                Command_OK.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_OK.Background = new SolidColorBrush(Colors.White);
                Command_OK.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[8] % 2 == 0)
            {
                Command_PC_off.Background = new SolidColorBrush(Colors.Green);
                Command_PC_off.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_PC_off.Background = new SolidColorBrush(Colors.White);
                Command_PC_off.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[9] % 2 == 0)
            {
                Command_KCY.Background = new SolidColorBrush(Colors.Green);
                Command_KCY.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_KCY.Background = new SolidColorBrush(Colors.White);
                Command_KCY.Foreground = new SolidColorBrush(Colors.Black);
            }

            if (StateCommand[10] % 2 == 0)
            {
                Command_Fpol.Background = new SolidColorBrush(Colors.Green);
                Command_Fpol.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт

            }
            else
            {
                Command_Fpol.Background = new SolidColorBrush(Colors.White);
                Command_Fpol.Foreground = new SolidColorBrush(Colors.Black);
            }



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
            if (ckeck_SelectMode.IsChecked == true)//работает как обычный терминал
            {
                Thread.Sleep(50);
                string data = _serialCOM.ReadLine();
                Dispatcher.BeginInvoke(new ReadStringCOM(VisibleTextBox_Strings), new object[] { data,false });
               

            }
            else if (ckeck_SelectMode.IsChecked == false)    //работает как спец. терминал
            {
                byte[] buffer = new byte[256];
                int readBytes = _serialCOM.Read(buffer, 0, buffer.Length);
                dataFormat = convData.ConvertStructData(buffer);
                Receive_Data_struct(dataFormat);
                Dispatcher.BeginInvoke(new ReadStructDataCOM(VisibleTextBox_Datastruct), new object[] { dataFormat, false });
                Dispatcher.BeginInvoke(new ReadStructDataCOM(VisibleTextBox_HEXDatastruct), new object[] { dataFormat, false });
                
            }
        }
        
        /// <summary>
        /// Разнесение данных по полям окна(диагностика сигналов) по принятой стрктуре
        /// </summary>
        /// <param name="Data"></param>
        private void Receive_Data_struct(IHH_Formata_Data Data)
        {
           
        }



        /// <summary>
        /// Метод обновления данных по переданной структуре
        /// </summary>
        /// <param name="data"></param>
        private void Update_Transmit_Data_struct(IHH_Formata_Data data)
        {

        }



        #region Методы отображения принятых и отправленых данных в полях

        /// <summary>
        /// Метод отображения в поле текстбокса  данных отправляемых/принимаемых со структуры
        /// </summary>
        /// <param name="data"></param>
        private void VisibleTextBox_Datastruct(IHH_Formata_Data data,bool Res_Tran)
        {
            if(Res_Tran)//Передача данных
            {
                string TimeTransmit = DateTime.Now.ToString();
                StringFormatData.Text += string.Format("Время передачи:{0}" + "{1}||{2}||{3}||{4}||{5}"+Environment.NewLine, TimeTransmit, data.ADC_massive, data.DAC_massive, data.Digital_input, data.Digital_Output, data.ZeroByte);

            }
            else  //прием данных
            {
                string TimeTransmit = DateTime.Now.ToString();
                StringFormatData.Text += string.Format("Время Приема:{0}" + "{1}||{2}||{3}||{4}||{5}" + Environment.NewLine, TimeTransmit, data.ADC_massive, data.DAC_massive, data.Digital_input, data.Digital_Output, data.ZeroByte);
            }
        }


        /// <summary>
        /// Метод отображения в поле текстбокса  данных в виде HEX отправляемых/принимаемых со структуры
        /// </summary>
        /// <param name="data"></param>
        private void VisibleTextBox_HEXDatastruct(IHH_Formata_Data data, bool Res_Tran)
        {
            if (Res_Tran)//Передача данных
            {
                string TimeTransmit = DateTime.Now.ToString();
                HextFormatData.Text += string.Format("Время передачи:{0}" + Environment.NewLine + " 0x{1:X} ||0x{2:X}||0x{3:X}||0x{4:X}||0x{5:X}" + Environment.NewLine, TimeTransmit, data.ADC_massive, data.DAC_massive, data.Digital_input, data.Digital_Output, data.ZeroByte);

            }
            else  //прием данных
            {
                string TimeTransmit = DateTime.Now.ToString();
                HextFormatData.Text += string.Format("Время Приема:{0}" + Environment.NewLine + "0x{1:X}||0x{2:X}||0x{3:X}||0x{4:X}||0x{5:X}" + Environment.NewLine, TimeTransmit, data.ADC_massive, data.DAC_massive, data.Digital_input, data.Digital_Output, data.ZeroByte);
            }
        }

        /// <summary>
        /// Метод отображения в поле текстбокса  данных отправляемых/принимаемых ввид строки и HEX
        /// </summary>
        /// <param name="data"></param>
        private void VisibleTextBox_Strings(string data,bool flagoperation)
        {
            string DataTime = DateTime.Now.ToString();
            if(flagoperation)
            {
                StringFormatData.Text += string.Format("[{0}]->:" + "{1}" + Environment.NewLine, DataTime, data);
                HextFormatData.Text += string.Format("[{0}]->:" + Environment.NewLine + "0x{1:X}" + Environment.NewLine, DataTime, data);
            }
            else
            {
                StringFormatData.Text += string.Format("[{0}]<-:" + "{1}" + Environment.NewLine, DataTime, data);
                HextFormatData.Text += string.Format("[{0}]<-:" + Environment.NewLine + "0x{1:X}" + Environment.NewLine, DataTime, data);
            }

            
        }
        

        




        #endregion

        /// <summary>
        /// Метод передачи обычной строки в COM-порт
        /// </summary>
        /// <param name="DataString"></param>
        private void Transmit_string(string DataString)
        {
            try
            {
                
                _serialCOM.WriteLine(String.Format("{0}", DataString));
                TextCommand.Clear();
                StringFormatData.Text += "Передача :" + DataString + Environment.NewLine;
                VisibleTextBox_Strings(DataString,true);
                //VisibleTextBox_HEXString(DataString);

            }
            catch (Exception ex)
            {
                MessageBox.Show("Ошибка :" + ex.Message);

            }
        }

        /// <summary>
        /// Метод передачи структуры в виде массива байтов через СОМ- терминал
        /// </summary>
        /// <param name="Data"></param>
        private void Transmit_DataStruct(IHH_Formata_Data Data)
        {
            try
            {
                byte[] mass = convData.ConvertInMassByte(Data);//конвертируем структуру в массив байтов
                _serialCOM.WriteLine(String.Format("{0}", mass));
                TextCommand.Clear();
                StringFormatData.Text += "Передача :" + String.Format("{0}", mass) + Environment.NewLine;
                VisibleTextBox_Datastruct(Data,true);
                VisibleTextBox_HEXDatastruct(Data,true);

            }
            catch(Exception ex)
            {
                MessageBox.Show("Ошибка :" + ex.Message);
            }

            
           
        }

        /// <summary>
        /// Метод закрытия порта и закрытия окна
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            //вызываем функция разъединения
            Disconnect();
           
           
        }

        #region Команды отправки данных в COM
        private void Command_K1_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[0]++;
            if(StateCommand[0]%2==0)
            {
                Command_K1.Background = new SolidColorBrush(Colors.Green);
                Command_K1.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[0] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_K1.Background = new SolidColorBrush(Colors.White);
                Command_K1.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[0] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_K2_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[1]++;
            if (StateCommand[1] % 2 == 0)
            {
                Command_K2.Background = new SolidColorBrush(Colors.Green);
                Command_K2.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[1] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_K2.Background = new SolidColorBrush(Colors.White);
                Command_K2.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[1] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_K4_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[2]++;
            if (StateCommand[2] % 2 == 0)
            {
                Command_K4.Background = new SolidColorBrush(Colors.Green);
                Command_K4.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[2] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_K4.Background = new SolidColorBrush(Colors.White);
                Command_K4.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[2] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_Typr_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[3]++;
            if (StateCommand[3] % 2 == 0)
            {
                Command_Typr.Background = new SolidColorBrush(Colors.Green);
                Command_Typr.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[3] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_Typr.Background = new SolidColorBrush(Colors.White);
                Command_Typr.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[3] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_PK_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[4]++;
            if (StateCommand[4] % 2 == 0)
            {
                Command_PK.Background = new SolidColorBrush(Colors.Green);
                Command_PK.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[4] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_PK.Background = new SolidColorBrush(Colors.White);
                Command_PK.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[4] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_NP_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[5]++;
            if (StateCommand[5] % 2 == 0)
            {
                Command_NP.Background = new SolidColorBrush(Colors.Green);
                Command_NP.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[5] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_NP.Background = new SolidColorBrush(Colors.White);
                Command_NP.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[5] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_BPG_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[6]++;
            if (StateCommand[6] % 2 == 0)
            {
                Command_BPG.Background = new SolidColorBrush(Colors.Green);
                Command_BPG.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[6] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_BPG.Background = new SolidColorBrush(Colors.White);
                Command_BPG.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[6] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_OK_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[7]++;
            if (StateCommand[7] % 2 == 0)
            {
                Command_OK.Background = new SolidColorBrush(Colors.Green);
                Command_OK.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[7] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_OK.Background = new SolidColorBrush(Colors.White);
                Command_OK.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[7] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_PC_off_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[8]++;
            if (StateCommand[8] % 2 == 0)
            {
                Command_PC_off.Background = new SolidColorBrush(Colors.Green);
                Command_PC_off.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[8] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_PC_off.Background = new SolidColorBrush(Colors.White);
                Command_PC_off.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[8] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_KCY_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[9]++;
            if (StateCommand[9] % 2 == 0)
            {
                Command_KCY.Background = new SolidColorBrush(Colors.Green);
                Command_KCY.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[9] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_KCY.Background = new SolidColorBrush(Colors.White);
                Command_KCY.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[9] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void Command_Fpol_Click(object sender, RoutedEventArgs e)
        {
            StateCommand[10]++;
            if (StateCommand[10] % 2 == 0)
            {
                Command_Fpol.Background = new SolidColorBrush(Colors.Green);
                Command_Fpol.Foreground = new SolidColorBrush(Colors.White);
                //отправляем данные в ком порт
                dataFormat.ADC_massive[10] = 1;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
            else
            {
                Command_Fpol.Background = new SolidColorBrush(Colors.White);
                Command_Fpol.Foreground = new SolidColorBrush(Colors.Black);
                dataFormat.ADC_massive[10] = 0;//один условно, мы меняем данные первого элемента отвечающие за определенную команду
                Transmit_DataStruct(dataFormat);
            }
        }

        private void SendCommand_Click(object sender, RoutedEventArgs e)
        {
            Transmit_string(TextCommand.Text);
        }

        #endregion

        /// <summary>
        /// Обработчик выбора режима работы терминала (выбран checkbox)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ckeck_SelectMode_Checked(object sender, RoutedEventArgs e)
        {
            TextCommand.IsReadOnly = false;
            SendCommand.IsEnabled = true;
            Command_K1.IsEnabled = false;
            Command_K2.IsEnabled = false;
            Command_K4.IsEnabled = false;
            Command_Typr.IsEnabled = false;
            Command_PK.IsEnabled = false;
            Command_NP.IsEnabled = false;
            Command_BPG.IsEnabled = false;
            Command_OK.IsEnabled = false;
            Command_PC_off.IsEnabled = false;
            Command_KCY.IsEnabled = false;
            Command_Fpol.IsEnabled = false;


        }


        /// <summary>
        /// Обработчик выбора режима работы терминала (отжат checkbox)
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ckeck_SelectMode_Unchecked(object sender, RoutedEventArgs e)
        {
            TextCommand.IsReadOnly = true;
            SendCommand.IsEnabled = false;
            Command_K1.IsEnabled = true;
            Command_K2.IsEnabled = true;
            Command_K4.IsEnabled = true;
            Command_Typr.IsEnabled = true;
            Command_PK.IsEnabled = true;
            Command_NP.IsEnabled = true;
            Command_BPG.IsEnabled = true;
            Command_OK.IsEnabled = true;
            Command_PC_off.IsEnabled = true;
            Command_KCY.IsEnabled = true;
            Command_Fpol.IsEnabled = true;
        }
    }
}
