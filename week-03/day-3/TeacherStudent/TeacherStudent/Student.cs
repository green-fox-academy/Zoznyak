using System;
using System.Collections.Generic;
using System.Text;

namespace TeacherStudent
{
    class Student
    {
        string name;

        public Student(string name)
        {
            this.name = name;
        }

        public static void Learn()
        {
            Console.WriteLine("Learning...");
        }

        public static void Question()
        {
            Console.WriteLine("Question from student");
            Teacher.Answer();
        }
    }
}
