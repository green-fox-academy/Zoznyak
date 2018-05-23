using System;
using System.Collections.Generic;
using System.Text;

namespace Counter
{
    class Counter
    {
        private int defaultNumber;
        public int result = 0;

        public Counter(int defaultNumber)
        {
            this.defaultNumber = defaultNumber;
            result = defaultNumber;
        }

        public int Add(int number)
        {
            result += number;
            return result;
        }

        public int Add()
        {
            result++;
            return result;
        }

        public int Get()
        {
            return result;
        }

        public int Reset()
        {
            result = this.defaultNumber;
            return result;
        }
    }
}
