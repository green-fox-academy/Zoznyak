using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace CenterBoxFunction
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);          
            int sizeX = 50;
            int sizeY = 50;

            for (int i = 1; i < 4; i++)
            {
                DrawCenterBox(sizeX, sizeY);
                sizeX += 50;
                sizeY += 50;
            }
        }

        private void DrawCenterBox(int sizeX, int sizeY)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.FillColor(Colors.Transparent);
            foxDraw.DrawRectangle(canvas.Width/2-sizeX/2, canvas.Height/2-sizeY/2, sizeX, sizeY);
        }
    }
}
