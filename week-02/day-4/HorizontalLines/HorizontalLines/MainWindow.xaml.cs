using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace HorizontalLines
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            var startPoint = new Point();
            for (int i = 0; i < 9; i += 3)
            {
                startPoint.X = 100;
                startPoint.Y = 200 + i * 30;
                DrawVerticalLines(startPoint.X, startPoint.Y);
            }
        }

        public void DrawVerticalLines(double num1, double num2)
        {
            var foxDraw = new FoxDraw(canvas);
            var startPoint = new Point(num1, num2);
            var endPoint = new Point(num1+50, num2);
            foxDraw.DrawLine(startPoint, endPoint);
        }
    }
}
