using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace Circles
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            double circleSize = 100;
            double centerX = canvas.Width / 2;
            double centerY = canvas.Height / 2;

            foxDraw.StrokeColor(Colors.Black);
            foxDraw.FillColor(Colors.Transparent);



            foxDraw.DrawEllipse(centerX, centerY, circleSize, circleSize);
            circleSize = circleSize / 2;



        }
    }

}
