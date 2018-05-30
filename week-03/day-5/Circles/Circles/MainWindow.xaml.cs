using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace Circles
{

    public partial class MainWindow : Window
    {
        FoxDraw foxDraw;

        public MainWindow()
        {
            InitializeComponent();
            foxDraw = new FoxDraw(canvas);
            foxDraw.StrokeColor(Colors.Black);
            foxDraw.FillColor(Colors.Transparent);

            double circleSize = 200;
            double centralX = canvas.Width / 2;
            double centralY = canvas.Height / 2;
            
            DrawCirlces(centralX,centralY,circleSize);

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

        public void DrawCirlces(double centralX, double centralY, double sizeOfCircle)
        {
            while (sizeOfCircle >90)
            {
                Point startPoint = CentralPointToStart(centralX, centralY, sizeOfCircle);

                foxDraw.DrawEllipse(startPoint.X, startPoint.Y, sizeOfCircle, sizeOfCircle);

                sizeOfCircle = sizeOfCircle / 2;
                double circleRadius = sizeOfCircle / 2;
                //right side small cirle
                double centralTwoX = centralX + Math.Cos(DegreeToRadian(30)) * circleRadius;
                double centralTwoY = centralY + Math.Sin(DegreeToRadian(30)) * circleRadius;
                startPoint = CentralPointToStart(centralTwoX, centralTwoY, sizeOfCircle);
                foxDraw.DrawEllipse(startPoint.X, startPoint.Y, sizeOfCircle, sizeOfCircle);

                //left side small cirle
                double centralThreeX = centralX - Math.Cos(DegreeToRadian(30)) * circleRadius;
                double centralThreeY = centralY + Math.Sin(DegreeToRadian(30)) * circleRadius;
                startPoint = CentralPointToStart(centralThreeX, centralThreeY, sizeOfCircle);
                foxDraw.DrawEllipse(startPoint.X, startPoint.Y, sizeOfCircle, sizeOfCircle);

                //top small circle
                double centralFourX = centralX;
                double centralFourY = centralY - circleRadius;
                startPoint = CentralPointToStart(centralFourX, centralFourY, sizeOfCircle);
                foxDraw.DrawEllipse(startPoint.X, startPoint.Y, sizeOfCircle, sizeOfCircle);

                DrawCirlces(centralFourX, centralFourY, sizeOfCircle); ;
            }
            
        }
    }
}
