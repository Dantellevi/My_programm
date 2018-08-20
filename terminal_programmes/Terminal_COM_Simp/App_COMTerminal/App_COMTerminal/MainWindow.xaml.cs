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


namespace App_COMTerminal
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        SerialPort _dataport;
        Convert_dataList _Listdata;
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


        private void btn_Setting_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (ListNamePORT.SelectedIndex!=-1 && SpeedBuad.SelectedIndex!=-1 &&
                    Format_Data.SelectedIndex!=-1 && Parity_BitStatus.SelectedIndex!=-1 && Stop_BitStatus.SelectedIndex!=-1)
                {

                }
            }
            catch(Exception exs)
            {
                MessageBox.Show("Ошибка!!!" + exs.Message);
            }
            

        }
    }
}
