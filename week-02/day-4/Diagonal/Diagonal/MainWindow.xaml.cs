using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace Diagonal
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            var startpoint = new Point(0, 0);
            var endpoint = new Point(canvas.Width, canvas.Height);
            var startpoint2 = new Point(canvas.Width, 0);
            var endpoint2 = new Point(0, canvas.Height);
            foxDraw.StrokeColor(Colors.Green);
            foxDraw.DrawLine(startpoint, endpoint);
            foxDraw.StrokeColor(Colors.Red);
            foxDraw.DrawLine(startpoint2, endpoint2);
        }
    }
}
