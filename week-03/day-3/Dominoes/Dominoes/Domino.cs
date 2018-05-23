using System;
using System.Collections.Generic;
using System.Text;

namespace Dominoes
{
    public class Domino
    {
        private readonly int[] Values;

        public Domino(int valueA, int valueB)
        {
            this.Values = new int[] { valueA, valueB };
        }

        public int[] GetValues()
        {
            return Values;
        }

        public override string ToString()
        {
            return Values[0]+":"+Values[1];
        }
    }
}
