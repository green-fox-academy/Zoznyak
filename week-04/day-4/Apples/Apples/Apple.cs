using System;
using System.Collections.Generic;
using System.Text;

namespace Apples
{
    public class Apple
    {
        private string name;

        public Apple(string name)
        {
            this.name = name;
        }

        public string GetName
        {
            get 
            {
                return name;
            }
        }
    }
}
