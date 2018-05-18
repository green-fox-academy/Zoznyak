using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Media;
using FoxDrawNameSpace;

namespace SuperHexagon
{
    public partial class MainWindow : Window
    {
        FoxDraw foxDraw;
        public MainWindow()
        {
            InitializeComponent();
            foxDraw = new FoxDraw(canvas);
            var startPoint = new Point(400, 100);
            double radiusOfHexagon = 40;
            /*
            Point startPointTemp;
            double radiusOfHexagon = 20;
            double heightOfTriangle = Math.Sqrt(Math.Pow(sizeOfTheTriangle, 2) - Math.Pow(sizeOfTheTriangle / 2, 2));
            int numberOfLines = 20;
            */
            DrawOneHexagon(startPoint, radiusOfHexagon);
        }        

        private void DrawOneHexagon(Point startPoint, double radius)
        {
            double heightOfHexagonHalf = 0.5 * Math.Sqrt(3) * radius;
            //double heightOfTriangle = Math.Sqrt(Math.Pow(sizeOfTriangle, 2) - Math.Pow(halfOfSide, 2));
            var points = new List<Point>();
            points.Add(new Point(startPoint.X, startPoint.Y));
            points.Add(new Point(startPoint.X + radius, startPoint.Y));
            points.Add(new Point(startPoint.X + (radius*1.5), startPoint.Y + heightOfHexagonHalf));
            points.Add(new Point(startPoint.X + radius, startPoint.Y + heightOfHexagonHalf*2));
            points.Add(new Point(startPoint.X, startPoint.Y + heightOfHexagonHalf*2));
            points.Add(new Point(startPoint.X - (radius*0.5), startPoint.Y + heightOfHexagonHalf));
            foxDraw.StrokeColor(Colors.Red);
            foxDraw.FillColor(Colors.Transparent);
            foxDraw.DrawPolygon(points);
        }
    }
}
