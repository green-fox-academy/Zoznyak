using System;

namespace BMI
{
    class Program
    {
        static void Main(string[] args)
        {
            double massInKg = 81.2;
            double heightInM = 1.78;
            double bmiIndex = 1.00;

            bmiIndex = massInKg / (heightInM * heightInM);
            Console.WriteLine("Your BMI index is: {0}", bmiIndex);

                Console.ReadLine();
        }
    }
}
