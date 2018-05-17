using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace PositionSquare
{

    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            var foxDraw = new FoxDraw(canvas);
            int startPosX = 0;
            int startPosY = 0;

            for (int i = 1; i < 4; i++)
            {
                DrawReactangle(startPosX, startPosY);
                startPosX += 50;
                startPosY += 50;
            }         
        }

        private void DrawReactangle(int startPosX, int startPosY)
        {
            var foxDraw = new FoxDraw(canvas);
            foxDraw.DrawRectangle(startPosX, startPosY, 50, 50);
        }
    }
}
