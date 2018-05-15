using System;
using System.Collections.Generic;

namespace ElementFinder
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List<int>{ 1, 2, 3, 4, 5 };
            if (ContainsNumber(list) == true)
            {
                Console.WriteLine("Hoorraay");
            }
            else
            {
                Console.WriteLine("Nooooooo");
            }
            Console.ReadLine();
        }
        
        public static bool ContainsNumber(List<int> oneList)
        {
            int number = 7;
            return oneList.Contains(number);
        }
    }
}
