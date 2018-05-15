using System;

namespace String_05
{
    class Program
    {
        static void Main(string[] args)
        {
            string textToReverse;
            textToReverse = ".eslaf eb t'ndluow ecnetnes siht ,dehctiws erew eslaf dna eurt fo sgninaem eht fI";
            textToReverse = ReverseString(textToReverse);
            Console.WriteLine(textToReverse);
            Console.ReadLine();
        }
        public static string ReverseString(string text)
        {
            string tempText = "";
            for (int i = text.Length; i > 0; i--)
            {
                tempText += text[i-1];
            }
            return tempText;
        }
            
    }
}
