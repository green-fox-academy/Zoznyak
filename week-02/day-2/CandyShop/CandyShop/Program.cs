using System;
using System.Collections.Generic;
using System.Text;

namespace CandyShop
{
    class Program
    {
        static void Main(string[] args)
        {
            var list = new List<object>();
            list.Add("Cupcake");
            list.Add(2);
            list.Add("Brownie");
            list.Add(false);
            Console.WriteLine(Sweet(list));
            Console.ReadLine();
        }
        public static string Sweet(List<object> oneList)
        {
            var newList = new List<string>();
            string correctListInString;
            foreach (var item in oneList)
            {
                newList.Add(string.Format("{0} ", item));
            }
            correctListInString = String.Join(" ", newList.ToArray());
            StringBuilder builder = new StringBuilder(correctListInString);
            builder.Replace("2", "Croissont")
                   .Replace("False", "Ice Cream");
            return builder.ToString();
        }
    }
}
