using System;
using System.Collections.Generic;
using System.Text;

namespace GreenFox
{
    class Mentor : Person
    {
        private string level;

        public Mentor(string name, int age, string gender, string level) : base(name, age, gender)
        {
            this.level = level;
        }

        public Mentor()
        {
            Name = "Jane Doe";
            Age = 30;
            Gender = "female";
            level = "intermediate";
        }

        public override string GetGoal()
        {
            return String.Format("Educate brilliant junior software developers.");
        }

        public override string Introduce()
        {
            return String.Format("Hi, I'm {0}, a {1} year old {2} {3} mentor.", Name, Age, Gender, level);
        }

    }
}
