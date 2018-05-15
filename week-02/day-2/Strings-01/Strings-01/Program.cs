using System;

namespace Strings_01
{
    class Program
    {
        static void Main(string[] args)
        {
            string example = "In a dishwasher far far away";
            example = example.Replace("dishwasher", "galaxy");
            Console.WriteLine(example);
            Console.ReadLine();
        }
    }
}
