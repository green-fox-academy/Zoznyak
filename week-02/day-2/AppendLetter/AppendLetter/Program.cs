using System;
using System.Collections.Generic;
using System.Text;

namespace AppendLetter
{
    class Program
    {
        static void Main(string[] args)
        {
            var far = new List<string> { "kuty", "macsk", "kacs", "rok", "halacsk" };
            foreach (var word in AppendA(far))
            {
                Console.WriteLine(word);
            }
            Console.ReadLine();
        }
        public static List<string> AppendA(List<string> oneList)
        {
            var completeList = new List<string>();
            string letter = "a";
            foreach (var word in oneList)
            {
                completeList.Add(string.Format("{0}{1}", word, letter));
            }
            return completeList;
        }
    }
}
