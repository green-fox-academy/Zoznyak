using System;
using System.Collections.Generic;

namespace IsInList
{
    class Program
    {
        static void Main(string[] args)
        {
            var list1 = new List<int> { 2, 4, 6, 8, 10, 12, 14, 16 };
            var list2 = new List<int> { 4, 8, 12, 16 };
            Console.WriteLine(IsItInList(list1,list2));
            Console.ReadLine();
        }

        static public bool IsItInList(List<int> listOne, List<int> listTwo)
        {
            int matches = 0;
            for (int i = 0; i < listTwo.Count; i++)
            {
                if (listOne.Contains(listTwo[i]))
                {
                    matches += 1;
                }
            }
            return matches == listTwo.Count;
        }
    }
}
