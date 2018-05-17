using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace ToTheCenter
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            var startPoint = new Point();
            for (int i = 0; i < 9; i+= 3)
            {
                startPoint.X = 100+i*30;
                startPoint.Y = 200+i*30;
                DrawLines(startPoint.X, startPoint.Y);
            }
        }

        public void DrawLines(double num1, double num2)
        {
            var foxDraw = new FoxDraw(canvas);
            var startPoint = new Point(num1,num2);
            var endPoint = new Point(canvas.Width / 2, canvas.Height / 2);
            foxDraw.DrawLine(startPoint, endPoint);
        }
    }
}
