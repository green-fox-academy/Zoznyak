using System;

namespace Append_a_func
{
    class Program
    {
        static void Main(string[] args)
        {
            string am = "Kuty";
            Console.WriteLine(AppendA(am));
            Console.ReadLine();
        }
        public static string AppendA(string text1)
        {
            return (text1 + "a");
        }
    }
}
