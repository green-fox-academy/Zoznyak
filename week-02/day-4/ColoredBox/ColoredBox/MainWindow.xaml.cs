using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace ColoredBox
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            foxDraw.StrokeColor(Colors.Green);
            foxDraw.DrawLine(200, 100, 400,100);
            foxDraw.StrokeColor(Colors.Red);
            foxDraw.DrawLine(200, 300, 400, 300);
            foxDraw.StrokeColor(Colors.Purple);
            foxDraw.DrawLine(400, 100, 400, 300);
            foxDraw.StrokeColor(Colors.Blue);
            foxDraw.DrawLine(200, 300, 200, 100);
        }
    }

}
