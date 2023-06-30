using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
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

namespace ProyectoMorse
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        string nodemcuUrl = "http://192.168.1.4/data";
        HttpClient httpClient = new HttpClient();
        public MainWindow()
        {
            InitializeComponent();
        }
        private async void Btn_Enviar(object sender, RoutedEventArgs e)
        {
            try
            {
                var data = new System.Collections.Generic.Dictionary<string, string>
                {
                    {"data", Tb_mensaje.Text }
                };
                var content = new FormUrlEncodedContent(data);

                // Enviar la solicitud POST al NodeMCU
                HttpResponseMessage response = await httpClient.PostAsync(nodemcuUrl, content);

            }
            catch(Exception ex)
            {
                MessageBox.Show("Error en la solicitud HTTP: " + ex.Message);
            }

        }

        //Diseño
        private void TL_Titulo_MouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
                DragMove();
        }
        private void Image_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            Close();
        }
        private void Image_MouseEnter(object sender, MouseEventArgs e)
        {
            ToolTip = "Cerrar";
        }
        private void MinimizeButton_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            WindowState = WindowState.Minimized;
        }
        private void MinimizeButton_MouseEnter(object sender, MouseEventArgs e)
        {
            ToolTip = "Minimizar";
        }
        private void MinimizeButton_MouseLeave(object sender, MouseEventArgs e)
        {
            ToolTip = null;
        }
    }
}
