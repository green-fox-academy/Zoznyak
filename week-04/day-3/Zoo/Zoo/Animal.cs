using System;
using System.Collections.Generic;
using System.Text;

namespace Zoo
{
    public abstract class Animal
    {
        protected string name;
        protected int age;
        protected string gender;
        protected int weight;

        protected Animal(string name, int age, string gender, int weight)
        {
            this.name = name;
            this.age = age;
            this.gender = gender;
            this.weight = weight;
        }

        public abstract string WantChild();
        public abstract string Greet();
    }
}
