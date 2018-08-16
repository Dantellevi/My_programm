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

namespace App_COMTerminal
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private List<int> SpeedBaudL;//список скоростей порта
        private string NamePortL;//имя порта
        private List<string> formatDataL;//формат данных
        private List<string> bitParityL;//бит четности
        private List<string> stopBitsL;//стоп бит



        public MainWindow()
        {
            InitializeComponent();
           

        }
    }
}
