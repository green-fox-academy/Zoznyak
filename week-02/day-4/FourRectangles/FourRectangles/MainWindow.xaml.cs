using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace FourRectangles
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            var startPoint = new Point(100, 100);
            var ShapeColor = new Color[] { Colors.Cyan, Colors.CadetBlue, Colors.Gold };
            for (int i = 1; i < 4; i++)
            {
                foxDraw.StrokeColor(ShapeColor[i-1]);
                foxDraw.FillColor(ShapeColor[i-1]);
                foxDraw.DrawRectangle(startPoint.X*i, startPoint.Y*i, 0+i*10, 0+i*10);
            }
        }
    }
}
