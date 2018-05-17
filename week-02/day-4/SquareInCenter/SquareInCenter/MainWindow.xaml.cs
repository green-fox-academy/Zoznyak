using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace SquareInCenter
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            foxDraw.StrokeColor(Colors.Green);
            foxDraw.DrawLine(canvas.Width/2-5, canvas.Height/2-5, canvas.Width/2+5, canvas.Height/2-5);
            foxDraw.DrawLine(canvas.Width/2+5, canvas.Height/2-5, canvas.Width/2+5, canvas.Height/2+5);
            foxDraw.DrawLine(canvas.Width/2+5, canvas.Height/2+5, canvas.Width/2-5, canvas.Height/2+5);
            foxDraw.DrawLine(canvas.Width/2-5, canvas.Height/2+5, canvas.Width/2-5, canvas.Height/2-5);

        }
    }
}
