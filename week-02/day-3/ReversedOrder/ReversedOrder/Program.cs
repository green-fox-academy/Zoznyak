using System;
using System.Collections.Generic;
using System.IO;

namespace Doubled
{
    class Program
    {
        static void Main(string[] args)
        {
            string file1 = @"D:\Greenfox\Zoznyak\week-02\day-3\ReversedOrder\ReversedOrder\reversed-order.txt";
            string file2 = @"D:\Greenfox\Zoznyak\week-02\day-3\ReversedOrder\ReversedOrder\correct-order.txt";
            ReversedOrder(file1, file2);
            Console.ReadLine();
        }

        public static void ReversedOrder(string file1, string file2)
        {
            StreamReader reader = new StreamReader(file1);
            string line = " ";
            int numberOfLines = 0;
            File.WriteAllText(file2, "");
            while (line != null)
            {
                line = reader.ReadLine();

                if (line != null)
                {

                    numberOfLines += 1;
                }           
            }
            Console.WriteLine(numberOfLines);
            for (int i = numberOfLines; i < numberOfLines; i++)
            {

            }
        }
    }
}