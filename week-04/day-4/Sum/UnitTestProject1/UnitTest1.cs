using NUnit.Framework;

namespace UnitTestProject1
{
    [TestFixture]
    public class UnitTest1
    {
        [TestCase]
        public void WorksOrNot()
        {
            Assert.AreEqual(null, null);
        }
    }
}
