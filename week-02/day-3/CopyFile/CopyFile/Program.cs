using System;
using System.IO;

namespace CopyFile
{
    class Program
    {
        static void Main(string[] args)
        {
            string file1Path = @"D:\Greenfox\Zoznyak\week-02\day-3\CopyFile\CopyFile\TextFile1.txt";
            string file2Path = @"D:\Greenfox\Zoznyak\week-02\day-3\CopyFile\CopyFile\TextFile2.txt";
            Console.WriteLine(CopyFiles(file1Path, file2Path));
            Console.ReadLine();
        }

        public static bool CopyFiles(string file2, string file1)
        {
            try
            {
                File.WriteAllText(file1, File.ReadAllText(file2));
                return true;
            }
            catch (Exception )
            {
                Console.WriteLine("Copy error");
               return false;
            }
            
        }
    }
}
