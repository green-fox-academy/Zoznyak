using System;

namespace Greeter
{
    class Program
    {
        static void Main(string[] args)
        {
            string al = "Geenfox";
            Console.WriteLine(Greet(al));
            Console.ReadLine();
        }
        public static string Greet(string text1)
        {
            return ("Greetings deer, " + text1);
        }
    }
}
