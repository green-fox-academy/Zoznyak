using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    class Violin : StringedInstrument
    {
        private string name = "Violin";
        public Violin() : base()
        {
            NumberOfStrings = 4;
        }

        public Violin(int numberOfStrings) : base()
        {
            this.NumberOfStrings = numberOfStrings;
        }

        public override string Sound()
        {
            return String.Format("screeches");
        }

        public override void Play()
        {
            Console.WriteLine("{0}, a {1}-stringed instrument that {2}.", name, NumberOfStrings, Sound());
        }
    }
}
