using System;
using System.Collections.Generic;
using System.IO;

namespace Doubled
{
    class Program
    {
        static void Main(string[] args)
        {
            string file1 = @"D:\Greenfox\Zoznyak\week-02\day-3\Doubled\Doubled\duplicated-chars.txt";
            string file2 = @"D:\Greenfox\Zoznyak\week-02\day-3\Doubled\Doubled\decrypted-chars.txt";
            Decrypted(file1,file2);
            Console.ReadLine();
        }

        public static void Decrypted(string file1,string file2)
        {
            StreamReader reader = new StreamReader(file1);
            string line = " ";
            File.WriteAllText(file2,"");
            while (line != null)
            {
                line = reader.ReadLine();

                if (line != null)
                {
                    string tempLine = " ";
                    for (int i = 0; i < line.Length; i+=2)
                    {
                        tempLine += line[i];
                    }
                    File.AppendAllText(file2,tempLine + "\n");
                }
            }
        }
    }
}
