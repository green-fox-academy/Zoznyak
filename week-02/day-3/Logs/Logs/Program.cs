using System;
using System.Collections.Generic;
using System.IO;

namespace Logs
{
    class Program
    {
        static void Main(string[] args)
        {
            string path1 = @"D:\Greenfox\Zoznyak\week-02\day-3\Logs\Logs\log.txt";
            Console.WriteLine("Uniq IPs: ");            
            foreach (var item in UniqueIPs(path1))
            {
                Console.WriteLine(item);
            }
            Console.WriteLine();
            GetPostRatio(path1);
            Console.ReadLine();
        }

        public static string[] UniqueIPs(string file1)
        {
            StreamReader reader = new StreamReader(file1);
            List<string> listOfUniqs = new List<string>();
            int index = 0;
            string line = " ";
            while (line != null)
            {
                line = reader.ReadLine();
                if (line != null)
                {
                    if (listOfUniqs.Contains(line.Substring(27, 11)) != true) 
                    {
                        listOfUniqs.Add(line.Substring(27,11));
                        index += 1;
                    }
                }             
            }
            //Console.WriteLine(index); //number of the uniq IPs
            return listOfUniqs.ToArray();
        }

        public static void GetPostRatio(string file1)
        {
            StreamReader reader = new StreamReader(file1);
            int get = 0;
            int post = 0;
            string line = " ";
            while (line != null)
            {
                line = reader.ReadLine();
                if (line != null)
                {
                    if (line.Contains("POST /"))
                    {
                        post += 1;
                    }
                    else if (line.Contains("GET /"))
                    {
                        get += 1;
                    }
                }
            }
            Console.WriteLine("The GET / POST ratio is : {0} / {1}",get,post);
        }
    }
}
