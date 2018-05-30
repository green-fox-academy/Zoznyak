using System;
using System.Collections.Generic;
using System.Text;

namespace Zoo
{
    public abstract class Animal
    {
        private string name;
        private int age;
        private string gender;
        private int weight;

        public abstract string WantChild();
        public abstract string Greeet();
    }
}
