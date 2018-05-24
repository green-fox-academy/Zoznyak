using System;

namespace NummerAdder
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(NummerAdder(6)); 
            Console.ReadLine();
        }

        public static int NummerAdder(int n)
        {
            if (n == 1)
            {
                return 1;  
            }
            else
            {
                return n + NummerAdder(n - 1); 
            }
        }
    }
}
