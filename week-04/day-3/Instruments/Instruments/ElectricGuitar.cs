using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    class ElectricGuitar : StringedInstrument
    {
        public ElectricGuitar() : base()
        {
            NumberOfStrings = 6;
            name = "Electric Guitar";
        }

        public ElectricGuitar(int numberOfStrings) : base()
        {
            this.NumberOfStrings = numberOfStrings;
            name = "Electric Guitar";
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
