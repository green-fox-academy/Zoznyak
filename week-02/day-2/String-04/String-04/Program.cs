using System;
using System.Text;

namespace String_04
{
    class Program
    {
        static void Main(string[] args)
        {
            string toDoText = " - Buy milk\n";
            StringBuilder newStringBuilder = new StringBuilder(toDoText);
            newStringBuilder
                .Insert(0, "My todo:\n")
                .Append(" - Download games\n")
                .Append("\t- Diablo");
            Console.WriteLine(newStringBuilder);
            Console.ReadLine();
        }
    }
}
