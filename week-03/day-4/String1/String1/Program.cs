using System;

namespace String1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(ChangeString("xhxhxh"));
            Console.ReadLine();
        }
        //not done

        public static string ChangeString(string stringArg)
        {
            char temp = stringArg[0];
            if (temp == 'x')
            {
                temp = 'y';
            }
            return stringArg
        }
    }
}
