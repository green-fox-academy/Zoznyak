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
            var startPoint = new Point(300, 150);
            Point startPointTemp;
            double radiusOfHexagon = 40;
            double heightOfHexagonHalf = 0.5 * Math.Sqrt(3) * radiusOfHexagon;
 
            for (int i = 1; i <= 7; i++)
            {
                startPointTemp = startPoint;
                if (i<=4)
                {
                    for (int j = 1; j < i+4 ; j++)
                    {
                        DrawOneHexagon(startPointTemp, radiusOfHexagon);
                        startPointTemp.Y += heightOfHexagonHalf * 2;
                    }
                    startPoint.X += 1.5 * radiusOfHexagon;
                    if (i != 4)
                    {
                        startPoint.Y -= heightOfHexagonHalf;
                    }
                    else
                    {
                        startPoint.Y += heightOfHexagonHalf;
                    }
                }
                else 
                {
                    for (int k = 11-i; k >0 ; k--)
                    {
                        DrawOneHexagon(startPointTemp, radiusOfHexagon);
                        startPointTemp.Y += heightOfHexagonHalf * 2;
                    }
                    startPoint.X += 1.5 * radiusOfHexagon;
                    startPoint.Y += heightOfHexagonHalf;
                }
            }            
        }        

        private void DrawOneHexagon(Point startPoint, double radius)
        {
            double heightOfHexagonHalf = 0.5 * Math.Sqrt(3) * radius;
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
