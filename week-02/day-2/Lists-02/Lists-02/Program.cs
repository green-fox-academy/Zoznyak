using System;
using System.Collections.Generic;

namespace Lists_02
{
    class Program
    {
        static void Main(string[] args)
        {
            var girls = new List<string> { "Eve", "Ashley", "Bozsi", "Kat", "Jane" };
            var boys = new List<string> { "Joe", "Fred", "Bela", "Todd", "Neef","Jeff" };
            foreach (var name in Together(girls,boys))
            {
                Console.Write(name + ", ");
            }
            Console.ReadLine();
        }

        public static List<string> Together(List<string> listOne, List<string> listTwo)
        {
            for (int i = 0; i < listTwo.Count-1; i++)
            {
                listOne.Insert((2*i) + 1, listTwo[i]);
            }
            listOne.Add(listTwo[listTwo.Count-1]);
            return listOne; 
        }
    }
}
