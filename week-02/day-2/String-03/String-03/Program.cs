using System;
using System.Text;

namespace String_03
{
    class Program
    {
        static void Main(string[] args)
        {
            string quote = "Hofstadter's Law: It you expect, even when you take into account Hofstadter's Law.";
            string toInsert = " always takes longer";
            StringBuilder newStringBuilder = new StringBuilder(quote);
            newStringBuilder.Insert(20, toInsert);
            Console.WriteLine(newStringBuilder);
            Console.ReadLine();
        }
    }
}
