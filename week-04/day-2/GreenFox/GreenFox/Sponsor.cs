using System;
using System.Collections.Generic;
using System.Text;

namespace GreenFox
{
    class Sponsor : Person
    {
        string company;
        int hiredStudents = 0;

        public Sponsor(string name, int age, string gender, string company) : base(name, age, gender)
        {
            this.company = company;
        }

        public Sponsor()
        {
            Name = "Jane Doe";
            Age = 30;
            Gender = "female";
            company = "Google";
            hiredStudents = 0;
        }

        public override string GetGoal()
        {
            return String.Format("My goal is: Hire brilliant junior software developers.");
        }

        public override string Introduce()
        {
            return String.Format("Hi, I'm {0}, a {1} year old {2} who represents {3} and hired {4} students so far.",
                Name, Age, Gender, company, hiredStudents);
        }

        public void Hire()
        {
            hiredStudents++;
        }

    }
}
