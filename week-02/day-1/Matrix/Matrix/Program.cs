using System;

namespace Matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Give me a number");
            int number = int.Parse(Console.ReadLine());
            Console.WriteLine();
            int[,] matrix = new int[number, number];

            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                for (int j = 0; j < matrix.GetLength(1); j++)
                {
                    if (j==i)
                    {
                        matrix[i, j] = 1;
                        Console.Write(matrix[i,j]);
                    }
                    else
                    {
                        matrix[i, j] = 0;
                        Console.Write(matrix[i, j]);
                    }
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}
