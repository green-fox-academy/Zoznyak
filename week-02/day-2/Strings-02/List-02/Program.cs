using System;

namespace List_02
{
    class Program
    {
        static void Main(string[] args)
        {
            string url = "https//www.reddit.com/r/nevertellmethebots";
            url = CompleteHttps(url);
            url = url.Replace("bots", "odds");
            Console.WriteLine(url);
            Console.ReadLine();
        }

        public static string CompleteHttps(string string1)
        {
            string1 = string1.Insert(5, ":");
            return string1;
        }
    }
}
