using System;

namespace CodingHours
{
    class Program
    {
        static void Main(string[] args)
        {
            float workDaysWeekly = 5.00f;
            int weekNumbers = 17;
            float dailyCodingHours = 6.00f;
            int avarageWorkingHoursWeekly = 52;

            Console.WriteLine("Spent hours with coding in a semester: " + workDaysWeekly * dailyCodingHours * weekNumbers);
            Console.WriteLine("Percentage of the coding hours in the semester: " + (((dailyCodingHours * workDaysWeekly * weekNumbers)/(avarageWorkingHoursWeekly*weekNumbers))*100) + " %");
            Console.ReadLine();
        }
    }
}
