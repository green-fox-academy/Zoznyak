using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments
{
    class BassGuitar : StringedInstrument
    {
        public BassGuitar() : base()
        {
            NumberOfStrings = 4;
            name = "Bass Guitar";
        }

        public BassGuitar(int numberOfStrings) : base()
        {
            this.NumberOfStrings = numberOfStrings;
            name = "Bass Guitar";
        }

        public override string Sound()
        {
            return String.Format("Duum-duum-duum");
        }

        public override void Play()
        {
            Console.WriteLine("{0}, a {1}-stringed instrument that {2}.", name, NumberOfStrings, Sound());
        }
    }
}
