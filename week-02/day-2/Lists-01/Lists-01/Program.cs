using System;
using System.Collections.Generic;
using System.Text;

namespace Lists_01
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> planetList = new List<string> {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Uranus", "Neptune" };
            Console.WriteLine(PutSaturn(planetList));
            Console.ReadLine();
        }
        public static string PutSaturn (List<string> listOne)
        {
            listOne.Insert(6, "Saturn");
            string listToText = string.Join(",", listOne.ToArray());            
            return listToText;
        }
    }
}
