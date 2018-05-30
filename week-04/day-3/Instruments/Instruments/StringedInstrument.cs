using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments 
{
    public abstract class StringedInstrument : Instrument
    {
        private int numberOfStrings;

        public int NumberOfStrings
        {
            get
            {
                return this.numberOfStrings;
            }
            set
            {
                this.numberOfStrings = value;
            }
        }

        public StringedInstrument() : base()
        {
        }

        public StringedInstrument(int numberOfStrings) : base()
        {
            this.numberOfStrings = numberOfStrings;
        }
    }
}
