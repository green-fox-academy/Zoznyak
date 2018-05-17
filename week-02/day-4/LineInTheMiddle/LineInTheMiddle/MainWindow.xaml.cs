using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace LineInTheMiddle
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            foxDraw.StrokeColor(Colors.Red);
            foxDraw.DrawLine(0, canvas.Height/2, canvas.Width, canvas.Height/2);
            foxDraw.StrokeColor(Colors.Green);
            var startPoint = new Point(canvas.Width/2, 0);
            var endPoint = new Point(canvas.Width/2, canvas.Height);
            foxDraw.DrawLine(startPoint, endPoint);

        }
    }

}
