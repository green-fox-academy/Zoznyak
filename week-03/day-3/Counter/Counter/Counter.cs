﻿using System;
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

        public void Add(int number)
        {
            result += number;
        }

        public void Add()
        {
            result++;
        }

        public string Get()
        {
            return result.ToString();
        }

        public int Reset()
        {
            result = this.defaultNumber;
            return result;
        }
    }
}
