﻿using System;
using System.Collections.Generic;
using System.Text;

namespace GreenFox
{
    class Student : Person
    {
        private string previousOrganization;
        private static int skippedDays = 0;

        public Student(string name, int age, string gender, string previousOrganization) : base(name, age, gender)
        {
            this.previousOrganization = previousOrganization;
            //this.skippedDays = skippedDays;
        }

        public Student()
        {
            Name = "Jane Doe";
            Age = 30;
            Gender = "female";
            previousOrganization = "The School of Life";
            skippedDays = 0;
        }

        public override string GetGoal()
        {
            return String.Format("Be a junior software developer");
        }

        public override string Introduce()
        {
            return String.Format("Hi, I'm {0}, a {1} year old {2} from {3} who skipped {4} days from the course already.", Name, Age, Gender, previousOrganization,skippedDays);
        }
    }
}
