using System;
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
            double circleSize = 200;
            double centralX = canvas.Width / 2;
            double centralY = canvas.Height / 2;
            Point startPoint = CentralPointToStart(centralX, centralY, circleSize);

            foxDraw.StrokeColor(Colors.Black);
            foxDraw.FillColor(Colors.Transparent);

            foxDraw.DrawEllipse(startPoint.X, startPoint.Y, circleSize, circleSize);
            
            circleSize = circleSize / 2;
            double circleRadius = circleSize / 2;

            centralX += Math.Cos(DegreeToRadian(30)) * circleRadius;
            centralY += Math.Sin(DegreeToRadian(30)) * circleRadius;
            startPoint = CentralPointToStart(centralX, centralY, circleSize);
            foxDraw.DrawEllipse(startPoint.X, startPoint.Y, circleSize, circleSize);




        }

        private double DegreeToRadian(double angle)
        {
            return Math.PI * angle / 180.0;
        }

        public Point CentralPointToStart(double centralX, double centralY, double size)
        {
            Point startPoint = new Point(centralX-(size/2), centralY-(size/2));
            return startPoint;
        }
    }

}
