using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace RainbowBox
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
                InitializeComponent();
                var foxDraw = new FoxDraw(canvas);
                double sizeX = canvas.Width;
                double sizeY = canvas.Height;

                for (int i = 1; i < 11; i++)
                {
                    DrawRainbowBoxes(sizeX, sizeY);
                    sizeX -= 50;
                    sizeY -= 50;
                }
            }

            private void DrawRainbowBoxes(double sizeX, double sizeY)
            {
                var foxDraw = new FoxDraw(canvas);
                foxDraw.FillColor(Colors.Transparent);
                foxDraw.DrawRectangle(canvas.Width / 2 - sizeX / 2, canvas.Height / 2 - sizeY / 2, sizeX, sizeY);
            }
        }

}
