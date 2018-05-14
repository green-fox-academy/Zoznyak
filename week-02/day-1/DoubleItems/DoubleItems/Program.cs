using System;

namespace DoubleItems
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] numList = { 3, 4, 5, 6, 7 };

            DoubleIt(numList);

            for (int i = 0; i < numList.Length; i++)
            {
                Console.WriteLine(numList[i]);
            }
            Console.ReadLine();
        }

        public static int[] DoubleIt(int[] arrayOne)
        {
            for (int i = 0; i < arrayOne.Length; i++)
            {
                arrayOne[i] *= 2;
            }
            return arrayOne;
        }
    }
}
