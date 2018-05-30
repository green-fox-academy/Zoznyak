using System;
using System.Collections.Generic;
using System.Text;

namespace Instruments 
{
    class StringedInstrument : Instrument
    {
        private int numberOfStrings;

        public StringedInstrument(int numberOfStrings) : base ()
        {

        }

        public override void Play()
        {
            throw new NotImplementedException();
        }
    }
}
