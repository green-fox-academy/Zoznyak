using System;
using System.Collections.Generic;

namespace QuoteSwap
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List<string> { "What", "I", "do", "create,", "I", "cannot", "not", "understand." };
            Console.WriteLine(QuoteSwap(list,2,5));
            Console.ReadLine();
        }

        public static string QuoteSwap(List<string> listOne,int index1,int index2)
        {
            string temp = "";
            temp = listOne[index1];
            listOne[index1] = listOne[index2];
            listOne[index2] = temp;
            return String.Join(" ", listOne.ToArray());
        }
    }
}
