using System;
using System.Collections.Generic;
using System.Text;

namespace Practice
{
    public class Code
    {

        public static string ReverseString(string str)
        {
            string output = ""; //output
            Stack<char> word = new Stack<char>();
            string currWord = "";
            for (int i = 0; i < str.Length; i++)
            {
                word.Push(str[i]);
                if (str[i] == ' ')
                {
                    word.Pop();
                    currWord = "";
                    while (word.Count > 0)
                    {

                        currWord += word.Pop();

                    }
                 //   Console.Write(currWord + ' ');
                    output += currWord + ' ';
                }
            }
            currWord = "";
            while (word.Count > 0)
            {
                currWord += word.Pop();
            }
          //  Console.Write(currWord + ' ');
            output += currWord;

            return output;
        }
    }
}
