using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace Triangles
{

    public partial class MainWindow : Window
    {
        FoxDraw foxDraw;
        public MainWindow()
        {
            InitializeComponent();
            foxDraw = new FoxDraw(canvas);
            var startPoint = new Point(400, 10);
            Point startPointTemp;
            double sizeOfTheTriangle = 20;
            double heightOfTriangle = Math.Sqrt(Math.Pow(sizeOfTheTriangle, 2) - Math.Pow(sizeOfTheTriangle/2, 2));
            int numberOfLines = 20;

            for (int i = 1; i <= numberOfLines; i++)
            {
                startPointTemp = startPoint;
                for (int j = 1; j <= i ; j++)
                {
                    DrawOneTrianle(startPointTemp, sizeOfTheTriangle);
                    startPointTemp.X += sizeOfTheTriangle;
                }
                startPoint.X -= sizeOfTheTriangle/2;
                startPoint.Y += heightOfTriangle;
            }
        }

        private void DrawOneTrianle(Point startPoint, double sizeOfTriangle)
        {
            double halfOfSide = sizeOfTriangle / 2;
            double heightOfTriangle = Math.Sqrt(Math.Pow(sizeOfTriangle, 2) - Math.Pow(halfOfSide, 2));
            var points = new List<Point>();
            points.Add(new Point(startPoint.X, startPoint.Y));
            points.Add(new Point(startPoint.X + halfOfSide, startPoint.Y + heightOfTriangle));
            points.Add(new Point(startPoint.X - halfOfSide, startPoint.Y + heightOfTriangle));
            foxDraw.StrokeColor(Colors.Red);
            foxDraw.FillColor(Colors.Transparent);
            foxDraw.DrawPolygon(points);
        }
    }

}
