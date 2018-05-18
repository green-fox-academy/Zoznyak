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
            var startPoint = new Point(200, 50);
            double sizeOfTheTriangle = 40;

            DrawOneTrianle(startPoint, sizeOfTheTriangle);
        }

        private void DrawOneTrianle(Point startPoint, double sizeOfTriangle)
        {
            double halfOfSide = sizeOfTriangle / 2;
            double heightOfTriangle = Math.Sqrt(Math.Pow(sizeOfTriangle, 2) - Math.Pow(halfOfSide, 2));
            var points = new List<Point>();
            points.Add(new Point(startPoint.X, startPoint.Y));
            points.Add(new Point(startPoint.X + halfOfSide, startPoint.Y + heightOfTriangle));
            points.Add(new Point(startPoint.X - halfOfSide, startPoint.Y + heightOfTriangle));
            foxDraw.FillColor(Colors.Transparent);
            foxDraw.DrawPolygon(points);
        }
    }

}
