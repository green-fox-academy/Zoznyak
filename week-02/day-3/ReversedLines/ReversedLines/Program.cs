using System;
using System.Collections.Generic;
using System.IO;

namespace Doubled
{
    class Program
    {
        static void Main(string[] args)
        {
            string file1 = @"D:\Greenfox\Zoznyak\week-02\day-3\ReversedLines\ReversedLines\reversed-lines.txt";
            string file2 = @"D:\Greenfox\Zoznyak\week-02\day-3\ReversedLines\ReversedLines\correct-lines.txt";
            ReversedLines(file1, file2);
            Console.ReadLine();
        }

        public static void ReversedLines(string file1, string file2)
        {
            StreamReader reader = new StreamReader(file1);
            string line = " ";
            File.WriteAllText(file2, "");
            while (line != null)
            {
                line = reader.ReadLine();

                if (line != null)
                {
                    string tempLine = "";
                    for (int i = line.Length; i > 0; i--)
                    {
                        tempLine += line[i - 1];
                    }
                    File.AppendAllText(file2, tempLine + "\n");
                }
            }
        }
    }
}
