using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    class ElectricGuitar : StringedInstrument
    {
        private string name = "Electric Guitar";
        public ElectricGuitar() : base()
        {
            NumberOfStrings = 6;
        }

        public ElectricGuitar(int numberOfStrings) : base()
        {
            this.NumberOfStrings = numberOfStrings;
        }

        public override string Sound()
        {
            return String.Format("twangs");
        }

        public override void Play()
        {
            Console.WriteLine("{0}, a {1}-stringed instrument that {2}.", name, NumberOfStrings, Sound());
        }
    }
}
